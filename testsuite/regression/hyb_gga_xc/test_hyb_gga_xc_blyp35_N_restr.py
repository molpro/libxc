
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_blyp35_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_blyp35", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.871092757892974e+00, -2.817798981618301e+00, -2.743165746833555e+00, -2.639871450835764e+00, -2.499307043881720e+00, -2.312604209305699e+00, -2.073031062240941e+00, -1.780178839291789e+00, -1.445005832268611e+00, -1.089970440325665e+00, -7.358417712329489e-01, -4.754549128338523e-01, -4.081885395543227e-01, -3.431358248047821e-01, -2.500132974154080e-01, -1.528120955266262e-01, -8.298404357186853e-02, -6.222726550945597e-02, -3.891293640745422e-02, -2.647610632789757e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_blyp35_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_blyp35", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.563824222530410e+00, -3.489984219369030e+00, -3.386506079111058e+00, -3.243147669835077e+00, -3.047793007233681e+00, -2.787845019557154e+00, -2.453656413969790e+00, -2.045215112403565e+00, -1.583319805391763e+00, -1.124833354114387e+00, -7.576859921470229e-01, -5.766346805268576e-01, -5.149640532638522e-01, -4.135315138419865e-01, -2.890649815304810e-01, -1.812670915526428e-01, -9.302590797016194e-02, -3.063540641171952e-02, -1.158485150307719e-02, -4.449952751386037e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_blyp35_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_blyp35", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.633275418137277e-06, -2.837773114477042e-06, -3.158873200285785e-06, -3.682480163350126e-06, -4.583380552590179e-06, -6.255329693558773e-06, -9.703882643257236e-06, -1.792327298162236e-05, -4.163955125121691e-05, -1.286180696066143e-04, -5.830035173423117e-04, -3.913026500853362e-03, -7.835660258355684e-03, -1.410354418192018e-02, -3.893295388734040e-02, -1.064519337409541e-01, -3.086615867993991e-01, -1.130748656350067e+02, -1.097058308482886e+04, -6.523074630864630e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_blyp35_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_blyp35", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.736014023457479e-03, -8.079031928538394e-03, -8.598153746769812e-03, -9.401071656856708e-03, -1.068157997694449e-02, -1.281236514678755e-02, -1.656527827034431e-02, -2.364839141333412e-02, -3.781811595458384e-02, -6.447942191558134e-02, -1.152964918516484e-01, -3.363381095254794e-01, -4.333486183216076e-01, -6.741753541161302e-01, -1.117055915368842e+00, 6.788011801014808e-01, 1.829939449498654e+01, 3.646702792335384e+01, 1.064393371929474e+04, 6.642580904578106e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_blyp35_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_blyp35", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.312709393950287e-08, 1.487482556286820e-08, 1.778703503348507e-08, 2.295464139858678e-08, 3.297358317076675e-08, 5.493794335707953e-08, 1.117457998164951e-07, 2.921639063558351e-07, 9.768578995239551e-07, 2.149162237446993e-06, -6.883270036012559e-05, 3.848218939935674e-03, 1.640058950503353e-02, 2.944754900354121e-02, -1.889170415235131e-01, -3.174045081451630e+01, -4.482454513990732e+03, -6.948171171874747e+05, -6.570263021551788e+09, -2.216741458492342e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_blyp35_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_blyp35", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.835875380636359e-14, 8.526730652180369e-14, 1.170839641306863e-13, 1.844286758532350e-13, 3.532210605454979e-13, 8.923141373453245e-13, 3.326996226118320e-12, 2.131410235571186e-11, 2.865029371974793e-10, 1.041466710201193e-08, 1.385831812545001e-06, 3.377411232105419e-04, 2.971098869037617e-03, 1.996551238735545e-02, 8.507920129210086e-01, 2.394584514985324e+02, 4.883912878076372e+05, 1.298009269062116e+10, 1.573266653248271e+16, 5.231808890978918e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
