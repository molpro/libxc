
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_xc_bn05_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_bn05", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.849753938418830e+00, -3.765929540582138e+00, -3.648485284352715e+00, -3.485826317677083e+00, -3.264251764004260e+00, -2.969517507658026e+00, -2.590592957037642e+00, -2.126644312207119e+00, -1.597663227711248e+00, -1.058358394539989e+00, -6.161937760725185e-01, -4.037833799403888e-01, -3.337652126433613e-01, -2.426350909014577e-01, -1.297810014992892e-01, -4.056866512396388e-02, -5.136106289461397e-03, -2.109763702259284e-04, -2.218685412406572e-06, -3.387183548115954e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_xc_bn05_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_bn05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.233143987893605e+00, -5.121079380421969e+00, -4.964046773588791e+00, -4.746512999067647e+00, -4.450092524805575e+00, -4.055598729195439e+00, -3.547992977604223e+00, -2.925586476713839e+00, -2.214040879662492e+00, -1.484868807682250e+00, -8.814934895565057e-01, -5.885912386466842e-01, -4.914883361492273e-01, -3.646092217253836e-01, -2.054242456404235e-01, -7.090025274889550e-02, -9.756916535385341e-03, -4.120988218492293e-04, -4.376870573608669e-06, -6.736199667543198e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_xc_bn05_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_bn05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.032655551732730e-02, -1.075558722272198e-02, -1.140326159277167e-02, -1.240178462209265e-02, -1.398828422567784e-02, -1.661990861978353e-02, -2.126155835949886e-02, -3.019188757343293e-02, -4.956306262453222e-02, -9.821964014909534e-02, -2.267983568965343e-01, -4.132155163967286e-01, -5.327833998070679e-01, -7.974882118222029e-01, -1.622814300041925e+00, -4.238685334855065e+00, -8.761564886055847e+00, -1.216450052911021e+01, -1.488172930794145e+01, -1.723649318200208e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
