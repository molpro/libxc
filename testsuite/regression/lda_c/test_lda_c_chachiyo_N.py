
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_chachiyo_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.171614826517508e-01, -1.165590907274702e-01, -1.156946807756305e-01, -1.144557176816981e-01, -1.126829835013462e-01, -1.101531421278470e-01, -1.065571834908037e-01, -1.014778731698442e-01, -9.438299031892462e-02, -8.470615731814225e-02, -7.195198819396191e-02, -5.795392344312975e-02, -5.413912208531842e-02, -5.025003135729540e-02, -4.223406501512771e-02, -3.113777954198676e-02, -1.886375051616171e-02, -8.266942440609543e-03, -2.114999848173535e-03, -2.494907086449058e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_chachiyo_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270048782399110e-01, -1.270072219913586e-01, -1.263914465417025e-01, -1.263964213513315e-01, -1.255099264260249e-01, -1.255206054783059e-01, -1.242435769083682e-01, -1.242668773340800e-01, -1.224249575173032e-01, -1.224770114456011e-01, -1.198131221482572e-01, -1.199334779458535e-01, -1.160569151830740e-01, -1.163495129517697e-01, -1.106238957036996e-01, -1.113893676028734e-01, -1.026163629779254e-01, -1.048421871625627e-01, -9.018205665385728e-02, -9.761023901161790e-02, -6.995662181453660e-02, -9.649125699342322e-02, -5.122851103108039e-02, -1.100652814542224e-01, -4.789533143091577e-02, -1.076089445442238e-01, -4.487938193657610e-02, -9.756143889170281e-02, -3.817547580238800e-02, -8.559061222205787e-02, -2.889365022524927e-02, -7.016798165789692e-02, -1.866738094751778e-02, -5.003850085449118e-02, -9.194117116044107e-03, -2.630560203395387e-02, -2.645017249139195e-03, -7.684474504486103e-03, -3.286177136924566e-04, -9.921330034368381e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_chachiyo_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.817325999519999e-04, -5.934455547823714e-04, 4.817564865100506e-04, 5.091166841129046e-04, -6.278127946648989e-04, 5.091705636666749e-04, 5.511686556680442e-04, -6.806768386223684e-04, 5.512948719474983e-04, 6.176041015540542e-04, -7.644043703298822e-04, 6.179162871383597e-04, 7.269002929886822e-04, -9.026842704772262e-04, 7.277351931898433e-04, 9.173618605617822e-04, -1.145155112541419e-03, 9.198598122265000e-04, 1.277290492616073e-03, -1.608256323251891e-03, 1.286069712089967e-03, 2.037832586632581e-03, -2.606801140267430e-03, 2.076681043626766e-03, 3.891460987907388e-03, -5.156062834370252e-03, 4.129500337286945e-03, 8.982940174705254e-03, -1.321868598166014e-02, 1.122367169155588e-02, 1.891335670900843e-02, -4.173632411783103e-02, 4.851764775876869e-02, 1.608556552653161e-02, -9.158759822348325e-02, 2.068575283088750e-01, 1.938794363637642e-02, -1.301915335825634e-01, 3.168060600085167e-01, 3.591053675921564e-02, -2.325879337740691e-01, 5.318011572651802e-01, 7.714057252359015e-02, -6.325111071298521e-01, 1.517687384989058e+00, 1.591604066108609e-01, -2.781197237913899e+00, 7.759557261936816e+00, -6.893618476484208e-01, -2.150985110693520e+01, 7.688390522728695e+01, -4.512222838000153e+01, -3.270096154683688e+02, 1.672499194889698e+03, -2.521735325225459e+03, -1.056981486810488e+04, 1.002931310068710e+05, -2.756681082558571e+05, -9.611064532346439e+05, 2.503166950355860e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
