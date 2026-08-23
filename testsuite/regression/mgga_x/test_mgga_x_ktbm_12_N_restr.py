
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_12_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.037210773190646e+00, -4.937621226653673e+00, -4.797968751204787e+00, -4.604274131528411e+00, -4.339753021666284e+00, -3.986184204227335e+00, -3.526978197678878e+00, -2.951499961649458e+00, -2.260004767687564e+00, -1.499739721014399e+00, -8.764287150769291e-01, -5.895114390485244e-01, -5.748591345837204e-01, -4.945686322072215e-01, -3.340912238199212e-01, -1.770932921916742e-01, -7.498940641088526e-02, -2.380415645139463e-02, -4.930229299576075e-03, -5.457182668284661e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_12_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.260697902299397e+00, -6.123774524971344e+00, -5.931992000381799e+00, -5.666562625584421e+00, -5.305606872058394e+00, -4.827489243975946e+00, -4.219393355121575e+00, -3.494659678856605e+00, -2.706802083912358e+00, -1.880048401945720e+00, -1.123026635992065e+00, -7.880022260334039e-01, -8.400274960937404e-01, -6.557653684590558e-01, -4.247163668017135e-01, -2.235213302434985e-01, -9.501941528030333e-02, -3.023214510397983e-02, -6.248735379559699e-03, -6.903960460636705e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_12_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.020760844441036e-05, -1.104282961693914e-05, -1.235982188799291e-05, -1.451950972497287e-05, -1.826132511301676e-05, -2.525314052966234e-05, -3.967611483734010e-05, -7.297007867270995e-05, -1.550681614878646e-04, -3.307209784435808e-04, -6.777948164572076e-04, -3.729166500592470e-03, -2.229798535990280e-02, -5.533504951339933e-02, -1.542816350938896e-01, -3.903823224168447e-01, -1.171483415679683e+00, -9.405010945133368e+00, -2.363363185257215e+02, -2.099082275842656e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_12_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.210063948186132e-02, 1.238163712093542e-02, 1.279657839901892e-02, 1.341565293273206e-02, 1.435130252963246e-02, 1.578393985972513e-02, 1.797750837467256e-02, 2.109226661225713e-02, 2.361620411515421e-02, 1.838896453324335e-02, 6.568447510213104e-03, 4.221858828769275e-03, 5.319395504088460e-02, 8.491337871966204e-02, 8.872504404892019e-02, 4.115406153472006e-02, 9.491903916462395e-03, 2.325337600347179e-03, 5.221517483848432e-04, 6.370798117092717e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_12_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.675213788682115e-02, -1.756078207130629e-02, -1.878606096091192e-02, -2.068113634088598e-02, -2.369006884156278e-02, -2.860750290002949e-02, -3.677429044530271e-02, -4.968951651154248e-02, -6.743411453526836e-02, -1.139869319964089e-01, -2.361948522984356e-01, -6.880592967924677e-01, -9.951404209340620e-01, -1.435634731432267e+00, -2.561364140769163e+00, -5.952838402495107e+00, -3.223833541366680e+01, -3.447226373307371e+02, -8.180984003965595e+03, -6.715131505004901e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_12_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.294825908871654e-08, 8.356282871174865e-08, 1.014782496017334e-07, 1.338361933535929e-07, 1.980489716644815e-07, 3.426367518912614e-07, 7.223720556137205e-07, 1.845653831797852e-06, 3.995429408221849e-06, -2.144576104323337e-05, -4.253307501532345e-04, -6.067107387463875e-03, 2.483697978990388e-02, 1.371675954972579e-01, -5.090258066271902e-01, -2.892130963752453e+01, -2.047749960912435e+02, 1.842581943460079e+05, 6.440306057797321e+08, 4.253384572746484e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_12_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.148349724117130e-05, -4.567158622351220e-05, -5.241784003976252e-05, -6.381243569702558e-05, -8.434402497304863e-05, -1.245252408900115e-04, -2.100341922098634e-04, -3.874121552519488e-04, -4.623869708771973e-04, 1.596494432376389e-03, 5.120580709744477e-03, 2.958199729922726e-02, 9.848311953240896e-02, 2.515458072205569e-02, 6.133419728685393e-01, 3.380755637780231e+00, 2.317720954742031e+00, -4.372871931830483e+01, -1.420102362839082e+03, -1.290884407764279e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_12_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.115631042061684e-13, -1.415167017244279e-13, -1.990261700298606e-13, -3.242737051588240e-13, -6.509208061869565e-13, -1.751336830723515e-12, -7.051032786776607e-12, -4.817492644052989e-11, -6.076337987280948e-10, -1.343873462104912e-08, -5.915861763111389e-07, -4.983697039285621e-05, -1.842357747585553e-03, -2.642839880792868e-02, -1.078165931042104e+00, -1.525595746888143e+02, -1.535785450233762e+05, -1.855605529021115e+09, -6.705623927048719e+14, -3.420173458175908e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_12_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.282194987178950e-10, 3.966785062287697e-10, 5.207052231447987e-10, 7.692969058471763e-10, 1.345228846096872e-09, 2.985310168879439e-09, 9.218209857255269e-09, 4.391290442558171e-08, 3.367982051587679e-07, 3.394911353531260e-06, 3.803844284489995e-05, 1.282103595725090e-03, 2.087991385224915e-02, 1.632991833244727e-01, 2.930850166269571e+00, 6.969799307750372e+01, 3.129978386409199e+03, 8.970366135128206e+05, 2.809283204157166e+09, 1.968423674429859e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_12_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.838471598420919e-07, -3.309221500173628e-07, -4.125265824989389e-07, -5.659920054690163e-07, -8.901979728469475e-07, -1.697423404214104e-06, -4.215173509638993e-06, -1.461007832348503e-05, -6.852355187857570e-05, -2.899503835342919e-04, -6.528063465501762e-04, -4.167120292672329e-03, -7.877813626067162e-02, -3.490551667173946e-01, -2.584382413918277e+00, -1.199476907272569e+01, -3.985796203722283e+01, -3.299578096385836e+02, -9.140223267373212e+03, -8.798006916510273e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
