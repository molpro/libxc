
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_wpbesol_whs_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbesol_whs", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.983979245366338e+00, -3.900354290449290e+00, -3.783207632833163e+00, -3.621000383050746e+00, -3.400128245614048e+00, -3.106521080142086e+00, -2.729463873648184e+00, -2.268611057609514e+00, -1.743874350658418e+00, -1.202206637512985e+00, -7.032392782450700e-01, -4.157763649578263e-01, -3.438425604989393e-01, -2.428412810023844e-01, -1.217652974615764e-01, -3.386733324491383e-02, -3.297484765370976e-03, -7.989470114514364e-05, -6.319385601607748e-07, -8.425773814442777e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_wpbesol_whs_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbesol_whs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.257865977847771e+00, -5.143506410056338e+00, -4.983135457652164e+00, -4.760722321996409e+00, -4.457124246667507e+00, -4.051991772579902e+00, -3.528534451170497e+00, -2.882797170009318e+00, -2.139865716598482e+00, -1.382894987247429e+00, -8.024764425539829e-01, -6.204619740234145e-01, -5.204434439799415e-01, -3.845565395903837e-01, -2.136884011180895e-01, -6.947269729927309e-02, -8.502780363144238e-03, -1.980334215961518e-04, -1.303590953396514e-06, -1.686451288181793e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbesol_whs_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbesol_whs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.497081202664667e-06, -1.630009746893472e-06, -1.841383175682971e-06, -2.192426683422238e-06, -2.812704041851744e-06, -4.009403341111817e-06, -6.621638880988938e-06, -1.338019206613031e-05, -3.523150706293235e-05, -1.272370359492228e-04, -6.011991108520426e-04, 4.584996622330503e-04, 3.430510100521628e-03, 5.188222811831585e-03, 1.715601410761034e-02, 5.763819902494466e-02, 1.504974699231247e-01, 1.003840580092369e-01, 1.269129571458191e-02, 3.166392323804725e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbesol_whs_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbesol_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.174331207643433e-02, -1.228366959974502e-02, -1.310603466638783e-02, -1.438910215063157e-02, -1.646411893881849e-02, -1.999797358293950e-02, -2.647703465353763e-02, -3.962203641347922e-02, -6.976594756600883e-02, -1.471591540163923e-01, -3.657168717224768e-01, -4.760469125366208e-01, -5.610244485740907e-01, -8.991356907733340e-01, -2.257564422817880e+00, -1.046256235810621e+01, -2.049502946958689e+01, -1.352065100959117e+01, -5.470879013268522e+00, -4.390345893865903e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbesol_whs_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbesol_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.702070885118800e-08, 1.956216162003892e-08, 2.388363590283924e-08, 3.178654612722346e-08, 4.782182418997618e-08, 8.553263917916358e-08, 1.946337848595371e-07, 6.134763045482846e-07, 2.926756942164285e-06, 2.304567176753964e-05, 4.264904418742987e-04, 3.711295548384214e-03, -3.332131944681200e-03, 2.432235263736253e-02, 6.925141015359773e-01, 4.234238290525304e+01, 1.064665176812854e+03, 1.975490644581367e+04, 2.901941428277314e+05, 5.425379916656636e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_lc_wpbesol_whs_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbesol_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.596180868258886e-14, -9.192222772204738e-14, -1.208123788253697e-13, -1.785776094793868e-13, -3.115920229137924e-13, -6.847977208305840e-13, -2.052101742987430e-12, -8.923787886717798e-12, -4.455069225292151e-11, 1.414001827122566e-09, 2.986220880588625e-08, -5.122845913841733e-04, -4.409456881343970e-03, -2.910661724542422e-02, -1.248520373966222e+00, -3.117275760228192e+02, -9.788187642764863e+04, -5.559222706770197e+07, -9.670541382560849e+10, -1.387231843887225e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
