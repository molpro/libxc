
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_gap_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.162681254033946e+00, -5.069000635763534e+00, -4.937543170290930e+00, -4.754959136235692e+00, -4.504852835204092e+00, -4.168171566144444e+00, -3.723023743240756e+00, -3.138487439540221e+00, -2.356468996537857e+00, -1.385165770436962e+00, -6.503976615460880e-01, -4.439156628542983e-01, -5.876585698494081e-01, -5.161486814772573e-01, -3.202461603250049e-01, -1.295476239660961e-01, -4.483203476896348e-02, -1.350278547563073e-02, -2.782736456032938e-03, -3.082521590552143e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_gap_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.995316146890124e+00, -5.866441061361785e+00, -5.686823953544266e+00, -5.440265659417165e+00, -5.109778133779094e+00, -4.683860613492379e+00, -4.172256589623258e+00, -3.634259018554041e+00, -3.131030923972400e+00, -2.251051122970946e+00, -1.060913958766226e+00, -8.378675194296034e-01, -9.143658855879223e-01, -7.133320479246568e-01, -5.092700918436284e-01, -2.035215647123709e-01, -5.777985143581347e-02, -1.632087487160631e-02, -3.343724599979777e-03, -3.708830057292293e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_gap_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.216277822006923e-05, -1.316486858428240e-05, -1.474571821994730e-05, -1.733948912515851e-05, -2.183530230710686e-05, -3.023294043210151e-05, -4.749487036339298e-05, -8.675631523508007e-05, -1.790212113785871e-04, -3.688431337101551e-04, -9.751065409397184e-04, -6.656900577824392e-03, -3.181230661535151e-02, -7.276621518586111e-02, -1.858264450453095e-01, -4.262183475190223e-01, -1.367243680686678e+00, -1.129666887151089e+01, -2.675709601672609e+02, -2.262224251282099e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_gap_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.987275993836748e-03, 6.346761944796761e-03, 6.899330425559630e-03, 7.772618865401927e-03, 9.206201790285765e-03, 1.167759559876507e-02, 1.616709270071280e-02, 2.440654613660963e-02, 3.604434359738486e-02, 3.458488505425610e-02, 1.759959198067748e-02, 2.865715353920452e-02, 8.620204576868273e-02, 1.291648430580771e-01, 1.734137092724684e-01, 7.533746074699853e-02, 1.400712155352591e-02, 2.903721314190999e-03, 5.923647755946616e-04, 6.866129823589569e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_gap_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.603860104726507e-02, -1.669000278711684e-02, -1.764080568115169e-02, -1.901879175303211e-02, -2.094918952505190e-02, -2.330451521421916e-02, -2.441656663681237e-02, -1.610486695338723e-02, 6.945425523775171e-03, -1.705243859911776e-01, -6.232899550782063e-01, -1.504229524262645e+00, -5.004239677251267e-01, -5.423888787930827e-01, -2.706511732142756e+00, -1.390121941484232e+01, -1.909804948613680e+01, -6.770908876941323e+01, -1.224971640352012e+03, -9.529275692345831e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_gap_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.330397845309509e-08, 9.516122706077771e-08, 1.150442029270726e-07, 1.505630998717638e-07, 2.196517897767696e-07, 3.689866238434189e-07, 7.233796179434362e-07, 1.435324710198690e-06, -1.572472528362026e-06, -7.376114055548170e-05, -7.613112805700381e-04, -6.817132422422855e-03, 4.786434660231464e-02, 1.508806449612152e-01, -2.155419560740140e+00, -6.710984031104623e+01, -2.738590676329311e+03, -6.986545754876992e+05, -1.955833923650169e+09, -1.268258627340335e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_gap_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.040106867303497e-05, -7.932056873600235e-05, -9.406206371007421e-05, -1.198865826489449e-04, -1.688835195242443e-04, -2.719666401678676e-04, -5.144037579242190e-04, -1.090430195635469e-03, -1.452828790524916e-03, 5.931906957678978e-03, 2.166082838407003e-02, 9.916286155229734e-02, -1.472247711524002e-01, -5.710095352985953e-01, 1.526517242723622e+00, 1.406347490613505e+01, 3.074198519685164e+01, 1.819856589835966e+02, 4.332102642711409e+03, 3.849340574184631e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_gap_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.213721879239657e-14, 1.689728131152675e-14, 2.697468578060570e-14, 5.210425778635308e-14, 1.310377865571327e-13, 4.736250267775206e-13, 2.797450999308995e-12, 3.123396970992176e-11, 7.119942954110274e-10, 2.715657773972531e-08, 1.388053711215066e-06, 6.697137876474161e-05, 4.861514797081589e-04, 1.676973317330744e-02, 1.850540179608700e+00, 3.828753455152431e+02, 3.142903344687783e+05, 3.367652817266223e+09, 1.191213204847698e+15, 6.049400430113213e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_gap_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.493570445861393e-10, 1.849079046434939e-10, 2.511153673431746e-10, 3.890640457842565e-10, 7.263013790375198e-10, 1.758632808615691e-09, 6.054983464168625e-09, 3.231539707416200e-08, 2.603656793068824e-07, 2.348975640665712e-06, 3.299157527293286e-05, 1.769742667400539e-03, 2.150018670056674e-02, 1.509243929321242e-01, 2.413378075938261e+00, 3.031941999630813e+01, -3.189498012792411e+01, -2.858470024106139e+05, -1.125040470084813e+09, -8.332859160655014e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_gap_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_gap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.106626103980186e-06, 1.236674635570551e-06, 1.448089445357752e-06, 1.808630456786405e-06, 2.461481486805131e-06, 3.715705967505789e-06, 6.074625466570918e-06, 7.548323646645362e-06, -3.398602446908618e-05, -3.593961551236674e-04, -1.185177259062273e-03, -1.190418046582665e-02, 7.753894447229046e-03, -2.150656333979336e-02, -3.071661073619017e+00, -1.493463768726466e+01, -2.699697643415540e+01, -7.429068711419102e+01, -8.568916436351353e+02, -5.144408543963700e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
