
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_sb98_2b_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2b", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.337487935147665e+00, -3.273095850609936e+00, -3.182889334226964e+00, -3.057984341972030e+00, -2.887918477064580e+00, -2.661919614727064e+00, -2.371973956364139e+00, -2.018622224446820e+00, -1.619549996294501e+00, -1.213991037008462e+00, -8.256742174158366e-01, -5.493650482889956e-01, -4.777205380426398e-01, -3.968349640393780e-01, -2.883540349251543e-01, -1.841471338237350e-01, -9.622196954615889e-02, -3.124879789424858e-02, -5.928369558155154e-03, -6.288652498594934e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_sb98_2b_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.318192251008856e+00, -4.230416616443827e+00, -4.107222507821057e+00, -3.936144826042864e+00, -3.702126459212742e+00, -3.388737055675783e+00, -2.981309102061333e+00, -2.473026423000605e+00, -1.876410130026840e+00, -1.256580911931744e+00, -8.097074321613033e-01, -6.926716450120047e-01, -6.107334863184929e-01, -4.948419351308632e-01, -3.337584258540373e-01, -1.884357580622360e-01, -1.054870749813758e-01, -4.135428450226129e-02, -7.978820663496051e-03, -8.396123550840328e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2b_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.155375800302283e-06, -1.254128788856167e-06, -1.412280274655246e-06, -1.677932544267316e-06, -2.156035424923355e-06, -3.106524550695281e-06, -5.284882843620605e-06, -1.137411095399001e-05, -3.347900113922856e-05, -1.402467424652320e-04, -7.489524731700231e-04, -2.252769535620183e-03, -5.728589699637793e-03, -9.097243101587944e-03, -4.104745450693856e-02, -2.936225690128517e-01, -1.664666216545972e+00, -2.645708024812853e+00, -1.508797219089527e+00, -4.228576106855239e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2b_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.675689714570094e-03, -9.093182789709345e-03, -9.733069754249228e-03, -1.074213265224394e-02, -1.240096888569112e-02, -1.529995643875696e-02, -2.084402256184669e-02, -3.292387665218911e-02, -6.398168721680821e-02, -1.503362613470788e-01, -3.498925071613564e-01, -4.046453522704461e-01, -4.319342932275111e-01, -8.635158778251747e-01, -2.284223884626743e+00, -6.399278815641591e+00, 1.647826270727598e+01, -3.229693624003566e+02, -9.667342258611501e+03, -7.299494630811728e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2b_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.343764466881744e-09, 9.947987185494111e-09, 1.277540993183838e-08, 1.820700261504653e-08, 2.998565216102212e-08, 6.024213081490573e-08, 1.585221150253225e-07, 5.980221600300730e-07, 3.559541290758215e-06, 3.382100244249538e-05, 5.277058036349877e-04, 4.347662414642955e-03, -1.328023280864984e-02, 5.504596979359385e-02, 7.663175807005284e-01, 1.089352687139564e+01, -3.424355251464757e+03, -3.120211715958078e+05, -2.199491771691893e+07, -4.629935132286384e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2b_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.808151098419749e-15, 8.816958149522250e-16, -5.883340251061660e-15, -2.364397926573441e-14, -7.866716304652571e-14, -2.913255947232877e-13, -1.400961815942950e-12, -1.006472934241553e-11, -1.188940548083961e-10, -1.194745922075453e-09, 1.854879823144995e-07, 3.799852517731135e-05, 1.227752282112693e-02, 2.301763312040320e-04, -7.184469826328756e-03, 9.904550121887721e+01, 3.660990660583173e+05, 9.187970170765101e+08, 7.627874757259759e+12, 1.234789923594618e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
