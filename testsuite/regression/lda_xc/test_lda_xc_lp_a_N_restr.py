
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_lp_a_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_a", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.862174558402162e+00, -4.763958618526936e+00, -4.626313207162895e+00, -4.435596474580614e+00, -4.175632154426484e+00, -3.829467203246579e+00, -3.383622201600749e+00, -2.835965569337312e+00, -2.207573258596372e+00, -1.558226921938715e+00, -1.010282997859831e+00, -7.352767238371719e-01, -6.414332179137844e-01, -5.156290512496873e-01, -3.503463900897825e-01, -1.954982674586184e-01, -8.574074012935277e-02, -2.743855132846159e-02, -5.680723890080112e-03, -6.281091561676439e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_lp_a_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.482899411202883e+00, -6.351944824702581e+00, -6.168417609550528e+00, -5.914128632774152e+00, -5.567509539235313e+00, -5.105956270995438e+00, -4.511496268800999e+00, -3.781287425783082e+00, -2.943431011461829e+00, -2.077635895918287e+00, -1.347043997146441e+00, -9.803689651162292e-01, -8.552442905517126e-01, -6.875054016662497e-01, -4.671285201197100e-01, -2.606643566114911e-01, -1.143209868391370e-01, -3.658473510461546e-02, -7.574298520106815e-03, -8.374788748901918e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_lp_a_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.206659538442153e-02, -1.256926499730833e-02, -1.332833131613220e-02, -1.449912466784420e-02, -1.636068100140751e-02, -1.945221828642370e-02, -2.491621739682816e-02, -3.546859093354116e-02, -5.853499614746586e-02, -1.174855451189672e-01, -2.794858047937776e-01, -5.276478918113165e-01, -6.933347208063338e-01, -1.072929254871160e+00, -2.324077196142494e+00, -7.463800410336999e+00, -3.880354353466473e+01, -3.788990242559709e+02, -8.839719437991986e+03, -7.230620942178686e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
