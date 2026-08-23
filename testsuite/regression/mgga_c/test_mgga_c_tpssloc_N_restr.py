
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_tpssloc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.716834237957040e-02, -4.693998795924576e-02, -4.660616558636371e-02, -4.611401905790545e-02, -4.537779082177625e-02, -4.424470921342299e-02, -4.238610810566194e-02, -3.884253854504718e-02, -3.028899368452284e-02, -1.314776408545779e-02, -4.945428890175936e-03, -4.576915403047825e-02, -5.511290690741942e-02, -3.670109637058137e-02, -1.427581544003107e-02, -1.427927127767833e-03, -2.190221130106652e-05, -3.183719047128313e-08, -1.678588502263853e-12, -7.370789024143467e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_tpssloc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.287283025815976e-01, -1.274302435563591e-01, -1.255660929508899e-01, -1.228949567413943e-01, -1.190908894948843e-01, -1.137731170485817e-01, -1.067999655666657e-01, -9.977252317812313e-02, -9.796443529795774e-02, -7.575879696144489e-02, -3.936686739379874e-02, -1.024299628912514e-01, -8.381492228791704e-02, -8.626084549474496e-02, -7.061519635178033e-02, -1.192935721848086e-02, -2.174196388538525e-04, -3.334757555097720e-07, -1.800159067334862e-11, -7.993556485439023e-18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpssloc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.064992404384630e-06, 2.160952743818421e-06, 2.305360593676084e-06, 2.526460034278942e-06, 2.872484836162461e-06, 3.427947367385169e-06, 4.343127075784608e-06, 5.927588506284032e-06, 9.688335123746820e-06, 2.234401778883256e-05, 8.475422388267249e-05, 4.252783326402331e-03, 9.313775821287229e-03, 1.888928113887683e-02, 5.070207823669084e-02, 5.529588053536075e-02, 1.307431182266573e-02, 6.665779337425506e-04, 4.321479881755319e-06, 1.481628520338233e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpssloc_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.726225857606513e-03, -2.673713430326130e-03, -2.597516176947888e-03, -2.486268378191775e-03, -2.322104346639045e-03, -2.075495483008868e-03, -1.695099987575688e-03, -1.097196411634435e-03, -2.780492590866581e-04, 1.241497359824926e-04, 4.480072292191441e-05, -1.013913707242234e-05, -7.844562737375921e-04, -2.464241325437040e-03, 2.188925244592094e-03, 5.529502981270371e-04, 1.126585625885028e-05, 1.962838883177338e-08, 1.166536613438144e-12, 5.454322899874129e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpssloc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.201647680269430e-04, -5.513625251202999e-04, -5.994492758604183e-04, -6.756522821990753e-04, -8.007181437780237e-04, -1.013077941583154e-03, -1.368312474342921e-03, -1.806291246517997e-03, -3.001368301628316e-03, -3.557864431112898e-02, -1.357136547931156e-01, 5.769389012654679e-02, 4.741959851276893e-02, 1.129722180053040e-01, -1.874379159101291e+00, -6.759471492332547e+00, -1.949380855665082e+00, -9.831829314555290e-02, -6.161290087606873e-04, -2.050828522174816e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpssloc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.435047987522668e-09, 8.341344195101554e-09, 9.849849326822407e-09, 1.253198127786561e-08, 1.778730856382449e-08, 2.967667123938673e-08, 6.285375665826242e-08, 1.849506595742428e-07, 8.460362327491022e-07, 1.356552083114239e-05, 3.366438916728204e-04, -5.632068380891401e-03, -2.576547079396813e-02, -7.014930180027881e-03, 1.737387506384596e+00, 3.589641592038865e+01, 1.317053028688955e+02, 2.196751008018089e+02, 1.649572407599730e+02, 4.234101833577274e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpssloc_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.000708616092623e-06, -5.188067048229607e-06, -5.484029121030115e-06, -5.980447317640795e-06, -6.906619114384735e-06, -8.980892160397415e-06, -1.504761623347280e-05, -3.749008534316432e-05, -9.387278500925290e-05, 2.043686571631632e-05, 1.503285456032563e-04, -2.958291057927260e-04, -1.513551489236624e-03, -8.419036988891743e-02, -1.975212455146679e-02, 2.974742565617156e-01, 9.502902641030619e-02, 5.422562451170586e-03, 3.741349064339974e-05, 1.311088427452615e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpssloc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.036160426641019e-15, 2.354521801095691e-15, 9.446226837945957e-15, 2.597532570466813e-14, 6.963688183797500e-14, 1.987093586345971e-13, 5.303633550971781e-13, -2.012089380253175e-12, -1.546975056352583e-10, -8.024245011121007e-09, -1.100454523297708e-06, -4.195876923350801e-04, -2.777672104562572e-05, -4.828415713772603e-02, -2.918552046063398e+00, -2.386625913497995e+02, -1.059447628753827e+04, -5.788710195464109e+05, -5.198374920712458e+07, -1.028796346220243e+10]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpssloc_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.322028498594892e-10, -7.138207972827346e-10, -8.493046438099458e-10, -1.088209110045075e-09, -1.546025749220662e-09, -2.524106071614931e-09, -4.876855817685738e-09, -1.058522708375457e-08, -1.451839777638197e-08, 8.433097065646342e-09, -7.882377300171354e-08, 1.576528963672200e-05, -2.893285286156404e-03, 1.168491776916853e-03, 9.184669949734521e-02, -6.315159782935373e-01, -3.492461969228515e+00, -6.975167513435085e+00, -5.866119460572270e+00, -1.591013986520980e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpssloc_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpssloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.788728087990388e-06, 1.892359626140951e-06, 2.050957529138021e-06, 2.299638497713772e-06, 2.701745400918727e-06, 3.373276297404210e-06, 4.500548062393534e-06, 6.066411005440073e-06, 5.473230476875232e-06, -1.446118553114471e-06, -4.193018343144081e-06, 9.607423476395685e-06, 4.149293687769909e-03, 5.234560400233403e-02, -5.834061084716987e-02, -1.572623374252310e-01, -4.418884559901932e-02, -2.658653709518506e-03, -1.963274344752214e-05, -7.252513625462091e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
