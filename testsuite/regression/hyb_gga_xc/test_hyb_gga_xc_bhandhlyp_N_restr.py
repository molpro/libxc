
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_bhandhlyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandhlyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.222664643877868e+00, -2.181630624056056e+00, -2.124162752036178e+00, -2.044618562992987e+00, -1.936357927060677e+00, -1.792526915580811e+00, -1.607884231803323e+00, -1.381979780145610e+00, -1.122923504827836e+00, -8.473278972837492e-01, -5.723957692353547e-01, -3.752439361987084e-01, -3.234567942853644e-01, -2.719219920058251e-01, -1.973723471458328e-01, -1.178421040762684e-01, -6.101787209685485e-02, -4.861383359064486e-02, -3.014322016401108e-02, -2.038986551578790e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_bhandhlyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandhlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.757030310755706e+00, -2.700245581394875e+00, -2.620670624112911e+00, -2.510432542821167e+00, -2.360222207931477e+00, -2.160372072872626e+00, -1.903512249879260e+00, -1.589761403969734e+00, -1.235461629801966e+00, -8.850843468242183e-01, -6.037365167525726e-01, -4.564340556983935e-01, -4.077643676741758e-01, -3.299319933828008e-01, -2.345177967227418e-01, -1.518358489366007e-01, -7.920551764040008e-02, -2.460131416632007e-02, -9.190382830722366e-03, -3.454530683569752e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_bhandhlyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandhlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.013340301925017e-06, -2.169306110592643e-06, -2.414119851378093e-06, -2.813125104232750e-06, -3.499089739235057e-06, -4.770482701164608e-06, -7.386911769476937e-06, -1.359620572673959e-05, -3.134564893266052e-05, -9.490670603321059e-05, -4.125999747419593e-04, -2.836643983319528e-03, -5.689818932186062e-03, -9.885898174733126e-03, -2.419528699499387e-02, -1.437430416197022e-02, 7.398917929271094e-01, -8.577030461263219e+01, -8.438910065252796e+03, -5.017749716049715e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_bhandhlyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandhlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.941193254845358e-03, -6.203990799053560e-03, -6.601581885790068e-03, -7.216222471579860e-03, -8.195651323540108e-03, -9.823053998406927e-03, -1.268121409526844e-02, -1.804085364332751e-02, -2.856362158145372e-02, -4.681519259631174e-02, -7.533929169082944e-02, -2.548705623999912e-01, -3.326809468808606e-01, -5.062227598435900e-01, -7.555402176408192e-01, 1.563813370077095e+00, 1.946531454862590e+01, 1.102718014363428e+01, 7.869593662543301e+03, 5.082560443988757e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_bhandhlyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandhlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.981775114261271e-09, 1.130535593648985e-08, 1.350887495246048e-08, 1.741352469527010e-08, 2.496658642253493e-08, 4.145840456195328e-08, 8.377368653481777e-08, 2.156091562675332e-07, 6.820195135478020e-07, 4.964893406460101e-07, -9.018193629930547e-05, 2.502225231288355e-03, 1.128771064819188e-02, 1.552050329626808e-02, -2.738432852019690e-01, -3.196687804436327e+01, -4.243491719093705e+03, -4.966695308301977e+05, -5.054048478110056e+09, -1.705185737301802e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_bhandhlyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandhlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.258365677412583e-14, 6.559023578600283e-14, 9.006458779283564e-14, 1.418682121947962e-13, 2.717085081119215e-13, 6.863954902656343e-13, 2.559227866244862e-12, 1.639546335054759e-11, 2.203868747672918e-10, 8.011282386163024e-09, 1.066024471188462e-06, 2.598008640081091e-04, 2.285460668490474e-03, 1.535808645181188e-02, 6.544553945546220e-01, 1.841988088450250e+02, 3.756856060058748e+05, 9.984686685093197e+09, 1.210205117883285e+16, 4.024468377676090e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
