
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b5050lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b5050lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.220771631079035e+00, -2.179469059367239e+00, -2.121615186040833e+00, -2.041516428934346e+00, -1.932459856845702e+00, -1.787489679583440e+00, -1.601230619930371e+00, -1.373098251592547e+00, -1.111290066794647e+00, -8.338439158236642e-01, -5.635472324226027e-01, -3.771828690720533e-01, -3.266293325725638e-01, -2.739359373735061e-01, -1.987214366375099e-01, -1.196736012301761e-01, -6.220162320452972e-02, -4.485229565637203e-02, -2.631923302791096e-02, -1.725207993731324e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b5050lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b5050lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.782282064023518e+00, -2.725497589838787e+00, -2.645917841746227e+00, -2.535661713429416e+00, -2.385400650450342e+00, -2.185420301346594e+00, -1.928233260884330e+00, -1.613647369605633e+00, -1.257165776435420e+00, -9.014042042507042e-01, -6.126664323909224e-01, -4.632866581966818e-01, -4.133337982087632e-01, -3.354080903679605e-01, -2.383719134740130e-01, -1.523177254779021e-01, -7.899669660813961e-02, -2.580697474494492e-02, -9.022660392263251e-03, -3.066665357510830e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b5050lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b5050lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.692799156180490e-06, -1.823984649968480e-06, -2.029912414507025e-06, -2.365566840340265e-06, -2.942691770115908e-06, -4.012575687182749e-06, -6.215095620654350e-06, -1.144563336414734e-05, -2.641936586731066e-05, -8.024556824424094e-05, -3.512463338010222e-04, -2.405319878242202e-03, -4.823337467687672e-03, -8.429342122252537e-03, -2.107194915517968e-02, -2.085094932909423e-02, 4.944570142983080e-01, -7.220440283846952e+01, -7.088684454812371e+03, -4.214909761481760e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b5050lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b5050lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.828714086680902e-03, -6.084677656097601e-03, -6.471869416286032e-03, -7.070341740283507e-03, -8.023953207180133e-03, -9.608980055832101e-03, -1.239708385262512e-02, -1.765418947689049e-02, -2.817773944826584e-02, -4.802931727467534e-02, -8.520866417074688e-02, -2.533550238638976e-01, -3.309145494783035e-01, -5.075986315803946e-01, -8.291860663938364e-01, 5.547875849311343e-01, 1.193630878213166e+01, -3.428747678098678e+01, 5.238080905974854e+03, 4.131895548564429e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b5050lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b5050lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.399769725075790e-09, 9.514285271194613e-09, 1.137000471959545e-08, 1.465906667350045e-08, 2.102363467707648e-08, 3.492926157469478e-08, 7.065389742137013e-08, 1.822988915855321e-07, 5.819196445713347e-07, 5.674236556033668e-07, -7.091244480851946e-05, 2.161401808208299e-03, 9.654333510719591e-03, 1.396431224070445e-02, -2.133204366457493e-01, -2.587052849294955e+01, -3.461124571955604e+03, -4.221170786081878e+05, -4.245400721613318e+09, -1.432356019333513e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b5050lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b5050lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.417027169026570e-14, 5.509579806024238e-14, 7.565425374598193e-14, 1.191692982436288e-13, 2.282351468140140e-13, 5.765722118231327e-13, 2.149751407645684e-12, 1.377218921445997e-11, 1.851249748045251e-10, 6.729477204376940e-09, 8.954605557983081e-07, 2.182327257668116e-04, 1.919786961531998e-03, 1.290079261952198e-02, 5.497425314258825e-01, 1.547269994298209e+02, 3.155759090449348e+05, 8.387136815478285e+09, 1.016572299021960e+16, 3.380553437247916e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
