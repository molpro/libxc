
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_case21_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_case21", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.285104782675548e+00, -3.222942364805227e+00, -3.135910877706750e+00, -3.015506479982946e+00, -2.851775999818483e+00, -2.634593988114873e+00, -2.356653007344041e+00, -2.018800303806756e+00, -1.636536450039273e+00, -1.236708975878788e+00, -8.356785595201003e-01, -5.435966422507378e-01, -4.751587616758752e-01, -3.935631182757439e-01, -2.879554635203749e-01, -1.824880353775228e-01, -9.070348736395085e-02, -3.043103493906144e-02, -6.321556057433078e-03, -6.988692416297507e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_case21_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_case21", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.159685491423346e+00, -4.072178227030312e+00, -3.949397236304596e+00, -3.778986536772180e+00, -3.546126454591124e+00, -3.234992804392162e+00, -2.832598755282234e+00, -2.337086248953734e+00, -1.775713681914866e+00, -1.252132965745685e+00, -8.480667976121178e-01, -6.826873063617345e-01, -6.169884353489735e-01, -4.891763247078091e-01, -3.258195940267886e-01, -2.033635542355422e-01, -1.109059083645517e-01, -4.028558441814586e-02, -8.430768471879492e-03, -9.318363463813130e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_case21_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_case21", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.135220556555532e-06, -2.330866048665142e-06, -2.642437587581467e-06, -3.160838575259418e-06, -4.078632179522424e-06, -5.851004534036229e-06, -9.708597710357106e-06, -1.954970098220436e-05, -4.993635873617516e-05, -1.567131285193167e-04, -6.923659904280062e-04, -2.367819768222218e-03, -1.342475231130772e-03, -9.314952295682849e-03, -4.816776306019040e-02, -1.969763135807073e-01, -6.350430962120406e-01, -5.631475788081877e-01, 6.566131377331130e-01, 2.327614217942091e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_case21_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_case21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.819117542506084e-03, -1.029848199705964e-02, -1.102945703646317e-02, -1.217445831316204e-02, -1.403101572754683e-02, -1.718983009940560e-02, -2.291479798167016e-02, -3.399171347653369e-02, -5.387770042821933e-02, -4.857595399023869e-02, -3.706055666560155e-02, -4.680870826940629e-01, -5.193467201945998e-01, -9.998036410115609e-01, -2.116154533056872e+00, -1.738310584253733e+00, -8.957402265455430e+00, -3.802862433046882e+02, -9.864007094442544e+03, -8.046370655811344e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_case21_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_case21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.478447416070373e-08, 2.842428713269481e-08, 3.457926116149572e-08, 4.576601106755308e-08, 6.815906213208717e-08, 1.194615246975199e-07, 2.605355929482914e-07, 7.455409059361026e-07, 2.552689761365456e-06, -7.501711176413062e-06, -3.402455488765194e-04, 1.060685962649746e-02, 2.238687691679790e-02, 1.166048345058175e-01, 6.688925716429124e-01, -1.784253914830406e+01, -1.785722412129247e+03, -7.259671253366831e+04, 8.213941817904584e+06, 2.367179930842512e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_case21_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_case21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.082091421956469e-13, -1.295902918682643e-13, -1.674915148014788e-13, -2.411815553312389e-13, -4.016076509636060e-13, -8.022652087412549e-13, -1.897355677536377e-12, -2.522274745303054e-12, 1.623425793321528e-10, 1.689814602877262e-08, 2.384790461377066e-06, -4.975401773928206e-04, -7.356977718918594e-03, -2.465048099257531e-02, 1.872187345670545e-01, 2.035981239262227e+02, 1.723975921027041e+05, 2.000801781677187e+08, -3.336496057321787e+12, -6.798318612741234e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
