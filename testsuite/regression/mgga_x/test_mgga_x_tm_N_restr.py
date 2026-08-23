
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_tm_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.654704676903998e+00, -4.562039958551827e+00, -4.432261216847059e+00, -4.252627417834628e+00, -4.008157132100673e+00, -3.683437575895458e+00, -3.266876757094065e+00, -2.758242382817971e+00, -2.177966802409940e+00, -1.568625590992182e+00, -9.989578976764479e-01, -6.714902287138048e-01, -5.583348918683476e-01, -4.753637059626852e-01, -3.427509270329808e-01, -2.093439620522600e-01, -1.087768167968312e-01, -4.828817342721750e-02, -1.774529322771158e-02, -4.666581675938924e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_tm_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.090621629309544e+00, -5.959681808668078e+00, -5.775966157998287e+00, -5.520996576045219e+00, -5.172630475093668e+00, -4.707241344294518e+00, -4.105435178469034e+00, -3.363936948953233e+00, -2.517560943088088e+00, -1.675564902819098e+00, -1.088405271506198e+00, -7.644821857732719e-01, -7.318261562895462e-01, -5.715014316026102e-01, -3.755425806449197e-01, -2.060170396097512e-01, -9.246262865107910e-02, -3.246642757920967e-02, -9.883722356458527e-03, -2.420244541369995e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tm_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.644766262176335e-06, -1.907728215617535e-06, -2.333672312211193e-06, -3.058246187524108e-06, -4.377068417265718e-06, -7.009214059938480e-06, -1.295235337982698e-05, -2.871887579065985e-05, -7.990230543701696e-05, -2.848256451800255e-04, -7.272052229955501e-04, -9.787493841633278e-04, -1.093971714342714e-02, -5.354592295723880e-02, -1.396528406519956e-01, -6.284066152594781e-01, -5.543482744278022e+00, -1.105873167457938e+02, -5.835950158752773e+03, -1.268539921080029e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tm_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.187030505191435e-04, 1.072633150033167e-03, 1.292257850727728e-03, 1.604679057289157e-03, 2.047357606791113e-03, 2.671274384020943e-03, 3.543725822293962e-03, 4.745640984751234e-03, 6.320315722769588e-03, 7.642802120628612e-03, 9.271873425827016e-04, -1.033598178070998e-02, 6.701059164274671e-03, 4.781485017697207e-02, 4.141729977853107e-02, 3.019722734193459e-02, 2.250817907663633e-02, 1.496023583986324e-02, 7.362225230469160e-03, 2.256545382385064e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tm_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.258660787808823e-03, -5.578611762565988e-03, -6.071086229577680e-03, -6.850746072654395e-03, -8.133541305054268e-03, -1.035416787121645e-02, -1.444467461296157e-02, -2.248209540354341e-02, -3.917009059943565e-02, -8.205667885698288e-02, -1.915617743164467e-01, -5.239807049163862e-01, -6.937762992379288e-01, -1.170601312582754e+00, -1.901463337234391e+00, -6.390562783737977e+00, -7.785723461917226e+01, -1.456076210412929e+03, -5.932809804856576e+04, -1.063274331934181e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tm_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.245427753770083e-07, -2.476231464333422e-07, -2.849709173169020e-07, -3.485912548586903e-07, -4.652594841680583e-07, -7.031355455581156e-07, -1.268367663349275e-06, -2.945035697195737e-06, -9.686196475600500e-06, -3.912154100962326e-05, 3.058762671975436e-04, -5.854944524075666e-03, 9.584742374673728e-03, 6.657588236686558e-02, -1.102044643458130e+00, 9.912821325942920e+00, 9.337673050708747e+03, 7.678038876941282e+06, 4.197107045185677e+10, 5.981749639643706e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tm_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.624518171046288e-04, 3.777420442782375e-04, 4.008765757798826e-04, 4.366463995872198e-04, 4.936730610079085e-04, 5.885662116339357e-04, 7.558899081544617e-04, 1.072130894471340e-03, 1.686422252188631e-03, 2.213376117760054e-03, -4.687480320377392e-03, 1.615996913354745e-02, 2.974775601685927e-02, 5.816307568827071e-02, 7.461891259352895e-01, -9.279653578656146e-01, -7.035041999948211e+01, -1.994462750936235e+03, -1.022532308920970e+05, -2.027584741647891e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tm_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.455918733818063e-12, 8.801338314561505e-12, 1.117234222976586e-11, 1.574142212784873e-11, 2.575802061557517e-11, 5.220891801518210e-11, 1.435950595527801e-10, 6.083011373820937e-10, 4.643596310297730e-09, 5.993703313719537e-08, -5.927330350616624e-06, -3.758293336501508e-05, -1.415230067398166e-02, -5.294850937231366e-02, 3.737577043020291e+00, -8.819216431614112e+01, -1.614482192671390e+06, -4.512001239794012e+10, -3.031243146572789e+16, -3.370998631518054e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tm_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.118145055070421e-08, -1.240323857310745e-08, -1.439645546875166e-08, -1.783109299308058e-08, -2.423048194960923e-08, -3.755215289296189e-08, -6.994383531974934e-08, -1.669863306083366e-07, -5.315052909791284e-07, -1.188828040674143e-06, 7.931999867056648e-05, 7.344570486665262e-04, 2.548173621077928e-02, 2.397517210068443e-01, -5.294700257819819e-02, 5.359646540725371e+01, 1.696079835844091e+04, 1.475808646029787e+07, 9.287522921513766e+10, 1.472593415489061e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tm_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.654748063367586e-05, 1.724392576333033e-05, 1.829439221710882e-05, 1.990943115082255e-05, 2.245690190986149e-05, 2.660762990746404e-05, 3.361029276878760e-05, 4.552559536919611e-05, 6.145223882192470e-05, 8.084473022813807e-06, -7.949291502450194e-04, -1.720609885769795e-03, -4.132653006505863e-02, -4.547827129293744e-01, -5.559757689417402e-01, -6.787830910105121e+00, -1.445108535314358e+02, -4.106422138596336e+03, -2.379002399968857e+05, -5.269159678295702e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
