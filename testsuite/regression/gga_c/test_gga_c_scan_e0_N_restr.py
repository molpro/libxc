
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_scan_e0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_scan_e0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.983194557119900e-02, -6.897711577212301e-02, -6.775953935309348e-02, -6.603302812705891e-02, -6.360126779024343e-02, -6.021195055554011e-02, -5.556948488720157e-02, -4.940693080494007e-02, -4.172837885550414e-02, -3.354050500639883e-02, -2.960160357161575e-02, -4.818697600223078e-02, -5.425632300840672e-02, -4.224893848110253e-02, -3.016590735348590e-02, -1.881992735692770e-02, -9.314000117619839e-03, -3.049829182202831e-03, -4.765057136709021e-04, -2.375345719458493e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_scan_e0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_scan_e0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.238818614842984e-01, -1.227613265082889e-01, -1.211439931325195e-01, -1.188071182782555e-01, -1.154273935541884e-01, -1.105399963653877e-01, -1.035005531183389e-01, -9.352217285698144e-02, -8.007921733363223e-02, -6.461631084883449e-02, -5.661415296775412e-02, -8.015083332869236e-02, -7.877284236338414e-02, -7.043725211096286e-02, -5.419195198253584e-02, -3.483726075676328e-02, -1.733992813465133e-02, -5.740508577695786e-03, -9.204485252450309e-04, -4.693313750333884e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_scan_e0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_scan_e0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.638944100090600e-07, 5.979339202597505e-07, 6.502559399036428e-07, 7.329757739688884e-07, 8.690298576162493e-07, 1.105486700394822e-06, 1.549014568735929e-06, 2.474289614805008e-06, 4.736925077345446e-06, 1.222029928521035e-05, 6.969377941886804e-05, 2.300884411177751e-03, 7.236991681143295e-03, 9.245971646762309e-03, 2.050182450347018e-02, 7.700253428740389e-02, 4.667433567137934e-01, 4.776388718907620e+00, 8.711502438826332e+01, 3.349461040339582e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_scan_e0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_scan_e0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.458729633237256e-04, -3.713421781926437e-04, -4.109590758116427e-04, -4.746523046453379e-04, -5.818860687254203e-04, -7.742226997813028e-04, -1.149664807177015e-03, -1.966557110233693e-03, -3.996064345695650e-03, -9.943100090911714e-03, -3.178778773110002e-02, -4.333482900199603e-02, -1.676900023752759e-02, -1.161454920729312e-01, -5.024133461085746e-01, -2.392262503291254e+00, -1.524424276532238e+01, -1.576481829917270e+02, -2.991295061232609e+03, -1.183909476972630e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_scan_e0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_scan_e0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.434688674269445e-09, 3.936348806830240e-09, 4.784294873305359e-09, 6.320785230862231e-09, 9.393754804911189e-09, 1.645719935565153e-08, 3.617316503845009e-08, 1.080960605333656e-07, 4.868311877694781e-07, 3.876245503776893e-06, 8.128578899437728e-05, 2.479461617906838e-03, -2.353323107327161e-03, 3.023980812659124e-02, 4.017676454491295e-01, 1.128790891046409e+01, 8.894073606449635e+02, 2.828715228327393e+05, 5.909656173760812e+08, 1.714463309741849e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_scan_e0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_scan_e0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.089857526469283e-14, -1.099198238819888e-13, -1.443729895848057e-13, -2.133913645186293e-13, -3.731337413302064e-13, -8.276959144691287e-13, -2.564178807170503e-12, -1.264608219250610e-11, -1.192035632596195e-10, -2.913695926457235e-09, -4.028146130212708e-07, -6.453825299000846e-04, -8.430984858360304e-03, -3.513101783887051e-02, -8.175042717813578e-01, -1.148531568388682e+02, -1.092717240853713e+05, -1.128820364241053e+09, -2.775315943565255e+14, -6.115282084014662e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
