
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vwn_4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.185824111041210e-01, -1.179948579179800e-01, -1.171517402045461e-01, -1.159432742143997e-01, -1.142140730362047e-01, -1.117459656347624e-01, -1.082364208735578e-01, -1.032750321795206e-01, -9.633539411103011e-02, -8.690347401572221e-02, -7.558765451071978e-02, -6.763486596716875e-02, -6.431845541102740e-02, -5.915359033637706e-02, -5.046522676057628e-02, -3.859808808378642e-02, -2.477698306709388e-02, -1.175955052319235e-02, -3.353399297887107e-03, -4.454830836829644e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vwn_4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.281844970089497e-01, -1.275874295610536e-01, -1.267304650055301e-01, -1.255017456641820e-01, -1.237427102045497e-01, -1.212302148673413e-01, -1.176537010166022e-01, -1.125893229066586e-01, -1.054874301312930e-01, -9.579531430810051e-02, -8.409315737719926e-02, -7.580841680547026e-02, -7.233593493934938e-02, -6.690427618596151e-02, -5.769113963470407e-02, -4.491095884768395e-02, -2.961921641404512e-02, -1.458205703580527e-02, -4.316809613949938e-03, -5.873120727295062e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vwn_4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.448017149215148e-05, -5.787298508578485e-05, -6.311958879217173e-05, -7.149319654607447e-05, -8.547675326711742e-05, -1.103941706795647e-04, -1.591120919810207e-04, -2.678185155978298e-04, -5.596838149584364e-04, -1.554165254331764e-03, -5.497060239539110e-03, -1.379637883562512e-02, -2.045009874115646e-02, -3.827110588915796e-02, -1.150357335936071e-01, -5.903110815391877e-01, -5.558495540907302e+00, -1.042651957678047e+02, -4.253884283253365e+03, -4.813344872327053e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
