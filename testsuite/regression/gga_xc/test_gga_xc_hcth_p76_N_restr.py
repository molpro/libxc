
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_hcth_p76_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p76", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.513264622070190e+00, -4.415834456183913e+00, -4.279438994638308e+00, -4.090780089880909e+00, -3.834353496361558e+00, -3.494607724245533e+00, -3.061219731394627e+00, -2.539752738823587e+00, -1.970003074021851e+00, -1.436078558982132e+00, -9.427353704935086e-01, -5.708665906929493e-01, -4.930702562403669e-01, -3.757083756975635e-01, -2.522573594518217e-01, -1.602746150246631e-01, -1.215168310963614e-01, -6.941001657646817e-02, -1.721601721282189e-02, -1.914467922647808e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_hcth_p76_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p76", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.244541573564965e+00, -6.110341977075243e+00, -5.921851079370743e+00, -5.659784595206698e+00, -5.300565215023351e+00, -4.817618242982945e+00, -4.184442072712547e+00, -3.379284496889128e+00, -2.398581598716214e+00, -1.358116532191346e+00, -7.433454144816490e-01, -7.962868373175677e-01, -7.197419004511790e-01, -5.116431676510199e-01, -2.599646891827772e-01, -8.676481914622357e-02, -1.577874340213442e-02, -7.340999417592034e-02, -2.257075318724431e-02, -2.558793041044013e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_p76_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p76", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.730078137411367e-06, 1.798309291274318e-06, 1.893583545630421e-06, 2.019996617026816e-06, 2.161299808221845e-06, 2.199464981536817e-06, 1.506770692232336e-06, -3.403232721056767e-06, -3.447207216629273e-05, -2.392245319188901e-04, -1.454135559988292e-03, 3.346653002157468e-04, 1.241642386111797e-02, -5.476798285529244e-03, -8.922648504545061e-02, -7.615557091772109e-01, -1.019639575322619e+01, -3.894583788106490e+01, -7.089718331700506e+01, -9.271175975134729e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_p76_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p76", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.344337089638562e-02, -1.411823478605241e-02, -1.515934508688591e-02, -1.681999609178970e-02, -1.960799380826432e-02, -2.467798395112851e-02, -3.511671528105675e-02, -6.077374340422387e-02, -1.363187329900070e-01, -3.522855093262695e-01, -7.811652865957766e-01, -7.779169291559861e-01, -8.832686553130321e-01, -1.748633829698348e+00, -4.046895399680836e+00, -1.887106958100018e+01, 2.489652469674559e+02, 1.219489145583881e+03, -2.199050747745836e+04, -2.226439558641329e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_p76_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p76", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.533051252697739e-08, 1.838719439128510e-08, 2.383197600217200e-08, 3.448908093408171e-08, 5.838614618907577e-08, 1.235031811070108e-07, 3.565507246909181e-07, 1.548626799844712e-06, 1.068590202952770e-05, 1.081475685936056e-04, 1.633668150087960e-03, 2.285937331194921e-02, 8.396696545165074e-02, 2.916813003427902e-01, 2.230308035697631e+00, 8.467247884457068e+01, -1.900325603139449e+04, -4.403095265679467e+06, -9.781712910522254e+08, -9.576770285237590e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_p76_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p76", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.042022167645864e-13, -3.740926596594618e-13, -5.037032627841739e-13, -7.729671478517765e-13, -1.433291890902854e-12, -3.498652605433988e-12, -1.270748485184295e-11, -8.009041972795090e-11, -9.880035262237804e-10, -2.183490811122657e-08, -1.204864694393494e-06, -1.851308635277416e-03, -4.730401671836142e-02, -9.224613611730036e-02, -3.754826497747883e-01, -1.616825661669755e+01, 2.322098350012782e+06, 1.388160855895312e+10, 3.595677569984517e+14, 2.707814194166688e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
