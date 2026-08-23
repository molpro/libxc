
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m06_2x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.969512468115362e-02, -9.788484082852138e-02, -9.526697532803272e-02, -9.147774780312375e-02, -8.599628749732235e-02, -7.811294665699689e-02, -6.702300180545809e-02, -5.250961612284846e-02, -3.737222324363673e-02, -2.796339610274066e-02, -2.400660926437924e-02, -6.698297785830382e-02, -4.762371662402642e-02, -3.563494809299287e-02, -2.096352518538157e-02, -2.815536873026258e-03, 2.494752600011552e-02, 2.359403793604734e-02, 7.015442980606672e-03, 8.928168641565236e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m06_2x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.521315112334685e-01, -1.530657251352585e-01, -1.543374270093764e-01, -1.560000879443963e-01, -1.579943469448400e-01, -1.598793055686175e-01, -1.600520981048277e-01, -1.535815542678205e-01, -1.291877035804601e-01, -9.490829054723635e-02, -1.426725315711080e-01, -6.972735212550021e-02, -5.344725095804760e-02, -6.312480649255781e-02, -6.318080021291776e-02, -2.827806821289550e-02, -1.069421745896328e-02, 4.041539924787706e-03, 1.142995919356122e-03, 2.475617090451030e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_2x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.229812220757221e-07, -2.811367824847872e-07, -2.084279145934972e-07, -7.385875681486081e-08, 1.957452871751241e-07, 7.912945536161070e-07, 2.267111862143018e-06, 6.355371428374442e-06, 1.779051827724786e-05, 4.284035189810981e-05, 3.642947462563191e-04, 4.468108838425227e-03, 6.148336176036130e-03, 1.133835382163820e-02, 6.474042966232169e-02, -7.158979452779470e-02, 1.443265386383665e+00, 1.315182376582632e+02, 5.762557994925187e+03, 6.655739281133845e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_2x_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.819145567511800e-03, 1.757419397522669e-03, 1.666293630474937e-03, 1.530012718418582e-03, 1.322168682977356e-03, 9.962054446405325e-04, 4.695215508039576e-04, -3.668503115556834e-04, -1.349012339982563e-03, -1.108176607489396e-03, -6.488980934163235e-04, -5.320452242306565e-03, -6.593266855725873e-03, -4.437417502935834e-03, -1.825636320732979e-02, 2.618666940673433e-02, 1.490843574548757e-02, -2.857114538185387e-02, -1.266663430139321e-02, -2.019923031780168e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_2x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.011744119468511e-03, 1.076822567116200e-03, 1.175969383636180e-03, 1.330639147016056e-03, 1.579419600296362e-03, 1.991032706528413e-03, 2.643288768395811e-03, 3.074239613785317e-03, -2.661064425278159e-03, -3.968454188353526e-02, -1.766896904021277e-02, 1.310509839313323e-03, 6.477433849827170e-02, 7.978237937005186e-03, -1.452713434479048e-01, -1.553182569387819e+01, 4.085162187569013e+01, 1.847141550013364e+01, -5.243471455802008e+03, -8.943245331804134e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_2x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.922895740953119e-08, -2.203608864725266e-08, -2.679551040648390e-08, -3.547418821951507e-08, -5.304355929540061e-08, -9.420278651250669e-08, -2.098163545226479e-07, -5.723813932591505e-07, -7.557530037337101e-07, 2.999216462428054e-05, 4.118428196305659e-04, 3.603359432949998e-03, -3.611439172073063e-02, -1.108548544338525e-01, 3.482648871980615e-01, 1.809411984820590e+02, -9.504921105598303e+03, -7.378821723833170e+05, 5.038162793063603e+09, 5.314623113745112e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_2x_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.746330417080028e-05, 1.910301558787860e-05, 2.174680334190904e-05, 2.623453401150263e-05, 3.442804554978394e-05, 5.088877062104339e-05, 8.729227815611713e-05, 1.655689103208364e-04, 2.032274828598335e-04, -9.543533048806774e-04, -4.615842469895038e-03, -5.158339851538234e-03, 7.154289702883321e-03, 1.486711424497511e-01, -2.194814967324419e-01, -1.272768251607500e+01, 7.422401542729011e+01, 3.025535771945366e+02, -1.092718317161570e+04, -1.612838191564959e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_2x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.558293916971692e-13, 1.917525729571243e-13, 2.586574399788300e-13, 3.987385524228055e-13, 7.467692594834131e-13, 1.852262799433465e-12, 6.720154763951976e-12, 3.617461814684242e-11, 1.058575373393704e-10, -2.000313229649407e-08, -3.314634879170586e-06, -1.783547909765158e-03, -6.714934998318212e-03, 2.330104868095122e-02, -1.306829068552667e+00, -1.836147072261284e+03, 3.126913822016238e+05, 3.805684827077287e+09, 1.343616465530331e+14, 1.381063029006893e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_2x_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.843623126809551e-10, 1.929272350387529e-10, 2.023145391532497e-10, 2.055277146851515e-10, 1.699895994445060e-10, -6.022092047984700e-11, -1.323642161648054e-09, -8.633003454468549e-09, -4.484161372940164e-08, 2.181414178351271e-07, 1.508579318215746e-05, 6.560559798566427e-04, 1.240887216983661e-02, -1.956948875695390e-02, -2.704265382870299e-01, 1.168718915238971e+02, 2.158155298130530e+03, -5.939900960380784e+06, -3.238173334034071e+10, -2.950111598050129e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_2x_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.905584140690190e-07, -1.028698432250190e-06, -1.083533356432929e-06, -1.160809887760615e-06, -1.262616824074817e-06, -1.364086282045931e-06, -1.299613283900102e-06, -2.296124979867182e-07, 5.072614230392498e-06, 1.359830068934000e-05, -2.567243153785796e-05, 1.418996731352067e-04, -1.276526930419099e-02, -4.968715973761283e-02, 4.033646242050269e-01, -6.985974750837430e+00, -8.748068427672230e+01, 2.373188397709340e+03, 1.417040134148957e+05, 1.790507345092051e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
