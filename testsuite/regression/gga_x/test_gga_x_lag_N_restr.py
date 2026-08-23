
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_lag_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lag", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.178388009837963e+00, -4.094769589175478e+00, -3.977622290732020e+00, -3.815393731078303e+00, -3.594450712932556e+00, -3.300667968944133e+00, -2.923252899510803e+00, -2.461900037199245e+00, -1.937609978860432e+00, -1.403280834984895e+00, -9.274704486452148e-01, -6.341586466105397e-01, -5.505237016984419e-01, -4.459091638020593e-01, -3.107503279582320e-01, -1.913351439230836e-01, -1.141855864794622e-01, -6.482133595047823e-02, -3.938539482438660e-02, -2.755352143761269e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_lag_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lag", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.517574933130607e+00, -5.404447819797425e+00, -5.245822056535533e+00, -5.025857955779847e+00, -4.725641222389092e+00, -4.325026626723248e+00, -3.807148929968390e+00, -3.166746264644724e+00, -2.423215700710258e+00, -1.646696195624951e+00, -1.039853523115098e+00, -8.295583209209449e-01, -7.293967667531296e-01, -5.792676806491254e-01, -3.785127013724335e-01, -1.869996465213460e-01, -8.101081712560999e-02, -3.527512975752164e-02, -1.113363695269003e-02, -4.373932648165119e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lag_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lag", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.752151336542212e-07, -6.314252735544998e-07, -7.218789968890895e-07, -8.747503678503305e-07, -1.151929166390814e-06, -1.707709931527325e-06, -2.994019944056595e-06, -6.637910241572842e-06, -2.022119525163296e-05, -9.027787225838162e-05, -5.240968199083486e-04, -1.282810480473155e-03, -1.721894914427188e-03, -5.676109536991904e-03, -3.375279470605656e-02, -3.647347475893859e-01, -4.829078845274626e+00, -1.152679352459254e+02, -1.126647822529491e+04, -6.842900555348673e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lag_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lag", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.090773426378425e-02, -1.139256674799627e-02, -1.212965643589058e-02, -1.327833867894880e-02, -1.513446357668365e-02, -1.829845476212069e-02, -2.414071054167565e-02, -3.631123319216770e-02, -6.651977446099054e-02, -1.565174845394663e-01, -3.976451710065784e-01, -5.005291424809389e-01, -6.154800847882915e-01, -1.051834925674274e+00, -2.852612877263817e+00, -1.080612298176026e+01, 3.310659971833347e+00, -3.767131677116882e+01, 6.814887404881308e+03, 7.571196320062184e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lag_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lag", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.844475453799725e-09, 7.980277238865948e-09, 9.948239266271738e-09, 1.364753127558911e-08, 2.146451226283091e-08, 4.099892364463092e-08, 1.030121180800006e-07, 3.787731494827742e-07, 2.312785902949488e-06, 2.551281539784137e-05, 4.844693831170897e-04, 4.337109350347656e-03, 8.978769630916723e-03, 5.491983951389862e-02, 9.134473440133074e-01, 2.919221945786875e+01, -2.088442003549110e+03, -7.383529736234095e+05, -5.393231334945391e+09, -2.399270647164567e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lag_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lag", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.748861688345687e-14, -3.408756073675996e-14, -4.642452547010174e-14, -7.229986350590731e-14, -1.363238380213943e-13, -3.370984379164190e-13, -1.219492170972612e-12, -7.436544973316959e-12, -8.885912204745225e-11, -2.049371773457917e-09, -1.318652626932562e-07, -1.264154858764453e-04, -1.261320355790728e-03, -7.239912578258487e-03, -2.277766261293325e-01, 6.737751105082623e+01, 5.860318481248297e+05, 1.242415033654398e+10, 1.578828718658398e+16, 5.503937024415393e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
