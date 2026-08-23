
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_cf22d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.969108080490340e-01, 4.282854361450764e-01, 2.067648509735658e-01, -7.065300221561424e-02, -3.915962457287335e-01, -7.143279401940286e-01, -9.617925655732008e-01, -1.072517411257361e+00, -1.158913349308444e+00, -1.388195729762964e+00, -1.139394857698048e+00, -4.728240921405993e-01, -2.945233284561995e-01, -2.529938375823438e-01, -2.328516741589817e-01, -1.492608159079143e-01, -3.160177717484777e-02, 4.830731627651112e-04, 1.298608141701959e-04, -2.294820903361775e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_cf22d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.364135107826288e+00, 7.756577702645637e+00, 6.916310225308167e+00, 5.781002792093310e+00, 4.309703003306717e+00, 2.550996949496747e+00, 7.882069724261053e-01, -3.045810236485135e-01, -1.213154694858887e-01, 2.413153034297666e-01, -3.050590592111528e-01, -4.304736378287951e-01, -2.333184493983281e-01, -1.610011716053781e-01, -1.216204641423235e-01, -1.495426580017238e-01, -7.837409183093073e-02, -2.687647150746215e-03, 1.820841638861437e-04, 3.990713910806369e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_cf22d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.346227988670576e-05, -3.427858583527053e-05, -3.533968746459075e-05, -3.657959574708590e-05, -3.760841637905244e-05, -3.705009958498786e-05, -3.091454741413531e-05, -1.140809378339817e-05, 5.082649089780287e-06, -2.879422810416670e-04, -2.544720632673797e-03, -1.252400102444219e-02, -9.308656426106079e-03, -1.727267605126089e-02, -1.538748789943263e-01, -9.148821762038112e-01, -1.399363920496297e+00, 6.810240520489736e-01, 2.374203193649952e+00, 2.968709023912386e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_cf22d_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.006113199870565e-01, -9.472744924581895e-02, -8.644384319661645e-02, -7.501916430561394e-02, -5.994140998343152e-02, -4.195906995716479e-02, -2.558519312549404e-02, -2.183517743557107e-02, -3.710156091420518e-02, -3.792925134630444e-02, -1.259030004584760e-02, -9.255073341743046e-03, -5.383110474654197e-02, -7.653696750535995e-02, -1.851970141380305e-02, 7.559441272795869e-02, 4.269085427171315e-02, 3.171333478855933e-03, 3.572690681121229e-05, 5.453059750627652e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_cf22d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.194438268189541e-01, 1.251138898293384e-01, 1.331295189338731e-01, 1.440878425462082e-01, 1.577106607857202e-01, 1.696401713095193e-01, 1.610177968381101e-01, 7.708210028830968e-02, -1.352443106969242e-01, -2.482931982659798e-01, -6.321029173686575e-02, 3.039296457908137e-02, 5.194198830536821e-01, -1.589130224404326e-01, 2.210225608003096e-01, 1.197279038609909e+01, -6.777045107714211e+01, -3.527586078647434e+02, 1.226344599594226e+01, 3.108710298504149e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_cf22d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.968066131609722e-07, -2.348020644006195e-07, -2.995762231229063e-07, -4.172133759774492e-07, -6.483129556127372e-07, -1.142227086399914e-06, -2.244170692729694e-06, -4.090693427832675e-06, 4.416533464111929e-06, 1.930815980347234e-04, 2.099477416325893e-03, 3.182882727877534e-02, 5.410071402525424e-02, 2.365783137917855e-01, 3.036157093050902e+00, -6.726663224635529e+01, -2.652517344238956e+03, 8.882999304541730e+04, 3.289166108417954e+07, 3.072296444912527e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_cf22d_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.951964559201147e-03, -2.041427688591199e-03, -2.164165156399239e-03, -2.322195030358497e-03, -2.490614955188404e-03, -2.544802366811190e-03, -2.054725442940542e-03, -5.177488800884149e-05, 2.733153104694718e-03, -4.818113900401380e-03, -2.227376544130834e-02, -5.605420840733245e-02, -3.199798378685217e-01, -4.594784645637723e-01, -2.373914901727967e+00, -2.372193719772000e+00, 6.290536360605481e+01, 2.734089587692048e+02, 3.744154980421781e+02, 4.237935878491505e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_cf22d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.901291391895530e-13, 4.755952930263057e-13, 6.304596650704820e-13, 9.394305130716899e-13, 1.642865726915611e-12, 3.548219748467152e-12, 9.878905355237669e-12, 3.374222396755714e-11, 2.905965937546884e-11, -2.957421509976816e-09, 1.723878297515477e-06, 1.046504420791374e-03, 5.221422760470018e-03, 5.018287908501750e-02, 2.649355009361376e+00, 3.710794635164274e+02, -8.850581692800035e+04, -4.241052762633182e+08, -1.218837600432163e+13, -8.671852266321474e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_cf22d_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.758113212874951e-09, 1.108926159000933e-08, 1.328006765875464e-08, 1.707459308500304e-08, 2.407381908978651e-08, 3.782824639310277e-08, 6.505127977940812e-08, 9.993123607587825e-08, -1.130275747499984e-07, -3.104714713148433e-06, -2.551074967341107e-05, -1.432688915975331e-03, -1.360375080168726e-02, -1.460048217617183e-01, -1.570803939564579e+00, 6.740142535764728e+01, 4.097031147274751e+03, 4.937193460556036e+04, 3.786622351360062e+05, 4.332698158376465e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_cf22d_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.850043943175928e-05, 2.920003794242912e-05, 2.996391702795095e-05, 3.043725530011484e-05, 2.944108586081232e-05, 2.346029602323355e-05, 3.570671484173471e-06, -4.056182957627641e-05, -3.669130408035173e-05, 3.465722589089957e-04, 9.515280803888465e-04, 5.559314862779386e-03, 1.510270848087794e-01, 5.788931617467032e-01, 2.339093222588029e+00, -9.011791217678901e+00, -1.054799374515333e+02, -2.845788318545857e+02, -4.007436912088337e+02, -4.833872382109162e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
