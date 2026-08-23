
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_br89_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.417190408801351e+00, -3.405278932063166e+00, -3.383404613622814e+00, -3.343522176101279e+00, -3.272223602217877e+00, -3.148946017688834e+00, -2.946076204050204e+00, -2.637120792192518e+00, -2.221016524553664e+00, -1.737213660014544e+00, -1.223699114988372e+00, -7.121544806433443e-01, -5.259815441036239e-01, -4.675295434251506e-01, -3.722419193730768e-01, -2.591633963770047e-01, -1.695843361788980e-01, -1.104656998927716e-01, -7.350334657389672e-02, -4.991181884872214e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_br89_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.781042598828686e+00, -4.844423208741692e+00, -4.909808611966223e+00, -4.954293134709914e+00, -4.925782231269782e+00, -4.724266053263362e+00, -4.221813609482663e+00, -3.433267188244290e+00, -2.588814433648190e+00, -1.826876023373624e+00, -1.221867971811982e+00, -9.051939748875709e-01, -7.998627419199489e-01, -6.370073034580833e-01, -4.102689225473264e-01, -2.380157069624061e-01, -1.250504774121504e-01, -6.544669505932232e-02, -3.640531864115502e-02, -2.159439461264033e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.181603024953004e-07, -2.553622440749566e-07, -5.618837664289310e-07, -1.265752262136760e-06, -2.927701222350648e-06, -6.878889803212681e-06, -1.569602654019612e-05, -3.303578436838040e-05, -7.007278749523572e-05, -1.897046117098374e-04, -8.114756037737523e-04, -6.560037343314994e-03, -8.536456946537724e-03, -3.096096073502760e-02, -8.896064634039881e-02, -4.424175346953852e-01, -4.561868135555804e+00, -1.132159775720700e+02, -9.759632775448950e+03, -5.323462940047555e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.290233982537324e-05, -1.075405552766818e-04, -2.167021535525189e-04, -4.302456106254663e-04, -8.302427673021796e-04, -1.504683168222258e-03, -2.368355920005161e-03, -2.934939353974274e-03, -2.936340499243670e-03, -2.795642579621824e-03, -3.259239295119034e-03, -1.015711601302944e-02, -8.774929633525668e-03, -1.653248777390593e-02, -1.490055749971723e-02, -1.287575538989702e-02, -1.119994935988389e-02, -9.109675410262009e-03, -6.968770578298374e-03, -5.138202962560634e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.692874874411944e-04, 3.441297768853817e-04, 6.934468913680605e-04, 1.376785954001492e-03, 2.656776855366975e-03, 4.814986138311226e-03, 7.578738944016514e-03, 9.391805932717677e-03, 9.396289597579745e-03, 8.946056254789838e-03, 1.042956574438091e-02, 3.250277124169421e-02, 2.807977482728214e-02, 5.290396087649897e-02, 4.768178399909514e-02, 4.120241724767047e-02, 3.583983795162844e-02, 2.915096131283843e-02, 2.230006585055480e-02, 1.644224948019403e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.253241438854283e-02, -1.470289734033661e-02, -1.766619297404967e-02, -2.143113485090907e-02, -2.537398495814265e-02, -2.782328196085943e-02, -3.112628290581611e-02, -4.907056630166971e-02, -7.732513439331855e-02, -1.264023200664240e-01, -2.584147093715277e-01, -6.279811906326265e-01, -1.008872944692681e+00, -1.362836325194932e+00, -2.721096809832840e+00, -6.200029908137921e+00, -1.449663609620173e+01, 1.616644382599342e+02, 2.614471242677084e+04, 1.507682261402555e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.217822688234795e-09, -2.670030624890284e-09, -5.895884774065333e-09, -1.270815191864402e-08, -2.308122645700094e-08, -4.247549492480806e-09, 2.628776216230269e-07, 1.188911479854128e-06, 2.809175363816160e-06, 1.013528024111544e-05, 1.392184028932739e-04, 1.189291886385737e-02, -5.618257371228259e-03, 1.936507038849898e-01, 5.739106634047149e-01, 6.273780146226500e+00, 2.904970750055604e+02, 1.968316445874131e+05, 3.412045013684991e+09, 2.072791583069420e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.406403023422320e-07, -1.762834074726431e-06, -3.678579928042468e-06, -7.484046316399539e-06, -1.386466868097335e-05, -1.812633028096354e-05, 4.252444728178077e-07, 2.303488423476668e-05, -5.746586688026331e-05, -3.248997359946217e-04, -1.469527295633826e-03, 2.014093987283729e-03, -2.711635020776150e-02, 2.600291306161730e-02, -1.262738425989791e-01, -9.234569087849328e-01, -1.069146416269646e+01, -2.672023172001670e+02, -2.196274448102742e+04, -1.130800026415016e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.690048967495143e-06, 5.641069039124577e-06, 1.177145576973590e-05, 2.394894821247853e-05, 4.436693977911474e-05, 5.800425689908333e-05, -1.360782313016985e-06, -7.371162955125337e-05, 1.838907740168426e-04, 1.039679155182790e-03, 4.702487346028243e-03, -6.445100759307935e-03, 8.677232066483680e-02, -8.320932179717536e-02, 4.040762963167332e-01, 2.955062108111785e+00, 3.421268532062868e+01, 8.550474150405345e+02, 7.028078233928776e+04, 3.618560084528052e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.102577110062443e-15, -3.940044739100946e-15, -1.515669721637440e-14, -6.407187787088543e-14, -2.990792038908916e-13, -1.427331332337395e-12, -4.481932394966900e-12, 2.016374646338467e-11, 5.200574975779460e-10, 1.270391763382074e-08, 1.058075250551035e-06, 3.298686457076719e-04, -2.884330705394508e-03, 8.594922846230970e-04, 1.236911275699217e+00, 1.826623732413489e+02, 2.664652329458187e+05, 6.215974722064149e+09, 6.677925939913523e+15, 1.931627015860875e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.936421770122096e-13, -1.659268779504896e-12, -5.845495320867639e-12, -2.177886229643643e-11, -8.481341742978138e-11, -3.122133792928746e-10, -6.762737749900706e-10, 1.791371815454447e-09, 2.179256665331411e-08, 1.872153383357947e-07, 4.249690832049134e-06, 5.107461936825819e-04, -2.964906768483098e-03, 4.589504120659245e-04, 2.071777616709495e-01, 5.316055202045796e+00, 6.542050376033552e+02, 5.001547775388139e+05, 4.768307874369191e+09, 1.864405137639568e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.579654966439071e-12, 5.309660094415666e-12, 1.870558502677644e-11, 6.969235934859657e-11, 2.714029357753004e-10, 9.990828137371986e-10, 2.164076079968226e-09, -5.732389809454232e-09, -6.973621329060516e-08, -5.990890826745432e-07, -1.359901066255723e-05, -1.634387819784262e-03, 9.487701659145914e-03, -1.468641318610958e-03, -6.629688373470385e-01, -1.701137664654654e+01, -2.093456120330737e+03, -1.600495288124205e+06, -1.525858519798141e+10, -5.966096440446619e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.210118428012286e-10, -6.987669087402025e-10, -2.254436771974993e-09, -7.402917764997692e-09, -2.405154113872313e-08, -6.829331914815316e-08, -1.020421948472291e-07, 1.591476557708066e-07, 9.131989511755052e-07, 2.758958607766480e-06, 1.706860845539772e-05, 7.908046968259596e-04, -3.047733787722699e-03, 2.450696585692440e-04, 3.470145820016145e-02, 1.547140903171015e-01, 1.606154118097016e+00, 4.024385758953523e+01, 3.404763722951032e+03, 1.799522624561996e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.072378969639317e-10, 2.236054107968648e-09, 7.214197670319977e-09, 2.368933684799261e-08, 7.696493164391401e-08, 2.185386212740901e-07, 3.265350235111331e-07, -5.092724984665812e-07, -2.922236643761617e-06, -8.828667544852736e-06, -5.461954705727271e-05, -2.530575029843071e-03, 9.752748120712638e-03, -7.842229074215808e-04, -1.110446662405166e-01, -4.950850890147250e-01, -5.139693177910451e+00, -1.287803442865128e+02, -1.089524391344330e+04, -5.758472398598389e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.263161270284582e-09, -7.155373145499675e-09, -2.308543254502393e-08, -7.580587791357637e-08, -2.462877812605248e-07, -6.993235880770884e-07, -1.044912075235626e-06, 1.629671995093060e-06, 9.351157260037175e-06, 2.825173614352876e-05, 1.747825505832727e-04, 8.097840095497827e-03, -3.120879398628044e-02, 2.509513303749059e-03, 3.553429319696533e-01, 1.584272284847120e+00, 1.644701816931344e+01, 4.120971017168408e+02, 3.486478052301857e+04, 1.842711167551484e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
