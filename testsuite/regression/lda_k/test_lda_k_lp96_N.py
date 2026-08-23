
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_k_lp96_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp96", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.600462350484295e-02, 3.596848598413633e-02, 3.591527778657903e-02, 3.583613859173306e-02, 3.571671670127569e-02, 3.553275048392331e-02, 3.524090893796809e-02, 3.475835313725104e-02, 3.391427308081776e-02, 3.234266427468891e-02, 2.949903536993350e-02, 2.655166134985005e-02, 2.500040543445394e-02, 2.209892350502218e-02, 1.546363223942504e-02, 1.151325840219941e-03, -2.356301640437661e-02, 1.082099352073422e-01, 7.508675703843901e+00, 7.218288274966947e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_k_lp96_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp96", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.658899066122005e-02, 3.658899066122005e-02, 3.656472852994700e-02, 3.656472852994700e-02, 3.652899900559403e-02, 3.652899900559403e-02, 3.647584253673462e-02, 3.647584253673462e-02, 3.639559670587451e-02, 3.639559670587451e-02, 3.627190424813283e-02, 3.627190424813283e-02, 3.607549042391871e-02, 3.607549042391871e-02, 3.575020834061415e-02, 3.575020834061415e-02, 3.517966668981660e-02, 3.517966668981660e-02, 3.411193787806299e-02, 3.411193787806299e-02, 3.216125242542033e-02, 3.216125242542033e-02, 3.011218685203527e-02, 3.011218685203527e-02, 2.902183330937955e-02, 2.902183330937955e-02, 2.695879488743906e-02, 2.695879488743906e-02, 2.211101422051204e-02, 2.211101422051204e-02, 1.082664212051809e-02, 1.082664212051809e-02, -1.627661463501771e-02, -1.627661463501771e-02, -4.375133764777334e-02, -4.375133764777334e-02, 2.020903438995877e+00, 2.020903438995877e+00, 2.360478730671296e+02, 2.360478730671296e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_k_lp96_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp96", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.190592255826856e-06, 2.190592255826856e-06, 2.190592255826856e-06, 2.376564205836582e-06, 2.376564205836582e-06, 2.376564205836582e-06, 2.671711906750101e-06, 2.671711906750101e-06, 2.671711906750101e-06, 3.160713312119552e-06, 3.160713312119552e-06, 3.160713312119552e-06, 4.022518245570911e-06, 4.022518245570911e-06, 4.022518245570911e-06, 5.682182877950260e-06, 5.682182877950260e-06, 5.682182877950260e-06, 9.311823094219883e-06, 9.311823094219883e-06, 9.311823094219883e-06, 1.883289271316612e-05, 1.883289271316612e-05, 1.883289271316612e-05, 5.111833989679582e-05, 5.111833989679582e-05, 5.111833989679582e-05, 2.046022589054255e-04, 2.046022589054255e-04, 2.046022589054255e-04, 1.144044396942194e-03, 1.144044396942194e-03, 1.144044396942194e-03, 4.025241481524089e-03, 4.025241481524089e-03, 4.025241481524089e-03, 6.901422498595147e-03, 6.901422498595147e-03, 6.901422498595147e-03, 1.630431449317577e-02, 1.630431449317577e-02, 1.630431449317577e-02, 7.398637763590912e-02, 7.398637763590912e-02, 7.398637763590912e-02, 6.990201979094686e-01, 6.990201979094686e-01, 6.990201979094686e-01, 1.387869039017531e+01, 1.387869039017531e+01, 1.387869039017531e+01, -4.863526211573534e+02, -4.863526211573534e+02, -4.863526211573534e+02, -5.812702011885918e+06, -5.812702011885918e+06, -5.812702011885918e+06, -4.154530693403821e+11, -4.154530693403821e+11, -4.154530693403821e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
