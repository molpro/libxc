
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_sb98_1c_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1c", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.554854234980353e+00, -3.487331600975853e+00, -3.392758660502318e+00, -3.261851307856535e+00, -3.083713672198891e+00, -2.847221186651763e+00, -2.544331504983998e+00, -2.176212207173942e+00, -1.761527525983897e+00, -1.336653067218732e+00, -9.103190790493345e-01, -5.831809966794926e-01, -5.073195385101796e-01, -4.203417389302760e-01, -3.075858654332823e-01, -1.983411702510441e-01, -1.009553160102233e-01, -3.099610789296849e-02, -5.485940350433819e-03, -5.445415651616345e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_sb98_1c_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1c", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.522027798438075e+00, -4.428764165607307e+00, -4.297772917345934e+00, -4.115685812532170e+00, -3.866281029688976e+00, -3.531783700504669e+00, -3.096470630979142e+00, -2.554431866966570e+00, -1.925598970124611e+00, -1.292777870797285e+00, -8.393790204141039e-01, -7.307279214811234e-01, -6.537627726990254e-01, -5.202698478913418e-01, -3.410794792752267e-01, -1.977060394331203e-01, -1.144013246269266e-01, -4.169038340175077e-02, -7.458928191685924e-03, -7.306791623501006e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1c_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1c", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.074834565189349e-06, -2.250060022550831e-06, -2.529982741232368e-06, -2.998186950190365e-06, -3.834523600709229e-06, -5.474487959029267e-06, -9.137734210050819e-06, -1.890351923657066e-05, -5.158383473457744e-05, -1.930297524479907e-04, -9.797625912791323e-04, -2.875356615713017e-03, -4.192369734043448e-03, -1.164091906845481e-02, -5.985186927017486e-02, -3.540538986670156e-01, -1.565092583077259e+00, -2.064132657534830e+00, -5.962896746003545e-01, 6.966632799995397e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1c_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.736783759459761e-03, -1.023497845699867e-02, -1.099943242936370e-02, -1.220570745757953e-02, -1.418628447604654e-02, -1.762525477927292e-02, -2.407717923908797e-02, -3.748653923381556e-02, -6.861943411790981e-02, -1.403935962973613e-01, -2.976834230550412e-01, -5.052776646223590e-01, -4.592963284885142e-01, -1.116813256278814e+00, -2.530585826638374e+00, -3.818497188237211e+00, 1.382335860069766e+01, -3.722651336804343e+02, -9.437778515621078e+03, -6.492368166813815e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1c_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.620676179295380e-08, 1.912671861944233e-08, 2.419387642056150e-08, 3.370632352890722e-08, 5.363268329197673e-08, 1.021934061151600e-07, 2.476629001261054e-07, 8.220184517474257e-07, 4.031142884655803e-06, 2.894528290501159e-05, 3.702767419459604e-04, 1.123785395670250e-02, -1.245855729632847e-02, 1.385705204448788e-01, 9.634622757666712e-01, -4.788316001239501e+00, -3.528016164109350e+03, -2.471346834704081e+05, -9.345678253559753e+06, 6.945053894149861e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1c_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.278476995096079e-14, -2.081000718434620e-14, -3.694487261404753e-14, -7.340450900733308e-14, -1.691694471629418e-13, -4.731338569932309e-13, -1.678377317512594e-12, -7.337130290829433e-12, -1.535428197697027e-12, 5.473176251762304e-09, 1.102631983586318e-06, -4.529279235138052e-04, 9.002455233634793e-03, -2.715727113070304e-02, 1.343769897694608e-01, 2.175020494421861e+02, 3.624458538032420e+05, 7.158998160735338e+08, 3.001310475633147e+12, -2.034973179611840e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
