
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_rpaf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpaf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.197478934161586e-01, -1.191771031384763e-01, -1.183585675135758e-01, -1.171864441845044e-01, -1.155115863807439e-01, -1.131260226810459e-01, -1.097445416724102e-01, -1.049873799069945e-01, -9.838394895544908e-02, -8.951622175598981e-02, -7.906272634792157e-02, -7.184796970372058e-02, -6.887261513719788e-02, -6.427821916858575e-02, -5.665988591740957e-02, -4.653747441998021e-02, -3.587131637775480e-02, -2.791243131280087e-02, -2.023224038995910e-02, -1.383879797738981e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_rpaf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpaf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.290784721675395e-01, -1.284935485679452e-01, -1.276544377297415e-01, -1.264522106835398e-01, -1.247330000653241e-01, -1.222814630512700e-01, -1.188005883049412e-01, -1.138912415190668e-01, -1.070507552031967e-01, -9.781288874619669e-02, -8.683850381332632e-02, -7.920522853516185e-02, -7.604175753257288e-02, -7.113675925355065e-02, -6.293518036576753e-02, -5.179004873627521e-02, -3.915975195204469e-02, -2.978607285605036e-02, -2.153932673378973e-02, -1.458601787697995e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_rpaf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpaf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.338300427248039e-05, -5.668423934550408e-05, -6.178592968047767e-05, -6.992051607667896e-05, -8.348574092529986e-05, -1.076063894487939e-04, -1.546131522455711e-04, -2.589676860752550e-04, -5.368628861968872e-04, -1.471243102504598e-03, -5.103871986219402e-03, -1.261142928657913e-02, -1.856670789823067e-02, -3.437484268088813e-02, -1.015117154314264e-01, -5.081900846991728e-01, -4.201886337151291e+00, -6.047606212311258e+01, -5.057894687656883e+03, -2.021813645266315e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
