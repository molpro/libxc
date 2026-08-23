
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_exp4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_exp4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.960557055477726e+01, 8.688671713569028e+01, 8.320983531577319e+01, 7.837500397069552e+01, 7.227404778515542e+01, 6.501916884049386e+01, 5.701926336855634e+01, 4.841395203239667e+01, 3.647022180586706e+01, 1.946619736428037e+01, 8.187419898994392e+00, 2.478790045941881e+00, 1.463887629317696e+00, 1.383838340083968e+00, 9.721918958908772e-01, 3.065831023348846e-01, 5.897077628916277e-02, 6.039274156229084e-03, 2.588628633590776e-04, 3.164700657534418e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_exp4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_exp4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.963378069860649e+01, 8.341570028903048e+01, 7.487165375286376e+01, 6.339307324121089e+01, 4.854029676890622e+01, 3.067395192162087e+01, 1.292326104614249e+01, 6.813221279736093e+00, 3.037723335482854e+01, 3.203965067809433e+01, 1.364397955953107e+01, 9.610041920002842e-01, 1.867118018187078e+00, 2.340443981794850e-01, 1.365867306125350e+00, 5.109718372248077e-01, 9.828462714860461e-02, 1.006545692704847e-02, 4.314381055984627e-04, 5.274501095890696e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_exp4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_exp4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.406643539135793e-04, 7.017230736854124e-04, 7.986934954297313e-04, 9.588720752984277e-04, 1.237201195558578e-03, 1.748843423840132e-03, 2.715766301671415e-03, 4.235245704873413e-03, 3.836508009997650e-03, 1.625769266534575e-04, 4.581857023955579e-06, 2.543958764748201e-01, 2.127626933976784e-01, 7.699306811449702e-01, 2.397606733885562e-01, 4.481934790729913e-16, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_exp4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_exp4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.357153264241555e+00, 1.431381412285895e+00, 1.541901696210353e+00, 1.705465247656494e+00, 1.935370077159425e+00, 2.178413090173450e+00, 1.922908378279639e+00, -1.787881624920427e+00, -1.317556216502689e+01, 1.329867174472377e+00, 5.596508394349005e+00, 1.106917797587061e+01, 7.699985807951628e+00, 9.457471615252933e+00, -5.039711098950392e+01, 2.926208905526167e+01, 6.672076429353466e+01, 2.084908800046514e+02, 1.007034987655962e+03, 9.107792262459696e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_exp4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_exp4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.098177874846998e-05, -1.258684658666161e-05, -1.524938677946075e-05, -1.989050145441509e-05, -2.838699917610299e-05, -4.377538149202106e-05, -5.887922689209882e-05, 1.098242363005334e-04, 1.814858195711792e-03, 9.229880571690953e-04, 1.737100795633557e-04, -8.052181350975431e-01, -1.735959143663547e+00, -3.242285388052395e+00, 6.029353532349879e+01, 8.213778959011996e-12, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_exp4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_exp4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.944758154180554e-11, 9.624970288887018e-11, 1.260669529839068e-10, 1.830998833772967e-10, 3.007153326427075e-10, 5.354628067257824e-10, 4.591861941202420e-10, -1.312849750955394e-08, -2.578675130014885e-07, -3.825148689498132e-07, -4.702639358638643e-07, 3.165272937088818e-02, 4.526897271640516e-01, -1.346421265355031e-01, -6.018422051561216e+01, -4.418912978250774e-11, -0.000000000000000e+00, -0.000000000000000e+00, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
