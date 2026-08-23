
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_bop_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_bop", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.108011703777041e+00, -4.025564261591374e+00, -3.910063895497964e+00, -3.750123334867273e+00, -3.532291001430697e+00, -3.242561374572625e+00, -2.869921556475752e+00, -2.412558810578963e+00, -1.885587638592812e+00, -1.324606369203009e+00, -7.881013216859285e-01, -4.628421445679790e-01, -3.776060109532615e-01, -2.774076135984674e-01, -1.469709599692245e-01, -4.420521718155175e-02, -6.101306090512546e-03, -3.737522660263341e-04, -6.959752190756779e-06, -1.871748691436618e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_bop_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_bop", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.214778387442514e+00, -5.101931781479290e+00, -4.943833689983754e+00, -4.724893033519200e+00, -4.426719328204978e+00, -4.030299668552784e+00, -3.521281761139966e+00, -2.900039599508023e+00, -2.197585102115979e+00, -1.494883211026917e+00, -9.259922151143500e-01, -6.467179687336659e-01, -5.463272623127026e-01, -4.086134511542822e-01, -2.353695054869259e-01, -8.499225371775845e-02, -1.435967346843722e-02, -1.063581130885913e-03, -2.310823616160945e-05, -6.773797429137229e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_bop_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_bop", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.577005099676140e-06, -3.845962385834456e-06, -4.266801109145180e-06, -4.949526977711966e-06, -6.115272361554672e-06, -8.254106050568266e-06, -1.258938653065393e-05, -2.264671897877641e-05, -5.045343451847961e-05, -1.455158313294563e-04, -5.656320938713255e-04, -2.307414311856135e-03, -3.438920496857076e-03, -4.197325276626432e-03, -3.132460218373580e-04, 5.140491010087918e-02, 2.912804325516993e-01, 1.139364967472455e+00, 3.648944508197396e+00, 8.960417562610443e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_bop_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_bop", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.163436321712227e-02, -1.214095852719691e-02, -1.290668389667958e-02, -1.408894253029000e-02, -1.596988967701027e-02, -1.909017239325425e-02, -2.456894516200973e-02, -3.491682868750463e-02, -5.610171188807920e-02, -1.020823546540614e-01, -2.167022023326151e-01, -4.508469482162034e-01, -5.815634035586821e-01, -8.643998797817288e-01, -1.764946422126563e+00, -5.665225884340529e+00, -1.895164099612302e+01, -6.094099056194781e+01, -1.888717899393555e+02, -4.632617876159965e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_bop_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_bop", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.739386170359702e-08, 1.966302282647989e-08, 2.343245715623687e-08, 3.009175608816848e-08, 4.292235320950180e-08, 7.080936489053766e-08, 1.421560175233475e-07, 3.667704530148710e-07, 1.243171634186754e-06, 4.440267769342133e-06, -6.424650569285663e-08, 1.605775926448746e-03, 3.429343037305993e-03, 7.523152742369282e-04, -2.629183495292053e-02, 6.078884070619221e+00, 7.109770580600160e+02, 1.050138533899967e+05, 4.347156344277022e+07, 8.540323446817479e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_bop_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_bop", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.856563861559116e-14, 1.100838772551228e-13, 1.503810801792002e-13, 2.350722436618203e-13, 4.450877407906547e-13, 1.104985958979238e-12, 4.010238758203891e-12, 2.461266101218115e-11, 3.083336187035020e-10, 9.893296923042320e-09, 9.998307712521143e-07, 1.199965964086564e-04, 6.761798858709125e-04, 1.195741628185991e-03, -1.550060868844312e-01, -7.557939594551927e+01, -7.672548123130407e+04, -3.460317340467189e+08, -1.655468481296325e+13, -2.467682352081958e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
