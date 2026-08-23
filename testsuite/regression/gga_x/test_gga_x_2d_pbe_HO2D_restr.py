
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_2d_pbe_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.488250402426913e-01, -8.488228806246357e-01, -8.488172045112116e-01, -8.488023152414227e-01, -8.487633815511968e-01, -8.486620870241013e-01, -8.484006479555697e-01, -8.477342815090539e-01, -8.460682260823985e-01, -8.420215613515968e-01, -8.326012311808766e-01, -8.119786882852321e-01, -7.707095236250036e-01, -6.982712521820120e-01, -5.875654376745928e-01, -4.083356332813700e-01, -1.735994972034716e-01, -3.503509837199822e-02, -2.277291806440789e-03, -2.355571732566282e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_2d_pbe_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.273237556854856e+00, -1.273234305959579e+00, -1.273225742965488e+00, -1.273203201920710e+00, -1.273143927460066e+00, -1.272988331246363e+00, -1.272581104745953e+00, -1.271520773002648e+00, -1.268784532717279e+00, -1.261833425869559e+00, -1.244647374402616e+00, -1.204057092637969e+00, -1.115269147654899e+00, -9.467922385348000e-01, -7.202280552818653e-01, -5.389477353713702e-01, -2.565688795679968e-01, -5.253493857642643e-02, -3.415934928500400e-03, -3.533357598668648e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_pbe_HO2D_restr_1_vsigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.954571100459986e-02, -2.954593634140329e-02, -2.954652831258322e-02, -2.954807998095077e-02, -2.955213274161867e-02, -2.956265881090516e-02, -2.958976140894565e-02, -2.965864061922240e-02, -2.983044144847630e-02, -3.024832202008547e-02, -3.123419123385300e-02, -3.348324144968261e-02, -3.840381568867467e-02, -4.799721116997470e-02, -5.716322250305848e-02, -3.469123339889119e-02, -5.916774234299326e-03, -3.739072793813878e-04, -7.946099338419523e-06, -2.835271775959663e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_pbe_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.000001566792204e+00, -1.000004138068247e+00, -1.000010940223089e+00, -1.000028970011930e+00, -1.000076901883434e+00, -1.000204883029373e+00, -1.000548641273129e+00, -1.001478714005712e+00, -1.004013071296969e+00, -1.010943853361450e+00, -1.029796328808070e+00, -1.079904963509684e+00, -1.203987384611316e+00, -1.424408293904333e+00, -1.111044266456563e+00, -4.940568927289576e-01, -8.804847203723712e+00, -5.148109273792387e+01, -7.949502221567525e+02, -7.685394652440630e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_pbe_HO2D_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.961565783105975e-02, 6.961654091567135e-02, 6.961885788415501e-02, 6.962491870392352e-02, 6.964069703275579e-02, 6.968146437923863e-02, 6.978557501726296e-02, 7.004682725757408e-02, 7.068604338598941e-02, 7.219701600452175e-02, 7.561028066209230e-02, 8.281346038889408e-02, 9.536751542718051e-02, 9.254558173969796e-02, -1.775697230390129e-01, -1.350512832205868e+00, -2.034356563578201e+00, -3.305330435585279e+00, -1.664291059314126e+01, -5.550291401288241e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_x_2d_pbe_HO2D_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.017567891690027e-03, 7.017728661886324e-03, 7.018151360804296e-03, 7.019260837267033e-03, 7.022165185127418e-03, 7.029737210015746e-03, 7.049361179035670e-03, 7.099810546570169e-03, 7.228311186585571e-03, 7.553582679851983e-03, 8.383966096817966e-03, 1.061092917342485e-02, 1.745660057845131e-02, 4.511819827990917e-02, 1.991364186402536e-01, 9.427325038537947e-01, 4.224173271435973e+00, 9.306821821323867e+01, 6.340099838667588e+04, 1.160669366245310e+10]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
