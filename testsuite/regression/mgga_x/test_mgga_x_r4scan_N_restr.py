
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_r4scan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.884471859610466e+00, -4.785580324808835e+00, -4.646967434196069e+00, -4.454864610117206e+00, -4.192907387774397e+00, -3.843843484414923e+00, -3.393647754665321e+00, -2.838941025242570e+00, -2.196779174884571e+00, -1.503441413809009e+00, -8.332160732609176e-01, -5.657394653203746e-01, -5.739432407563542e-01, -4.927893339907630e-01, -3.328389415852947e-01, -1.752069755957383e-01, -6.616703310148656e-02, -1.691377752615844e-02, -2.226489851277001e-03, -1.021847106738345e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_r4scan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.404003036709200e+00, -6.270983091985995e+00, -6.084497708227604e+00, -5.825959821047908e+00, -5.473182341562192e+00, -5.002517399974182e+00, -4.394107294066271e+00, -3.641360173604118e+00, -2.760062967147055e+00, -1.768226188387309e+00, -1.123442882539844e+00, -7.854701124924023e-01, -8.776527098666963e-01, -6.627319987735346e-01, -4.119896224420061e-01, -1.672526790033677e-01, -6.028364409083844e-02, -2.489633261162479e-02, -3.744094809292803e-03, -1.556495125317401e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r4scan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.330294836696240e-06, -3.594473010639902e-06, -4.010920263465051e-06, -4.694756122575090e-06, -5.886569462657985e-06, -8.152550958723369e-06, -1.304004970025219e-05, -2.572613454541497e-05, -7.078508755902574e-05, -3.779272455608338e-04, -7.649884088004276e-04, -5.453707666551441e-03, -2.998252929936030e-02, -4.178653175903010e-02, -1.699819520745575e-01, -1.426038601071036e+00, -7.456423429269792e+00, -6.069914795105828e+00, 8.930530480309130e+01, -1.044767428112376e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r4scan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.924521073507591e-03, 5.004510362246704e-03, 5.121536043757372e-03, 5.294608582442588e-03, 5.555379189143572e-03, 5.960094956999705e-03, 6.612943793126581e-03, 7.726907632820483e-03, 1.003658324265010e-02, 1.840342093688396e-02, 9.422057059926266e-03, 8.634945161498203e-03, 7.690232531935497e-02, 6.905750664685691e-02, 9.220298595019398e-02, 1.364657642476022e-01, 6.324581356965532e-02, 4.392871132384834e-03, 4.301558364862945e-04, 7.065563277455702e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r4scan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.310095362351990e-02, -1.366333983088540e-02, -1.451684532580917e-02, -1.584388273284065e-02, -1.797913577391387e-02, -2.157268579472324e-02, -2.792889627141073e-02, -3.981799687478387e-02, -6.368043232675555e-02, -1.786090528825389e-01, -3.201991784072668e-01, -7.572444018029928e-01, -1.282803993899138e+00, -1.477123357807309e+00, -4.147423645054225e+00, -4.051775884030685e+01, -8.587557954648032e+02, -2.997182613773538e+03, -6.229764659409902e+04, -1.278891770779186e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r4scan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.690225222870286e-09, 9.506025547851043e-09, 1.083120017779702e-08, 1.311088199743859e-08, 1.728912898972304e-08, 2.465623324602702e-08, 2.575565254694914e-08, -1.518355427379002e-07, -3.516650551086284e-06, -2.924433998779233e-05, 1.183431877986562e-04, -1.932727492799661e-02, 1.203243638599798e-01, 1.877504897795964e-01, 1.360483464468012e+00, 4.108962702017738e+02, 1.660562350706736e+05, 1.660509612753613e+07, 3.986697279864455e+10, 7.055196354587898e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r4scan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.062832343179503e-06, 1.033122789514354e-05, 1.236287408147821e-05, 1.577776720536506e-05, 2.200884706974633e-05, 3.530805664847495e-05, 7.233625245188742e-05, 2.106383307029447e-04, 9.386284224359221e-04, 3.961721072271895e-03, 1.341574198819438e-03, 5.012468399371017e-02, 9.853781253934719e-02, -3.652705696876254e-02, 4.056779701780597e-01, -2.798577740658857e+01, -1.241946481094475e+03, -4.036537555758035e+03, -8.508011979476655e+04, -2.126723457299437e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r4scan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.368922841334229e-13, 4.241339752066848e-13, 5.889322769672209e-13, 9.395513284875030e-13, 1.827667249815908e-12, 4.758186669122211e-12, 1.932014545878783e-11, 1.511402909712498e-10, 3.001838983243058e-09, 1.423960338291512e-07, -2.248852305336095e-06, 1.735160675755616e-03, 1.623332937234827e-02, 1.129687938915489e-01, 5.717262760674182e+00, -5.416189301966064e+03, -3.420741193663594e+07, -1.059562297806206e+11, -2.905748254922318e+16, -3.989732283028243e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r4scan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.732927535842868e-10, -4.440646183471314e-10, -5.689667191760784e-10, -8.102213270127171e-10, -1.342669987103336e-09, -2.781462218430363e-09, -8.076421681785375e-09, -3.850860846124216e-08, -3.749012711306050e-07, -6.261857686563249e-06, 4.278288925829747e-05, 8.228067633275701e-04, -2.660091728094181e-02, -1.349956250666451e-01, -2.509965903129975e+00, 5.213512532899159e+02, 2.687540325418995e+05, 2.673861770380203e+07, 6.387436557998916e+10, 1.216739766062783e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r4scan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r4scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.042448894435965e-07, 4.551794860850151e-07, 5.398212282454869e-07, 6.897748530310275e-07, 9.813480277487376e-07, 1.630819544578363e-06, 3.396220262830184e-06, 9.849557814973914e-06, 4.692906269280136e-05, 2.764846955404599e-04, -6.086168236455210e-04, -5.665065488563280e-03, -3.555586225351555e-02, 1.707320222046832e-01, 1.116444859488139e+00, -5.001483383187838e+01, -2.115055554211839e+03, -6.866109933415026e+03, -1.442298055984441e+05, -3.731178877107812e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
