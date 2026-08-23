
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_karasiev_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.172577953967919e-01, -1.166571809298499e-01, -1.157953753363382e-01, -1.145602582378887e-01, -1.127932672234286e-01, -1.102721405035789e-01, -1.066897347348172e-01, -1.016325309435168e-01, -9.457968606419120e-02, -8.505278258781739e-02, -7.375601979759416e-02, -6.593131731660473e-02, -6.270017449460273e-02, -5.770648501960480e-02, -4.940494099414992e-02, -3.819864799537560e-02, -2.504546137797498e-02, -1.203255469441073e-02, -3.257073241724117e-03, -3.921241233419429e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_karasiev_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270735634184869e-01, -1.264627560124453e-01, -1.255860096727416e-01, -1.243288170649736e-01, -1.225288413622821e-01, -1.199576580065459e-01, -1.162976647436681e-01, -1.111168370500519e-01, -1.038606398018933e-01, -9.399312133852725e-02, -8.217940639342766e-02, -7.391840919824537e-02, -7.048817821882952e-02, -6.516565471380269e-02, -5.626390979887438e-02, -4.414858552888126e-02, -2.973598910684415e-02, -1.495327429744674e-02, -4.246258952004996e-03, -5.213398199921113e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_karasiev_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.573219804012933e-05, -5.920653655079792e-05, -6.457908717140519e-05, -7.315326651042604e-05, -8.747013293465215e-05, -1.129750145660041e-04, -1.628133639746228e-04, -2.738779975610824e-04, -5.712024676495911e-04, -1.577507336594136e-03, -5.513604227750509e-03, -1.366899981116088e-02, -2.013987422428458e-02, -3.730974104993977e-02, -1.101669018763063e-01, -5.552645120981822e-01, -5.296060693308016e+00, -1.066088299688407e+02, -4.420019437472063e+03, -4.437126621551894e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
