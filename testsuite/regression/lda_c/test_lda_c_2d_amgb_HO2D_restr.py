
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_2d_amgb_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_amgb", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.231287758737777e-01, -1.231286873467637e-01, -1.231284544154491e-01, -1.231278423147652e-01, -1.231262371454518e-01, -1.231220416627624e-01, -1.231111332814812e-01, -1.230830039119040e-01, -1.230113788131113e-01, -1.228323990429785e-01, -1.223968990900224e-01, -1.213736791193589e-01, -1.190674842272813e-01, -1.140896015369834e-01, -1.037728915027816e-01, -8.348251333824688e-02, -4.936397083875476e-02, -1.453240433339635e-02, -1.171893830942085e-03, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_2d_amgb_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_amgb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.404955149663093e-01, -1.404954388901580e-01, -1.404952387192923e-01, -1.404947127061811e-01, -1.404933332864656e-01, -1.404897278120270e-01, -1.404803531941439e-01, -1.404561770913706e-01, -1.403946061277236e-01, -1.402406748432946e-01, -1.398656739469156e-01, -1.389820744161218e-01, -1.369774009952522e-01, -1.325862641020231e-01, -1.231884937464770e-01, -1.033928553981789e-01, -6.554768222548236e-02, -2.064427126311786e-02, -1.741855514278160e-03, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_2d_amgb_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_amgb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.344294424414815e-02, -2.344308863698922e-02, -2.344346856549604e-02, -2.344446697290527e-02, -2.344708536361596e-02, -2.345393031781412e-02, -2.347173541015438e-02, -2.351770267736174e-02, -2.363509604315910e-02, -2.393063909023885e-02, -2.466302021031701e-02, -2.645981602261125e-02, -3.092690894246975e-02, -4.284251689103915e-02, -8.092586749686952e-02, -2.536016728077958e-01, -1.531547775512173e+00, -1.650160361862436e+01, -3.916174796211288e+02, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
