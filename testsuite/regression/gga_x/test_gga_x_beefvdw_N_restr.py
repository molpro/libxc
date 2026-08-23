
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_beefvdw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_beefvdw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.416128585324750e+00, -4.331821034487931e+00, -4.213910283257166e+00, -4.051050674372381e+00, -3.830136085556662e+00, -3.538184760827806e+00, -3.166688514380272e+00, -2.720382150646012e+00, -2.221834420169546e+00, -1.692935216229923e+00, -1.151155692499596e+00, -6.818248464064148e-01, -5.781823063065308e-01, -4.850706823177794e-01, -3.653481781033437e-01, -2.533790290188250e-01, -1.296115412875156e-01, -4.359370285476376e-02, -9.091283382292393e-03, -1.005566451591865e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_beefvdw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_beefvdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.553522115345653e+00, -5.431213546739399e+00, -5.259424252122937e+00, -5.020828494982432e+00, -4.695033377374412e+00, -4.261100531758223e+00, -3.699319720344212e+00, -2.994141384552963e+00, -2.269245197295684e+00, -1.589511436407071e+00, -9.166233724075062e-01, -8.140835182591065e-01, -7.415078983213265e-01, -5.596233364134744e-01, -3.589559968703169e-01, -2.118629309736404e-01, -1.562809183902353e-01, -5.725978125689669e-02, -1.211300501789041e-02, -1.340742882305838e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_beefvdw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_beefvdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.590723066689786e-06, -3.938027771513095e-06, -4.494949417377120e-06, -5.427781601250661e-06, -7.084577837983057e-06, -1.027541379204681e-05, -1.729606733812504e-05, -3.629098255997893e-05, -8.746395270253734e-05, -2.687011699158248e-04, -1.646679681301490e-03, -7.624405689749273e-03, -1.092312435592152e-02, -3.237377827517458e-02, -1.207742097997446e-01, -6.745723946895461e-01, -1.120859557294946e+00, -1.949526166237816e+00, -2.370401570886434e+00, -2.618935307987214e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_beefvdw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_beefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.420708879399003e-02, -1.496614591704279e-02, -1.610452611723826e-02, -1.783028550861821e-02, -2.049506456228784e-02, -2.493745801387599e-02, -3.455938075200567e-02, -5.324061248272751e-02, -5.049303869022913e-02, -2.144715946896197e-01, -9.399473523797870e-01, -6.873249840356596e-01, -7.351037079815331e-01, -1.550349745244425e+00, -1.600483629839639e+00, 2.781736783467193e+01, 4.787607910712859e-01, -4.896363057971124e+02, -1.401498883874504e+04, -1.157441594586460e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_beefvdw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_beefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.152800223738356e-08, 4.821933350337557e-08, 5.933170503050977e-08, 7.874394649291282e-08, 1.152319474262056e-07, 1.959259985796796e-07, 4.673087130740015e-07, 1.442127499121460e-06, 6.769671634219077e-07, 5.013517985856346e-05, 1.996962350283144e-03, 1.999452180545998e-02, 4.977270520771145e-02, 2.515204220390497e-01, -1.747037924231622e-01, -1.814402507374721e+02, -3.628393694202066e+03, -2.329749424868922e+05, -3.313724130203731e+07, -2.713300059481387e+10]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_x_beefvdw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_beefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.587411449520200e-13, -1.948620562372085e-13, -2.563633482653573e-13, -3.639241574591048e-13, -5.497662508067099e-13, -8.855620271067053e-13, -2.818532811518000e-12, -4.614114446049551e-12, 7.924355534076432e-10, 4.282636167289707e-09, -1.678890385483553e-06, -2.872935219643644e-04, -5.331860057597671e-03, -1.836402275193512e-02, 2.429362839383142e+00, 1.385294236062431e+03, 3.491276121685126e+05, 7.069713204149718e+08, 1.203500562278266e+13, 7.649196036329821e+18]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
