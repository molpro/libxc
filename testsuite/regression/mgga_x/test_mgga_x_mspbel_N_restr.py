
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mspbel_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.608439343743496e+00, -4.517751899165165e+00, -4.390723088338478e+00, -4.214854917096087e+00, -3.975423832336476e+00, -3.657222142762407e+00, -3.248694452542686e+00, -2.749433057985610e+00, -2.179752910813315e+00, -1.567369081078581e+00, -9.863692135219259e-01, -6.152771779173116e-01, -5.593003429336815e-01, -4.780495442974801e-01, -3.392981842033459e-01, -2.104597090200497e-01, -1.140775761002029e-01, -4.149739762272703e-02, -8.765616176487027e-03, -9.701562627890557e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mspbel_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.978138142110301e+00, -5.854304596911177e+00, -5.680667465545103e+00, -5.439886861378612e+00, -5.111245721477852e+00, -4.672612595900305e+00, -4.105052953106764e+00, -3.399742373950291e+00, -2.554746486808013e+00, -1.509798623709827e+00, -1.007236528470479e+00, -8.124810423918597e-01, -7.575195415715871e-01, -6.059822248012838e-01, -3.567285423673346e-01, -1.976396395178980e-01, -1.136000209370408e-01, -5.306749621988961e-02, -1.166419698688964e-02, -1.293508506806629e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mspbel_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.807617216423121e-06, -1.961274444110474e-06, -2.205527834924446e-06, -2.611419678448903e-06, -3.331092890579571e-06, -4.735868880179515e-06, -7.914354928383522e-06, -1.711547117179864e-05, -5.991097895240337e-05, -4.863591832209912e-04, -1.292378244156178e-03, -5.861773307754627e-03, -1.315608489034724e-02, -5.436339329663984e-02, -2.155981733781700e-01, -5.174007405634899e-01, -3.176013616547352e+00, -5.107564863446579e+00, -6.341450337514507e+00, -7.014758291744990e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mspbel_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.928689631659457e-05, 5.457252371701287e-05, 6.322691277985925e-05, 7.823723168084302e-05, 1.065408440696016e-04, 1.668016955125674e-04, 3.198333033452373e-04, 8.207634514257187e-04, 3.155023402583351e-03, 1.646029305236404e-02, 5.574064856393396e-03, 5.676875549670129e-03, 1.879676783083647e-02, 6.716104171635696e-02, 8.260934038325254e-02, 9.316445474914966e-03, 6.434303654764923e-03, 3.710056561308116e-06, 2.429281707332246e-11, 6.137201625085944e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mspbel_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.141699295571352e-02, -1.185969628602946e-02, -1.251818340845821e-02, -1.350841707713844e-02, -1.501280448191437e-02, -1.729469152745322e-02, -2.054985467168239e-02, -2.348406398223266e-02, -1.409964790431877e-02, -1.190184454011954e-01, -3.733726957072915e-01, -8.707620718300442e-01, -1.364950103427474e+00, -1.653198238673217e+00, -4.756771075187864e+00, -2.794677862604997e+01, -4.687090999731462e+00, -2.863851935072134e+02, -1.328757018699603e+04, -1.116445011169233e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mspbel_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.245000224637306e-08, -1.548075715212803e-08, -2.106023778892575e-08, -3.246358205731221e-08, -5.947079072953901e-08, -1.381445039164552e-07, -4.442440057257319e-07, -2.221456390862109e-06, -1.958877056385667e-05, -1.030557476688176e-04, 9.028307029651324e-05, 5.128886096578445e-03, -7.717716915906300e-02, 2.778105151349403e-01, 3.484288191120440e+00, 4.661514987229435e+02, 5.953693826213763e+03, -5.821787228870328e+05, -8.857701415834776e+07, -7.267435320559183e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mspbel_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.539832089134360e-05, 3.984110741127489e-05, 4.720691297690987e-05, 6.019987601744690e-05, 8.524833362247479e-05, 1.400771038112390e-04, 2.838361399813108e-04, 7.691039884137847e-04, 3.034927658430857e-03, 7.587068981733436e-03, 4.102416117223757e-03, 3.219577872741414e-02, 3.817563776007597e-01, -2.353246971590209e-02, -4.441526743578523e-01, -4.420153343165229e+01, -9.380165714143567e+01, -4.240768304758403e+00, -6.372299931748335e-03, -2.539221128402959e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mspbel_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.298896750279344e-13, 9.309386893957064e-13, 1.320364528428259e-12, 2.180450677262982e-12, 4.476419764317302e-12, 1.253743369486326e-11, 5.461534418178439e-11, 4.445851363677111e-10, 8.639967417842522e-09, 2.395467534888016e-07, -7.856036661539968e-07, 4.480264229455655e-05, -1.992217674781217e-02, 3.786976931812166e-02, -4.428397945187522e+00, -9.182394712105212e+03, -2.196814589955153e+06, 1.708741442255407e+09, 3.217525943082149e+13, 2.048803413192736e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mspbel_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.028012388116225e-09, -1.233299540993228e-09, -1.601889108512564e-09, -2.331405359698159e-09, -3.992800408365327e-09, -8.624352789450463e-09, -2.590396945128386e-08, -1.239786463081080e-07, -1.129578902070368e-06, -1.000867389147502e-05, 4.015381732667929e-05, 6.039434845196450e-04, 6.908239977105488e-02, -2.360146991726380e-02, 3.416347115741853e+00, 8.926284301526886e+02, 2.371275652500781e+04, 3.092497203739833e+04, 5.120403243631789e+03, 1.503381955914035e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mspbel_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.472314353634792e-06, 1.661384411739142e-06, 1.976125180548463e-06, 2.534638433843956e-06, 3.620961358815165e-06, 6.031103888341512e-06, 1.248766975097643e-05, 3.512467221654055e-05, 1.498918693967601e-04, 4.282450719562611e-04, -6.392800673243450e-04, -3.726779241983075e-03, -2.321592175118535e-01, -1.037676457268235e-02, -2.229055947940700e+00, -8.378352138242661e+01, -1.990006494875005e+02, -8.301686402910981e+00, -1.198128803310857e-02, -4.698765885478815e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
