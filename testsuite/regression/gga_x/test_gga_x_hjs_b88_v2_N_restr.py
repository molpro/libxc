
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_hjs_b88_v2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88_v2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.260792069502661e+00, -4.179056137807617e+00, -4.064614982861879e+00, -3.906274970513800e+00, -3.690912825383404e+00, -3.405108131319110e+00, -3.038941803636822e+00, -2.592678115018761e+00, -2.085148889074098e+00, -1.555633276970416e+00, -1.027622763221556e+00, -6.066477519729030e-01, -5.042143587689205e-01, -4.137075563095408e-01, -2.898230216195011e-01, -1.726793657893117e-01, -8.794952642844597e-02, -3.686864198663839e-02, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_hjs_b88_v2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88_v2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.316952786268302e+00, -5.203229483260486e+00, -5.043834386028085e+00, -4.822954080326082e+00, -4.521842604440800e+00, -4.120929973278007e+00, -3.605115747274829e+00, -2.974259573340650e+00, -2.257635567348149e+00, -1.537009479318537e+00, -9.644638108208536e-01, -7.408295498409155e-01, -6.551340849857746e-01, -4.976400620912242e-01, -3.035692009068328e-01, -1.367992452022026e-01, -3.648709859305502e-02, 5.765301479014533e-03, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b88_v2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88_v2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.128433326417666e-06, -4.451868188027375e-06, -4.960424362225775e-06, -5.791459602448145e-06, -7.225970251177885e-06, -9.901607326043926e-06, -1.546149725215939e-05, -2.885359226124256e-05, -6.854009232528044e-05, -2.244684854657110e-04, -1.135441842980388e-03, -7.070892749498256e-03, -1.362658522478076e-02, -2.738858114058522e-02, -9.669709612915646e-02, -6.027088419090344e-01, -6.646511231307241e+00, -1.538141553599196e+02, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b88_v2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.197176267848645e-02, -1.250934491398299e-02, -1.332425036646433e-02, -1.458760046735597e-02, -1.660873117212761e-02, -1.998314609233753e-02, -2.593065004269798e-02, -3.716210657715216e-02, -6.228691466081828e-02, -1.140427074821852e-01, -2.791583704374810e-01, -5.470997774478339e-01, -6.695854387832308e-01, -1.129782163767941e+00, -2.507825471908633e+00, -5.913664660420833e+00, -1.195427047744069e+01, -2.338894956146872e+02, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b88_v2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.103330891155125e-08, 2.389726549097970e-08, 2.869113029549088e-08, 3.725349319826040e-08, 5.400452872572204e-08, 9.112344461038225e-08, 1.878294024711961e-07, 4.978262165322393e-07, 2.039100097603310e-06, 9.509832185330615e-06, 1.764737364740764e-04, 9.405895730266537e-03, 3.430197037444777e-02, 9.879275576638800e-02, 6.774023032888956e-01, 2.273189556236638e+00, -1.049116446112362e+03, 1.603561188542286e+05, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b88_v2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b88_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.040731447181707e-13, 1.295596145774917e-13, 1.774313641851469e-13, 2.785766675375226e-13, 5.319517502623358e-13, 1.344909093576605e-12, 5.083476943024574e-12, 3.351669255158317e-11, 4.305650826114836e-10, 1.660264459719152e-08, 2.039347415753923e-06, 4.549611984075055e-04, 3.310317021655224e-03, 2.575438309137570e-02, 1.152684701160938e+00, 3.530237696405385e+02, 6.617202003662626e+05, 1.244446009616153e+10, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
