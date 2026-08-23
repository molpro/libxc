
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_cam_pbeh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_pbeh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.751848680155873e-01, -3.740995721081188e-01, -3.725439094113581e-01, -3.703177216855213e-01, -3.671405616994797e-01, -3.626281537588595e-01, -3.562833385515228e-01, -3.475664289957705e-01, -3.361965256244515e-01, -3.231069326137598e-01, -3.111540682206374e-01, -3.027101682782661e-01, -2.951049491524707e-01, -2.713206753812632e-01, -2.318372275185258e-01, -1.706702941401398e-01, -9.546214107220118e-02, -3.346386706963392e-02, -7.015191704799841e-03, -7.761288707540340e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_cam_pbeh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_pbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.376648246334784e-01, -4.365202330811003e-01, -4.348582017909973e-01, -4.324332324100567e-01, -4.288682155996243e-01, -4.235635995802504e-01, -4.155290374065622e-01, -4.031963555273552e-01, -3.852124930158929e-01, -3.591930802278636e-01, -3.391526081137238e-01, -3.400835823156755e-01, -3.349121931160603e-01, -3.076370537247555e-01, -2.532138395206984e-01, -1.751649137740713e-01, -1.082111936237127e-01, -4.356376936487875e-02, -9.342872544270043e-03, -1.034823237589458e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_pbeh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_pbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.300644075843620e-07, 6.705086408109313e-07, 7.329823264558262e-07, 8.324251920013415e-07, 9.974537752892231e-07, 1.287262309409189e-06, 1.835035722343783e-06, 2.970057687883384e-06, 5.676409341930500e-06, 1.248017708993618e-05, 4.822456424140669e-05, 9.919320250141028e-04, 3.639456250609526e-03, 1.345615810824340e-03, -1.725198477934994e-02, -2.063416405607509e-01, -1.199723211757492e+00, -2.310961597403297e+00, -2.851088046006643e+00, -3.156025753726254e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_pbeh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.757948711341925e-04, -2.969726791693181e-04, -3.303697841299826e-04, -3.852628958012632e-04, -4.810981588776121e-04, -6.635302728094332e-04, -1.052641963341784e-03, -1.962586513351835e-03, -4.086501008957479e-03, -1.397509555627068e-02, -3.098459477192897e-02, -9.414052919123859e-02, -8.263813099187106e-02, -3.158821175107387e-01, -1.114512297048879e+00, -3.126785001067597e+00, 1.408319124052404e+01, -3.279948234805076e+02, -1.075583229943985e+04, -8.932888213207901e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_pbeh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.420236668394586e-09, 2.782025938266818e-09, 3.399523170092011e-09, 4.536737177863895e-09, 6.875482594859847e-09, 1.251737026795245e-08, 2.953267960471225e-08, 9.644283565120983e-08, 4.369700985385787e-07, 4.985637700836692e-06, 5.821623922897234e-05, 4.302162378360918e-03, 5.329691927264809e-03, 6.524637506428507e-02, 5.574552735241890e-01, -1.855358814391511e+00, -3.250385693436667e+03, -2.731631780073690e+05, -3.980822740721837e+07, -3.269645034807340e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_pbeh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.450750785878791e-14, -1.023051390893455e-13, -1.346350686215744e-13, -1.997171590401921e-13, -3.516482190249139e-13, -7.906935655868027e-13, -2.511837009841245e-12, -1.275333475156412e-11, -1.179521652898656e-10, -3.220101144796686e-09, -2.415716072225909e-07, -4.806673598708055e-04, -5.740784503685229e-03, -2.496135876949042e-02, -1.070467166648654e-01, 1.547746627523378e+02, 3.315533584716102e+05, 8.305458921220286e+08, 1.446151342042011e+13, 9.217679859165552e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
