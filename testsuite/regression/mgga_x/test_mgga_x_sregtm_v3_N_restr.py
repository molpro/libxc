
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_sregtm_v3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.654431278898217e+00, -4.561768657165839e+00, -4.431993026230400e+00, -4.252363968103305e+00, -4.007901262575245e+00, -3.683194823341247e+00, -3.266659428508450e+00, -2.758081168844918e+00, -2.177939473794972e+00, -1.568807660276289e+00, -9.969722572998402e-01, -6.672421412105429e-01, -5.606532172342187e-01, -4.782481140068501e-01, -3.429638263863978e-01, -2.093265477484467e-01, -1.087743231501635e-01, -4.828815837075429e-02, -1.774529409801594e-02, -4.666581678570135e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_sregtm_v3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.058387940903789e+00, -5.929272356473327e+00, -5.748066281610749e+00, -5.496478599095243e+00, -5.152531370378949e+00, -4.692650502719830e+00, -4.097220371349976e+00, -3.362238262327964e+00, -2.521005491387406e+00, -1.679628686889049e+00, -1.080978648031522e+00, -7.606208789376315e-01, -7.469520039899381e-01, -5.864387928401027e-01, -3.780443539296774e-01, -2.057074769431796e-01, -9.237091788261327e-02, -3.246281271869501e-02, -9.883713556533507e-03, -2.420244637185684e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.548032321621027e-06, -2.814290911984777e-06, -3.242680756543364e-06, -3.965443083663845e-06, -5.268794949982457e-06, -7.846092079879946e-06, -1.362293254480928e-05, -2.890279538170230e-05, -7.870454205928300e-05, -2.816440556196167e-04, -7.835290119884828e-04, -8.783582769075017e-04, -1.371858802579105e-02, -4.904063643438453e-02, -1.362240090826313e-01, -6.330861616012499e-01, -5.559188816625044e+00, -1.106088137919314e+02, -5.835958215301923e+03, -1.268539871009601e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v3_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.195618821779523e-03, 2.277187710961368e-03, 2.397046908719648e-03, 2.574554416132589e-03, 2.839997577054137e-03, 3.241264079442869e-03, 3.853653984179701e-03, 4.789348814318329e-03, 6.166402308776403e-03, 7.535823737284918e-03, 1.441754991245902e-03, -1.028791565528278e-02, 1.447282585583483e-02, 4.720992272537061e-02, 4.053559425637952e-02, 3.059822535178549e-02, 2.261863368009976e-02, 1.496541934218442e-02, 7.362244102622121e-03, 2.256545234017912e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.070881731553655e-02, -1.115020551977204e-02, -1.181788218569903e-02, -1.285012067028010e-02, -1.449587517924096e-02, -1.723349623599865e-02, -2.204508050059497e-02, -3.103995619219120e-02, -4.880247506674782e-02, -9.093321449911820e-02, -1.940657788760880e-01, -5.381974867147492e-01, -7.964847346963063e-01, -1.340737106712213e+00, -2.154900442753908e+00, -6.174018021239149e+00, -7.622035964586888e+01, -1.452103924738865e+03, -5.932034023391790e+04, -1.063272574242691e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.106941989745670e-08, -6.964485562669910e-08, -8.401358735795381e-08, -1.097145483975846e-07, -1.601369690067230e-07, -2.728092008732823e-07, -5.749104748169635e-07, -1.617528875189776e-06, -6.599409925847425e-06, -3.305016684603058e-05, 2.489021460948090e-04, -6.413104663006582e-03, 2.413496075339118e-03, 7.170582569242662e-02, -8.258602817692665e-01, 5.906745210342228e+00, 9.057377567839800e+03, 7.655175101315972e+06, 4.196547461777997e+10, 5.981739496400476e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v3_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.250690664900055e-04, 1.347272791571797e-04, 1.497321771657085e-04, 1.737921433688098e-04, 2.140734069410136e-04, 2.854904731045696e-04, 4.215938754629621e-04, 7.025242154784296e-04, 1.304948178257810e-03, 2.044716289063271e-03, -3.887830300027942e-03, 1.818558180312328e-02, 7.345561761334844e-02, 1.359082402826785e-01, 7.138515948888222e-01, -5.591171977610908e-01, -6.840108970862823e+01, -1.989046922919345e+03, -1.022409202389615e+05, -2.027581629258870e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.566433399181202e-12, 3.132137087293585e-12, 4.165301152365574e-12, 6.257759857817399e-12, 1.116833413944172e-11, 2.537111493554999e-11, 8.051352057666963e-11, 4.029798955401018e-10, 3.659068755077570e-09, 5.662012616579957e-08, -5.444100194445332e-06, -1.632448600772214e-04, -1.514908298839960e-02, 2.372154053124770e-02, 3.720696202379818e+00, -2.124781160376487e+01, -1.566559567008756e+06, -4.498860821734443e+10, -3.030840217759347e+16, -3.370992790771103e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v3_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.884596265376342e-09, -4.452449952918640e-09, -5.409557391496758e-09, -7.135146566083421e-09, -1.055468844013379e-08, -1.827902199109805e-08, -3.911068407298179e-08, -1.096816677173510e-07, -4.132054999412215e-07, -1.150815491259984e-06, 7.687691938792259e-05, 9.006859949371318e-04, 3.299496059687815e-02, 9.969937736309409e-02, -2.555336295699401e-01, 4.816407142989070e+01, 1.664839220993715e+04, 1.472795397533851e+07, 9.286641760925740e+10, 1.472591602906452e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v3_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.684374895825243e-06, 6.119929597088109e-06, 6.795064953248222e-06, 7.873237407995199e-06, 9.664586319725107e-06, 1.279258986405801e-05, 1.856155915128650e-05, 2.954768436683497e-05, 4.729330683865900e-05, 1.018577205389491e-05, -7.945880951682829e-04, -2.079809588134111e-03, -6.929651621995765e-02, -2.793430011312576e-01, -3.997885991913028e-01, -6.355024437003011e+00, -1.424901434690746e+02, -4.099531919630768e+03, -2.378809824534275e+05, -5.269154058828771e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
