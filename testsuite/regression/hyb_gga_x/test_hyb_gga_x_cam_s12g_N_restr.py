
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_x_cam_s12g_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12g", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.036124342043435e+00, -3.951427519795353e+00, -3.833024098785098e+00, -3.669619997871438e+00, -3.448350752659521e+00, -3.157062154320204e+00, -2.789481848622508e+00, -2.353335634173982e+00, -1.872123646410714e+00, -1.363534071082892e+00, -8.572466692265341e-01, -4.852548609935388e-01, -4.087179855792338e-01, -3.295477650442364e-01, -2.429806056121696e-01, -1.586056455663011e-01, -7.987631802007178e-02, -2.685511571749015e-02, -5.596939692566257e-03, -6.190434310480782e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_x_cam_s12g_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12g", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.321818089621147e+00, -5.198128087212341e+00, -5.023785072709900e+00, -4.780136105380629e+00, -4.443760408829762e+00, -3.987858908402502e+00, -3.390025543321885e+00, -2.664043990921033e+00, -1.933482856509114e+00, -1.360725758660556e+00, -8.620859042867572e-01, -6.180085949611837e-01, -5.562655161142777e-01, -3.954647863419513e-01, -2.321364778768918e-01, -1.560500103766958e-01, -9.556045046527420e-02, -3.530763684248116e-02, -7.457681824227546e-03, -8.253842701171076e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_cam_s12g_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12g", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.595585644494757e-06, -1.819803563920903e-06, -2.194569284949233e-06, -2.860990488682723e-06, -4.149844428120010e-06, -6.927045254597268e-06, -1.369706128708562e-05, -3.192715172816602e-05, -8.116409566713999e-05, -2.128732850468585e-04, -8.706069444733043e-04, -4.215514842943912e-03, -2.477466800830734e-03, -2.054384762037040e-02, -9.069990975522840e-02, -3.014212843953712e-01, -7.468393583845782e-01, -1.130484936869179e+00, -1.341359954638773e+00, -1.480316675142272e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_cam_s12g_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.446272666000819e-02, -1.537942605729289e-02, -1.681531968924910e-02, -1.914238876061838e-02, -2.307669347801705e-02, -2.999685026579097e-02, -4.200743410137572e-02, -5.777503028366651e-02, -5.412332169643225e-02, 3.716029009070304e-04, 5.571468588629196e-02, -7.087778909589104e-01, -6.080067984314634e-01, -1.477419704624750e+00, -7.973987067336260e-01, 4.700438496429398e+00, 4.642908217585467e+00, -3.048405432879212e+02, -8.634849305890144e+03, -7.125474795511101e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_cam_s12g_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.354118975103210e-08, 5.218630291237049e-08, 6.746315491288440e-08, 9.678784208885783e-08, 1.595463042533111e-07, 3.124816764102610e-07, 7.293418606709261e-07, 1.774758706149728e-06, 1.553268580941723e-06, -3.509052913649669e-05, -7.139408696507003e-04, 2.551296074234734e-02, 3.141421985509009e-02, 2.858550364357241e-01, -4.506714491974103e-01, -4.987548972443569e+01, -2.523962573959963e+03, -1.374273870502359e+05, -1.876628642805640e+07, -1.533669946142429e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_cam_s12g_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12g", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.428053357910517e-13, -4.358827502742301e-13, -6.129820438664550e-13, -9.907235933385315e-13, -1.928647804990613e-12, -4.728034858727847e-12, -1.444147754929075e-11, -3.562613236913478e-11, 5.832720576163577e-10, 3.259146824606400e-08, 3.761384610235722e-06, -1.336077945536224e-03, -8.738782087953657e-03, -5.900707240031435e-02, 2.121676748131610e+00, 4.519036820710255e+02, 2.398346749367105e+05, 4.152080386048825e+08, 6.814336145412878e+12, 4.323632956834394e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
