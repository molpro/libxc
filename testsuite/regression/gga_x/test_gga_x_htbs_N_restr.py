
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_htbs_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_htbs", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.295496968989504e+00, -4.213367579843132e+00, -4.098346794365785e+00, -3.939141342900450e+00, -3.722458527752534e+00, -3.434567185930610e+00, -3.064932410299618e+00, -2.612589308472161e+00, -2.095167114852593e+00, -1.561881604201858e+00, -1.053580200472115e+00, -6.613680022739643e-01, -5.621722455228702e-01, -4.688186599818068e-01, -3.403620857525111e-01, -2.338013944746992e-01, -1.314221077632599e-01, -4.238120640772890e-02, -8.774367452886237e-03, -9.701687044429635e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_htbs_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_htbs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.407460445552658e+00, -5.294377742976818e+00, -5.135967122384272e+00, -4.916640702743607e+00, -4.618066511363280e+00, -4.221450445887125e+00, -3.713056888884552e+00, -3.093883786899327e+00, -2.381445116809098e+00, -1.574050062323306e+00, -9.355703094340518e-01, -8.093821390827335e-01, -7.174155558079369e-01, -5.649982018332844e-01, -3.709150941538201e-01, -1.406055184779602e-01, -1.642579263302345e-01, -5.650827521030492e-02, -1.169915660384832e-02, -1.293558272590618e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_htbs_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_htbs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.432131297509742e-06, -3.696839788833293e-06, -4.111600975908669e-06, -4.785633188258380e-06, -5.938781947332415e-06, -8.058013705978650e-06, -1.235423669687473e-05, -2.233341324944606e-05, -5.199772646484277e-05, -2.046071466535392e-04, -1.249699022974805e-03, -5.812963603744792e-03, -1.194314453024712e-02, -2.232617395705669e-02, -7.811439397638216e-02, -9.163615358660290e-01, -7.437533499100274e-01, -6.148154980139533e-13, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_htbs_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_htbs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.156241330913228e-02, -1.205497033637325e-02, -1.279640184461424e-02, -1.393356923634913e-02, -1.572288971963133e-02, -1.863523814341597e-02, -2.358369812847759e-02, -3.302564367898023e-02, -6.262771146239103e-02, -2.521527302933358e-01, -8.202649938985553e-01, -5.041097427283570e-01, -6.566312659888144e-01, -1.009190664199176e+00, -3.321978836191903e+00, -6.469157701343004e+00, 5.048989050095715e+01, -5.852421858000966e+02, -1.365370822982718e+04, -1.116831697629218e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_htbs_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_htbs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.606819083196288e-08, 1.804069440825417e-08, 2.126454298244364e-08, 2.681133302438795e-08, 3.702568548050020e-08, 5.746236751961982e-08, 1.017764860657787e-07, 2.295963342009796e-07, 1.926518396272162e-06, 6.565014315587718e-05, 1.667724141759418e-03, 5.495796038506184e-03, 2.787540107456851e-02, 4.734996763377869e-02, 1.391329956619507e+00, 1.308222317541621e+01, -7.202157996674689e+03, -1.831039134132653e-06, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_htbs_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_htbs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.017685756187274e-13, 1.282466390699887e-13, 1.786327831949523e-13, 2.869352811409597e-13, 5.639439084025440e-13, 1.470643191745968e-12, 5.660648354397475e-12, 3.487618382056602e-11, 2.788099863093384e-10, -7.794568695307755e-09, -1.679490448048894e-06, 5.632000371954132e-04, 4.032077038132936e-03, 3.418772955293515e-02, 1.537976601466421e-01, 4.919610780705406e+02, 5.566824310661309e+05, 4.183423058319253e-03, 1.976262583364986e-323, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
