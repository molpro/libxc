
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b1pw91_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1pw91", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.312415922937947e+00, -3.250140671343832e+00, -3.162912588783733e+00, -3.042153005701442e+00, -2.877757426094449e+00, -2.659287811591484e+00, -2.378787696859331e+00, -2.035829375617816e+00, -1.644161779938441e+00, -1.234285972890857e+00, -8.325683630188861e-01, -5.456763126246024e-01, -4.766081797516351e-01, -3.940534955406363e-01, -2.842553473155247e-01, -1.808689306437486e-01, -1.102464748309650e-01, -6.807151833028428e-02, -4.384858543821329e-02, -3.043120406068206e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b1pw91_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.162983003186562e+00, -4.076825401982243e+00, -3.956037580390344e+00, -3.788596696261405e+00, -3.560206857450517e+00, -3.255824541943292e+00, -2.863438782880192e+00, -2.381338160323390e+00, -1.829862167762921e+00, -1.268646333422970e+00, -8.264194529679333e-01, -6.875558037819927e-01, -6.175791544996363e-01, -4.954149705144750e-01, -3.336158534807708e-01, -1.739554042576044e-01, -7.155977903992980e-02, -3.019836990670086e-02, -1.197237096162489e-02, -4.977110339965988e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1pw91_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.497155485731819e-06, -2.699098351378068e-06, -3.017217512866588e-06, -3.538410804931550e-06, -4.441340831146203e-06, -6.134171398699057e-06, -9.680137139925208e-06, -1.834451979499894e-05, -4.448733533114750e-05, -1.493170686234771e-04, -7.438950321659221e-04, -2.267732705972224e-03, -1.926359850758178e-03, -7.524936880937099e-03, -3.747921924870632e-02, -3.510213391630664e-01, -5.106384875518247e+00, -1.364710008473116e+02, -1.265835897216278e+04, -7.526624573923802e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1pw91_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.218959217199122e-03, -9.638190113764440e-03, -1.027425456042814e-02, -1.126189975888442e-02, -1.284692691848536e-02, -1.551258859947588e-02, -2.030021251590819e-02, -2.971396295835192e-02, -5.059374411293709e-02, -1.041248427970887e-01, -2.604433163636209e-01, -4.319499297137273e-01, -5.002637323543184e-01, -9.087356644185558e-01, -2.549055779731466e+00, -1.044696139302403e+01, -1.757254740561550e+01, 1.225377255403529e+02, 1.387116540592900e+04, 7.800102290082686e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1pw91_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.804520018454845e-08, 2.050743619894999e-08, 2.463113600989334e-08, 3.200700585634610e-08, 4.649402084422174e-08, 7.897428902482789e-08, 1.666419281376283e-07, 4.726442665675767e-07, 1.993708985015605e-06, 1.442510018678797e-05, 2.640311776520328e-04, 7.661735751573055e-03, 1.560280227357092e-02, 8.149471211764060e-02, 1.050847098643119e+00, 3.253687261479153e+01, -4.111594717809760e+02, -9.804799460479442e+05, -7.580932512040466e+09, -2.557778603369119e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1pw91_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.406686408692168e-15, -2.658988196997605e-15, 1.697912616066344e-15, 1.401189503171022e-14, 5.523400425722381e-14, 2.296260352133974e-13, 1.253689793287168e-12, 1.078214203029573e-11, 1.792332618571007e-10, 7.397968720303825e-09, 8.892175742024201e-07, -3.034600966136091e-04, -4.431096166646470e-03, -1.730480042248610e-02, -4.055976586463010e-01, 2.802873457000919e+01, 4.954335597186765e+05, 1.494833751069966e+10, 1.815303008003356e+16, 6.036702565853592e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
