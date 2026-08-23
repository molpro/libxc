
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ncapr_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncapr", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.310851205894518e+00, -4.229360692447891e+00, -4.115299203880119e+00, -3.957560888271801e+00, -3.743180245427456e+00, -3.459029091831227e+00, -3.095740030032920e+00, -2.654601976515007e+00, -2.155828670088495e+00, -1.636670172293914e+00, -1.107242931458502e+00, -6.666128710415348e-01, -5.633829919709458e-01, -4.741070742529370e-01, -3.535713409291611e-01, -2.392825474076318e-01, -1.600481878209324e-01, -1.461504567770252e-01, -2.227951137251338e-01, -4.228723900234005e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ncapr_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncapr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.363416289572966e+00, -5.248620702921707e+00, -5.087661418317352e+00, -4.864491996900066e+00, -4.560023995552714e+00, -4.154197925136241e+00, -3.631255017981045e+00, -2.990493040048330e+00, -2.265681780574905e+00, -1.551223907063845e+00, -9.957375043286812e-01, -7.951009811313638e-01, -7.138863225470693e-01, -5.511578476686289e-01, -3.538137402580608e-01, -1.902740550953961e-01, -6.498971186849199e-02, 3.461778941298561e-02, 1.004151160032869e-01, 1.496897392893438e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ncapr_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncapr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.124380651333199e-06, -4.463547818765674e-06, -4.999130258230510e-06, -5.879655790771860e-06, -7.412615112638436e-06, -1.030606619155829e-05, -1.641847395223867e-05, -3.147202560712085e-05, -7.680927804261664e-05, -2.539197582553458e-04, -1.280017363810110e-03, -7.520081831409458e-03, -1.385403715717073e-02, -3.008791361094365e-02, -1.108237523626378e-01, -6.895313281260139e-01, -1.006046045975596e+01, -5.171173751508524e+02, -1.082194861091763e+05, -1.508629694641070e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ncapr_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncapr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.247111030972029e-02, -1.305347493309577e-02, -1.393844425896014e-02, -1.531529502031655e-02, -1.752954171237022e-02, -2.125659531224187e-02, -2.791605619774397e-02, -4.065500340224620e-02, -6.621193300841438e-02, -1.175352669618735e-01, -2.557345014195355e-01, -5.813559569832079e-01, -6.894249408655143e-01, -1.210743249007128e+00, -2.513342838749736e+00, -6.289450696367471e+00, -1.016640214880695e+02, -3.708865397957000e+03, -4.978386566928960e+05, -4.553134239726582e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ncapr_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncapr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.669795639233739e-08, 3.048803661185499e-08, 3.686530018199109e-08, 4.834110686560388e-08, 7.104034621082668e-08, 1.222368942463706e-07, 2.600127229454471e-07, 7.225743670258868e-07, 2.669225279242241e-06, 1.199860244634840e-05, 1.308767123334371e-04, 1.231104986779421e-02, 4.112156189864133e-02, 1.302564956377950e-01, 7.095545667679030e-01, 4.504382165438267e+00, 5.396351338304480e+03, 9.165388266144143e+06, 1.674524807592261e+11, 1.235948155217060e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ncapr_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncapr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.301384814357022e-14, 5.534120950295705e-14, 7.937860887663568e-14, 1.328852686874502e-13, 2.768096230746847e-13, 7.837053628730865e-13, 3.396588018231090e-12, 2.627138365807656e-11, 4.341262472320838e-10, 1.828363194617238e-08, 2.480841687072461e-06, 3.112303592227177e-04, 1.413060351300449e-03, 2.138711089555426e-02, 1.409570704841114e+00, 3.987763346126932e+02, 5.601281855283742e+05, 2.762023005613561e+10, 9.195700178837435e+16, 8.402702744848646e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
