
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_pw6b95_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.196851582037303e+00, -3.137877381207745e+00, -3.055289550625956e+00, -2.940986495617814e+00, -2.785441926495615e+00, -2.578840966444462e+00, -2.313723715355444e+00, -1.989595840561778e+00, -1.618505833552486e+00, -1.225594025228992e+00, -8.326569606309493e-01, -5.550270039305611e-01, -4.560880156607213e-01, -3.780547903798760e-01, -2.796863613649740e-01, -1.817289451250770e-01, -9.890420597270981e-02, -1.812897559710405e-02, -2.265616580797733e-04, -3.814467425633962e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_pw6b95_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.930638834374723e+00, -3.848906559859177e+00, -3.734390609478053e+00, -3.575786334841561e+00, -3.359749779114868e+00, -3.072468660523993e+00, -2.703494569661079e+00, -2.253100649962821e+00, -1.744043780736301e+00, -1.235632660818062e+00, -8.261424835703537e-01, -6.749034904976087e-01, -5.629533455042999e-01, -4.495758095423679e-01, -3.062721607093147e-01, -1.787598782632224e-01, -1.108713855904542e-01, -5.720384446023718e-02, -8.905413680878267e-04, -1.476588151687523e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pw6b95_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.253460356827003e-06, -3.500229101847550e-06, -3.886980095776879e-06, -4.515998712555843e-06, -5.594400310866785e-06, -7.586281705672527e-06, -1.167050048649551e-05, -2.134362553626712e-05, -4.916135638660270e-05, -1.525817693134549e-04, -7.043718585568487e-04, 1.530019695795466e-03, -1.630420888374045e-03, -1.222757851156732e-02, -5.079705758382110e-02, -3.145316678929848e-01, -1.371466544433267e+00, 7.451629476419045e+01, 1.603311256488461e+02, 2.048116205963524e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pw6b95_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.439871863775734e-04, -3.491701049540032e-04, -3.563827750523077e-04, -3.661907350190002e-04, -3.789371662026954e-04, -3.939330487087583e-04, -4.073302515039011e-04, -4.078253189065846e-04, -3.745474769169067e-04, -3.076467701960110e-04, -4.161102836476062e-04, -6.072659598200788e-03, -1.233129715107278e-02, -8.867015282966116e-03, -5.352244999550134e-03, -2.065686157683478e-03, -3.635464995562674e-04, -2.277488878666457e-05, -3.457482984743095e-07, -6.761068171679148e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pw6b95_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.617910563149892e-03, -8.997680059704149e-03, -9.572111543705632e-03, -1.045990816914973e-02, -1.187431084224728e-02, -1.422460826909617e-02, -1.835720678465368e-02, -2.615120221309570e-02, -4.190938601821780e-02, -7.497861364865287e-02, -1.758594341918698e-01, -2.353137946670186e-01, -3.878308123195213e-01, -7.751482093155302e-01, -1.832328114398993e+00, -3.994648464131490e+00, 8.645865724179639e+01, -2.468222553366646e+03, -9.160842058554832e+03, -1.099931771476951e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pw6b95_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.585754402345201e-08, 1.797609692925996e-08, 2.151230937442775e-08, 2.780521602415812e-08, 4.006561189962516e-08, 6.717457808282670e-08, 1.383854784437563e-07, 3.716844590833035e-07, 1.341715542101234e-06, 5.859795979441395e-06, 1.174825674876041e-04, 5.830956775724394e-03, 8.271083301889665e-05, 9.285791428739501e-02, 7.849233838691415e-01, 2.008310043487484e+00, -8.183540689981842e+03, 4.238882007427137e+06, 2.213148469839859e+09, 2.057944355063209e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pw6b95_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.577532603142059e-06, -1.787196341645558e-06, -2.130360258439352e-06, -2.722076908569112e-06, -3.816593277268740e-06, -6.034573422481276e-06, -1.105781997853219e-05, -2.388277542536087e-05, -6.019242488479939e-05, -1.761514923597595e-04, -9.456103569684636e-04, -1.436654396207764e-02, -1.663061206451619e-02, -7.411205516988795e-02, -2.466362309520517e-01, -7.357320329726291e-01, -1.740189974184394e+00, -3.450830219801370e+00, -5.976488091770060e+00, -8.712725373582240e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pw6b95_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.220281110007428e-14, 8.927292064896865e-14, 1.210837658271513e-13, 1.875287016157033e-13, 3.511906758539479e-13, 8.630769013090628e-13, 3.128686344077479e-12, 1.973259258600026e-11, 2.690070234981697e-10, 9.978681993173948e-09, 9.498843684509765e-07, -2.396627640224367e-03, -1.150040996348996e-02, -3.283945973838937e-02, -2.691259971723097e-01, 1.395836927913231e+02, 6.659745586348927e+05, -1.653495950298988e+10, -8.068966764019501e+14, -5.850905439191786e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pw6b95_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.895568841432764e-11, 3.424677618137632e-11, 4.351771113182877e-11, 6.118445346685729e-11, 9.905676613438495e-11, 1.945882020091187e-10, 4.946516208054871e-10, 1.747008266195800e-09, 9.200363651149502e-09, 8.269349728357317e-08, 2.899679707810180e-06, 1.581258928964875e-03, 1.220575574556864e-02, 3.578608367163512e-02, 2.718179304102961e-01, 4.419528760847412e+00, 1.299263037173193e+02, 8.475735238569147e+03, 1.757536601598256e+06, 1.974753622954275e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pw6b95_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pw6b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.479281294991928e-138, -3.256046006393622e-138, -2.960051208472817e-138, -2.581274003965762e-138, -8.482332477866573e-138, -6.397921113563909e-138, -8.542738895584960e-138, 0.000000000000000e+00, -3.369153414520278e-137, -8.531848332150388e-137, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -1.749655682672519e-131, -3.589032619196331e-131, -4.991570423523757e-131, 8.021027003778716e-131]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
