
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.123759716085011e-02, -6.106943218190817e-02, -6.081943604492026e-02, -6.044227018373092e-02, -5.986087099053471e-02, -5.893593649785146e-02, -5.739479701126333e-02, -5.464958299167929e-02, -4.931574669191897e-02, -3.851942047736292e-02, -2.757576257670772e-02, -4.120734741489564e-02, -4.101764338883682e-02, -3.454254934263504e-02, -2.190251291391559e-02, -1.275465908408974e-03, 1.220269948652407e-02, -3.235727194607825e-03, -9.108326858672550e-04, -1.023961420889946e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.771727150669461e-02, -6.778345481435906e-02, -6.788577411908817e-02, -6.804878610813661e-02, -6.831954359079714e-02, -6.879558392420027e-02, -6.969836957749311e-02, -7.158237585696089e-02, -7.593437783597869e-02, -8.592098919032358e-02, -9.057159877107156e-02, -5.576530627018002e-02, -5.043208237525431e-02, -5.126692518551532e-02, -5.269384736361098e-02, -5.373170688312724e-02, -3.313754987452720e-02, -4.487673348321922e-03, -1.208820589539621e-03, -1.364571241821358e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.311008544917941e-08, 5.891723568868898e-08, 6.839131164754366e-08, 8.472509282516809e-08, 1.152129719486837e-07, 1.790072734826092e-07, 3.363244764573939e-07, 8.273517895363371e-07, 2.967358795860769e-06, 1.746450587813502e-05, 1.554118339258821e-04, 7.512977417932514e-04, 1.462985488379339e-03, 4.172921849223739e-03, 2.493026931282792e-02, 2.925511277679759e-01, 4.235069725348803e+00, 5.244898795282883e+00, 7.435325164346740e-10, 1.884753025935382e-139]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.154264052837646e-05, 4.614629922922017e-05, 5.365765080907261e-05, 6.660814600963133e-05, 9.077752114118107e-05, 1.413164961951366e-04, 2.656664883177742e-04, 6.509389233611789e-04, 2.284692995646671e-03, 1.206557180125359e-02, 5.785137551190033e-02, 1.668792801830256e-02, 2.877957921629365e-03, 5.361922106487729e-02, 4.495121081192579e-01, 4.513854003329142e+00, 2.335171472742377e+01, -7.377231245543086e+01, -1.378206526628154e+03, -1.175077579757398e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.026209698773901e-10, -5.928761514379781e-10, -7.516586509547962e-10, -1.056864315785480e-09, -1.723402738237779e-09, -3.473391421800908e-09, -9.466691070773377e-09, -3.957334402680627e-08, -3.007751063727082e-07, -5.012420315357269e-06, -1.613460560965718e-04, -1.984420464202706e-03, -5.755218874613607e-03, -3.090298239464235e-02, -5.569307641301551e-01, -3.272163547718650e+01, -3.446949069436947e+03, 1.638224236940590e+05, 2.905166407798053e-02, 5.579311791278084e-128]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_lyp", 1)
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
