
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_20_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.220888241814778e+00, -5.118121349709196e+00, -4.973934593136743e+00, -4.773771367433616e+00, -4.499991366542059e+00, -4.132997084079342e+00, -3.653654843191073e+00, -3.046038708520536e+00, -2.301963779129073e+00, -1.480468953730276e+00, -8.442837889826099e-01, -5.759288085106664e-01, -5.786096304157741e-01, -5.020640670543066e-01, -3.321263756757213e-01, -1.687809539272579e-01, -6.973167207419929e-02, -2.197785409231441e-02, -4.543023682593642e-03, -5.024391488418586e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_20_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.391487423069232e+00, -6.251041893219457e+00, -6.054545409506545e+00, -5.783084077401734e+00, -5.415059302415655e+00, -4.930253239569497e+00, -4.319929166690438e+00, -3.605190776530904e+00, -2.834217562899145e+00, -1.959119872543227e+00, -1.125636344395170e+00, -7.860197782862866e-01, -8.647667313651776e-01, -6.792154991027953e-01, -4.426447885390670e-01, -2.237952742697701e-01, -9.172132100272018e-02, -2.891837212630022e-02, -5.968028086812850e-03, -6.591325280691519e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_20_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.275471832553252e-05, -1.378912341504091e-05, -1.541776079488737e-05, -1.808221805650463e-05, -2.268069874752932e-05, -3.121504742217624e-05, -4.859297143222937e-05, -8.760696230855747e-05, -1.775556868174970e-04, -3.407628068017811e-04, -5.937427869440594e-04, -3.491380657619351e-03, -2.550081327514964e-02, -6.382683862882586e-02, -1.631290164754395e-01, -3.333578740571269e-01, -6.147656760944277e-01, -2.799944200036266e+00, -6.546220210825530e+01, -6.082317499765660e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_20_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.510957685573892e-02, 1.548363680564391e-02, 1.603736449764103e-02, 1.686627636666328e-02, 1.812445068809431e-02, 2.005980500731466e-02, 2.302764928306069e-02, 2.717016747427767e-02, 3.000873345423640e-02, 2.178577530717568e-02, 7.005809919683376e-03, 5.368741469399287e-03, 6.448826659263870e-02, 1.061373862628577e-01, 1.073004550511657e-01, 4.163712202659952e-02, 6.023228484047204e-03, 7.473150577313336e-04, 1.452615402378819e-04, 1.846106874198529e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_20_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.784368456979639e-02, -1.868652595584618e-02, -1.995609672441086e-02, -2.190048556762954e-02, -2.493484443129875e-02, -2.973382450675654e-02, -3.717463480620419e-02, -4.725134798101503e-02, -5.986847911742143e-02, -1.230361399458658e-01, -2.682210543964266e-01, -7.368248994618972e-01, -1.046873662783377e+00, -1.408514760625540e+00, -2.643536961716878e+00, -6.985471481631123e+00, -3.350455078258938e+01, -3.467885966443549e+02, -8.207494997449072e+03, -6.738851573989908e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_20_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.051124565219342e-08, 1.035328010917236e-07, 1.254465646818316e-07, 1.648381879411965e-07, 2.423704459003392e-07, 4.142765286555487e-07, 8.509144379484003e-07, 2.025776456055858e-06, 2.988869093442091e-06, -3.639486977433895e-05, -5.139517264560530e-04, -7.823039271838578e-03, 1.831601958354120e-02, 1.141533438933029e-01, -1.111202789648910e+00, -3.397101406506532e+01, -5.046864929085164e+01, 2.689806054364988e+05, 8.998762846923953e+08, 5.908915427772430e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_20_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.073551180685119e-05, -6.702257207663393e-05, -7.716167650241243e-05, -9.430493656021886e-05, -1.251958263903892e-04, -1.854219836625311e-04, -3.114567305424013e-04, -5.551252877223305e-04, -5.167114709124615e-04, 2.689147761015390e-03, 7.156417774896586e-03, 3.582982321338974e-02, 1.180891083935030e-01, 2.411938521671413e-02, 1.005509542944926e+00, 4.723757362568969e+00, 2.402051084863928e+00, -6.284540320684004e+01, -1.983058426291725e+03, -1.793317991793855e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_20_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.768974304768211e-13, -2.242630023417798e-13, -3.151112041308207e-13, -5.126422528597499e-13, -1.026360485611613e-12, -2.748016092836603e-12, -1.095193876976243e-11, -7.306657450836087e-11, -8.674188917869911e-10, -1.681637021229433e-08, -6.486811146815600e-07, -5.453243204165645e-05, -2.538795675879024e-03, -3.744240254550652e-02, -1.380028780557468e+00, -1.681850042340142e+02, -1.633655868373568e+05, -1.971778890771900e+09, -7.118223914609269e+14, -3.627884375895602e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_20_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.110357877407356e-10, 6.168889957543274e-10, 8.083027528548296e-10, 1.190843027466448e-09, 2.072944886408699e-09, 4.564858673767673e-09, 1.389581819180776e-08, 6.427220179636956e-08, 4.610744083890397e-07, 4.065632642266455e-06, 3.930540574559822e-05, 1.395579848832409e-03, 2.835970866151327e-02, 2.250604380619254e-01, 3.612501606421918e+00, 7.067834035663913e+01, 2.539728277139802e+03, 6.295441653572645e+05, 1.942127578125518e+09, 1.370681749176030e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_20_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_20", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.665119681383312e-07, -4.300358429326820e-07, -5.408435295176872e-07, -7.510078861582596e-07, -1.199994903323348e-06, -2.333414987638004e-06, -5.919039629885252e-06, -2.080548826381369e-05, -9.560348905849218e-05, -3.672376323755758e-04, -7.346157100400287e-04, -4.888407959667904e-03, -9.825092800104340e-02, -4.649713023302739e-01, -3.333911347896334e+00, -1.304573341034685e+01, -3.230426658274517e+01, -1.955408486729452e+02, -5.114196781687131e+03, -4.978421780083319e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
