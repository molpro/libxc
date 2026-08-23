
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b3p86_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.529018319693194e+00, -3.462517355542274e+00, -3.369368458122320e+00, -3.240408457199668e+00, -3.064843188028737e+00, -2.831521673099120e+00, -2.531950351780188e+00, -2.165714863521326e+00, -1.747652987080375e+00, -1.310532693614496e+00, -8.831291259023364e-01, -5.850227786889902e-01, -5.102085950727644e-01, -4.242134819238622e-01, -3.080352638674162e-01, -1.949330755512132e-01, -1.155930445129911e-01, -7.836858923239724e-02, -4.667623005354126e-02, -2.987575715463102e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b3p86_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.450420580271882e+00, -4.358506609811465e+00, -4.229631530349344e+00, -4.050943173292131e+00, -3.807133157516915e+00, -3.482030377302297e+00, -3.062572595446464e+00, -2.546500031375922e+00, -1.955181116201054e+00, -1.354050657345174e+00, -8.883811904272867e-01, -7.340521850892785e-01, -6.556388047251424e-01, -5.287618769696679e-01, -3.644127685310309e-01, -2.073171677226778e-01, -8.071753886560680e-02, -3.620822782672335e-02, -1.730261390739580e-02, -5.643589196396166e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3p86_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.481687807000273e-06, -2.684284135875521e-06, -3.003848045874212e-06, -3.528416474003353e-06, -4.439804279674952e-06, -6.155868729084908e-06, -9.773802987671055e-06, -1.869717708395709e-05, -4.593466894462200e-05, -1.558005112392139e-04, -7.574178588823380e-04, -2.557168771534849e-03, -3.827558514420027e-03, -9.104842106513279e-03, -3.530313632086440e-02, -2.552672404442287e-01, -4.750113896147384e+00, -1.514440883758868e+02, -1.216170574250957e+04, -7.225559591112937e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3p86_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.823370772347828e-03, -1.027604988117631e-02, -1.096391318507528e-02, -1.203444402681143e-02, -1.375851914598097e-02, -1.667378639275895e-02, -2.195381995305019e-02, -3.246423917955203e-02, -5.610353113201849e-02, -1.171671659821181e-01, -2.937463939262789e-01, -4.333767681000451e-01, -5.272120874766770e-01, -8.888189295465653e-01, -2.177180986469433e+00, -9.321078262974806e+00, -8.330899099994902e+01, 8.318766733905094e+02, 9.187595228044991e+03, 6.803917634610170e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3p86_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.909476293615989e-08, 2.177917253773180e-08, 2.629646897505297e-08, 3.443265301894990e-08, 5.057614153886943e-08, 8.731426750994619e-08, 1.886643330499132e-07, 5.535313283394126e-07, 2.436936450374997e-06, 1.836788390596357e-05, 3.366030181982129e-04, 5.697139725090656e-03, 1.414859931757416e-02, 5.482400867597810e-02, 5.744078284708549e-01, 2.401456765718867e+01, 4.236737373332210e+03, -2.631513809260895e+06, -7.702444046207114e+09, -2.455467461863329e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3p86_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.851336110586064e-14, -2.058565120746870e-14, -2.348532488916387e-14, -2.668244204383284e-14, -2.460865873885425e-14, 2.514531287006040e-14, 5.022431526126959e-13, 6.324042962339535e-12, 1.303159174879722e-10, 6.123760995847717e-09, 6.739400090348285e-07, -6.479879514647381e-05, -1.104767575048738e-03, -1.749050639344055e-03, 3.191811245790399e-02, 7.651630092001312e+00, 1.306801164495676e+05, 2.015066834347820e+10, 1.757145187898871e+16, 5.795234463890628e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
