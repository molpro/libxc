
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_lp_b_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_b", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.543691700321376e+00, -4.461847430610672e+00, -4.346529373478121e+00, -4.185547175555339e+00, -3.963835481188925e+00, -3.664451626197130e+00, -3.271692399703256e+00, -2.777850319259858e+00, -2.195124737135814e+00, -1.574105695186693e+00, -1.034474290732600e+00, -7.580633644600101e-01, -6.628680043887930e-01, -5.345463663407439e-01, -3.647164324623502e-01, -2.043162453040699e-01, -8.985823262885527e-02, -2.879892575763890e-02, -5.965674378966944e-03, -6.597006548413420e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_lp_b_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.891248769250780e+00, -5.788085385848588e+00, -5.642544908953002e+00, -5.439012875344381e+00, -5.158013326651413e+00, -4.777309320881720e+00, -4.275667786117580e+00, -3.641378925004492e+00, -2.887853602416945e+00, -2.078763597718385e+00, -1.370642283339437e+00, -1.006102495203868e+00, -8.802695703530314e-01, -7.104170236370820e-01, -4.852125396630497e-01, -2.720839672003390e-01, -1.197456589301439e-01, -3.839185850215362e-02, -7.953944609300670e-03, -8.795973525731052e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_lp_b_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.479665514840691e-03, -9.929130670712428e-03, -1.061062184748686e-02, -1.166773996426220e-02, -1.336170349247961e-02, -1.620460084242356e-02, -2.129864225699115e-02, -3.130761034337852e-02, -5.363648928330857e-02, -1.119687007056643e-01, -2.754916090097413e-01, -5.290802311523690e-01, -6.993074187762431e-01, -1.090742500925787e+00, -2.387376610647507e+00, -7.742535549742109e+00, -4.053406325696407e+01, -3.972676237475653e+02, -9.281112267094921e+03, -7.594111267682761e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
