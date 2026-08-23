
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_rmggac_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.650654727323626e-02, -2.645928862532200e-02, -2.638926160527535e-02, -2.628416704646763e-02, -2.612362017508880e-02, -2.587250945092852e-02, -2.546920087139483e-02, -2.481855143652516e-02, -2.395776605862113e-02, -2.452068788858511e-02, -2.846679025492110e-02, -4.759650782340988e-02, -5.345124231138135e-02, -3.762182129214713e-02, -2.457489568871471e-02, -1.528198851290819e-02, -7.647831332015722e-03, -2.390353287900924e-03, -3.274817288943265e-04, -1.396801132450588e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_rmggac_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.919985459063715e-02, -2.926607970228549e-02, -2.937184104379109e-02, -2.954960874277230e-02, -2.987257189578236e-02, -3.053174031763474e-02, -3.211511411465023e-02, -3.668912926160706e-02, -5.068291148159148e-02, -7.121275373910325e-02, -5.746421343167154e-02, -7.988866778524430e-02, -7.738285760934471e-02, -6.982982082547352e-02, -6.052156426107312e-02, -3.856645239668720e-02, -1.784716518907261e-02, -5.425369259868993e-03, -7.516889689005819e-04, -3.063976325843041e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rmggac_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.077430739689872e-08, 3.474164632266092e-08, 4.148415791567786e-08, 5.388484687163017e-08, 7.958244661308363e-08, 1.433882908086844e-07, 3.503113656267743e-07, 1.308018654431247e-06, 7.511250466287761e-06, 4.163439763802478e-05, 9.390951178347791e-05, 2.294916435481544e-03, 8.206760513862576e-03, 2.133098787179601e-02, 6.826877733122046e-02, 2.320095859223971e-01, 1.070962750679218e+00, 9.089171188241725e+00, 1.397542003997988e+02, 3.558582299050725e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rmggac_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.006685488742492e-05, -1.157309600612327e-05, -1.412855719068519e-05, -1.877747848471359e-05, -2.809410500095353e-05, -4.935343988827856e-05, -1.063584733735443e-04, -2.855850173209447e-04, -8.493821726643497e-04, -1.499931838492036e-03, -2.253533363903681e-04, 2.876216944369947e-05, -1.262906530658937e-03, -1.642887081668955e-02, -2.376719979631921e-02, -1.460621058933301e-02, -5.091127295179749e-03, -1.305058868615526e-03, -1.765748479579418e-04, -4.823318003798729e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rmggac_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.290417859669806e-04, -3.844110108204538e-04, -4.794663202078636e-04, -6.550149466500617e-04, -1.013102280312940e-03, -1.844490882673680e-03, -4.090741172157435e-03, -1.093840823365894e-02, -2.879901415471743e-02, -2.546483478164138e-02, -2.763462153710882e-02, -4.611951930007597e-02, -1.889111474017997e-03, -1.761078209779222e-02, -2.135537658798757e-01, -4.081949072793940e+00, -4.029112174933263e+01, -6.116235468720539e+02, -1.842189642025996e+04, -7.880802298369013e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rmggac_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.763199693326995e-09, 1.213047761904235e-08, 1.653465082153337e-08, 2.567371775600242e-08, 4.775891779261128e-08, 1.134292656430007e-07, 3.685501051313688e-07, 1.701626186638234e-06, 9.711351968552266e-06, 2.141289407952350e-05, 4.710327918096502e-05, 2.635532055969481e-03, 1.585105933891097e-03, -2.664641198238315e-02, -4.204046553913451e-01, 3.188868523442041e+01, 5.364907657041732e+03, 3.048626172361929e+06, 1.206285830160260e+10, 4.113902589373356e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rmggac_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.420850651024078e-05, -1.658207634793709e-05, -2.066023731920303e-05, -2.820241283088013e-05, -4.362348186712019e-05, -7.956046079214463e-05, -1.771349318227168e-04, -4.754604535095810e-04, -1.234743026837720e-03, -7.351493256192664e-04, 2.694318123060995e-04, 8.215360476246810e-05, -9.853922340457812e-03, 3.276660424467866e-02, 3.558114051300746e-01, -1.513891214339072e+00, -3.178346155294922e+01, -6.734828552838100e+02, -2.555919563658022e+04, -1.214604196473805e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rmggac_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.874272605543937e-13, -3.800208021152046e-13, -5.665107278555834e-13, -1.000719964714400e-12, -2.241423052488298e-12, -6.952855734577321e-12, -3.313469257837057e-11, -2.644101362118162e-10, -3.273249271700418e-09, -1.733598984401284e-08, 4.218202924478128e-09, -6.472093556129480e-04, -6.737581049573829e-03, 1.003643336854612e-01, 3.117920517076481e+00, -2.143432752374952e+02, -8.303820215281422e+05, -1.730122366420066e+10, -8.530156563148576e+15, -2.282099917405022e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rmggac_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.086315604557609e-10, 5.079953629152859e-10, 6.931079451511385e-10, 1.078012654793084e-09, 2.010881871881013e-09, 4.795465897453394e-09, 1.565329947801827e-08, 7.224181154627642e-08, 3.967394319274850e-07, 2.651649828753526e-07, -4.496275863909053e-06, -1.225045724264024e-05, -4.899714558819000e-03, -2.315595101997378e-01, -2.769016472866056e+00, -1.531472749845607e+01, 4.032653433774592e+03, 3.663936969259366e+06, 1.784318840301423e+10, 6.728985675414242e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rmggac_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rmggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.818935985184298e-07, -6.801474429854082e-07, -8.493016323535113e-07, -1.162984773877714e-06, -1.806556944925155e-06, -3.311761720124875e-06, -7.403662807691923e-06, -1.975860223124724e-05, -4.806174586559270e-05, 6.225476130251320e-06, 4.734192563483027e-05, 3.865577043411875e-06, 9.826070030281429e-03, 3.697064282228612e-01, 1.722972862523315e+00, 3.439666033705034e+00, -1.929679847427950e+01, -8.108548824005704e+02, -3.813703521106761e+04, -2.015518275677510e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
