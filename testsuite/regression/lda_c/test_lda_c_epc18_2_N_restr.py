
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_epc18_2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.471064279410795e-03, -1.565074041843462e-03, -1.710889015850682e-03, -1.944688935326363e-03, -2.337982690124603e-03, -3.047277509308573e-03, -4.463811565870720e-03, -7.758006200186467e-03, -1.745338751255005e-02, -5.786304678921223e-02, -1.269140628590119e-01, -5.110741168531970e-02, -3.172687247322339e-02, -1.518445213798187e-02, -4.442498119990879e-03, -7.506917823103521e-04, -6.298358744014307e-05, -2.063182963176352e-06, -1.830872691298757e-08, -2.474870125360901e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_epc18_2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.693522939748413e-05, 1.914197493257603e-05, 2.282513002851653e-05, 2.938670544056504e-05, 4.222582037782046e-05, 7.097595225709702e-05, 1.491046287738957e-04, 4.286511487816139e-04, 1.869947626211939e-03, 9.063844680049532e-03, -1.839472992533118e-01, -1.106868026553386e-01, -6.832785765179471e-02, -3.183522605262189e-02, -9.032727547532956e-03, -1.505841486732818e-03, -1.259988804194253e-04, -4.126399979092037e-06, -3.661745650765026e-08, -4.949740251211801e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_epc18_2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.892009630892697e-07, -2.273559413567229e-07, -2.960250451095082e-07, -4.324175710704326e-07, -7.447006628242635e-07, -1.622330513217094e-06, -4.935255153897683e-06, -2.397053081586551e-05, -2.131989140660494e-04, -5.506706079227049e-04, 9.179690603801628e-02, -2.042322709651768e-01, -1.976513193358676e-01, -1.691976788442388e-01, -1.414300726002719e-01, -1.305027511898501e-01, -1.283988386497822e-01, -1.282114763690285e-01, -1.282051845396654e-01, -1.282051282812781e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
