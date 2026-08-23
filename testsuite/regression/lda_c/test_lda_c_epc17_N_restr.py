
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_epc17_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.759541560503387e-03, -1.871602570022249e-03, -2.045326320218990e-03, -2.323648245047663e-03, -2.791209965065552e-03, -3.632484557459130e-03, -5.305222314920648e-03, -9.159079522010538e-03, -2.024368790493991e-02, -6.386603865573395e-02, -1.614987964804173e-01, -8.090950040026604e-02, -5.160728864611342e-02, -2.506720896513561e-02, -7.368316845179992e-03, -1.245781068134331e-03, -1.045257200001455e-04, -3.424005527852768e-06, -3.038469570899854e-08, -4.107231271872077e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_epc17_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.453572753037410e-05, 1.642296218064999e-05, 1.957031920114519e-05, 2.517026698573970e-05, 3.610486200456701e-05, 6.050056412663793e-05, 1.263309072566875e-04, 3.582859704936914e-04, 1.507430699148883e-03, 6.569875470503979e-03, -1.800148869697113e-01, -1.672935144453150e-01, -1.089899282656962e-01, -5.229160428587192e-02, -1.497395583586789e-02, -2.498895966312717e-03, -2.091038143369429e-04, -6.848067327597111e-06, -6.076939584949811e-08, -8.214462544553883e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_epc17_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.618579880078733e-07, -1.943773083227796e-07, -2.528409077052819e-07, -3.687654450337940e-07, -6.334375116208712e-07, -1.373567935619865e-06, -4.140653000284342e-06, -1.970433672297775e-05, -1.658378951508584e-04, -2.515344985262078e-04, 1.642811472358620e-01, -2.559366031564502e-01, -2.933064223063508e-01, -2.728362404419673e-01, -2.340044626090169e-01, -2.165457967016934e-01, -2.130859474452036e-01, -2.127764477391516e-01, -2.127660505403224e-01, -2.127659575726471e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
