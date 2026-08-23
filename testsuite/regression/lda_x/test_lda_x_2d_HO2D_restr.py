
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_2d_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_2d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.488250390729645e-01, -8.488228756321776e-01, -8.488171832441006e-01, -8.488022249275939e-01, -8.487629999285811e-01, -8.486604872542884e-01, -8.483940254474867e-01, -8.477073965700941e-01, -8.459622617844099e-01, -8.416215096036438e-01, -8.311777788385252e-01, -8.072823673703506e-01, -7.565342460979354e-01, -6.598822574255163e-01, -5.028958253921672e-01, -3.013881696191547e-01, -1.197667105539729e-01, -2.399411429987852e-02, -1.559362320936443e-03, -1.612963388541866e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_2d_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_2d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.273237558609447e+00, -1.273234313448266e+00, -1.273225774866151e+00, -1.273203337391391e+00, -1.273144499892872e+00, -1.272990730881433e+00, -1.272591038171230e+00, -1.271561094855141e+00, -1.268943392676615e+00, -1.262432264405466e+00, -1.246766668257788e+00, -1.210923551055526e+00, -1.134801369146903e+00, -9.898233861382745e-01, -7.543437380882507e-01, -4.520822544287320e-01, -1.796500658309594e-01, -3.599117144981778e-02, -2.339043481404664e-03, -2.419445082812799e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_2d_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_2d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.000001559901923e+00, -1.000004108660002e+00, -1.000010814946794e+00, -1.000028437989996e+00, -1.000074653617322e+00, -1.000195456139384e+00, -1.000509595419487e+00, -1.001319991533881e+00, -1.003385613639932e+00, -1.008560681340624e+00, -1.021233224428728e+00, -1.051461542411424e+00, -1.121993310329130e+00, -1.286330028736355e+00, -1.687877131401608e+00, -2.816389124461600e+00, -7.087331356355915e+00, -3.537644076160264e+01, -5.443419734850526e+02, -5.262527154594142e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
