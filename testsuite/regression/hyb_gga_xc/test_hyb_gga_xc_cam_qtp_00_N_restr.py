
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_cam_qtp_00_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_00", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.998080341323979e+00, -1.960126268614193e+00, -1.906959459425479e+00, -1.833342341613705e+00, -1.733092318408804e+00, -1.599781875283824e+00, -1.428375421109934e+00, -1.218061156616702e+00, -9.755596430604867e-01, -7.153821684726078e-01, -4.593120678623965e-01, -2.939450362066610e-01, -2.491680798780936e-01, -1.995533316075415e-01, -1.282893180722554e-01, -5.432697600675124e-02, -1.150091280275701e-02, -1.321926766849521e-02, -6.662162605241587e-03, -3.822759351725008e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_cam_qtp_00_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_00", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.498931375906756e+00, -2.446729917592146e+00, -2.373585774796759e+00, -2.272273827346686e+00, -2.134263669993001e+00, -1.950727375299805e+00, -1.715015095403698e+00, -1.427484100476832e+00, -1.103549643924357e+00, -7.840721171852999e-01, -5.253166335041946e-01, -3.780400822147794e-01, -3.304977325075042e-01, -2.626703286964087e-01, -1.799789926786823e-01, -1.078231800576178e-01, -4.664573609580806e-02, -1.034767123599998e-02, -3.269073194682981e-03, -8.238840226839242e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_00_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_00", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.768538328332078e-06, -1.903642202406079e-06, -2.115358026750726e-06, -2.459563981132614e-06, -3.049088243488158e-06, -4.135311897550511e-06, -6.349379309524159e-06, -1.151772293448075e-05, -2.583472391990018e-05, -7.365072925112494e-05, -2.779044416284166e-04, -1.769033353293249e-03, -3.354546629832321e-03, -4.684348103828794e-03, -1.860402655293285e-03, 1.537611948768967e-01, 2.747212227387147e+00, -1.218780643068979e+01, -1.519003829290530e+03, -9.031949488889880e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_00_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.420960864769188e-03, -5.658393104869161e-03, -6.017251384672858e-03, -6.571175933909226e-03, -7.451776932407288e-03, -8.909423984937319e-03, -1.145303193301340e-02, -1.616703661455581e-02, -2.519721523469870e-02, -3.978238156450303e-02, -5.861616663912191e-02, -2.169366831512618e-01, -2.902295495995834e-01, -4.108710570512145e-01, -5.028476189129283e-01, 1.445249492529523e+00, 1.185406227561776e+01, -7.138148038108609e+01, -2.956466609988825e+02, 7.457322617742422e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_00_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.599944809396419e-09, 9.723525127014025e-09, 1.158876193725642e-08, 1.487956877611757e-08, 2.120133118657722e-08, 3.484620135887351e-08, 6.912686611581325e-08, 1.711481306877461e-07, 4.793806938566048e-07, -9.742229508382276e-07, -1.138961471670875e-04, 8.610017542099379e-04, 4.642124468968878e-03, -5.684658177961498e-03, -4.290492265502509e-01, -2.897499432397720e+01, -2.933817431293711e+03, 1.206695793092168e+04, -9.097289487129353e+08, -3.069334327147142e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_00_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.631987868708886e-14, 5.772646738062295e-14, 7.916418153671931e-14, 1.244583998208732e-13, 2.376725654771721e-13, 5.977193545086138e-13, 2.212651611044568e-12, 1.400560027725743e-11, 1.842348231769797e-10, 6.419841059874478e-09, 7.895951124525689e-07, 1.785281595639130e-04, 1.498714684534234e-03, 9.298516390936148e-03, 3.221909170233896e-01, 5.498717327828407e+01, 6.993426258758087e+04, 1.797474807253322e+09, 2.178369272817273e+15, 7.244043079817784e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
