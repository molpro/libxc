
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_gaploc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gaploc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.067121407037260e-02, -7.783074035564948e-02, -7.376059403040465e-02, -6.799914484157100e-02, -6.006484546869173e-02, -4.973805887461956e-02, -3.762374451140808e-02, -2.557756294414831e-02, -1.602086249077684e-02, -1.038990756803174e-02, -8.829162405632021e-03, -5.967245373408544e-02, -6.389401330669586e-02, -4.812845222809307e-02, -1.177027298603747e-02, -5.694381662553256e-03, -3.294981717079969e-03, -8.142393879566069e-04, -4.383808646705743e-05, -5.721547953368043e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_gaploc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gaploc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.997636427574433e-01, -2.977106334001476e-01, -2.929325273958066e-01, -2.825923511148866e-01, -2.618827518463978e-01, -2.248481194298383e-01, -1.696384546150228e-01, -1.067790285433802e-01, -5.542119056321067e-02, -2.662384233804548e-02, -1.967867761727051e-02, -1.440266707387525e-01, -7.325910525673575e-02, -1.496495263301575e-01, -4.947399315257303e-02, -9.243422099601169e-03, -6.858529988549364e-03, -2.647319966346030e-03, -1.587963601090075e-04, -2.096112469235060e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gaploc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gaploc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.432642222040457e-06, 2.601783682690362e-06, 2.841173240319419e-06, 3.170218173677087e-06, 3.594339692529007e-06, 4.072812417908173e-06, 4.492012120469058e-06, 4.751067052387225e-06, 5.012563885827564e-06, 6.496563093556848e-06, 2.838949929993540e-05, 6.468184273400395e-03, 5.626951745285796e-04, 3.674018412717839e-02, 3.504343613549139e-02, 1.648291244243299e-02, 2.364125963125409e-01, 4.101600051639216e+00, 3.125499495408625e+01, 3.221699720851836e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gaploc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gaploc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.137661457049661e-04, -9.987189773184419e-04, -1.926509665230463e-03, -3.390857815418100e-03, -5.600203609806289e-03, -8.527885590286294e-03, -1.141635970575669e-02, -1.294603345272681e-02, -1.304408396443385e-02, -1.360581865723156e-02, -3.117352643249886e-02, 8.236377414399838e-01, 1.930836652101806e-02, 1.972186206503166e+00, -4.589533219518944e+00, -6.625483193289250e-01, -2.265841968921296e+00, -1.623862421989099e+02, -1.441469476203142e+03, -1.444999034468007e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gaploc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gaploc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.878670732174918e-09, 1.121928520227445e-08, 2.458553194837848e-08, 5.009781375091694e-08, 1.004997312642464e-07, 2.005887961259636e-07, 3.935805732862674e-07, 7.681442901878434e-07, 1.680749005834228e-06, 5.486384175905444e-06, 8.216542797088017e-05, -7.136593167789333e-02, -1.533626048363123e-02, -7.951499505715645e-01, 4.342477754321264e+00, 3.072625797411493e+00, 1.420710195555670e+02, 3.613532875337384e+05, 3.915426804033360e+08, 3.054487710250240e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gaploc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gaploc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.724969889467376e-13, -4.132108500102463e-13, -6.892146949632013e-13, -1.282151466281841e-12, -2.692702919119281e-12, -6.429950539848387e-12, -1.760236533839069e-11, -5.819892509887518e-11, -2.791129682827371e-10, -2.951732459579523e-09, -2.954066763993445e-07, 4.737755361984788e-03, 5.125052759139757e-03, 2.117104907492414e-01, -4.934327243235915e+00, -2.766892744261650e+01, -3.588709609970281e+04, -1.283754176534431e+09, -1.560397307011693e+14, -9.397440017638356e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
