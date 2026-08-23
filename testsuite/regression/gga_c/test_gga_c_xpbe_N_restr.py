
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_xpbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_xpbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.976383823409296e-02, -6.883349962707391e-02, -6.749865992302295e-02, -6.558525708115280e-02, -6.284605791799805e-02, -5.893222818462834e-02, -5.336039221287503e-02, -4.550332648540615e-02, -3.478418953569744e-02, -2.208286592967567e-02, -1.549145398896309e-02, -4.198852384457978e-02, -5.069096806298978e-02, -3.533037354824645e-02, -1.876363376831348e-02, -4.811110435675968e-03, -2.783089231956542e-04, -2.574878946394490e-06, -2.366828925632343e-09, -7.395215219542492e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_xpbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_xpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.225187932234312e-01, -1.216433068005898e-01, -1.203832940264372e-01, -1.185689057229175e-01, -1.159534082308254e-01, -1.121746438031282e-01, -1.066890749365687e-01, -9.863973727708171e-02, -8.654762193778151e-02, -6.834109292487349e-02, -5.499655227448044e-02, -8.329152260181463e-02, -8.135057701983947e-02, -7.454679562948442e-02, -5.629774828717192e-02, -2.236205851455956e-02, -1.679126663845620e-03, -1.656608480971312e-05, -1.548884866199159e-08, -4.893032676215216e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_xpbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_xpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.288543740101452e-07, 5.642139316893743e-07, 6.191879418267562e-07, 7.075841273193794e-07, 8.567152856626813e-07, 1.126080987249977e-06, 1.661850471254596e-06, 2.880872160031064e-06, 6.207600570523614e-06, 1.780167220506297e-05, 1.011503880250336e-04, 3.055910922789607e-03, 9.664439335511974e-03, 1.347440235657367e-02, 3.382661486361382e-02, 9.146245980621956e-02, 9.287509834030312e-02, 3.067755560267448e-02, 3.435348958817806e-03, 8.339183151712256e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_xpbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_xpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.456016076930416e-04, -2.625791717405018e-04, -2.890357979056855e-04, -3.317476345525677e-04, -4.043305646168410e-04, -5.372824283005011e-04, -8.095697804176040e-04, -1.471659370161502e-03, -3.583267975039556e-03, -1.306189289618750e-02, -5.311974136635297e-02, -3.683460495357650e-02, -9.697098016686067e-03, -1.050609984102510e-01, -8.003321705076235e-01, -5.507118434666380e+00, -8.291975930542719e+00, -2.785949362837253e+00, -3.004924187451372e-01, -7.116701828617300e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_xpbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_xpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.335182875870002e-09, 2.663862243821256e-09, 3.218635488529954e-09, 4.223215935532496e-09, 6.236475902677199e-09, 1.090945224194524e-08, 2.435011480513987e-08, 7.755052496919488e-08, 4.213791193897109e-07, 4.974043351354446e-06, 1.348738737265766e-04, 2.059108663220228e-03, -4.544670163024434e-03, 2.715634354510113e-02, 6.871161956084187e-01, 2.851223583190706e+01, 5.494120081501364e+02, 6.110168315881794e+03, 7.869798545639853e+04, 1.429133119648622e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_xpbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_xpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.685837597260829e-14, -9.305149099412020e-14, -1.224744872675014e-13, -1.817265017256926e-13, -3.201235942981040e-13, -7.205642465979770e-13, -2.299968233064031e-12, -1.207702947605942e-11, -1.297533890644517e-10, -3.974739063631584e-09, -6.287673733938010e-07, -7.858145091190025e-04, -1.134365539654381e-02, -4.660018216424982e-02, -1.399418751394612e+00, -2.188041643783401e+02, -4.721900835999623e+04, -1.703329200300737e+07, -2.618685551864304e+10, -3.653511296111607e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
