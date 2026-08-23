
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_w20_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_w20", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.192723171295732e-01, -1.186805216656091e-01, -1.178307792208176e-01, -1.166116933591987e-01, -1.148649408568572e-01, -1.123668665401458e-01, -1.088046046473067e-01, -1.037488228602908e-01, -9.664267486263035e-02, -8.694468253266505e-02, -7.532442469353154e-02, -6.722620902249193e-02, -6.387607954129407e-02, -5.869629841477330e-02, -5.009190303641022e-02, -3.852241897911605e-02, -2.505831044296451e-02, -1.187150100171705e-02, -3.102955820413106e-03, -4.531501738726247e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_w20_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_w20", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.289412466722228e-01, -1.283448486027580e-01, -1.274884019420830e-01, -1.262594700336277e-01, -1.244980436317971e-01, -1.219775136490905e-01, -1.183792445748165e-01, -1.132612017333075e-01, -1.060362336221063e-01, -9.609450441372855e-02, -8.402577023057511e-02, -7.550453276828405e-02, -7.195311161370352e-02, -6.643329302151095e-02, -5.719286467670458e-02, -4.464436765606050e-02, -2.983362604614112e-02, -1.482150366194415e-02, -4.033598896672357e-03, -5.927479824277440e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_w20_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_w20", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.440783956582553e-05, -5.782019180931032e-05, -6.310117674539935e-05, -7.153947438063733e-05, -8.565541529024012e-05, -1.108734369601681e-04, -1.603665284646315e-04, -2.714006614684815e-04, -5.715556188330150e-04, -1.600109094087441e-03, -5.668405010112484e-03, -1.413950815099104e-02, -2.086790941191301e-02, -3.871915060944763e-02, -1.143277717469775e-01, -5.735222416174850e-01, -5.410834349221927e+00, -1.077459836600877e+02, -4.321644210749138e+03, -4.670615617124038e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
