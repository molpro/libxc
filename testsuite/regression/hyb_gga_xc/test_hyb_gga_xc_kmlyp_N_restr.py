
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_kmlyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_kmlyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.949514557577958e+00, -1.911851340177819e+00, -1.859050149817111e+00, -1.785853524672460e+00, -1.686002179636263e+00, -1.552877846203224e+00, -1.381070500879533e+00, -1.169268531678323e+00, -9.245333442072170e-01, -6.679347563104703e-01, -4.485803173874906e-01, -3.456782469008638e-01, -3.080242653976949e-01, -2.543113467190710e-01, -1.806842415411657e-01, -1.053185006483405e-01, -4.857242750814235e-02, -2.382182139521782e-02, -6.893861584442934e-03, -1.021343836313608e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_kmlyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_kmlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.572625286516135e+00, -2.522645607863486e+00, -2.452593909218500e+00, -2.355518423441684e+00, -2.223168952323448e+00, -2.046887825403913e+00, -1.819778707575217e+00, -1.540766347079913e+00, -1.220852704810796e+00, -8.913541703020298e-01, -6.095379241104182e-01, -4.500177804495668e-01, -3.981245536301826e-01, -3.316605060459089e-01, -2.432004819033916e-01, -1.575449586402955e-01, -8.304176413833321e-02, -3.012274027979420e-02, -8.783365736116211e-03, -1.331161209727535e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_kmlyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_kmlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.379331828123237e-08, 2.639492158853266e-08, 3.063930761809956e-08, 3.795684158567531e-08, 5.161541143301031e-08, 8.019525852020890e-08, 1.506733654529125e-07, 3.706536017122789e-07, 1.329376740545624e-06, 7.824098633404489e-06, 6.962450159879520e-05, 3.365813883233767e-04, 6.554174987939440e-04, 1.869468988452235e-03, 1.116876065214691e-02, 1.310629052400532e-01, 1.897311236956264e+00, 2.349714660286733e+00, 3.331025673627351e-10, 8.443693556190801e-140]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_kmlyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_kmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.589108468211161e-03, -4.779639979862916e-03, -5.067176539786169e-03, -5.510227830542567e-03, -6.213462437134792e-03, -7.377667251267086e-03, -9.422317017149722e-03, -1.331456783606446e-02, -2.149977829976800e-02, -4.005408182851516e-02, -8.329494760544488e-02, -2.007664631485309e-01, -2.737549843378843e-01, -4.056716622922110e-01, -7.494709665189356e-01, -1.175295673765358e+00, -7.937213807971597e+00, -2.567044691133327e+02, -8.324917267320227e+03, -1.035779079956247e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_kmlyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_kmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.251741945050708e-10, -2.656085158442142e-10, -3.367430756277487e-10, -4.734752134718951e-10, -7.720844267305250e-10, -1.556079356966807e-09, -4.241077599706473e-09, -1.772885812400921e-08, -1.347472476549733e-07, -2.245564301280056e-06, -7.228303313126416e-05, -8.890203679628125e-04, -2.578338055826896e-03, -1.384453611279977e-02, -2.495049823303095e-01, -1.465929269377955e+01, -1.544233183107753e+03, 7.339244581493846e+04, 1.301514550693532e-02, 2.499531682492667e-128]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_kmlyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_kmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
