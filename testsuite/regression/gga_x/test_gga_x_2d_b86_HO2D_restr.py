
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_2d_b86_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.488250394023161e-01, -8.488228770378686e-01, -8.488171892321305e-01, -8.488022503566237e-01, -8.487631073794576e-01, -8.486609376919545e-01, -8.483958901314719e-01, -8.477149668890487e-01, -8.459921054563631e-01, -8.417342648446127e-01, -8.315800549589157e-01, -8.086214660618036e-01, -7.606934320813888e-01, -6.722406323183256e-01, -5.403121948114635e-01, -4.293928678174759e-01, -6.040120305150432e-01, -3.986330192072028e-01, -2.757935237112134e-02, -2.853183108753013e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_2d_b86_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.273237558115419e+00, -1.273234311339730e+00, -1.273225765884106e+00, -1.273203299247846e+00, -1.273144338716559e+00, -1.272990055224976e+00, -1.272588241145989e+00, -1.271549739388862e+00, -1.268898627357938e+00, -1.262263134259486e+00, -1.246163289075228e+00, -1.208915302308570e+00, -1.128566700505232e+00, -9.713274287727237e-01, -6.987196034666967e-01, -2.698479076683087e-01, 1.947656895367796e-01, -5.255345626296485e-01, -4.135605373699724e-02, -4.279774578765127e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b86_HO2D_restr_1_vsigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.318976276558771e-03, -8.319039884531480e-03, -8.319207249186026e-03, -8.319647058590793e-03, -8.320800475856326e-03, -8.323815732883169e-03, -8.331659511372328e-03, -8.351914692389547e-03, -8.403682329312195e-03, -8.534281825657840e-03, -8.859668465953170e-03, -9.668557763402969e-03, -1.174228129422207e-02, -1.766647150217681e-02, -3.964691624883003e-02, -1.765042407390811e-01, -1.700382793515069e+00, -1.528968951878173e+00, -3.707056661838198e-02, -1.323162498915442e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b86_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.000001561841971e+00, -1.000004116940273e+00, -1.000010850219964e+00, -1.000028587787864e+00, -1.000075286649709e+00, -1.000198110473087e+00, -1.000520590504246e+00, -1.001364702061520e+00, -1.003562597637808e+00, -1.009236254559204e+00, -1.023704121960187e+00, -1.060177372219031e+00, -1.152778252804766e+00, -1.406026723765611e+00, -2.300166817380291e+00, -7.963474513315470e+00, 3.654629344670297e+00, 6.901178842146822e+01, -9.597207372126908e+03, -9.308922157629617e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b86_HO2D_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.960118721676193e-02, 1.960143700213103e-02, 1.960209423449175e-02, 1.960382135803171e-02, 1.960835098117709e-02, 1.962019379884153e-02, 1.965101272666249e-02, 1.973067896502353e-02, 1.993484351614263e-02, 2.045352835745528e-02, 2.176847957604339e-02, 2.517601105926317e-02, 3.478335874056039e-02, 6.856649574919851e-02, 2.613892865389099e-01, 2.962967964366103e+00, 6.223642554492080e+00, -1.236372397591212e+04, -7.762632073793758e+04, -2.590205778863152e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b86_HO2D_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.534760221099013e-05, 1.534795426645788e-05, 1.534888062265341e-05, 1.535131515061024e-05, 1.535770111863582e-05, 1.537440406583382e-05, 1.541791292697864e-05, 1.553065324553835e-05, 1.582131263034008e-05, 1.657075426844761e-05, 1.854048424471397e-05, 2.410157750693187e-05, 4.320336566797859e-05, 1.474834266504910e-04, 1.683761240543510e-03, 1.583734353606436e-01, 3.012485951402747e+02, 3.562413023211948e+05, 2.957329388065100e+08, 5.416603008425589e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
