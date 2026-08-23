
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mbeef_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.632142405198314e+00, -4.543103696160678e+00, -4.418499141821973e+00, -4.246232694449088e+00, -4.012234134017409e+00, -3.702397758412945e+00, -3.307047234526745e+00, -2.828507149569395e+00, -2.285552780771241e+00, -1.640466152965298e+00, -1.002062751386928e+00, -6.176510931633149e-01, -5.798692012727820e-01, -4.969127367864254e-01, -3.516930890203565e-01, -2.063451031721440e-01, -8.845264992633667e-02, -2.803194108597537e-02, -5.585183688847530e-03, -6.160496605901226e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mbeef_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.866627481508547e+00, -5.740560950073610e+00, -5.563618400752300e+00, -5.317912200367164e+00, -4.981916806641597e+00, -4.532486777784209e+00, -3.950338664144013e+00, -3.231171225312255e+00, -2.384254086455554e+00, -1.348815301038476e+00, -1.057769503588952e+00, -8.216693363825620e-01, -8.104764827155478e-01, -6.346958729905449e-01, -3.575181263223187e-01, -2.507634573597156e-01, -1.360078254722964e-01, -4.043610093631524e-02, -7.483105473035464e-03, -8.214518765577561e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeef_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.306798854319637e-06, -3.605555190818527e-06, -4.082283496335734e-06, -4.878039898473749e-06, -6.294450691410478e-06, -9.057052044246340e-06, -1.520249402042114e-05, -3.203217529476251e-05, -1.070483831126839e-04, -8.619860946293906e-04, -1.146940219251101e-03, -7.158639569655936e-03, -1.535044420488632e-02, -4.981007017817389e-02, -2.951413246607120e-01, -1.857396609131500e-01, 3.392317304309829e+00, 1.056928174303374e+01, 9.859475953800294e+00, 1.105550018260937e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeef_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.354547098087916e-05, -3.549054680285032e-05, -3.824944966705427e-05, -4.191307508925737e-05, -4.553578113923051e-05, -4.203062762737685e-05, 1.447091439224962e-05, 4.708184176769560e-04, 4.743101865832964e-03, 3.413574830542079e-02, 4.788219250389259e-03, 7.609612280480355e-03, 3.131718902895046e-02, 6.208015491731198e-02, 1.252233123970673e-01, 7.045521938946002e-03, -2.464247871985782e-02, -1.421384409263665e-03, -1.789066368736733e-08, 4.225019764745852e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeef_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.443494470467358e-02, -1.517286275313361e-02, -1.629952495740417e-02, -1.806073779530250e-02, -2.089588677968838e-02, -2.558721637516864e-02, -3.321721303878336e-02, -4.180654917106371e-02, -1.906723552367273e-02, -4.408221355261024e-01, -1.723969906460631e-01, -1.026629858993349e+00, -1.875191240376220e+00, -1.729990244598126e+00, -7.393660628242409e+00, -4.887521328716831e+00, 3.788988835762711e+02, 4.411753326935702e+02, -9.233648565213720e+03, -7.097772652303597e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeef_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.855638428955044e-08, 5.601749888700188e-08, 6.859548556107452e-08, 9.114294214701808e-08, 1.347140860878310e-07, 2.244550281884357e-07, 3.858698243681541e-07, -9.126549227550149e-08, -2.000195712823807e-05, 2.531524570706227e-04, -1.351542170896471e-03, 2.168921939972876e-03, -1.315004288027388e-01, 5.559527868178845e-01, 1.086770378321171e+01, 2.323917437265968e+02, -8.647970206453835e+04, -6.383084161189623e+06, 1.356393882472163e+08, 1.205498420110187e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeef_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.465190771051978e-05, -2.659234382432485e-05, -2.946611006960759e-05, -3.362042604620279e-05, -3.891157521400331e-05, -4.108812373374697e-05, -6.682450459800809e-06, 3.317830185555112e-04, 3.332742628719239e-03, -6.927324589951851e-03, 1.447301240477707e-02, 4.855777143308723e-02, 6.260972546154219e-01, -4.424094121409725e-01, -3.672378709219977e+00, -3.118383122357274e+01, 6.556578893595376e+02, 1.719987428500757e+03, 2.088886183498575e+00, -1.806848640067933e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeef_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.670261988828595e-13, -6.926515537389609e-13, -9.176699558970225e-13, -1.353283158547399e-12, -2.262093815687630e-12, -4.028315445794816e-12, -9.475088005809215e-13, 2.208778379580395e-10, 1.106719175376155e-08, -5.976313158061445e-08, 2.881949632811921e-06, 1.456118196793885e-04, -2.972012186527395e-02, 2.172287258046842e-01, -2.156274598842843e+01, -6.459107399803243e+03, 1.712271645724000e+07, 4.398399179516184e+10, -4.862159863781774e+13, -3.571803213017993e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeef_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.056399865421865e-10, 8.097989720104363e-10, 9.803431715591012e-10, 1.268337011774584e-09, 1.748664810525260e-09, 2.301776253577584e-09, -5.365601188624791e-10, -6.487933252921582e-08, -1.515499322222504e-06, 2.365486622092171e-06, 3.839735383279011e-05, 9.956026838004164e-04, 1.040538625833064e-01, -4.849472203224284e-01, 1.110013687427812e+01, 6.791487530616409e+02, -1.315812740881256e+05, -1.183495247064491e+07, -2.966491508582558e+06, 1.047398692547803e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeef_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeef", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.001984534939206e-06, -1.080334481470248e-06, -1.195284216435857e-06, -1.357538005925781e-06, -1.546936670935980e-06, -1.517777247423300e-06, 5.728318467065260e-07, 2.016319847516294e-05, 2.197636871378698e-04, -2.307803508637978e-05, -9.394500416266266e-04, -5.668083608146867e-03, -3.709997053802748e-01, 9.648639226519247e-01, -5.417280525690874e+00, -6.541485861340283e+01, 9.971796379174317e+02, 3.092442967516589e+03, 8.486593940983479e+00, -3.234765867550549e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
