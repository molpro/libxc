
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ow_lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow_lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.631250539076539e-02, -4.625690157171701e-02, -4.617524505868777e-02, -4.605426128625495e-02, -4.587274716852126e-02, -4.559557710016014e-02, -4.516186194887923e-02, -4.446037936829837e-02, -4.327814669218104e-02, -4.121694099504269e-02, -3.788954935829791e-02, -3.489343579537646e-02, -3.347091182291628e-02, -3.105101990103371e-02, -2.645102812883842e-02, -1.936298194448776e-02, -1.090191027613044e-02, -4.108023338217024e-03, -9.108326858682791e-04, -1.023961420889946e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ow_lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow_lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.721260610615220e-02, -4.717335457620073e-02, -4.711563611031035e-02, -4.702995321681872e-02, -4.690102948491547e-02, -4.670330267077983e-02, -4.639181041001692e-02, -4.588261146644058e-02, -4.500934686306027e-02, -4.344151015016923e-02, -4.078903483251641e-02, -3.827223009394332e-02, -3.703467422764439e-02, -3.486641451834729e-02, -3.052588697595562e-02, -2.327613351184136e-02, -1.373032494138255e-02, -5.362982888347005e-03, -1.208820589551049e-03, -1.364571241821358e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ow_lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow_lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.546074652116783e-06, -3.842539906312285e-06, -4.312167470872683e-06, -5.088087160415891e-06, -6.449827328249251e-06, -9.055384345432612e-06, -1.469556627866099e-05, -2.924165175331335e-05, -7.711858186840211e-05, -2.923249365794792e-04, -1.479393096028237e-03, -4.693565303712378e-03, -7.623855399203881e-03, -1.629854801506687e-02, -5.928588208690341e-02, -3.599624564269648e-01, -3.414522361483229e+00, -4.981787954315515e+01, -1.378206527019359e+03, -1.175077579757398e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
