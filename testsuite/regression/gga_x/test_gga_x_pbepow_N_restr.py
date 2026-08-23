
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbepow_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbepow", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.309618719932783e+00, -4.228256507847486e+00, -4.114404675757964e+00, -3.957025078479549e+00, -3.743295700687910e+00, -3.460418934805034e+00, -3.099862129885529e+00, -2.665171451884385e+00, -2.181658180118643e+00, -1.683400182067371e+00, -1.145739929321101e+00, -6.670330050340686e-01, -5.631764287174912e-01, -4.749596534444672e-01, -3.605455076226096e-01, -2.456009850581283e-01, -1.256795901367059e-01, -4.212190574642724e-02, -8.771878165864035e-03, -9.701651707498996e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbepow_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbepow", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.355168382855540e+00, -5.239404510738995e+00, -5.076934702981248e+00, -4.851329461078932e+00, -4.542751658877551e+00, -4.129563240735703e+00, -3.592449221886215e+00, -2.923281793728303e+00, -2.156162866738820e+00, -1.473508319261390e+00, -9.860251476391133e-01, -7.894117041531055e-01, -7.136196999253410e-01, -5.440417173511428e-01, -3.327586382783513e-01, -2.267671491449189e-01, -1.510036576918286e-01, -5.547749244118435e-02, -1.168920230127681e-02, -1.293544137870212e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbepow_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbepow", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.195246656299172e-06, -4.552057661864262e-06, -5.118462416747841e-06, -6.057192813873496e-06, -7.712404811716883e-06, -1.090231071179838e-05, -1.788376903876877e-05, -3.613306102005271e-05, -9.497307758744290e-05, -3.102656407874215e-04, -1.442598782679781e-03, -8.021557858790034e-03, -1.385076969470191e-02, -3.315407241900398e-02, -1.394251326475184e-01, -5.392306655875684e-01, -1.123209076525158e+00, -1.543675663353786e+00, -1.806561944608164e+00, -1.992378816017145e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbepow_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbepow", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.287854361244422e-02, -1.352016134853459e-02, -1.450434219602388e-02, -1.605833579715711e-02, -1.861861674045499e-02, -2.310993754810246e-02, -3.173663936295744e-02, -5.005305186714302e-02, -8.320732250129428e-02, -5.170935927396214e-02, 9.116882850104506e-02, -6.398890933241175e-01, -6.994182957301998e-01, -1.401752077513244e+00, -2.555071219134920e+00, 1.149946688068649e+01, 8.882147652721379e+00, -4.904844206832841e+02, -1.354921852236824e+04, -1.116721865873714e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbepow_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbepow", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.123435932023786e-08, 3.603049519028863e-08, 4.423844628218423e-08, 5.939869838637031e-08, 9.064922449157676e-08, 1.660685053395575e-07, 3.934678695496867e-07, 1.297493500700707e-06, 5.088405415673030e-06, -1.272174491560160e-05, -7.877154145665105e-04, 1.725364154609867e-02, 4.491450983949854e-02, 2.053470085583800e-01, 8.475793980578069e-01, -9.634672778892948e+01, -4.076626211909959e+03, -1.894692731664954e+05, -2.528609983078703e+07, -2.064199692608320e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbepow_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbepow", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.749295995861838e-19, 6.454093223723627e-19, 2.111528606425861e-18, 1.068819620223456e-17, 9.380287510867616e-17, 1.578214435707073e-15, 5.318636733458088e-14, 3.337860976361039e-12, 3.111934259362679e-10, 3.335990295322730e-08, 5.286844404690600e-06, 1.252113230227521e-06, 2.335122905581237e-11, 6.002278147743983e-04, 1.815845607659206e+00, 8.466308454462680e+02, 3.797292094364874e+05, 5.710499662350973e+08, 9.180747324294139e+12, 5.819263074163564e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
