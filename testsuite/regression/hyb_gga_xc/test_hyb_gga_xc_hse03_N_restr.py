
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hse03_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse03", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.310087662395271e+00, -3.248074761180478e+00, -3.161274266748547e+00, -3.041234271955066e+00, -2.878089587002789e+00, -2.661850978661263e+00, -2.385329279348612e+00, -2.048858902511112e+00, -1.663821335969403e+00, -1.250792195105824e+00, -8.483897866082517e-01, -5.668232135120891e-01, -4.987149965838434e-01, -4.164869431634763e-01, -3.080318339484800e-01, -2.012337877212330e-01, -1.115408012737988e-01, -4.201833864141444e-02, -8.772729293487561e-03, -9.701665794389387e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hse03_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse03", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.172607829945363e+00, -4.084433524778714e+00, -3.960698623480964e+00, -3.788954568361847e+00, -3.554356126940746e+00, -3.241434996362663e+00, -2.839274319730047e+00, -2.354670513713958e+00, -1.836652553906698e+00, -1.329703544722973e+00, -8.742803246642712e-01, -7.054297850851564e-01, -6.427934123680286e-01, -5.128134253263892e-01, -3.618393877349718e-01, -2.062048019663355e-01, -1.263411179756360e-01, -5.530859717715504e-02, -1.169585085635209e-02, -1.293554023386951e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse03_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse03", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.271753742684976e-06, -2.486220821706396e-06, -2.828394320926963e-06, -3.398756043150308e-06, -4.409149994038069e-06, -6.352600506881129e-06, -1.050249233632729e-05, -2.041436161725080e-05, -4.594131744471389e-05, -1.303637248145973e-04, -6.505252998161913e-04, -2.426276380774400e-03, -5.637896135780428e-04, -9.189111669409857e-03, -3.333892944568321e-02, -2.863686428085133e-01, -1.224679142074424e+00, -9.325772655153592e-01, 6.036659648291788e-03, 1.504922553420553e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse03_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse03", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.011174211118200e-02, -1.061416754431330e-02, -1.137811870450024e-02, -1.256525845429242e-02, -1.446080484494455e-02, -1.757017687722323e-02, -2.266300711480669e-02, -2.975536795553222e-02, -3.349418270717924e-02, -8.742207361824877e-02, -3.008078250798829e-01, -4.828286313006117e-01, -5.278034302924168e-01, -9.843896524014586e-01, -1.684994882345691e+00, -3.575938179211148e+00, 1.820678076275735e+00, -3.586271742867915e+02, -1.364211369819990e+04, -1.116820700037707e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse03_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse03", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.804947512609217e-08, 3.218895147708388e-08, 3.915631575429999e-08, 5.166074177583887e-08, 7.610663615227086e-08, 1.291399828432147e-07, 2.546860539632530e-07, 5.048963228117368e-07, -1.140727761304881e-07, 6.852610642288492e-06, 3.583269063900477e-04, 1.199480398146565e-02, 2.514577824669559e-02, 1.122365627609968e-01, 2.105602926160292e-01, -6.210435905395304e+00, -2.649471649340821e+03, -4.367848461948558e+05, 1.380746113142922e+05, 2.578585853613300e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_hse03_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse03", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.312510095946682e-13, -1.572461329638695e-13, -2.029281125999900e-13, -2.893869547047944e-13, -4.669734447891962e-13, -8.385778541449152e-13, -1.099687979052377e-12, 1.319560586510738e-11, 4.585354707296625e-10, 8.718162116913686e-09, 4.325091273297762e-07, -6.159453149676493e-04, -9.377559847401289e-03, -2.410158113978583e-02, 3.202066673278943e-01, 1.995749821443081e+02, 2.953907192657370e+05, 1.072766986837679e+09, -4.600982050329903e+10, -6.593259128892691e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
