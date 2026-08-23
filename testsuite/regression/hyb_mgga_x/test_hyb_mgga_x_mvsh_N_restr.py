
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_mvsh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.664132229218886e+00, -3.590000656283353e+00, -3.486094312566212e+00, -3.342092972723998e+00, -3.145728899981247e+00, -2.884057065080011e+00, -2.546489251149084e+00, -2.130111967393898e+00, -1.646066045636063e+00, -1.123261162893516e+00, -5.990098495797014e-01, -4.319643642761832e-01, -4.367737317274913e-01, -3.701353508475507e-01, -2.497813745912040e-01, -1.260284983871603e-01, -4.029034978129670e-02, -7.309590994660300e-03, -6.945887659739869e-04, -2.582766326411395e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_mvsh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.744055226966742e+00, -4.642767285210099e+00, -4.500669608621979e+00, -4.303476667475921e+00, -4.034043888624403e+00, -3.673953819464103e+00, -3.207611975377948e+00, -2.630868662597727e+00, -1.971711492272588e+00, -1.353584405868093e+00, -8.347000818865227e-01, -6.054635552683749e-01, -7.192561216311910e-01, -4.987804698543525e-01, -3.179771558219888e-01, -6.600644778133291e-02, -6.104514036863849e-02, -1.362918812101576e-02, -1.373520076138676e-03, -5.162437638405881e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mvsh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.126550603536147e-06, -4.475489244407099e-06, -5.028784990776623e-06, -5.944143704059659e-06, -7.553176090695023e-06, -1.063633760152473e-05, -1.730462505409466e-05, -3.428173993960395e-05, -8.609171995139329e-05, -2.391562572732084e-04, -2.853434862128643e-04, -6.138657499800157e-04, -2.453570266563888e-02, -1.950522939416141e-02, -9.016924579053720e-02, -2.247357676557144e+00, -1.804407069796087e+00, 4.365131596859171e+00, 1.139969999498050e+02, 3.622600055436773e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mvsh_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.934591786247147e-03, 6.055115022217887e-03, 6.232257032570320e-03, 6.494940552243760e-03, 6.889185328385243e-03, 7.489953283866025e-03, 8.419534263921204e-03, 9.852238401515239e-03, 1.175817048067083e-02, 1.178925135645102e-02, 4.500417438272616e-03, 3.237476342139002e-03, 8.081907592633715e-02, 3.376357877138882e-02, 5.002826039733941e-02, 2.167978891185486e-01, 2.616199423350405e-02, 1.696631435621156e-03, 2.759781193182895e-05, 5.553421131101714e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mvsh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.156859356765532e-02, -1.216467997797062e-02, -1.308303696694067e-02, -1.454293831765673e-02, -1.697411394402310e-02, -2.131501531299409e-02, -2.992759969970506e-02, -4.989029936745291e-02, -1.050566861855682e-01, -2.153429300251683e-01, -2.029852452652501e-01, -4.610762766760607e-01, -3.915681981848317e-01, -1.008236752049302e+00, -2.802049576961444e+00, -1.490642955451255e+02, -3.245719074046235e+02, -1.328192406195415e+03, -7.859212267419770e+03, -1.427114241273569e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mvsh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.062462289581035e-08, 4.728497327376059e-08, 5.883191371905939e-08, 8.057456288200964e-08, 1.267157695876898e-07, 2.431657254952633e-07, 6.208297887090768e-07, 2.369506606163803e-06, 1.505903621626749e-05, 1.102983732815892e-04, -9.481655642591403e-06, -2.014273015854367e-03, 1.225897226717415e-01, 1.155839737556140e-01, 9.020298631449750e-01, 2.456217573525370e+03, 5.681193187786111e+04, 6.334541475238935e+06, 3.148685845841958e+09, 2.399332256160064e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mvsh_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.557175386083191e-05, -2.834850515520659e-05, -3.288900324824295e-05, -4.074640273179280e-05, -5.550303884205688e-05, -8.668230275976150e-05, -1.645778368779999e-04, -4.085650215498019e-04, -1.369801565336748e-03, -3.542815291599388e-03, 1.048791045087103e-03, 1.396617050092957e-02, -2.076882249407940e-01, -4.750224066026373e-02, 1.630172721963419e-01, -2.126085761728033e+02, -4.117584069487261e+02, -1.416029840200848e+03, -5.103457594817841e+03, -1.574846215902145e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mvsh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.914175857376122e-13, -3.720656776807310e-13, -5.284699129632605e-13, -8.744898145050043e-13, -1.800214833826967e-12, -5.057905562716834e-12, -2.206041921072185e-11, -1.771346868399452e-10, -3.125472098452453e-09, -8.800225990564965e-08, -4.062229865315594e-06, -5.755770698922006e-05, 7.855611938464324e-03, -1.105974268270057e-02, 3.946373956337448e+00, -4.422849705918546e+04, -1.165613229089921e+07, -3.943214068135991e+10, -2.119338522725840e+15, -9.603834712417171e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mvsh_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.212457256033564e-10, 5.058932703015514e-10, 6.580694948023753e-10, 9.597863365769379e-10, 1.648477717370095e-09, 3.572952736455146e-09, 1.075218537449358e-08, 5.085880866034072e-08, 4.239658819553312e-07, 4.254816107809905e-06, 5.569104879675497e-05, 3.531082546103961e-04, -2.555656737046766e-02, 2.100899353645806e-02, -2.044920528283325e+00, 4.136403932716168e+03, 9.063090298862025e+04, 9.576617747503482e+06, 3.944720735838571e+09, 9.156487561116246e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_mvsh_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_mvsh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.037195553239819e-07, -6.819880633636331e-07, -8.124554702687474e-07, -1.044399994134258e-06, -1.496605560731522e-06, -2.502276161984945e-06, -5.195143831175798e-06, -1.447257201976292e-05, -5.694210860655049e-05, -2.015579849799991e-04, -7.196699522535056e-04, -1.751903850464601e-03, 8.401546950808206e-02, -3.608423812081980e-02, 1.090973482059738e+00, -3.863324105555110e+02, -7.199572886855922e+02, -2.486138139886035e+03, -9.053480308034064e+03, -2.834369797668501e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
