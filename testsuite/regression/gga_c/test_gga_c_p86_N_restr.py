
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_p86_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.002435564295220e-02, -6.902254899341820e-02, -6.758856618825325e-02, -6.554059697402677e-02, -6.262598418373921e-02, -5.850218670641087e-02, -5.273073758332152e-02, -4.483727951516236e-02, -3.461144978658964e-02, -2.294479800118860e-02, -1.374707384002789e-02, -4.569320845940247e-02, -5.383351141631306e-02, -3.972640584981178e-02, -2.257562436109952e-02, -3.895431368968881e-03, 3.856854591813367e-03, -8.674499765897504e-03, -3.335429970846198e-03, -4.506436826535016e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_p86_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.297153814834028e-01, -1.285274596662913e-01, -1.267971523326990e-01, -1.242626919793790e-01, -1.205203846036540e-01, -1.149317916030157e-01, -1.064621425929195e-01, -9.344108483072516e-02, -7.360079981198039e-02, -4.769641383269727e-02, -4.590327564871013e-02, -8.843418956221556e-02, -8.011988199490418e-02, -7.888531765831966e-02, -6.912477009525675e-02, -4.479251521774708e-02, 2.467892968004749e-03, 1.991648944206259e-04, -4.249829252275548e-03, -5.930727728501467e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86", 1)
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


def test_gga_c_p86_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.581259482583036e-04, -4.982804863968816e-04, -5.618527491496362e-04, -6.667434382921650e-04, -8.502467714822473e-04, -1.198855647528996e-03, -1.941275505760305e-03, -3.785080491705346e-03, -9.335792245315631e-03, -2.965756616003752e-02, -1.008706699587089e-01, -4.197703605049751e-03, 9.427277079382968e-03, -1.641776483685885e-03, -3.195672790083405e-01, -5.476082119139395e+00, -9.109601412378352e+01, 9.422639641567106e+02, -2.499857240245789e+03, -4.822901153573871e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86", 1)
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


def test_gga_c_p86_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86", 1)
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
