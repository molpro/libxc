
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_17_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.182077773950241e+00, -5.080273444151302e+00, -4.937450683114300e+00, -4.739209951329761e+00, -4.468122309814217e+00, -4.104873191309868e+00, -3.630705902420662e+00, -3.030119071237748e+00, -2.294568159594593e+00, -1.478577133177805e+00, -8.404074548258325e-01, -5.727427616070994e-01, -5.778656692602436e-01, -5.005870393207424e-01, -3.314727393723788e-01, -1.686137085965355e-01, -6.971451616226582e-02, -2.199122930506683e-02, -4.549108650057343e-03, -5.033476465389534e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_17_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.350827802543298e+00, -6.211416892168902e+00, -6.016336134355837e+00, -5.746760952317058e+00, -5.381138560175475e+00, -4.899153576970236e+00, -4.291658416904931e+00, -3.579113541436223e+00, -2.811105309209196e+00, -1.944569836341958e+00, -1.119070793637698e+00, -7.883969159596095e-01, -8.627701672922056e-01, -6.764375400463200e-01, -4.403483183054120e-01, -2.212505750269462e-01, -9.015165698242020e-02, -2.837722368456293e-02, -5.854221801173559e-03, -6.464725450097270e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_17_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.223067103459971e-05, -1.322786768669826e-05, -1.479914614071648e-05, -1.737284804971549e-05, -2.182314375316396e-05, -3.010846310588900e-05, -4.707270809698174e-05, -8.556099721656872e-05, -1.762689747491681e-04, -3.489615102858721e-04, -6.295355333342055e-04, -3.505626866839287e-03, -2.482081845296519e-02, -6.252687872722326e-02, -1.648731248120874e-01, -3.673526835256216e-01, -8.958607706139010e-01, -6.159701129277572e+00, -1.539812374999273e+02, -1.390333045917103e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_17_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.418807933860811e-02, 1.454808361014836e-02, 1.508192829495401e-02, 1.588319160168485e-02, 1.710446432705964e-02, 1.899597433997035e-02, 2.193252822667960e-02, 2.614264539739761e-02, 2.940840188315851e-02, 2.200433574504440e-02, 7.384363951692797e-03, 5.961395629628760e-03, 6.335923464057103e-02, 1.036197073236481e-01, 1.075647912496027e-01, 4.438534102094713e-02, 8.027092479923488e-03, 1.559920496145786e-03, 3.406127533429130e-04, 4.219780232894773e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_17_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.762834040438521e-02, -1.846712556704324e-02, -1.973245399224491e-02, -2.167502359419664e-02, -2.471917008700996e-02, -2.957115124546325e-02, -3.721846289184629e-02, -4.801335028889524e-02, -6.256600133908163e-02, -1.295815180791396e-01, -2.815419285540212e-01, -7.560223410658279e-01, -1.016372957550198e+00, -1.394126955579629e+00, -2.737031816515865e+00, -7.334112413368427e+00, -3.390209180339823e+01, -3.468458001200260e+02, -8.205588264206546e+03, -6.741639701032883e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_17_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.807761193869478e-08, 1.008598402479269e-07, 1.224129836347485e-07, 1.612758813626684e-07, 2.381563501272148e-07, 4.101552188689066e-07, 8.550155772580221e-07, 2.111697420215013e-06, 3.853683600145682e-06, -2.950616949378525e-05, -4.706128274144828e-04, -7.422689670902044e-03, 1.996727410245496e-02, 1.276221326971965e-01, -8.573967614372788e-01, -2.998181542827209e+01, 8.251980775348213e+01, 3.017910198535293e+05, 9.947755880688919e+08, 6.540907049090616e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_17_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.860838164491499e-05, -6.475197740912056e-05, -7.467961226025075e-05, -9.151738577014212e-05, -1.220090321619303e-04, -1.819664592286220e-04, -3.095501779700495e-04, -5.675991367513258e-04, -6.113589182750267e-04, 2.433821670329215e-03, 7.106475124922134e-03, 3.695618196989087e-02, 1.048166092810859e-01, -2.944960138967921e-03, 9.034809131305731e-01, 4.502991850432404e+00, 1.607025350772704e+00, -7.060417778505582e+01, -2.192292463747146e+03, -1.985124987347327e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_17_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.737735815481427e-13, -2.204771900904311e-13, -3.101638388563076e-13, -5.055345907460491e-13, -1.015163257323582e-12, -2.731788525233231e-12, -1.098703172461219e-11, -7.463494191105701e-11, -9.210183247184699e-10, -1.926370365257645e-08, -7.927289111283887e-07, -6.546687847175960e-05, -2.640234595471914e-03, -3.903660196693132e-02, -1.547870492889666e+00, -2.069268336172129e+02, -1.989862847282777e+05, -2.371196604774393e+09, -8.556199064597498e+14, -4.364934867588142e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_17_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.680974499542723e-10, 5.655298866959318e-10, 7.419325562482023e-10, 1.095128220589853e-09, 1.911908839605686e-09, 4.229923619393445e-09, 1.297665691368176e-08, 6.084214016827020e-08, 4.471892660805908e-07, 4.093062495488839e-06, 4.057704698381368e-05, 1.375244906251645e-03, 2.693266482948844e-02, 2.149532125729972e-01, 3.587081023048475e+00, 7.555085992849695e+01, 3.136397144047353e+03, 8.768361237719357e+05, 2.755916922241916e+09, 1.941023521177232e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_17_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.788884681469430e-07, -3.304285985119771e-07, -4.211322504567593e-07, -5.952628631627086e-07, -9.733646862069559e-07, -1.948374050389874e-06, -5.117659470619885e-06, -1.872852582035724e-05, -9.005740725090010e-05, -3.626603139987020e-04, -7.505245123920019e-04, -4.992247676423031e-03, -9.107083728185246e-02, -4.309557910005704e-01, -3.254682687991166e+00, -1.356978824778210e+01, -3.899993489641013e+01, -2.917975288327488e+02, -8.005731432569462e+03, -7.761478932763017e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
