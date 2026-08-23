
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_edf2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_edf2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.697447834107555e+00, -3.627155837834960e+00, -3.528691683517813e+00, -3.392360664679878e+00, -3.206729775422111e+00, -2.959951804837429e+00, -2.642892502123024e+00, -2.254720104325178e+00, -1.810276448067076e+00, -1.344095711087866e+00, -9.021779089026728e-01, -6.014143973613593e-01, -5.189679238617015e-01, -4.322529031060217e-01, -3.121396509140560e-01, -1.921595620197173e-01, -1.042315661898458e-01, -6.365941964541307e-02, -3.611666622766772e-02, -2.337778601322547e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_edf2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_edf2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.691096342098945e+00, -4.594901430275695e+00, -4.460085553030416e+00, -4.273288561235595e+00, -4.018682589060151e+00, -3.679741753311622e+00, -3.243580409877908e+00, -2.709262724355380e+00, -2.101205097936713e+00, -1.487216579051653e+00, -9.861073334841476e-01, -7.466447625506882e-01, -6.632033342371539e-01, -5.323486466434441e-01, -3.675226778662331e-01, -2.197147981091293e-01, -1.086438909060391e-01, -3.881156438071359e-02, -1.292282630727032e-02, -4.228039891262039e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_edf2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_edf2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.345116307419247e-06, -2.527533762771092e-06, -2.814033125338619e-06, -3.281393042538918e-06, -4.085998563335213e-06, -5.580737978921973e-06, -8.669353705529231e-06, -1.605741230659593e-05, -3.755218249386052e-05, -1.181377265963397e-04, -5.567547242937029e-04, -3.676443013033978e-03, -7.363969119884475e-03, -1.366726331458408e-02, -4.145236903650655e-02, -1.765306429240592e-01, -1.460952507790533e+00, -1.001840856526276e+02, -9.579075356199341e+03, -5.696116445546892e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_edf2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_edf2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.693760530874939e-03, -1.011671826615480e-02, -1.075655995603428e-02, -1.174575575022100e-02, -1.332287715901917e-02, -1.594834913604694e-02, -2.058594364164067e-02, -2.943470022279593e-02, -4.783478686995429e-02, -8.805394967029768e-02, -1.846838731597486e-01, -4.296730370501189e-01, -5.526719949753305e-01, -8.735343351577894e-01, -1.690429648785342e+00, -2.607227478401414e+00, -1.460223630682183e+00, -7.139666754504154e+01, 6.230579129503194e+03, 5.512052193006630e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_edf2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_edf2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.169195325495050e-08, 1.325205349814369e-08, 1.585302726029757e-08, 2.047240791524124e-08, 2.944185884757931e-08, 4.915981826870936e-08, 1.004521614225282e-07, 2.657532527388803e-07, 9.276296016558263e-07, 3.129161940685728e-06, -1.801674946043592e-05, 3.935093890150128e-03, 1.611362492914872e-02, 3.444921746671836e-02, -1.356102520904987e-02, -1.878242376477698e+01, -2.961199252261201e+03, -6.523263441247498e+05, -5.732732767925064e+09, -1.935576229652171e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_edf2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_edf2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.120634142620306e-14, 7.633732995488591e-14, 1.048048719829825e-13, 1.650471694639205e-13, 3.159870192972714e-13, 7.978114216210797e-13, 2.972070343944129e-12, 1.901396108447030e-11, 2.550170185515965e-10, 9.240456545282390e-09, 1.227575233230538e-06, 3.018939924725397e-04, 2.662457913775971e-03, 1.782994256565371e-02, 7.561404977728095e-01, 2.113406388442697e+02, 4.277311286227717e+05, 1.133073891438805e+10, 1.373600430631561e+16, 4.568520536286478e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
