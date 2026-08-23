
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ow_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.953309848625984e-02, -4.947362795185674e-02, -4.938629300705522e-02, -4.925689596699898e-02, -4.906275927336758e-02, -4.876631466995573e-02, -4.830243876598306e-02, -4.755217476153911e-02, -4.628772907703786e-02, -4.408318618013918e-02, -4.052440618638612e-02, -3.731994149729161e-02, -3.579849454830004e-02, -3.321032222030038e-02, -2.829044488769623e-02, -2.070949268564571e-02, -1.166003417089184e-02, -4.393697185648950e-03, -9.741724131084073e-04, -1.095168172810312e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ow_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.049579262268412e-02, -5.045381152314270e-02, -5.039207928837584e-02, -5.030043796674794e-02, -5.016254881875870e-02, -4.995107199030131e-02, -4.961791841331618e-02, -4.907330953913734e-02, -4.813931771038980e-02, -4.646245290563035e-02, -4.362552322469221e-02, -4.093369871780030e-02, -3.961008264282421e-02, -3.729104114813069e-02, -3.264867130815912e-02, -2.489476662714224e-02, -1.468513810322737e-02, -5.735927204698097e-03, -1.292882533761391e-03, -1.459464158597060e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ow_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.792670327396152e-06, -4.109751912810617e-06, -4.612037595931335e-06, -5.441915100404144e-06, -6.898351310815587e-06, -9.685099970918164e-06, -1.571750277058902e-05, -3.127512977275889e-05, -8.248144380394368e-05, -3.126533481919602e-04, -1.582270777777252e-03, -5.019958010883918e-03, -8.154021838107444e-03, -1.743195660009185e-02, -6.340864981234483e-02, -3.849944125266032e-01, -3.651969829483893e+00, -5.328223798230908e+01, -1.474047647849091e+03, -1.256793019423325e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
