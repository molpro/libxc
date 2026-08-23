
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_q1d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q1d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.169495804818399e+00, -4.080145258586667e+00, -3.953968980052416e+00, -3.776982943984237e+00, -3.530674690395106e+00, -3.190316008389932e+00, -2.720409272748911e+00, -2.064558036156587e+00, -1.180244518782144e+00, -3.799184289338648e-01, -1.492114149241448e-01, -6.071507368808420e-01, -5.532551421975805e-01, -4.073445971189207e-01, -1.347574446712363e-01, -8.874713756155379e-03, -3.540155001184455e-04, -1.150114297867045e-05, -1.092707117933148e-07, -1.550502255920271e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_q1d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q1d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.896509365907074e+00, -5.814168384307865e+00, -5.703187650686247e+00, -5.559180011573125e+00, -5.384871312533353e+00, -5.202651204350256e+00, -5.074721474009994e+00, -5.059205101877486e+00, -4.577034123962347e+00, -2.230267809866799e+00, -9.547608274437352e-01, -1.026811656210553e+00, -7.501793176210493e-01, -8.046098678706333e-01, -6.657623702051977e-01, -5.706047765657134e-02, -1.573537841433652e-03, -4.609562982489314e-05, -4.370847533371694e-07, -6.202009028144612e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_q1d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q1d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.617894099271311e-06, 4.274363788070099e-06, 5.397464689010688e-06, 7.461997362044007e-06, 1.165189096113472e-05, 2.135980245663425e-05, 4.787665060827224e-05, 1.322261204558845e-04, 3.789480158647866e-04, 6.936322167823111e-04, 2.013067423777098e-03, 1.743501896046372e-02, 4.646047141470716e-03, 9.714771991022188e-02, 4.580196459750681e-01, 2.421833932464418e-01, 7.467103893858749e-02, 6.931575235684991e-02, 7.933607343768355e-02, 8.742142552672827e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_q1d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q1d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.779402716541361e-03, 4.143240617836974e-03, 6.474871312996342e-03, 1.072770328567770e-02, 1.914991483052136e-02, 3.745269757866404e-02, 7.952630079344304e-02, 1.508567033550595e-01, -9.356037975198137e-02, -1.403222317880113e+00, -2.897300139305685e+00, 1.215485799776655e+00, -2.427760861532164e-01, 3.869523825515051e+00, -1.988543386697237e+01, -2.846957565437462e+01, -6.200219138324074e+00, -4.322703302434852e+00, -4.591029881411233e+00, -4.819218732161328e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_q1d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q1d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.475837080675340e-07, -1.788536540157204e-07, -2.352841250707288e-07, -3.473780115083601e-07, -6.016668684132885e-07, -1.289230433933512e-06, -3.557340556161918e-06, -1.136895544988212e-05, 3.202906789498123e-07, 5.139157792555047e-04, 7.189196301437493e-03, -1.418803091184645e-01, -1.357443433540961e-01, -1.904142291846761e+00, 1.561618993099046e+01, 1.436993404141843e+02, 3.841020451195516e+02, 8.664932647084384e+03, 1.111101387650099e+06, 9.057344043305948e+08]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_x_q1d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q1d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.294527933755730e-12, 1.657526502184895e-12, 2.361033021193591e-12, 3.910717023165057e-12, 7.994481121030261e-12, 2.169374505254731e-11, 8.267749565203395e-11, 3.673509083882190e-10, -3.843807732736664e-09, -2.699379686057863e-07, -2.359785928235268e-05, 8.372992156950901e-03, 4.483341866206226e-02, 4.821288516250627e-01, -2.330326596421104e+01, -9.180116113752420e+02, -3.291055489440083e+04, -2.599608223014025e+07, -4.033539961080688e+11, -2.553385277081377e+17]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
