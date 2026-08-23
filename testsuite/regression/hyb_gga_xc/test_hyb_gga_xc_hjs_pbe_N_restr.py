
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hjs_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.307284889895918e+00, -3.244957495655866e+00, -3.157670533556487e+00, -3.036860255545389e+00, -2.872463958985807e+00, -2.654147555053842e+00, -2.374195210941086e+00, -2.032681716379641e+00, -1.644111473959811e+00, -1.238025521094055e+00, -8.387726886971379e-01, -5.567269804459686e-01, -4.897066927873621e-01, -4.059826406024522e-01, -2.965291702640830e-01, -1.917704904943094e-01, -1.051503042038507e-01, -4.069678438295790e-02, -8.764696550069105e-03, -9.701549674496163e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hjs_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.181912947621687e+00, -4.095124009363005e+00, -3.973399904244159e+00, -3.804557596029082e+00, -3.574051931396139e+00, -3.266469148017957e+00, -2.869350682852094e+00, -2.380922016315875e+00, -1.824105055144515e+00, -1.276207060976147e+00, -8.460861991534514e-01, -7.032020585884692e-01, -6.339960485126137e-01, -5.101396450192850e-01, -3.459335148366037e-01, -2.011911133294791e-01, -1.186923601458836e-01, -5.216792342823540e-02, -1.166991293327121e-02, -1.293517138406689e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.171311995816374e-06, -2.358603249793688e-06, -2.655356359113734e-06, -3.145555261412760e-06, -4.004622959476772e-06, -5.640772972124854e-06, -9.138542554563406e-06, -1.788411437366872e-05, -4.467355931487374e-05, -1.465195268246655e-04, -7.011329525785969e-04, -1.783946598608262e-03, -4.777549518530256e-04, -6.093899782915000e-03, -3.661574012956185e-02, -2.576387766588222e-01, -1.183122568307933e+00, -2.638358588950467e+00, -3.543723612541473e+00, -3.941401393920163e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.464261444964232e-03, -9.910189858582571e-03, -1.058854804668075e-02, -1.164569760327614e-02, -1.335035566338436e-02, -1.623281595551615e-02, -2.142809792461114e-02, -3.156700452082882e-02, -5.249524826108789e-02, -8.408418749376059e-02, -1.791400834740389e-01, -4.479122663278849e-01, -5.006883175402537e-01, -9.478465034524406e-01, -2.502033508272111e+00, -4.464109439286648e+00, 1.141859385369928e+01, -3.517212254471656e+02, -1.341373058103979e+04, -1.116581472637199e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.070005739210428e-08, 2.365616509812903e-08, 2.863743521840754e-08, 3.762185694597059e-08, 5.546050237437833e-08, 9.596089755447988e-08, 2.063690534132749e-07, 5.888022212914290e-07, 2.287481430566186e-06, 6.477471630150452e-06, 4.388976629328967e-05, 8.925729123299695e-03, 1.501683518446856e-02, 9.589848304051474e-02, 1.020028678641076e+00, -1.516621029926402e+00, -3.173910188928126e+03, -3.089713340041614e+05, -4.942296672473392e+07, -4.082214309823373e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.047623120929293e-14, -7.133734211188414e-14, -9.008289682511889e-14, -1.247162433281065e-13, -1.938410613241455e-13, -3.364411161833483e-13, -4.998916092175683e-13, 2.934926855998325e-12, 1.427332006447139e-10, 1.033829449265519e-08, 1.381469709307203e-06, -4.874251078513937e-04, -5.804858858126220e-03, -2.576401340671985e-02, -3.928494547757853e-01, 1.537701069733258e+02, 3.238166006206896e+05, 9.539351890260592e+08, 1.796041150051183e+13, 1.150921205435262e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
