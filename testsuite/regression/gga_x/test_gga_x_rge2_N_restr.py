
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_rge2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rge2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.245409503328479e+00, -4.162847635871788e+00, -4.047237465104460e+00, -3.887257449453405e+00, -3.669630275451605e+00, -3.380793282127597e+00, -3.010859329215378e+00, -2.560924112405407e+00, -2.053407089298735e+00, -1.536203703737491e+00, -1.034367653637304e+00, -6.505932997352971e-01, -5.570560698558534e-01, -4.602606746671655e-01, -3.341769756890848e-01, -2.223521434469149e-01, -1.255034859925830e-01, -4.233843617446986e-02, -8.774347836107923e-03, -9.701687040849506e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_rge2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rge2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.441037750119996e+00, -5.326898931459874e+00, -5.166814604318017e+00, -4.944745827902978e+00, -4.641490037136003e+00, -4.236493354861341e+00, -3.712365827780104e+00, -3.063497365749468e+00, -2.311175808767691e+00, -1.539813414285751e+00, -9.678165731650797e-01, -8.115105071300989e-01, -7.217931213046658e-01, -5.638645700223534e-01, -3.574024828817873e-01, -1.820457909690118e-01, -1.396782082995543e-01, -5.622895041463316e-02, -1.169902594288318e-02, -1.293558270203892e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rge2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rge2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.355281416452162e-06, -2.555243288384325e-06, -2.872554944022705e-06, -3.398158956169091e-06, -4.324058416881991e-06, -6.105450777287778e-06, -9.992456519903733e-06, -2.012623413404300e-05, -5.383851453000036e-05, -2.046069242910643e-04, -1.095583894243615e-03, -4.489381827975101e-03, -7.782537276365716e-03, -1.850800687843063e-02, -8.307614966129725e-02, -6.127137727784997e-01, -1.875035665451507e+00, -5.009217662357022e-01, -2.845335680219835e-02, -4.037085611810825e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rge2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.175032387216538e-02, -1.229721853822988e-02, -1.313115610399713e-02, -1.443632697557028e-02, -1.655799814921145e-02, -2.020404723623464e-02, -2.700231812149595e-02, -4.126180400650719e-02, -7.599979740047232e-02, -1.657043505530356e-01, -3.731650388178161e-01, -5.549010174017686e-01, -6.528281855512177e-01, -1.181481528987359e+00, -3.198074425000860e+00, -2.760709331695343e+00, 7.822153479936772e+01, -5.377415402499024e+02, -1.365111973796018e+04, -1.116831662598835e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rge2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.741385099662708e-08, 2.007395576135550e-08, 2.462022027793974e-08, 3.299903900179101e-08, 5.020817255782696e-08, 9.148645714515541e-08, 2.149742548219805e-07, 7.181037594389803e-07, 3.790047247130964e-06, 3.164180658933104e-05, 4.590764704882906e-04, 9.479528221674010e-03, 2.514408077313229e-02, 1.120176008678827e-01, 1.337926462777469e+00, -1.312962826140308e+01, -8.516499832337833e+03, -1.005182690998660e+05, -6.632434024362091e+05, -6.970953570105287e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_x_rge2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.305318195202625e-15, 1.730031722690695e-15, 2.592518880026542e-15, 4.631987738702100e-15, 1.064079681105961e-14, 3.497080592359065e-14, 1.909171617684732e-13, 2.123163183873164e-12, 6.215644338307679e-11, 5.890589654896225e-09, 1.199015867303395e-06, 1.488164375350616e-05, 3.443936832718533e-05, 1.306904867821216e-03, 2.971600487167336e-01, 4.460896005675271e+02, 7.499014580426363e+05, 2.732674685931380e+08, 2.167441418882197e+11, 1.768688836784576e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
