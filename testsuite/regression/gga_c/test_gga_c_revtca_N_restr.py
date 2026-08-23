
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_revtca_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_revtca", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.669158052127241e-02, -6.615429797961922e-02, -6.535800655640304e-02, -6.416358513847266e-02, -6.234330682098267e-02, -5.951478328448221e-02, -5.503351573152970e-02, -4.789457495710336e-02, -3.708549002119867e-02, -2.396902232019780e-02, -1.757315792818473e-02, -4.358480008448775e-02, -4.907035052747823e-02, -3.567285694572971e-02, -1.831270073892317e-02, -4.979913474372822e-03, -5.148498206163363e-04, -1.575811835676905e-05, -1.006120700636313e-07, -7.537757067921012e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_revtca_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_revtca", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.848941503479616e-02, -9.888760023565203e-02, -9.945050558835333e-02, -1.002324048972053e-01, -1.012752105436911e-01, -1.025239886867682e-01, -1.035277611894987e-01, -1.025059130102417e-01, -9.441974798860969e-02, -7.331961746749992e-02, -5.786047227949159e-02, -8.047204253492099e-02, -7.083218595825697e-02, -7.279877673023818e-02, -5.339683120455593e-02, -1.883151781167228e-02, -2.182933127406529e-03, -6.882478171070950e-05, -4.421241021569149e-07, -3.316152767301952e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_revtca_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_revtca", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.258274338530972e-07, 3.575872295831660e-07, 4.083261316580441e-07, 4.930219458679057e-07, 6.432332537856600e-07, 9.322534886213046e-07, 1.549335324123401e-06, 3.034134409550364e-06, 7.028547976353935e-06, 1.928943030062197e-05, 1.034081664184423e-04, 2.593759004119525e-03, 5.991742574938354e-03, 1.204558893082084e-02, 3.023258821241134e-02, 6.853057121529714e-02, 1.037807942127440e-01, 1.086213143986787e-01, 8.400021494756361e-02, 4.887482854564915e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_revtca_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_revtca", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.830698979673578e-04, 1.939396947414972e-04, 2.096454474384580e-04, 2.317298208751062e-04, 2.598090138232320e-04, 2.809847411304913e-04, 2.163138087584049e-04, -3.533763363834411e-04, -3.480826353882918e-03, -1.686825901906374e-02, -6.161824728706214e-02, 1.307423775305820e-02, 3.401068662276623e-02, -2.270731598024061e-02, -8.897010097153170e-01, -3.942301987138382e+00, -7.047305100234305e+00, -7.185973746227427e+00, -5.253462189143777e+00, -2.919795260695821e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_revtca_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_revtca", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.064180258868834e-09, -2.332808525746801e-09, -2.768334025325100e-09, -3.501974476329085e-09, -4.777185043243143e-09, -6.905707818219487e-09, -8.582072369360673e-09, 1.525006407490130e-08, 4.115278325755658e-07, 6.518937380302409e-06, 1.567439678196653e-04, -2.004811945528030e-03, -1.886399229024706e-02, -6.601807399676298e-03, 7.225489880177579e-01, 1.933691489256260e+01, 4.382274158267718e+02, 1.471414079367434e+04, 1.292319084927417e+06, 5.569298311543747e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_revtca_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_revtca", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.968856596268967e-15, -1.324381681037686e-14, -1.982091552434779e-14, -3.503815941814068e-14, -7.799291758179440e-14, -2.378632069851378e-13, -1.105743102468834e-12, -8.859892206101292e-12, -1.377794828606581e-10, -4.740174726936385e-09, -6.889374154351436e-07, -3.640367651760341e-04, -1.393191696575053e-03, -2.970498674300966e-02, -1.319846919222376e+00, -1.494138053111835e+02, -3.973844414779982e+04, -4.348455264079954e+07, -4.590568181766304e+11, -1.534588539480879e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
