
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_x_cam_s12h_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12h", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.191042488285430e+00, -3.128838056315975e+00, -3.041956665274583e+00, -2.922212850781588e+00, -2.760366182947620e+00, -2.547792409779238e+00, -2.279924761970310e+00, -1.960646514808416e+00, -1.602021058392675e+00, -1.214462887506605e+00, -8.071405039479932e-01, -4.699678922481231e-01, -3.972513787361390e-01, -3.287360768015251e-01, -2.439614975914880e-01, -1.558847282322504e-01, -7.801449054698692e-02, -2.626644493072425e-02, -5.476142688486501e-03, -6.056939027978553e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_x_cam_s12h_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12h", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.072481886371579e+00, -3.977819586009898e+00, -3.844428653575596e+00, -3.658247095090143e+00, -3.402213762009161e+00, -3.058848827023634e+00, -2.619687701159356e+00, -2.108791941902305e+00, -1.601763688376080e+00, -1.166239665938468e+00, -7.785174665527862e-01, -5.637313044006886e-01, -5.248158357974257e-01, -3.778691184551086e-01, -2.419031516607234e-01, -1.553322192508927e-01, -9.276407918135408e-02, -3.449373282799550e-02, -7.296312111217995e-03, -8.075844583330851e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_cam_s12h_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12h", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.061891493782799e-06, -2.330383299195883e-06, -2.771723733777747e-06, -3.536747627939336e-06, -4.958758774626057e-06, -7.838777152300370e-06, -1.423431046606787e-05, -2.957180937022822e-05, -6.879413273575048e-05, -1.869978715187307e-04, -8.222119124801953e-04, -5.639783156113983e-03, -4.297065168632289e-03, -2.476053230274104e-02, -8.311202713561079e-02, -2.913099630833226e-01, -7.780030915629805e-01, -1.207679110028862e+00, -1.437758574394656e+00, -1.586957452981786e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_cam_s12h_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.212873106612405e-02, -1.289058640791815e-02, -1.405901097198476e-02, -1.588549704567725e-02, -1.878195884835386e-02, -2.331244371481115e-02, -2.962427479994404e-02, -3.497471451572733e-02, -3.137886958366012e-02, -6.705458207911830e-03, 3.858643882856514e-02, -6.148484532467677e-01, -5.774308198576176e-01, -1.184859232558827e+00, -7.000359494996384e-01, 3.347945256035216e+00, 6.046422279330583e+00, -2.927256771809027e+02, -8.441903702086172e+03, -6.971745909462377e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_cam_s12h_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.825456076232595e-08, 5.674782061083239e-08, 7.126414425179194e-08, 9.771861785737632e-08, 1.498091855448964e-07, 2.603336337949721e-07, 4.971390598657167e-07, 8.602120661083689e-07, -1.050735989364208e-07, -2.425287282447304e-05, -5.437703499155278e-04, 2.408406669470957e-02, 4.959513244477509e-02, 2.104216420395529e-01, -5.486231476165851e-01, -4.315632955043914e+01, -2.574038220754870e+03, -1.464643738976739e+05, -2.011275934449338e+07, -1.644151950252054e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_cam_s12h_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_cam_s12h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.536164197097581e-13, -4.385215133651474e-13, -5.932198932371544e-13, -9.008937460857521e-13, -1.578496784441367e-12, -3.182937980299908e-12, -6.093459193206417e-12, 1.392161544106631e-11, 6.985746426727732e-10, 2.660573117030772e-08, 3.240386442671587e-06, -9.734148513148277e-04, -1.333236800329298e-02, -2.171483347651273e-02, 2.054664046814736e+00, 4.091514591421807e+02, 2.460870287933156e+05, 4.427777872998707e+08, 7.303460877305149e+12, 4.635099006078959e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
