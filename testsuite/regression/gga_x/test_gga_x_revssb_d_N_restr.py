
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_revssb_d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_revssb_d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.527185354915477e+00, -4.438300040592629e+00, -4.314102680414413e+00, -4.142852148657767e+00, -3.911335473688425e+00, -3.607535368014604e+00, -3.226683771853639e+00, -2.780781832806112e+00, -2.301257321218116e+00, -1.810314207507414e+00, -1.235700035594249e+00, -6.888321289907802e-01, -5.922537509968742e-01, -4.833023448481188e-01, -3.560108350347581e-01, -2.312080795551317e-01, -1.209127824602733e-01, -4.187449043669451e-02, -8.769403214411289e-03, -9.701612710468511e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_revssb_d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_revssb_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.865565466916769e+00, -5.732645904415956e+00, -5.544766986393959e+00, -5.281089648428714e+00, -4.914766840743503e+00, -4.413856995044506e+00, -3.749974760828920e+00, -2.935310836661151e+00, -2.091364536540887e+00, -1.373859041433966e+00, -8.987551152942482e-01, -8.517510565964395e-01, -7.912435071257851e-01, -5.824362190341159e-01, -3.590449535944135e-01, -2.221620000646204e-01, -1.367818837804278e-01, -5.451516558742831e-02, -1.167928068322974e-02, -1.293529501337744e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_revssb_d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_revssb_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.831643910372951e-06, -2.115776072292419e-06, -2.595929712957445e-06, -3.462159616030345e-06, -5.167851824541839e-06, -8.920069999762132e-06, -1.827120999341234e-05, -4.429999987278102e-05, -1.234130117918890e-04, -4.207107943764709e-04, -2.053260644005183e-03, -5.791266302253054e-03, -2.758219261742760e-04, -2.487770617365315e-02, -1.123904728546607e-01, -4.652543583356244e-01, -1.660650299959227e+00, -2.973015721357979e+00, -3.613641179981178e+00, -3.991887244434275e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_revssb_d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_revssb_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.632910855611983e-02, -1.747569608921293e-02, -1.928588874833027e-02, -2.224841942104689e-02, -2.731045063717646e-02, -3.628840572872956e-02, -5.195745371932921e-02, -7.438053269770278e-02, -9.523700962362960e-02, -1.474075118967329e-01, -2.770226582431841e-01, -9.595718142085574e-01, -7.328941918353683e-01, -2.044131901842747e+00, -1.808615217031265e+00, 2.186889106599482e+00, 2.520851099178085e+01, -4.074166752500982e+02, -1.344540687588067e+04, -1.116611667456907e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_revssb_d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_revssb_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.806884518919469e-08, 7.008980331106557e-08, 9.144084165433855e-08, 1.326666800587112e-07, 2.213916639757350e-07, 4.383914845641094e-07, 1.033710486512911e-06, 2.687145538231682e-06, 6.791551183392993e-06, 2.905008850924290e-05, 3.271702268086173e-04, 4.149522863495844e-02, 3.702932447524863e-02, 4.295359913531362e-01, 3.430330256234301e-02, -4.576404723620851e+01, -4.856138671369768e+03, -3.541940765375777e+05, -5.039797153346868e+07, -4.126991377672916e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_revssb_d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_revssb_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.767878670693477e-13, -6.097421216850469e-13, -8.637753199796078e-13, -1.408044844398102e-12, -2.764013470793199e-12, -6.809632609349420e-12, -2.084682995017569e-11, -5.884595317460006e-11, 3.788606883571487e-10, 2.619367644217109e-08, 3.407515487868337e-06, -2.481176712291738e-03, -1.549611353050043e-02, -1.104927624101484e-01, 1.946535715241202e+00, 5.253412955849786e+02, 4.812619654951721e+05, 1.074881483937906e+09, 1.830400828803966e+13, 1.163460386504523e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
