
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_relpbe0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_relpbe0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.272243411360276e+00, -3.207439326410856e+00, -3.116625663285046e+00, -2.990812430245546e+00, -2.819353620521996e+00, -2.591131082929833e+00, -2.297420076312152e+00, -1.937230171918394e+00, -1.525342293771265e+00, -1.101139020942482e+00, -7.284312755053503e-01, -5.207617273347732e-01, -4.586837615511273e-01, -3.712824137181703e-01, -2.576568854947041e-01, -1.534971109246059e-01, -8.349554063574942e-02, -3.602318373630364e-02, -8.216177982587863e-03, -9.303552363417401e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_relpbe0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_relpbe0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.319360332109517e+00, -4.232154578699275e+00, -4.109886699715264e+00, -3.940365399498365e+00, -3.709056830447175e+00, -3.400546772978510e+00, -3.002121945067568e+00, -2.510433271565335e+00, -1.941903123378338e+00, -1.350564162793199e+00, -8.735954390365411e-01, -6.895059609755471e-01, -6.083969373875340e-01, -4.918581709703007e-01, -3.328840966752233e-01, -1.757655142079516e-01, -7.554275844624601e-02, -4.141689949496915e-02, -1.083545030892180e-02, -1.238566947840673e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_relpbe0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_relpbe0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.138777596880410e-07, -3.453547496389732e-07, -3.959270833726875e-07, -4.811701464141705e-07, -6.350306835263306e-07, -9.411386383108185e-07, -1.640095851882049e-06, -3.575529388164624e-06, -1.053545165748409e-05, -4.476800689829011e-05, -2.464215035161365e-04, 2.336120587123215e-04, 1.764007284587692e-03, 1.214925553717780e-03, -5.993494512115404e-03, -1.436411597418379e-01, -2.372347071171512e+00, -1.436957583866914e+01, -2.280905926910986e+01, -2.555828014370818e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_relpbe0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_relpbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.418997035795232e-03, -8.788316725327931e-03, -9.348637839345137e-03, -1.021903306877141e-02, -1.161817332112810e-02, -1.398238676495872e-02, -1.828129385091731e-02, -2.699071989580824e-02, -4.757873629518214e-02, -1.054309114436098e-01, -2.676831111904092e-01, -3.857243911306359e-01, -4.718712448718886e-01, -8.086768246407847e-01, -2.236930187231438e+00, -9.118215374658488e+00, -3.706431749616766e+00, 2.084909753759081e+02, -1.130731140172865e+04, -1.061289015944929e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_relpbe0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_relpbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.421619735115279e-09, 6.248966908332230e-09, 7.662920344227620e-09, 1.026914776874693e-08, 1.562478586799441e-08, 2.849212886780362e-08, 6.717399899280825e-08, 2.270833293581381e-07, 1.251234153106551e-06, 1.254504953926424e-05, 2.470641077398645e-04, 2.715510353805421e-03, 1.298802433405500e-03, 3.297044408510173e-02, 6.682397731218581e-01, 2.396719389445839e+01, -1.403190537097554e+03, -1.413540538045679e+06, -3.158394114679853e+08, -2.647591906392733e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_relpbe0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_relpbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.774704841266736e-14, -4.581382968139272e-14, -6.050786189016628e-14, -9.019758430546665e-14, -1.598349844924147e-13, -3.621978217496794e-13, -1.161199347819061e-12, -6.023212545640481e-12, -5.876879271756939e-11, -1.125103389167453e-09, -1.332542952924897e-07, -2.909767211051083e-04, -2.962833156265573e-03, -1.687208265192242e-02, -5.660389331932463e-01, -4.536784436911992e+01, 3.125501938318753e+05, 4.526372822118445e+09, 1.149831436366333e+14, 7.464185295384188e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
