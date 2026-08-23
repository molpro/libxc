
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_p86_ft_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86_ft", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.003722505674756e-02, -6.903564398273115e-02, -6.760198897915543e-02, -6.555449836053313e-02, -6.264058901598574e-02, -5.851783471953406e-02, -5.274794757402210e-02, -4.485683320717670e-02, -3.463438067535685e-02, -2.297148009609123e-02, -1.377100731965835e-02, -4.569608127004262e-02, -5.383432802360211e-02, -3.972889276669615e-02, -2.258068823665435e-02, -3.904422334731024e-03, 3.844087516569126e-03, -8.677934405954775e-03, -3.335439215642988e-03, -4.506436826535031e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_p86_ft_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86_ft", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.296999910374846e-01, -1.285119570497147e-01, -1.267814957384695e-01, -1.242468298892686e-01, -1.205042624805004e-01, -1.149153774305767e-01, -1.064455064072026e-01, -9.342462832134865e-02, -7.358581916521255e-02, -4.768525004079351e-02, -4.588984071176167e-02, -8.842894020576419e-02, -8.011817767706682e-02, -7.888070573870111e-02, -6.911667507569967e-02, -4.478176732511568e-02, 2.469689962116643e-03, 1.868677478365321e-04, -4.249947144234619e-03, -5.930727728502095e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86_ft_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86_ft", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.095311086439197e-07, 6.469815559341004e-07, 7.044830424680751e-07, 7.951790649111474e-07, 9.435833442320319e-07, 1.198430847024705e-06, 1.662495273690508e-06, 2.556585947186969e-06, 4.285963567701269e-06, 7.407276290509370e-06, 7.460062281650209e-05, 3.220818492501487e-03, 7.989644322613365e-03, 1.374989030593661e-02, 4.373594551285392e-02, 2.303771460861370e-01, 3.480028142080381e-01, -2.514504767096048e+01, -1.191140949462840e+01, -1.648632154419437e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86_ft_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86_ft", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.582053881074667e-04, -4.983621650410392e-04, -5.619373097913350e-04, -6.668311844091655e-04, -8.503361433827293e-04, -1.198937302761311e-03, -1.941307391662747e-03, -3.784867949169442e-03, -9.334317634348555e-03, -2.964922350847633e-02, -1.008498174078194e-01, -4.217990806666605e-03, 9.415449020319345e-03, -1.694508877340471e-03, -3.197998267448472e-01, -5.476876897402750e+00, -9.105871514904935e+01, 9.420948198505255e+02, -2.504129160194032e+03, -4.822901153639765e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86_ft_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86_ft", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.935827217364744e-09, 5.736519472432164e-09, 7.113923863634285e-09, 9.674628224526262e-09, 1.499256457955734e-08, 2.791873956606100e-08, 6.715946221143481e-08, 2.297003583983022e-07, 1.261161307146675e-06, 1.287896636834434e-05, 2.889826904953331e-04, -9.408858162405069e-04, -1.282610201591751e-02, -1.482416766563113e-02, 2.061334351301363e-01, 2.831129347116194e+01, 6.644031115045719e+03, -2.074504303017197e+06, -5.229056749479468e+08, -1.820315816350740e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86_ft_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86_ft", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.163183162688041e-13, -1.419945039978503e-13, -1.890748518051808e-13, -2.850971043114367e-13, -5.133131734966851e-13, -1.188945435656427e-12, -3.928661912282663e-12, -2.133332138791640e-11, -2.308218512596177e-10, -6.678520468118902e-09, -1.062653668283646e-06, -5.418913950632707e-04, -5.427618562125485e-03, -2.946419648556693e-02, -1.124045107296651e+00, -3.179696553437656e+02, -5.062495721650185e+05, 7.125027083633419e+09, 1.779422201939266e+14, 4.535412913400841e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
