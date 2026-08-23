
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m05_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.051721659561179e-02, -7.042012338897054e-02, -7.027446248943543e-02, -7.004881637959685e-02, -6.967833128260482e-02, -6.900622893573878e-02, -6.758909906341748e-02, -6.401080158692794e-02, -5.366514398112186e-02, -2.679940189832093e-02, -3.980434695755565e-03, -3.251329689139440e-02, -5.110510514517260e-02, -3.090848381682714e-02, -2.104143268529814e-02, 1.482457557781558e-02, 1.569482699009188e-02, -3.889589566791835e-03, -1.704733130168961e-03, -2.162112164402845e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m05_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.169412844878802e-02, -6.916186674696137e-02, -6.561965607827963e-02, -6.077782187742121e-02, -5.447569621319306e-02, -4.718760335297494e-02, -4.148937841830367e-02, -4.556014062953431e-02, -7.688996682838112e-02, -1.357369476391093e-01, -1.300672139696081e-01, -9.983568287900930e-02, -1.142766677358440e-01, -4.698413174300584e-02, -5.773353387088195e-02, -6.536417509632519e-02, 5.122627951436262e-02, 7.027759070245533e-04, -2.472576472632047e-03, -3.379762115472308e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.746312495408032e-07, 1.096980323805569e-07, 1.897682404234891e-09, -1.854349336363914e-07, -5.283229721983611e-07, -1.187786489175135e-06, -2.480819067448594e-06, -4.724459156348184e-06, -5.195783876459879e-06, 2.673238862506186e-05, 2.842886601232475e-04, 4.886662411484917e-03, 2.330987985468925e-02, -1.200817901398280e-03, 9.579617532694847e-03, 4.011558587664225e-01, -2.095533600712827e+00, -8.688460341542545e+00, 2.281297679229253e+02, 2.913665429406990e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.068361309844779e-04, -4.042836436979078e-04, -2.574801193834776e-04, -4.911372709890237e-05, 2.407684885296263e-04, 6.255299674804288e-04, 1.081209815422702e-03, 1.476429137143930e-03, 1.520117742087696e-03, 1.042765161002459e-03, 5.955937592001513e-04, 2.290869102591349e-04, -2.326442247486106e-03, 8.993664182827857e-03, 1.464011107142395e-02, 5.239727906436649e-03, -1.124284999008002e-03, -1.504629831396326e-03, -5.596727098707579e-04, -8.852627336818486e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.857254919199358e-03, -1.961268349843899e-03, -2.108826459960680e-03, -2.310681615902905e-03, -2.557116326293421e-03, -2.734627341896752e-03, -2.277404800226976e-03, 1.266632545099583e-03, 1.719895545132600e-02, 5.860921937959417e-02, 1.128365208885586e-01, -3.591206049291703e-01, 1.207983367825476e-02, -5.778505087557108e-01, 2.734667585215757e+00, -1.512198997766313e+01, -1.479543519766760e+01, 7.348296199524736e+02, -1.543727924039334e+03, -3.207994983890792e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.665351908286109e-08, 4.138432472872606e-08, 4.901880227747183e-08, 6.181778955101482e-08, 8.409244397964317e-08, 1.229254951745731e-07, 1.763219706020288e-07, 7.330855930783485e-08, -2.338615281312644e-06, -2.910481953317435e-05, -3.947445901350513e-04, 2.975729224987681e-02, 7.790225164732098e-03, 2.962247367456053e-01, -3.043784107352717e+00, 6.311071601269027e+01, 1.331042375718220e+03, -1.634144666810864e+06, -1.218705516740149e+08, 2.297436373760320e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.878916023923982e-05, -4.133439563666471e-05, -4.508568501756765e-05, -5.059671162599050e-05, -5.850024209194594e-05, -6.883730814715836e-05, -7.793264721230115e-05, -6.707026406243356e-05, 2.389326001047291e-05, 2.998701803170274e-04, 8.351762069598574e-04, -2.673707771869215e-03, -2.650040853715157e-02, -1.439422138890143e-01, 2.356425082764261e-01, 1.642796146684301e+00, 4.161446521047336e+00, -1.332724563851706e+00, -5.145423210465333e+02, -7.073593001930963e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.560752946904168e-13, -6.703487368856091e-13, -8.726148185102946e-13, -1.261124673094441e-12, -2.090458669560932e-12, -4.087073860685617e-12, -9.235849524187597e-12, -1.576690594239815e-11, 2.152761205725687e-10, 7.670191810346666e-09, 2.727697867806766e-07, -3.639229748199119e-03, -3.904498925185770e-02, -1.686616351535993e-01, 2.119319645713364e+00, -5.999988492055714e+02, 1.659430259969889e+05, 5.309864457279866e+09, 1.332256514032923e+14, 9.656095629163256e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.327020402538488e-10, 3.969986619516844e-10, 5.068546748984664e-10, 7.074444683308506e-10, 1.106894409486400e-09, 1.992686681161446e-09, 4.210487169027764e-09, 1.041656290524904e-08, 2.861121890704197e-08, 7.658685511690978e-08, 5.214140673456289e-07, 2.973220094467483e-04, 3.975564323293003e-03, 9.725447581304777e-02, 3.564556205434333e-01, -1.980026401578396e+00, -5.038060555254017e+02, -3.019172398308760e+05, -1.427314335468184e+09, -1.292881290912155e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m05_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.302659499914374e-07, 1.955851366794864e-07, 1.363374483125178e-07, 2.960813694169867e-08, -1.748345275418592e-07, -5.928843723333874e-07, -1.498609901441975e-06, -3.510185999670205e-06, -7.739261570149109e-06, -1.544063125234951e-05, -3.884895704010587e-05, -1.074168731787697e-04, 7.511107756702270e-03, -8.203502349395542e-02, -4.519370183194895e-01, -1.023950668000698e+00, 2.941359171190283e+00, 1.358675902101346e+02, 6.279506133162550e+03, 7.847451347003542e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
