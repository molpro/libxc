
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_w94_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_w94", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.830032089353066e-02, -6.748576583492931e-02, -6.626370909016341e-02, -6.440181826734626e-02, -6.151240291927246e-02, -5.694826795501914e-02, -4.970446537099014e-02, -3.867312307621304e-02, -2.434620803914772e-02, -1.169075392936170e-02, -7.902644418549765e-03, -5.279340660409753e-02, -6.982811665379041e-02, -4.481707140572139e-02, -1.670482015870111e-02, -3.137775136991127e-03, -2.631724834963896e-04, -8.041043306448156e-06, -5.956141373652070e-08, -5.776570006747229e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_w94_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_w94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.225493855538923e-01, -1.238245141568332e-01, -1.256165336597653e-01, -1.280666561669724e-01, -1.311962826091785e-01, -1.344645160735106e-01, -1.354149651462433e-01, -1.268170167680926e-01, -9.744267174651020e-02, -5.428794905527116e-02, -3.818044085381086e-02, -1.289777660436984e-01, -1.057348326788218e-01, -1.257835162106169e-01, -7.169573546542425e-02, -1.580392474049507e-02, -1.371016781474644e-03, -4.206420807305459e-05, -3.118708627855418e-07, -3.027229834988583e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_w94_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_w94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.800454347882442e-07, 6.417566355056453e-07, 7.405146949253273e-07, 9.053097817038063e-07, 1.195607904797529e-06, 1.740918393031054e-06, 2.829649930302453e-06, 5.046139429093385e-06, 9.213929247876299e-06, 1.712967799734601e-05, 8.058066796906091e-05, 6.049008701705470e-03, 1.279629082872857e-02, 2.976225865282671e-02, 5.159628833475609e-02, 6.767624869772008e-02, 7.499125758639698e-02, 7.658023746644028e-02, 6.863565786819321e-02, 5.176168997034773e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_w94_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_w94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.983733572413839e-04, 5.232924532941613e-04, 5.553945092484201e-04, 5.894236673132546e-04, 5.967669190616214e-04, 4.573824827412757e-04, -2.960376144490407e-04, -3.264716426414853e-03, -1.203993498535084e-02, -2.921113971273651e-02, -8.327707637045280e-02, 3.821788975845661e-02, 1.781616554440033e-01, -1.590165410631452e-01, -2.759910842410354e+00, -5.269053635034282e+00, -5.848580432770656e+00, -5.523434761604598e+00, -4.621929427066886e+00, -3.323219930014445e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_w94_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_w94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.370113731882152e-09, -6.007596631616237e-09, -6.984997844411317e-09, -8.452652413769174e-09, -1.033919862534151e-08, -1.043227354547909e-08, 9.475353560537053e-09, 1.862511581006569e-07, 1.516028080070651e-06, 1.174140008609440e-05, 2.215345060978226e-04, -3.392280036349864e-03, -6.817194720353724e-02, 5.344795227345361e-02, 2.580210126126688e+00, 2.812629109153767e+01, 3.957339764239312e+02, 1.242887238349023e+04, 1.257041440779247e+06, 7.021271259681745e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_w94_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_w94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.400150139494801e-16, -3.703462348441883e-15, -1.241903407725971e-14, -3.724936521944546e-14, -1.234153146685486e-13, -5.092655589341807e-13, -2.889317184697019e-12, -2.420059862077377e-11, -3.065346978361460e-10, -6.668923333269540e-09, -8.120476033347845e-07, -1.013694215732931e-03, 6.445486409601390e-03, -1.044379449202072e-01, -3.623614827739877e+00, -2.020668765300182e+02, -3.540918861097943e+04, -3.690763528859559e+07, -4.509662053355619e+11, -1.956012125709177e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
