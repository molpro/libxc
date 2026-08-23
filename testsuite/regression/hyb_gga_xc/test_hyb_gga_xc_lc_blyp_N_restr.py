
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_blyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.190297649293425e+00, -4.108082560400695e+00, -3.992925145393354e+00, -3.833495992546497e+00, -3.616436517414603e+00, -3.327893357174269e+00, -2.957099392147249e+00, -2.502585681598935e+00, -1.979568661898260e+00, -1.421228025097354e+00, -8.766777896555933e-01, -5.278291757571315e-01, -4.354247775832676e-01, -3.338208151148965e-01, -1.923575549825081e-01, -5.760056200898143e-02, 5.555290312514837e-03, -3.467050809601138e-03, -9.128924809956734e-04, -1.023989265361040e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_blyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.277236251290431e+00, -5.164119007342754e+00, -5.005634058686183e+00, -4.786144379632285e+00, -4.487204301949190e+00, -4.089757830870102e+00, -3.579515581982027e+00, -2.957379922078101e+00, -2.256571846566307e+00, -1.564104340080128e+00, -1.005674642098044e+00, -7.033443540447790e-01, -6.034568481909527e-01, -4.621065269701088e-01, -2.912038449812592e-01, -1.449219490146714e-01, -4.587102750730303e-02, -4.949081042710222e-03, -1.212940010607426e-03, -1.364626930758809e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.803409442171140e-06, -4.093310919149285e-06, -4.547511333484823e-06, -5.285735001149444e-06, -6.549595623655043e-06, -8.877100681486404e-06, -1.361849585193639e-05, -2.468334130495504e-05, -5.539248829396540e-05, -1.592688231545594e-04, -6.161923951735855e-04, -3.618359286066753e-03, -6.663194068412628e-03, -9.285322625701298e-03, -4.815405677483547e-03, 2.437719922183129e-01, 4.215522812813161e+00, 5.243301789660631e+00, -2.828135158254753e-05, -6.380209847038626e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.173717427260340e-02, -1.225028437789170e-02, -1.302576287301536e-02, -1.422270960948788e-02, -1.612554885858261e-02, -1.927591437388231e-02, -2.477837180062942e-02, -3.501322351763853e-02, -5.493884452686436e-02, -9.042740275651256e-02, -1.526014293358449e-01, -4.589949727683406e-01, -6.062012399652966e-01, -8.600060869193032e-01, -1.190819348152004e+00, 3.871070373213454e-01, 1.210005357002992e+01, -8.797639782518964e+01, -1.392627286366857e+03, -1.175221821771884e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.849369824897988e-08, 2.090968165600920e-08, 2.492102326105924e-08, 3.200031047998788e-08, 4.560872368123188e-08, 7.502605359203886e-08, 1.492373614313595e-07, 3.731666557112375e-07, 1.103861682299100e-06, -1.448279660142377e-07, -1.692884825888505e-04, 1.966736117729140e-03, 9.133030947799258e-03, -7.745414679186585e-03, -6.777536914612053e-01, -3.904828240296214e+01, -3.502729653592428e+03, 1.636568507748011e+05, -3.589057475792316e+02, -6.286506802648154e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.885574763029446e-14, 1.231527366683878e-13, 1.687927507650911e-13, 2.651461316505364e-13, 5.056946832356871e-13, 1.269259193869491e-12, 4.683708489789292e-12, 2.948821651782210e-11, 3.841084102300825e-10, 1.312111606631678e-08, 1.551197573019131e-06, 3.367054567127818e-04, 2.750661323927965e-03, 1.622786187454872e-02, 4.811640876333502e-01, 4.392772365540414e+01, 3.888297271826068e+03, 3.735880136738413e+05, 9.772780825960377e+07, 1.329187205085465e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
