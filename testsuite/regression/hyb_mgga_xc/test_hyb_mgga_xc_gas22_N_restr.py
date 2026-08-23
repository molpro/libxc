
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_gas22_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.230122287710602e+00, -4.130724212983414e+00, -3.991572900039662e+00, -3.799205154239859e+00, -3.538251492845876e+00, -3.194349363721887e+00, -2.760928905396018e+00, -2.250027400372178e+00, -1.698854721695325e+00, -1.164940548423025e+00, -7.212015001907683e-01, -4.507277636455654e-01, -3.925463105415357e-01, -2.973861756254242e-01, -1.863618887639130e-01, -8.889751169545623e-02, -6.678540493585547e-02, -6.114735366466990e-02, -3.272925285396632e-02, -1.284855512603997e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_gas22_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.013685472313028e+00, -5.878923781866968e+00, -5.687997626079647e+00, -5.419231424951716e+00, -5.044622822749651e+00, -4.531550166923866e+00, -3.853818990051721e+00, -3.026207876922189e+00, -2.145865739680276e+00, -1.337260778779710e+00, -7.359963594001010e-01, -6.202873661335720e-01, -5.556612284851524e-01, -3.951938381805252e-01, -2.433572355648755e-01, -1.075688241175492e-01, -3.529313531004487e-02, -4.540058800642589e-02, -2.345803683941930e-02, -7.099039566976047e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_gas22_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.833298043187006e-06, -3.041422376235529e-06, -3.375992451474145e-06, -3.942049692726819e-06, -4.972543116747319e-06, -7.046163091119806e-06, -1.177496738684031e-05, -2.412200693888724e-05, -6.059061912883414e-05, -1.790496815164940e-04, -6.892146167742026e-04, -5.252195703145557e-04, 5.436048956032927e-04, -5.845800338645854e-03, -2.452596460254264e-02, 1.567355574298498e-01, 1.375522495349688e+00, -4.049693074324539e+01, -4.989487437326679e+03, -2.091917862018628e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_gas22_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.363629127556730e-02, 1.367528898857046e-02, 1.369485735735144e-02, 1.364795501221171e-02, 1.343249644063656e-02, 1.286117667251262e-02, 1.170421665228339e-02, 9.999304693804891e-03, 8.196993839583959e-03, 5.090872339800942e-03, 1.525542914180555e-04, 1.034819697724255e-03, -4.511421489528959e-04, -1.134167909653864e-02, -2.589783147005756e-03, -3.811610475163429e-02, -5.506762846494309e-02, -1.114863776768721e-02, -4.696044925710932e-04, -3.514068900497488e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_gas22_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.390885770353340e-02, -1.488962292961050e-02, -1.642837700391588e-02, -1.891190423081299e-02, -2.303862938820218e-02, -3.001286255693218e-02, -4.151301304730078e-02, -5.874784379476409e-02, -8.508704626527422e-02, -1.432791310026748e-01, -2.995541176386274e-01, -7.119955924796590e-01, -5.815459992954219e-01, -1.034077289073011e+00, -8.841584763305019e-01, -7.265165147208045e+00, 1.076028433768936e+01, 2.915163818429834e+02, 5.856600528180285e+03, 5.354438317981045e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_gas22_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.659741980957195e-08, 2.035194678333115e-08, 2.708687218193849e-08, 4.019439859361693e-08, 6.847011512536536e-08, 1.373633549616434e-07, 3.283324728068664e-07, 9.179541477753185e-07, 2.670595735040838e-06, -9.161664451743716e-07, -1.254130824301124e-04, 1.450758113563560e-02, -2.555845907074039e-02, 1.840353844534512e-01, -7.630790554503860e-03, -1.268350078269161e+01, 3.752066939097728e+03, 3.173179922440872e+05, -6.784214441166898e+09, -2.359559191230220e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_gas22_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.455893472661414e-05, 2.144957955015974e-05, 3.268742847099447e-05, 5.157769966744622e-05, 8.397952943354147e-05, 1.385511272005816e-04, 2.193155577249816e-04, 3.012111120130783e-04, 4.537836804267832e-04, 1.739711451740416e-03, 5.870817198258819e-03, 1.444253642928499e-02, 2.188090874173617e-02, -1.932078956637591e-01, -4.458735342344570e-01, 3.678849474197988e+00, -6.381053254378804e+01, -6.590783244605207e+02, -3.401214810837324e+03, -1.914474203024145e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_gas22_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.066589849844860e-14, -3.214743478529555e-14, -5.522992542870095e-14, -1.066270308529671e-13, -2.347915240541404e-13, -5.848696731407698e-13, -1.429619948109382e-12, 1.658555851278994e-12, 2.007156981953995e-10, 1.206707013020703e-08, 1.563168064212044e-06, -1.109239761430839e-03, 7.455575706192127e-03, -6.403953899108614e-02, -6.565638900277909e-01, -8.176965078704116e+01, -1.036839877937279e+05, 5.130552114681517e+09, 8.457547864472761e+15, 2.036677086090844e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_gas22_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.190734292944199e-10, 1.154553431035810e-10, 1.039880815684421e-10, 7.074526638111193e-11, -2.426126859913175e-11, -2.965269207028777e-10, -1.029801617222458e-09, -2.129099558817184e-09, 9.186024330724252e-09, 2.296257700088673e-07, 1.060544504831591e-06, -1.782149801878947e-04, -1.551389190732727e-03, 6.640507462434318e-05, 5.710357203622254e-01, -4.763549949874520e-01, -3.414676692721749e+03, -7.135628266376329e+05, -3.993018987315140e+08, -1.708238966952846e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_gas22_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_gas22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.090849621521893e-06, -1.267127169058737e-06, -1.546112945626347e-06, -1.998561342523091e-06, -2.744313268910594e-06, -3.953105536851017e-06, -5.721352876004593e-06, -7.977649341360748e-06, -1.590177442670609e-05, -6.509723488026475e-05, -1.798890142254481e-04, -8.021556709357757e-04, 6.113479156253045e-03, 1.720620864945673e-01, 1.729029921299724e-03, -1.165031865325642e+00, 1.084048376214347e+02, 9.763720842470984e+02, 5.261123204244992e+03, 3.115000510310622e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
