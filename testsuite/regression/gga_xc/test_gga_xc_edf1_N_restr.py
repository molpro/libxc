
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_edf1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_edf1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.428886962751152e+00, -4.343750493945708e+00, -4.224558558296124e+00, -4.059672841451036e+00, -3.835483748608198e+00, -3.538186628509973e+00, -3.157975065856034e+00, -2.696736583926838e+00, -2.178493221626765e+00, -1.650169633153937e+00, -1.121128606857681e+00, -7.151558023569707e-01, -6.195247510655135e-01, -5.120368490651991e-01, -3.705870918897560e-01, -2.397478081489763e-01, -1.636519195143254e-01, -1.481635419692530e-01, -1.092143744390172e-01, -7.879197807932732e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_edf1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_edf1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.678379718953197e+00, -5.559458206893654e+00, -5.392569165039207e+00, -5.160862709203793e+00, -4.844045251285618e+00, -4.420152668353078e+00, -3.870155348423240e+00, -3.187282505246587e+00, -2.395294635373259e+00, -1.591904338069859e+00, -1.023522970979110e+00, -8.963400470538020e-01, -8.032959178978563e-01, -6.352455769409908e-01, -4.153386552041569e-01, -2.190780120037532e-01, -9.241544972463989e-02, -3.745218071963671e-02, -2.396131127809255e-02, -1.229310714526235e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_edf1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_edf1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.196727681470985e-06, -2.402996486135781e-06, -2.733202585058859e-06, -3.286917071380810e-06, -4.278902009790367e-06, -6.230628768946034e-06, -1.060967289537114e-05, -2.237437951797552e-05, -6.236872332167177e-05, -2.410526223901109e-04, -1.244835359811574e-03, -3.818969459309172e-03, -4.994624476487651e-03, -1.517980857578944e-02, -7.149671640494347e-02, -5.235034997215294e-01, -7.351362971455519e+00, -3.538529734440464e+02, -3.312174808838671e+04, -1.961329348093618e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_edf1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_edf1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.263379397588791e-02, -1.325207037359193e-02, -1.419847999418590e-02, -1.568772290399897e-02, -1.812675747074279e-02, -2.235904702404937e-02, -3.033560955947541e-02, -4.717133597582845e-02, -8.778640827627301e-02, -1.934236838248888e-01, -4.405041831035232e-01, -5.994786555218627e-01, -6.865724390261101e-01, -1.275774718016847e+00, -3.274359846653250e+00, -7.413004646081522e+00, 2.147960248875922e+01, 7.511869853284737e+02, 4.781206036741427e+04, 2.103482873090294e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_edf1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_edf1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.368797138123176e-08, 2.746670495081827e-08, 3.395525101953926e-08, 4.598536481458688e-08, 7.086448099831606e-08, 1.309133118312039e-07, 3.107706660197946e-07, 1.033754627853730e-06, 5.281645928963398e-06, 4.382505623514080e-05, 6.608244502790713e-04, 1.147163717974766e-02, 2.535722312894632e-02, 1.276431688870843e-01, 1.271723761237214e+00, 5.386495528993031e+00, -5.095208656817226e+03, -2.430645827114966e+06, -2.062163215099770e+10, -6.691515180370752e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_edf1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_edf1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.021990755249693e-14, -9.847404589514973e-14, -1.320127231938828e-13, -2.004518547864256e-13, -3.623433308972587e-13, -8.320447991389451e-13, -2.616706924697211e-12, -1.179117527185894e-11, -5.135462580216301e-11, 3.733524338346351e-09, 8.762073452706897e-07, -3.002366584120468e-04, -3.906974091225549e-03, -1.463879968268833e-02, 6.491722152376589e-02, 2.972492278862269e+02, 1.231499307270559e+06, 3.974753468038242e+10, 4.771290443246394e+16, 1.573633635646547e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
