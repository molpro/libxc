
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_o3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_o3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.943813865955674e+00, -3.866544471440026e+00, -3.758345057006167e+00, -3.608627272475072e+00, -3.405000921346022e+00, -3.134916445064561e+00, -2.789647712327029e+00, -2.372025709258427e+00, -1.908274450569080e+00, -1.449833270344865e+00, -9.927703441929171e-01, -6.356950122266578e-01, -5.552408593964601e-01, -4.550331028664585e-01, -3.296395167246918e-01, -2.216358240134074e-01, -1.283285426193518e-01, -5.483998069139813e-02, -1.195459329345413e-02, -1.338614085019741e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_o3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_o3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.161271016454879e+00, -5.054342220417371e+00, -4.904152257656441e+00, -4.695331984819173e+00, -4.409104146692887e+00, -4.024423309587780e+00, -3.520994599697588e+00, -2.885315288282775e+00, -2.126831011787252e+00, -1.349932416299743e+00, -8.504819421091562e-01, -8.145534779946046e-01, -7.285341246089624e-01, -5.759085671376899e-01, -3.595029652704083e-01, -1.895946444768931e-01, -1.561396725395246e-01, -7.002127519815461e-02, -1.587500462659543e-02, -1.783451305286330e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_o3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_o3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.172542731530827e-07, -9.163552856742869e-07, -1.079562915789942e-06, -1.364518538594745e-06, -1.905066885408897e-06, -3.057380292040245e-06, -5.943706488463474e-06, -1.489884048325413e-05, -5.076851469044230e-05, -2.302590923383107e-04, -1.242121999546335e-03, -1.877001984549854e-03, -9.652059072302699e-04, -8.786901607742755e-03, -7.141354853171561e-02, -5.492214835073045e-01, -2.530043587228952e-01, -2.580805789809285e+00, -8.321705812263637e+00, -9.195549999615379e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_o3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_o3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.102875737609416e-02, -1.159183226811521e-02, -1.246131124396181e-02, -1.384834972679531e-02, -1.617033315448823e-02, -2.034614036149861e-02, -2.868620393142394e-02, -4.787970137399028e-02, -9.826541996164179e-02, -2.137781959764904e-01, -4.233651183062904e-01, -5.594862388729160e-01, -5.996447420335033e-01, -1.254041778961833e+00, -4.019170528960740e+00, 2.359587425740056e+00, 1.283628612543561e+02, -3.769330018647162e+02, -1.792459893338453e+04, -1.534206076392611e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_o3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_o3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.668361531161154e-08, 1.978743563843593e-08, 2.526316071084666e-08, 3.581473361220151e-08, 5.886276513379538e-08, 1.189166573664562e-07, 3.184722451693900e-07, 1.231252869880851e-06, 7.243020759980524e-06, 5.705952844837890e-05, 6.983296922115055e-04, 1.155584026094326e-02, 1.455889754092423e-02, 1.518428467277507e-01, 2.224617915184419e+00, -4.125040696633322e+01, -1.312861279448758e+04, -6.818666375073576e+05, -1.163240416827734e+08, -9.526868360202943e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_o3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_o3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.146570529025831e-13, -1.444326457572461e-13, -2.010470740066822e-13, -3.225634857694918e-13, -6.325461527815842e-13, -1.641656003164457e-12, -6.245186662515035e-12, -3.893508306002224e-11, -4.109476556648737e-10, -2.348985091628896e-09, 8.158669749487813e-07, -6.268745180551146e-04, -4.550272274755826e-03, -3.749525529077422e-02, -8.034307813651982e-01, 5.611376591599266e+02, 1.039722540880869e+06, 2.473029822274216e+09, 4.224825428109670e+13, 2.685766677045835e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
