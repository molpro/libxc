
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_csk_loc4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.440059877709609e+01, 2.437002268726017e+01, 2.435676579362631e+01, 2.442245215811318e+01, 2.469393102887533e+01, 2.528518631663347e+01, 2.596681211279405e+01, 2.594838078849890e+01, 2.468703811474181e+01, 2.287748794470213e+01, 1.959088078633832e+01, 6.235897847564836e+00, 7.840898077054369e-01, 8.821652585802418e-01, 9.499281869065066e-01, 8.863147970964319e-01, 8.458184902180145e-01, 8.262714045320076e-01, 8.157274784493715e-01, 8.127092903791464e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_csk_loc4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.433936982864512e+01, -2.414391951225926e+01, -2.357375657366827e+01, -2.195086962683934e+01, -1.787576009806176e+01, -9.809868527786172e+00, 8.623801047043380e-01, 7.712691584174824e+00, 8.014730774435147e+00, 1.771076107225306e+01, 8.371748373761180e+00, 3.632592914019141e+00, 2.543985330135477e+00, 1.626064362299106e+00, 9.113145139178133e-01, 3.698760700783861e-01, 1.634593966177933e-01, 1.114856907344471e-01, 9.966725139959826e-02, 9.475084561030607e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.979507215137548e-04, 7.418521819248228e-04, 8.091846097143949e-04, 9.136980439876914e-04, 1.074899615592109e-03, 1.313165051787939e-03, 1.649778211926696e-03, 2.204098610257338e-03, 3.372054983038155e-03, -2.625493395614732e-03, -1.283787627445623e-02, -3.330196534929535e-02, -2.452643184342176e-02, -2.948478551756636e-02, -3.068477331553621e-01, -1.771713848387520e+00, -2.100199904314878e+01, -6.408240228827160e+02, -7.221231626582904e+04, -5.342160670691156e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc4_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.429832931818279e-06, 5.022624385289930e-05, 2.511633207808608e-04, 1.146380783400147e-03, 4.579142182252077e-03, 1.506449664220920e-02, 3.791091665983388e-02, 6.959044795109592e-02, 1.021009535985612e-01, 2.094487551881688e-01, 2.171250000000000e-01, 2.171250000000000e-01, 2.014094572504836e-01, 1.957631753566080e-01, 2.170255722925144e-01, 2.171250000000000e-01, 2.171250000000000e-01, 2.171250000000000e-01, 2.171250000000000e-01, 2.171250000000000e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.747245318826290e-01, 2.981752813801353e-01, 3.497224246788321e-01, 4.834349422860599e-01, 8.560482997876836e-01, 1.841784441172114e+00, 4.074077492087941e+00, 8.469290213454142e+00, 1.883193290244632e+01, 1.838808957486689e+01, 4.737695900683681e-01, 3.240124512958061e+00, 1.394018083387828e+01, 3.083882279841437e+01, 5.797970242630874e+00, -7.239921611531125e+00, -2.045112279934018e+02, -6.526602378586703e+03, -6.959728779771243e+05, -4.908181024767150e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.898969295885589e-06, -4.414245814730767e-06, -5.307780451965812e-06, -7.095445455251716e-06, -1.168730991218286e-05, -2.754203681422880e-05, -9.486355299093291e-05, -4.304110492499960e-04, -2.862266339426288e-03, -1.246888739951685e-02, 7.990839623672545e-03, 5.377071011518392e-02, -1.534853949562799e+00, -9.143075614721056e+00, 1.938387984149697e+00, 1.521924829366359e+02, 2.138588915434775e+04, 1.991056622078001e+07, 2.528299937200541e+11, 1.383693606374758e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc4_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.513717637714251e-07, 2.587370488181015e-06, 1.436973541254213e-05, 7.609331975466984e-05, 3.739749265450934e-04, 1.635083118255729e-03, 6.076911685498359e-03, 1.951880811605150e-02, 6.650440510703065e-02, 1.135031683707534e-01, -2.817681462947307e-132, -1.127072585178923e-131, 9.775194220055052e-01, 2.955683902370986e+00, 2.638731051845399e-01, -3.606632272572553e-130, 0.000000000000000e+00, -2.769893585335721e-127, 1.181821263076574e-125, 1.210184973390412e-122]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_csk_loc4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.354120831799891e-15, 1.261063868932347e-14, 1.200051202703228e-13, 1.175270143493683e-12, 1.191742561408924e-11, 1.256956453249769e-10, 1.408284309807887e-09, 1.873738879798678e-08, 4.185539418763809e-07, 9.534617687556366e-06, 0.000000000000000e+00, 0.000000000000000e+00, 2.548560299469446e-01, 3.295922482679834e+00, 4.387065912288530e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc4_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.615718327035168e-13, -3.167280708833322e-12, -2.760262614542197e-11, -2.382535190800537e-10, -2.015555127808931e-09, -1.639762034584140e-08, -1.267305938910385e-07, -9.927901548569688e-07, -1.046025668570116e-05, -8.379940323509305e-05, 0.000000000000000e+00, 0.000000000000000e+00, -1.562409195003624e-01, -1.049626181171214e+00, -4.382406226117986e-01, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc4_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.654543902910692e-11, 7.954923882674403e-10, 6.348937182077479e-09, 4.829931200777978e-08, 3.408842316107327e-07, 2.139150901458655e-06, 1.140440415058395e-05, 5.260243581468643e-05, 2.614166514362248e-04, 7.365098646506385e-04, 0.000000000000000e+00, 0.000000000000000e+00, 9.578437257851267e-02, 3.342660896879739e-01, 4.377751489194989e-02, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
