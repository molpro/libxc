
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_gvt4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.600446805526500e+00, -4.508530248413002e+00, -4.379793283817802e+00, -4.201595960114456e+00, -3.959093752249752e+00, -3.637105680271998e+00, -3.224638886455414e+00, -2.723571574746945e+00, -2.161634936826130e+00, -1.590016561377064e+00, -9.314342990849471e-01, -5.180237459020579e-01, -5.879072178840127e-01, -4.846245089692073e-01, -3.435902217399336e-01, -2.275694527479924e-01, -1.058552624838466e-01, -8.758170960265071e-03, -9.692401172832972e-05, -1.406720083078369e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_gvt4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.040146313536135e+00, -5.913597942875975e+00, -5.735898317893721e+00, -5.488923162724793e+00, -5.150570916369601e+00, -4.696103960834222e+00, -4.101443684229403e+00, -3.348435395160504e+00, -2.434502523102357e+00, -1.440870652525549e+00, -8.278442951450893e-01, -1.114991091955689e+00, -8.212704957952517e-01, -6.270408151330056e-01, -3.620207942052968e-01, -1.113675696958914e-01, -1.293392118393986e-01, -2.339285629199126e-02, -2.917463852240947e-04, -4.304674242186785e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gvt4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.446244613616029e-06, -1.600784289859501e-06, -1.852820897072132e-06, -2.287275162950616e-06, -3.098499161533147e-06, -4.798269635997165e-06, -9.000202805947678e-06, -2.211530692051536e-05, -7.799441809709190e-05, -4.172131193314179e-04, -3.305777553099565e-03, -1.196965488722363e-02, -7.595139200349014e-03, -2.153329744858464e-02, -1.544977606852860e-01, -1.801791364374547e+00, -1.054226932691390e+01, -6.327768322045007e+00, 1.428930373953371e+00, 4.775643997960499e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gvt4_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.000878498405611e-03, 1.033690326308535e-03, 1.083269852469473e-03, 1.159881778854085e-03, 1.282240821452491e-03, 1.487504774385593e-03, 1.858124475280007e-03, 2.604850683961922e-03, 4.364288934806312e-03, 9.365132266709627e-03, 2.600202856520945e-02, 4.995980802861779e-02, 2.303418722711054e-02, 2.269761227268866e-02, 4.210833243619021e-02, 9.856729601700009e-02, 1.107709439241110e-01, 1.266284875403193e-02, 1.511925617496976e-04, 2.262062188985000e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gvt4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.300753800217575e-02, -1.366187199907212e-02, -1.467175347035445e-02, -1.628230698789321e-02, -1.898047882498061e-02, -2.385330137134646e-02, -3.373148694689106e-02, -5.754480901637212e-02, -1.290379637718281e-01, -3.650979369298082e-01, -1.121976610694265e+00, -1.387486376857779e-01, -6.064355071255678e-01, -1.508874380006463e+00, -6.314908955540429e+00, -1.020816728105866e+01, 3.821094692913388e+02, -4.383635182598680e+02, -1.322343836077950e+03, -1.558385625415855e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gvt4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.975794355336782e-08, 2.335832580569187e-08, 2.970668878861034e-08, 4.194452045018302e-08, 6.875620443020276e-08, 1.392893612496964e-07, 3.796935677745684e-07, 1.550743120540299e-06, 1.053666182287811e-05, 1.182890594825779e-04, 2.699312754424185e-03, 5.364356214252090e-02, 4.830058655309395e-02, 2.569107236867718e-01, 4.645808730379482e+00, -1.527599290314455e-01, -5.742209585456114e+04, -4.442885599013601e+06, -5.096478912896915e+08, -3.784926870171212e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gvt4_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.864095639503433e-06, -2.045520819370229e-06, -2.338474247017149e-06, -2.836389931642742e-06, -3.747900751339464e-06, -5.606320730338877e-06, -1.003334895192332e-05, -2.315904498728083e-05, -7.386154208376561e-05, -2.706046840889852e-04, -1.988448576680148e-03, -9.843397813890124e-02, -7.541640547212476e-02, -9.421569134087535e-02, -2.585629685428859e-01, 4.810020334675399e+00, 3.245392423972326e+02, 1.890036865692498e+03, 2.743513124833676e+03, 3.056403306155902e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gvt4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.199367063762762e-14, -7.822126392535440e-14, -1.091395271132982e-13, -1.756944963312465e-13, -3.461353447946846e-13, -9.034625743131039e-13, -3.448831857043564e-12, -2.101243888519731e-11, -1.604869009619386e-10, 1.434608025019604e-08, 7.018108620456525e-06, 1.582279576269085e-04, -1.683137924765214e-03, -1.592432926010321e-02, 3.584659149343393e-01, 2.127343364480157e+03, 7.720302938408913e+06, 2.331597699673742e+10, 3.760020090157550e+14, 2.273411955440296e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gvt4_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.841771560384441e-11, -9.397851585482177e-11, -1.218718326663413e-10, -1.769387564195865e-10, -3.018411576357700e-10, -6.476825799947436e-10, -1.922279794836273e-09, -8.983909882569510e-09, -7.835305939524962e-08, -1.559879532369303e-06, -8.144703182147972e-05, -2.600224921630823e-03, -7.622949331736685e-03, -4.654084618826611e-02, -1.210896468450311e+00, -1.301894045997283e+02, -3.248915654658221e+04, -4.919283985532654e+06, -8.441173698492941e+08, -7.322921802295819e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gvt4_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gvt4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.784177725147549e-07, 2.010242266561280e-07, 2.385576609550560e-07, 3.048901973944127e-07, 4.330678226712788e-07, 7.143275195868814e-07, 1.452842419191097e-06, 3.939679784871081e-06, 1.556713094938428e-05, 9.472413303121405e-05, 8.542595104067585e-04, 9.056052844455962e-03, 3.076967631958282e-02, 1.075808325324305e-01, 8.278039282640388e-01, 1.138407755770553e+01, 9.027995283587748e+01, 1.411460317128124e+02, 1.733962685547569e+02, 2.173936166336397e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
