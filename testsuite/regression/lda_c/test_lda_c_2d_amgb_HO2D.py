
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_2d_amgb_HO2D_2_zk():
    # Prepare the input
    inp = test_data["HO2D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_amgb", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.231282893610158e-01, -1.231274085634341e-01, -1.231250996489437e-01, -1.231190687638774e-01, -1.231034068077557e-01, -1.230631076310303e-01, -1.229609253513371e-01, -1.227077144218448e-01, -1.221019500280223e-01, -1.207265530915031e-01, -1.178266822182148e-01, -1.122854211283221e-01, -1.028893929755974e-01, -8.888366802033741e-02, -7.035461709934143e-02, -4.819263123556329e-02, -2.495332431032593e-02, -7.290155807406449e-03, -6.179845383370044e-04, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_2d_amgb_HO2D_2_vrho():
    # Prepare the input
    inp = test_data["HO2D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_amgb", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.401057515479728e-01, -1.408861185545921e-01, -1.398639552220109e-01, -1.411291309234561e-01, -1.394735338623802e-01, -1.415227370476677e-01, -1.388453151698705e-01, -1.421592618565130e-01, -1.378400770205231e-01, -1.431860183725106e-01, -1.362457817351219e-01, -1.448354658836259e-01, -1.337524468217814e-01, -1.474677709741539e-01, -1.299369987170300e-01, -1.516241625987990e-01, -1.242873645141640e-01, -1.580765344565291e-01, -1.163132458402616e-01, -1.678271429559173e-01, -1.057779187239458e-01, -1.819521610898728e-01, -9.298427847717761e-02, -2.011034469558320e-01, -7.887341499146285e-02, -2.244312619846401e-01, -6.466420818918074e-02, -2.476549876723002e-01, -5.107781932696928e-02, -2.596334348285915e-01, -3.768998192601491e-02, -2.365500663847358e-01, -2.314584371934453e-02, -1.502520488787976e-01, -8.362367748260456e-03, -4.402002405009317e-02, -8.315231620247904e-04, -3.495362731829385e-03, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_2d_amgb_HO2D_2_v2rho2():
    # Prepare the input
    inp = test_data["HO2D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_amgb", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.212736872792819e-01, -2.692156130163504e-01, 2.233905550156365e-01, 2.206206504596987e-01, -2.692165390253772e-01, 2.240526720627285e-01, 2.195690752117056e-01, -2.692189788340533e-01, 2.251280615148546e-01, 2.178844229199172e-01, -2.692254042717178e-01, 2.268749671845221e-01, 2.152077294299796e-01, -2.692423140110551e-01, 2.297135599403530e-01, 2.110102982673946e-01, -2.692867635519519e-01, 2.343286350435707e-01, 2.045628404686309e-01, -2.694033878416806e-01, 2.418401469579668e-01, 1.949711484226239e-01, -2.697084719300032e-01, 2.540932475736202e-01, 1.813748055394131e-01, -2.705028100109590e-01, 2.741766022913382e-01, 1.634137132749418e-01, -2.725559442024390e-01, 3.074382721884660e-01, 1.419190324238584e-01, -2.778064817656797e-01, 3.637767042118126e-01, 1.194194404353056e-01, -2.910654170367658e-01, 4.636989109785102e-01, 9.985920153068288e-02, -3.243721718622263e-01, 6.567843039081710e-01, 8.770461071784554e-02, -4.104965512876238e-01, 1.086265121477570e+00, 8.824390073892381e-02, -6.595214653869098e-01, 2.255770510156266e+00, 1.093554761793355e-01, -1.576386255535453e+00, 6.337478796845993e+00, 4.729091789192468e-02, -6.431540815427254e+00, 2.519834042961819e+01, -3.438641344493183e+00, -4.877302650577346e+01, 1.733512826827894e+02, -1.578828552870214e+02, -9.320879966736900e+02, 3.468119925666472e+03, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
