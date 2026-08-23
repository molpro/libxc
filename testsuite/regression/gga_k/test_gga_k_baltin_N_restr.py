
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_baltin_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_baltin", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.047766660432298e+02, 1.011019387174740e+02, 9.607537138107519e+01, 8.934895047266821e+01, 8.062625761557717e+01, 6.981046569119336e+01, 5.722389907620490e+01, 4.381770461389506e+01, 3.111878936252369e+01, 2.034780772744291e+01, 1.002442796012364e+01, 2.610184311295348e+00, 1.758120820996576e+00, 1.354114483585406e+00, 8.861448905853391e-01, 5.652408224500183e-01, 4.195457996978725e-01, 3.619749891256225e-01, 3.350057019011616e-01, 3.190193955294457e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_baltin_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_baltin", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.384882650393266e+02, 1.324343496192743e+02, 1.241607125643698e+02, 1.131032362515695e+02, 9.879044847018207e+01, 8.109157804338093e+01, 6.058609783633089e+01, 3.894226462459337e+01, 1.902863846334243e+01, 4.637219082621225e+00, 4.783576706467909e-01, 2.952956450085858e+00, 2.475591131548669e+00, 1.381741101734508e+00, 3.768852271166642e-01, -1.719586694965392e-01, -3.438985977362757e-01, -3.542278604536591e-01, -3.346736348581765e-01, -3.190153358788043e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_baltin_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_baltin", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.877700206295057e-04, 4.122511997043122e-04, 4.501536482487293e-04, 5.107516525305333e-04, 6.122082386399848e-04, 7.936898126916788e-04, 1.150589142727753e-03, 1.954172996063846e-03, 4.143053061739317e-03, 1.178077221384358e-02, 4.322517264126677e-02, 1.121278294589069e-01, 1.688929526885695e-01, 3.251275227167884e-01, 1.036508644499532e+00, 5.965366492887273e+00, 7.071380149208343e+01, 2.157656642702748e+03, 2.431391120061584e+05, 1.798707296529009e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_baltin_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_baltin", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.173343313958053e-01, 7.382436390285424e-01, 7.696895853129593e-01, 8.179581873930233e-01, 8.943358529397429e-01, 1.020853045457697e+00, 1.245582136979648e+00, 1.689777377255649e+00, 2.715827130642442e+00, 5.490885205067552e+00, 1.030013305504055e+01, 5.434861964790671e+00, 5.119493699279647e+00, 8.409875405627158e+00, 2.016882912462426e+01, 8.584867103257461e+01, 8.287524919540447e+02, 2.241307581616316e+04, 2.345458534932151e+06, 1.652605336663342e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_baltin_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_baltin", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.165264480145704e-06, -2.447295143870084e-06, -2.917991621255627e-06, -3.756488408102457e-06, -5.397104555404885e-06, -9.071186670295951e-06, -1.906351740522700e-05, -5.499060621905014e-05, -2.471743968823805e-04, -1.998526952944353e-03, -2.690518391808938e-02, -1.810461620039863e-01, -4.107575443372325e-01, -1.522193846802562e+00, -1.547064244976050e+01, -5.124326024802556e+02, -7.200636078904965e+04, -6.703894350430981e+07, -8.512794401348624e+11, -4.658901031564843e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_baltin_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_baltin", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
