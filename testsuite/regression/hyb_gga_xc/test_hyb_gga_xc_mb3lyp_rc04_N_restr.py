
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mb3lyp_rc04_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mb3lyp_rc04", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.537257028040810e+00, -3.471490691512809e+00, -3.379384236418152e+00, -3.251893360975412e+00, -3.078375601971459e+00, -2.847852775786718e+00, -2.551965311023727e+00, -2.190179265506059e+00, -1.776279553680313e+00, -1.339707938110789e+00, -9.099143995324911e-01, -5.956995889855108e-01, -5.134577128220110e-01, -4.324153621980844e-01, -3.174108859971133e-01, -1.988294576863059e-01, -1.105538495441684e-01, -7.322705486803915e-02, -4.396549438092166e-02, -2.942338958717200e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mb3lyp_rc04_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mb3lyp_rc04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.414579451842659e+00, -4.323758206398246e+00, -4.196476598868169e+00, -4.020126725891804e+00, -3.779781059461670e+00, -3.459882878336292e+00, -3.048403832632884e+00, -2.544886796976638e+00, -1.973686908433506e+00, -1.401981980681905e+00, -9.412403356335641e-01, -7.234698041947197e-01, -6.469714715917516e-01, -5.207849001242690e-01, -3.632668344322114e-01, -2.226979618465359e-01, -1.125688114633456e-01, -3.953053067823809e-02, -1.397932880080250e-02, -5.057162429493251e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mb3lyp_rc04_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mb3lyp_rc04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.932669388605008e-06, -3.160918657737280e-06, -3.519419112322407e-06, -4.104276958575015e-06, -5.111273396826152e-06, -6.982269671971079e-06, -1.084903736821495e-05, -2.009976787391290e-05, -4.700717050442343e-05, -1.476682953910483e-04, -6.920534190017271e-04, -4.558084913309869e-03, -9.115020120026912e-03, -1.686463413662666e-02, -5.054728293987276e-02, -2.050062084870619e-01, -1.602649745154709e+00, -1.268135248832186e+02, -1.215203049396450e+04, -7.225559591111589e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mb3lyp_rc04_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mb3lyp_rc04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.411588251062459e-03, -9.827646887024390e-03, -1.045737675816398e-02, -1.143159480553288e-02, -1.298608016393083e-02, -1.557576056407108e-02, -2.014978492786920e-02, -2.884778057700274e-02, -4.665767336276345e-02, -8.335367827375369e-02, -1.655365564812748e-01, -4.182450293094486e-01, -5.357575093036838e-01, -8.518855549219839e-01, -1.586178546150989e+00, -1.430623273164583e+00, 7.691574696140117e+00, -5.231287154465356e+00, 1.046545511446898e+04, 7.247565125056171e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mb3lyp_rc04_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mb3lyp_rc04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.469040737555899e-08, 1.665322452395131e-08, 1.992632488164462e-08, 2.574130008013380e-08, 3.703762817354010e-08, 6.188833916494730e-08, 1.265981239847248e-07, 3.354083917621358e-07, 1.171596416523641e-06, 3.872769449205334e-06, -2.821397293015969e-05, 4.853389225502935e-03, 1.988009122440288e-02, 4.181840365525070e-02, -4.346794928883768e-02, -2.541767403325562e+01, -3.939050161749658e+03, -8.184122513227419e+05, -7.277829808496783e+09, -2.455467461714594e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mb3lyp_rc04_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mb3lyp_rc04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.572046575474118e-14, 9.444993953184407e-14, 1.296930064216833e-13, 2.042902255605065e-13, 3.912602516811669e-13, 9.884095059825132e-13, 3.685288127392601e-12, 2.360946722478852e-11, 3.173570996649001e-10, 1.153624663607475e-08, 1.535075238511385e-06, 3.741132441716771e-04, 3.291063362626283e-03, 2.211564449060911e-02, 9.424157681586556e-01, 2.652462847368359e+02, 5.409872726484596e+05, 1.437794882653420e+10, 1.742695369751931e+16, 5.795234463853570e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
