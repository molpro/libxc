
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_absp3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.240392071991869e+01, -2.058004840463383e+01, -1.809160482624503e+01, -1.477385460913294e+01, -1.049430173309651e+01, -5.229821940128322e+00, 8.175722651581013e-01, 7.087939986777212e+00, 1.251719564208202e+01, 1.495466628001786e+01, 8.934116641733047e+00, -1.269974575713966e-01, -5.075984270450951e-01, 6.439333213687051e-02, 4.995400547118353e-01, 6.763103729920089e-01, 6.895679476547305e-01, 6.448353146942762e-01, 6.027222367706817e-01, 5.742313907135271e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_absp3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.023909889254327e+02, -9.922406751211798e+01, -9.488950623776823e+01, -8.908411718040101e+01, -8.154646848889796e+01, -7.218292649570827e+01, -6.125410068128895e+01, -4.954380420612177e+01, -3.824282611675134e+01, -2.777198503358077e+01, -1.432204567031827e+01, -2.726893753017162e+00, -1.664295804610615e+00, -1.467887247405986e+00, -1.147474505092963e+00, -8.780641174571436e-01, -7.283749622610297e-01, -6.488095917029935e-01, -6.028925871637331e-01, -5.742334733143062e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_absp3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp3", 1)
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


def test_gga_k_absp3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.792170293199780e-02, -7.274435292015677e-03, 9.575269619564767e-03, 3.730083256709308e-02, 8.543966372170306e-02, 1.753755428618857e-01, 3.608724098393999e-01, 7.971478507261602e-01, 2.005147615099972e+00, 5.798702469607575e+00, 1.223983952570996e+01, 1.125892470573433e+00, -7.082935345474192e-01, 2.793267682379395e+00, 1.813562481016613e+01, 1.219688181795773e+02, 1.417516883145265e+03, 4.011155676664479e+04, 4.220704874169748e+06, 2.974679472107398e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_absp3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp3", 1)
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


def test_gga_k_absp3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp3", 1)
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
