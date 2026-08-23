
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_xc_b93_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_b93", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.140548690024530e+00, -2.098207402354031e+00, -2.038858066671738e+00, -1.956605545418810e+00, -1.844446905089477e+00, -1.695015347789826e+00, -1.502389241020235e+00, -1.265451899910821e+00, -9.929661346474876e-01, -7.102762397116230e-01, -4.700804609798991e-01, -3.484160360827387e-01, -3.066045811730338e-01, -2.502015740991025e-01, -1.751647454374622e-01, -1.030141948044683e-01, -4.912956010022009e-02, -1.761775576710315e-02, -4.111200038290378e-03, -4.966924468207947e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_xc_b93_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_b93", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.839202944224088e+00, -2.782841077855978e+00, -2.703842213749642e+00, -2.594363377801875e+00, -2.445091518910421e+00, -2.246237852825834e+00, -1.989952696179552e+00, -1.674807546076919e+00, -1.312559578180863e+00, -9.370626326728638e-01, -6.184625484007594e-01, -4.573770397439728e-01, -4.020924886675571e-01, -3.276005840393012e-01, -2.287188912463033e-01, -1.340407537129950e-01, -6.379798557523787e-02, -2.294967062779746e-02, -5.400127745389609e-03, -6.581787014533734e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_xc_b93_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_b93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.193102878173558e-03, -5.410000520659195e-03, -5.737592813891289e-03, -6.243015916617808e-03, -7.046971237951728e-03, -8.382968365413617e-03, -1.074655146133983e-02, -1.531851395925123e-02, -2.533928955935907e-02, -5.107209305935456e-02, -1.223814739891735e-01, -2.327201031335348e-01, -3.069299441421062e-01, -4.782024256054250e-01, -1.051538145665660e+00, -3.486400172908648e+00, -1.939495489332592e+01, -2.146918805845956e+02, -5.895046894419173e+03, -5.527026776606322e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
