
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_vt84f_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vt84f", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.084445650896034e+02, 1.050834636442434e+02, 1.005025073934039e+02, 9.440280016250128e+01, 8.654312285467851e+01, 7.686062561713631e+01, 6.559042572454013e+01, 5.317252770782826e+01, 3.970280347121964e+01, 2.599749627536908e+01, 1.298505952527831e+01, 2.908666479983190e+00, 1.770853373490600e+00, 1.574268607068454e+00, 1.135379109980992e+00, 7.976770885669811e-01, 7.060253806660484e-01, 6.463474327079609e-01, 6.027861610426277e-01, 5.742321716955459e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_vt84f_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vt84f", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.127413509835382e+02, 1.064646354484549e+02, 9.794510251935540e+01, 8.669763931706741e+01, 7.247709256407977e+01, 5.573745741136069e+01, 3.845475751366893e+01, 2.503246784500226e+01, 1.911992050035342e+01, 5.278373456445713e+00, -2.597119656935833e+00, 1.974119673988448e+00, 2.196012433416286e+00, 8.631108571325478e-01, 5.161625136578192e-01, -5.729336698691873e-01, -6.958664393769697e-01, -6.462313573190773e-01, -6.027859323783517e-01, -5.742321716596702e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vt84f_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vt84f", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.296225516060069e-04, 7.849185133249369e-04, 8.706340478079478e-04, 1.007483588611623e-03, 1.234534613003739e-03, 1.628915106711647e-03, 2.343795152755122e-03, 3.645432888382510e-03, 5.936668954320750e-03, 1.531188726600190e-02, 6.455903472173415e-02, 2.305913631654052e-01, 2.806434846893168e-01, 6.541328041987285e-01, 1.296679216546788e+00, 1.018690683708837e+01, 1.269405092958654e+02, 3.883651175804338e+03, 4.376503704821917e+05, 3.237673133714289e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vt84f_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vt84f", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.117068767045848e+00, 1.149900200077342e+00, 1.195599715020202e+00, 1.256375153672032e+00, 1.327037329796460e+00, 1.369553403920233e+00, 1.216412258750122e+00, 2.974801411840806e-01, -1.155922978508061e+00, 1.450181870809520e+01, 3.277678642839278e+01, 6.793115701262622e+00, 7.578617243446417e+00, 6.793258688360959e+00, 1.333355870167970e+01, 1.672221000515827e+02, 1.461998461158744e+03, 4.017277510029286e+04, 4.220955555521458e+06, 2.974681719952594e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vt84f_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vt84f", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.482739462718891e-06, -8.327052767088467e-06, -9.666874813803419e-06, -1.185581222678176e-05, -1.550147578412563e-05, -2.126907883293204e-05, -2.618412098201024e-05, 9.867994562055725e-06, 2.417981559267389e-04, -5.595406781401947e-03, -9.016971055349814e-02, -3.745846422388184e-01, -1.492756957463908e+00, -1.522990605140556e+00, -7.724176962221514e+00, -1.071130251587386e+03, -1.311308160434130e+05, -1.206877063787053e+08, -1.532303464526605e+12, -8.386021857242405e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vt84f_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vt84f", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.657371610088126e-11, 4.191730270405412e-11, 5.035675854582520e-11, 6.340878698442687e-11, 7.944605622209707e-11, 5.969671191909805e-11, -4.183685348768492e-10, -6.446644351406347e-09, -7.519717294675880e-08, 1.206354764605016e-06, 1.331336273945276e-04, 1.815446788612696e-04, 3.010044440635684e-01, -5.719819484732679e-01, -1.095821193976353e+01, 1.049868305065054e+03, 1.267655171990238e+05, 4.883409156629776e+07, 1.582614297386548e+11, 1.107758353543054e+16]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
