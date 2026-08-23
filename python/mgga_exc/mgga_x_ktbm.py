"""
 libxc functional
"""

# type: mgga_exc
# prefix:
#   mgga_x_ktbm_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_ktbm_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_ct = param_default("ct")
params_a_at = param_default("at")
params_a_bt = param_default("bt")
params_a_a2t = param_default("a2t")
params_a_b2t = param_default("b2t")
params_a_xt = param_default("xt")
params_a_cb = param_default("cb")
params_a_ab = param_default("ab")
params_a_bb = param_default("bb")
params_a_a2b = param_default("a2b")
params_a_b2b = param_default("b2b")
params_a_xb = param_default("xb")

@helper
def ktbm_t(t):
    return t/K_FACTOR_C

@helper
def ktbm_top(p, t):
    return params_a_ct + params_a_at*p + params_a_bt*t + params_a_a2t*p*p + params_a_b2t*t*t + params_a_xt*p*t

@helper
def ktbm_bot(p, t):
    return params_a_cb + params_a_ab*p + params_a_bb*t + params_a_a2b*p*p + params_a_b2b*t*t + params_a_xb*p*t

@helper
def ktbm_f(x, u, t):
    return ktbm_top(mgga_p(x),ktbm_t(t))/ktbm_bot(mgga_p(x),ktbm_t(t))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(ktbm_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_ktbm_params"
