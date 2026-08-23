
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.348831777374131e+00, -1.349320540654924e+00, -1.350106512380363e+00, -1.351362661327327e+00, -1.353349942745587e+00, -1.356440956648692e+00, -1.361111494652838e+00, -1.367815964209844e+00, -1.376541170797112e+00, -1.385609855454157e+00, -1.389039327640093e+00, -1.371890388672100e+00, -1.304869647440575e+00, -1.145070563377624e+00, -9.169332767090010e-01, -6.592474584878156e-01, -4.441679300568999e-01, -3.069531135187891e-01, -2.212984668864977e-01, -1.634217352360129e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_vsigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_vlapl():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_vtau():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.724795033166433e+00, -1.724412843721418e+00, -1.723799950637625e+00, -1.722824853894660e+00, -1.721293723122070e+00, -1.718941827533860e+00, -1.715463342494605e+00, -1.710658055373266e+00, -1.704867779882420e+00, -1.700009411172885e+00, -1.701552944299678e+00, -1.721226872716551e+00, -1.776962692549979e+00, -1.865045744203531e+00, -1.525615902450718e+00, 5.620775752602856e+00, 1.270008124515872e+02, 7.333484604070908e+03, 3.788831490868493e+06, 7.599320082506136e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.557291070046473e-02, -6.565002497419396e-02, -6.577581475035944e-02, -6.598158328692134e-02, -6.631970684364877e-02, -6.687933673548474e-02, -6.781617565741208e-02, -6.941247990864254e-02, -7.220711740663678e-02, -7.730311180943852e-02, -8.717985938636247e-02, -1.081927298964152e-01, -1.601533794053464e-01, -3.266184191488039e-01, -1.553124717081278e+00, -1.302255693340661e+01, -6.064976025217449e+02, -4.590371650893750e+05, -3.221814562155326e+10, -3.563033144450418e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -1.683818917925166e-01, -2.741452226888199e-01, -9.133988764702112e-01, -1.077602012497688e+01, -1.166086010350440e+03, -4.999004276445410e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.339590499813356e-01, 3.343500841727002e-01, 3.349862279536832e-01, 3.360223323893781e-01, 3.377130685078151e-01, 3.404805539924619e-01, 3.450332021992623e-01, 3.525834286561630e-01, 3.652703139921909e-01, 3.870463891471854e-01, 4.257321059530542e-01, 4.984038669986641e-01, 6.479264093629131e-01, 1.005323804605860e+00, 2.776481493833531e+00, 8.361439611802826e+00, 6.149413862053317e+01, 1.868055118592043e+03, 5.537669124911582e+05, 6.552413141442062e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_prhg07_prp10_HO2D_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_prhg07_prp10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
