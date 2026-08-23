
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m11_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.558758665687532e+00, -1.577402866799529e+00, -1.590963651491722e+00, -1.585354418696730e+00, -1.534776237055159e+00, -1.409510085687318e+00, -1.228719498927599e+00, -1.146167329097813e+00, -1.222951044569867e+00, -1.119092276998768e+00, -6.941355077007194e-01, -3.702993733011432e-01, -2.394520713731960e-01, -1.868630804351550e-01, -1.562034323954407e-01, -6.933163495298289e-02, -1.772753844832840e-02, -1.095713344751359e-03, -1.077597086916273e-05, -1.463840461380302e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m11_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.498682374729344e-02, -3.574678647637566e-01, -7.818654688291643e-01, -1.317780825675933e+00, -1.880112156723596e+00, -2.173915860344192e+00, -1.665985415816152e+00, -4.596313602308512e-01, -2.196555223417836e-01, -7.826367895963714e-01, -7.618139241761306e-01, -2.431736462716224e-01, -2.046836552115483e-01, -9.929621065143686e-02, -9.984705952266051e-02, -7.576906242444045e-02, -2.287817782042495e-02, -1.959335491942084e-03, -2.144243998014186e-05, -2.927489638403604e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m11_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.602355615809386e-06, 8.458561350281018e-06, 8.290012965582077e-06, 8.156418031353500e-06, 8.264595034862894e-06, 9.144344275785361e-06, 1.126718135349379e-05, 8.118326744031246e-06, -5.469245920067890e-05, -2.679860372005861e-04, -5.919687006529087e-04, -7.690545338635535e-03, -1.052275457668809e-03, -5.736279512761326e-03, -9.129284077648640e-02, -1.531042617011687e-01, -4.599140571931868e-01, -3.846789766708638e-01, -2.216251666194125e-02, -3.007742065981022e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m11_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.963480907992957e-02, -6.122203634576155e-02, -4.952189324054165e-02, -3.412463681847547e-02, -1.648384933942813e-02, -3.286947455712491e-03, -8.361556573269160e-03, -3.124568715431801e-02, -2.581954799929406e-02, -2.202499751735326e-03, 6.027362034320051e-04, -1.602983534346392e-02, -5.321094993908829e-02, -9.112046117707202e-02, -2.395360215950896e-02, -6.707503767564029e-03, -2.762972062359114e-03, -3.902020716414997e-05, -2.014250080948371e-08, -3.813809779335411e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m11_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.029077176422313e-02, 7.353531484750638e-02, 7.613681348423675e-02, 7.465404697929573e-02, 5.960721694480853e-02, 1.046973721497841e-02, -8.749344489208563e-02, -1.242223853141378e-01, 9.728431831886854e-03, 4.901553066340943e-01, -3.422946054567250e-01, 4.862667988650396e-01, 6.009812589619800e-01, -1.872614545250430e-02, 3.373516323913867e+00, -1.515000278010492e+01, -1.996329725775597e+01, -3.194509541517002e+01, -7.341407868446720e+01, -7.580449398336887e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m11_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.460270643496190e-07, 1.492983383185524e-07, 1.514606364198583e-07, 1.486840856909893e-07, 1.329480020923447e-07, 1.054673171150497e-07, 2.564990349243010e-07, 2.455064987777781e-06, 1.546621996814128e-05, -7.740731184627957e-05, -5.753112413292861e-04, -2.514508896431352e-02, 1.184162412470251e-01, 4.464152572281869e-01, -4.519522869604894e-01, 4.009698974776319e+00, 3.854406833132636e+02, -5.210998730079927e+04, -3.610259473456885e+05, -3.635411311425892e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m11_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.049204382239544e-03, -2.134159265698073e-03, -2.204208173879467e-03, -2.173304919928988e-03, -1.804382190790670e-03, -5.900953158420246e-04, 1.761702736815372e-03, 1.952848895405293e-03, -3.491444257724876e-03, -9.021172847769860e-03, 1.200366147738363e-02, -2.772926028080197e-02, -4.430237423606496e-01, -7.923872072833011e-01, -2.175568636171137e+00, 7.351902976384830e+00, -3.772437518893966e+00, -3.963434031051285e+00, -2.574320834080090e-01, -3.621838211023548e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m11_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.302176665741011e-13, -2.692056495701625e-13, -3.387783305576338e-13, -4.778735149145536e-13, -8.115168864749996e-13, -1.867010149894479e-12, -6.539093489744741e-12, -2.787901136816123e-11, 4.800175100671300e-10, 4.632607418404719e-08, 9.337511179571521e-07, 5.355688347585936e-04, -3.940339892178307e-04, 4.803912971454494e-04, 2.503228389168193e+00, 7.317915251034752e+01, 5.221502562085501e+04, 1.398043185429698e+08, 1.125338406585829e+11, 8.784802993995544e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m11_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.590556771860951e-09, -4.696784842002694e-09, -4.788438953411729e-09, -4.780591573496319e-09, -4.496194488011348e-09, -3.989543928973317e-09, -7.645244584864881e-09, -5.750724337818955e-08, -3.840917646665037e-07, 5.565001674416304e-07, 2.185281183778876e-05, 2.966047137707301e-03, -4.547130766168356e-02, -2.425509983513763e-01, -3.871585619072615e-01, -2.911021801128681e+00, -6.051783843078830e+02, -1.554253415569585e+03, -4.937136709367168e+02, -6.890259246933365e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m11_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.351696669276018e-05, 6.508127709140247e-05, 6.591908640009514e-05, 6.366379976397609e-05, 5.219532368325407e-05, 1.938820570102478e-05, -3.731017409210691e-05, -1.708203005704070e-05, 1.794629761026068e-04, 2.029189552221550e-04, -6.385675478151100e-04, -2.311282580752222e-04, 2.376548593179643e-01, 8.991544237302799e-01, 1.640312953775943e+00, -4.638797642488778e+00, 9.335862992325330e+00, 3.720755026212293e+00, 2.266786681514317e-01, 3.380902733519536e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
