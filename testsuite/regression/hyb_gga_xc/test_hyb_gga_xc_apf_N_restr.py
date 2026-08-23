
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_apf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.387567887558590e+00, -3.323533973332106e+00, -3.233849196871841e+00, -3.109703178443567e+00, -2.940730524196969e+00, -2.716254796802350e+00, -2.428223420294388e+00, -2.076470127958124e+00, -1.675531437679459e+00, -1.256370381428442e+00, -8.467887795619365e-01, -5.573793343703457e-01, -4.873630043906618e-01, -4.023965801211593e-01, -2.903114314612402e-01, -1.835781552552096e-01, -1.013987307156473e-01, -4.704894720330393e-02, -2.159699419904768e-02, -1.248876486047896e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_apf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.281159425233085e+00, -4.192368820797368e+00, -4.067861161900387e+00, -3.895205461796202e+00, -3.659585926056640e+00, -3.345345549606490e+00, -2.939883502154232e+00, -2.441427965628455e+00, -1.872904338940107e+00, -1.304226026695871e+00, -8.564651492566064e-01, -7.047482657836703e-01, -6.330069185098419e-01, -5.069714099559843e-01, -3.405375676686104e-01, -1.874206059737857e-01, -9.502467594325260e-02, -3.818403719458546e-02, -1.043343961015212e-02, -2.605562176245073e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_apf_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.300441172865355e-06, -2.492854560666982e-06, -2.796929891992295e-06, -3.297389041024902e-06, -4.170014844827056e-06, -5.820779836811427e-06, -9.319855449214769e-06, -1.798412647200508e-05, -4.427614086137676e-05, -1.465966839831064e-04, -7.125914211917688e-04, -2.118829087789625e-03, -1.483679353301342e-03, -7.274220033358309e-03, -3.825038030423375e-02, -2.962492372248123e-01, -2.698519835977143e+00, -5.512360681767260e+01, -4.996056606714164e+03, -2.969706734609101e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_apf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.539857971388841e-03, -9.981342357415483e-03, -1.065216777853259e-02, -1.169595867854537e-02, -1.337577343386256e-02, -1.621012289829148e-02, -2.131049332834873e-02, -3.125453990925494e-02, -5.204677536915597e-02, -9.382943003341260e-02, -2.068955942865098e-01, -4.492854945206456e-01, -5.131469510014230e-01, -9.481680643106570e-01, -2.530945019795981e+00, -6.582353647394586e+00, -1.238620484542461e+00, -1.529540005478418e+02, -1.046145129770764e+03, 2.526011810452385e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_apf_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.915890567373134e-08, 2.185112674041504e-08, 2.637879862655744e-08, 3.452395887270604e-08, 5.064496060606815e-08, 8.712382187542202e-08, 1.863262704336595e-07, 5.290932730326463e-07, 2.068729075541232e-06, 9.447291274027026e-06, 1.044311763582328e-04, 8.290653599810736e-03, 1.556789293632284e-02, 8.915352541887471e-02, 1.001026199987677e+00, 9.832444505250267e+00, -2.037965737779277e+03, -5.379945735671195e+05, -3.013117899285182e+09, -1.009215180380850e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_apf_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.219190864120872e-14, -3.682354552883836e-14, -4.420538285333073e-14, -5.589059698653759e-14, -7.155081872995415e-14, -6.234364311909606e-14, 3.373267233851555e-13, 6.776565482826541e-12, 1.680964043948304e-10, 9.181596809920567e-09, 1.249350789848120e-06, -3.746393608146712e-04, -4.837228977781259e-03, -2.042519274768151e-02, -3.385597678861249e-01, 1.168691090048151e+02, 3.842882215170161e+05, 6.357450255817834e+09, 7.170446200171930e+15, 2.381846454287241e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
