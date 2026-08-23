
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_upw92_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_upw92", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.181785815647394e-01, -1.175894747821141e-01, -1.167442217512348e-01, -1.155328966132673e-01, -1.138000414661218e-01, -1.113276830194121e-01, -1.078142614688481e-01, -1.028523619515022e-01, -9.592351573910257e-02, -8.653193580517465e-02, -7.530893738167485e-02, -6.744956803188715e-02, -6.417753224351123e-02, -5.908547679046670e-02, -5.051753564119377e-02, -3.875849712925160e-02, -2.488595706359627e-02, -1.172698990289337e-02, -3.349693752811730e-03, -4.547980625172912e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_upw92_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_upw92", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.278064869589163e-01, -1.272069774109885e-01, -1.263465620693366e-01, -1.251130141678808e-01, -1.233473330995406e-01, -1.208259592416662e-01, -1.172382613105135e-01, -1.121616086543474e-01, -1.050514645625477e-01, -9.537035316012604e-02, -8.372616845719719e-02, -7.551704056157023e-02, -7.208485280645549e-02, -6.672524897290630e-02, -5.765090438521949e-02, -4.504564613728312e-02, -2.978084047334460e-02, -1.456379863443658e-02, -4.303682685515459e-03, -5.981856036020152e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_upw92_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_upw92", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.470437208723912e-05, -5.810821961115605e-05, -6.337131279303205e-05, -7.176985936773590e-05, -8.579153238730761e-05, -1.107669954721961e-04, -1.595672166789319e-04, -2.683410441449303e-04, -5.598496790699270e-04, -1.549953077424406e-03, -5.456688387795812e-03, -1.364605833271769e-02, -2.019869505346324e-02, -3.772952359155542e-02, -1.132556023348771e-01, -5.842958441193837e-01, -5.601442639726502e+00, -1.052482561224198e+02, -4.210976406067382e+03, -4.851570909057143e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
