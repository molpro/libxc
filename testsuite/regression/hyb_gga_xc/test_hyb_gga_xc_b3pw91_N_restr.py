
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b3pw91_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3pw91", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.524856878343533e+00, -3.458379598700669e+00, -3.365261812323171e+00, -3.236340108832976e+00, -3.060815556037461e+00, -2.827519841253756e+00, -2.527909585468771e+00, -2.161445761563463e+00, -1.742746155342286e+00, -1.304901529574845e+00, -8.804449478674712e-01, -5.803042896727167e-01, -5.056996982971398e-01, -4.191073192097528e-01, -3.032938179353626e-01, -1.934642997332714e-01, -1.163682682898960e-01, -6.945853146383607e-02, -4.312187500428458e-02, -2.934354239972364e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b3pw91_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.445435951990503e+00, -4.353772905125945e+00, -4.225272787946353e+00, -4.047152931517416e+00, -3.804220915091673e+00, -3.480503500835578e+00, -3.063273564689726e+00, -2.550771643006942e+00, -1.964636262337425e+00, -1.367823093136039e+00, -8.930102883083568e-01, -7.285408077991415e-01, -6.528853857899183e-01, -5.237233399511496e-01, -3.540573025638243e-01, -1.893629011825723e-01, -8.180496543670862e-02, -3.426149778800548e-02, -1.283215733371338e-02, -4.949258328393490e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3pw91_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.487647280601968e-06, -2.687619917529535e-06, -3.002511197102705e-06, -3.518129046332587e-06, -4.410704183244766e-06, -6.082314077241860e-06, -9.578639238674643e-06, -1.810436147511123e-05, -4.375516835714676e-05, -1.462303482650692e-04, -7.303576330046612e-04, -2.644150379987877e-03, -3.169732473741338e-03, -9.258433378949344e-03, -4.141141776071201e-02, -3.533855069063217e-01, -4.922586783964662e+00, -1.310199314531033e+02, -1.215202553213390e+04, -7.225559590989466e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3pw91_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.650394644344302e-03, -1.008521557990283e-02, -1.074457046356569e-02, -1.176756410402823e-02, -1.340742349677029e-02, -1.616065785818183e-02, -2.109324883905498e-02, -3.075449329756149e-02, -5.203778658054360e-02, -1.059316590567549e-01, -2.611093992238187e-01, -4.497187841180824e-01, -5.320480748856229e-01, -9.427065927738338e-01, -2.516570153297370e+00, -9.747674223917947e+00, -1.882369081787850e+01, 7.243801285971220e+01, 1.190882434070655e+04, 7.346170676574335e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3pw91_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.697560126841544e-08, 1.928812554093325e-08, 2.315984022878204e-08, 3.008151227112785e-08, 4.366540444499346e-08, 7.407882820645529e-08, 1.559590467527369e-07, 4.402579184859634e-07, 1.836033067344755e-06, 1.292383582389899e-05, 2.298771808525315e-04, 7.215501240259663e-03, 1.647292898422368e-02, 7.645600109574373e-02, 9.148808326597679e-01, 2.652468724036637e+01, -5.122612683153607e+02, -9.427994460667925e+05, -7.277716242334077e+09, -2.455467459621892e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3pw91_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.261906783137642e-15, 1.260402261228256e-14, 2.163984147240174e-14, 4.326998271951439e-14, 1.058739577735335e-13, 3.404360738326194e-13, 1.591315002467700e-12, 1.242251429841275e-11, 1.947659889268922e-10, 7.794893200332778e-09, 9.601217411213641e-07, -1.873474838551989e-04, -3.074959244573284e-03, -1.056131889055607e-02, -1.812816397287140e-01, 6.414800699183803e+01, 4.858304447234498e+05, 1.435470788781269e+10, 1.742691588006457e+16, 5.795234463318530e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
