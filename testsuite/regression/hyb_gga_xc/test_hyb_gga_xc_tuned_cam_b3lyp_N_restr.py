
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_tuned_cam_b3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_tuned_cam_b3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.967807904489972e+00, -3.892209790170506e+00, -3.786332142201873e+00, -3.639775445322015e+00, -3.440297750900259e+00, -3.175255634399696e+00, -2.834967569783206e+00, -2.418590670651279e+00, -1.941231472343300e+00, -1.434723764386359e+00, -9.335115933071746e-01, -5.800159391491230e-01, -4.885027428211991e-01, -3.953766426587789e-01, -2.624017696083899e-01, -1.216482811681929e-01, -1.874204005518873e-02, -5.871956937366968e-03, -1.384091519798137e-03, -1.675950609211990e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_tuned_cam_b3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_tuned_cam_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.956996393569351e+00, -4.852532212330497e+00, -4.706145288718067e+00, -4.503356621300636e+00, -4.227048437345864e+00, -3.859445655480715e+00, -3.386984006735859e+00, -2.809756878125769e+00, -2.157110660533746e+00, -1.508237142053460e+00, -9.877170499074189e-01, -7.305385552421706e-01, -6.416485781749403e-01, -5.031237334060568e-01, -3.344492517504549e-01, -1.911935945841745e-01, -7.235748564430622e-02, -8.412957790149668e-03, -1.817677214057593e-03, -2.221443642546256e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_tuned_cam_b3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_tuned_cam_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.642670637442560e-06, -3.923844337823349e-06, -4.365042226317422e-06, -5.083772388172795e-06, -6.318561379920828e-06, -8.605031792596594e-06, -1.330487749335931e-05, -2.444642743992078e-05, -5.632225989702375e-05, -1.716965775040157e-04, -7.562239385876282e-04, -4.713022551430512e-03, -9.121735811496468e-03, -1.550639766348782e-02, -3.480652635636074e-02, 3.824619860454673e-02, 3.153615368930862e+00, 4.214798912951917e+00, -6.093766739956105e-04, -1.375182771284634e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_tuned_cam_b3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_tuned_cam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.090747915923095e-02, -1.138922629445271e-02, -1.211806885127028e-02, -1.324483915566221e-02, -1.504063932004764e-02, -1.802609429278379e-02, -2.327814672459371e-02, -3.318287842766237e-02, -5.307669531207682e-02, -9.201338855949219e-02, -1.726511621762805e-01, -4.583643071706239e-01, -5.924574474080980e-01, -8.960104506095034e-01, -1.428758668500686e+00, 3.003660356157227e-01, -2.560080013639613e+00, -1.391922683645694e+02, -1.988746090705929e+03, -1.866990714761852e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_tuned_cam_b3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_tuned_cam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.804829248881505e-08, 2.044000426343174e-08, 2.442217039637556e-08, 3.148032868833666e-08, 4.514170841778484e-08, 7.501725156011173e-08, 1.520104714747596e-07, 3.954390120605093e-07, 1.320010313655013e-06, 3.315096543832390e-06, -7.093667179196562e-05, 4.277583304917515e-03, 1.754856180951843e-02, 2.522758615757388e-02, -3.465186869202447e-01, -3.774961312153671e+01, -3.439820796638200e+03, 1.292562562877768e+05, -7.732446871042017e+03, -1.354985686333108e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_tuned_cam_b3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_tuned_cam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.409658226256923e-14, 1.173051516486877e-13, 1.609424890045091e-13, 2.532000656501814e-13, 4.840258820185028e-13, 1.219220560042921e-12, 4.524892975943638e-12, 2.876449089571417e-11, 3.812993355170018e-10, 1.348759348579140e-08, 1.705525340647080e-06, 3.956577819154846e-04, 3.374113764476002e-03, 2.149980205626159e-02, 7.943986562029567e-01, 1.459315262762757e+02, 5.011214388283130e+04, 7.800728203829225e+06, 2.105468008597680e+09, 2.864913548596957e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
