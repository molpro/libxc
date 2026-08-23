
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m06_hf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.384884846996255e-01, -1.366698123143271e-01, -1.340105875962742e-01, -1.300932691650278e-01, -1.242595116550477e-01, -1.154340396690188e-01, -1.017881937330975e-01, -8.012367283161434e-02, -4.516148807764692e-02, 6.288786792432739e-03, 2.387668119783876e-02, -6.250230959236411e-02, -5.543891178094948e-02, -5.070785688946002e-02, -9.903618880271492e-03, 3.019392173843475e-02, -4.273871289134928e-02, -6.998862488599558e-02, -2.092546570496791e-02, -2.579225587926745e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m06_hf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.804631010443811e-01, -1.830709743586432e-01, -1.868274828586607e-01, -1.922102900339218e-01, -1.998130275996638e-01, -2.101604411384490e-01, -2.229339907039253e-01, -2.345416710499155e-01, -2.331393990967826e-01, -1.979455340816166e-01, -1.445578298178972e-01, -7.715433265429807e-02, -4.586680425827944e-02, -1.127136619424778e-01, -1.304132948514260e-01, -2.044602688650901e-03, 6.417976004110743e-02, -1.362771563320780e-01, -5.283784497708792e-02, -7.274759065960962e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_hf_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.779806696115017e-07, -4.150661883071797e-07, -3.063383774808883e-07, -1.072746010481323e-07, 2.832997531036396e-07, 1.113113354489890e-06, 3.033165219791482e-06, 7.836083199232037e-06, 2.056246907439355e-05, 6.534182843251582e-05, 6.267231122597264e-04, 3.268530561684955e-03, -8.355905869378734e-03, 1.653438734550313e-02, 9.941390818568786e-02, 2.667614573831656e-01, 1.840819478724626e+00, 3.967020431113283e+02, 1.879597139138355e+04, 2.176153054863543e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_hf_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.840303903905238e-03, 1.752761055062311e-03, 1.627721869733550e-03, 1.450822613973433e-03, 1.206028178829581e-03, 8.848214601905494e-04, 5.186767218238085e-04, 2.681547082304824e-04, 5.319006042524969e-04, 1.114297502682184e-03, -2.009312505874076e-03, -2.937344034911391e-03, 2.444003024724127e-03, 6.431870968398734e-03, 8.467621634545021e-03, -8.661880410510494e-03, -1.099609349107462e-01, -1.111364642510509e-01, -4.171065597762918e-02, -6.605005261776931e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_hf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.049375593428713e-03, 2.192379859502028e-03, 2.406574187728926e-03, 2.729955032981960e-03, 3.217147684634606e-03, 3.920621442591179e-03, 4.730402897531562e-03, 4.406816784633409e-03, -4.413850161743805e-03, -5.794717460796162e-02, -2.413336112879612e-01, 1.525098962310076e-01, 9.801153874457165e-02, 9.119789247681980e-01, -1.152114613854073e+00, -3.818827255208934e+01, 3.750148301381362e+02, 2.318949339911499e+03, -7.007375998028471e+04, -9.017467887500608e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_hf_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.692667580660547e-08, -4.202405153882790e-08, -5.041116513829717e-08, -6.493834745732508e-08, -9.176814867199042e-08, -1.447460531419284e-07, -2.506002773385909e-07, -3.714739912026554e-07, 1.164383652282505e-06, 3.225317560619170e-05, 4.582895486931741e-04, -2.497240592403147e-02, -4.361452613385356e-02, -4.172121306323974e-01, 1.427093090339228e+00, 2.019201211476487e+02, -2.744536397955653e+04, -6.298693396471157e+06, 1.575474295151028e+10, 1.737225166898662e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_hf_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.210948591050777e-05, 3.425856251559468e-05, 3.743520451599025e-05, 4.212062217735512e-05, 4.886424463333256e-05, 5.758641840189886e-05, 6.366749509242306e-05, 3.791906707066420e-05, -1.561987079227268e-04, -6.692956171396016e-04, 1.860328616101558e-03, 1.254997420605882e-02, 3.015664014608680e-03, 8.505410096571475e-02, -3.932610821075560e-01, 2.822812378206185e-01, 3.358383231878074e+01, -4.460349791530152e+02, -3.858997509479151e+04, -5.277582290084236e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_hf_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.623171279289234e-13, 5.591218686201592e-13, 7.313382164162646e-13, 1.064698567142039e-12, 1.784697684806533e-12, 3.545305810635526e-12, 8.066995999309400e-12, 8.579479279408034e-12, -4.971065026375710e-10, -3.109451644496113e-08, -4.398569877087325e-06, 1.073478438055415e-03, 1.459961221905915e-02, 1.216034043874184e-01, -5.024631042497258e+00, -2.089626472036920e+03, 2.405058931380775e+06, 2.583528827835243e+10, 7.272325437338299e+14, 6.113450855568625e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_hf_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.726967577275815e-11, -7.327315057620952e-11, -1.195996263161054e-10, -2.083384188249913e-10, -3.937731220137557e-10, -8.179846946913021e-10, -1.823925735585437e-09, -3.189994424453453e-09, 2.162966266150596e-08, 7.227777460073887e-07, 1.840018933897268e-05, 3.063628916611036e-04, 1.421852226705787e-02, -1.693678526177677e-02, 1.016772339912928e+00, 1.050448895157548e+02, -8.311275134647876e+03, -1.998380992856467e+07, -1.060043718389249e+11, -9.645986378115002e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_hf_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.229487796158020e-07, -8.295756689012394e-07, -8.343302408830773e-07, -8.297726437769437e-07, -7.951583808028269e-07, -6.753123110833778e-07, -3.396945514625949e-07, 3.377769248540954e-07, -8.502585488391334e-07, -3.222510462099815e-05, -2.532562589084864e-04, -1.205668344518403e-03, -1.783133850567480e-02, -3.269397034932833e-02, -4.657809843821987e-01, -1.332904398135876e+01, 1.089079830883477e+02, 9.436086336168257e+03, 4.669108561057397e+05, 5.854888104032507e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
