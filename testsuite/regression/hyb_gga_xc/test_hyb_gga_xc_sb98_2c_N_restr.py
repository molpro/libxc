
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_sb98_2c_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2c", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.451589425354801e+00, -3.385766117458936e+00, -3.293559684449007e+00, -3.165900322876551e+00, -2.992126708036093e+00, -2.761318336832912e+00, -2.465506159237988e+00, -2.105667639469845e+00, -1.700050382632672e+00, -1.285445509071690e+00, -8.745769623466702e-01, -5.664501692197056e-01, -4.923914269545691e-01, -4.083765943664742e-01, -2.977761628599941e-01, -1.904185914381315e-01, -9.567410321600621e-02, -2.881480970340845e-02, -4.976461484700628e-03, -4.857430677828175e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_sb98_2c_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2c", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.408995337169428e+00, -4.318778560256562e+00, -4.192056409765445e+00, -4.015877965333376e+00, -3.774501106245152e+00, -3.450604196992766e+00, -3.028662648935744e+00, -2.502208233659312e+00, -1.888870534109921e+00, -1.266738902181749e+00, -8.213812592383356e-01, -7.118425991036671e-01, -6.299905721230484e-01, -5.076117601790077e-01, -3.355049958500084e-01, -1.943867626425611e-01, -1.095963482263268e-01, -3.898336922834782e-02, -6.787852905087571e-03, -6.524235194046989e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2c_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2c", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.816459539977160e-06, -1.965351078045002e-06, -2.203417704586007e-06, -2.602272683184803e-06, -3.316897442558053e-06, -4.725765655707559e-06, -7.901528827929309e-06, -1.648938898797857e-05, -4.582033845555727e-05, -1.758399138611438e-04, -8.997289478310786e-04, -2.602039467023021e-03, -5.792606556334042e-03, -1.039265455154526e-02, -5.257459784417252e-02, -3.147591266084540e-01, -1.421944845590737e+00, -1.751143716392684e+00, -8.872932291205937e-02, 1.345004250560747e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2c_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.163573550800221e-03, -9.633757860401153e-03, -1.035623599060589e-02, -1.149860989873908e-02, -1.337996292792309e-02, -1.666157440012839e-02, -2.286217569155784e-02, -3.590469348730364e-02, -6.688909526152187e-02, -1.418031181608346e-01, -3.076878345137162e-01, -4.627592575089743e-01, -3.912843590395474e-01, -1.026524927417303e+00, -2.413942898295808e+00, -4.409908808470944e+00, 8.549804814045368e+00, -3.631428470913330e+02, -8.714510149195170e+03, -5.822834513287203e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2c_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.208755406086578e-08, 1.449590727685995e-08, 1.872331940531984e-08, 2.677880649041591e-08, 4.397517139177765e-08, 8.686094378607747e-08, 2.188978328225377e-07, 7.576464777275352e-07, 3.902270739996254e-06, 3.013596256594864e-05, 4.080599340959865e-04, 8.496142301341538e-03, -3.251844999550806e-02, 1.111156152245788e-01, 8.802414135215363e-01, -8.618000067045019e-01, -3.052688603456465e+03, -2.098878818615812e+05, -2.317184826446073e+06, 1.364472683806100e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2c_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.279229507258951e-14, 8.730007474564404e-15, -8.218845032616609e-16, -2.584121564137310e-14, -1.010892293746683e-13, -3.719113572328419e-13, -1.596654317134619e-12, -8.709762248456012e-12, -4.231388940137131e-11, 3.431874069168128e-09, 8.238929904007528e-07, -2.686663037791223e-04, 1.893573969940723e-02, -1.933894842390304e-02, 7.926943151717948e-02, 1.713194507242929e+02, 3.157667666067013e+05, 6.005492282502103e+08, 4.229768180954683e+11, -3.928610096003500e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
