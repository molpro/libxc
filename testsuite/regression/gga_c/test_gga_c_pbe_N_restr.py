
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.416958125521995e-02, -6.312637738301728e-02, -6.163072241400871e-02, -5.948951672646457e-02, -5.643118954302589e-02, -5.208084106291070e-02, -4.594658889020094e-02, -3.748942196509720e-02, -2.658762897712945e-02, -1.530506669210152e-02, -1.128146794798093e-02, -4.304648537801435e-02, -5.250728346012794e-02, -3.667933745433601e-02, -1.931666804233494e-02, -5.203550639855580e-03, -3.654427458318314e-04, -4.114485394752653e-06, -4.159597299501745e-09, -1.334573215046060e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.322085888736983e-01, -1.312391591359406e-01, -1.298314957957055e-01, -1.277774479130788e-01, -1.247564303852146e-01, -1.202548067505437e-01, -1.133993964885090e-01, -1.026034833953797e-01, -8.509980657600030e-02, -5.967713911699968e-02, -4.736878010641918e-02, -8.869123855576863e-02, -8.266016964367368e-02, -7.911980385071618e-02, -6.027770679245755e-02, -2.417736784287558e-02, -2.167279204418760e-03, -2.628932870429524e-05, -2.718012729794541e-08, -8.828529158534324e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.180696874898097e-07, 7.661538333463756e-07, 8.407538910560603e-07, 9.602851448977967e-07, 1.160689289055329e-06, 1.518447733184909e-06, 2.213408331147116e-06, 3.715807760615456e-06, 7.376996462873855e-06, 1.790482706865915e-05, 9.644580044941252e-05, 3.462996523813402e-03, 9.453056391940993e-03, 1.488351403583653e-02, 3.784914620196298e-02, 1.010349927311372e-01, 1.211804179701333e-01, 4.892863643109241e-02, 6.036659648291790e-03, 1.504922553420554e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.862100377096019e-04, -3.095539316601495e-04, -3.465141442045336e-04, -4.075848034638946e-04, -5.149487495133350e-04, -7.215069839287992e-04, -1.174164260157879e-03, -2.362226311213407e-03, -6.207030078170590e-03, -2.003195983673992e-02, -6.905451623086577e-02, -2.502235865203449e-02, 9.689225543978839e-03, -7.381004988081252e-02, -9.084969336666929e-01, -6.010578646416421e+00, -1.044427607610478e+01, -4.380601518014180e+00, -5.263092679015767e-01, -1.283773191663749e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.790955469164837e-09, 3.226550202897824e-09, 3.974226307340162e-09, 5.361587680152410e-09, 8.242775862882266e-09, 1.528519010580163e-08, 3.707137687939153e-08, 1.313820665620500e-07, 7.718354038055494e-07, 8.033159768682292e-06, 1.835477390834426e-04, 9.101618111040615e-04, -1.282805918893406e-02, 1.304558540021083e-02, 7.925420252409648e-01, 3.177215258733139e+01, 7.021290212334470e+02, 9.670565926417288e+03, 1.380746113142922e+05, 2.578585853627247e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.914795690246909e-14, -1.205412068649563e-13, -1.596146375390159e-13, -2.388935498723110e-13, -4.260974305622042e-13, -9.763627238198288e-13, -3.195316121367684e-12, -1.730475061788637e-11, -1.884685148149099e-10, -5.254223203548333e-09, -7.536358155428847e-07, -7.538409323572904e-04, -7.510427748549705e-03, -4.391798057319216e-02, -1.580868940205556e+00, -2.454018512700961e+02, -6.116849061556183e+04, -2.711506673357684e+07, -4.600982050329904e+10, -6.593259128892694e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
