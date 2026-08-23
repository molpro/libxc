
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pmgb06_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pmgb06", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.651479030555499e-03, -1.679754699475148e-03, -1.721155526770176e-03, -1.782237154316018e-03, -1.873333737283841e-03, -2.011283065008932e-03, -2.224703762267738e-03, -2.564800258560951e-03, -3.128124262322200e-03, -4.096607855181719e-03, -5.668963107020441e-03, -7.129293285830598e-03, -7.841753355053951e-03, -9.079535683375784e-03, -1.148180937299371e-02, -1.523998794379993e-02, -1.855987736215849e-02, -1.145786169242655e-02, -3.356065780223334e-03, -4.555939942526962e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pmgb06_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pmgb06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.193197417686312e-03, -1.214287058820462e-03, -1.245191537748373e-03, -1.290840838641375e-03, -1.359036695654949e-03, -1.462556033199949e-03, -1.623258673395687e-03, -1.880576993719327e-03, -2.309608472702455e-03, -3.053896756142480e-03, -4.280352446985022e-03, -5.451785946819418e-03, -6.041669575502488e-03, -7.106531446931561e-03, -9.346880561415019e-03, -1.309283794713401e-02, -1.888341978630964e-02, -1.400495420491803e-02, -4.310145730587510e-03, -5.993006242292542e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pmgb06_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pmgb06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.908002900027976e-06, 2.061654302060532e-06, 2.304191559780465e-06, 2.702878587791032e-06, 3.397487382782056e-06, 4.712767164433692e-06, 7.518188286010528e-06, 1.460694555313669e-05, 3.732601171479243e-05, 1.366473902144952e-04, 6.820644575669032e-04, 2.215691832990859e-03, 3.671325537101575e-03, 8.163315605834663e-03, 3.113902040200813e-02, 1.885505573693037e-01, 1.459345927247922e+00, -8.725488672385896e+01, -4.204038173978439e+03, -4.863015948099757e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
