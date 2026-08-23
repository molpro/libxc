
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_kt1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kt1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.424659786898422e+00, -4.345434188208813e+00, -4.234711655048000e+00, -4.081954418825680e+00, -3.875139407919789e+00, -3.602796581712830e+00, -3.258695944148078e+00, -2.850486929715336e+00, -2.410828035206176e+00, -1.980431518414021e+00, -1.363849868413221e+00, -6.748424162088666e-01, -5.628768406023166e-01, -4.615794793913783e-01, -3.107425515549777e-01, -1.694649207737499e-01, -7.357717716623470e-02, -2.349790068506601e-02, -4.863881371189298e-03, -5.377875833868840e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_kt1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kt1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.201867353397183e+00, -5.083263815260825e+00, -4.916636445433499e+00, -4.684893363330357e+00, -4.367142588135978e+00, -3.939998464048758e+00, -3.381077709702255e+00, -2.675644905903489e+00, -1.829952774230132e+00, -9.370914013712570e-01, -5.667664390858331e-01, -7.985096078434581e-01, -7.222607098331725e-01, -5.796311510981931e-01, -3.985554646555139e-01, -2.231522922544876e-01, -9.788162894628062e-02, -3.132387758398895e-02, -6.485120068651649e-03, -7.170500402387017e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_kt1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kt1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.486896233558250e-06, -8.123493932270471e-06, -9.133979291797020e-06, -1.080855858569179e-05, -1.376081672696684e-05, -1.944900264058567e-05, -3.189649328667272e-05, -6.456436882259881e-05, -1.751976267951197e-04, -6.935090760456781e-04, -3.543060511977898e-03, -9.692930909467193e-03, -1.355396851015260e-02, -1.991125717494061e-02, -2.707608153296034e-02, -2.968914475734627e-02, -2.998838308478582e-02, -2.999987811421455e-02, -2.999999977606353e-02, -2.999999999996653e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_kt1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kt1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.487462003697404e-02, -1.568144797193028e-02, -1.692697273416300e-02, -1.891196252594044e-02, -2.222692531002517e-02, -2.815970946075112e-02, -3.993187352592719e-02, -6.717171468567154e-02, -1.455589147512399e-01, -4.249940090027378e-01, -9.762286956468175e-01, -5.489241235432740e-01, -6.210806208205302e-01, -9.424147045392957e-01, -1.988341898180410e+00, -6.389757175514789e+00, -3.322359406940045e+01, -3.244136282126560e+02, -7.568574406777338e+03, -6.190863068898107e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_kt1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kt1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.572741202982936e-08, 6.428185513523630e-08, 7.892049082121494e-08, 1.059552039954925e-07, 1.616759253252580e-07, 2.961881816558360e-07, 7.038861903294169e-07, 2.417249471295399e-06, 1.385499148086827e-05, 1.532391386851989e-04, 2.593193260485133e-03, 1.412523730729814e-02, 2.409456511798118e-02, 4.179934170806979e-02, 5.251749150705601e-02, 3.523489551259789e-02, 1.576623620632299e-02, 5.049342837967098e-03, 1.045396121542964e-03, 1.155878895489394e-04]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_x_kt1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kt1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
