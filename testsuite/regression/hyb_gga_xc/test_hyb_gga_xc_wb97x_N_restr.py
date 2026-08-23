
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_wb97x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.559213689772830e+00, -3.489240790856649e+00, -3.391301250686214e+00, -3.255874245629224e+00, -3.071883486202946e+00, -2.828214380062264e+00, -2.517125302869692e+00, -2.139759476871099e+00, -1.711015437302351e+00, -1.258025847009225e+00, -8.029026351820496e-01, -4.650363134533444e-01, -3.909469206159305e-01, -3.015440609228824e-01, -1.905758885219397e-01, -7.519292514925544e-02, 2.634088955223204e-03, 2.364589249008422e-02, 7.278118185563814e-03, 8.969846719603498e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_wb97x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.526350246947979e+00, -4.426847325942672e+00, -4.286963437029586e+00, -4.092361338946384e+00, -3.825853844928660e+00, -3.469577782061557e+00, -3.011289410655133e+00, -2.458097322234218e+00, -1.854229201394653e+00, -1.243591313705027e+00, -7.458018889984215e-01, -6.075198277364543e-01, -5.576392453879208e-01, -3.928221435283088e-01, -2.457950877690855e-01, -1.110958865291776e-01, -1.340960564838824e-02, 2.401910048852387e-02, 9.411297572344551e-03, 1.189935849864457e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.649176195872234e-06, -2.896899296860322e-06, -3.294959924404133e-06, -3.964427256932346e-06, -5.162394574885719e-06, -7.488467489287451e-06, -1.249155244133166e-05, -2.462736793470043e-05, -5.863687015252887e-05, -1.921074187745607e-04, -9.894232782522933e-04, -3.559637042308247e-03, 3.060500674552327e-03, -1.457434232759324e-02, -3.508951258946755e-02, -8.862101727158593e-02, -4.029365221728565e-01, 8.732035324662567e+00, 1.644501331516430e+01, 2.057983725868375e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.134904801182729e-02, -1.196789888878623e-02, -1.290506281650403e-02, -1.434950197103860e-02, -1.662095059419854e-02, -2.025800513711797e-02, -2.610435071629866e-02, -3.518545770457391e-02, -5.047746254282224e-02, -1.647677322221738e-01, -6.710540778142927e-01, -6.430396421907639e-01, -5.755390853760080e-01, -1.230859611607006e+00, -3.917530109815007e-01, -2.205754430480955e+01, -3.959164835859244e+01, -3.501674654182020e+02, 8.890294670407164e+03, 1.002344162366055e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.088274742262309e-08, 3.606494277358424e-08, 4.478807468968891e-08, 6.037825647984648e-08, 9.047394178373789e-08, 1.541937454334974e-07, 3.022498599248650e-07, 6.591389760525787e-07, 1.575053856945120e-06, 3.764388827727578e-05, 1.378686750201280e-03, 2.215127612110543e-02, 2.661898181492108e-02, 1.851900282565560e-01, -1.044200261779290e+00, 1.055037060619357e+02, 2.445898953459092e+03, 9.810543867212064e+05, 2.276516591931869e+08, 2.127612172454221e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.312084423782391e-13, -1.637794966740297e-13, -2.215848956402692e-13, -3.312704490646838e-13, -5.523631396870711e-13, -9.803328035752662e-13, -1.078986975173567e-12, 1.412601248150014e-11, 3.722987609746376e-10, 1.271056040320171e-09, -1.709181018378177e-06, -1.254042920831157e-03, -1.648136647659318e-02, -3.994762999825791e-02, 1.429804377840223e+00, -6.304675913272266e+02, -3.177417285790874e+05, -3.160699219489214e+09, -8.345630518725355e+13, -6.010771517733168e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
