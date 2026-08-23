
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_lkt_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lkt", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.045091769597338e+02, 1.008796178774154e+02, 9.592000602251916e+01, 8.929407913921798e+01, 8.072482936024872e+01, 7.014878001824012e+01, 5.794756444985218e+01, 4.517628780293915e+01, 3.349623129200931e+01, 2.388135237787059e+01, 1.237421188684580e+01, 2.628168510234866e+00, 1.750691659002586e+00, 1.376029918133060e+00, 9.910326392024762e-01, 7.820075896293903e-01, 7.044964572956662e-01, 6.463256703154281e-01, 6.027861181680759e-01, 5.742321716888192e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_lkt_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lkt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.357332637127669e+02, 1.295451250081417e+02, 1.210740067796895e+02, 1.097233731805342e+02, 9.497035945396837e+01, 7.660170605296423e+01, 5.506793226444538e+01, 3.187218287069653e+01, 9.904134945863866e+00, -5.678778924949411e+00, -5.623446877303697e+00, 2.761965904868394e+00, 2.453959600524670e+00, 1.233003058437347e+00, 2.732778214360213e-02, -6.127396045304583e-01, -7.009800317300448e-01, -6.463256307645111e-01, -6.027861181680759e-01, -5.742321716888192e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lkt_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lkt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.125471449850757e-04, 4.410386995762686e-04, 4.855472636470203e-04, 5.576514689791440e-04, 6.807526935383885e-04, 9.074500114206060e-04, 1.372995854967906e-03, 2.489300084813209e-03, 5.794281339079891e-03, 1.830186714081901e-02, 6.990790031872428e-02, 1.298586944741797e-01, 1.723292838080397e-01, 3.939576255384619e-01, 1.530602357077221e+00, 1.026021430970271e+01, 1.271144149754635e+02, 3.883781878214659e+03, 4.376504016110850e+05, 3.237673133752216e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lkt_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lkt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.010364004422951e-01, 8.301333291640356e-01, 8.746348868175953e-01, 9.446471015109777e-01, 1.059503054641716e+00, 1.260003969664307e+00, 1.643400805201726e+00, 2.475772040850943e+00, 4.575491707058336e+00, 1.033502898249252e+01, 1.974387388902137e+01, 6.841388810123230e+00, 5.456017025752693e+00, 1.137089571824030e+01, 3.630555563953379e+01, 1.614660779604780e+02, 1.454087225856303e+03, 4.016303037979269e+04, 4.220953387229526e+06, 2.974681719700928e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lkt_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lkt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.173413797548007e-06, -3.628243652499878e-06, -4.398494980612074e-06, -5.799700215447317e-06, -8.624766503873832e-06, -1.522458706445162e-05, -3.423744012492812e-05, -1.076543431383492e-04, -5.276058902338619e-04, -4.417326876243815e-03, -5.880199827568446e-02, -3.104072936008908e-01, -5.488097838638494e-01, -2.794765120944817e+00, -3.395308336095533e+01, -1.052514711471386e+03, -1.308298411745191e+05, -1.206701480599045e+08, -1.532302992242752e+12, -8.386021856816717e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lkt_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lkt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.332750733462165e-12, 1.154446471947069e-11, 1.565903464207599e-11, 2.422101284008557e-11, 4.513096222677778e-11, 1.092467048192413e-10, 3.800003143004601e-10, 2.155853126763929e-09, 2.295349504055809e-08, 5.281751559152966e-07, 4.071974275531067e-05, 8.083065730092567e-03, 4.818314603286704e-02, 3.530675429279789e-01, 1.046638425638654e+01, 9.164660649699489e+02, 9.435822720967626e+04, 1.176171151789434e+05, 2.141233941288418e-13, 6.196048028416532e-243]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
