
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_dk_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_dk", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.420557037704111e+01, 9.055898901622321e+01, 8.557358567619994e+01, 7.890730585911975e+01, 7.027180928095231e+01, 5.957974994161963e+01, 4.715989515131110e+01, 3.394987145528027e+01, 2.139931541811379e+01, 1.091404436362420e+01, 4.513026833304073e+00, 2.205171025245163e+00, 1.624397298690581e+00, 1.101072706031313e+00, 5.493656808481042e-01, 1.658020078565921e-01, 2.534014228929224e-01, 5.510679251693684e-01, 5.967660219959350e-01, 5.727830994345667e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_dk_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_dk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.485463211061906e+02, 1.424620292973573e+02, 1.341462378525640e+02, 1.230325102133351e+02, 1.086515997329928e+02, 9.089322337990201e+01, 7.042285183476125e+01, 4.922082132531551e+01, 3.103691120373479e+01, 1.886083527964963e+01, 8.618724914975795e+00, 3.342735885488419e+00, 2.603598150354686e+00, 1.631800432363137e+00, 8.466067154493523e-01, 1.928885929548803e-01, -7.345906664003752e-01, -7.696329060320890e-01, -6.088415673928187e-01, -5.729326327250504e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_dk_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_dk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.080596628915342e-05, 9.680396139700956e-05, 1.060946625412902e-04, 1.209382913213832e-04, 1.456790725739601e-04, 1.892284152089764e-04, 2.704550158208593e-04, 4.220700235969533e-04, 5.840111259072508e-04, -2.699187804978200e-04, -2.921839547009627e-03, 2.668479299553200e-02, 3.853714577174836e-02, 7.553871933709908e-02, 6.501859919901390e-02, 4.468460386448043e-01, 7.842718761534576e+01, 3.803886813924023e+03, 4.365673105227786e+05, 3.229819046050643e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_dk_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_dk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.093293528856695e-01, 6.233252525850782e-01, 6.439161790311742e-01, 6.743992794661069e-01, 7.196392102824761e-01, 7.855421997127243e-01, 8.701028357525341e-01, 8.930561961615644e-01, 2.746912593688094e-01, -1.284861051445988e+00, 1.494274185898135e+00, 4.079634530701842e+00, 4.529977854330776e+00, 5.605204416766488e+00, -3.714619676261538e+00, 1.421270999465690e+02, 2.444607819911306e+03, 4.106465231086960e+04, 4.194351285397275e+06, 2.967304400641534e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_dk_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_dk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.046458906814696e-07, -6.802399683120065e-07, -8.036394732880031e-07, -1.014671180131629e-06, -1.394709182937178e-06, -2.093181762899587e-06, -3.050732442268114e-06, 1.738741369195500e-06, 1.210954889058079e-04, 1.375399556863801e-03, 5.545743393191437e-03, -3.863088565023357e-02, -1.146394781617314e-01, -1.902168065600817e-01, 1.143788460473549e+01, -7.019089390906205e+02, -1.995232283837593e+05, -1.284572654874116e+08, -1.528908401851262e+12, -8.365679046872306e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_dk_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_dk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.047181169094939e-12, 1.206632323678602e-12, 1.450800506349204e-12, 1.785498207152146e-12, 1.899793060836457e-12, -1.565243661795297e-12, -4.730735885953551e-11, -7.805761188837667e-10, -1.967527798178867e-08, -5.350436962840722e-07, -9.926850958346586e-06, -3.575208321128546e-04, 7.770121111812537e-03, -6.072318658508628e-02, -1.169188885925289e+01, 3.553025760743063e+03, 8.111832200283587e+06, 2.314116710804966e+10, 1.082348254000328e+14, 7.718407052982888e+18]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
