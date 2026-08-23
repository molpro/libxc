
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_yukawa_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_yukawa", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.019473497663160e+00, -3.935488792639213e+00, -3.817794619615168e+00, -3.654735842873401e+00, -3.432501806913453e+00, -3.136641691605242e+00, -2.755724033741703e+00, -2.288120388512383e+00, -1.752247651949220e+00, -1.199990862770727e+00, -7.368674228522979e-01, -5.070087015541106e-01, -4.294125395319150e-01, -3.265613465376670e-01, -1.951021143171211e-01, -8.107709567249340e-02, -1.728916063266238e-02, -1.000380463295143e-03, -9.915136916930956e-06, -1.347581349985264e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_yukawa_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_yukawa", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.405391274692457e+00, -5.293348225162869e+00, -5.136329835973026e+00, -4.918781323413909e+00, -4.622265540090488e+00, -4.227477523498912e+00, -3.719112497510099e+00, -3.094887845214039e+00, -2.379152682588700e+00, -1.640709738265026e+00, -1.019883672585129e+00, -7.103992931531845e-01, -6.054916541561077e-01, -4.658533718325465e-01, -2.856125316454522e-01, -1.252678729106860e-01, -2.963011430115726e-02, -1.930776687277790e-03, -1.979406206411610e-05, -2.695101921946435e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_yukawa_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_yukawa", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.032415678947972e-02, -1.075395831341309e-02, -1.140294866643274e-02, -1.240386572984022e-02, -1.399508793896106e-02, -1.663705618006200e-02, -2.130464424437698e-02, -3.031253070839397e-02, -4.997500341584561e-02, -1.000667979642239e-01, -2.366832347213884e-01, -4.433868031252091e-01, -5.798414139323453e-01, -8.882390721711627e-01, -1.868925799281723e+00, -5.475352319252770e+00, -2.018624813053573e+01, -5.460561944239392e+01, -6.896626055754844e+01, -6.980267492611590e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
