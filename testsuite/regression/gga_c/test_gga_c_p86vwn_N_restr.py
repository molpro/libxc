
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_p86vwn_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.021411781580975e-02, -6.922765996128991e-02, -6.781577273978592e-02, -6.579960197023380e-02, -6.293069892548278e-02, -5.887239761385116e-02, -5.319402306376701e-02, -4.543004578037787e-02, -3.537402367542642e-02, -2.389018594287865e-02, -1.475315302755175e-02, -4.654084953731822e-02, -5.453623185251343e-02, -4.004451745022255e-02, -2.240898821908945e-02, -3.555646240332526e-03, 3.996070668716575e-03, -8.723863351877815e-03, -3.350389795362676e-03, -4.454830836828037e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_p86vwn_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.296546563309639e-01, -1.284816396936486e-01, -1.267728858425106e-01, -1.242696512185479e-01, -1.205726838400762e-01, -1.150500738449936e-01, -1.066765567614714e-01, -9.379505723249390e-02, -7.415343483977176e-02, -4.851059294203915e-02, -4.696753232984632e-02, -8.957176200229613e-02, -8.124379952064999e-02, -7.979975837468563e-02, -6.921896733241537e-02, -4.443119996750327e-02, 2.703430516806388e-03, 1.626763535509338e-04, -4.274888434767383e-03, -5.873120727224602e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86vwn_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.098774701463822e-07, 6.473549169995022e-07, 7.048988010897591e-07, 7.956639626667263e-07, 9.441871906538692e-07, 1.199255351119857e-06, 1.663774328980717e-06, 2.558945357383013e-06, 4.291434795615625e-06, 7.424733226078735e-06, 7.471499456710320e-05, 3.221564583490807e-03, 7.990715865671788e-03, 1.375291200985754e-02, 4.375020341036909e-02, 2.305004710307330e-01, 3.493115142467365e-01, -2.516320428208529e+01, -1.194475128946752e+01, -1.663470461749511e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86vwn_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.567701365498723e-04, -4.968312729051631e-04, -5.602583561034714e-04, -6.649157251214712e-04, -8.480259065853430e-04, -1.195926665555108e-03, -1.936947584554695e-03, -3.777622848079774e-03, -9.320174691285352e-03, -2.961800083913035e-02, -1.007847934079840e-01, -4.189590939038079e-03, 9.246818434153332e-03, -6.043107555464091e-03, -3.269759332790170e-01, -5.482312035640859e+00, -9.098387337837748e+01, 9.432579327076859e+02, -2.544524311220796e+03, -4.813344864726602e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86vwn_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.934855030864473e-09, 5.735454729772510e-09, 7.112716773006130e-09, 9.673201040777607e-09, 1.499081129303301e-08, 2.791664357202489e-08, 6.715825839242218e-08, 2.297142319945231e-07, 1.261373083567237e-06, 1.288278271767758e-05, 2.890452909754931e-04, -9.427531807610752e-04, -1.283113480897005e-02, -1.484667989991715e-02, 2.058788380423050e-01, 2.830582339990521e+01, 6.646615788688813e+03, -2.074574561414771e+06, -5.242151082553075e+08, -1.836235569664211e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86vwn_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.163380578525948e-13, -1.420192478263120e-13, -1.891090510010459e-13, -2.851514414868386e-13, -5.134184079259519e-13, -1.189215053225250e-12, -3.929685154049264e-12, -2.134002995364072e-11, -2.309150397246024e-10, -6.682081037317327e-09, -1.063129912934020e-06, -5.418667152075936e-04, -5.426951774907433e-03, -2.946258658018909e-02, -1.124071179877471e+00, -3.180180921541167e+02, -5.065520446899901e+05, 7.126814218449379e+09, 1.783928166288936e+14, 4.575112859778715e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
