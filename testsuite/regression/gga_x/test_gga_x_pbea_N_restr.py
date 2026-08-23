
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbea_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbea", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.300849915292904e+00, -4.218994605856458e+00, -4.104388554705755e+00, -3.945824057551426e+00, -3.730160794595471e+00, -3.443953369166637e+00, -3.077222977459819e+00, -2.630026198024632e+00, -2.120240174095287e+00, -1.583810507610361e+00, -1.059089870539128e+00, -6.634065883413600e-01, -5.625608566535495e-01, -4.709526036462824e-01, -3.453973038682569e-01, -2.201844922199412e-01, -1.134061827753615e-01, -4.032407038642055e-02, -8.687912287680297e-03, -9.691758065124215e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbea_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbea", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.388707638301347e+00, -5.274770266114216e+00, -5.115084219811154e+00, -4.893828719098327e+00, -4.592290590000549e+00, -4.191060389898660e+00, -3.675546618036796e+00, -3.047143242244217e+00, -2.342808345167812e+00, -1.656168810531288e+00, -1.087429353433761e+00, -8.028904437749692e-01, -7.160024742278280e-01, -5.586409430373390e-01, -3.707950222901742e-01, -2.236892043310227e-01, -1.278147470457415e-01, -5.095299318166629e-02, -1.146407711713744e-02, -1.290857601805968e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbea_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbea", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.709926766068945e-06, -4.006697012132192e-06, -4.473809863042255e-06, -5.238061033082907e-06, -6.558885868954824e-06, -9.023810917047863e-06, -1.413691359525618e-05, -2.634582462348946e-05, -6.109077838809435e-05, -1.833278017842249e-04, -8.647965086368237e-04, -6.551987805809213e-03, -1.266061868534511e-02, -2.574513817643496e-02, -8.455351887358313e-02, -3.742461192945359e-01, -1.585827928861672e+00, -6.337486438386067e+00, -3.261922833669230e+01, -2.911050740871442e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbea_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbea", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.199618619924114e-02, -1.253320839700965e-02, -1.334568255953315e-02, -1.460122798893425e-02, -1.659896814328638e-02, -1.990290687999730e-02, -2.562466609177113e-02, -3.590026815319450e-02, -5.340261929084883e-02, -7.164542016577753e-02, -1.125177983651413e-01, -5.412858784931779e-01, -6.716800401893648e-01, -1.102493359393152e+00, -1.835824545991813e+00, 5.878635004184491e-01, 1.046182757822204e+01, -2.950081767191057e+02, -1.223952416304899e+04, -1.104800267686675e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbea_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbea", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.109700951678192e-08, 2.395020141896029e-08, 2.870437223263046e-08, 3.713120956109933e-08, 5.340020372113629e-08, 8.860394507263591e-08, 1.761338554678532e-07, 4.195288886605810e-07, 8.594975975357105e-07, -8.855813173002720e-06, -3.012439224790118e-04, 8.759289449444829e-03, 3.389178535512966e-02, 8.570022062962616e-02, -8.452301699793297e-03, -3.744557290198888e+01, -3.650147342116034e+03, -5.243603431158625e+05, -3.103384493115435e+08, -2.050860977354383e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbea_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbea", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.000211862797602e-14, 8.873561122442575e-14, 1.246958631191134e-13, 2.030285607266864e-13, 4.076420062632847e-13, 1.100937757763124e-12, 4.503820191621571e-12, 3.261821817324326e-11, 5.047047640231689e-10, 2.025025837618110e-08, 2.713944520600531e-06, 4.289948106039953e-04, 2.661274185186839e-03, 2.786900303111502e-02, 1.593503665764487e+00, 4.300415601300162e+02, 3.933969523560732e+05, 1.773193571456870e+09, 1.259545855824122e+14, 6.461869427900571e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
