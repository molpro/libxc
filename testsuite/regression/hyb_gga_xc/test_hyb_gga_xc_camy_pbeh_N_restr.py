
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_camy_pbeh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_pbeh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.195348837009030e-01, -3.186246579876806e-01, -3.173515368795159e-01, -3.155972648437572e-01, -3.132400759749541e-01, -3.102145461332754e-01, -3.066795265350298e-01, -3.034210618950333e-01, -3.024136095524952e-01, -3.044343959611133e-01, -2.895568961033561e-01, -2.460329652944595e-01, -2.400096375808976e-01, -2.203751453430106e-01, -1.927027106120606e-01, -1.531325369091127e-01, -9.245889609932005e-02, -3.334146100883026e-02, -7.014093136243143e-03, -7.761273855648321e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_camy_pbeh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_pbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.746708156123819e-01, -3.722312535551334e-01, -3.686574673667525e-01, -3.633846065396572e-01, -3.555335806495855e-01, -3.437240148552839e-01, -3.258419346991995e-01, -2.991548660484631e-01, -2.631139236807539e-01, -2.309518557578523e-01, -2.173461180766589e-01, -2.761639827090250e-01, -2.755685118381704e-01, -2.478296019559551e-01, -1.971514950412936e-01, -1.416542550396741e-01, -1.025852661449640e-01, -4.332087803950024e-02, -9.340675644696183e-03, -1.034820267211902e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_pbeh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_pbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.649064413467955e-07, 5.833568641171290e-07, 6.084840628501460e-07, 6.403395441252244e-07, 6.722446091244673e-07, 6.692327178916166e-07, 4.755348724887221e-07, -6.258174328642444e-07, -6.233161205666471e-06, -3.588966923507007e-05, -2.508840507902990e-04, 6.533310735683854e-04, 4.075876823878973e-03, 8.077612565227394e-04, -2.353684770339847e-02, -2.466708657139195e-01, -1.210301838498618e+00, -2.309203213961870e+00, -2.851052382789431e+00, -3.156025673062763e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_pbeh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.709751142485021e-04, -8.411738659135834e-04, -9.522532487606431e-04, -1.135119996140873e-03, -1.452955512525027e-03, -2.046398656400955e-03, -3.254502872548778e-03, -5.906953086050762e-03, -1.131331650177884e-02, -1.269332897234343e-02, -1.849386177711651e-02, -1.254954210650553e-01, -8.533988935973130e-02, -3.534720619827149e-01, -1.494781749892341e+00, -1.746624508262581e+00, 1.938389107085145e+01, -3.206375668503703e+02, -1.074814348899044e+04, -8.932811276391417e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_pbeh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.749949878775912e-09, 9.038752889472510e-09, 1.125916718416484e-08, 1.539093890086698e-08, 2.395913179227377e-08, 4.460461585822581e-08, 1.054591028853107e-07, 3.357305193550294e-07, 1.424522471912711e-06, 4.798466674119304e-06, 3.398017871259081e-05, 7.346596378947578e-03, 8.188967216584986e-03, 9.155688318891547e-02, 1.146578061931647e+00, -4.416108399567698e-01, -3.301067695698699e+03, -2.729982351266314e+05, -3.980777543706658e+07, -3.269644955333051e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_pbeh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.332451743314595e-13, -1.618902165224005e-13, -2.139978078483298e-13, -3.189303470806534e-13, -5.630608802725209e-13, -1.258550979875923e-12, -3.869233213847303e-12, -1.766711783714322e-11, -1.072007556155696e-10, 1.957327889541944e-09, 5.654339932693136e-07, -7.043157540084085e-04, -7.696087010937911e-03, -3.607440869578918e-02, -6.538619858360150e-01, 1.517351222682018e+02, 3.344146137923566e+05, 8.301640181543711e+08, 1.446139034304883e+13, 9.217679691129106e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
