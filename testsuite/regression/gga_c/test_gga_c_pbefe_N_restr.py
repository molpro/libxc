
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pbefe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbefe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.480214799052105e-02, -7.378806268310473e-02, -7.233177041102287e-02, -7.024176101741166e-02, -6.724510464689307e-02, -6.295590614253369e-02, -5.684211232451662e-02, -4.823682592070914e-02, -3.664913081220701e-02, -2.351617530126065e-02, -1.819064273539060e-02, -4.953636882618617e-02, -5.611360840624741e-02, -4.270359543188248e-02, -2.594957247983780e-02, -8.972995839694778e-03, -8.028079343219319e-04, -9.792618592100454e-06, -1.000947456929360e-08, -3.213458471991157e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pbefe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbefe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.384270280413222e-01, -1.376040297131587e-01, -1.364109412535197e-01, -1.346746399900213e-01, -1.321322886661227e-01, -1.283720597173942e-01, -1.227143526171430e-01, -1.139492155131028e-01, -9.982244694532727e-02, -7.799726776565878e-02, -6.533425713174008e-02, -8.854788229119269e-02, -8.024020492168800e-02, -7.899665656442013e-02, -6.701317439727887e-02, -3.600978511492341e-02, -4.566593392775766e-03, -6.226625039468528e-05, -6.538840070312996e-08, -2.125773523646059e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbefe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbefe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.627582533267694e-07, 7.086770523392821e-07, 7.801637857825498e-07, 8.953088619862308e-07, 1.089947390533877e-06, 1.442076569110945e-06, 2.142047971541563e-06, 3.722065303388176e-06, 7.920342911502765e-06, 2.190055768003948e-05, 1.254962535477833e-04, 2.843536579740830e-03, 6.887968373555426e-03, 1.220604241741481e-02, 3.720142757876305e-02, 1.429317146213585e-01, 2.527280310795045e-01, 1.157566975049860e-01, 1.452175814194715e-02, 3.623617764964075e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbefe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbefe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.983844633817599e-04, -2.152411335848397e-04, -2.419467126008461e-04, -2.860999644887493e-04, -3.637549363583275e-04, -5.131825034940942e-04, -8.410905447103045e-04, -1.711807000781871e-03, -4.699369231985325e-03, -1.751113628613181e-02, -6.520163087089352e-02, -3.919213656880517e-03, 1.067671217183630e-02, -9.816743330910930e-03, -4.863240457797862e-01, -6.293793546887200e+00, -2.034272277367790e+01, -1.028990427928943e+01, -1.265628994643384e+00, -3.091108271650977e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbefe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbefe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.740665102343517e-09, 2.026770711934237e-09, 2.520464715863662e-09, 3.442973658374851e-09, 5.375933741989204e-09, 1.015272466463677e-08, 2.513585916060517e-08, 9.149458391781230e-08, 5.703081808676684e-07, 6.934950323293112e-06, 1.712850812752131e-04, -9.466192400598244e-04, -1.316246740421307e-02, -1.279116587641583e-02, 3.639399274045950e-01, 3.264970808655948e+01, 1.364039428201918e+03, 2.270866424915702e+04, 3.320243377804273e+05, 6.208795428071680e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_pbefe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbefe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.158177568551659e-14, -9.939339225179962e-14, -1.319974639203917e-13, -1.983551867488216e-13, -3.557183274072549e-13, -8.209951175077611e-13, -2.713055865762493e-12, -1.492000617673149e-11, -1.686753433659282e-10, -5.236259235164744e-09, -7.962832590884482e-07, -4.693170348046887e-04, -3.875902805469485e-03, -2.649048176340468e-02, -1.142270622965449e+00, -2.792104384606469e+02, -1.206120762295718e+05, -6.375929873861690e+07, -1.106459131992020e+11, -1.587545992173836e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
