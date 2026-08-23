
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_pc07_opt_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.439417039708808e+01, 2.434649506414809e+01, 2.427631182275994e+01, 2.417288481194229e+01, 2.402098710015142e+01, 2.379995872331040e+01, 2.353160285967419e+01, 2.415235413980818e+01, 2.382425680591718e+01, 2.252768928253614e+01, 1.871193441738691e+01, 5.559453817429050e+00, 7.144848482368525e-01, 8.402064085207860e-01, 9.249791927845480e-01, 8.825980315096382e-01, 8.578415563797452e-01, 1.017798843234478e+00, 6.413280811032532e-01, 5.746458457989374e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_pc07_opt_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.439417039708808e+01, -2.434649506414809e+01, -2.427631182275994e+01, -2.417288481194229e+01, -2.402098710015142e+01, -2.379995872331040e+01, -1.751500547691446e+01, 1.126615970411709e+01, 1.304809957149156e+01, 1.326644540988543e+01, 5.482237429211038e+00, 3.302922016636752e+00, 2.200000634192313e+00, 1.387745171608760e+00, 7.274684171121822e-01, 3.186005078832924e-01, 2.385326782323721e-02, -3.245044213394702e-01, -6.844386700375640e-01, -5.750585646090255e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_opt_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.979860371331102e-04, 7.420521594677619e-04, 8.102765668477127e-04, 9.193529745549600e-04, 1.101974829551973e-03, 1.428641662845022e-03, 1.948447104139276e-03, 1.871594838952649e-03, 2.348962182899590e-03, 9.103057305217037e-05, 5.878881329130154e-03, 1.545546722416484e-02, 1.241867146178816e-02, 3.040745523899330e-02, -8.081268358727173e-02, -1.475854097279014e+00, -5.852766046029843e+00, 1.583765050244400e+03, 5.425228237134389e+05, 3.246219120251698e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_opt_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.104859245710181e-02, 8.743824928618743e-02, 1.282003282767263e-01, 1.869872847886959e-01, 1.753212497643366e-01, 1.746004963625263e-01, 1.793052449069466e-01, 1.773689508120142e-01, 1.957871920894305e-01, 2.155895272986494e-01, 2.082183078157360e-01, 1.846238220407070e-01, -3.406747049988978e-02, -3.626413088233219e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_opt_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.724286451938134e-01, 2.890619078051568e-01, 3.147284255915275e-01, 3.555746168869369e-01, 4.235283706457518e-01, 5.440258016978089e-01, 8.598128864681394e+00, 1.338980741643661e+01, 1.634860796186040e+01, 1.172310446101626e+01, 3.806624746242492e+00, 4.242108234255140e+00, 8.321157394093310e+00, 1.585834810959864e+01, 2.312041970352819e+01, 1.528451196064998e+00, 1.100757636221302e+02, -5.121420092159537e+04, 5.711855594327042e+06, 2.986012242380601e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_opt_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.897476064262268e-06, -4.405131258966150e-06, -5.252384918260128e-06, -6.761679134584423e-06, -9.714788199728793e-06, -1.632813600653271e-05, -1.951840184952207e-04, -6.760091278301841e-04, -2.458158341458051e-03, -7.595923484100735e-03, -3.870600844811673e-03, -1.127569183232826e-02, -7.734684199017007e-01, -4.098401540363035e+00, -2.753230146436023e+01, 3.176298988847787e+01, -2.479437066466907e+04, 5.948612247179352e+08, -2.733203646804992e+12, -8.457942041577489e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_opt_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.468074151319896e-02, 3.313528092668450e-02, 5.822681422853095e-02, 6.727075805269155e-02, -5.855531822001061e-04, -1.652842656954988e-02, 4.595511473674674e-01, 1.269410310766856e+00, 2.901720244573027e+00, 1.628277643185744e+00, 3.793613980859693e+01, -3.074645602877911e+04, 3.885562906979698e+05, 3.051780445355009e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_opt_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 3.395416013884230e-09, 3.169370322912062e-08, 3.650707645729042e-07, 5.655254988043791e-06, 2.140174727545156e-05, 4.874471151876558e-04, 1.183244629930708e-01, 1.404409426847476e+00, 4.827593420386569e+01, 1.735565063358603e+03, 1.115757895597639e+07, -5.875782165190429e+12, 1.025786990656063e+18, 4.886139261489531e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_opt_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -3.059890744144578e-07, -1.684683397487701e-06, -9.172001759966579e-06, -5.032068981856099e-05, -5.837816561022753e-05, -5.977324152192568e-04, -7.305022890476888e-02, -4.505981705879084e-01, -4.894125068553793e+00, -3.458773372989621e+01, -1.867520683863435e+04, 2.750413108574118e+08, -4.176847771242936e+11, -2.602888822729774e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pc07_opt_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pc07_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 2.757706018249094e-05, 8.958380075333227e-05, 2.306098124029673e-04, 4.491600429449479e-04, 1.679101068484754e-04, 7.255301283476180e-04, 4.521607478742314e-02, 1.449151094642209e-01, 4.987103562779352e-01, 7.293378523559398e-01, 3.314717366110987e+01, -1.279072387489356e+04, 1.630877732921485e+05, 1.329200888263548e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
