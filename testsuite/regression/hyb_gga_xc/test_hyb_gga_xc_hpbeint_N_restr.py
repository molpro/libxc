
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hpbeint_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hpbeint", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.608097796789300e+00, -3.538262076412504e+00, -3.440435246254048e+00, -3.304987383173047e+00, -3.120575280326285e+00, -2.875500545606783e+00, -2.560968484364924e+00, -2.177149666872370e+00, -1.741910192070956e+00, -1.295438358093221e+00, -8.714693976459289e-01, -5.890124422368358e-01, -5.189036473643142e-01, -4.237467499646293e-01, -3.010895904385369e-01, -1.890414207452306e-01, -1.002752467430593e-01, -3.489738776059396e-02, -7.307872272074603e-03, -8.084680894172535e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hpbeint_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hpbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.670618370338120e+00, -4.574650472654238e+00, -4.440015337665931e+00, -4.253174864993823e+00, -3.997873052516958e+00, -3.656606604706567e+00, -3.214340334610903e+00, -2.665717263423767e+00, -2.028370074057144e+00, -1.376027378049079e+00, -8.889832646496492e-01, -7.653729243911526e-01, -6.828030516746306e-01, -5.495316547141829e-01, -3.651909758042949e-01, -1.931090119064248e-01, -1.119229670563178e-01, -4.543858148119296e-02, -9.732917556267130e-03, -1.077941904025020e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hpbeint_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hpbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.268848777484520e-06, -1.387663490580157e-06, -1.577618719450069e-06, -1.895584289955407e-06, -2.463926535916337e-06, -3.579263169577745e-06, -6.076819482018764e-06, -1.279401461224073e-05, -3.579061960985554e-05, -1.386661583369213e-04, -7.135916058522196e-04, -5.978223213369441e-04, 1.461778002283092e-03, -1.868154763126078e-03, -2.805463438052024e-02, -3.039789744547301e-01, -1.464922829284406e+00, -2.455692552963139e+00, -2.970776972969736e+00, -3.287500338432665e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hpbeint_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hpbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.001420974560822e-02, -1.048734786387306e-02, -1.120953118691235e-02, -1.234138343054275e-02, -1.418487863194443e-02, -1.736085019416990e-02, -2.329789554953547e-02, -3.574597665422054e-02, -6.556131375722495e-02, -1.373979558997817e-01, -3.123374517492158e-01, -4.713617883687239e-01, -5.325052239210093e-01, -1.007089562964547e+00, -3.100311299239553e+00, -7.216725163688851e+00, 2.500544765279926e+01, -3.397479031794463e+02, -1.120656898216595e+04, -9.305118624688012e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hpbeint_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hpbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.654992021473586e-08, 1.908028090961846e-08, 2.340315696903407e-08, 3.136469327548822e-08, 4.769477509881296e-08, 8.675735405297987e-08, 2.029150934945165e-07, 6.692375021164884e-07, 3.401032508009404e-06, 2.550953215077456e-05, 3.711612082187217e-04, 7.406506377553682e-03, 7.418382662222096e-03, 8.583688241795689e-02, 1.431161089667128e+00, 1.303533449799625e+01, -4.203699138622620e+03, -2.941778967984279e+05, -4.148929162093075e+07, -3.405835716650284e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hpbeint_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hpbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.704400326032535e-14, -1.056939817257219e-13, -1.396483341074479e-13, -2.081615205512131e-13, -3.683073044142538e-13, -8.295358351151261e-13, -2.605805934579481e-12, -1.258108786189691e-11, -8.727441264065468e-11, 1.923678082972043e-09, 5.300288264045668e-07, -5.568747577111109e-04, -5.140315068380311e-03, -3.115833652298544e-02, -9.357664813456166e-01, 1.010847381700010e+02, 4.161529990404032e+05, 8.909046335790441e+08, 1.507085843413461e+13, 9.601633803056325e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
