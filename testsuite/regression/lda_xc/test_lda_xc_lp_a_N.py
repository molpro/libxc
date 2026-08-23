
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_lp_a_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_a", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.862174557681790e+00, -4.763958615312668e+00, -4.626313192554921e+00, -4.435596406393112e+00, -4.175631823465865e+00, -3.829465501957011e+00, -3.383612679917273e+00, -2.835905078521313e+00, -2.207109897957969e+00, -1.553667813173025e+00, -9.599975195218516e-01, -5.277276994306936e-01, -4.370611369941475e-01, -3.608928224965818e-01, -2.325397736197570e-01, -1.113924993820605e-01, -3.557140535143329e-02, -6.180620119075390e-03, -4.448271402536484e-04, -1.070509548930709e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_lp_a_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_a", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.482781046612577e+00, -6.483017776753683e+00, -6.351697338333203e+00, -6.352192315357651e+00, -6.167897692112168e+00, -6.168937546466188e+00, -5.913028765063714e+00, -5.915228591401261e+00, -5.565158615643083e+00, -5.569860904108366e+00, -5.100852492807360e+00, -5.111062317569607e+00, -4.500150475010658e+00, -4.522854758169309e+00, -3.755132343362797e+00, -3.807523162624700e+00, -2.879774222921984e+00, -3.007705614186212e+00, -1.912103346576829e+00, -2.249247256947332e+00, -9.297791676905653e-01, -1.831356131052957e+00, -3.374387080025362e-01, -1.900031254771893e+00, -2.673624072188694e-01, -1.715622281777405e+00, -2.257328216495397e-01, -1.355592953353767e+00, -1.393505113101229e-01, -9.519820175559978e-01, -6.027799554548156e-02, -5.731917417795779e-01, -1.659471449801306e-02, -2.789397055508203e-01, -2.454025275201446e-03, -9.905935321321108e-02, -1.573423190357438e-04, -2.197245038761317e-02, -3.614370771232868e-06, -2.494548793246933e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_lp_a_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_a", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.223220260016845e-02, -6.636627460984899e-02, 4.223396509972109e-02, 4.399046858500786e-02, -6.913095746399446e-02, 4.399438643855322e-02, 4.664466600705739e-02, -7.330582213351379e-02, 4.665365341629470e-02, 5.073615067128782e-02, -7.974518511591303e-02, 5.075772311808172e-02, 5.723475046130183e-02, -8.998374226587222e-02, 5.729002303228887e-02, 6.800499264175179e-02, -1.069871789705912e-01, 6.816057857269252e-02, 8.695615248134932e-02, -1.370390203938248e-01, 8.745771987390792e-02, 1.231591046669648e-01, -1.950753587821702e-01, 1.251248145724356e-01, 1.998149473537262e-01, -3.219117631676763e-01, 2.099914569653069e-01, 3.739293351972027e-01, -6.453111410044520e-01, 4.501881949353030e-01, 6.388580215473542e-01, -1.502394350645651e+00, 1.387097763449340e+00, 5.371029054078321e-01, -2.529711059154048e+00, 3.901137028887772e+00, 6.307750797643087e-01, -3.261068897336841e+00, 5.327112100076020e+00, 1.033649693594014e+00, -5.096166794126811e+00, 8.086743305833240e+00, 2.001915430346851e+00, -1.082870335717696e+01, 1.817406738586412e+01, 4.777551763007468e+00, -3.302335456497435e+01, 6.352414649310980e+01, 1.448148090933145e+01, -1.566568593530452e+02, 3.706685840085433e+02, 5.898882419983285e+01, -1.350067569663037e+03, 4.061058473081570e+03, 3.884209744337010e+02, -2.824963632801613e+04, 1.022272562533898e+05, 6.320587873539202e+03, -2.199994816040256e+06, 8.608807475967584e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
