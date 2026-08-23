
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_rregtm_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.650614430755276e-02, -2.645881781408067e-02, -2.638867559528272e-02, -2.628337454914504e-02, -2.612244278672018e-02, -2.587070660406489e-02, -2.546846990819262e-02, -2.486386603641430e-02, -2.499266071035429e-02, -3.107155158510425e-02, -2.937259453509341e-02, -4.723541613336868e-02, -5.400416953950712e-02, -3.994910911614629e-02, -2.926152371035272e-02, -1.880985179330156e-02, -9.249068211195392e-03, -2.994999074586777e-03, -4.627093054488734e-04, -2.284445110954115e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_rregtm_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.904445185212275e-02, -2.909248068456223e-02, -2.916945764216172e-02, -2.930092487137214e-02, -2.955150739753938e-02, -3.012977553023343e-02, -3.195104510389370e-02, -4.049702495851593e-02, -8.524109835949066e-02, -8.271725370162325e-02, -5.610753229272398e-02, -7.971928127175626e-02, -7.551893642363583e-02, -6.337089743097712e-02, -5.677640938458988e-02, -3.542404379489865e-02, -1.656021222579212e-02, -5.524200033433358e-03, -8.902248566969922e-04, -4.514249216080411e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rregtm_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.632529599510758e-08, 2.944984993845478e-08, 3.473347116339736e-08, 4.444748020105772e-08, 6.494031819866816e-08, 1.197096142799760e-07, 3.393379952941286e-07, 1.937518190386995e-06, 2.005691356950566e-05, 4.713997090751657e-05, 6.436734304213258e-05, 2.186010818669280e-03, 7.688093082327922e-03, 1.721445044695721e-02, 4.395727463790785e-02, 8.910163062366064e-02, 3.210617256556096e-01, 3.908794913251414e+00, 8.118486872299850e+01, 3.212383777271662e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rregtm_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.729032925042046e-06, -4.486089681086803e-06, -5.856246605119276e-06, -8.601181840264127e-06, -1.496593456032479e-05, -3.313722483120559e-05, -1.021300411589067e-04, -4.685580122683636e-04, -2.537313842990916e-03, -1.732096266424232e-03, 5.438318875387207e-05, 1.781766708186225e-04, -1.665666291026252e-03, -1.517072967541798e-02, -1.322336957304307e-02, -1.134071975068669e-03, 1.109927310266489e-03, 2.001805288989076e-04, 7.759990952978301e-06, 2.740704196236937e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rregtm_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.108325711491586e-04, -1.368678227015004e-04, -1.847143714936418e-04, -2.823267243773206e-04, -5.128930650237807e-04, -1.178434639405597e-03, -3.655318796866051e-03, -1.512258521907530e-02, -4.067202447313013e-02, 3.594813901235961e-02, -3.235071112335697e-02, -5.192357624064746e-02, 4.699532123491235e-02, 3.450167378672256e-02, 1.161421473722512e-01, -3.245422127686289e-01, -2.307518910880139e+01, -2.571183893176780e+02, -3.757949658046639e+03, -1.184301496231115e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rregtm_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.489354992296556e-09, 4.552585191752559e-09, 6.662196219195010e-09, 1.147656857788427e-08, 2.488516550302935e-08, 7.426874537087907e-08, 3.386975036908811e-07, 2.474194223814165e-06, 1.598801169650397e-05, -5.301465702482322e-05, 7.858087369026786e-05, 2.488703268887946e-03, 4.855318929843372e-03, 3.704571977226434e-02, -1.411195442108811e+00, -2.814026299628957e+01, 2.426947533601535e+03, 9.323537180094112e+05, 1.211899368504699e+09, 1.903064065975924e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rregtm_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.261959729063454e-06, -6.423924755979183e-06, -8.553236266098097e-06, -1.288754703515200e-05, -2.312604379785512e-05, -5.284616473626573e-05, -1.654070907062266e-04, -7.110344591280342e-04, -2.205568526623239e-03, 2.498784177798931e-03, 5.014162474778882e-05, 7.531165164972748e-04, -3.268956225542029e-02, -9.614155786511167e-02, 8.082020824510970e-01, 3.610851312195479e+00, -1.138982699333101e+01, -1.639314122697718e+02, -1.436252673772376e+03, -7.775153124658379e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rregtm_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.070609188095877e-13, -1.480667575093752e-13, -2.358823319189272e-13, -4.599886276581742e-13, -1.195788976880442e-12, -4.653463928177148e-12, -3.128041672564842e-11, -4.035292461666842e-10, -6.174643626994464e-09, 7.666589566897667e-08, -3.949460825157070e-07, -6.145107429028746e-04, -7.130148971844095e-03, 8.691148692373722e-02, 7.494976155580487e+00, 6.582548221556270e+02, -4.198657025629418e+05, -5.343991276369042e+09, -7.519123999516186e+14, -7.340959744622867e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rregtm_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.524523597178450e-10, 1.983602841046830e-10, 2.894618366102577e-10, 4.976157560359817e-10, 1.079380059406229e-09, 3.239385238253150e-09, 1.500280630302810e-08, 1.134290263644405e-07, 7.932554585068653e-07, -3.943671066148539e-06, 1.617531986338325e-07, -9.913153832609137e-06, -4.942067034303455e-03, -2.300784418929667e-01, -4.689471604412692e+00, -7.274144072937573e+01, 2.526633504284889e+03, 1.101212896678483e+06, 1.107401110269886e+09, 4.518696040130783e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rregtm_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rregtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.180455531439883e-07, -2.668304741060702e-07, -3.565359012890968e-07, -5.400617789352820e-07, -9.768747325028673e-07, -2.259483015691611e-06, -7.205445544864365e-06, -3.191324905674467e-05, -1.020013870122980e-04, 1.961339830934973e-04, -4.159458410351437e-06, -6.909217779270009e-05, 1.917738913662673e-02, 4.411581283467443e-01, 2.655687518716972e+00, 6.844822036602721e+00, -2.045257327531563e+01, -2.861740255519494e+02, -2.541734920614458e+03, -1.398753924004104e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
