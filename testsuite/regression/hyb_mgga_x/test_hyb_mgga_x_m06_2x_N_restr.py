
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m06_2x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.504748802826384e+00, -1.475607952118031e+00, -1.438907124360543e+00, -1.396380316437658e+00, -1.352904468330138e+00, -1.311288742746296e+00, -1.251100334075159e+00, -1.141694567571344e+00, -1.025467891865149e+00, -7.652067441096778e-01, -6.419952266764765e-01, -3.445140530051753e-01, -2.555961588318357e-01, -2.171857868478002e-01, -1.649144070739003e-01, -1.407852811681036e-01, -1.131819016979752e-01, -6.479599518327224e-02, -1.463736510032507e-02, -1.625441666731572e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m06_2x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.954835398012329e+00, -1.814678664838951e+00, -1.617377948256477e+00, -1.359439385280259e+00, -1.081550548814338e+00, -9.220219093363465e-01, -1.015655733309935e+00, -9.349962765754473e-01, -8.929261354129308e-01, -5.846730801601654e-01, -3.535999893511510e-01, -1.903394002419991e-01, -2.211731720465171e-01, -1.685198051099872e-01, -1.839663559202956e-01, -1.039796422088616e-01, -4.434463864140718e-02, -7.590888868226857e-02, -1.940152222117523e-02, -2.167089169984949e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_2x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.346367251488754e-06, -1.455470290331940e-06, -1.632151011365154e-06, -1.934686781119809e-06, -2.494090077388890e-06, -3.628230127207997e-06, -6.141413959350410e-06, -1.246607714220205e-05, -3.329589850456392e-05, -1.044343997858258e-04, -6.298338686897805e-04, -3.605459954934160e-03, -5.910703978413349e-03, -1.274269678116433e-02, -4.652342641844093e-02, -2.934447255877486e-01, -1.583965740730556e+00, -4.564789114458494e+00, -5.961151452161607e+00, -6.609955253091825e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_2x_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.805832868182577e-03, -6.223502273755385e-04, -4.184728851972973e-03, -9.018335266905653e-03, -1.426666233182061e-02, -1.654892354891081e-02, -1.171509524346053e-02, -9.373376336769631e-03, -5.388435722441475e-03, -4.610718811456053e-03, -8.359941678384544e-03, -1.952192265525086e-02, -4.130353618112999e-02, -5.071093522337910e-02, 8.348228290109524e-03, -1.974664886177418e-02, -6.412714600034405e-02, -7.376223414381530e-03, -8.947576763562156e-05, -1.387346513434471e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_2x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.766890983748299e-02, -2.985574952663763e-02, -3.167885649445593e-02, -3.097205642078383e-02, -2.236939294938294e-02, 1.349387721200749e-03, 2.169588959391614e-02, -3.161849460556157e-02, 1.226034173856525e-01, -4.503729305395850e-01, 7.610596661310727e-01, -4.095259018147932e-01, -4.993431994401515e-02, 3.057102273429880e-01, -6.265300648456013e+00, 1.877821734161837e+01, 1.128345800309154e+02, 1.796627755074370e+02, -2.136300163015536e+04, -1.869646569536438e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_2x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.971595053472499e-09, 9.662205202222932e-09, 1.276992349747970e-08, 1.894745878968021e-08, 3.222000586371528e-08, 6.206997648445198e-08, 1.301702359988810e-07, 3.787399854615881e-07, 1.341790098066381e-06, 3.435341898122707e-06, 3.062770134917638e-05, 9.407476433804192e-03, 2.264682881728880e-02, 7.595435158758794e-02, 1.124544959828975e-01, -2.239546599170129e+01, -3.568053303135640e+03, -5.285980314054867e+05, -8.321190794050063e+07, -6.847989757514778e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_2x_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.684188813859091e-04, 6.214600527409895e-04, 6.656734160638457e-04, 6.469788455078678e-04, 4.279482411000180e-04, -1.895628679926680e-04, -7.840410130390929e-04, 4.116663472392442e-04, -3.865659632199727e-03, 1.070401785039105e-02, -2.659393938102289e-02, 1.653933149366213e-02, -7.579801191494899e-02, -4.518849849091489e-01, 3.245468379490781e+00, -1.199342148004789e+01, -5.800203869025954e+01, -6.375730109416509e+02, -9.366375514067050e+02, -1.077978393224982e+03]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_x_m06_2x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.805534269600422e-14, 2.294164228381332e-14, 3.244605137468077e-14, 5.365611373870618e-14, 1.114693126297500e-13, 3.208913140346790e-13, 1.437680612083843e-12, 1.161577059165261e-11, 2.163252319698861e-10, 9.763766708998328e-09, 1.743149934644405e-06, 1.718025787000677e-04, 8.741707078413686e-04, 1.018883027274457e-02, 7.130593274201213e-01, 3.276356169458070e+02, 4.680338190362310e+05, 1.658987511537130e+09, 3.026873242926042e+13, 1.930589573341170e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_2x_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.022228215063050e-12, -3.644111281383145e-12, -3.076933889532681e-11, -9.189790168976633e-11, -2.318617169593868e-10, -5.233347099495519e-10, -9.528067368444452e-10, -2.880059295971688e-09, -1.043792967265211e-08, -1.067504401034521e-07, -5.105011067143782e-06, -3.298771468536118e-04, -2.322983591732683e-03, -1.392989348004421e-02, 3.515141664989750e-02, -3.535591502597006e+00, -9.138551979440081e+02, -1.614549793176151e+04, -1.275821749897780e+05, -1.461285472509229e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_2x_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.397699804543477e-05, -1.515566336515621e-05, -1.603105367548491e-05, -1.520704635928379e-05, -9.205929301688898e-06, 6.863030435621480e-06, 2.202360268160086e-05, -6.932345206883872e-06, 1.038268513401256e-04, -2.665179784534803e-04, 9.508392970094894e-04, -1.673921005048970e-04, 4.601215213879820e-02, 3.322864174832436e-01, -2.062626830788024e+00, 9.021820273987670e+00, 7.187399775376872e+01, 6.287489040491888e+02, 1.001307007317088e+03, 1.229777892811754e+03]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
