
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_vv10_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_vv10", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.115638584816993e+00, -4.032892794000663e+00, -3.917022339367824e+00, -3.756674631236422e+00, -3.538524815023152e+00, -3.248920503827084e+00, -2.877738969251717e+00, -2.425264282626868e+00, -1.910924265652798e+00, -1.373806193093754e+00, -8.456279237275623e-01, -4.794455803284439e-01, -3.979081946430369e-01, -2.931721622653215e-01, -1.615917640652229e-01, -5.554220276160875e-02, -6.360361465941321e-03, -1.347275484354867e-04, -1.112208629790834e-06, -1.497550807375681e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_vv10_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_vv10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.262000107397878e+00, -5.146660584184765e+00, -4.984910515567686e+00, -4.760584308313603e+00, -4.454406373538213e+00, -4.046006921024359e+00, -3.519066494556453e+00, -2.871709048423270e+00, -2.135239461839197e+00, -1.412669313659338e+00, -8.466079589548718e-01, -6.704785217160014e-01, -5.795905342099703e-01, -4.302582143895393e-01, -2.357686865225632e-01, -7.471615170645501e-02, -1.214818156299861e-02, -2.926886266851961e-04, -2.243543467733495e-06, -2.995719392206611e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_vv10_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_vv10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.091769790740471e-06, -3.354098366108775e-06, -3.769257197684416e-06, -4.453917175237279e-06, -5.651019416474334e-06, -7.923770397704035e-06, -1.276164943829111e-05, -2.478875601250176e-05, -6.136042607738557e-05, -1.994903825467877e-04, -9.486686056753461e-04, -1.722457047389789e-03, 1.146695186438366e-03, -2.292402112375542e-03, -1.922400868344336e-02, -1.344840448653224e-01, -9.616880271818125e-02, 4.556796639213011e-02, 6.035733129122767e-03, 1.504921713740989e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_vv10_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_vv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.254353819471531e-02, -1.313266661496808e-02, -1.402860652327143e-02, -1.542420883954407e-02, -1.767299288085290e-02, -2.147081433657790e-02, -2.830021095634946e-02, -4.156738819540523e-02, -6.870958760269301e-02, -1.084101681452497e-01, -2.275219469966847e-01, -5.548555917565203e-01, -6.097681072404452e-01, -1.106096616521041e+00, -3.412941598719474e+00, -6.858497677318957e+00, -1.119655461704076e+01, -1.299303260760933e+01, -8.289044998649036e+00, -7.769891931241360e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_vv10_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_vv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.702251008823270e-08, 3.088093481175058e-08, 3.738164252337174e-08, 4.910311544602733e-08, 7.236266253355705e-08, 1.251061882942761e-07, 2.684986427779997e-07, 7.620086469480952e-07, 2.919367731118362e-06, 7.395530684046380e-06, 3.768810945893895e-05, 1.023143417473328e-02, 1.060113975045103e-02, 9.794735929677206e-02, 1.762793091665161e+00, 1.839208129066105e+01, -6.234859329280198e+00, 9.099050111580276e+03, 1.380563811957321e+05, 2.578584692203376e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_lc_vv10_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_vv10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.678796781298669e-14, -6.631957297343064e-14, -8.234968820615608e-14, -1.105613681685131e-13, -1.610409484761211e-13, -2.316310628077910e-13, 1.650124332267507e-14, 7.431198553784315e-12, 2.258473995781342e-10, 1.467015997699874e-08, 1.916453791752446e-06, -7.136384820004352e-04, -7.754074960098326e-03, -4.329062150473260e-02, -1.706590346214719e+00, -8.325478051950080e+01, -9.333826062582710e+03, -2.593386880896940e+07, -4.600512260021229e+10, -6.593256676424772e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
