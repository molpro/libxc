
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_1d_ehwlrg_1_HO1D_2_zk():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_1", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.142922757200915e-01, -5.142891079471936e-01, -5.142807732178231e-01, -5.142588730161057e-01, -5.142014553666046e-01, -5.140514720012543e-01, -5.136621260009917e-01, -5.126622097306432e-01, -5.101425288381649e-01, -5.040084871560072e-01, -4.900032819509779e-01, -4.616509613768378e-01, -4.155610751035694e-01, -3.621843628642922e-01, -3.056894253252225e-01, -2.005309158977227e-01, -6.966562394873724e-02, -9.154250588085451e-03, -2.800320485809539e-04, -8.202342173301258e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_1d_ehwlrg_1_HO1D_2_vrho():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_1", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.135734163681252e+00, -1.135734163681252e+00, -1.135719936200841e+00, -1.135719936200841e+00, -1.135682502283087e+00, -1.135682502283087e+00, -1.135584141625248e+00, -1.135584141625248e+00, -1.135326261729357e+00, -1.135326261729357e+00, -1.134652646444413e+00, -1.134652646444413e+00, -1.132904023983131e+00, -1.132904023983131e+00, -1.128413453765659e+00, -1.128413453765659e+00, -1.117099284496232e+00, -1.117099284496232e+00, -1.089566499464808e+00, -1.089566499464808e+00, -1.026784659004086e+00, -1.026784659004086e+00, -9.003175711149043e-01, -9.003175711149043e-01, -6.995493973482102e-01, -6.995493973482102e-01, -4.976566284522549e-01, -4.976566284522549e-01, -4.025143937852139e-01, -4.025143937852139e-01, -3.003357790146537e-01, -3.003357790146537e-01, -1.125192636659944e-01, -1.125192636659944e-01, -1.498623496597581e-02, -1.498623496597581e-02, -4.586914066022566e-04, -4.586914066022566e-04, -1.343543647645473e-06, -1.343543647645473e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_1d_ehwlrg_1_HO1D_2_v2rho2():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_1", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.473550751639080e+00, -2.473550751639080e+00, -2.473550751639080e+00, -2.473518779164833e+00, -2.473518779164833e+00, -2.473518779164833e+00, -2.473434655299013e+00, -2.473434655299013e+00, -2.473434655299013e+00, -2.473213605398899e+00, -2.473213605398899e+00, -2.473213605398899e+00, -2.472634009061321e+00, -2.472634009061321e+00, -2.472634009061321e+00, -2.471119671297271e+00, -2.471119671297271e+00, -2.471119671297271e+00, -2.467186216290917e+00, -2.467186216290917e+00, -2.467186216290917e+00, -2.457068783122356e+00, -2.457068783122356e+00, -2.457068783122356e+00, -2.431473771042734e+00, -2.431473771042734e+00, -2.431473771042734e+00, -2.368551191911249e+00, -2.368551191911249e+00, -2.368551191911249e+00, -2.221457461692583e+00, -2.221457461692583e+00, -2.221457461692583e+00, -1.907303243321823e+00, -1.907303243321823e+00, -1.907303243321823e+00, -1.339177098011449e+00, -1.339177098011449e+00, -1.339177098011449e+00, -5.978915949058023e-01, -5.978915949058023e-01, -5.978915949058023e-01, -2.004894046636541e-01, -2.004894046636541e-01, -2.004894046636541e-01, -8.637890509595670e-01, -8.637890509595670e-01, -8.637890509595670e-01, -3.010443398415778e+00, -3.010443398415778e+00, -3.010443398415778e+00, -1.057976032505219e+01, -1.057976032505219e+01, -1.057976032505219e+01, -7.684676804347249e+01, -7.684676804347249e+01, -7.684676804347249e+01, -2.103807981716397e+03, -2.103807981716397e+03, -2.103807981716397e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
