
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_pbe_gx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.079545404426791e+00, -4.974867551296802e+00, -4.828092406685098e+00, -4.624566766990440e+00, -4.346792572955523e+00, -3.976119357634877e+00, -3.496833935306015e+00, -2.903344448125758e+00, -2.208771422496871e+00, -1.443837064839906e+00, -7.439194260942633e-01, -5.751546922817204e-01, -5.868368294877204e-01, -4.965986585163077e-01, -3.228316082875302e-01, -1.475779696193630e-01, -3.571928335440597e-02, -2.215562763103458e-03, -2.303699463262391e-05, -3.280410133052385e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_pbe_gx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.696034506859507e+00, -6.555132202793134e+00, -6.357495012909511e+00, -6.083297641542044e+00, -5.708774680722340e+00, -5.208406146571154e+00, -4.560334634083985e+00, -3.756395466123215e+00, -2.817657929004282e+00, -1.819587476943021e+00, -1.193427556534334e+00, -8.452760276038386e-01, -9.360153813762294e-01, -7.014778050833815e-01, -4.319227046938078e-01, -1.115543394560503e-01, -7.556878989500020e-02, -7.592707164400319e-03, -9.057985274854960e-05, -1.311163075535589e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pbe_gx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.647091077260193e-06, -5.041107497458858e-06, -5.666308709898400e-06, -6.701829027802569e-06, -8.525945201990616e-06, -1.203620949776506e-05, -1.970408569530255e-05, -3.978673946637289e-05, -1.079518730866927e-04, -4.496971639693938e-04, 5.034239062350941e-06, 8.297665978952346e-04, -2.145218768078869e-02, -4.018898796525038e-02, -1.872300203917361e-01, -2.602563523543238e+00, -7.848199227153244e-01, 7.628788456792274e+00, 1.568623357117267e+01, 1.843998478356665e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pbe_gx_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.699505307602159e-03, 8.875531978963534e-03, 9.134468004143220e-03, 9.519046416012217e-03, 1.009808327504620e-02, 1.098686466911806e-02, 1.238838181808089e-02, 1.468260956796457e-02, 1.864301617068187e-02, 2.649964772971097e-02, 6.276382497740885e-03, 5.929596855854658e-03, 8.415452861038475e-02, 8.622170185283574e-02, 1.242074530071331e-01, 2.735461092417627e-01, 3.046125904259085e-02, 1.092601434607881e-03, 2.163571774667363e-06, 1.683697033034960e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pbe_gx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.497824228902280e-02, -1.569210054402930e-02, -1.678276129952804e-02, -1.849471451275356e-02, -2.129008588864436e-02, -2.612790758820323e-02, -3.525710415213024e-02, -5.486520585299003e-02, -1.057668151901864e-01, -2.720577903997015e-01, -2.714587954576173e-01, -5.987379127406790e-01, -3.936057277049055e-01, -1.558412726274035e+00, -4.949887591928604e+00, 5.091943373390276e+01, -3.040409999850832e+02, -1.115418834423513e+03, -1.173144602862058e+03, -1.045508704509139e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pbe_gx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.310997049527490e-08, 3.811760860577849e-08, 4.666009309155593e-08, 6.236124903126796e-08, 9.448110090805529e-08, 1.710788345118157e-07, 3.984098642302040e-07, 1.317045768323384e-06, 6.962553299600448e-06, 5.713563705690076e-05, -5.099516809877043e-05, -5.595322881098485e-03, 1.422022225070088e-01, 2.523006016255521e-01, 2.489996714833498e+00, -1.644602121339052e+03, 4.712788068849033e+04, 4.418432649080180e+06, 3.991683650275233e+08, 2.067737337196394e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pbe_gx_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.393386959649910e-05, -1.501697778609569e-05, -1.671328173716975e-05, -1.946649937000955e-05, -2.416090955607444e-05, -3.270795663824027e-05, -4.955139919274006e-05, -8.474595870263989e-05, -1.395035861280865e-04, 7.117117490538744e-04, 1.351563180275606e-03, 1.860258825541343e-02, -2.978834656675691e-01, -1.259062112725901e-01, 9.827670098833952e-02, 1.726779817125092e+02, -3.212738614784400e+02, -8.056438103626976e+02, -3.832626386383016e+02, -4.686889246885289e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pbe_gx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.455440440577350e-14, 4.413170934884713e-14, 6.271943661192468e-14, 1.038975438004684e-13, 2.143534866813350e-13, 6.052862535937634e-13, 2.675534891586264e-12, 2.244298039426941e-11, 4.787042602082910e-10, 5.344961297348615e-08, -3.923154569403467e-06, -1.065786232178246e-04, 1.348593940446539e-02, 4.265535335353868e-02, 4.975695640728365e+00, 3.742994655203455e+04, -9.649370945589226e+06, -2.543140434306205e+10, -2.146483691602303e+14, -6.286215199491791e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pbe_gx_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.227442443807298e-11, -5.078647800830133e-11, -6.610258761758252e-11, -9.651700806558842e-11, -1.661495736532342e-10, -3.619966534910808e-10, -1.104588607418911e-09, -5.467746009446901e-09, -5.553788011595248e-08, -2.310705484444807e-06, 4.777836029586475e-05, 4.475483958670674e-04, -4.338505156025997e-02, -6.793641582024376e-02, -2.509501670069617e+00, -3.444711696829021e+03, 7.421099367355206e+04, 5.712125504566053e+06, 3.037750230382275e+08, 2.757323550141068e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pbe_gx_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pbe_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.104145287315122e-08, 4.638941962873266e-08, 5.531806264587545e-08, 7.123410254853621e-08, 1.024185695584222e-07, 1.724764863307833e-07, 3.646248327298785e-07, 1.074634729071911e-06, 5.348736073936517e-06, 9.248801219290704e-05, -6.473759854736358e-04, -2.384593105745880e-03, 1.379708843389995e-01, 1.018193927530311e-01, 1.208074725865995e+00, 3.158437177901187e+02, -6.041286174449007e+02, -1.517601811974925e+03, -7.066013937689447e+02, -8.592313666165748e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
