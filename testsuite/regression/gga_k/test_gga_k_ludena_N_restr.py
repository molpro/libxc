
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_ludena_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ludena", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.439417039708808e+01, 2.434649506414809e+01, 2.427631182275994e+01, 2.417288481194229e+01, 2.402098710015142e+01, 2.379995872331040e+01, 2.348127042120717e+01, 2.300888906903142e+01, 2.216430707008302e+01, 1.976116081260395e+01, 1.095459002745251e+01, 9.432117463993127e-01, 3.068619098257963e-01, 5.907035503627888e-01, 7.425154736047581e-01, 7.519680271664344e-01, 7.041205781320927e-01, 6.463256685725453e-01, 6.027861181680759e-01, 5.742321716888192e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_ludena_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ludena", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.439417039708808e+01, -2.434649506414809e+01, -2.427631182275994e+01, -2.417288481194229e+01, -2.402098710015142e+01, -2.379995872331040e+01, -2.348127042120717e+01, -2.300888906903142e+01, -2.216430707008302e+01, -1.976116081260395e+01, -1.095459002745251e+01, -9.432117463993127e-01, -3.068619098257963e-01, -5.907035503627888e-01, -7.425154736047581e-01, -7.519680271664344e-01, -7.041205781320927e-01, -6.463256685725453e-01, -6.027861181680759e-01, -5.742321716888192e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ludena_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ludena", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.979860371331102e-04, 7.420521594677619e-04, 8.102765668477127e-04, 9.193529745549600e-04, 1.101974829551973e-03, 1.428641662845022e-03, 2.071060456909956e-03, 3.517511392914923e-03, 7.457495511130772e-03, 2.120538998491845e-02, 7.780531075428020e-02, 2.018300930260324e-01, 3.040073148394251e-01, 5.852295408902189e-01, 1.865715560099157e+00, 1.073765968719709e+01, 1.272848426857502e+02, 3.883781956864946e+03, 4.376504016110850e+05, 3.237673133752216e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ludena_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ludena", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.724286451938134e-01, 2.890619078051568e-01, 3.147284255915275e-01, 3.555746168869369e-01, 4.235283706457518e-01, 5.440258016978089e-01, 7.780980903579449e-01, 1.294944471018139e+00, 2.644643527719490e+00, 6.704689945375275e+00, 1.363720450034690e+01, 3.045896232304317e+00, 1.492612243722210e+00, 5.531154681296596e+00, 2.216516276350068e+01, 1.291900283418584e+02, 1.433982032309486e+03, 4.016300751777158e+04, 4.220953387229526e+06, 2.974681719700928e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ludena_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ludena", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.897476064262268e-06, -4.405131258966150e-06, -5.252384918260128e-06, -6.761679134584423e-06, -9.714788199728793e-06, -1.632813600653271e-05, -3.431433132940861e-05, -9.898309119429025e-05, -4.449139143882849e-04, -3.597348515299836e-03, -4.842933105256088e-02, -3.258830916071753e-01, -7.393635798070185e-01, -2.739948924244612e+00, -2.784715640956890e+01, -9.223786844644601e+02, -1.296114494202894e+05, -1.206700983077577e+08, -1.532302992242752e+12, -8.386021856816717e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ludena_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ludena", 1)
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
