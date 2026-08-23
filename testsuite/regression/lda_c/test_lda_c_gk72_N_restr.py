
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_gk72_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gk72", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.199166381803945e-01, -1.193291100084171e-01, -1.184859583981839e-01, -1.172772790037124e-01, -1.155473655977347e-01, -1.130771804772121e-01, -1.095617225175330e-01, -1.045830394831493e-01, -9.758962668121283e-02, -8.797795634964883e-02, -7.609035372099397e-02, -6.759120801676023e-02, -6.499964374637793e-02, -6.085597832537765e-02, -5.352086763384305e-02, -4.244848920915239e-02, -2.680472862359584e-02, -1.117737753637663e-02, -3.370799703119205e-03, -4.628777877437438e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_gk72_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gk72", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.295180136952968e-01, -1.289215845526646e-01, -1.280655722855384e-01, -1.268382883729359e-01, -1.250814364559406e-01, -1.225722670670016e-01, -1.190006911259890e-01, -1.139428062516393e-01, -1.068449312372675e-01, -9.712901081245845e-02, -8.527064440358828e-02, -7.391787468342689e-02, -7.132631041304459e-02, -6.718264499204432e-02, -5.984753430050972e-02, -4.877515587581906e-02, -3.313139529026251e-02, -1.374645921630305e-02, -4.310397456079741e-03, -6.089742272645145e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_gk72_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gk72", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.442289812503599e-05, -5.781009601958193e-05, -6.304792601340001e-05, -7.140740251426063e-05, -8.536735500774336e-05, -1.102440175644881e-04, -1.588926351451750e-04, -2.675197275711556e-04, -5.598108751840872e-04, -1.562895972953794e-03, -5.630665509362882e-03, -1.021529377502426e-02, -1.538682356173943e-02, -2.962041782959028e-02, -9.443008354848535e-02, -5.434687489680020e-01, -6.442310171134769e+00, -9.636436268606482e+01, -4.099116517739149e+03, -4.942316828372324e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
