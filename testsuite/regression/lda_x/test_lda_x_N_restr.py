
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.162997500333359e+00, -4.078904939014905e+00, -3.961052834661588e+00, -3.797761025312666e+00, -3.575179379594633e+00, -3.278792688998617e+00, -2.897059864499272e+00, -2.428155845573446e+00, -1.890125878236584e+00, -1.334155058208107e+00, -8.650050598146164e-01, -6.295444819227877e-01, -5.491956018303450e-01, -4.414819800622555e-01, -2.999668417239793e-01, -1.673857630930441e-01, -7.341128594785108e-02, -2.349290820827544e-02, -4.863840051489045e-03, -5.377875301790263e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.550663333777812e+00, -5.438539918686541e+00, -5.281403779548784e+00, -5.063681367083555e+00, -4.766905839459511e+00, -4.371723585331488e+00, -3.862746485999029e+00, -3.237541127431262e+00, -2.520167837648779e+00, -1.778873410944143e+00, -1.153340079752822e+00, -8.393926425637168e-01, -7.322608024404599e-01, -5.886426400830074e-01, -3.999557889653057e-01, -2.231810174573921e-01, -9.788171459713478e-02, -3.132387761103392e-02, -6.485120068652060e-03, -7.170500402387017e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.033142801014302e-02, -1.076181410936793e-02, -1.141172726034486e-02, -1.241416140540478e-02, -1.400802733314319e-02, -1.665500387319141e-02, -2.133328400592127e-02, -3.036823413538690e-02, -5.011770756416511e-02, -1.005912117676604e-01, -2.392959554947590e-01, -4.517725203573392e-01, -5.936337074988985e-01, -9.186428320111596e-01, -1.989876636864815e+00, -6.390511504266319e+00, -3.322362305148746e+01, -3.244136284927450e+02, -7.568574406777818e+03, -6.190863068898107e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
