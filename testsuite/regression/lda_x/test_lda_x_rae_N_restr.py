
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_rae_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rae", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.552295566900487e-01, -2.500739189207440e-01, -2.428485145464493e-01, -2.328372435553176e-01, -2.191909671020154e-01, -2.010197710723290e-01, -1.776160818884642e-01, -1.488680067644611e-01, -1.158818831748235e-01, -8.179582236957240e-02, -5.303266647012272e-02, -3.859679450322823e-02, -3.367067839460845e-02, -2.706685508432600e-02, -1.839069181011868e-02, -1.026226753848450e-02, -4.500778577699377e-03, -1.440328644655204e-03, -2.981975703933153e-04, -3.297125998995623e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_rae_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rae", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.403060755867315e-01, -3.334318918943254e-01, -3.237980193952658e-01, -3.104496580737568e-01, -2.922546228026872e-01, -2.680263614297719e-01, -2.368214425179523e-01, -1.984906756859481e-01, -1.545091775664313e-01, -1.090610964927632e-01, -7.071022196016362e-02, -5.146239267097098e-02, -4.489423785947794e-02, -3.608914011243466e-02, -2.452092241349157e-02, -1.368302338464600e-02, -6.001038103599169e-03, -1.920438192873605e-03, -3.975967605244204e-04, -4.396167998660830e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_rae_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rae", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.334103709629425e-04, -6.597969477749480e-04, -6.996425266871601e-04, -7.611008442658094e-04, -8.588193017300459e-04, -1.021103004478214e-03, -1.307924066526147e-03, -1.861848568300543e-03, -3.072670661680450e-03, -6.167154888831640e-03, -1.467101544830576e-02, -2.769775866699809e-02, -3.639513787579293e-02, -5.632114906432780e-02, -1.219975106528944e-01, -3.917963962567693e-01, -2.036909842580834e+00, -1.988950187401821e+01, -4.640223517940773e+02, -3.795561338860112e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
