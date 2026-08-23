
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_kcis_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.883139050398641e-02, -4.837649744319863e-02, -4.771966427662807e-02, -4.676985038538702e-02, -4.539402440355113e-02, -4.339868405722157e-02, -4.051082094962789e-02, -3.639186391777505e-02, -3.083831038741468e-02, -2.468024727554022e-02, -2.334961979565203e-02, -4.640461113201683e-02, -4.924227324568178e-02, -3.295941322326853e-02, -2.142671694469866e-02, -1.113209158052189e-02, -3.794796855997357e-03, -7.465307183491246e-04, -3.675887426133910e-05, -4.763967348792763e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_kcis_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.021801522438353e-01, -1.015255777242325e-01, -1.005855461066245e-01, -9.923437962695715e-02, -9.728640527520405e-02, -9.445617928631318e-02, -9.027517666033667e-02, -8.393263151396194e-02, -7.423739062008287e-02, -6.153687499435256e-02, -5.689031747006830e-02, -7.750663581745179e-02, -7.376808094543981e-02, -6.107615587586691e-02, -4.669076728699165e-02, -2.940745769267976e-02, -1.099245734732442e-02, -2.730603926052636e-03, -1.408060786548618e-04, -1.841021629777412e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcis_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.077587319187198e-06, 1.136479104493399e-06, 1.226809264056254e-06, 1.369237864384021e-06, 1.602774115623842e-06, 2.007385707183181e-06, 2.764326017540599e-06, 4.338207470921912e-06, 8.136755259042264e-06, 2.019509458907030e-05, 1.073940692028226e-04, 2.518303526990268e-03, 1.011030825141672e-02, 1.497801147415357e-02, 3.327830784220693e-02, 1.219386245545985e-01, 6.001574584703966e-01, 5.003026263759332e+00, 3.159889623379389e+01, 3.222423830916702e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcis_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.212282073809705e-03, -1.193879987402960e-03, -1.167587764549651e-03, -1.130100786370784e-03, -1.076801465368222e-03, -1.001371110858054e-03, -8.957084035889734e-04, -7.514884474761306e-04, -5.670819389633522e-04, -3.667093138650232e-04, -2.392896474372746e-04, -3.792567337109326e-04, -3.116279924917580e-03, -9.069428552140622e-03, -7.607986839807014e-03, -3.996328657563519e-03, -1.338184407363444e-03, -2.179104887217504e-04, -1.169362396199223e-05, -1.639250050361012e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcis_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.119430568224355e-04, -3.314875393090902e-04, -3.619573310576485e-04, -4.112453026608505e-04, -4.954457681061640e-04, -6.513840588322625e-04, -9.760790663898486e-04, -1.767737847166199e-03, -4.060553606675486e-03, -1.151206196658541e-02, -3.711133913886323e-02, -2.731070349314904e-02, -2.931000982200226e-02, -1.150997998974162e-01, -4.662296384505050e-01, -2.938617885098348e+00, -1.791086518274547e+01, -2.098783841401382e+02, -1.355352116333077e+03, -1.335268031121116e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcis_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.068655566951786e-09, 6.860227386522074e-09, 8.182453978145795e-09, 1.054153475593875e-08, 1.517120098590228e-08, 2.560150481675652e-08, 5.430989975896303e-08, 1.597306463378944e-07, 7.370185016519635e-07, 6.071222270454274e-06, 1.163776494958827e-04, 1.656546428868529e-03, 7.676775906198114e-03, 5.826587210554979e-02, 6.157662276553714e-01, 1.931520676428686e+01, 1.451931882860937e+03, 5.128746189367042e+05, 3.988992021430629e+08, 3.055570816661270e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcis_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.083777918948022e-06, -7.518214679726399e-06, -8.184180415644833e-06, -9.232227692889038e-06, -1.094206817765137e-05, -1.386954538192681e-05, -1.920474588389911e-05, -2.970842813374442e-05, -5.239509300724296e-05, -1.073675378593708e-04, -2.674615987251520e-04, -5.907755294574620e-04, -4.757605187253825e-03, -4.338019459660556e-02, -1.646790717508913e-01, -6.518148184081476e-01, -3.006369529518329e+00, -1.748812828687980e+01, -1.086054516865912e+02, -1.131666376155758e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcis_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.166322532869552e-13, -1.409076645516974e-13, -1.848835778343301e-13, -2.730448101120868e-13, -4.775630192630780e-13, -1.063003423342936e-12, -3.330924042090943e-12, -1.689413018785143e-11, -1.676121865024367e-10, -4.296191742052866e-09, -5.646073234604246e-07, -5.468013048904350e-04, -1.110433867543969e-02, -4.454574040008699e-02, -1.095845984422574e+00, -1.790847247955150e+02, -1.604988313970836e+05, -1.724669882366043e+09, -1.585447163495089e+14, -9.400162789706241e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcis_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.195801757431016e-10, -1.321663755215496e-10, -1.525507689573963e-10, -1.872928619950413e-10, -2.509485319067628e-10, -3.801134854139625e-10, -6.825316793634439e-10, -1.547251503435866e-09, -4.820644557003536e-09, -2.384433120639927e-08, -3.541907137248054e-07, -8.718779995627508e-05, -6.006949481289279e-03, -2.722259861867297e-02, -1.382869256950811e-01, -1.538953189046757e+00, -4.691442157935040e+01, -1.406704655084364e+03, -1.748679421087998e+05, -1.366831165592721e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcis_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.507643719897518e-07, 5.775776095695653e-07, 6.182455440861939e-07, 6.812795692211949e-07, 7.819215737231715e-07, 9.491108554322610e-07, 1.241495834828726e-06, 1.786651428694649e-06, 2.887141788975661e-06, 5.430008120666942e-06, 1.560821128467996e-05, 1.778302061044852e-04, 1.006116285130082e-02, 8.272610242354729e-02, 2.348568853762032e-01, 7.809648652625077e-01, 3.500963708325957e+00, 1.967724709848474e+01, 1.312020080542852e+02, 1.453120585148711e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
