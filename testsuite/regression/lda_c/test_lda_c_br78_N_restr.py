
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_br78_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_br78", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.345840948354759e-02, -7.303773542466573e-02, -7.242682304970627e-02, -7.153638922478561e-02, -7.023238978054713e-02, -6.831182352961597e-02, -6.546637134665668e-02, -6.123558463544336e-02, -5.498608931533935e-02, -4.613173921660568e-02, -3.557029846287118e-02, -2.860484610209761e-02, -2.588092325960249e-02, -2.189519066401845e-02, -1.597679369042366e-02, -9.578837348465506e-03, -4.435017379505069e-03, -1.462552559805399e-03, -3.062833274691172e-04, -3.395603489238692e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_br78_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_br78", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.029917496706560e-02, -7.993979693008710e-02, -7.941583924017813e-02, -7.864777450425768e-02, -7.751362173614533e-02, -7.582295925783293e-02, -7.327377943710997e-02, -6.938561056073347e-02, -6.342803879428986e-02, -5.454997644464396e-02, -4.328970976310918e-02, -3.546415909168108e-02, -3.231757912219393e-02, -2.762595159834573e-02, -2.046769813446334e-02, -1.247174714270621e-02, -5.849037636164965e-03, -1.943075353572600e-03, -4.080710129700611e-04, -4.527094283960987e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_br78_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_br78", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.257971996065634e-05, -3.505966780888742e-05, -3.894637108567561e-05, -4.526746775163387e-05, -5.610281735853341e-05, -7.610862965508131e-05, -1.170917131290845e-04, -2.139427238812404e-04, -4.904127456099350e-04, -1.473269216407078e-03, -5.288759147342312e-03, -1.269517730499476e-02, -1.822276141501318e-02, -3.193200052815092e-02, -8.236949017797499e-02, -3.157718075622732e-01, -1.878059001256991e+00, -1.976381487566059e+01, -4.744586343337983e+02, -3.906973005218313e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
