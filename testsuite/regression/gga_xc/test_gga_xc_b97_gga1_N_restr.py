
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_b97_gga1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_gga1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.565894325997649e+00, -4.472510407940518e+00, -4.341728299847864e+00, -4.160723851257159e+00, -3.914464031536659e+00, -3.587675929513888e+00, -3.169725268131888e+00, -2.664631039614360e+00, -2.109272357210124e+00, -1.588405724543441e+00, -1.098305219461449e+00, -7.216750096346950e-01, -6.309105592116632e-01, -5.162662651366797e-01, -3.729273306721547e-01, -2.570281852790715e-01, -1.663978130349210e-01, -5.763674497597567e-02, -9.923309871666825e-03, -9.568151116568168e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_b97_gga1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_gga1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.226277001333357e+00, -6.098880814932334e+00, -5.919995862211758e+00, -5.671355400348386e+00, -5.330587660797096e+00, -4.872268089641186e+00, -4.270209705401758e+00, -3.499669588938849e+00, -2.540907383104333e+00, -1.459571091057764e+00, -8.287265362880502e-01, -9.404783239284887e-01, -8.315569015621076e-01, -6.587361109961953e-01, -4.177533012280224e-01, -1.717753853062163e-01, -1.238287553046579e-01, -7.390132973422979e-02, -1.353728901164280e-02, -1.285430394157641e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_gga1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_gga1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.675708142673408e-06, 1.753594156664976e-06, 1.866444707388382e-06, 2.026847984719106e-06, 2.238551634635650e-06, 2.434049354365953e-06, 2.121248516029093e-06, -1.844641351898916e-06, -3.163395552376103e-05, -2.581959888688485e-04, -1.662104755531631e-03, -9.056431700028087e-04, -8.759509730777282e-04, -7.478315040250471e-03, -6.662516901760664e-02, -9.111130010626990e-01, -7.146234280815863e+00, -1.394829702079008e+01, -1.244043191509825e+01, -1.021067831911562e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_gga1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_gga1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.222961241277560e-02, -1.282562987178461e-02, -1.374949105237766e-02, -1.523462969208982e-02, -1.776001065367561e-02, -2.244859061173803e-02, -3.242725579521160e-02, -5.835916055220230e-02, -1.436654496625048e-01, -4.494694769973613e-01, -1.161181352890564e+00, -5.769615888295302e-01, -7.769370453097496e-01, -1.214074819428891e+00, -5.027794153403152e+00, -2.209839869461719e+01, 1.657704523882456e+02, -1.701999733719297e+02, -1.701181573062389e+04, -1.148516024292025e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_gga1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_gga1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.035414772651461e-09, 8.826978258291884e-09, 1.218579435096449e-08, 1.922222122705653e-08, 3.641795400565131e-08, 8.827080681525868e-08, 2.951769118741167e-07, 1.478994202573040e-06, 1.190075786425455e-05, 1.502419009755234e-04, 2.703730451104437e-03, 5.999976563983773e-03, 4.066365639414107e-02, 7.496271954266709e-02, 2.969185740598927e+00, 1.027533675220488e+02, -1.397281776399098e+04, -1.628010555678530e+06, -1.763223655684563e+08, -1.064919860423577e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_gga1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_gga1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.985164184040643e-13, -2.462298810048680e-13, -3.366340855084322e-13, -5.307546420100115e-13, -1.031263028317649e-12, -2.715002560997203e-12, -1.099455509416206e-11, -7.953264554366379e-11, -1.180842138810578e-09, -3.747895587691887e-08, -3.651920705209285e-06, -2.245873428421001e-04, -1.211685749490670e-02, -5.467847372855926e-03, -1.588232628476167e+00, -4.674157262189441e+01, 1.550998360984048e+06, 4.880847658389565e+09, 6.302111899530034e+13, 2.982146969260696e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
