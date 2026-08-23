
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_revscan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.811397806693835e-02, -2.806341777616629e-02, -2.798829677594213e-02, -2.787506705376844e-02, -2.770081097561585e-02, -2.742453144188350e-02, -2.696811743466993e-02, -2.617727597769399e-02, -2.481004008237480e-02, -2.351823906431235e-02, -2.475276955799863e-02, -5.410118378761655e-02, -5.181526059110091e-02, -3.125237984943129e-02, -2.288455035864010e-02, -1.532519886240280e-02, -8.353917577119636e-03, -3.406588093418707e-03, -6.225317057175632e-04, -3.389657292339119e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_revscan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.170303818655148e-02, -4.188834820649890e-02, -4.215368673680950e-02, -4.253317721597150e-02, -4.307587106854928e-02, -4.385514271866495e-02, -4.499230706186303e-02, -4.671634772625110e-02, -4.944877325869543e-02, -5.479019031642442e-02, -4.861824488102113e-02, -9.078865199155582e-02, -6.433108248347598e-02, -5.031988665526333e-02, -4.936410072259496e-02, -2.962237718228993e-02, -2.565055262925143e-02, -8.006107286305320e-03, -1.250936449767905e-03, -6.693201308644362e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revscan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.353320464384005e-07, 3.623496986470887e-07, 4.048168050681107e-07, 4.741663780823326e-07, 5.937482868496236e-07, 8.165955507554138e-07, 1.281024405355561e-06, 2.423278378921607e-06, 6.079690067976490e-06, 2.555680903432692e-05, 1.014497741717062e-04, 5.003166883286042e-03, 1.244995395802304e-02, 2.027163479672303e-02, 5.450718706843670e-02, 7.796629067482050e-02, 2.639507185960434e+00, 1.669201062772973e+01, 1.608526262338078e+02, 4.895271973981176e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revscan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.374934181618483e-04, -4.435324564154650e-04, -4.520408717752602e-04, -4.638824211334279e-04, -4.800266233089882e-04, -5.012888146285969e-04, -5.278446049785654e-04, -5.598656213054637e-04, -6.129785250070326e-04, -8.555022621601217e-04, -4.641493012711219e-04, -2.514354097462160e-03, -1.013752205673660e-02, -2.185921207632732e-02, -2.037343602315946e-02, -1.000703085449522e-03, -1.737198188166610e-02, -2.917210153887689e-03, -1.073947660940319e-04, -3.568237640318811e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revscan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.536655389294689e-06, -7.692075609643511e-06, -1.467838967214219e-05, -2.708491858832838e-05, -5.070941131986874e-05, -9.987250413526811e-05, -2.150677647976394e-04, -5.397450873141382e-04, -1.807158490454920e-03, -7.316707959419371e-03, -2.573538445051352e-02, 8.204743728209098e-02, 5.600364683933501e-01, 8.926249514947193e-02, -2.232890414871047e-01, 5.387075075745248e+00, 1.311423825614455e+02, 1.388404170542047e+03, 7.954920568666974e+03, -1.096614097725453e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revscan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.459501764690589e-09, 1.767493757983433e-09, 2.313739846257838e-09, 3.370166884209666e-09, 5.674041060503207e-09, 1.160351534507420e-08, 3.078574813400514e-08, 1.164398427603936e-07, 7.328996077646225e-07, 8.242604879637999e-06, 1.080365831721152e-04, 5.993182854478816e-03, 5.591917968922136e-02, 4.027330412447169e-02, 7.259471485240918e-01, -1.409203391834018e+02, -2.736270979560785e+04, -9.673756387943890e+06, -8.091746356273186e+09, -8.624563364053229e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revscan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.297184142821406e-06, -3.660614250084755e-06, -4.245472887642558e-06, -5.231427808580447e-06, -7.003919661177893e-06, -1.048369481513552e-05, -1.818330121664578e-05, -3.821324561524166e-05, -1.034585807256712e-04, -3.483576822146742e-04, -4.906912831598963e-04, -1.489349419107873e-02, -2.908067422047287e-01, -1.267278686050398e-01, -3.701220329400443e-01, 1.414727776809519e+01, 2.087496343520485e+02, 2.503163636020708e+03, 1.994971214477858e+04, 1.012323690729548e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revscan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.620672417102539e-14, -9.502291719238205e-14, -1.303257776245424e-13, -2.046609411744013e-13, -3.892326591226366e-13, -9.689929520458711e-13, -3.516458957765765e-12, -2.167230368409659e-11, -2.874651792593888e-10, -1.059542491125604e-08, -5.193209910962735e-07, -1.788959456659228e-03, 2.807970387105231e-03, -1.166517957339665e-01, -2.292562657821956e+00, 2.909487972031774e+03, 5.560285253399086e+06, 6.337739063799466e+10, 6.339848409892073e+15, 1.028047932076934e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revscan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.251619536879158e-11, 7.347674519534589e-11, 9.257611243381150e-11, 1.287264788626802e-10, 2.056867831162149e-10, 3.992571459711913e-10, 1.016034307549104e-09, 3.773043793414350e-09, 2.418958910167015e-08, 2.852267879008496e-07, -5.309146763534018e-07, 3.407854067812988e-04, -4.282970594878786e-02, 7.311062620535271e-02, 2.488533502089091e-01, -2.818530253733716e+02, -4.553682654588823e+04, -1.679261144845132e+07, -1.538409143769099e+10, -5.883650384053995e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revscan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.325656941157468e-08, -2.610889682121639e-08, -3.080826417655084e-08, -3.901644068111135e-08, -5.459289184254591e-08, -8.782913950383244e-08, -1.714999360078130e-07, -4.379626604166162e-07, -1.641383931797145e-06, -6.899837226843689e-06, 2.776343490811891e-05, 1.137279571074996e-03, 1.670776481868863e-01, -5.830446027565402e-03, 1.832406580061053e-01, 2.630659980099230e+01, 3.659135661987892e+02, 4.361336907852398e+03, 3.530903456181016e+04, 1.821272155909579e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
