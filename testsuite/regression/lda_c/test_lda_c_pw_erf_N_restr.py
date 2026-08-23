
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pw_erf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_erf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.143677896630396e-01, -1.137192291954140e-01, -1.127871441842509e-01, -1.114481761870991e-01, -1.095259606251398e-01, -1.067690508312318e-01, -1.028203336293491e-01, -9.717617341727305e-02, -8.914465961960234e-02, -7.792511306625087e-02, -6.388667960273178e-02, -5.357316124108396e-02, -4.916510397050892e-02, -4.220387195600681e-02, -3.037829740233541e-02, -1.468921485372470e-02, -2.633336773857603e-03, -1.016280287659630e-04, -8.975159859832445e-07, -1.212908971122331e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pw_erf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_erf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.249602937791996e-01, -1.243144383006785e-01, -1.233862649400913e-01, -1.220529651434517e-01, -1.201389855515170e-01, -1.173940857417091e-01, -1.134629665995268e-01, -1.078447782634023e-01, -9.985205473837774e-02, -8.869043711327035e-02, -7.471257833807471e-02, -6.436498488055453e-02, -5.988841583977270e-02, -5.271519180177899e-02, -4.021075497289528e-02, -2.241038203381263e-02, -4.861461594600873e-03, -2.034269098821389e-04, -1.795184011261957e-06, -2.425820409063299e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pw_erf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_erf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.890130523488104e-05, -6.263457934477263e-05, -6.841637841691144e-05, -7.766451396315920e-05, -9.315862461143264e-05, -1.209008866871189e-04, -1.755360748174360e-04, -2.988074375839601e-04, -6.356230932962736e-04, -1.816650347165220e-03, -6.725428650287706e-03, -1.761309039011592e-02, -2.662073742237504e-02, -5.121564914927077e-02, -1.575319927497054e-01, -8.328115806290013e-01, -3.922446491512124e+00, -6.321934743160329e+00, -6.286726675254017e+00, -6.283227890838960e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
