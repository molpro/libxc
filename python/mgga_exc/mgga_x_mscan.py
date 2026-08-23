"""
 Copyright (C) 2025 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_mscan_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_mscan_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

# mscan depends on the total reduced gradient xt, so it does not obey
# exact spin scaling; keep it off the spin-density evaluation path.
# spin_scaled: false

include('mgga_x_scan')

# compute sigma1 from the SQUARED reduced gradients xt2, xs02, xs12.
# mscan_sigma1/mscan_alpha are opaque helpers, so taking the squares keeps
# them rational in sigma: the alpha recomputation (the bulk of mscan's
# size) no longer chains its high-order derivatives through sqrt(sigma).
# The genuine sqrt(xt) survives only in scan_gx below, as in base SCAN.

@helper
def mscan_sigma1(rs, z, xt2, xs02, xs12):
    # xs02 = sigma0/na^(8/3)
    sigma0 = xs02*n_spin(rs,z)**(Integer(8)/Integer(3))
    # xs12 = sigma2/nb^(8/3)
    sigma2 = xs12*n_spin(rs,-z)**(Integer(8)/Integer(3))
    # xt2 = (sigma0 + 2*sigma1 + sigma2)/(na+nb)^(8/3)
    sigma1 = (n_total(rs)**(Integer(8)/Integer(3))*xt2 - sigma0 - sigma2)/Integer(2)
    return sigma1

# Redefine scaled gradient; since this is now the total density the factor is different

@helper
def scan_gx(x):
    return -xc_expm1(-scan_a1/sqrt(XT2S*x))

# modified SCAN alpha, eq 15

@helper
def mscan_alpha(rs, z, xt2, xs02, xs12, t0, t1):
    return (n_spin(rs,z)**(Integer(8)/Integer(3))*t0 + n_spin(rs,-z)**(Integer(8)/Integer(3))*t1 - mscan_sigma1(rs, z, xt2, xs02, xs12)/Integer(4)) / (K_FACTOR_C * (n_spin(rs,z)**(Integer(8)/Integer(3)) + n_spin(rs,-z)**(Integer(8)/Integer(3))))

@helper
def mscan_f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return (
        (scan_h1x(scan_y(xt, mscan_alpha(rs, z, xt**Integer(2), xs0**Integer(2), xs1**Integer(2), t0, t1)))*(Integer(1) - scan_f_alpha(mscan_alpha(rs, z, xt**Integer(2), xs0**Integer(2), xs1**Integer(2), t0, t1)))
        + scan_h0x*scan_f_alpha(mscan_alpha(rs, z, xt**Integer(2), xs0**Integer(2), xs1**Integer(2), t0, t1)))*scan_gx(xt)
    )

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mscan_f(rs, z_thr( z), xt, xs0, xs1, u0, u1, t0, t1)*(my_piecewise3(screen_dens(rs, z), Integer(0), lda_x_spin(rs, z_thr(z))) + my_piecewise3(screen_dens(rs, -z), Integer(0), lda_x_spin(rs, z_thr(-z))))

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_mscan_params"
