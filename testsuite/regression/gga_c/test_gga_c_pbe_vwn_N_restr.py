
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pbe_vwn_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_vwn", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.464416414829147e-02, -6.360277624813063e-02, -6.210956024404269e-02, -5.997148083932354e-02, -5.691678609028042e-02, -5.256963801297848e-02, -4.643504620733258e-02, -3.796489560260953e-02, -2.701427832417483e-02, -1.561766966918882e-02, -1.150835766079110e-02, -4.338564802669011e-02, -5.281134098168271e-02, -3.690421490998378e-02, -1.940048770970967e-02, -5.186030331717575e-03, -3.619941537667944e-04, -4.133514078016835e-06, -4.140097491022920e-09, -1.247445162397551e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pbe_vwn_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_vwn", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.326852123701761e-01, -1.317216287054229e-01, -1.303226136090840e-01, -1.282815349930572e-01, -1.252803710756774e-01, -1.208100696454879e-01, -1.140060250352637e-01, -1.032963175895026e-01, -8.591997555014916e-02, -6.055384893933421e-02, -4.812127660959888e-02, -8.917398759998674e-02, -8.307634938234824e-02, -7.949667546028266e-02, -6.052581430036603e-02, -2.413263434016220e-02, -2.146841080028997e-03, -2.639463869710035e-05, -2.708395089036827e-08, -8.263117873756924e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_vwn_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_vwn", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.185269654311551e-07, 7.666780901894909e-07, 8.413912408045157e-07, 9.611269825528597e-07, 1.161938242419093e-06, 1.520622814686071e-06, 2.218102799429979e-06, 3.729064592986069e-06, 7.426639293779818e-06, 1.812588927118725e-05, 9.776231614605365e-05, 3.466825886988399e-03, 9.455202073214177e-03, 1.489978165445462e-02, 3.792404995999778e-02, 1.007662962640069e-01, 1.200813087501711e-01, 4.915400960103631e-02, 6.008365928129896e-03, 1.406673458171275e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_vwn_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_vwn", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.849616932480884e-04, -3.081615025949602e-04, -3.448849805299520e-04, -4.055441147441693e-04, -5.121345906113243e-04, -7.170800026259081e-04, -1.165930736977876e-03, -2.344137855365784e-03, -6.169156795573887e-03, -2.005329068872787e-02, -6.943917578758015e-02, -2.488061707977265e-02, 9.528578781537816e-03, -7.370313448936644e-02, -9.103355939246485e-01, -6.015460162629811e+00, -1.034884678634536e+01, -4.394662322401395e+00, -5.251381037454831e-01, -1.203459593804632e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_vwn_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_vwn", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.780795635961426e-09, 3.214270610396044e-09, 3.958130042793803e-09, 5.337928702264821e-09, 8.201977671444310e-09, 1.519768292771842e-08, 3.682181319701965e-08, 1.303932847810092e-07, 7.670927080433512e-07, 8.038990587794150e-06, 1.844071262726412e-04, 8.863437840789488e-04, -1.285403271520964e-02, 1.277953697157751e-02, 7.917247192130560e-01, 3.175297793753433e+01, 6.959013820307299e+02, 9.709044074790498e+03, 1.375862217010992e+05, 2.413444439293639e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_pbe_vwn_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_vwn", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.908533303542474e-14, -1.204610347119745e-13, -1.595005438353554e-13, -2.387050564002323e-13, -4.257141700482545e-13, -9.753303341818127e-13, -3.191344837786803e-12, -1.728333755640441e-11, -1.884775468189580e-10, -5.280506327593851e-09, -7.591879326406254e-07, -7.525419004434529e-04, -7.502865266258513e-03, -4.384829990755826e-02, -1.580691149249540e+00, -2.449359584078800e+02, -6.063747242382263e+04, -2.723945056545214e+07, -4.579421586374697e+10, -6.162818398610045e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
