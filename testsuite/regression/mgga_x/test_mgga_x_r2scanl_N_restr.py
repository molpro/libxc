
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_r2scanl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.885392040280302e+00, -4.786555800967261e+00, -4.648029163573114e+00, -4.456065948124008e+00, -4.194347352913540e+00, -3.845725350614875e+00, -3.396119216174891e+00, -2.835189616995979e+00, -2.192826487551431e+00, -1.510411724703020e+00, -8.368035536916287e-01, -5.812020651171397e-01, -6.257113524061447e-01, -5.048356523759723e-01, -3.366336997699687e-01, -1.747389749384433e-01, -6.401026512062120e-02, -1.675798659173353e-02, -2.222429398070224e-03, -1.197189015938527e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_r2scanl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.524108037862822e+00, -6.392803161218890e+00, -6.208808976552257e+00, -5.953922179088689e+00, -5.606588309105507e+00, -5.144282513406264e+00, -4.510241856829232e+00, -3.548752050134703e+00, -2.618961674168294e+00, -1.542739185648747e+00, -1.070437028094353e+00, -7.846114142068966e-01, -7.309269403905350e-01, -5.802618138790612e-01, -3.496493559726159e-01, -1.255891444978817e-01, -8.841257638416296e-02, -2.726973037567456e-02, -4.008899959954999e-03, -2.403090666380970e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scanl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.100018212929167e-07, 1.226249320421338e-07, 1.431478365245816e-07, 1.782899529086841e-07, 2.429997539990468e-07, 3.747650055335512e-07, -1.222754589473019e-07, -1.161462408932675e-05, -4.895748077747881e-05, -3.612574795544536e-04, -7.338947366661008e-04, -6.138234206252833e-03, -1.725337251495682e-02, -3.297118561719384e-02, -1.680996803873751e-01, -1.602728196206015e+00, -9.617743173425547e-01, 1.094863542068794e+01, 2.931149772603900e+02, 2.937247379040243e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scanl_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 7.222704891382543e-05, 6.906871034605467e-04, 1.326428427114872e-03, 3.316302994766720e-03, 1.717929010178513e-03, 2.607429105200720e-03, 9.787796239403915e-03, 1.051934017292543e-02, 1.723168482329716e-02, 2.897330543750836e-02, 2.407449850536345e-03, 9.383902403399620e-06, -4.400598682543965e-06, -8.360372628656387e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scanl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.195942728580454e-02, -1.244875609392688e-02, -1.318652053783668e-02, -1.432183152317817e-02, -1.612079505879988e-02, -1.909321999756363e-02, 2.686770737450980e-02, 7.167462309729919e-02, 1.365920065343026e-01, 2.252387088960216e-01, -2.974637481739156e-01, -3.980358990723343e-01, -1.214040320900693e-01, 2.562571140194477e-01, 3.458639416457419e-01, -6.465227707795127e+01, -8.959615757006334e+01, -4.424194395475479e+02, -1.035789328980513e+04, -4.782878679754907e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scanl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.972885012911135e-09, -2.301450425226423e-09, -2.867346894945197e-09, -3.919971372130049e-09, -6.102407343089279e-09, -1.136785498733932e-08, -1.086546916487614e-06, -5.320389314055887e-06, -3.016353854967369e-05, -2.724216493486100e-04, 3.654064852387409e-04, -1.092494163962657e-02, -6.146351393872317e-02, -4.086663686226715e-01, -4.895898997865850e+00, 6.728453160953362e+02, 1.225598025509082e+04, 3.805673153692970e+05, 1.613233231766583e+09, 5.387132052539384e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scanl_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 9.612961841043904e-05, 2.905054875730495e-04, 8.032450148191925e-04, 2.833585590792817e-03, -4.612969214776961e-04, 3.385825865058262e-03, 5.257409054389003e-02, 1.584252476150897e-01, 6.767057577353077e-01, -9.752342708830811e+00, -1.691296385381609e+01, -1.245809340613705e+00, -3.501495109216696e+01, 2.299960944956681e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scanl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.238113796377697e-14, 1.521098355721296e-14, 2.040343830000964e-14, 3.097144927081909e-14, 5.584352788970701e-14, 1.273369741665303e-13, 2.289814250637557e-11, 2.936748358722920e-10, 5.325000135970289e-09, 2.558644424345926e-07, -1.864542201663351e-06, 1.670571341901172e-03, 2.028536590609258e-02, 2.192596539625151e-01, 1.303110575753579e+01, -7.295683913501351e+03, -2.934611232696290e+06, -2.164926010444962e+09, -8.563947606558408e+14, 2.297643306212753e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scanl_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -2.016144833706205e-09, -1.513867319049372e-08, -1.298502820901847e-07, -2.189889324283433e-06, 7.041463384243035e-06, 1.004836705071001e-04, -1.080171260673679e-02, -6.230900527661048e-02, -1.215798276561092e+00, 1.318265030084426e+02, 4.512595508833798e+03, 1.773527662270088e+04, 2.332640380335870e+07, -3.789696338950211e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scanl_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.806773723521853e-07, 7.865670564310127e-07, 3.180440976085398e-06, 1.881936333867841e-05, -1.894361131429905e-05, -1.828064885162511e-04, 5.405862387859910e-03, 1.826383944877097e-02, 1.148408180335859e-01, -2.369617802547504e+00, -7.042681770909377e+00, -9.415972195476527e-01, -6.481117634280736e+00, 2.643744518327113e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
