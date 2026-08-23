
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_tih_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_tih", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.628205209830129e+00, -5.569848346612088e+00, -5.487479241548882e+00, -5.370653058846104e+00, -5.204404888089672e+00, -4.971764587782659e+00, -4.649870330759223e+00, -4.113441405488802e+00, -3.204678128187683e+00, -2.038379373876875e+00, -1.280536090632648e+00, -1.079819036399921e+00, -1.011060806102134e+00, -8.644799984589724e-01, -5.935935661504541e-01, -4.286640139620407e-01, -3.925854142336858e-01, -3.893052890976348e-01, -3.891949493360098e-01, -3.891939626775783e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_tih_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_tih", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.376522393255585e-03, -5.608868178077045e-03, -6.028178341547461e-03, -6.778368137757504e-03, -8.039583491902468e-03, -1.002628710450516e-02, -1.463363715396365e-02, -3.279566909233492e-02, -6.867722154858573e-02, -1.669891012591629e-01, -1.848800777629151e-01, -2.594096661037205e-01, -4.470740975193984e-01, -1.200973521366784e+00, -2.635652822782419e+00, -3.321098459292425e+00, -3.447713026588130e+00, -3.458794403868099e+00, -3.459165917065500e+00, -3.459169238769710e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
