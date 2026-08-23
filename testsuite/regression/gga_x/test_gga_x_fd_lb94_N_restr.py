
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_fd_lb94_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_lb94", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.644230437627111e+00, -5.583592013036315e+00, -5.499825786302654e+00, -5.386318449179784e+00, -5.236989494298908e+00, -5.049528568178838e+00, -4.831939079028155e+00, -4.612873784785174e+00, -4.444989871132860e+00, -4.299614234886488e+00, -3.287908253716323e+00, -9.926857558073615e-01, -6.933965229977374e-01, -7.583682877371354e-01, -8.183521177764937e-01, -9.366803514529608e-01, -1.223729791771317e+00, -1.798394567607011e+00, -2.839044487428064e+00, -4.628038264482115e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_fd_lb94_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_lb94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.851373652596860e+00, -3.718203215291943e+00, -3.530793870997502e+00, -3.269511031166028e+00, -2.910013525973817e+00, -2.424462049922736e+00, -1.785497772579452e+00, -9.759169646796031e-01, -1.539080406077709e-02, 9.244265791057780e-01, 9.777796477678504e-01, -4.429445209507056e-01, -5.623656313598437e-01, -2.513258436657471e-01, 9.070623237193653e-02, 4.016478941017848e-01, 6.619275794675823e-01, 8.710878683382883e-01, 1.053797663765009e+00, 1.234169008750877e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_fd_lb94_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_lb94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.942417859563309e-05, -4.259321437152404e-05, -4.759146119943923e-05, -5.579706125805364e-05, -7.006288598492056e-05, -9.697918645601489e-05, -1.540340972293026e-04, -2.966513674292207e-04, -7.458480264531966e-04, -2.678919452943178e-03, -1.428050066847464e-02, -7.066504872710894e-02, -1.345477611764363e-01, -2.822964612084295e-01, -1.113603931779277e+00, -8.838356931465849e+00, -1.554792401343655e+02, -7.366184994205769e+03, -1.317552893399924e+06, -1.565651744974133e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_fd_lb94_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_lb94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.850577809616105e-02, -3.025192310692704e-02, -3.295485197120254e-02, -3.727596692676015e-02, -4.451255970998008e-02, -5.747014180434503e-02, -8.301072109407714e-02, -1.407160740057867e-01, -2.977345443119185e-01, -8.204956460541117e-01, -2.271988489897136e+00, -1.617399525758134e+00, -1.408680430593233e+00, -3.726430110164184e+00, -1.380166490171860e+01, -8.473177565740596e+01, -1.055616747028745e+03, -3.432342982404903e+04, -4.226108234738190e+06, -3.475959268811054e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_fd_lb94_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_lb94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.289443948768827e-07, 2.616718611009858e-07, 3.169887631642421e-07, 4.173163925649307e-07, 6.186517004855461e-07, 1.085746477354219e-06, 2.419441620724044e-06, 7.542258441762896e-06, 3.752776073273665e-05, 3.512083347157932e-04, 6.591660713343992e-03, 1.106553702710025e-01, 3.539681740090899e-01, 1.238741279151483e+00, 1.342999849217304e+01, 5.153035533578739e+02, 8.679007596770121e+04, 9.767297579398948e+07, 1.485479466939921e+12, 9.602350380464845e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_fd_lb94_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_fd_lb94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.928868393850156e-13, 8.625075752328906e-13, 1.180826980658301e-12, 1.851992955121771e-12, 3.524879007953717e-12, 8.826325320863351e-12, 3.252527694605296e-11, 2.057027683703075e-10, 2.750837962069261e-09, 1.025085185372142e-07, 1.400990069273608e-05, 3.328179920897688e-03, 3.058872438705202e-02, 1.944857894499651e-01, 8.227629882266690e+00, 2.661314212177769e+03, 8.426535285607928e+06, 4.675451486726781e+11, 1.270184963515838e+18, 9.402028393133809e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
