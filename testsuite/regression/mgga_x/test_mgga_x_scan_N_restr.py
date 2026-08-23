
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_scan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.884522762986202e+00, -4.785633297178157e+00, -4.647023611485404e+00, -4.454926050389025e+00, -4.192978422105145e+00, -3.843934946792871e+00, -3.393790021654554e+00, -2.839223244516172e+00, -2.197517147046585e+00, -1.505584476766062e+00, -8.395764509993102e-01, -5.691015783201449e-01, -5.679719532584933e-01, -4.932536886526031e-01, -3.330236835186423e-01, -1.733961502614364e-01, -6.624642727935902e-02, -1.689025964502427e-02, -2.219081546958482e-03, -1.014935476959485e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_scan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.410712326004933e+00, -6.277666039162364e+00, -6.091143973120515e+00, -5.832569095697251e+00, -5.479809000328292e+00, -5.009400353794469e+00, -4.401895662812342e+00, -3.651171162625762e+00, -2.773995568471954e+00, -1.772682251649628e+00, -1.142960622663081e+00, -7.845002491606716e-01, -8.794093013437501e-01, -6.631170688861313e-01, -4.081577968273494e-01, -2.015412514506051e-01, -6.288445737138326e-02, -2.547607353164279e-02, -3.954826066442550e-03, -1.955051426217062e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.139273246706629e-06, -3.391835633371232e-06, -3.790247024240197e-06, -4.444581764638883e-06, -5.583353817411170e-06, -7.738105815012517e-06, -1.234518352011910e-05, -2.420172138196669e-05, -6.602681700544857e-05, -3.788874707588377e-04, -8.471851665606087e-04, -5.688579279926464e-03, -2.967994401404833e-02, -4.592541895298743e-02, -1.923934250062399e-01, -7.044670734272266e-01, -7.008686405884919e+00, -2.431693831421197e+00, 2.510369423886121e+02, 1.268831657284365e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.652082778405854e-03, 4.732721666778545e-03, 4.850519479695296e-03, 5.023780529984560e-03, 5.281250322995307e-03, 5.670244841839579e-03, 6.276396707672618e-03, 7.292064942908364e-03, 9.402612324588847e-03, 1.850776693275892e-02, 1.073924342103494e-02, 8.414907902893221e-03, 8.044830441771668e-02, 7.543193277436450e-02, 1.044303224417811e-01, 6.954841942512124e-02, 6.007802919753245e-02, 3.517960263800629e-03, 7.116768495169330e-05, 1.744518436170300e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.313318653540092e-02, -1.369856272261088e-02, -1.455297630567721e-02, -1.587196613225574e-02, -1.797059859432965e-02, -2.145502777341102e-02, -2.759407684461439e-02, -3.931664442055507e-02, -6.405118041150752e-02, -1.345886366543179e-01, -3.570109680499601e-01, -1.036696158086416e+00, -1.917293137669098e+00, -1.520986931763756e+00, -3.937797266047410e+00, -2.564721485619497e+02, -8.142935451196693e+02, -2.406389528153797e+03, -1.810729211406927e+04, -4.855734947287475e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.991736258432629e-09, 1.099884022323788e-08, 1.256069110992784e-08, 1.500891084119227e-08, 1.873348963775822e-08, 2.300848498651197e-08, 1.464381300969372e-08, -1.582287111470751e-07, -2.953225228245266e-06, -9.658292765038499e-05, -9.629701760376349e-05, -7.207448167861260e-03, -8.547025217019169e-02, 2.210846071503569e-01, -7.878321047891054e-01, 4.839014788205075e+03, 1.572326734863076e+05, 1.295742110982527e+07, 7.432864905247581e+09, 7.717374183728853e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.584027036854062e-06, 7.675876319479345e-06, 9.510221917551168e-06, 1.279743247816300e-05, 1.924201217187577e-05, 3.354962513488534e-05, 7.128529202048668e-05, 1.984249528733354e-04, 8.267054115959662e-04, 7.184319148878779e-03, 4.905027316414005e-03, 6.135749246604599e-02, 5.712655139415576e-01, -6.368175800713533e-02, 1.702081342034384e+00, -4.456480471181246e+02, -1.176572175344802e+03, -3.145499936947933e+03, -1.327488271008208e+04, -4.951037952378560e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.889216518705872e-13, 3.658022725994575e-13, 5.132248152584617e-13, 8.339910099601817e-13, 1.671327763647772e-12, 4.514109669184859e-12, 1.863804411181013e-11, 1.414128320617980e-10, 2.669492448692083e-09, 2.444644022059801e-07, -1.123116153452167e-05, 9.650015552964358e-04, -1.973314330759362e-02, 2.483632260555746e-01, 1.833227311418256e+01, -9.486122216035496e+04, -3.245257372659238e+07, -8.346803095410143e+10, -5.241631202565065e+15, -3.150766841288250e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.306486018787155e-10, -3.950007699902645e-10, -5.098618663568385e-10, -7.352200171512378e-10, -1.241867722466275e-09, -2.627834019684990e-09, -7.665234918278020e-09, -3.549554887508443e-08, -3.315813968133831e-07, -1.113472363288094e-05, 1.576970061500102e-04, 6.471411468180772e-04, 9.352195263572900e-02, -3.523781051104429e-01, -9.207109039418727e+00, 8.842877731753606e+03, 2.551337101137592e+05, 2.108631472619487e+07, 1.023583333781561e+10, 2.877421024275299e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.801175243597784e-07, 4.282975067137559e-07, 5.083577318494189e-07, 6.500752524589519e-07, 9.248324490619052e-07, 1.532245548588386e-06, 3.157243594381422e-06, 8.930363970704198e-06, 4.132742388375667e-05, 5.090346036194134e-04, -2.085611861239537e-03, -6.442629705166694e-03, -3.537351895651189e-01, 5.227717574465918e-01, 4.684314197210226e+00, -8.242640167651831e+02, -2.009750725042878e+03, -5.448074920250225e+03, -2.346054918807968e+04, -8.904836758527684e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
