"""
 libxc functional
"""

# type: mgga_exc
# prefix:
#   mgga_c_ltapw_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_c_ltapw_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_ltafrac = param_default("ltafrac")

define('lda_c_pw_params')
include('lda_c_pw')

# kinetic energy density to electron density

@helper
def nt_tau(t):
    return (t/K_FACTOR_C)**(Integer(3)*params_a_ltafrac/Integer(5))

# effective density

@helper
def n_eff_s(rs, z, t):
    return n_spin(rs, z) * nt_tau(t)

@helper
def n_eff(rs, z, ts0, ts1):
    return n_eff_s(rs, z, ts0) + n_eff_s(rs, -z, ts1)

# recompute rs and zeta

@helper
def eff_rs(rs, z, ts0, ts1):
    return r_ws(n_eff(rs, z, ts0, ts1))

@helper
def eff_z(rs, z, ts0, ts1):
    return (n_eff_s(rs, z, ts0) - n_eff_s(rs, -z, ts1))/n_eff(rs, z, ts0, ts1)

def f(rs, z, xt, xs0, xs1, us0, us1, ts0, ts1):
    return f_pw(eff_rs(rs, z, ts0, ts1), eff_z(rs, z, ts0, ts1))

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_c_ltapw_params"
