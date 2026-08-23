
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ol2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ol2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.327073598574017e+00, -4.248465658446858e+00, -4.137936016634329e+00, -3.984099835483155e+00, -3.773148416087866e+00, -3.490081564836675e+00, -3.122094596292699e+00, -2.665465588644845e+00, -2.136721811725069e+00, -1.583621648929090e+00, -1.058764502348005e+00, -6.726576114129695e-01, -5.607455100836457e-01, -4.778294250833270e-01, -3.465533565480667e-01, -2.249975723261913e-01, -1.697272245166462e-01, -2.793961530446215e-01, -1.145862954867370e+00, -9.826148502532634e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ol2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ol2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.152224169307316e+00, -5.061615690986687e+00, -4.933556303609590e+00, -4.754021736970778e+00, -4.505290711802531e+00, -4.166653912969307e+00, -3.717254282801820e+00, -3.142754100946305e+00, -2.448250290329211e+00, -1.687026548145864e+00, -1.066168690210115e+00, -8.026474304424477e-01, -6.628049494479870e-01, -5.679703167678126e-01, -3.855944504944562e-01, -1.847120410014412e-01, 1.008563376194630e-02, 3.026757267109776e-01, 1.513300942733904e+00, 1.309992482394202e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ol2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ol2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.622515757358361e-06, -6.892079844993221e-06, -7.305759498285975e-06, -7.959869476314648e-06, -9.041611356688871e-06, -1.095767444964150e-05, -1.473627456388627e-05, -2.357351012949291e-05, -5.055947947520231e-05, -1.708091143243299e-04, -9.202677314508642e-04, -7.561262980248639e-03, -3.152488383423642e-02, -2.568559072968282e-02, -7.206099999859322e-02, -6.173241755249949e-01, -1.602460928072636e+01, -1.521491972453848e+03, -8.279968021095680e+05, -5.539903208512306e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ol2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ol2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.256928897676817e-03, -4.598714208694924e-03, -5.127318905597902e-03, -5.970844991078582e-03, -7.378318595271509e-03, -9.880910441641086e-03, -1.475356583373372e-02, -2.556143283956896e-02, -5.442894149382783e-02, -1.509653704489340e-01, -4.231761969327069e-01, -2.815314808489043e-01, -1.693175997018177e-01, -6.672516617216691e-01, -2.525959874156020e+00, -1.678500593811270e+01, -3.133623920187349e+02, -2.482311930152075e+04, -1.243056948050282e+07, -7.917699350011041e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ol2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ol2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.722084109069155e-08, -6.191663338733609e-08, -6.925113738845031e-08, -8.106824752577184e-08, -1.008273558522467e-07, -1.348996604910677e-07, -1.910486212094010e-07, -2.245959265673581e-07, 7.244200107332531e-07, 2.236088411658088e-05, 5.379278223134159e-04, -1.207372728637772e-02, -1.367196705054529e-01, -8.141213711423692e-02, 5.724559068963865e-01, 6.155856733112984e+01, 2.147467097295941e+04, 6.299971401918719e+07, 3.865294458744342e+12, 1.913215536389918e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ol2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ol2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.143010949490970e-12, 1.331188428308031e-12, 1.657111096255178e-12, 2.269481592374706e-12, 3.562910316932971e-12, 6.795407902811578e-12, 1.708639113435897e-11, 6.358179532301761e-11, 4.160483481565238e-10, 6.548994393448584e-09, 6.014702310423278e-07, 2.275055892209391e-03, 8.877150300713497e-02, 8.981730120201979e-02, 8.118780423605684e-01, 4.897844597303492e+01, 1.911799535041772e+04, 7.018245472306854e+07, 5.162095485668091e+12, 2.889780168167009e+19]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
