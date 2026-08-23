
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_bhandh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.142736347327530e+00, -2.100521901689361e+00, -2.041345853375714e+00, -1.959322782840064e+00, -1.847450560787851e+00, -1.698332280997160e+00, -1.505924729260899e+00, -1.268727505778402e+00, -9.943786858102112e-01, -7.055969495814166e-01, -4.600782924840159e-01, -3.559795883762895e-01, -3.156154443040093e-01, -2.552835393737628e-01, -1.718859337759052e-01, -8.496834745493102e-02, -2.450294348740147e-02, -1.498218129874554e-02, -3.342752711611777e-03, -3.712899071785077e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_bhandh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.843048938395600e+00, -2.787053414157629e+00, -2.708587663893480e+00, -2.599889469649914e+00, -2.451772463320553e+00, -2.254657376589944e+00, -2.001071612577008e+00, -1.690352939572592e+00, -1.336018296660368e+00, -9.753576946623952e-01, -6.672416386474825e-01, -4.754616275520384e-01, -4.165624835954843e-01, -3.455882452270190e-01, -2.526717418462638e-01, -1.653222156118233e-01, -8.207840717309459e-02, -2.014961215383888e-02, -4.451380623865651e-03, -4.949821443014866e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_bhandh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandh", 1)
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


def test_hyb_gga_xc_bhandh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.124171364543134e-03, -5.334760755454746e-03, -5.652205979363358e-03, -6.140472556692758e-03, -6.913236145430416e-03, -8.186185440400569e-03, -1.040097551464286e-02, -1.453317814433227e-02, -2.277416078643588e-02, -3.823003408257661e-02, -6.179660223547916e-02, -2.091983321603670e-01, -2.939388958278199e-01, -4.057021949407025e-01, -5.454262103131498e-01, 1.318598251195982e+00, 6.739903201680043e+00, -2.359791267018034e+02, -5.162493730017063e+03, -4.270509114206451e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_bhandh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandh", 1)
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


def test_hyb_gga_xc_bhandh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_bhandh", 1)
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
