"""
 Copyright (C) 2021 Johannes Voss
               2021 Susi Lehtola

 This Source Code Form is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
"""

# type: mgga_exc

from libxc_codegen import *  # noqa: F401, F403

include('mbeef')

# MS2 f(alpha) transformation

@helper
def mbeef_xj0(a):
    return one_minus_z_pow_n(a, Integer(2))**Integer(3)/(Integer(1) + a**Integer(3)*(Integer(1) + Integer(4)*a**Integer(3)))

mbeef_n = Integer(8)

mbeef_coefs = maple_list([ maple_list([ Float('1.067841267592822e+00'), -Float('1.587224228252040e-01'), -Float('2.372737447003859e-01'),  Float('2.558752743285125e-03'), Float('6.748483298726394e-03'),  Float('1.199436228162263e-03'),  Float('1.552846614645878e-03'),  Float('5.848922069964790e-04') ]), maple_list([ Float('2.032399091383024e-01'),  Float('1.179363564823021e-01'), -Float('1.437960658302686e-02'), -Float('1.030571429426108e-02'), Float('1.683215086686233e-02'), -Float('2.577333382727080e-04'),  Float('2.334616776649133e-03'),  Float('3.837976998664341e-04') ]), maple_list([ -Float('6.952718706718514e-04'),  Float('1.794638556864410e-03'), -Float('1.153807045825489e-03'), -Float('7.090296813211244e-04'), Float('1.370288635457470e-04'),  Float('6.670848599065867e-03'), -Float('5.498112922165805e-03'),  Float('1.421391023843761e-03') ]), maple_list([ -Float('2.565692477269114e-03'),  Float('2.125332357775206e-03'), -Float('9.641371299507833e-04'),  Float('3.712786171321043e-03'), Float('1.282471852770764e-03'),  Float('2.262886186270548e-04'), -Float('6.510071882485726e-03'),  Float('1.243327883803539e-02') ]), maple_list([ -Float('2.170152177993684e-03'),  Float('2.915285520983635e-03'), -Float('1.863882881010248e-03'), -Float('2.494950550547465e-03'), Float('4.187827907710905e-04'), -Float('1.009981263546227e-03'),  Float('4.230264400260503e-04'),  Float('2.457525918536260e-03') ]), maple_list([ -Float('2.723387704355568e-03'),  Float('2.007295399058147e-03'), -Float('1.189668304951413e-03'),  Float('1.672905908063297e-04'), -Float('2.721968500889238e-04'), -Float('5.869916483960576e-04'),  Float('1.136485825094485e-03'),  Float('1.522474179598972e-03') ]), maple_list([ -Float('1.977607215613360e-03'),  Float('1.491587478361034e-03'), -Float('1.288306127279617e-03'), -Float('6.058496834176058e-04'), Float('2.776060240069905e-04'), -Float('1.622621390953226e-03'),  Float('4.260858412001439e-04'), -Float('3.682519432462936e-04') ]), maple_list([ -Float('2.516160322803815e-03'),  Float('1.940164714223896e-03'), -Float('1.175614476758423e-03'),  Float('4.312411759243052e-04'), Float('3.212943141118693e-06'), -Float('2.202759704065197e-04'),  Float('3.807158595350892e-04'), -Float('3.695503801501715e-04') ]) ])

@helper
def mcml_f(x, u, t):
    return mbeef_expansion(x, t)

def f(rs, z, xt, xs0, xs1, u0, u1, t0, t1):
    return mgga_exchange(mcml_f, rs, z, xs0, xs1, u0, u1, t0, t1)

TYPE = "mgga_exc"
