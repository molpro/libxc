
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_chachiyo_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_chachiyo", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.043518807583070e-02, -5.948449410712636e-02, -5.812909129383509e-02, -5.620434493120907e-02, -5.348723634810618e-02, -4.968684206693774e-02, -4.445322763712138e-02, -3.745328740490076e-02, -2.866423083953885e-02, -1.931863372252752e-02, -1.498114920390605e-02, -4.161847819709471e-02, -5.078744363397436e-02, -3.562221531528001e-02, -1.992361312819613e-02, -6.498926117649810e-03, -3.760335790240702e-04, -9.486321339917256e-09, -1.665895009161749e-39, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_chachiyo_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_chachiyo", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.240688923474981e-01, -1.228003551700721e-01, -1.209686370124108e-01, -1.183200597472567e-01, -1.144843263350950e-01, -1.089226851294491e-01, -1.008679569189705e-01, -8.931768227383884e-02, -7.339562483795917e-02, -5.445738940368575e-02, -4.570977091308159e-02, -8.463133693281626e-02, -8.050334952330215e-02, -7.491031566687140e-02, -5.584502468062760e-02, -2.625395578687613e-02, -2.626274966859599e-03, -1.611560187821605e-07, -1.269980225607831e-37, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_chachiyo_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_chachiyo", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.768238679293967e-07, 7.173907910282452e-07, 7.797285304745843e-07, 8.782428036412316e-07, 1.040174055702991e-06, 1.321301440136794e-06, 1.847401487617928e-06, 2.938065752295292e-06, 5.554648908649795e-06, 1.382235673185368e-05, 7.987716080497315e-05, 3.262003811385170e-03, 9.339862953569526e-03, 1.374808551346474e-02, 3.291783274620261e-02, 1.034495545084234e-01, 1.454895835177674e-01, 3.001239107321100e-04, 2.561477511258816e-32, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_chachiyo_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_chachiyo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.479674229991016e-04, -4.809278317299594e-04, -5.321846623074707e-04, -6.145853914828101e-04, -7.533839011366035e-04, -1.002851319940590e-03, -1.492714422242603e-03, -2.574075089011938e-03, -5.340062042953440e-03, -1.379365245232084e-02, -4.757057492593265e-02, -4.006934583248897e-02, 3.748730087642443e-03, -1.079695449749408e-01, -8.109560744161859e-01, -5.088787279559781e+00, -1.421259329237024e+01, -7.719978921574441e-02, -3.321289386508390e-29, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_chachiyo_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_chachiyo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.683099882859627e-09, 5.363859336216347e-09, 6.513620982865671e-09, 8.594945615038695e-09, 1.275319173118673e-08, 2.230533584614523e-08, 4.900206106543480e-08, 1.470386151218662e-07, 6.725123863383830e-07, 5.526342465098036e-06, 1.257699541269602e-04, 2.193932879312759e-03, -1.068196900550485e-02, 2.687882954325555e-02, 7.130199808629569e-01, 2.676012988202914e+01, 9.311353190073804e+02, 1.541913537919454e+02, 6.805060130305820e-24, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_chachiyo_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_chachiyo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.166417224702176e-13, -1.410791927523569e-13, -1.853507056590058e-13, -2.740624585523649e-13, -4.794809231404437e-13, -1.064525339821897e-12, -3.303409366926691e-12, -1.634935049951701e-11, -1.550604778740925e-10, -3.810077380792217e-09, -5.568000643203764e-07, -8.182463470219794e-04, -8.075724995381112e-03, -4.614777029690009e-02, -1.406066363218136e+00, -2.210812099334007e+02, -7.827474386117823e+04, -3.461000626503174e+05, -1.442699285921213e-18, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
