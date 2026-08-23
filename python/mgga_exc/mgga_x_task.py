"""
 Copyright (C) 2019 M.A.L. Marques

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc
# prefix:
#   mgga_x_task_params *params;
#
#   assert(p->params != NULL);
#   params = (mgga_x_task_params * )(p->params);

from libxc_codegen import *  # noqa: F401, F403

params_a_task_c = param_default("task_c")
params_a_task_h0x = param_default("task_h0x")
params_a_task_d = param_default("task_d")
params_a_task_anu = param_default("task_anu")
params_a_task_bnu = param_default("task_bnu")

@helper
def task_gx(x):
    return m_one_minus_recexp(x**(Integer(1)/Integer(4))/params_a_task_c)

# expand (not simplify) the Chebyshev sums: Maple 2025's simplify()
# throws an internal "content/content" error on these during the
# codegen derivative processing, while expand() produces the same
# expanded polynomial without tripping it.

@helper
def task_hx1(r):
    return expand(sum((params_a_task_anu[i+Integer(1)]*chebyshevt(i, (r - Integer(1))/(r + Integer(1)))) for i in range(Integer(0), (Integer(2)) + Integer(1))))

@helper
def task_fx(r):
    return expand(sum((params_a_task_bnu[i+Integer(1)]*chebyshevt(i, (r - Integer(1))/(r + Integer(1)))) for i in range(Integer(0), (Integer(4)) + Integer(1))))

@helper
def task_f0(s, a):
    return (
        params_a_task_h0x*task_gx(s**Integer(2)) +
        (Float('1.0') - task_fx(a))*(task_hx1(s**Integer(2)) - params_a_task_h0x)*task_gx(s**Integer(2))**params_a_task_d
    )

@helper
def task_f(x, u, t):
    return task_f0(gga_s(x), mgga_alpha_safe(x, t))

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(task_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
PARAMS_STRUCT = "mgga_x_task_params"
