
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_b86_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.314139316157052e+00, -4.232632644557178e+00, -4.118546166183647e+00, -3.960768656886043e+00, -3.746326084852293e+00, -3.462078117424996e+00, -3.098645546992478e+00, -2.657321197315835e+00, -2.158285403130772e+00, -1.637717014840288e+00, -1.106449433273681e+00, -6.672122614471472e-01, -5.637590233228125e-01, -4.745614226190398e-01, -3.539584125122195e-01, -2.364323477303017e-01, -1.290462459917068e-01, -4.553580062385060e-02, -9.561468906520942e-03, -1.057923578529239e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_b86_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.364270174306240e+00, -5.249543704893503e+00, -5.088677739784591e+00, -4.865628330298101e+00, -4.561299068911459e+00, -4.155591588277506e+00, -3.632639345941452e+00, -2.991618857019840e+00, -2.267515730048069e+00, -1.564557478662377e+00, -1.017224701700327e+00, -7.953828933363114e-01, -7.139076736679871e-01, -5.513704494948027e-01, -3.547607647161874e-01, -2.096461743513034e-01, -1.399502635005471e-01, -5.895700175089188e-02, -1.273090693929225e-02, -1.410539559507468e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.162259687714864e-06, -4.502860919451319e-06, -5.040596840566380e-06, -5.924448810240937e-06, -7.462838107087976e-06, -1.036620665455099e-05, -1.650082109612839e-05, -3.161533619046237e-05, -7.699118251489512e-05, -2.491159163509960e-04, -1.219969387522973e-03, -7.561589608804229e-03, -1.403237162190482e-02, -3.023399571401336e-02, -1.104177047807742e-01, -5.654483316246720e-01, -2.176808035671145e+00, -3.960090384766497e+00, -4.824103952089989e+00, -5.330669033303066e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.243895048589001e-02, -1.302011449583239e-02, -1.390361391424496e-02, -1.527906803722050e-02, -1.749341125065359e-02, -2.122689982608717e-02, -2.791197500431049e-02, -4.067668570842411e-02, -6.515243632265130e-02, -9.673454669932109e-02, -1.523732811606300e-01, -5.807561402646062e-01, -6.878044633052026e-01, -1.211056346686084e+00, -2.361128805953125e+00, 2.535345136430363e+00, 4.554493705180061e+01, -4.008982527915252e+02, -1.461015767525316e+04, -1.217569740352546e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.633583442769481e-08, 3.008586630886117e-08, 3.640186102462658e-08, 4.778469998310910e-08, 7.035432295725917e-08, 1.214489278195210e-07, 2.596248633769155e-07, 7.232119816490066e-07, 2.530942561358405e-06, 3.324847951351245e-06, -1.562947623451192e-04, 1.225074347119384e-02, 4.051310525700147e-02, 1.302495513524235e-01, 5.616896000105024e-01, -4.572072421272383e+01, -6.307637151549116e+03, -4.725448627964584e+05, -6.743326212918074e+07, -5.522734601157124e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.992532921549689e-14, 6.349439282624395e-14, 8.966505338163588e-14, 1.470856169769362e-13, 2.987673181909242e-13, 8.220725073335562e-13, 3.469585508984004e-12, 2.654308760642135e-11, 4.533996648268438e-10, 2.133675892658690e-08, 3.112974702228398e-06, 3.232400787457067e-04, 1.853951599041555e-03, 2.172848814105615e-02, 1.541283923882294e+00, 5.916193501907844e+02, 6.279387536678907e+05, 1.434501595059911e+09, 2.449138568419296e+13, 1.556941483454622e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
