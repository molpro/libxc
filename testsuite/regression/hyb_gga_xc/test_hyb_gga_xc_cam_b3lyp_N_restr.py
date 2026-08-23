
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_cam_b3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_b3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.484499668492968e+00, -3.417904136364308e+00, -3.324631521329409e+00, -3.195515578202909e+00, -3.019760715983383e+00, -2.786203940903088e+00, -2.486261423662095e+00, -2.119070161704458e+00, -1.697691251391608e+00, -1.249924282539318e+00, -8.086589591615103e-01, -5.039002291259250e-01, -4.245794850300605e-01, -3.430522592509193e-01, -2.285676318586757e-01, -1.158729550454956e-01, -4.913564852707283e-02, -3.672633696716173e-02, -2.183853908261077e-02, -1.436881250342675e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_cam_b3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.358103902526951e+00, -4.266184052785654e+00, -4.137379871284051e+00, -3.958957451144015e+00, -3.715868799130747e+00, -3.392504339662409e+00, -2.976995516468246e+00, -2.469565886737068e+00, -1.896311769764231e+00, -1.327175802715738e+00, -8.695035374236940e-01, -6.379279838479501e-01, -5.591178063468987e-01, -4.382897864346129e-01, -2.906346963506284e-01, -1.626761755743348e-01, -7.057404366422351e-02, -2.069740236096108e-02, -7.388327006696692e-03, -2.544773617668590e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_b3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.177495084653449e-06, -3.422058332714562e-06, -3.805676068444324e-06, -4.430279455980478e-06, -5.502501344527899e-06, -7.485456750017885e-06, -1.155305989728468e-05, -2.116125413533475e-05, -4.846107444663772e-05, -1.458109299316920e-04, -6.266626259732794e-04, -3.913050269542014e-03, -7.559987444932820e-03, -1.265189977736409e-02, -2.787738176762791e-02, -3.197912117467727e-04, 9.747903450709492e-01, -5.946300898394765e+01, -5.907237058686640e+03, -3.512424801234830e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_b3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.582826600557754e-03, -1.000507144506420e-02, -1.064373114129380e-02, -1.163069870891745e-02, -1.320272111694624e-02, -1.581349407696812e-02, -2.039811546336506e-02, -2.901339450958298e-02, -4.617238606269364e-02, -7.888548161417579e-02, -1.442265845527468e-01, -3.980091679386051e-01, -5.166220372340289e-01, -7.759969693650395e-01, -1.255841079723021e+00, -4.192694104358603e-01, 9.962530518881188e+00, -2.674019473552531e+01, 4.542241282553272e+03, 3.453406269707918e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_b3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.567026111397072e-08, 1.773970937031042e-08, 2.118296369464377e-08, 2.727951261800841e-08, 3.905981434752434e-08, 6.474855484333549e-08, 1.306041087075685e-07, 3.364337414238247e-07, 1.090461320571495e-06, 2.035268784460701e-06, -8.452893776658497e-05, 3.350803438528200e-03, 1.411691829583674e-02, 1.811750539308664e-02, -3.085312302679785e-01, -2.888645211940161e+01, -3.375267669715179e+03, -3.297243685176505e+05, -3.537834099783851e+09, -1.193630016111550e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_b3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.228220365182354e-14, 1.025634239176604e-13, 1.406898768069269e-13, 2.212749690956040e-13, 4.228155099667611e-13, 1.064336072365910e-12, 3.945965411674477e-12, 2.504140394358148e-11, 3.309606810429422e-10, 1.164361106081984e-08, 1.459768013420724e-06, 3.367451148935560e-04, 2.865126676950196e-03, 1.821547697856073e-02, 6.794542564995765e-01, 1.491459190730034e+02, 2.647685409491523e+05, 6.989452530051527e+09, 8.471435870137789e+15, 2.817127864373324e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
