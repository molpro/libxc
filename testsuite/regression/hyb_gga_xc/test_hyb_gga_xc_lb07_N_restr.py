
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lb07_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lb07", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.560209033537087e+00, -3.484484468309780e+00, -3.378354489376552e+00, -3.231292826258211e+00, -3.030807939482907e+00, -2.763782651806482e+00, -2.419711095217807e+00, -1.996658328841646e+00, -1.510094583494530e+00, -1.004545713521544e+00, -5.816562536555683e-01, -3.941627289378085e-01, -3.273720911373758e-01, -2.346682281915185e-01, -1.189750709400167e-01, -2.664575606768520e-02, 9.575443673719878e-03, -3.326202648250159e-03, -9.116400452835061e-04, -1.023972337004168e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lb07_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lb07", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.813536083981406e+00, -4.712775868059091e+00, -4.571580379571429e+00, -4.375978817007098e+00, -4.109431889829287e+00, -3.754676207124583e+00, -3.298186722626471e+00, -2.738525615159166e+00, -2.099246050897837e+00, -1.445837310597408e+00, -8.944586582131957e-01, -5.844926120833750e-01, -4.867142062256538e-01, -3.658885208861372e-01, -2.157614767449392e-01, -1.005820575005239e-01, -3.829759929349227e-02, -4.668275628268008e-03, -1.210435174353597e-03, -1.364593074027644e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lb07_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lb07", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.311008544917941e-08, 5.891723568868897e-08, 6.839131164754366e-08, 8.472509282516809e-08, 1.152129719486837e-07, 1.790072734826092e-07, 3.363244764573939e-07, 8.273517895363370e-07, 2.967358795860768e-06, 1.746450587813502e-05, 1.554118339258821e-04, 7.512977417932514e-04, 1.462985488379339e-03, 4.172921849223738e-03, 2.493026931282792e-02, 2.925511277679759e-01, 4.235069725348804e+00, 5.244898795282887e+00, 7.435325164346767e-10, 1.884753025935447e-139]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lb07_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lb07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.249097993471695e-03, -9.631191643155726e-03, -1.020757002447773e-02, -1.109509970261764e-02, -1.250239351046111e-02, -1.482832045491735e-02, -1.890169433539945e-02, -2.661442196552229e-02, -4.264135049049678e-02, -7.774182802761663e-02, -1.534138560753152e-01, -3.752898684196569e-01, -5.061535178753233e-01, -7.127191783600320e-01, -1.058303677950017e+00, 1.277888293013205e+00, 1.834718439583739e+01, -7.935486589216538e+01, -1.383858265045107e+03, -1.175134128042551e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lb07_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lb07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.026209698773901e-10, -5.928761514379779e-10, -7.516586509547962e-10, -1.056864315785480e-09, -1.723402738237779e-09, -3.473391421800908e-09, -9.466691070773377e-09, -3.957334402680627e-08, -3.007751063727082e-07, -5.012420315357268e-06, -1.613460560965718e-04, -1.984420464202706e-03, -5.755218874613607e-03, -3.090298239464234e-02, -5.569307641301551e-01, -3.272163547718650e+01, -3.446949069436948e+03, 1.638224236940590e+05, 2.905166407798063e-02, 5.579311791278274e-128]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lb07_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lb07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
