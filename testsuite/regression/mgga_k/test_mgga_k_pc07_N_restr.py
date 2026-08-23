
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_pc07_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.439417039708808e+01, 2.434649506414809e+01, 2.427631182275994e+01, 2.417288481194229e+01, 2.402098710015142e+01, 2.379995872331040e+01, 2.348128802890687e+01, 2.332673617626929e+01, 2.369123605989600e+01, 2.446200338677695e+01, 1.871193441738691e+01, 5.559453817429050e+00, 1.045960033637717e+00, 1.052063908923756e+00, 1.016883571820025e+00, 8.970208854678647e-01, 8.578415563797452e-01, 1.017798843234478e+00, 6.413280811032532e-01, 5.746458457989374e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_pc07_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.439417039708808e+01, -2.434649506414809e+01, -2.427631182275994e+01, -2.417288481194229e+01, -2.402098710015142e+01, -2.379995872331040e+01, -2.347478813263947e+01, 2.876428622633520e-01, 4.591881791045034e+01, 1.320512902231925e+01, 5.482237429211038e+00, 3.302922016636752e+00, 2.880308540940996e+00, 2.181631539412395e+00, 6.990902122381523e-01, 1.666240360583652e-01, 2.385326782323721e-02, -3.245044213394702e-01, -6.844386700375640e-01, -5.750585646090255e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.979860371331102e-04, 7.420521594677619e-04, 8.102765668477127e-04, 9.193529745549600e-04, 1.101974829551973e-03, 1.428641662845022e-03, 2.070925950599066e-03, 2.359863198650585e-03, -2.861376431352836e-03, 2.531998953233399e-03, 5.878881329130154e-03, 1.545546722416484e-02, -7.980550189794077e-03, -1.261000709343934e-01, 2.223035256660071e-01, 1.044813763353094e+00, -5.852766046029843e+00, 1.583765050244400e+03, 5.425228237134389e+05, 3.246219120251698e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.212025752782657e-05, 6.149930939822729e-02, 2.589554937737763e-01, 1.653702401622491e-01, 1.753212497643366e-01, 1.746004963625263e-01, 1.918492431634595e-01, 2.274022433385265e-01, 1.652989257727297e-01, 1.710954036467568e-01, 2.082183078157360e-01, 1.846238220407070e-01, -3.406747049988978e-02, -3.626413088233219e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.724286451938134e-01, 2.890619078051568e-01, 3.147284255915275e-01, 3.555746168869369e-01, 4.235283706457518e-01, 5.440258016978089e-01, 8.131303514039168e-01, 3.506370694649659e+01, 1.057298868072707e+02, 6.426484190330973e-01, 3.806624746242492e+00, 4.242108234255140e+00, -5.325644887574897e+01, -1.905153400597783e+02, 1.127679742765897e+01, 3.281590504706242e+01, 1.100757636221302e+02, -5.121420092159537e+04, 5.711855594327042e+06, 2.986012242380601e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.897476064262268e-06, -4.405131258966150e-06, -5.252384918260128e-06, -6.761679134584423e-06, -9.714788199728793e-06, -1.632813600653271e-05, -3.504222530941372e-05, -1.790124813739295e-03, -1.640283274011459e-02, 9.840309618817183e-04, -3.870600844811673e-03, -1.127569183232826e-02, 9.256121613666155e+00, 7.008930612598682e+01, -4.724359997015319e+00, -1.793394111635968e+02, -2.479437066466907e+04, 5.948612247179352e+08, -2.733203646804992e+12, -8.457942041577489e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 6.579278765290894e-05, 9.158591091667936e-02, 4.160303222982364e-01, -1.239591676455588e-02, -5.855531822001061e-04, -1.652842656954988e-02, -5.677215366913352e+00, -2.221179528386242e+01, 1.508428006579284e-01, 1.542587486569956e+00, 3.793613980859693e+01, -3.074645602877911e+04, 3.885562906979698e+05, 3.051780445355009e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.521866905842305e-11, 8.764635314082416e-08, 2.609680863596631e-06, -1.030185934252156e-06, 2.140174727545156e-05, 4.874471151876558e-04, -1.474067838805909e+00, -2.467664731336529e+01, 2.596751167900059e+00, 1.580489020383148e+03, 1.115757895597639e+07, -5.875782165190429e+12, 1.025786990656063e+18, 4.886139261489531e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -1.371376064972555e-09, -4.656842103353525e-06, -6.551187071171367e-05, 8.912637347311335e-06, -5.837816561022753e-05, -5.977324152192568e-04, 9.061318901278572e-01, 7.886695914153101e+00, -2.936071401378860e-01, -3.103474203428380e+01, -1.867520683863435e+04, 2.750413108574118e+08, -4.176847771242936e+11, -2.602888822729774e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.235786898624028e-07, 2.474522656791098e-04, 1.644921481288252e-03, -7.581349115836595e-05, 1.679101068484754e-04, 7.255301283476180e-04, -5.568871376017086e-01, -2.520158519462619e+00, 3.497380659134430e-02, 6.421020738966178e-01, 3.314717366110987e+01, -1.279072387489356e+04, 1.630877732921485e+05, 1.329200888263548e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
