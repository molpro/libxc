
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_bkl2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.389663077723116e-02, -9.299595995222772e-02, -9.169993825703208e-02, -8.983447764286737e-02, -8.714805730795534e-02, -8.327675425130619e-02, -7.769609627084381e-02, -6.967535825437414e-02, -5.838308659158822e-02, -4.419364999035495e-02, -3.686035972357701e-02, -5.910652981147729e-02, -6.070206927254153e-02, -5.152368078823297e-02, -3.793473139289162e-02, -1.997407989999590e-02, -3.577046783688511e-03, -6.174353999059816e-05, -6.632501149724874e-08, -2.135207100614301e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_bkl2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.427158914014207e-01, -1.421306775467555e-01, -1.412843942656504e-01, -1.400576095639318e-01, -1.382726753853912e-01, -1.356603799827812e-01, -1.317995815634267e-01, -1.259972194303436e-01, -1.170557630335848e-01, -1.034058050811887e-01, -9.171992592802147e-02, -8.391003680132221e-02, -7.593788183341998e-02, -7.444913159243620e-02, -6.828443457190836e-02, -5.328807647097060e-02, -1.689933356897895e-02, -3.838652337141984e-04, -4.327862387432641e-07, -1.412462695012524e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bkl2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.804999886419250e-07, 5.160993695720725e-07, 5.718414946096793e-07, 6.623930202376928e-07, 8.174138388103943e-07, 1.103350127634591e-06, 1.689447839618551e-06, 3.083021470008384e-06, 7.162840182002027e-06, 2.334558958497773e-05, 1.430350621208586e-04, 1.534776117469560e-03, 3.110371698425091e-03, 6.494732884702228e-03, 2.509509685287097e-02, 1.693443855713429e-01, 8.864975978045735e-01, 7.098349577483444e-01, 9.608880795936890e-02, 2.407689949257981e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bkl2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.137624359035750e-05, -4.649269736492157e-05, -5.478324558761250e-05, -6.891187968468206e-05, -9.476077478061306e-05, -1.469931937911743e-04, -2.682175148300919e-04, -6.092439477679319e-04, -1.856817087670777e-03, -7.981384858163078e-03, -2.975474926832882e-02, 7.160562812854053e-03, -7.493482372086047e-04, 1.996009456134878e-02, 1.953271421601707e-02, -2.321062525374070e+00, -5.103149646948160e+01, -6.099719875536272e+01, -8.361014938785537e+00, -2.053818805509231e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_bkl2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.670277253472164e-10, -1.560508260963040e-10, -1.285070609186131e-10, -5.492660013918101e-11, 1.617266694511611e-10, 8.990988834814001e-10, 4.001541932142590e-09, 2.177680742226571e-08, 1.812403240581561e-07, 2.828771844456905e-06, 6.981788189635076e-05, -1.915376628221604e-03, -8.272690927038346e-03, -2.460261958887778e-02, -1.491422250409647e-01, 9.383679327120340e+00, 3.361442976060109e+03, 1.344026101381457e+05, 2.193213473438448e+06, 4.125290616869772e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_bkl2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_bkl2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.178486681772533e-14, -5.127557114252183e-14, -6.879260043240470e-14, -1.048646808443003e-13, -1.918278656360000e-13, -4.548857190800121e-13, -1.558116192021213e-12, -8.967904553091054e-12, -1.074022492548582e-10, -3.663429122970831e-09, -5.596043986128096e-07, -1.268373012932348e-04, -7.685425402611452e-04, -6.725370736329240e-03, -3.698863471715441e-01, -1.672184860643576e+02, -3.240276967523581e+05, -3.798529604995567e+08, -7.310965714885699e+11, -1.054812728154641e+16]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
