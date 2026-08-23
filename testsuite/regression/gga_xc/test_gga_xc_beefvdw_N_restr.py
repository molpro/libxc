
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_beefvdw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_beefvdw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.512665323805163e+00, -4.427586558451577e+00, -4.308569713084599e+00, -4.144125836516626e+00, -3.920946756060855e+00, -3.625769749503121e+00, -3.249708604076908e+00, -2.797037556019121e+00, -2.289964829720366e+00, -1.750907530870641e+00, -1.200772430577033e+00, -7.394200302872249e-01, -6.375952715293502e-01, -5.350988209321058e-01, -4.032976032495371e-01, -2.786515920179934e-01, -1.446704946900444e-01, -5.064286483171305e-02, -1.110698018315530e-02, -1.279000716159481e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_beefvdw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_beefvdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.683050340205821e+00, -5.559993870566132e+00, -5.387124648077377e+00, -5.146966252435002e+00, -4.818902022287334e+00, -4.381653809441770e+00, -3.814975448627210e+00, -3.102428733361033e+00, -2.366259215972054e+00, -1.670539327063141e+00, -9.857279238461479e-01, -8.947746567318980e-01, -8.177246838204644e-01, -6.312042835888535e-01, -4.175558102820028e-01, -2.484776220130791e-01, -1.749809699394007e-01, -6.601799727655266e-02, -1.470281550906092e-02, -1.700427071091543e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_beefvdw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_beefvdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.303614733709420e-06, -3.631693785089643e-06, -4.158787827056142e-06, -5.043827408585581e-06, -6.620495350315631e-06, -9.668287485244277e-06, -1.641107248702360e-05, -3.480527805188973e-05, -8.451438221689026e-05, -2.615422198284666e-04, -1.608117417119601e-03, -6.239783589149908e-03, -7.143475514668778e-03, -2.642285042211776e-02, -1.056408523274868e-01, -6.341752175894726e-01, -1.072407563847217e+00, -1.929962857153093e+00, -2.367987911991502e+00, -2.618875136138561e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_beefvdw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_beefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.435440092866588e-02, -1.512483780207825e-02, -1.628115967313446e-02, -1.803638579801373e-02, -2.075252172356448e-02, -2.529251887554123e-02, -3.512476894105555e-02, -5.434643076892457e-02, -5.331143369926127e-02, -2.234130869107261e-01, -9.708387685084540e-01, -7.055326487515931e-01, -7.433687064592378e-01, -1.602524975552166e+00, -2.031669797360599e+00, 2.506466675603379e+01, -7.037909607925537e+00, -5.543873718435054e+02, -1.654881368953020e+04, -1.449313989665882e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_beefvdw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_beefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.264391979543495e-08, 4.950941643845923e-08, 6.092073393657029e-08, 8.088768898447771e-08, 1.185276855395855e-07, 2.020375299909355e-07, 4.821310922978565e-07, 1.494658453667123e-06, 9.855728321787916e-07, 5.334710643050088e-05, 2.070350889457916e-03, 2.035843500898479e-02, 4.464361710766462e-02, 2.567364844105179e-01, 1.421810777337419e-01, -1.687366790320086e+02, -3.347658973971543e+03, -2.291083260421620e+05, -3.308203444374486e+07, -2.713196958974740e+10]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_xc_beefvdw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_beefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.983838218685012e-13, -2.430584716567499e-13, -3.201826311309115e-13, -4.594418071504164e-13, -7.201342876522536e-13, -1.275944574795100e-12, -4.096127313742668e-12, -1.153313385196596e-11, 7.170795231357732e-10, 2.181821592661208e-09, -1.980219248746406e-06, -5.887043978057686e-04, -8.334780844288301e-03, -3.592390365195190e-02, 1.797278441461392e+00, 1.287174349293846e+03, 3.246703990629832e+05, 6.961298077537942e+08, 1.201660935415363e+13, 7.648932415727199e+18]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
