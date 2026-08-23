
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pbe_gaussian_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_gaussian", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.416891531543371e-02, -6.312571035048789e-02, -6.163005399731515e-02, -5.948884672567737e-02, -5.643051816990240e-02, -5.208016981743768e-02, -4.594592297536381e-02, -3.748877699264275e-02, -2.658704718555260e-02, -1.530462393956229e-02, -1.128110762326384e-02, -4.304605593480931e-02, -5.250703026034514e-02, -3.667893881588487e-02, -1.931626833347508e-02, -5.203362888027463e-03, -3.654249580816270e-04, -4.114269333642240e-06, -4.159376677228533e-09, -1.334502390236811e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pbe_gaussian_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_gaussian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.322081253319655e-01, -1.312386859309578e-01, -1.298310083660175e-01, -1.277769392848316e-01, -1.247558895511467e-01, -1.202542155383883e-01, -1.133987233297168e-01, -1.026026729884304e-01, -8.509878626095299e-02, -5.967596814840693e-02, -4.736767840386081e-02, -8.869116864736994e-02, -8.266031092082046e-02, -7.911972921378885e-02, -6.027714602555902e-02, -2.417668051690885e-02, -2.167177990664187e-03, -2.628795428060871e-05, -2.717868601522655e-08, -8.828060636662100e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_gaussian_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_gaussian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.180722748169034e-07, 7.661564852778758e-07, 8.407566247276848e-07, 9.602879640927182e-07, 1.160692131236305e-06, 1.518450261816450e-06, 2.213409043547217e-06, 3.715799620892948e-06, 7.376943073341137e-06, 1.790453629046529e-05, 9.644383615665974e-05, 3.463030519163632e-03, 9.453224520979754e-03, 1.488365773147683e-02, 3.784903200755642e-02, 1.010323649578062e-01, 1.211748158894614e-01, 4.892608103266140e-02, 6.036339559718633e-03, 1.504842688641433e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_gaussian_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.862155360123550e-04, -3.095598508513638e-04, -3.465207314989502e-04, -4.075924988929988e-04, -5.149584027447843e-04, -7.215204171337891e-04, -1.174185885185414e-03, -2.362267747431071e-03, -6.207114289412619e-03, -2.003200870023859e-02, -6.905429121662982e-02, -2.502403674034953e-02, 9.688894918852362e-03, -7.381523817615770e-02, -9.085225507942185e-01, -6.010511368243710e+00, -1.044382634825699e+01, -4.380374218505121e+00, -5.262813699623479e-01, -1.283705063395600e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_gaussian_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.791020613374883e-09, 3.226624782777280e-09, 3.974316975740220e-09, 5.361707941078041e-09, 8.242956877820657e-09, 1.528551725737399e-08, 3.707214314095722e-08, 1.313845847807705e-07, 7.718466285350265e-07, 8.033183323879112e-06, 1.835472253040634e-04, 9.103089560105017e-04, -1.282792701733128e-02, 1.304767606184521e-02, 7.925681111022088e-01, 3.177182000940564e+01, 7.020988664285993e+02, 9.670064287114583e+03, 1.380672925712169e+05, 2.578449011285516e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_pbe_gaussian_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.914896072158288e-14, -1.205424151940449e-13, -1.596162153290151e-13, -2.388958657048274e-13, -4.261014505618212e-13, -9.763715873109245e-13, -3.195343411952592e-12, -1.730487969644632e-11, -1.884693269032085e-10, -5.254201091325939e-09, -7.536292427995049e-07, -7.538604381430960e-04, -7.510711552377379e-03, -4.391919455687761e-02, -1.580892226478413e+00, -2.453981913153079e+02, -6.116582258384296e+04, -2.711365844664163e+07, -4.600738157370654e+10, -6.592909232533315e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
