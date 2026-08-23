
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ob_pw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.171793140279986e-01, -1.165794405359694e-01, -1.157186200501037e-01, -1.144847448486654e-01, -1.127191537181580e-01, -1.101991683194754e-01, -1.066163815482684e-01, -1.015538021235041e-01, -9.448149444026072e-02, -8.489949713118659e-02, -7.348424374991210e-02, -6.554364912046008e-02, -6.225897760294208e-02, -5.718098228035487e-02, -4.875955561620743e-02, -3.754532129721705e-02, -2.485816474742935e-02, -1.243083584833656e-02, -2.966031313239955e-03, -2.658842678222008e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ob_pw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.269826184568110e-01, -1.263732767343625e-01, -1.254986023202784e-01, -1.242443081108216e-01, -1.224483115965939e-01, -1.198823956608628e-01, -1.162288354280281e-01, -1.110542551047635e-01, -1.037987865145187e-01, -9.390967129065592e-02, -8.201866626652787e-02, -7.366013187094186e-02, -7.017820875697089e-02, -6.476410110880347e-02, -5.569334830195882e-02, -4.341786775309993e-02, -2.928293229312110e-02, -1.537567656069748e-02, -4.026748087950813e-03, -3.606692561895676e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ob_pw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.559767770209025e-05, -5.906532079351248e-05, -6.442793746441031e-05, -7.298729598530004e-05, -8.728214817443050e-05, -1.127557994270755e-04, -1.625598654264678e-04, -2.736556016987560e-04, -5.716103034044346e-04, -1.583647283231394e-03, -5.565962549837052e-03, -1.386223681621996e-02, -2.046161347857409e-02, -3.799201306280142e-02, -1.122246150900002e-01, -5.573670136967038e-01, -5.046569343911884e+00, -1.030425549192220e+02, -4.909862814555938e+03, -3.355988088714771e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
