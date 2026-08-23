
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pw91_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pw91", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.027535286241969e-02, -6.929888353261002e-02, -6.789761479684679e-02, -6.588856648755870e-02, -6.301184198923504e-02, -5.890134296704485e-02, -5.305354467124094e-02, -4.483407988691950e-02, -3.375014273456596e-02, -2.107325768127762e-02, -1.533835303091561e-02, -4.462142944888311e-02, -5.294945340684370e-02, -3.798433154585116e-02, -2.105059596764884e-02, -6.018973391959509e-03, -4.156174558965701e-04, -4.358736228726109e-06, -4.220997557021835e-09, -1.337038510558914e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pw91_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.290134443130434e-01, -1.281322121114686e-01, -1.268603053996102e-01, -1.250210611918590e-01, -1.223528609394973e-01, -1.184598085206534e-01, -1.127179624275418e-01, -1.040696181542310e-01, -9.057128981393937e-02, -6.990129697212825e-02, -5.667207599568184e-02, -8.655267963967246e-02, -8.158072655125398e-02, -7.741736821854682e-02, -6.087992944207461e-02, -2.679919117739418e-02, -2.457827391120472e-03, -2.790867970363025e-05, -2.759985076928055e-08, -8.845639755464466e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pw91_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.025200953294758e-07, 6.432366680439294e-07, 7.065492316718672e-07, 8.083644906553267e-07, 9.801132356294081e-07, 1.290063563271769e-06, 1.904717228976290e-06, 3.290816479414945e-06, 6.982176261634430e-06, 1.923974924354125e-05, 1.081226808358400e-04, 3.114179881696946e-03, 8.802846780089925e-03, 1.356329315499820e-02, 3.620911521302637e-02, 1.093668087318528e-01, 1.363820231142945e-01, 5.180426456103174e-02, 6.125717533143907e-03, 1.507701471105938e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pw91_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.448553741385218e-04, -2.629844663402703e-04, -2.913952555294276e-04, -3.376538325001875e-04, -4.172836514634240e-04, -5.660328575727904e-04, -8.798916405288626e-04, -1.676274108318878e-03, -4.321272247286506e-03, -1.580369620074066e-02, -6.065731555952627e-02, -2.461219408628659e-02, 3.074624849416552e-03, -6.897269305585496e-02, -7.414772910913499e-01, -6.021900443145964e+00, -1.174294713741869e+01, -4.661513358244869e+00, -5.348778281866530e-01, -1.286405912468028e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pw91_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.318606058340456e-09, 2.660088067058250e-09, 3.240335604770420e-09, 4.301422339762728e-09, 6.459037103062668e-09, 1.157659504919661e-08, 2.678136172924152e-08, 8.987051612606736e-08, 5.195170551348396e-07, 6.161735702783050e-06, 1.572849979561333e-04, 9.317672083364625e-04, -9.961592010637314e-03, 1.185948358127498e-02, 6.262158802508395e-01, 3.140473646555670e+01, 7.836545027041598e+02, 1.025798573844092e+04, 1.402051681960053e+05, 2.583583007264326e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_pw91_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.328217156988091e-14, -1.010443418760019e-13, -1.333989690731871e-13, -1.987904232604840e-13, -3.523287579106584e-13, -7.999672001850541e-13, -2.585152006080124e-12, -1.381105299552565e-11, -1.513470502938370e-10, -4.618954858940711e-09, -7.098191325802729e-07, -6.931613926257728e-04, -7.859287169382181e-03, -4.034193010020393e-02, -1.387280750478234e+00, -2.482694786975283e+02, -6.809484929013567e+04, -2.869251694013468e+07, -4.668821572382851e+10, -6.605433818750136e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
