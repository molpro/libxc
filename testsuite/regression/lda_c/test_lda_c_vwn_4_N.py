
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vwn_4_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_4", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.185824110986919e-01, -1.179948578933694e-01, -1.171517400901301e-01, -1.159432736626720e-01, -1.142140702308004e-01, -1.117459502245969e-01, -1.082363261039083e-01, -1.032743444358354e-01, -9.632905034851595e-02, -8.682314765557812e-02, -7.438348943947842e-02, -6.121087033500095e-02, -5.734344215336316e-02, -5.312945187121966e-02, -4.463672038688572e-02, -3.274835489613294e-02, -1.950178776609867e-02, -8.412322042316588e-03, -2.302725678432777e-03, -3.205688053188601e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vwn_4_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_4", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.281836049584920e-01, -1.281853890694538e-01, -1.275855346485293e-01, -1.275893245191045e-01, -1.267263928181026e-01, -1.267345374045106e-01, -1.254928464112685e-01, -1.255106459365082e-01, -1.237227832013256e-01, -1.237626423858868e-01, -1.211839891154296e-01, -1.212764690195000e-01, -1.175407998546327e-01, -1.177667764398091e-01, -1.122921266393612e-01, -1.128877794784120e-01, -1.046174559236280e-01, -1.063689688792684e-01, -9.289710411985408e-02, -9.883884264130770e-02, -7.432228386623180e-02, -9.604497837374366e-02, -5.646047018670784e-02, -1.084093709588005e-01, -5.278867001519525e-02, -1.066407838355456e-01, -4.937101460922810e-02, -9.686091278785010e-02, -4.180238089886107e-02, -8.574555849937200e-02, -3.112631466803495e-02, -7.155915561074455e-02, -1.932206556143460e-02, -5.272049648338348e-02, -9.146073643867939e-03, -2.923606503010987e-02, -2.808160589075152e-03, -8.898263304928352e-03, -4.167128761531275e-04, -1.078701107772608e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vwn_4_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_4", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.547388253586578e-04, -4.637083858385134e-04, 3.547572605651579e-04, 3.751798302914048e-04, -4.909466094867137e-04, 3.752214493763978e-04, 4.066011021368520e-04, -5.328890855167116e-04, 4.066987189908648e-04, 4.563134132809251e-04, -5.994207336536205e-04, 4.565552966056858e-04, 5.382686242166389e-04, -7.095463351686148e-04, 5.389172080811992e-04, 6.815182663495562e-04, -9.032799558304819e-04, 6.834662061103310e-04, 9.534137636274847e-04, -1.275074717963281e-03, 9.602983518640511e-04, 1.531528212358171e-03, -2.082455688853747e-03, 1.562244551145177e-03, 2.952324435724580e-03, -4.165628563907477e-03, 3.142825047947545e-03, 6.884710587104288e-03, -1.085859664668712e-02, 8.709371759542839e-03, 1.450254481115784e-02, -3.532832911781014e-02, 3.940469856641415e-02, 1.594535080744784e-02, -9.570124240378558e-02, 2.266475829533892e-01, 2.066791350464509e-02, -1.422230861202878e-01, 3.686760178500145e-01, 3.674488267882657e-02, -2.494796908787581e-01, 6.022392220070143e-01, 8.446461731900218e-02, -7.082328893977707e-01, 1.820595001082752e+00, 2.272738027225773e-01, -3.404025989498454e+00, 1.062055571420888e+01, -8.470883245174260e-02, -2.867965352306926e+01, 1.243214017857534e+02, -3.712459146264287e+01, -4.321662840112932e+02, 2.921970747625909e+03, -2.371705711245488e+03, -1.290507963003628e+04, 1.420548020055112e+05, -3.264726992038259e+05, -1.070514781301765e+06, 2.467778515996331e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
