
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pw_mod_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_mod", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.180998797157020e-01, -1.175098656931561e-01, -1.166632986818886e-01, -1.154500655249541e-01, -1.137144305843195e-01, -1.112380065810363e-01, -1.077186175411979e-01, -1.027479542481948e-01, -9.580639105839087e-02, -8.639742121513858e-02, -7.515586214518184e-02, -6.728759024268981e-02, -6.401356051572259e-02, -5.892116813594958e-02, -5.036264915094507e-02, -3.864262651589247e-02, -2.484783425258910e-02, -1.174260332593087e-02, -3.358560025091710e-03, -4.555973634625632e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pw_mod_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_mod", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.277425546703642e-01, -1.271422370254157e-01, -1.262806479504995e-01, -1.250453885201946e-01, -1.232771983613306e-01, -1.207521203201795e-01, -1.171589063600753e-01, -1.120739647225770e-01, -1.049513187129480e-01, -9.525185440158444e-02, -8.358501704869702e-02, -7.536143692422870e-02, -7.192417489465444e-02, -6.655852799559506e-02, -5.748199352730099e-02, -4.490048996859790e-02, -2.971425655334096e-02, -1.457546364456100e-02, -4.315135422127156e-03, -5.993073626680451e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pw_mod_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_mod", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.477774620409495e-05, -5.818693195045975e-05, -6.345836743771690e-05, -7.187042783083637e-05, -8.591514276026259e-05, -1.109328576358254e-04, -1.598189167583845e-04, -2.687937831155541e-04, -5.608715545530386e-04, -1.552974351048727e-03, -5.466992483587993e-03, -1.366768590973045e-02, -2.022618078531379e-02, -3.776201919969042e-02, -1.131996544665042e-01, -5.822888415509768e-01, -5.566286735164374e+00, -1.049701326764461e+02, -4.221519382060529e+03, -4.863190484314537e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
