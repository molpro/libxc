
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_wigner_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_wigner", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.562539220858821e-02, -5.560944080248793e-02, -5.558596252172973e-02, -5.555106029569129e-02, -5.549843355567646e-02, -5.541745989846147e-02, -5.528924312323331e-02, -5.507787608177443e-02, -5.471004119436822e-02, -5.403140382987446e-02, -5.282323528679752e-02, -5.159612187085064e-02, -5.095985239629102e-02, -4.978620591735505e-02, -4.717291405941753e-02, -4.175689488189888e-02, -3.133663345288086e-02, -1.611586968919643e-02, -4.313798874065567e-03, -5.117797708391985e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_wigner_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_wigner", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.588337353932801e-02, -5.587258980509739e-02, -5.585671215787925e-02, -5.583309680349056e-02, -5.579746156541413e-02, -5.574256780365987e-02, -5.565548843696864e-02, -5.551151281910943e-02, -5.525969800278047e-02, -5.479091550146110e-02, -5.394287837324360e-02, -5.306388493501976e-02, -5.260111293841546e-02, -5.173494339190281e-02, -4.974781434991572e-02, -4.537254279148030e-02, -3.597954168713687e-02, -1.995310974048506e-02, -5.641770382343531e-03, -6.808253273583603e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_wigner_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_wigner", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.737212497082407e-07, -1.056226115473101e-06, -1.187134946971495e-06, -1.403948896079681e-06, -1.785854755405921e-06, -2.520730902188454e-06, -4.125812298672135e-06, -8.327197142559432e-06, -2.252058495310789e-05, -8.951962376471662e-05, -4.941525520289867e-04, -1.714774444939984e-03, -2.918211526234347e-03, -6.796686101429207e-03, -2.981709638314058e-02, -2.608457327392498e-01, -4.552805963736181e+00, -1.362579307354749e+02, -5.962293545815848e+03, -5.811536143873041e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
