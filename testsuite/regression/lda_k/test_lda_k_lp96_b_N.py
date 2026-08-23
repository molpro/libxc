
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_k_lp96_b_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp96_b", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.909134583423423e-02, 4.901388344321138e-02, 4.890057589438322e-02, 4.873374642000483e-02, 4.848602605775348e-02, 4.811455179200438e-02, 4.755300935431038e-02, 4.671040650289535e-02, 4.555184446305360e-02, 4.482922562780618e-02, 5.062204951138925e-02, 7.125805991239373e-02, 9.038109619721134e-02, 1.463258011745464e-01, 4.169925225041329e-01, 2.369179413067944e+00, 2.841263258046137e+01, 8.701490562438527e+02, 9.805082018513576e+04, 7.252554244195198e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_k_lp96_b_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp96_b", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.034722231356548e-02, 5.034722231356548e-02, 5.028860683061041e-02, 5.028860683061041e-02, 5.020228630352215e-02, 5.020228630352215e-02, 5.007386174354998e-02, 5.007386174354998e-02, 4.987998660375501e-02, 4.987998660375501e-02, 4.958113566267337e-02, 4.958113566267337e-02, 4.910656382014422e-02, 4.910656382014422e-02, 4.832056782418345e-02, 4.832056782418345e-02, 4.694177229274350e-02, 4.694177229274350e-02, 4.436087763064437e-02, 4.436087763064437e-02, 3.964373727064134e-02, 3.964373727064134e-02, 3.468585209309732e-02, 3.468585209309732e-02, 3.204642490460527e-02, 3.204642490460527e-02, 2.705000292209634e-02, 2.705000292209634e-02, 1.529619252744988e-02, 1.529619252744988e-02, -1.214479584707360e-02, -1.214479584707360e-02, -7.874592417185608e-02, -7.874592417185608e-02, -1.574966908208725e-01, -1.574966908208725e-01, 4.520643534609002e+00, 4.520643534609002e+00, 5.437059201844231e+02, 5.437059201844231e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_k_lp96_b_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp96_b", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.292289011400244e-06, 5.292289011400244e-06, 5.292289011400244e-06, 5.741618677332976e-06, 5.741618677332976e-06, 5.741618677332976e-06, 6.454736678102651e-06, 6.454736678102651e-06, 6.454736678102651e-06, 7.636249830495392e-06, 7.636249830495392e-06, 7.636249830495392e-06, 9.718568357532369e-06, 9.718568357532369e-06, 9.718568357532369e-06, 1.372883731976179e-05, 1.372883731976179e-05, 1.372883731976179e-05, 2.249966276275846e-05, 2.249966276275846e-05, 2.249966276275846e-05, 4.550888109314186e-05, 4.550888109314186e-05, 4.550888109314186e-05, 1.235443114454749e-04, 1.235443114454749e-04, 1.235443114454749e-04, 4.946334106071574e-04, 4.946334106071574e-04, 4.946334106071574e-04, 2.767288014839489e-03, 2.767288014839489e-03, 2.767288014839489e-03, 9.742340716467228e-03, 9.742340716467228e-03, 9.742340716467228e-03, 1.670907558559279e-02, 1.670907558559279e-02, 1.670907558559279e-02, 3.949973335544089e-02, 3.949973335544089e-02, 3.949973335544089e-02, 1.795324614831030e-01, 1.795324614831030e-01, 1.795324614831030e-01, 1.703830017647715e+00, 1.703830017647715e+00, 1.703830017647715e+00, 3.447941174566822e+01, 3.447941174566822e+01, 3.447941174566822e+01, -8.885948544290059e+02, -8.885948544290059e+02, -8.885948544290059e+02, -1.328669604004579e+07, -1.328669604004579e+07, -1.328669604004579e+07, -9.578865780918628e+11, -9.578865780918628e+11, -9.578865780918628e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
