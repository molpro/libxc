
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_epc17_2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17_2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.494556065163245e-04, -9.033117773414488e-04, -9.867462157745264e-04, -1.120273233420338e-03, -1.344196580217742e-03, -1.745873931919705e-03, -2.539989620840568e-03, -4.347725238217548e-03, -9.399577904333165e-03, -2.801132356534987e-02, -8.580488090004788e-02, -6.913133907782036e-02, -4.813454436790064e-02, -2.461904202073546e-02, -7.355970121017606e-03, -1.245719643676187e-03, -1.045256835198436e-04, -3.424005526569838e-06, -3.038469570899765e-08, -4.107231271872077e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_epc17_2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17_2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.387810338914771e-06, 3.825600118141107e-06, 4.554950210571082e-06, 5.850526775935930e-06, 8.373485023405331e-06, 1.397583072138675e-05, 2.895785063056238e-05, 8.073285740801367e-05, 3.249935879176364e-04, 1.263817716466876e-03, -5.081522200669617e-02, -1.221321505274899e-01, -9.481521014740223e-02, -5.043851624617848e-02, -1.492381564519629e-02, -2.498649551351779e-03, -2.091036683792026e-04, -6.848067322465348e-06, -6.076939584949453e-08, -8.214462544553883e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_epc17_2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.756222729015755e-08, -4.507247029785053e-08, -5.855574635344601e-08, -8.523233073214692e-08, -1.459175883644908e-07, -3.145352710481646e-07, -9.372196207366886e-07, -4.346625307504129e-06, -3.420689828756910e-05, -2.362295194429423e-05, 7.942250851838295e-02, -6.813409768619455e-02, -1.896184536267058e-01, -2.455531635940134e-01, -2.317038603477443e-01, -2.164819870316035e-01, -2.130855013822281e-01, -2.127764472608095e-01, -2.127660505402847e-01, -2.127659575726471e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
