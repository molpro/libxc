
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hse_sol_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse_sol", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.262265255994068e+00, -3.199217360892475e+00, -3.110886690842242e+00, -2.988560356182583e+00, -2.821955003700441e+00, -2.600413962518094e+00, -2.315782910013178e+00, -1.967728198057303e+00, -1.571342568075074e+00, -1.162292113737428e+00, -7.819161411056290e-01, -5.456275955152891e-01, -4.852455532753576e-01, -3.963067329317704e-01, -2.822402810208959e-01, -1.779852168028297e-01, -1.002729229025323e-01, -4.035514669562733e-02, -8.760938724042265e-03, -9.701536869592900e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hse_sol_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse_sol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.234122154454172e+00, -4.147856459135423e+00, -4.026854946107499e+00, -3.858983444618179e+00, -3.629711105978179e+00, -3.323493771449767e+00, -2.927260679346749e+00, -2.437222593478731e+00, -1.871039986015219e+00, -1.291632196665334e+00, -8.435266072631513e-01, -7.145674607778748e-01, -6.393128652343067e-01, -5.192194499590173e-01, -3.520753240999499e-01, -1.906905344186994e-01, -1.057829748347701e-01, -5.087913091715246e-02, -1.165483780847746e-02, -1.293500964201154e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse_sol_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse_sol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.671149687750005e-07, -1.058914400312181e-06, -1.205609281875126e-06, -1.450936242758670e-06, -1.888650819177710e-06, -2.744554403188192e-06, -4.647383880490197e-06, -9.691954783025101e-06, -2.651039586041874e-05, -9.968084046283685e-05, -5.060643771836549e-04, 3.101128873659203e-04, 3.689681342218309e-03, 2.037197888939730e-03, -1.299725377246457e-02, -2.159875463395574e-01, -1.626056549035046e+00, -4.565605951341403e+00, -6.284231019060952e+00, -7.000206320360689e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse_sol_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.949743445227708e-03, -9.365555614658485e-03, -9.998873425002454e-03, -1.098814394196915e-02, -1.259085473697934e-02, -1.532773895256601e-02, -2.036630206032929e-02, -3.064634825551999e-02, -5.426887673208489e-02, -1.126432860424045e-01, -2.660551328663943e-01, -4.243638282951570e-01, -4.762710000117719e-01, -9.080233814789544e-01, -2.794004798293793e+00, -8.555114508434391e+00, 2.092022947682497e+01, -2.456439695328654e+02, -1.325603997347425e+04, -1.116417609642155e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse_sol_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.413575507036304e-08, 1.623752317914835e-08, 1.980980162387971e-08, 2.633897904420672e-08, 3.957819421269007e-08, 7.069258384207908e-08, 1.606611464452538e-07, 5.057138563451631e-07, 2.393327582071293e-06, 1.761692834695705e-05, 2.767206864983797e-04, 6.542988161810172e-03, 4.391118155034760e-03, 7.582519984663652e-02, 1.262729646141757e+00, 2.188761741722062e+01, -3.543868696995984e+03, -5.241200884994825e+05, -8.757129133218504e+07, -7.251592657355597e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse_sol_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.623190187003854e-14, -1.041148476630173e-13, -1.364108182873634e-13, -2.007879813465023e-13, -3.484550719052490e-13, -7.610441783006036e-13, -2.269368535968108e-12, -9.921195677526164e-12, -5.290109491618901e-11, 1.593121580119476e-09, 3.303361025186520e-07, -6.583039624304672e-04, -6.909804497780887e-03, -3.720526785790875e-02, -1.061980932200457e+00, 3.392394024383321e+00, 3.908649555790349e+05, 1.627193171679900e+09, 3.183074635905450e+13, 2.044390724270793e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
