
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ms2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.682403518321441e+00, -4.589628333056563e+00, -4.459655165379978e+00, -4.279668064199420e+00, -4.034537933652680e+00, -3.708563378921525e+00, -3.289618665666284e+00, -2.776660995231155e+00, -2.189326693145183e+00, -1.555375670384836e+00, -9.857734069863295e-01, -6.387233201974267e-01, -5.589870973329023e-01, -4.804757652415428e-01, -3.377532874195516e-01, -2.035590373889460e-01, -1.023786220421079e-01, -3.498122241616475e-02, -7.311774299828014e-03, -8.088275562690910e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ms2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.117274104358685e+00, -5.991403858467097e+00, -5.814932282609413e+00, -5.570265295367680e+00, -5.236409466648007e+00, -4.790992569942013e+00, -4.214961308739148e+00, -3.499406249821182e+00, -2.640664572636911e+00, -1.561511899454340e+00, -1.070346446313905e+00, -8.130718371464770e-01, -7.579687057416535e-01, -6.171803193418901e-01, -3.625253058868104e-01, -2.132664018218446e-01, -1.189542461982030e-01, -4.572833885611678e-02, -9.739867980397622e-03, -1.078423704256491e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.377335173451457e-06, -1.494868253031417e-06, -1.681948519704195e-06, -1.993552393935729e-06, -2.548418722406615e-06, -3.640864820390329e-06, -6.160001421440004e-06, -1.378367362916159e-05, -5.264534313587997e-05, -4.812592641311148e-04, -7.659036750403037e-04, -4.534814628543343e-03, -1.304342601261547e-02, -6.104757537073821e-02, -2.271052002745454e-01, -3.568775852898687e-01, -1.280498923968308e+00, -2.059330092808533e+00, -2.495171936715614e+00, -2.756569369243726e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.942881621640158e-05, 6.574485397073499e-05, 7.607165444090137e-05, 9.394384248151984e-05, 1.275300821343159e-04, 1.986487809542196e-04, 3.775903527604504e-04, 9.536381456817127e-04, 3.553604077398853e-03, 1.790131465358065e-02, 1.368885856139897e-03, 1.564165253164248e-03, 1.902121534252000e-02, 8.233076616728056e-02, 9.506136995685049e-02, 5.801729739788232e-03, 1.031927681131879e-03, 5.173498241603727e-07, 3.360707929324900e-12, 8.495384649467819e-20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.119512671885553e-02, -1.160432228007224e-02, -1.220802579176501e-02, -1.310374541030499e-02, -1.443236248899283e-02, -1.635166374252476e-02, -1.874632529723946e-02, -1.923263306126751e-02, -1.219797624323022e-03, -5.876182622985065e-02, -2.177518150392200e-01, -6.175364441961266e-01, -1.528087905205955e+00, -1.745073565936811e+00, -4.477841877865145e+00, -1.892592182970873e+01, 1.206964661227061e+00, -3.646343453127444e+02, -1.123896307242124e+04, -9.309538490432288e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.081983489034248e-08, -2.532456891711553e-08, -3.348787523186232e-08, -4.983103721211379e-08, -8.753596662788286e-08, -1.939057415270409e-07, -5.924326094206381e-07, -2.809335408425057e-06, -2.354687064188504e-05, -1.683232391205229e-04, -1.292082916216603e-04, 5.964537798414802e-03, -1.064783341733170e-01, 2.854526857851705e-01, 2.631667880871351e+00, 3.139122980821242e+02, -1.495938968192344e+03, -2.440233223873700e+05, -3.488333908928941e+07, -2.855894873826255e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.270179996990498e-05, 4.802129028891254e-05, 5.682873955448646e-05, 7.233308107218445e-05, 1.021291326860533e-04, 1.670243165504026e-04, 3.357818481718364e-04, 8.975656028681762e-04, 3.464559073191483e-03, 1.017976404013127e-02, 1.389142117970125e-03, 9.199808284259535e-03, 4.779917238506629e-01, 7.929772389841621e-03, -7.367313605066951e-02, -3.126013720886371e+01, -1.504213995842938e+01, -5.847343379617734e-01, -8.808225250590822e-04, -3.514832534520278e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.784040409775227e-13, 1.119419073793081e-12, 1.585690509236349e-12, 2.613592699041404e-12, 5.349624283043530e-12, 1.491099198635747e-11, 6.442989376387780e-11, 5.170306968573310e-10, 9.799457163251908e-09, 3.061984135538802e-07, 1.123793245186313e-06, 1.674710327279485e-04, -2.427731607709211e-02, 8.879409146430359e-02, -3.176474340589845e+00, -6.433660998251768e+03, -1.210971875591510e+05, 7.310725059375008e+08, 1.266879562919988e+13, 8.051190901818685e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.239758484820929e-09, -1.486057386360807e-09, -1.927713289256134e-09, -2.800129870033939e-09, -4.780893078149802e-09, -1.027554226826215e-08, -3.060463137711300e-08, -1.442764279555863e-07, -1.278308152490838e-06, -1.266700792651329e-05, 1.078056602268846e-05, 1.490807761135465e-04, 8.527480421022983e-02, -8.379381144990058e-02, 3.263081202012461e+00, 6.336466749251776e+02, 3.869937679093195e+03, 4.273720781627346e+03, 7.078245721774194e+02, 2.081007755768594e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.775277116080328e-06, 2.001510432937356e-06, 2.377581085794008e-06, 3.043482864744350e-06, 4.334314269382653e-06, 7.182609538854778e-06, 1.474275524817482e-05, 4.081116081132381e-05, 1.688676062015879e-04, 5.312046891686819e-04, -1.798476099044363e-04, -1.036686030436400e-03, -2.879156200269359e-01, 5.209099612777349e-02, -2.396441943720458e+00, -5.953909389669588e+01, -3.267758660773551e+01, -1.148460277736078e+00, -1.656306470577846e-03, -6.504116642344736e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
