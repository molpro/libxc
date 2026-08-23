
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_x_sogga11_x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_sogga11_x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.531676157497519e+00, -2.481792645908989e+00, -2.411888352380957e+00, -2.315040292641160e+00, -2.183039436647933e+00, -2.007272630179486e+00, -1.780836563090480e+00, -1.502395011839872e+00, -1.181683589599009e+00, -8.424501775026726e-01, -5.424822599472476e-01, -3.858751583044154e-01, -3.327294572974602e-01, -2.717870115441630e-01, -1.887310745509681e-01, -9.050876155211504e-02, -4.496782043176712e-04, 8.827959063799218e-05, 1.976999190283009e-06, 2.942230402805329e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_x_sogga11_x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_sogga11_x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.288635689522533e+00, -3.221791079958504e+00, -3.128173323905779e+00, -2.998589756042625e+00, -2.822225638480955e+00, -2.587928079300343e+00, -2.287185961024062e+00, -1.919409503851918e+00, -1.502214286207428e+00, -1.123567535094046e+00, -8.081824066931604e-01, -4.969049877897662e-01, -4.344194331899282e-01, -3.486142069190523e-01, -2.416074374182217e-01, -2.522648441856150e-01, 3.895721556826414e-03, 1.278689071440169e-04, 7.122143288404468e-06, 4.598167064955001e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_sogga11_x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_sogga11_x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.327692509527929e-07, -9.974088866205781e-07, -1.097416653052808e-06, -1.256932529177277e-06, -1.522383283182940e-06, -1.990694676476260e-06, -2.886234060110934e-06, -4.803208274005092e-06, -9.256613383011102e-06, 1.209761988300315e-07, 2.260541767371594e-04, -1.411896201543148e-03, -3.425278219724467e-03, -5.115331357768201e-03, -9.454641952218939e-03, 7.046165643960789e-01, -3.047325713482992e-01, -2.290063351003883e-02, -1.221430055273516e+00, -1.427594299304185e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_sogga11_x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_sogga11_x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.288167829151467e-03, -6.538613414782300e-03, -6.914533775920134e-03, -7.489249695495259e-03, -8.391425776528759e-03, -9.863798092374849e-03, -1.241410274573022e-02, -1.720345193500624e-02, -2.412220230073033e-02, 6.025806690254867e-02, 5.358788479374305e-01, -2.661273740711707e-01, -3.649406954991689e-01, -5.313485228302658e-01, -4.289594310751548e-01, 4.243563899763137e+01, -5.951165990572629e+01, -2.734665977330334e+01, 6.859591389562888e+01, 1.096182836761810e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_sogga11_x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_sogga11_x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.792339839834621e-09, 1.866613736139493e-09, 1.944713031814924e-09, 1.966512119683417e-09, 1.686523321912352e-09, 1.021906816052938e-10, -7.198210212855412e-09, -4.590112650086334e-08, -7.257298400464588e-07, -4.981521267973963e-05, -1.873899363010219e-03, -1.054105377605767e-04, 4.741552759256784e-03, -4.719491910238008e-03, -7.284580924065516e-01, -2.659125800268980e+02, 4.123890077596369e+03, 6.460662195221143e+04, -1.641332720228448e+07, -1.478324566441977e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_sogga11_x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_sogga11_x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.528318136387300e-14, 6.889849011608541e-14, 9.437673567971320e-14, 1.477489227421980e-13, 2.788343254052978e-13, 6.805650043897898e-13, 2.346979874917732e-12, 1.296302708014531e-11, 1.844743293053897e-10, 2.003495829524758e-08, 4.491351976127249e-06, 2.523661123741819e-04, 2.364949636973710e-03, 1.361701330886642e-02, 8.636901433349358e-01, 9.917547951180361e+02, -2.515085523538450e+05, -1.434455660615746e+08, 6.021269519246991e+12, 4.168115907182722e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
