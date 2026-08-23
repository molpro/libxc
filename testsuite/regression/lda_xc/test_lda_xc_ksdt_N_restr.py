
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_ksdt_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_ksdt", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.280322471556699e+00, -4.195532820607146e+00, -4.076687247798046e+00, -3.911985193622148e+00, -3.687412824338641e+00, -3.388237611492293e+00, -3.002639290075516e+00, -2.528450055809544e+00, -1.983326434162728e+00, -1.418143302864961e+00, -9.383579307295974e-01, -6.955514957918527e-01, -6.121460579875496e-01, -4.996615957973705e-01, -3.500458621929106e-01, -2.061424295532887e-01, -9.851420106015284e-02, -3.538203933295376e-02, -8.218324282260780e-03, -9.807935697488967e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_ksdt_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_ksdt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.679412827359409e+00, -5.566516552824215e+00, -5.408279892761026e+00, -5.188997189751491e+00, -4.890023061237132e+00, -4.491769109648037e+00, -3.978550149243895e+00, -3.347577104700858e+00, -2.622524219015336e+00, -1.871364704615569e+00, -1.234582836705303e+00, -9.129318735212935e-01, -8.026036750926544e-01, -6.539993783884794e-01, -4.568277948376717e-01, -2.680574079326309e-01, -1.278515137599693e-01, -4.609173318169447e-02, -1.080929612132346e-02, -1.301243892623765e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_ksdt_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_ksdt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.040217966698123e-02, -1.083648198517881e-02, -1.149241007309462e-02, -1.250435212985242e-02, -1.411388277496485e-02, -1.678825458461896e-02, -2.151875245790065e-02, -3.066639621673892e-02, -5.070627194626250e-02, -1.021265299863382e-01, -2.444606815250917e-01, -4.644977070928962e-01, -6.124266411744901e-01, -9.537680091807084e-01, -2.096406293499430e+00, -6.953430886928500e+00, -3.875893407737632e+01, -4.308138685526220e+02, -1.186060290807279e+04, -1.098400835247235e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
