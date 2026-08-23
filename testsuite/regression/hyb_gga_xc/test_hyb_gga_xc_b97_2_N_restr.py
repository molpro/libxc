
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b97_2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.544260490244387e+00, -3.474953340841832e+00, -3.377893794544864e+00, -3.243567566187559e+00, -3.060817494466069e+00, -2.818272728592618e+00, -2.507801490921274e+00, -2.131156900199061e+00, -1.710323010233555e+00, -1.292343385399729e+00, -8.832016801678190e-01, -5.734821767228260e-01, -5.002722444432457e-01, -4.121740755849814e-01, -2.988894966404702e-01, -1.943600359346147e-01, -1.064878504178194e-01, -3.331702155297234e-02, -5.520736448230612e-03, -5.187747473987215e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b97_2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.633988140426506e+00, -4.538313324535864e+00, -4.404011739612303e+00, -4.217458719804791e+00, -3.962138298268933e+00, -3.619835852838300e+00, -3.173611895326284e+00, -2.613101194588745e+00, -1.944552292479744e+00, -1.235868974750167e+00, -7.693144027893599e-01, -7.296381814094233e-01, -6.539158009448108e-01, -5.170087680299511e-01, -3.390500680459348e-01, -1.756969556302334e-01, -1.034925348293335e-01, -4.418669403435736e-02, -7.571026779508438e-03, -6.982652847164426e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.645154436328646e-07, -8.531769855105456e-07, -9.978147220661232e-07, -1.246996446977143e-06, -1.711051499678348e-06, -2.676554740034704e-06, -5.025949244845608e-06, -1.212680807914342e-05, -4.053875702727578e-05, -1.920591333234240e-04, -1.070651345853295e-03, -2.011257884002700e-03, -1.402939792375915e-03, -9.014887345210217e-03, -5.064955847625487e-02, -4.479523757767429e-01, -2.932496538430241e+00, -5.060109319719705e+00, -3.477884016312808e+00, -1.854857124462867e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.808105626204757e-03, -1.028632535862295e-02, -1.102107946980807e-02, -1.218488382763301e-02, -1.411415834286267e-02, -1.754094529185988e-02, -2.430502573487827e-02, -3.993251886272315e-02, -8.403238892102935e-02, -2.201390317182770e-01, -5.330801146647571e-01, -4.775798219909347e-01, -5.815087764771554e-01, -1.007692257929182e+00, -2.937160583317486e+00, -9.955958247647690e+00, 5.056572594458272e+01, -2.739363046892089e+02, -9.825028477672786e+03, -6.290767932017741e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.405475033245135e-08, 1.645607058243260e-08, 2.064873541531758e-08, 2.862295839461041e-08, 4.578154029721448e-08, 8.987063476492934e-08, 2.356874243834989e-07, 9.191104272568736e-07, 5.909456190340719e-06, 6.256402358570458e-05, 1.044464738389214e-03, 8.325768986912086e-03, 2.925971436796378e-02, 9.254298157548053e-02, 1.360029182857408e+00, 3.298476103913939e+01, -5.792906139448924e+03, -5.935203045027023e+05, -5.003521125673984e+07, -1.961432669513186e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.987853316794333e-14, -1.110363065463683e-13, -1.506189343781477e-13, -2.338951097447848e-13, -4.416943225898767e-13, -1.105990063438301e-12, -4.138392288494045e-12, -2.687150873997904e-11, -3.466779945020609e-10, -8.230028673895091e-09, -5.158487859961689e-07, -3.224328448667778e-04, -9.306249104755818e-03, -1.383439061869581e-02, -4.123972140457829e-01, 6.203151441530144e+01, 6.317271335898853e+05, 1.759583497827696e+09, 1.759736820106961e+13, 5.417044202342229e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
