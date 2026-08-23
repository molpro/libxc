
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_lp96_b_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_lp96_b", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.110186453518159e-02, -5.106046896281716e-02, -5.099969763007277e-02, -5.090971653063416e-02, -5.077490117498805e-02, -5.056966110771052e-02, -5.025077659765283e-02, -4.974434520857536e-02, -4.893540013975513e-02, -4.778114369967502e-02, -4.744457602129878e-02, -5.072009776843355e-02, -5.449486502884045e-02, -6.657025308675667e-02, -1.297068738029314e-01, -6.069604850821330e-01, -7.089782864791637e+00, -2.174610908900440e+02, -2.451355558269686e+04, -1.813151879402289e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_lp96_b_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_lp96_b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.177203743549738e-02, -5.174266413601910e-02, -5.169940487530262e-02, -5.163503990084393e-02, -5.153785954739958e-02, -5.138803087961256e-02, -5.115003234543364e-02, -5.075565811046869e-02, -5.006325203198896e-02, -4.876511639029797e-02, -4.638541819126862e-02, -4.387411038711349e-02, -4.253278797271683e-02, -3.998507039082674e-02, -3.394499090253084e-02, -1.955417575352915e-02, 1.783370709827418e-02, 1.015642278922317e-01, -1.134048550548069e+00, -1.775780465291345e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_lp96_b_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_lp96_b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.652002828278880e-06, -2.877296969249036e-06, -3.234880257349942e-06, -3.827396753915788e-06, -4.871824678644144e-06, -6.883748766172622e-06, -1.128572495377873e-05, -2.284122086609287e-05, -6.207578971602320e-05, -2.490496012937283e-04, -1.398769544094952e-03, -4.945245403275997e-03, -8.501149543381097e-03, -2.018662292295759e-02, -9.278227548144113e-02, -9.076607186170601e-01, -2.067520524760304e+01, -5.792786408673938e+02, 3.952385746315610e+06, 3.161073013470809e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
