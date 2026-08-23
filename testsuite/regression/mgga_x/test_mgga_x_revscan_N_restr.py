
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_revscan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.884600910075384e+00, -4.785716224773666e+00, -4.647113996761823e+00, -4.455028496464663e+00, -4.193101419442008e+00, -3.844095727440770e+00, -3.394028413864221e+00, -2.839649295569805e+00, -2.198522322230822e+00, -1.509112561882240e+00, -8.267344572214018e-01, -5.565614591600879e-01, -5.702474631413381e-01, -4.949782445739254e-01, -3.341577803748875e-01, -1.735272681412252e-01, -6.526574078260740e-02, -1.663079971630934e-02, -2.185237731037882e-03, -9.994683725631329e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_revscan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.420900189387262e+00, -6.288009244390843e+00, -6.101712444506300e+00, -5.843465659448532e+00, -5.491186824546063e+00, -5.021492643272582e+00, -4.415071837032126e+00, -3.666064228823825e+00, -2.791872906165129e+00, -1.794933013026882e+00, -1.124231041690625e+00, -7.653520112227324e-01, -8.954950167702452e-01, -6.655067418181725e-01, -4.115391132306304e-01, -1.897056586441077e-01, -6.042358288525788e-02, -2.510620664230235e-02, -3.895214225496821e-03, -1.925274941532548e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.847349193285991e-06, -3.076120833826687e-06, -3.436959603467895e-06, -4.029489144532780e-06, -5.060477064189733e-06, -7.010805915756894e-06, -1.118021074498924e-05, -2.191651176541608e-05, -5.995569240584986e-05, -3.542271860978803e-04, -9.077882733124251e-04, -6.039704573566550e-03, -3.178164967374286e-02, -4.354683215302978e-02, -1.843613721211063e-01, -9.436688036151555e-01, -7.236022986031608e+00, -2.248979264279037e+00, 2.477517007819908e+02, 1.249597039009178e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.234126692136929e-03, 4.307566934566683e-03, 4.414858547859077e-03, 4.572690255111153e-03, 4.807293614969978e-03, 5.161921954113914e-03, 5.715142861212359e-03, 6.644808066105191e-03, 8.594127242400976e-03, 1.736252754573659e-02, 1.140404770592909e-02, 8.584590310556714e-03, 8.789916891275563e-02, 7.174273405219242e-02, 1.003010789511335e-01, 9.183851449541561e-02, 6.177394873769859e-02, 3.426407313910108e-03, 6.884065093487665e-05, 1.686510361276866e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.301867719117045e-02, -1.357613472916911e-02, -1.441827900307651e-02, -1.571763998298078e-02, -1.778340064420180e-02, -2.120904021430724e-02, -2.723223028858459e-02, -3.868832103350696e-02, -6.259119305590971e-02, -1.242898561788855e-01, -3.617405282490543e-01, -1.060974273555519e+00, -1.662152693582520e+00, -1.498887274153154e+00, -3.786822242425768e+00, -2.892308185218611e+02, -8.641967473672757e+02, -2.355250240683840e+03, -1.769688986193718e+04, -4.776685354753517e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.654337536272339e-09, 9.490353694956072e-09, 1.076981461098458e-08, 1.272434946810232e-08, 1.551462443141036e-08, 1.782355451635450e-08, 4.734991138969462e-09, -1.811211681964065e-07, -3.017817416189875e-06, -1.039239759302178e-04, -1.345081144221643e-04, -7.784512128962420e-03, -2.619206417136402e-02, 2.146428832409136e-01, -1.224411901407360e+00, 5.444297368914768e+03, 1.679238825522398e+05, 1.266966669329020e+07, 7.218213435274215e+09, 7.570697235313009e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.368529665906323e-06, 7.409050027546474e-06, 9.156078536349636e-06, 1.228456638493446e-05, 1.841356875277147e-05, 3.201414806681048e-05, 6.789643959227650e-05, 1.890797846294442e-04, 7.933322161321325e-04, 7.359392634254449e-03, 5.626902524279408e-03, 6.499696280509565e-02, 4.009166626277862e-01, -6.864420663684608e-02, 1.885450893020160e+00, -5.002046563558657e+02, -1.259024744050776e+03, -3.075408310926529e+03, -1.284461294963903e+04, -4.786443879121167e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.716835478005216e-13, 3.439976969534998e-13, 4.826799335849761e-13, 7.844871486394827e-13, 1.572599998991746e-12, 4.249959843802223e-12, 1.756909096032409e-11, 1.336865588846773e-10, 2.545342296505907e-09, 2.485079771251180e-07, -1.288501072460093e-05, 1.029838633835463e-03, -9.892800150501922e-03, 2.561605610119906e-01, 1.997136956935743e+01, -1.064114245345089e+05, -3.473942470685340e+07, -8.162327451641328e+10, -5.085055607334743e+15, -3.086010234709212e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.118408162003569e-10, -3.725751899843098e-10, -4.809987458917010e-10, -6.937865115386862e-10, -1.172389681252110e-09, -2.482630770612586e-09, -7.251341705817633e-09, -3.367257531998562e-08, -3.171009895710878e-07, -1.135168133686151e-05, 1.800004987826261e-04, 6.928771963107709e-04, 6.207980325683552e-02, -3.695581517554475e-01, -1.011473048043742e+01, 9.920589644989774e+03, 2.731329087107611e+05, 2.061682158359189e+07, 9.904067928959089e+09, 2.781763004001317e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.615810680664614e-07, 4.074201121416783e-07, 4.835941217526638e-07, 6.184434060664673e-07, 8.799222470189328e-07, 1.458143285966729e-06, 3.006032233210053e-06, 8.515136207932337e-06, 3.965530465729304e-05, 5.202640011440305e-04, -2.375899211043295e-03, -6.817312013097696e-03, -2.545934855612471e-01, 5.560646588645937e-01, 5.180944414171249e+00, -9.248233689025111e+02, -2.151295404972922e+03, -5.326701409399456e+03, -2.270012156151464e+04, -8.608801032642834e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
