
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lcy_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.009076322917843e+00, -3.926233912692549e+00, -3.810203302361264e+00, -3.649578861275034e+00, -3.430927470054361e+00, -3.140365220940578e+00, -2.767254238005720e+00, -2.310714911138211e+00, -1.787766159193296e+00, -1.236882355797983e+00, -7.238438550943924e-01, -4.394710762296635e-01, -3.688322797478736e-01, -2.682461825947575e-01, -1.439745097028531e-01, -4.492337261469311e-02, -5.275336966600866e-03, -1.818206221228128e-04, -1.598557913731364e-06, -2.156396558941967e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lcy_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.187331208036270e+00, -5.073218616604168e+00, -4.913280948771604e+00, -4.691660987472177e+00, -4.389582463368402e+00, -3.987505863261432e+00, -3.470516848798508e+00, -2.839131183330621e+00, -2.128323521011365e+00, -1.431912419027194e+00, -8.757014675473085e-01, -6.390198213835991e-01, -5.440649272079979e-01, -4.109873295354705e-01, -2.413126178157786e-01, -8.919445526444499e-02, -1.155596304229043e-02, -3.802943346847121e-04, -3.215454021231887e-06, -4.313400429506861e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lcy_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.663449624147943e-06, -2.881078865101755e-06, -3.223921036896194e-06, -3.785490612260962e-06, -4.757406480641623e-06, -6.574021584968324e-06, -1.034647439469634e-05, -1.934072140334965e-05, -4.459906030855847e-05, -1.274066924529806e-04, -4.692380538267554e-04, 2.788241636407173e-04, 4.020205452390106e-03, 5.543543623525710e-03, 1.790995727134188e-02, 7.256534695952602e-02, 1.142703735805203e-01, 4.878658774432086e-02, 6.036341030500721e-03, 1.504922027223957e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lcy_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.213690040200771e-02, -1.268843029102683e-02, -1.352464362312763e-02, -1.482132928429146e-02, -1.689650852849986e-02, -2.036434031433583e-02, -2.649317193796993e-02, -3.800197265538181e-02, -6.000655819358287e-02, -9.542845655568009e-02, -1.969693047426583e-01, -4.692577356865554e-01, -5.483331358869867e-01, -8.962937479363996e-01, -2.264023834001786e+00, -8.852492857059897e+00, -1.865956753258668e+01, -1.525764165362027e+01, -1.168421156681401e+01, -1.118279598269203e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lcy_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.285341597521846e-08, 2.602350389070443e-08, 3.133716744125133e-08, 4.084553107226407e-08, 5.949710665281967e-08, 1.010320867295488e-07, 2.104849586392060e-07, 5.625338863583763e-07, 1.838223829233934e-06, 2.328947366625901e-06, -4.128439368675515e-05, 4.400668778583045e-03, -1.230262620625446e-03, 3.345552568549529e-02, 6.616864610887966e-01, 2.612586485443121e+01, 6.707901775006546e+02, 9.647479302227073e+03, 1.380686669383633e+05, 2.578585126743556e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_lcy_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.274196798582186e-14, -6.168743961555797e-14, -7.684633981850370e-14, -1.039619153270109e-13, -1.546070461029765e-13, -2.403951884178644e-13, -1.638222680969012e-13, 4.933024224790060e-12, 1.629882491736282e-10, 8.984134967372118e-09, 9.129139816191872e-07, -5.827640554383997e-04, -6.584571469960776e-03, -3.518387010901127e-02, -1.215886607161782e+00, -2.077505833641197e+02, -5.895677637894102e+04, -2.706282996400521e+07, -4.600820176077982e+10, -6.593257592003332e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
