
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_qtp17_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_qtp17", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.659143700827175e+00, -1.626932664084496e+00, -1.581774697280493e+00, -1.519172300481971e+00, -1.433768471281896e+00, -1.319890472983625e+00, -1.172871090410513e+00, -9.914596409391568e-01, -7.812925055872164e-01, -5.594058226859060e-01, -3.699759872312285e-01, -2.897033425724294e-01, -2.583036280256778e-01, -2.110710206825446e-01, -1.452726728210304e-01, -7.571217968438637e-02, -2.593051936198121e-02, -1.585098009068871e-02, -4.146174425638176e-03, -5.533886710770624e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_qtp17_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_qtp17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.193623018829897e+00, -2.150946366332270e+00, -2.091140319318387e+00, -2.008283499699718e+00, -1.895363371952110e+00, -1.745057319240696e+00, -1.551630311322397e+00, -1.314512225936965e+00, -1.043918436902083e+00, -7.681944288503484e-01, -5.317526660368709e-01, -3.828510080978925e-01, -3.371335553366163e-01, -2.820615962806891e-01, -2.095053877603366e-01, -1.403318199747419e-01, -7.270311399291499e-02, -2.065110522811780e-02, -5.376657866411363e-03, -7.267082111103982e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_qtp17_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_qtp17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.248806835934353e-08, 4.713378855095118e-08, 5.471304931803493e-08, 6.778007426013448e-08, 9.217037755894699e-08, 1.432058187860873e-07, 2.690595811659151e-07, 6.618814316290696e-07, 2.373887036688615e-06, 1.397160470250802e-05, 1.243294671407057e-04, 6.010381934346012e-04, 1.170388390703472e-03, 3.338337479378990e-03, 1.994421545026234e-02, 2.340409022143808e-01, 3.388055780279044e+00, 4.195919036226310e+00, 5.948260131477414e-10, 1.507802420748357e-139]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_qtp17_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_qtp17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.903903083125311e-03, -4.064467203142965e-03, -4.306508495898232e-03, -4.678803069912984e-03, -5.268027883458139e-03, -6.238605639254711e-03, -7.926973713223750e-03, -1.107463462687180e-02, -1.733334270644967e-02, -2.889740273447736e-02, -4.581232483450192e-02, -1.612606893727516e-01, -2.276496660864672e-01, -3.144259640762274e-01, -4.216655517542562e-01, 1.049896921307752e+00, 4.722801908588094e+00, -2.112585199912304e+02, -5.556377945583979e+03, -5.860997169229697e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_qtp17_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_qtp17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.020967759019121e-10, -4.743009211503824e-10, -6.013269207638370e-10, -8.454914526283841e-10, -1.378722190590223e-09, -2.778713137440726e-09, -7.573352856618702e-09, -3.165867522144502e-08, -2.406200850981665e-07, -4.009936252285814e-06, -1.290768448772574e-04, -1.587536371362165e-03, -4.604175099690885e-03, -2.472238591571388e-02, -4.455446113041241e-01, -2.617730838174920e+01, -2.757559255549559e+03, 1.310579389552472e+05, 2.324133126238451e-02, 4.463449433022620e-128]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_qtp17_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_qtp17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
