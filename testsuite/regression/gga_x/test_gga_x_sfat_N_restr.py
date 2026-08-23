
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_sfat_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.103934411392993e+00, -4.022003531556984e+00, -3.907265369043440e+00, -3.748461783514422e+00, -3.532351614252597e+00, -3.245285955057087e+00, -2.876881965748273e+00, -2.426470292950348e+00, -1.911127087373080e+00, -1.368168622065289e+00, -8.431986479241909e-01, -4.860375598034750e-01, -3.958173135488211e-01, -3.047835810854599e-01, -1.830010903065603e-01, -7.327844929500371e-02, -1.257665302492803e-02, -5.143360101191973e-04, -4.633767754926363e-06, -6.265003964850683e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_sfat_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.184803018332460e+00, -5.071769622192602e+00, -4.913400512277655e+00, -4.694066268364871e+00, -4.395322360379187e+00, -3.998087178396402e+00, -3.487953269921069e+00, -2.865394845789276e+00, -2.162193827473721e+00, -1.461791814580382e+00, -9.010186336831515e-01, -6.402419541333154e-01, -5.483662067530852e-01, -4.085148937876671e-01, -2.404252749236763e-01, -1.022132473390882e-01, -2.178799978145456e-02, -1.016578115304380e-03, -9.265823362815501e-06, -1.253000313317463e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sfat_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.824217020237255e-06, -4.116971763952594e-06, -4.575945115115338e-06, -5.322691015310194e-06, -6.603248909149109e-06, -8.968071491178316e-06, -1.380987572724432e-05, -2.522476931997951e-05, -5.767170228129012e-05, -1.749912460013412e-04, -7.738484420142193e-04, -4.452424623119499e-03, -8.383930763005955e-03, -1.441431299563927e-02, -3.647819010596775e-02, -1.007945017635269e-01, -1.171861322328314e-01, -1.558166961940861e-02, -2.862071189322995e-04, -6.459955915424191e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sfat_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.175065661787536e-02, -1.226623255465694e-02, -1.304589287463260e-02, -1.425043250414226e-02, -1.616843042967101e-02, -1.935329316859511e-02, -2.494965938584034e-02, -3.551001995415977e-02, -5.697702035437754e-02, -1.025163929779817e-01, -2.136867794882932e-01, -4.721940629404058e-01, -6.000450397957391e-01, -9.084302978118909e-01, -1.652050917664888e+00, -3.493226866749806e+00, -1.375189568264011e+01, -3.031896815548962e+01, -3.241957065147491e+01, -3.245439620138226e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sfat_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.879287280402912e-08, 2.126895015112490e-08, 2.538806235402021e-08, 3.268013366316288e-08, 4.677073695899127e-08, 7.751870310445456e-08, 1.565923504734656e-07, 4.069660951421252e-07, 1.387884872637782e-06, 5.003947750933237e-06, 4.888241092804649e-06, 4.282987300435596e-03, 1.624405677054543e-02, 3.035388399172784e-02, -2.686077965318228e-02, -7.681142234986814e+00, -2.701760741124723e+02, -1.588112204762606e+03, -3.631421660038245e+03, -6.365078561403770e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sfat_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sfat", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.808380445817974e-14, 1.221777363838002e-13, 1.674299958336137e-13, 2.629453421726489e-13, 5.013310664300169e-13, 1.257703486114652e-12, 4.637883894305555e-12, 2.917228134984332e-11, 3.795858063440293e-10, 1.296647078583227e-08, 1.543044174470967e-06, 3.396349366948530e-04, 2.807457336293809e-03, 1.698269241196983e-02, 5.548304644474058e-01, 7.851387846181969e+01, 2.107402516883617e+04, 3.609787021746709e+06, 9.888282565554394e+08, 1.345800259699453e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
