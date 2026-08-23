
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_task_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.881645797154444e+00, -4.782565528310492e+00, -4.643656388499826e+00, -4.451070496685456e+00, -4.188281665170742e+00, -3.837672985925220e+00, -3.384301196656184e+00, -2.822333942373355e+00, -2.165083468651875e+00, -1.470688367753062e+00, -6.265528782423179e-01, -4.450240844668587e-01, -5.756754863858398e-01, -4.880192371463047e-01, -3.254047114439010e-01, -1.626048735677258e-01, -5.558491463957835e-02, -1.912563806114417e-02, -2.794777903577691e-03, -1.281416899713063e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_task_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.043221780178784e+00, -5.903353564591945e+00, -5.706959924322849e+00, -5.434118704500280e+00, -5.060921227178825e+00, -4.562269658416573e+00, -3.921323922102417e+00, -3.162742515449614e+00, -2.466108852315745e+00, -1.733372657611504e+00, -9.994124169397574e-01, -8.853427012544202e-01, -8.972668576662429e-01, -6.687039503253472e-01, -4.038059079607105e-01, -6.607227480892708e-02, 5.672780073363022e-02, -2.374955355844525e-02, -5.009802368462549e-03, -2.469592722149443e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_task_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.368934640951052e-05, -1.484049764189889e-05, -1.666165676597475e-05, -1.966212588138451e-05, -2.489376442676130e-05, -3.474056037784787e-05, -5.507573071821929e-05, -9.967422739767877e-05, -1.680765300827445e-04, -3.968116587722194e-04, -2.502805166771326e-03, -1.612916695041384e-03, -2.030668417439838e-02, -3.586968817142690e-02, -2.078380110649664e-01, -3.077425063515970e+00, -2.566253232832398e+01, -1.317254677302556e+01, 3.491935004665597e+02, 1.609097775528046e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_task_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.977564828552928e-02, 2.017051832521177e-02, 2.074655690370046e-02, 2.158947706722846e-02, 2.282238992986880e-02, 2.459771983872863e-02, 2.695612974008025e-02, 2.885107312039597e-02, 2.333374822443702e-02, 1.986316380325742e-02, 3.469765152632778e-02, 2.718818427492540e-02, 7.342157622043025e-02, 6.695703980037698e-02, 1.182033011644616e-01, 2.893537970601918e-01, 1.909375788057043e-01, 3.569859216911167e-03, 8.577406075814313e-07, 6.900781197218296e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_task_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.765112102493727e-02, -2.978381643595131e-02, -3.319145795700773e-02, -3.890065173896973e-02, -4.914858227728970e-02, -6.945068208928540e-02, -1.153556210384378e-01, -2.330744605340931e-01, -4.577334372021047e-01, -1.074477156055663e-01, -1.071987942248122e+00, -1.123516872183285e+00, -6.010506939415361e-01, -1.439196042608874e+00, -5.171146116507227e+00, -5.002500916139871e+01, -1.275309765376771e+03, -1.604897466714587e+03, -1.255192527600347e+04, -5.776398524898242e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_task_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.431346810281689e-07, 4.064224063898878e-07, 5.183995541692792e-07, 7.353709070024096e-07, 1.214296714232274e-06, 2.486551582454721e-06, 6.850461423045134e-06, 2.729049170921703e-05, 1.308202859913199e-04, -1.871563997944465e-04, 2.426087763942568e-03, -1.857928183938900e-02, 7.895507902689847e-02, 3.067409602485278e-01, 8.258076411852224e-01, 2.335303085596352e+02, 2.567316815502848e+05, 1.126155916887302e+07, 1.869107969108733e+09, 7.705121679761939e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_task_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.802082318007815e-04, -4.267840212426588e-04, -5.037707802810584e-04, -6.389121452886472e-04, -8.972125140715314e-04, -1.452769620471258e-03, -2.846444584669976e-03, -6.910106593889578e-03, -1.608096959647806e-02, 1.242567888544719e-02, -1.454089211669389e-03, 7.653928540833178e-02, -1.349579647569495e-01, -2.513359818666439e-01, 1.418205811277115e+00, 3.085875650147197e+00, -1.921256851070643e+03, -3.172550835787880e+03, -1.536570386888370e+02, -1.865294159489743e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_task_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.880068287083376e-12, -8.783378082366653e-12, -1.247192249352453e-11, -2.061994078951187e-11, -4.234352636324849e-11, -1.181256133308305e-10, -5.037813804292681e-10, -3.721052735593814e-09, -4.303863041042463e-08, 4.257691485465767e-07, -2.123022893608202e-05, -7.550949992938404e-04, 1.560099219635948e-03, 2.002532349445449e-01, 2.113476753365413e+01, 1.819106623616853e+03, -5.433146006239817e+07, -8.250301087191415e+10, -9.880655160422552e+14, -2.804088334669470e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_task_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.763422924197458e-09, 1.172346424542489e-08, 1.524378538478895e-08, 2.221022890321332e-08, 3.804658987739050e-08, 8.186413105758026e-08, 2.408690595387532e-07, 1.048237962828773e-06, 5.725835167251584e-06, -2.045481269200888e-05, 2.396184959282422e-04, 2.740945217671788e-03, -6.891772760053341e-03, -3.634454279484636e-01, -1.186302275765929e+01, -1.506744010759265e+02, 4.467292248764648e+05, 2.257948983429096e+07, 1.247782562076486e+08, 1.119386989609576e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_task_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_task", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.382843921305005e-05, -1.561858514617476e-05, -1.859883032898004e-05, -2.388422420139214e-05, -3.413647501685354e-05, -5.666664415996059e-05, -1.150659169809590e-04, -2.951632693175888e-04, -7.619818340438394e-04, 9.762619962286151e-04, -3.008921350845393e-03, -1.091877112969300e-02, 3.743049082195692e-02, 6.575926493804450e-01, 6.566821597129983e+00, 1.144329267270006e+01, -3.648469031880461e+03, -6.002706399582205e+03, -2.938337808030728e+02, -3.526704850489766e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
