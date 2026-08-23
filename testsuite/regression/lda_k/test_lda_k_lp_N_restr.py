
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_k_lp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.431844963479533e+01, 9.054646944532848e+01, 8.538972674332392e+01, 7.849457088627368e+01, 6.956327605990882e+01, 5.850759806779118e+01, 4.567718088596773e+01, 3.208761721494721e+01, 1.944311341819892e+01, 9.687171029223723e+00, 4.072130138662249e+00, 2.156935688915808e+00, 1.641490805055062e+00, 1.060743347114421e+00, 4.897008459607279e-01, 1.524829854041648e-01, 2.932986179502663e-02, 3.003709421695828e-03, 1.287487207045957e-04, 1.574003917685788e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_k_lp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.571974160579922e+02, 1.509107824088808e+02, 1.423162112388732e+02, 1.308242848104561e+02, 1.159387934331814e+02, 9.751266344631864e+01, 7.612863480994622e+01, 5.347936202491202e+01, 3.240518903033154e+01, 1.614528504870621e+01, 6.786883564437082e+00, 3.594892814859680e+00, 2.735818008425104e+00, 1.767905578524035e+00, 8.161680766012133e-01, 2.541383090069413e-01, 4.888310299171106e-02, 5.006182369493046e-03, 2.145812011743262e-04, 2.623339862809647e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_k_lp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.851818745700412e-01, 5.972462505252242e-01, 6.150159522635096e-01, 6.414597087174299e-01, 6.813953713706208e-01, 7.429901528234433e-01, 8.408906943648982e-01, 1.003276081111732e+00, 1.288861609232222e+00, 1.825957684669270e+00, 2.816296452182101e+00, 3.869640273289306e+00, 4.435779662030184e+00, 5.518029706970016e+00, 8.121266560912451e+00, 1.455387026984678e+01, 3.318441639622009e+01, 1.036955773835333e+02, 5.008615939847087e+02, 4.529875730410677e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
