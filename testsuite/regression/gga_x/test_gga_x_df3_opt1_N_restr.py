
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_df3_opt1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.239106236559666e+00, -4.156253460098614e+00, -4.040204524506037e+00, -3.879548998031456e+00, -3.660851051905204e+00, -3.370246171686097e+00, -2.997228964261960e+00, -2.541550152403742e+00, -2.022837734502373e+00, -1.487185863071982e+00, -9.891349983729182e-01, -6.483141396147757e-01, -5.565779506702280e-01, -4.578991145403308e-01, -3.268422502426334e-01, -2.057189011910275e-01, -1.220564467201648e-01, -7.354710049794057e-02, -4.665775714652670e-02, -3.205137625249081e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_df3_opt1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.461012052982380e+00, -5.347723987604121e+00, -5.188915342551444e+00, -4.968793637272076e+00, -4.668584123658508e+00, -4.268515782643112e+00, -3.752702249038662e+00, -3.118423440502812e+00, -2.391138121488078e+00, -1.647861390164913e+00, -1.054694023319583e+00, -8.183779363991088e-01, -7.233498064571376e-01, -5.707869524752437e-01, -3.752921316717260e-01, -1.982572006366906e-01, -8.462489163574921e-02, -3.388322648293420e-02, -1.322695411643266e-02, -5.334056751804190e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_df3_opt1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.050783859747207e-06, -2.216730891813048e-06, -2.478561617770499e-06, -2.908599957845787e-06, -3.656574722923597e-06, -5.068065107226659e-06, -8.057218700156295e-06, -1.549649202269471e-05, -3.860659762039473e-05, -1.348275714260559e-04, -7.035570802473598e-04, -3.694468320466841e-03, -6.967375034464663e-03, -1.476633157050677e-02, -5.700446506016110e-02, -4.071488194058526e-01, -5.295496493636481e+00, -1.446210581156580e+02, -1.333657107636449e+04, -7.907901637237899e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_df3_opt1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.131128486763260e-02, -1.181226124525167e-02, -1.257202527001812e-02, -1.375124736299390e-02, -1.564339602816854e-02, -1.882773707816023e-02, -2.456354651580012e-02, -3.592599988130207e-02, -6.144019220907374e-02, -1.269325347414259e-01, -3.024822765070530e-01, -5.135634674777568e-01, -6.375239402041779e-01, -1.064594619592918e+00, -2.482431150826546e+00, -7.762296050192707e+00, -2.232778753131460e+01, 1.044857536411710e+02, 1.465484665442164e+04, 8.139839452441030e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_df3_opt1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.230413299927100e-08, 1.406011310034365e-08, 1.702416618683694e-08, 2.238749260540873e-08, 3.310428103340794e-08, 5.775935739888380e-08, 1.269432021199305e-07, 3.826735704621944e-07, 1.752362764769386e-06, 1.358112257377712e-05, 2.228067926372164e-04, 5.865882634460156e-03, 1.898953559174550e-02, 6.457756280219878e-02, 5.797375117743755e-01, 1.116710780892423e+01, -4.335883951316442e+02, -1.026203232926986e+06, -8.192955749899284e+09, -2.694770972747971e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_df3_opt1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_df3_opt1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.180670231227544e-14, 3.984120861702813e-14, 5.504640657902817e-14, 8.750535442963955e-14, 1.699094545683875e-13, 4.383198371038328e-13, 1.688532732900282e-12, 1.139443757148995e-11, 1.663808923977865e-10, 6.806963821223826e-09, 9.617491342163587e-07, 1.675292059181208e-04, 1.338884082803952e-03, 1.025427324865742e-02, 5.226781863803384e-01, 1.899109600405662e+02, 5.167786040775837e+05, 1.581292566131683e+10, 1.918168389278288e+16, 6.344073899779501e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
