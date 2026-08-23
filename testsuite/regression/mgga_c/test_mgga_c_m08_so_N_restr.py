
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m08_so_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.117817881029907e-02, -1.830220890699076e-02, -1.603729924335202e-02, -1.669700152402093e-02, -2.491792123867626e-02, -4.628424152912977e-02, -7.558036488744939e-02, -7.145193622512516e-02, 3.920577333618440e-03, 5.066528342720095e-02, 3.574812919301797e-02, -7.981368135896093e-02, -5.371922363840992e-02, -3.665005320924092e-02, 4.349125548435548e-03, 7.976560397393766e-03, -5.678645244589309e-02, -6.050872547241527e-02, -1.945573910163755e-02, -2.654554256127419e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m08_so_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.118245841019047e-01, -2.682758739303004e-01, -2.012590254346991e-01, -1.041164886717626e-01, 1.571548814140639e-02, 1.042838725559155e-01, 3.369487185646045e-02, -2.499492843016411e-01, -2.658928956973439e-01, -1.062566943005590e-01, 5.233562891283920e-02, -8.493387641077699e-02, -1.162670382880990e-01, -1.609534321326077e-01, -5.271657864511940e-02, 5.178012378444916e-02, 3.345576220833839e-03, -6.283509678629527e-02, -2.480678528624819e-02, -3.491546501037788e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m08_so_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.346707324728970e-06, 3.637452926929073e-06, 4.021856139552686e-06, 4.468956580984311e-06, 4.798527486433278e-06, 4.462204891445349e-06, 2.662490786886013e-06, 1.703381425835625e-06, 1.012017268050095e-05, 5.014066001612876e-05, 4.248192608833468e-04, 1.356976928555844e-02, 8.327789583921033e-03, 1.490309606032609e-02, 8.091837135556916e-02, 4.408019814356163e-01, 5.301429697831890e-01, -1.112944318258727e-01, -2.473310965085762e-02, -6.313085964677643e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m08_so_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.209754647680445e-05, -1.230655307649216e-03, -2.892760232613407e-03, -5.133283152510116e-03, -7.551140121925514e-03, -8.503008001443879e-03, -4.823434150197190e-03, 3.642824598221998e-03, 4.951249513246531e-03, 1.106276927363524e-03, -5.217417616008722e-03, -1.420718688097049e-02, 1.396357606784472e-02, 4.782025453118340e-02, -1.492409490640097e-02, -8.300056123003018e-02, -6.075475612443187e-02, -1.065709676782410e-02, -1.828468245026918e-04, -3.482431422959560e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m08_so_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.503662666812860e-03, -1.147650431636239e-02, -1.392490597712463e-02, -1.631646543385419e-02, -1.662590733371212e-02, -9.475933206043398e-03, 1.312916388788513e-02, 3.502737014264817e-02, -5.241617810888143e-02, 1.489331122479720e-02, -5.929733206960919e-01, 1.304842742448575e+00, 8.300255892057212e-01, 1.342433715368567e+00, 3.389019184892252e-01, -3.203983484598788e+01, 4.347468512950169e+01, 5.687236570935623e+02, -2.230531990156876e+04, -2.830658385751398e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m08_so_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.077665223059750e-09, 3.380652998805601e-09, 2.171229302568744e-08, 5.884527704403097e-08, 1.349058545442173e-07, 2.748225920571882e-07, 3.937439500037706e-07, -1.180807974841972e-07, 2.215873445685630e-07, 1.980875621595352e-06, 8.093056059258950e-04, -2.316231209517014e-02, -1.000733090103797e-01, -2.428973423603311e-01, -1.233231613573907e+00, 1.417278863043521e+02, 3.603896997824550e+03, -1.757198417082951e+04, -5.622367226697045e+05, -1.081621354364030e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m08_so_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.433432536401779e-04, 2.726304788274587e-04, 3.009131684070932e-04, 3.067218628379111e-04, 2.312401506434354e-04, -4.606035539790408e-05, -6.097924610145070e-04, -8.531032115928832e-04, 1.264419063580710e-03, -5.499073891721871e-04, 9.629658359531810e-03, -9.067534046756087e-02, -2.437938923233033e-01, -4.780053914596457e-01, 5.145336869152634e-01, 5.058854932306764e+00, -7.199699035128057e+01, -8.806487036631895e+02, -1.882054086592417e+03, -2.689710310787503e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m08_so_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.620988733800499e-13, -5.722910290892852e-13, -7.635374831776585e-13, -1.111758218409380e-12, -1.761574136791975e-12, -2.869200188349983e-12, -3.843619640629404e-12, -7.932754512666968e-12, -2.585515560924372e-10, -1.471392146306281e-08, -3.319574399738384e-06, -2.953929482676516e-03, -6.616406311559232e-03, -4.397576282602880e-02, -3.379768179854050e+00, -1.070655021232952e+03, -2.676013650991156e+05, 6.167668192192616e+07, 1.885092090368861e+11, 2.765844100979682e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m08_so_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.658537256574501e-10, 2.918617114043138e-10, -6.619177056305563e-11, -8.334415868048898e-10, -2.491555598771685e-09, -5.719755527972022e-09, -8.762550139168383e-09, 4.519441866111544e-09, 2.143485339740160e-08, 5.372034730530571e-07, -2.591798588885133e-08, 2.328610268326876e-03, 3.535381350512025e-02, 1.496028696577660e-01, 1.816495406534661e+00, -2.122720638611248e+00, -4.102099780111707e+02, -3.858080564115045e+03, -3.341652787308080e+03, -8.667632144945926e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m08_so_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.926836061453838e-06, -7.147054175370768e-06, -6.983882706907818e-06, -5.648637999290615e-06, -1.383249278953449e-06, 8.522438863949539e-06, 2.276677605051366e-05, 1.822419104015778e-05, -4.085420848737998e-05, -2.200171952804059e-05, -2.458274514866686e-04, 6.620791265543953e-03, 5.450008934834067e-02, -1.229566916126318e-02, -1.385079097782242e+00, -7.366112646216124e-01, 8.245832978064813e+01, 8.921054504244105e+02, 2.044394890273790e+03, 3.086876696520401e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
