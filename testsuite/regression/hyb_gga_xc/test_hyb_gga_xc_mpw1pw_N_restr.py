
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mpw1pw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.313697813772586e+00, -3.251428182541221e+00, -3.164207022941509e+00, -3.043454842905363e+00, -2.879064115108192e+00, -2.660587730177989e+00, -2.380043227843774e+00, -2.036927200674450e+00, -1.644766346833538e+00, -1.233580627415155e+00, -8.312620324737007e-01, -5.459338480640029e-01, -4.767433135911453e-01, -3.942488869341360e-01, -2.842694817051585e-01, -1.797536834744918e-01, -1.021194197512533e-01, -2.674064549677433e-02, -5.150294379249431e-04, -1.264221487049064e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mpw1pw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.162490816989170e+00, -4.076374083082643e+00, -3.955649208985897e+00, -3.788308049256985e+00, -3.560082250583884e+00, -3.255983387084279e+00, -2.864119417431994e+00, -2.383056760203926e+00, -1.833808119872811e+00, -1.277098739289654e+00, -8.353096277791556e-01, -6.876165090577712e-01, -6.174942824826013e-01, -4.955573150515962e-01, -3.347174007662018e-01, -1.786786168536977e-01, -9.499253610311657e-02, -6.863570832500084e-02, -1.896519595229942e-03, -4.604591252732392e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1pw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.520775805772108e-06, -2.723877628317612e-06, -3.043680878903141e-06, -3.567283533160970e-06, -4.473456988982024e-06, -6.169610919431693e-06, -9.712994265354188e-06, -1.832991057487152e-05, -4.409116604987723e-05, -1.455373172885644e-04, -7.155773788878694e-04, -2.290415464250995e-03, -2.024829160993813e-03, -7.568842698329923e-03, -3.645903196901720e-02, -3.177670451777257e-01, -2.783326065506697e+00, 7.432194184846533e+01, 3.293927502396298e+02, 6.171706728890468e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1pw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.206683238455450e-03, -9.623910712604072e-03, -1.025661283019022e-02, -1.123826862607449e-02, -1.281169607407722e-02, -1.545209242862065e-02, -2.017493915625652e-02, -2.938115333833659e-02, -4.936983077373751e-02, -9.777474487627240e-02, -2.369648002067231e-01, -4.300372722139622e-01, -4.999481178968533e-01, -9.024355125290553e-01, -2.471260996187347e+00, -8.822172741318289e+00, 6.314133837601686e+01, -1.142666395028322e+03, -1.774509771973879e+04, -3.157037327473363e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1pw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.792331091267028e-08, 2.035443644308181e-08, 2.442082726312980e-08, 3.168006764237422e-08, 4.589423293018448e-08, 7.759888907934052e-08, 1.623741563689997e-07, 4.526405996810461e-07, 1.829381753814843e-06, 1.167744303765582e-05, 1.965845075673281e-04, 7.505636345639338e-03, 1.551110955053030e-02, 7.907151655960276e-02, 9.723800850626614e-01, 2.311229081917648e+01, -6.421869395126916e+03, 9.734679418519697e+05, 4.228784534523036e+09, 5.834518240292967e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1pw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1pw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.211919240235652e-15, 1.331448955024102e-15, 7.193021872857525e-15, 2.271290117832928e-14, 7.204669925702424e-14, 2.727432646860937e-13, 1.418855053965288e-12, 1.189749963639191e-11, 1.959908569341309e-10, 8.159608521648320e-09, 1.006263343706370e-06, -2.870157002581939e-04, -4.278403599391107e-03, -1.630269546277770e-02, -3.507917089440016e-01, 5.810010093050852e+01, 6.890858895059651e+05, -9.132352221296564e+09, -1.570023973750720e+15, -1.684275539606953e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
