
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_1d_loos_HO1D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_loos", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.158710637041348e-03, -7.158750069244461e-03, -7.158853822539133e-03, -7.159126465135127e-03, -7.159841427793134e-03, -7.161710054870554e-03, -7.166567905776013e-03, -7.179090567204205e-03, -7.210948926144768e-03, -7.290381213937889e-03, -7.482570249822530e-03, -7.927602873287377e-03, -8.891926370322158e-03, -1.074137374464856e-02, -1.323797625456931e-02, -1.258185786691068e-02, -4.629672664969303e-03, -2.777346701725145e-04, -1.279124402598132e-06, -1.376571141149085e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_1d_loos_HO1D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_loos", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.768864113273517e-04, 5.768406757617971e-04, 5.767203362603662e-04, 5.764041021641980e-04, 5.755747841406918e-04, 5.734069805930002e-04, 5.677693515539790e-04, 5.532231494213704e-04, 5.161294587209975e-04, 4.230948922595983e-04, 1.947070907014443e-04, -3.526289960440302e-04, -1.635056876337951e-03, -4.555976409150639e-03, -1.044292062925907e-02, -1.605400115144357e-02, -8.034361052827094e-03, -5.423634935325701e-04, -2.554477202095796e-06, -2.753100419997700e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_1d_loos_HO1D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_loos", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.951375029157593e-03, 7.951442356461230e-03, 7.951619508922290e-03, 7.952085044036558e-03, 7.953305936370362e-03, 7.956497539724869e-03, 7.964799309157783e-03, 7.986230372543311e-03, 8.040951447820317e-03, 8.178639809589529e-03, 8.519279136894936e-03, 9.350129078591316e-03, 1.136736940220708e-02, 1.620344121487706e-02, 2.509762568151486e-02, 2.454542113897803e-03, -2.329163776748970e-01, -5.656012363657515e-01, -6.683216847759903e-01, -6.756770743069795e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
