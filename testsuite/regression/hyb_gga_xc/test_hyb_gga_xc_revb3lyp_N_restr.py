
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_revb3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_revb3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.511513157636710e+00, -3.445582555426743e+00, -3.353240495230548e+00, -3.225412108382322e+00, -3.051411794308148e+00, -2.820201549771876e+00, -2.523343257929150e+00, -2.160220976406149e+00, -1.744649646897120e+00, -1.306888921036544e+00, -8.810438708151682e-01, -5.780724326566667e-01, -4.977548585811766e-01, -4.170359150524049e-01, -3.035339882504041e-01, -1.878990092959329e-01, -1.036458777590819e-01, -7.004682605392225e-02, -4.182419712943762e-02, -2.755482409578483e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_revb3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_revb3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.406305921881594e+00, -4.315507087795122e+00, -4.188256851628761e+00, -4.011950233104325e+00, -3.771662560430403e+00, -3.451837563520608e+00, -3.040436634013953e+00, -2.536953997419040e+00, -1.965578938972398e+00, -1.393094666643482e+00, -9.304762688019315e-01, -7.082756721600694e-01, -6.312051434202587e-01, -5.068900340715736e-01, -3.521948645422636e-01, -2.156378506704872e-01, -1.094896596356056e-01, -3.892034284395625e-02, -1.410997292227644e-02, -4.930109856302618e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_revb3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_revb3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.724431047304113e-06, -2.936328806038486e-06, -3.269116256670417e-06, -3.811950186084470e-06, -4.746386736549318e-06, -6.481950456301880e-06, -1.006662400932779e-05, -1.863259156859922e-05, -4.348684896769548e-05, -1.359072390235697e-04, -6.305898831171666e-04, -4.176751808544795e-03, -8.355850113318995e-03, -1.533356447875426e-02, -4.488681922970575e-02, -1.655371314610281e-01, -1.126079860152077e+00, -1.175546575785686e+02, -1.130813948743912e+04, -6.723784619506618e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_revb3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_revb3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.334011564430495e-03, -9.744972559337433e-03, -1.036685570229961e-02, -1.132864976975795e-02, -1.286268469844429e-02, -1.541690700099620e-02, -1.992527423789067e-02, -2.849244921663073e-02, -4.602599598318020e-02, -8.210216127249581e-02, -1.619175825607913e-01, -4.109509245128775e-01, -5.279008086153761e-01, -8.311613286954108e-01, -1.515961601483579e+00, -1.098417109103374e+00, 9.021718643724897e+00, -1.368198704358556e+01, 8.988240538476279e+03, 6.583431082897729e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_revb3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_revb3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.362688913804880e-08, 1.544561503061539e-08, 1.847772176177445e-08, 2.386255524955468e-08, 3.431692717531571e-08, 5.729095782391785e-08, 1.169900854920425e-07, 3.087029414118977e-07, 1.064293701340409e-06, 3.171505874144289e-06, -4.017076659278345e-05, 4.345192042027749e-03, 1.800314170588393e-02, 3.624896561432040e-02, -8.848462010556085e-02, -2.647479884085354e+01, -3.962804368867090e+03, -7.474483831594945e+05, -6.772424960682001e+09, -2.284948887984414e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_revb3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_revb3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.046210007732861e-14, 8.789091595324380e-14, 1.206865476423998e-13, 1.901034043410269e-13, 3.640894008699748e-13, 9.197699569559500e-13, 3.429365340768115e-12, 2.196992088973377e-11, 2.953184121881710e-10, 1.073511839745845e-08, 1.428472791392539e-06, 3.481331577708662e-04, 3.062517295777236e-03, 2.057983584542793e-02, 8.769702287031935e-01, 2.468264038523334e+02, 5.034187120478722e+05, 1.337948015802489e+10, 1.621674857963603e+16, 5.392787626085961e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
