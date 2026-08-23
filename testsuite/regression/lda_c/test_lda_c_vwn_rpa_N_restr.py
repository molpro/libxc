
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vwn_rpa_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_rpa", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.410728648590941e-01, -1.404662075665247e-01, -1.395953563657676e-01, -1.383464735808659e-01, -1.365580512175386e-01, -1.340025098293458e-01, -1.303625214588930e-01, -1.252037661395189e-01, -1.179603725188959e-01, -1.080568209246740e-01, -9.606727220154075e-02, -8.755280754926753e-02, -8.397592309538625e-02, -7.836914392389727e-02, -6.881631317392892e-02, -5.542608491151217e-02, -3.898195145508535e-02, -2.167546607928894e-02, -7.846245286892675e-03, -1.335562479689184e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vwn_rpa_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_rpa", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.509856739448639e-01, -1.503721668994864e-01, -1.494913189728936e-01, -1.482277566072900e-01, -1.464175904242886e-01, -1.438294483768511e-01, -1.401397549038587e-01, -1.349034841375829e-01, -1.275357816338194e-01, -1.174287066965750e-01, -1.051307835697066e-01, -9.634779453768041e-02, -9.264392254519027e-02, -8.681926450366988e-02, -7.683555031315836e-02, -6.268833917215536e-02, -4.499011273191001e-02, -2.578946528633687e-02, -9.726278843459417e-03, -1.725317482369915e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vwn_rpa_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_rpa", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.597275846832540e-05, -5.947440483263356e-05, -6.489128807221123e-05, -7.354126333435942e-05, -8.799756888334757e-05, -1.137868219904235e-04, -1.642949081394259e-04, -2.772839705686071e-04, -5.818411429213231e-04, -1.625998518846404e-03, -5.804810780068874e-03, -1.468737025802391e-02, -2.185611787094601e-02, -4.118532381944267e-02, -1.256105812051631e-01, -6.639595486718025e-01, -6.667965568928449e+00, -1.448174559982130e+02, -7.888772248529422e+03, -1.284203569621249e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
