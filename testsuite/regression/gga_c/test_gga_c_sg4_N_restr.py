
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_sg4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sg4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.947516528407166e-02, -5.840629748022083e-02, -5.687339736576551e-02, -5.467789898220429e-02, -5.153994424395810e-02, -4.707206528599939e-02, -4.076471622598344e-02, -3.206557213710518e-02, -2.091951864531290e-02, -9.765761232321023e-03, -5.345419445458976e-03, -3.595252527251186e-02, -4.871318606294425e-02, -2.834155503362508e-02, -9.330297497321038e-03, -1.208418108452408e-03, -4.058429472243374e-05, -2.016495650771765e-07, -5.991580442384640e-11, -2.713578795884794e-16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_sg4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sg4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.294425461060997e-01, -1.284232498378190e-01, -1.269415386531312e-01, -1.247753698444260e-01, -1.215788239136753e-01, -1.167862836750931e-01, -1.094015963350431e-01, -9.750786573710145e-02, -7.748019098891096e-02, -4.732954364051943e-02, -3.064784086622968e-02, -9.257950562331031e-02, -8.760911548757576e-02, -8.262352484947962e-02, -4.546533532524624e-02, -8.070597385875185e-03, -3.106958532644745e-04, -1.644474416993148e-06, -5.115997841484473e-10, -2.394462680112244e-15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sg4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sg4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.393487143788806e-07, 7.883981873408589e-07, 8.644140595210385e-07, 9.860057271345621e-07, 1.189282770867668e-06, 1.550306538467428e-06, 2.244355885748777e-06, 3.708181173691750e-06, 7.030368175184375e-06, 1.473947646552150e-05, 6.496197534923563e-05, 4.313010820273111e-03, 1.278489136559287e-02, 1.932199551279361e-02, 3.396780695810970e-02, 3.774874118954901e-02, 1.878101675564758e-02, 3.312424805170620e-03, 1.243155983075633e-04, 4.508247673288615e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sg4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sg4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.203207300410009e-04, -3.464671724100213e-04, -3.879451298016247e-04, -4.566932849690942e-04, -5.781672331521211e-04, -8.138369729567081e-04, -1.337365902967251e-03, -2.738174368155297e-03, -7.318000712702425e-03, -2.252337698304134e-02, -7.248586122056562e-02, -4.488530458077833e-02, 2.572490313678002e-02, -1.905077929254954e-01, -1.788128320269624e+00, -3.585000659415411e+00, -2.055100693797737e+00, -3.618193499439440e-01, -1.342991964511637e-02, -4.842221833199789e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sg4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sg4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.208124184125937e-09, 3.706671452300721e-09, 4.562887792002145e-09, 6.153469989424622e-09, 9.464289332601096e-09, 1.759356680203923e-08, 4.295471793714276e-08, 1.541606162386971e-07, 9.126643267379989e-07, 8.906133253074496e-06, 1.872708761976409e-04, 2.718813041054760e-03, -1.832822574102820e-02, 5.798893153433930e-02, 1.652267641849204e+00, 1.965776646395857e+01, 1.427210152313191e+02, 8.300501903876633e+02, 3.694714136094404e+03, 1.028040026403754e+04]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_sg4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sg4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.062505025080014e-13, -1.291590603394792e-13, -1.710059520140006e-13, -2.559391149601334e-13, -4.566341491913319e-13, -1.047419146909915e-12, -3.436486949017377e-12, -1.868500537833778e-11, -2.024580810276974e-10, -5.215792990313517e-09, -6.668318024468221e-07, -1.107699221297487e-03, -1.065803649836561e-02, -7.460122023313792e-02, -2.333136682614564e+00, -1.362150757828911e+02, -1.203266878025351e+04, -2.285368182001609e+06, -1.212326290576019e+09, -2.592705816516678e+12]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
