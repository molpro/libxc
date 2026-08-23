
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbeint_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbeint", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.245346950550064e+00, -4.162779129071454e+00, -4.047159423029252e+00, -3.887163404645698e+00, -3.669507513728541e+00, -3.380613845078454e+00, -3.010552148565104e+00, -2.560273490525996e+00, -2.051636936471254e+00, -1.530808171808220e+00, -1.027785306231675e+00, -6.505510085108925e-01, -5.570528178551500e-01, -4.602020853433471e-01, -3.335905319844403e-01, -2.182295424007197e-01, -1.196414125672060e-01, -4.186878415937265e-02, -8.769438510566803e-03, -9.701617070370187e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbeint_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.441432366619848e+00, -5.327330874300046e+00, -5.167306213919296e+00, -4.945337280125784e+00, -4.642259793512112e+00, -4.237612095721675e+00, -3.714259266898688e+00, -3.067411210508023e+00, -2.321243292051256e+00, -1.566737841510168e+00, -9.975074218685309e-01, -8.117733674363145e-01, -7.218136671274168e-01, -5.642239433934556e-01, -3.605649536277484e-01, -1.946980730726150e-01, -1.303080387810893e-01, -5.447479165049325e-02, -1.167944738910151e-02, -1.293530283085683e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbeint_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.350152351453572e-06, -2.549262371904443e-06, -2.865099312533516e-06, -3.387935199306612e-06, -4.308000179159439e-06, -6.074882213841312e-06, -9.916283898101523e-06, -1.985212670143944e-05, -5.227046268222887e-05, -1.908774273641707e-04, -9.931281719295000e-04, -4.463764313147438e-03, -7.773293391536199e-03, -1.834546753217552e-02, -7.935949963823058e-02, -5.155294468490708e-01, -1.980385037184553e+00, -3.042637000328831e+00, -3.576853876064270e+00, -3.945297748528162e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbeint_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.173429560385275e-02, -1.227858965014073e-02, -1.310804917178980e-02, -1.440488210716536e-02, -1.650919541764154e-02, -2.011291316642621e-02, -2.678242100589763e-02, -4.051562197097091e-02, -7.223516163924361e-02, -1.421090943755736e-01, -2.924118119892444e-01, -5.518898991527975e-01, -6.524620454275373e-01, -1.169769511078712e+00, -2.923905860466064e+00, -9.903875783632801e-01, 4.853100654036989e+01, -3.991511567116758e+02, -1.344684358862893e+04, -1.116614209597856e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbeint_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.723398973143391e-08, 1.985126670129700e-08, 2.431770758376287e-08, 3.252988724990290e-08, 4.932968989563610e-08, 8.933907558466771e-08, 2.073552422339351e-07, 6.732215627071430e-07, 3.289786704434614e-06, 2.153425021545833e-05, 2.275867751451189e-04, 9.226554198947398e-03, 2.500186751309353e-02, 1.074579276487511e-01, 1.064762544648295e+00, -2.454925157195559e+01, -6.288198263945557e+03, -3.718772083024732e+05, -5.005977325361381e+07, -4.087512335159409e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbeint_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.825457628582334e-15, 3.734189837231948e-15, 5.572365347551970e-15, 9.893198440005294e-15, 2.250639908079349e-14, 7.282279197053510e-14, 3.872601198090124e-13, 4.106597227237770e-12, 1.095382535039231e-10, 8.708268780559908e-09, 1.589102746243848e-06, 3.075560476387532e-05, 7.613697055624792e-05, 2.623971686368883e-03, 4.848574804741256e-01, 4.476350591928946e+02, 6.085426607297036e+05, 1.122013924480664e+09, 1.817587792619958e+13, 1.152326325580913e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
