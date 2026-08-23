
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pk09_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pk09", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.182035830642094e-01, -1.176271595401730e-01, -1.167982716320246e-01, -1.156068121689154e-01, -1.138955478986011e-01, -1.114415571857887e-01, -1.079331843597973e-01, -1.029472337067890e-01, -9.595045799406926e-02, -8.645739441020073e-02, -7.516351211263328e-02, -6.729900262146611e-02, -6.403318305448330e-02, -5.895630051832516e-02, -5.041665833178258e-02, -3.868765338176074e-02, -2.488409926380941e-02, -1.169886852697123e-02, -3.047731887555107e-03, -3.628108236832793e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pk09_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pk09", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.276154058234366e-01, -1.270462969724770e-01, -1.262266517960704e-01, -1.250458823865149e-01, -1.233447349023773e-01, -1.208948240095179e-01, -1.173719568685412e-01, -1.123271683458415e-01, -1.051803547580942e-01, -9.537946625198157e-02, -8.360492201010411e-02, -7.535603396128221e-02, -7.192124767945610e-02, -6.657048223020820e-02, -5.752886577223209e-02, -4.495735008237410e-02, -2.974578880639922e-02, -1.459834725745973e-02, -4.004894916039294e-03, -4.804283519387437e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pk09_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pk09", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.185420947631167e-05, -5.524184194963910e-05, -6.049028089223447e-05, -6.888793435063159e-05, -8.295730747117589e-05, -1.081265224512673e-04, -1.575448187100796e-04, -2.681848192427693e-04, -5.652679561743668e-04, -1.570669900762277e-03, -5.499520502797458e-03, -1.367167355474164e-02, -2.019260108992942e-02, -3.762465675195686e-02, -1.128288046178282e-01, -5.833237610336002e-01, -5.561373869090678e+00, -1.063416508814365e+02, -4.323063101683303e+03, -4.023343854614219e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
