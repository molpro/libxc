
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_r2scan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.884471859610466e+00, -4.785580324808835e+00, -4.646967434196069e+00, -4.454864610117206e+00, -4.192907387774397e+00, -3.843843484414923e+00, -3.393647754665321e+00, -2.838941025242570e+00, -2.196779174884571e+00, -1.503441414294840e+00, -8.332160732609176e-01, -5.657394653203746e-01, -5.759807489742187e-01, -4.927895812936588e-01, -3.328390511596904e-01, -1.752069756014414e-01, -6.616703310148656e-02, -1.691377752615844e-02, -2.226489851277001e-03, -1.021847106738345e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_r2scan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.404003036709200e+00, -6.270983091985995e+00, -6.084497708227604e+00, -5.825959821047908e+00, -5.473182341562192e+00, -5.002517399974182e+00, -4.394107294066271e+00, -3.641360173604120e+00, -2.760062967147139e+00, -1.768226231948348e+00, -1.123442882539844e+00, -7.854701124924023e-01, -8.604936939781443e-01, -6.627317364235352e-01, -4.119936997486793e-01, -1.672526798566256e-01, -6.028364409083844e-02, -2.489633261162479e-02, -3.744094809292803e-03, -1.556495125317401e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.330294836696239e-06, -3.594473010639901e-06, -4.010920263465049e-06, -4.694756122575087e-06, -5.886569462657981e-06, -8.152550958723361e-06, -1.304004970025216e-05, -2.572613454541468e-05, -7.078508755899618e-05, -3.779271920423144e-04, -7.649884088004276e-04, -5.453707666551441e-03, -2.490873120584636e-02, -4.178096259175278e-02, -1.699666562673761e-01, -1.426038593663544e+00, -7.456423429269792e+00, -6.069914795105828e+00, 8.930530480309130e+01, -1.044767428112376e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.924521073507589e-03, 5.004510362246702e-03, 5.121536043757370e-03, 5.294608582442586e-03, 5.555379189143568e-03, 5.960094956999698e-03, 6.612943793126565e-03, 7.726907632820401e-03, 1.003658324264624e-02, 1.840341857800451e-02, 9.422057059926266e-03, 8.634945161498203e-03, 6.354776320468476e-02, 6.904839925603101e-02, 9.219535302566320e-02, 1.364657638806388e-01, 6.324581356965532e-02, 4.392871132384834e-03, 4.301558364862945e-04, 7.065563277455702e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.310095362351994e-02, -1.366333983088544e-02, -1.451684532580922e-02, -1.584388273284071e-02, -1.797913577391397e-02, -2.157268579472344e-02, -2.792889627141133e-02, -3.981799687478851e-02, -6.368043232720552e-02, -1.786096512822770e-01, -3.201991784072668e-01, -7.572444018029928e-01, -1.043481479309964e+00, -1.477054213045683e+00, -4.149168159862987e+00, -4.051776886756842e+01, -8.587557954648032e+02, -2.997182613773538e+03, -6.229764659409902e+04, -1.278891770779186e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.690225222871265e-09, 9.506025547852240e-09, 1.083120017779863e-08, 1.311088199744105e-08, 1.728912898972767e-08, 2.465623324603910e-08, 2.575565254700389e-08, -1.518355427371613e-07, -3.516650550924375e-06, -2.924357788332424e-05, 1.183431877986562e-04, -1.932727492799661e-02, 8.204246203891960e-02, 1.876607323093362e-01, 1.367860937324255e+00, 4.108963538127313e+02, 1.660562350706736e+05, 1.660509612753613e+07, 3.986697279864455e+10, 7.055196354587898e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.062832343178092e-06, 1.033122789514192e-05, 1.236287408147622e-05, 1.577776720536237e-05, 2.200884706974210e-05, 3.530805664846645e-05, 7.233625245186090e-05, 2.106383307027349e-04, 9.386284224145470e-04, 3.961687085108205e-03, 1.341574198819438e-03, 5.012468399371017e-02, 4.980428229218610e-02, -3.642602612598088e-02, 4.018898182777927e-01, -2.798578123630169e+01, -1.241946481094475e+03, -4.036537555758035e+03, -8.508011979476655e+04, -2.126723457299437e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.368922841333943e-13, 4.241339752066476e-13, 5.889322769671663e-13, 9.395513284874073e-13, 1.827667249815690e-12, 4.758186669121467e-12, 1.932014545878284e-11, 1.511402909711320e-10, 3.001838983184942e-09, 1.423950713081666e-07, -2.248852305336097e-06, 1.735160675755616e-03, 8.291427012864234e-04, 1.124121959507210e-01, 5.687723909664530e+00, -5.416189946218417e+03, -3.420741193663594e+07, -1.059562297806206e+11, -2.905748254922318e+16, -3.989732283028243e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.732927535842459e-10, -4.440646183470813e-10, -5.689667191760110e-10, -8.102213270126132e-10, -1.342669987103139e-09, -2.781462218429844e-09, -8.076421681782983e-09, -3.850860846120910e-08, -3.749012711230183e-07, -6.261815325973588e-06, 4.278288925829750e-05, 8.228067633275701e-04, -1.394528276567241e-03, -1.340878519367955e-01, -2.495281266851593e+00, 5.213512777597755e+02, 2.687540325418995e+05, 2.673861770380203e+07, 6.387436557998916e+10, 1.216739766062783e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_r2scan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_r2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.042448894435381e-07, 4.551794860849477e-07, 5.398212282454039e-07, 6.897748530309148e-07, 9.813480277485593e-07, 1.630819544578001e-06, 3.396220262829037e-06, 9.849557814964636e-06, 4.692906269181117e-05, 2.764828324940601e-04, -6.086168236455213e-04, -5.665065488563280e-03, -3.885670528975884e-02, 1.692531843191632e-01, 1.109149185224092e+00, -5.001483432975196e+01, -2.115055554211839e+03, -6.866109933415026e+03, -1.442298055984441e+05, -3.731178877107812e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
