
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_ms2h_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.260987201672512e+00, -4.176561783081472e+00, -4.058286200495780e+00, -3.894497938421472e+00, -3.671429519623939e+00, -3.374792674818587e+00, -2.993552985756319e+00, -2.526761505660351e+00, -1.992287290762117e+00, -1.415391860050200e+00, -8.970538003575599e-01, -5.812382213796583e-01, -5.086782585729411e-01, -4.372329463698040e-01, -3.073554915517919e-01, -1.852387240239408e-01, -9.316454605831823e-02, -3.183291239870992e-02, -6.653714612843493e-03, -7.360330762048729e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_ms2h_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.566719434966404e+00, -5.452177511205058e+00, -5.291588377174566e+00, -5.068941418784589e+00, -4.765132614649686e+00, -4.359803238647232e+00, -3.835614790952625e+00, -3.184459687337276e+00, -2.403004761099589e+00, -1.420975828503450e+00, -9.740152661456531e-01, -7.398953718032941e-01, -6.897515222249048e-01, -5.616340906011200e-01, -3.298980283569975e-01, -1.940724256578786e-01, -1.082483640403647e-01, -4.161278835906627e-02, -8.863279862161837e-03, -9.813655708734064e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_ms2h_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.253375007840826e-06, -1.360330110258590e-06, -1.530573152930818e-06, -1.814132678481514e-06, -2.319061037390020e-06, -3.313186986555200e-06, -5.605601293510404e-06, -1.254314300253705e-05, -4.790726225365078e-05, -4.379459303593145e-04, -6.969723442866763e-04, -4.126681311974442e-03, -1.186951767148007e-02, -5.555329358737177e-02, -2.066657322498363e-01, -3.247586026137806e-01, -1.165254020811161e+00, -1.873990384455765e+00, -2.270606462411208e+00, -2.508478126011791e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_ms2h_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.408022275692544e-05, 5.982781711336884e-05, 6.922520554122025e-05, 8.548889665818307e-05, 1.160523747422275e-04, 1.807703906683398e-04, 3.436072210120099e-04, 8.678107125703586e-04, 3.233779710432956e-03, 1.629019633475839e-02, 1.245686129087306e-03, 1.423390380379465e-03, 1.730930596169320e-02, 7.492099721222531e-02, 8.650584666073395e-02, 5.279574063207291e-03, 9.390541898300097e-04, 4.707883399859392e-07, 3.058244215685659e-12, 7.730800031015716e-20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_ms2h_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.018756531415853e-02, -1.055993327486574e-02, -1.110930347050616e-02, -1.192440832337754e-02, -1.313344986498347e-02, -1.488001400569753e-02, -1.705915602048791e-02, -1.750169608575344e-02, -1.110015838133951e-03, -5.347326186916409e-02, -1.981541516856902e-01, -5.619581642184752e-01, -1.390559993737419e+00, -1.588016945002498e+00, -4.074836108857282e+00, -1.722258886503494e+01, 1.098337841716625e+00, -3.318172542345974e+02, -1.022745639590333e+04, -8.471680026293382e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_ms2h_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.894604975021166e-08, -2.304535771457513e-08, -3.047396646099471e-08, -4.534624386302356e-08, -7.965772963137340e-08, -1.764542247896072e-07, -5.391136745727807e-07, -2.556495221666802e-06, -2.142765228411539e-05, -1.531741475996759e-04, -1.175795453757109e-04, 5.427729396557470e-03, -9.689528409771851e-02, 2.597619440645051e-01, 2.394817771592930e+00, 2.856601912547330e+02, -1.361304461055033e+03, -2.220612233725068e+05, -3.174383857125337e+07, -2.598864335181892e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_ms2h_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.885863797261353e-05, 4.369937416291042e-05, 5.171415299458268e-05, 6.582310377568785e-05, 9.293751074430849e-05, 1.519921280608663e-04, 3.055614818363711e-04, 8.167846986100403e-04, 3.152748756604249e-03, 9.263585276519460e-03, 1.264119327352813e-03, 8.371825538676176e-03, 4.349724687041032e-01, 7.216092874755875e-03, -6.704255380610924e-02, -2.844672486006597e+01, -1.368834736217074e+01, -5.321082475452138e-01, -8.015484978037648e-04, -3.198497606413453e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_ms2h_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.993476772895457e-13, 1.018671357151703e-12, 1.442978363405077e-12, 2.378369356127677e-12, 4.868158097569612e-12, 1.356900270758529e-11, 5.863120332512881e-11, 4.704979341401712e-10, 8.917506018559237e-09, 2.786405563340310e-07, 1.022651853119545e-06, 1.523986397824332e-04, -2.209235763015382e-02, 8.080262323251626e-02, -2.890591649936759e+00, -5.854631508409108e+03, -1.101984406788274e+05, 6.652759804031258e+08, 1.152860402257189e+13, 7.326583720655003e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_ms2h_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.128180221187046e-09, -1.352312221588334e-09, -1.754219093223082e-09, -2.548118181730884e-09, -4.350612701116320e-09, -9.350743464118561e-09, -2.785021455317283e-08, -1.312915494395836e-07, -1.163260418766663e-06, -1.152697721312710e-05, 9.810315080646497e-06, 1.356635062633274e-04, 7.760007183130915e-02, -7.625236841940954e-02, 2.969403893831340e+00, 5.766184741819117e+02, 3.521643287974808e+03, 3.889085911280885e+03, 6.441203606814518e+02, 1.893717057749421e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_ms2h_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_ms2h", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.615502175633099e-06, 1.821374493972994e-06, 2.163598788072547e-06, 2.769569406917359e-06, 3.944225985138215e-06, 6.536174680357848e-06, 1.341590727583909e-05, 3.713815633830467e-05, 1.536695216434450e-04, 4.833962671435006e-04, -1.636613250130370e-04, -9.433842876971242e-04, -2.620032142245117e-01, 4.740280647627387e-02, -2.180762168785617e+00, -5.418057544599326e+01, -2.973660381303932e+01, -1.045098852739830e+00, -1.507238888225840e-03, -5.918746144533710e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
