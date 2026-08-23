
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_q2d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_q2d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.417108587788960e-02, -6.312796589262121e-02, -6.163243917500168e-02, -5.949143492384200e-02, -5.643343665643572e-02, -5.208365594441473e-02, -4.595046303671098e-02, -3.749548132611108e-02, -2.659861829378507e-02, -1.532518990874959e-02, -1.129238650329644e-02, -4.304651389187448e-02, -5.250728618616060e-02, -3.667935548944332e-02, -1.931673551924256e-02, -5.203763491533163e-03, -3.661616835336291e-04, -7.347572917370539e-06, -2.546921657428010e-05, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_q2d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_q2d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.321999090466909e-01, -1.312299880505087e-01, -1.298215732384752e-01, -1.277663442483104e-01, -1.247433965885015e-01, -1.202384387899950e-01, -1.133768082064277e-01, -1.025680977162788e-01, -8.503586326987791e-02, -5.956206256921064e-02, -4.730817395172793e-02, -8.869110689058124e-02, -8.266015900665515e-02, -7.911972268521519e-02, -6.027737531066083e-02, -2.417631782477929e-02, -2.163856995717704e-03, -1.062945122623178e-05, 1.100315351370655e-04, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_q2d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_q2d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.179450602930434e-07, 7.660135488998935e-07, 8.405876497142493e-07, 9.600731150052708e-07, 1.160388956293730e-06, 1.517953907708234e-06, 2.212405867959392e-06, 3.713080115020963e-06, 7.366101146377259e-06, 1.784172857563025e-05, 9.622329645813979e-05, 3.462981452419956e-03, 9.453050531353396e-03, 1.488347043525719e-02, 3.784870015322871e-02, 1.010269032377345e-01, 1.208402376371158e-01, -3.014855519784445e-03, -4.543373957516025e+01, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_q2d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_q2d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.865464362973119e-04, -3.099319299723887e-04, -3.469609020833685e-04, -4.081523283079129e-04, -5.157476861964643e-04, -7.228081560129890e-04, -1.176765985794157e-03, -2.369126024906766e-03, -6.233186224561093e-03, -2.016266461030453e-02, -6.930065018131741e-02, -2.502363053444933e-02, 9.689090030976075e-03, -7.381229183799856e-02, -9.085273013063565e-01, -6.011112104519144e+00, -1.046461609333936e+01, -7.255923175094194e+00, -1.698500639313965e+03, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_q2d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_q2d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.795078339612521e-09, 3.231486131868026e-09, 3.980616930331208e-09, 5.370842369686505e-09, 8.258501705142328e-09, 1.531873651943733e-08, 3.717009056772838e-08, 1.318369635959918e-07, 7.756473179831647e-07, 8.094358352735849e-06, 1.843162668187128e-04, 9.102814718096294e-04, -1.282799964996877e-02, 1.304656906013744e-02, 7.925759404448313e-01, 3.177558136752855e+01, 7.038023281178672e+02, 1.757476343209692e+04, 5.780398577687931e+08, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_q2d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_q2d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.918706481432516e-14, -1.205911033438975e-13, -1.596854284917627e-13, -2.390104712444085e-13, -4.263373802458517e-13, -9.770336354238760e-13, -3.198223558859097e-12, -1.732803990826165e-11, -1.888994216932881e-10, -5.276357307528123e-09, -7.554796680605813e-07, -7.538492556429800e-04, -7.510445970613039e-03, -4.391829898723498e-02, -1.580897498901929e+00, -2.454183961763358e+02, -6.127188948125816e+04, -4.357793478145982e+07, -1.343044531924130e+14, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
