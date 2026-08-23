
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_th_fcfo_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fcfo", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.943322650105247e+00, -4.848188259191861e+00, -4.713472151188116e+00, -4.524409731206648e+00, -4.262959538764083e+00, -3.910132422940847e+00, -3.452949031183928e+00, -2.899264013650614e+00, -2.299776452845304e+00, -1.750834997797513e+00, -1.259951639094145e+00, -8.850053320496988e-01, -7.944980957865511e-01, -6.902385308787976e-01, -5.667178381829422e-01, -4.578659470592495e-01, -3.738628479228369e-01, -2.973272897692501e-01, -1.873095205459796e-01, 1.096453500840414e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_th_fcfo_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fcfo", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.705002285527152e+00, -6.596160934008724e+00, -6.438083285016727e+00, -6.208620964657360e+00, -5.877005139516173e+00, -5.403479975944596e+00, -4.744273804009790e+00, -3.869120897925040e+00, -2.801840937370135e+00, -1.705764532393687e+00, -1.069326264089874e+00, -1.079173600446518e+00, -9.856205576007843e-01, -7.957509904503375e-01, -5.683150160211199e-01, -3.703561418453893e-01, -2.324086192098996e-01, -1.587046257375817e-01, -1.753585569382642e-01, -4.548765488863101e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th_fcfo_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fcfo", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.802626049836402e-06, 3.043180411828687e-06, 3.393895535519879e-06, 3.901241073760886e-06, 4.610860912956682e-06, 5.482147807045768e-06, 5.934043864144567e-06, 2.374913750575769e-06, -2.684487184447060e-05, -2.254119333456524e-04, -1.416437470161523e-03, -2.224146318636021e-03, -2.527078304061306e-03, -1.871751794835111e-02, -1.065265750876679e-01, -9.427681749392788e-01, -1.493456650141691e+01, -4.741837287501100e+02, -1.446726335065301e+04, 1.389823653206044e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th_fcfo_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fcfo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.565404230095081e-03, -1.048246855297652e-02, -1.189712217045326e-02, -1.414642499146914e-02, -1.788100994661295e-02, -2.447749842363997e-02, -3.720729327713100e-02, -6.506850841480195e-02, -1.374447709623698e-01, -3.606366723685365e-01, -8.603324046884426e-01, -7.234537135487745e-01, -8.201249888271940e-01, -1.419779313693843e+00, -3.524839108571762e+00, -1.351210040461033e+01, -7.976467233148890e+01, 7.222936427543676e+02, 8.230421342970703e+05, 2.440753582059109e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th_fcfo_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fcfo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.365549057702570e-09, -1.852702630178826e-09, 3.040363942243701e-09, 1.353443709830473e-08, 3.900768420644015e-08, 1.116463216428313e-07, 3.681591056970217e-07, 1.578161353281862e-06, 1.005011991424419e-05, 1.090662148449260e-04, 1.853135820434579e-03, 1.750179084209726e-02, 5.047328412581305e-02, 1.660366711405059e-01, 1.592508724957616e+00, 4.603929164645537e+01, 3.783173984948646e+03, -3.033085869579812e+06, -2.760060762043849e+11, -6.309215828632916e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th_fcfo_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fcfo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.451087298746451e-13, -3.245380222687445e-13, -4.766729876873773e-13, -8.038705116542755e-13, -1.629695215929109e-12, -4.227650348736106e-12, -1.529572623441948e-11, -8.697863252031751e-11, -9.180468510910079e-10, -2.275976341760403e-08, -1.899479667601702e-06, -7.675579448315882e-04, -9.518418553768615e-03, -5.250928683623696e-03, 7.005289650227072e-01, 3.482084357598221e+02, 1.110489120367011e+06, 5.072021844090631e+10, 9.908005062338056e+16, 4.791418833050600e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
