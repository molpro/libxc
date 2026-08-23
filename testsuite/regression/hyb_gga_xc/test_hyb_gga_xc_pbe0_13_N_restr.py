
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbe0_13_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe0_13", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.933146494592438e+00, -2.877627070818269e+00, -2.799870445492925e+00, -2.692242685353254e+00, -2.545768839080443e+00, -2.351222175393794e+00, -2.101694621050766e+00, -1.797209701788676e+00, -1.450624836094656e+00, -1.088372289467477e+00, -7.330790478265627e-01, -4.860117997371296e-01, -4.276721782837793e-01, -3.513963224237335e-01, -2.521484428966959e-01, -1.576267715234023e-01, -8.088779954070849e-02, -2.792196747882209e-02, -5.846299005526606e-03, -6.467744715372539e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbe0_13_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe0_13", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.718270675451144e+00, -3.641019641398965e+00, -3.532666123270924e+00, -3.382355361698011e+00, -3.177115747430408e+00, -2.903169018540014e+00, -2.549295751946004e+00, -2.113737033491925e+00, -1.617361717983147e+00, -1.126496079659608e+00, -7.438980527405501e-01, -6.215399150603911e-01, -5.595274551068872e-01, -4.490417850135008e-01, -3.010118279229933e-01, -1.680777397399437e-01, -9.290684939474168e-02, -3.637728301156923e-02, -7.786342119800488e-03, -8.623535232451967e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe0_13_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe0_13", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.848934555437101e-06, -2.009937292710382e-06, -2.265228877199142e-06, -2.687397863330103e-06, -3.428424337455967e-06, -4.843090792996468e-06, -7.877868377647668e-06, -1.549844566588802e-05, -3.886004195738217e-05, -1.285459618234038e-04, -6.116787201943259e-04, -1.172790284925631e-03, 7.773053691952497e-04, -3.581520760191161e-03, -2.783421122876679e-02, -2.166671836204252e-01, -1.005719312574407e+00, -1.917845869971571e+00, -2.374900672426758e+00, -2.629996379405491e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe0_13_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe0_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.443113354596798e-03, -8.842270759922883e-03, -9.449781432747264e-03, -1.039728090993367e-02, -1.192716163497135e-02, -1.451984677648822e-02, -1.920787157012074e-02, -2.835444191831015e-02, -4.695904572579945e-02, -7.812317857621781e-02, -1.579532465014417e-01, -4.018763937428710e-01, -4.433304251918608e-01, -8.544047079465553e-01, -2.359589169638895e+00, -4.555500311951283e+00, 8.645850391250539e+00, -2.762475693189169e+02, -8.965418876922851e+03, -7.444094903827105e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe0_13_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe0_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.869446164697959e-08, 2.137145731262754e-08, 2.588599389459490e-08, 3.403916879415012e-08, 5.026274854115155e-08, 8.723304373379897e-08, 1.885779775001395e-07, 5.400041851507963e-07, 2.068961881105787e-06, 7.133802887566536e-06, 3.541272562589828e-05, 8.137473312064217e-03, 1.185142918848766e-02, 8.857285824352321e-02, 1.031293845497647e+00, 1.916653889759608e+00, -2.679844719582496e+03, -2.260584883113910e+05, -3.315051189227618e+07, -2.724661219255023e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe0_13_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe0_13", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.472336639279017e-14, -7.678346753883253e-14, -9.786981382727468e-14, -1.377296321352302e-13, -2.209944368232692e-13, -4.137295981973779e-13, -8.329883298468437e-13, 5.989056282769639e-13, 1.119359947823127e-10, 8.437734044478478e-09, 1.206194027282241e-06, -5.329425898434106e-04, -6.227317066589115e-03, -2.915367214240971e-02, -5.741475037619428e-01, 1.093175881251218e+02, 2.718104185838259e+05, 6.876724650270627e+08, 1.204359327275209e+13, 7.681289995013565e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
