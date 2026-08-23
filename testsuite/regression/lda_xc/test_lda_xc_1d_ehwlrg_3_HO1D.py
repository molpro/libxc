
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_1d_ehwlrg_3_HO1D_2_zk():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_3", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.271781198862936e-01, -5.271746650191421e-01, -5.271655749079914e-01, -5.271416898226184e-01, -5.270790678569771e-01, -5.269154874864471e-01, -5.264908273187940e-01, -5.254001025778324e-01, -5.226508575455228e-01, -5.159534907968198e-01, -5.006377477503288e-01, -4.695235538589119e-01, -4.186366864884241e-01, -3.598395505671745e-01, -3.026089861868358e-01, -2.031020128492897e-01, -7.428696061345705e-02, -1.068206846816394e-02, -3.808228421322628e-04, -1.440891251178145e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_1d_ehwlrg_3_HO1D_2_vrho():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_3", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.204940926966486e+00, -1.204940926966486e+00, -1.204925734449964e+00, -1.204925734449964e+00, -1.204885761382057e+00, -1.204885761382057e+00, -1.204780728596802e+00, -1.204780728596802e+00, -1.204505353765000e+00, -1.204505353765000e+00, -1.203786025163915e+00, -1.203786025163915e+00, -1.201918639841415e+00, -1.201918639841415e+00, -1.197122436960961e+00, -1.197122436960961e+00, -1.185034072166797e+00, -1.185034072166797e+00, -1.155591874922008e+00, -1.155591874922008e+00, -1.088312471084026e+00, -1.088312471084026e+00, -9.520813454985757e-01, -9.520813454985757e-01, -7.331082163445465e-01, -7.331082163445465e-01, -5.062720921858509e-01, -5.062720921858509e-01, -3.949524686098697e-01, -3.949524686098697e-01, -2.987034978897545e-01, -2.987034978897545e-01, -1.178978674598397e-01, -1.178978674598397e-01, -1.718825052541257e-02, -1.718825052541257e-02, -6.131232879442089e-04, -6.131232879442089e-04, -2.319834913794484e-06, -2.319834913794484e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_1d_ehwlrg_3_HO1D_2_v2rho2():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_3", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.641328483327574e+00, -2.641328483327574e+00, -2.641328483327574e+00, -2.641295945300862e+00, -2.641295945300862e+00, -2.641295945300862e+00, -2.641210333327022e+00, -2.641210333327022e+00, -2.641210333327022e+00, -2.640985372727799e+00, -2.640985372727799e+00, -2.640985372727799e+00, -2.640395519449311e+00, -2.640395519449311e+00, -2.640395519449311e+00, -2.638854362222801e+00, -2.638854362222801e+00, -2.638854362222801e+00, -2.634851104376988e+00, -2.634851104376988e+00, -2.634851104376988e+00, -2.624553196770636e+00, -2.624553196770636e+00, -2.624553196770636e+00, -2.598495590004570e+00, -2.598495590004570e+00, -2.598495590004570e+00, -2.534398321054347e+00, -2.534398321054347e+00, -2.534398321054347e+00, -2.384340941469171e+00, -2.384340941469171e+00, -2.384340941469171e+00, -2.062715667362229e+00, -2.062715667362229e+00, -2.062715667362229e+00, -1.475934311845724e+00, -1.475934311845724e+00, -1.475934311845724e+00, -6.915351409915739e-01, -6.915351409915739e-01, -6.915351409915739e-01, -2.165038775656379e-01, -2.165038775656379e-01, -2.165038775656379e-01, -8.033628368211453e-01, -8.033628368211453e-01, -8.033628368211453e-01, -3.005579322741142e+00, -3.005579322741142e+00, -3.005579322741142e+00, -1.160020778977195e+01, -1.160020778977195e+01, -1.160020778977195e+01, -9.821136004768785e+01, -9.821136004768785e+01, -9.821136004768785e+01, -3.473126127787339e+03, -3.473126127787339e+03, -3.473126127787339e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
