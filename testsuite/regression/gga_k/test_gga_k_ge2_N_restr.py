
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_ge2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ge2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.393481253341287e+01, 9.028127424451925e+01, 8.528589945984854e+01, 7.860544611180497e+01, 6.995026334884321e+01, 5.923270625861096e+01, 4.678777888900171e+01, 3.359153169432554e+01, 2.126798622026458e+01, 1.156506958850782e+01, 5.155721281255856e+00, 2.190979090673431e+00, 1.621737749962888e+00, 1.091579572313055e+00, 5.561380134276688e-01, 2.310328103760474e-01, 1.066033205280535e-01, 7.471913642671353e-02, 6.710076049312787e-02, 6.380509700108156e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_ge2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ge2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.493301185491435e+02, 1.432550140922289e+02, 1.349501844855965e+02, 1.238467406124328e+02, 1.094664427369160e+02, 9.166933747596333e+01, 7.102221802353407e+01, 4.916843754416289e+01, 2.887944160560155e+01, 1.341995722155631e+01, 5.347064349514572e+00, 3.372161670707775e+00, 2.611974202582356e+00, 1.644276013006859e+00, 7.068921042743346e-01, 1.622493425774317e-01, -3.095611856645675e-02, -6.697200775475011e-02, -6.676869345014270e-02, -6.380103735044013e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ge2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ge2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.755400412590113e-05, 8.245023994086244e-05, 9.003072964974586e-05, 1.021503305061067e-04, 1.224416477279970e-04, 1.587379625383357e-04, 2.301178285455507e-04, 3.908345992127692e-04, 8.286106123478635e-04, 2.356154442768716e-03, 8.645034528253355e-03, 2.242556589178138e-02, 3.377859053771389e-02, 6.502550454335766e-02, 2.073017288999064e-01, 1.193073298577454e+00, 1.414276029841669e+01, 4.315313285405495e+02, 4.862782240123167e+04, 3.597414593058018e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ge2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.962549335318882e-01, 6.097716800040283e-01, 6.298102850500581e-01, 6.599250243321624e-01, 7.061010215416310e-01, 7.790638002586713e-01, 8.997607634872279e-01, 1.114246501247588e+00, 1.540430007211558e+00, 2.511023007122985e+00, 4.239153277108595e+00, 4.081130305988752e+00, 4.456110479847554e+00, 5.951584436162004e+00, 1.031764567417951e+01, 2.843088065841533e+01, 1.914271442609396e+02, 4.562850252709118e+03, 4.694792517190282e+05, 3.305245723518189e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ge2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.330528960291408e-07, -4.894590287740167e-07, -5.835983242511252e-07, -7.512976816204914e-07, -1.079420911080977e-06, -1.814237334059190e-06, -3.812703481045401e-06, -1.099812124381003e-05, -4.943487937647609e-05, -3.997053905888706e-04, -5.381036783617875e-03, -3.620923240079725e-02, -8.215150886744650e-02, -3.044387693605125e-01, -3.094128489952099e+00, -1.024865204960511e+02, -1.440127215780993e+04, -1.340778870086196e+07, -1.702558880269725e+11, -9.317802063129685e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ge2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
