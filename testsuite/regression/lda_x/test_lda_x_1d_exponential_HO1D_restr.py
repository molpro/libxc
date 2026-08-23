
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_1d_exponential_HO1D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_exponential", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.278716954220589e-01, -3.278713312674818e-01, -3.278703731054922e-01, -3.278678552150776e-01, -3.278612521980833e-01, -3.278439928893245e-01, -3.277991128146944e-01, -3.276833452130331e-01, -3.273883374307939e-01, -3.266497102320794e-01, -3.248438808823955e-01, -3.205541979934598e-01, -3.106574216225479e-01, -2.883623617931258e-01, -2.396743291519868e-01, -1.473990938889643e-01, -4.341598440068705e-02, -3.190848546886691e-03, -2.388654339276768e-05, -4.418262688648699e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_1d_exponential_HO1D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_exponential", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.993094727451922e-01, -3.993092597283892e-01, -3.993086992371161e-01, -3.993072263429449e-01, -3.993033636540144e-01, -3.992932663906484e-01, -3.992670048805900e-01, -3.991992290224388e-01, -3.990262918193116e-01, -3.985918768585156e-01, -3.975212212192300e-01, -3.949288770397153e-01, -3.886820021249029e-01, -3.732205373288282e-01, -3.325560932932679e-01, -2.294357470621420e-01, -7.565495641652577e-02, -5.930891148621378e-03, -4.586902333569041e-05, -8.632804112544774e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_1d_exponential_HO1D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_exponential", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.703410178264308e-02, -3.703445472153109e-02, -3.703538338435047e-02, -3.703782383532239e-02, -3.704422431889132e-02, -3.706095797543521e-02, -3.710449650877223e-02, -3.721697267784460e-02, -3.750469649059673e-02, -3.823206972381668e-02, -4.005287498878443e-02, -4.462630071199210e-02, -5.659149809763440e-02, -9.174939056922315e-02, -2.189853845870156e-01, -7.471514527169499e-01, -2.376793330750183e+00, -5.578020976449458e+00, -1.104503539988135e+01, -2.018778350604311e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
