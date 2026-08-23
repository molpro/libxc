
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_ncap_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_ncap", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.378512970932805e+00, -4.295958331935026e+00, -4.180372043963001e+00, -4.020452884941917e+00, -3.802962579348613e+00, -3.514401804557453e+00, -3.144931294417524e+00, -2.695365204419629e+00, -2.185935613307638e+00, -1.655795886367998e+00, -1.118798437203376e+00, -7.116563982540122e-01, -6.170073750664312e-01, -5.132490666861453e-01, -3.753256165185239e-01, -2.433832699533155e-01, -1.613312857085930e-01, -1.737219247379105e-01, -2.776947915891728e-01, -5.451491024521496e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_ncap_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_ncap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.497536386488166e+00, -5.381617927284623e+00, -5.219016820965510e+00, -4.993428203784046e+00, -4.685353918487504e+00, -4.274056729937370e+00, -3.742594371033341e+00, -3.088096140297742e+00, -2.340589485623652e+00, -1.592920716729476e+00, -1.033425507197621e+00, -8.845211768540353e-01, -7.944283122059815e-01, -6.308037949139851e-01, -4.226048405679521e-01, -2.302768950100428e-01, -5.041665940651768e-02, 5.726401492506849e-02, 1.319488597443064e-01, 2.013407130352899e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_ncap_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_ncap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.433441239115309e-06, -3.728151312341539e-06, -4.195194245285259e-06, -4.966971125286650e-06, -6.320460987470518e-06, -8.901976469287008e-06, -1.443729321796983e-05, -2.836306509322597e-05, -7.159514312987668e-05, -2.468602058925225e-04, -1.219400489355866e-03, -4.149887041662585e-03, -5.602911971727719e-03, -1.576290992068190e-02, -6.635605312982036e-02, -4.861442268675640e-01, -1.099632693233226e+01, -6.496384700612714e+02, -1.366931306937376e+05, -1.962535688445004e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_ncap_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_ncap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.287759740194110e-02, -1.349745313097837e-02, -1.444220592994346e-02, -1.591876730146106e-02, -1.831035922707426e-02, -2.238311231075761e-02, -2.980957634031219e-02, -4.458202251752970e-02, -7.688935375040078e-02, -1.556556212018835e-01, -3.862103242593471e-01, -5.838041842587424e-01, -6.774681987723417e-01, -1.211401141846864e+00, -2.933125242027892e+00, -1.324996391555572e+01, -2.185244276234093e+02, -3.874560430265257e+03, -6.662835887715637e+05, -6.168899853541250e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_ncap_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_ncap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.099076830189039e-08, 3.550174838035558e-08, 4.312764476625829e-08, 5.694851461463759e-08, 8.459360455648322e-08, 1.481026573442566e-07, 3.247005499031595e-07, 9.581876399388714e-07, 4.096597829073456e-06, 2.842338882742062e-05, 5.033136969545917e-04, 1.118532959981992e-02, 2.722357154727145e-02, 1.146032606697470e-01, 1.011426438809951e+00, 4.149339428850124e+01, 1.406804943782301e+04, 1.011133092405110e+07, 2.234800536103557e+11, 1.671928494914726e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_ncap_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_ncap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.291087588459047e-14, -8.639373796421964e-14, -1.098005529529323e-13, -1.534322783393691e-13, -2.417991847130556e-13, -4.296081250628309e-13, -6.833078950454731e-13, 3.410101246012107e-12, 1.730054960776634e-10, 1.020946431932686e-08, 1.226765561538448e-06, -2.416306385653273e-04, -3.931261830180868e-03, -9.102629740488075e-03, 1.815946254888465e-01, 5.089058308545214e+01, 3.458228402232897e+04, 3.796261709703957e+10, 1.129135052230596e+17, 1.079528395671876e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
