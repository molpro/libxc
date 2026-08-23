
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_lambda_oc2_n_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_oc2_n", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.301324727758172e+00, -4.219492963349321e+00, -4.104922401075801e+00, -3.946412418548338e+00, -3.730835029064819e+00, -3.444767105933610e+00, -3.078270069578545e+00, -2.631461577460314e+00, -2.122206591538474e+00, -1.585775384539396e+00, -1.060170064524630e+00, -6.635824621489120e-01, -5.625956926113896e-01, -4.711331043440440e-01, -3.457946409887225e-01, -2.198330674141176e-01, -1.099651961319761e-01, -3.702146609617980e-02, -7.718234987313763e-03, -8.536807561292082e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_lambda_oc2_n_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_oc2_n", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.387093222899485e+00, -5.273087416429913e+00, -5.113300234215324e+00, -4.891894128204460e+00, -4.590130613313290e+00, -4.188566265772657e+00, -3.672589569246580e+00, -3.043744965439821e+00, -2.340093254566030e+00, -1.658816074472009e+00, -1.093023048394395e+00, -8.023634515368923e-01, -7.158783173142380e-01, -5.581485348266266e-01, -3.706368041342638e-01, -2.278552311143532e-01, -1.317733786257091e-01, -4.865296465822214e-02, -1.028397356620931e-02, -1.138231048257086e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_oc2_n_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_oc2_n", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.734041995411379e-06, -4.033525903355480e-06, -4.505048226347585e-06, -5.276840855326423e-06, -6.611510046309198e-06, -9.104377138222981e-06, -1.428089560888809e-05, -2.665036065536668e-05, -6.176416693894124e-05, -1.833167645621817e-04, -8.537340429633817e-04, -6.613092216725105e-03, -1.272400035996280e-02, -2.601749409303490e-02, -8.520179533313826e-02, -3.494288983439467e-01, -1.006459268609083e+00, -1.597625180118758e+00, -1.907617644397866e+00, -2.105874031955500e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_oc2_n_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_oc2_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.203168855523672e-02, -1.257210846123240e-02, -1.338993398838712e-02, -1.465419001054657e-02, -1.666664955627579e-02, -1.999608168992527e-02, -2.575866190576544e-02, -3.604765161916029e-02, -5.291762642846168e-02, -6.450809927617721e-02, -8.408355735475141e-02, -5.439422799230844e-01, -6.729611696323348e-01, -1.108271715802634e+00, -1.771391117673579e+00, 1.948845879016304e+00, 3.464726920389130e+00, -4.180815566763253e+02, -1.190409063402319e+04, -9.826221673725253e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_oc2_n_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_oc2_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.151018503364075e-08, 2.443287255643074e-08, 2.930649142726649e-08, 3.795420534978134e-08, 5.467374295810251e-08, 9.091521296828054e-08, 1.811059536042385e-07, 4.298055745489318e-07, 8.051167259360425e-07, -1.178815704020564e-05, -3.800682299310776e-04, 8.995207194019519e-03, 3.440513322655583e-02, 8.813252528270347e-02, -6.842368215258969e-02, -4.537209860623026e+01, -3.266904993484458e+03, -1.933516758523156e+05, -2.668303967706046e+07, -2.181767772998562e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_oc2_n_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_oc2_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.749527938929039e-14, 8.564603750679128e-14, 1.205387984345221e-13, 1.967146472809777e-13, 3.963742886160451e-13, 1.076547295495878e-12, 4.444571047357775e-12, 3.268411983489868e-11, 5.183248326212286e-10, 2.142924824329941e-08, 2.899435920994479e-06, 4.206199250225202e-04, 2.546916510136125e-03, 2.759699594678974e-02, 1.662168772987363e+00, 4.572657069978609e+02, 3.140934056238088e+05, 5.848347333296751e+08, 9.689531780542170e+12, 6.150716636300738e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
