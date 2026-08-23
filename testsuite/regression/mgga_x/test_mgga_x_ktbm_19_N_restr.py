
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_19_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.209111300232581e+00, -5.110029767153125e+00, -4.970988970756299e+00, -4.777893242753015e+00, -4.513537273690019e+00, -4.158373040018846e+00, -3.691733298884141e+00, -3.090755465249682e+00, -2.326670450890194e+00, -1.443319550988639e+00, -7.759840600112105e-01, -5.399292992296555e-01, -5.807096641831665e-01, -5.063118189297557e-01, -3.271307969136584e-01, -1.539304068522888e-01, -6.015030868236145e-02, -1.868257119626450e-02, -3.855778178533348e-03, -4.264811450210943e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_19_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.200124880876220e+00, -6.064043746411645e+00, -5.873944607859102e+00, -5.611990460145242e+00, -5.258453809409852e+00, -4.796730854781044e+00, -4.225805406843458e+00, -3.582370697529424e+00, -2.918975686727880e+00, -2.055858918555673e+00, -1.116505330438102e+00, -8.058500104745222e-01, -8.775141900803468e-01, -6.904690681478175e-01, -4.654055001601922e-01, -2.175725090888490e-01, -7.997926423974136e-02, -2.442895060992209e-02, -5.020344400937694e-03, -5.542599227104682e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_19_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.353007569592807e-05, -1.463826657075878e-05, -1.638519359666721e-05, -1.924827453650826e-05, -2.420256056093665e-05, -3.343261250252181e-05, -5.232699670430436e-05, -9.498112175177357e-05, -1.929826413282536e-04, -3.634240130116700e-04, -6.138769964182870e-04, -3.590608859738107e-03, -2.724080560932450e-02, -6.874243250568721e-02, -1.744872044890471e-01, -3.473149737657001e-01, -6.822912227106647e-01, -3.674839144251424e+00, -8.857925062693602e+01, -8.109816706413354e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_19_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.258575535288659e-02, 1.299198292691141e-02, 1.360196224364418e-02, 1.453439798726250e-02, 1.599429391190964e-02, 1.834707260130382e-02, 2.222455371326696e-02, 2.834084163540917e-02, 3.446547294482340e-02, 2.709061804220725e-02, 9.819321902015437e-03, 1.138578237487589e-02, 7.031508974937702e-02, 1.171376935401400e-01, 1.330347795834171e-01, 5.268272940444663e-02, 7.587283289528786e-03, 1.002385037543207e-03, 1.967428761454855e-04, 2.461523340757131e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_19_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.768456313375631e-02, -1.849666047353109e-02, -1.971088458798708e-02, -2.154684212953975e-02, -2.434404609093345e-02, -2.854853775135209e-02, -3.426165549390040e-02, -3.893744630520382e-02, -4.165248782306803e-02, -1.450791937669734e-01, -3.868419406213165e-01, -9.229151903571331e-01, -8.643283444253951e-01, -1.091069288410695e+00, -2.718220589336080e+00, -1.001311601182841e+01, -3.411830867464417e+01, -3.046464907083031e+02, -7.088351821730283e+03, -5.818676664337515e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_19_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.893120218502763e-08, 1.133549713852884e-07, 1.376888465786989e-07, 1.815917865816970e-07, 2.684775002216100e-07, 4.626996303112074e-07, 9.618916771929010e-07, 2.325146717262825e-06, 3.450440915348551e-06, -4.058642714560665e-05, -5.339505001865924e-04, -8.380498411980686e-03, 1.942468362117374e-02, 1.269752953623302e-01, -1.262680405086045e+00, -3.480966926908405e+01, -2.561434669397815e+01, 2.660535873346442e+05, 8.865098004788394e+08, 5.825567527633134e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_19_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.507971358000572e-05, -8.362773963564798e-05, -9.757687419857100e-05, -1.215721694518309e-04, -1.659231415232809e-04, -2.557736378401402e-04, -4.557240385161480e-04, -8.927840549272894e-04, -1.119869971229603e-03, 3.395870138246969e-03, 1.118120228832708e-02, 5.171740919372866e-02, 4.008581918613027e-02, -1.918564516755881e-01, 1.081332791041362e+00, 7.018568569280158e+00, 5.664484091865222e+00, -5.791689168106036e+01, -1.948486093377110e+03, -1.767964230544094e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_19_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.032070503473928e-13, -2.579596449541318e-13, -3.631715280484202e-13, -5.925696298125470e-13, -1.191677557301880e-12, -3.212452568045773e-12, -1.293597805125034e-11, -8.754838324635030e-11, -1.051277555932361e-09, -1.997682492633893e-08, -7.273462348174607e-07, -6.208900100576914e-05, -2.993821238297955e-03, -4.467333210288277e-02, -1.646877903820407e+00, -1.875335573363290e+02, -1.693478057010353e+05, -2.002377952004542e+09, -7.216001598200760e+14, -3.679581759572910e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_19_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.062695821689227e-10, 6.131530730738690e-10, 8.072969924007885e-10, 1.197861339605525e-09, 2.107320652916734e-09, 4.714189878027484e-09, 1.468631462657353e-08, 7.009979963593812e-08, 5.179800934817582e-07, 4.515271826711237e-06, 4.138795707032871e-05, 1.470960717885989e-03, 3.065304086759825e-02, 2.468767728102894e-01, 4.022455601998517e+00, 7.480774327873790e+01, 2.659254097871546e+03, 6.755368743725258e+05, 2.093252287238013e+09, 1.476234938147697e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_19_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_19", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.091177829647624e-07, 1.044632400869582e-07, 9.037321740894864e-08, 4.796767185913931e-08, -8.828510995728286e-08, -5.858587573157323e-07, -2.786900407561866e-06, -1.510194853884677e-05, -9.397731246848171e-05, -4.228579242191936e-04, -9.040787633375686e-04, -6.636508345514293e-03, -7.152553474239366e-02, -3.830932956403414e-01, -3.730348527487959e+00, -1.535406248477812e+01, -3.658707267876262e+01, -2.199370271309361e+02, -5.738819882523096e+03, -5.571572471231024e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
