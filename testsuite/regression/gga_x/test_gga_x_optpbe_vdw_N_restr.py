
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_optpbe_vdw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optpbe_vdw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.277247127025053e+00, -4.195164826149055e+00, -4.080245974889354e+00, -3.921262615549641e+00, -3.705070243730788e+00, -3.418285053836967e+00, -3.051214509141641e+00, -2.604935554363667e+00, -2.100518128679315e+00, -1.579902254072084e+00, -1.064289607055273e+00, -6.582514770363548e-01, -5.601671207755937e-01, -4.668255866431879e-01, -3.429166361505265e-01, -2.274125661632095e-01, -1.291875566253467e-01, -4.711789210196941e-02, -9.951453074023947e-03, -1.101396317139014e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_optpbe_vdw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optpbe_vdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.406086776314369e+00, -5.291723813283888e+00, -5.131351644425102e+00, -4.908946792799682e+00, -4.605390151096518e+00, -4.200410757814478e+00, -3.677490217520597e+00, -3.033651191853301e+00, -2.297510000564842e+00, -1.562977259865489e+00, -1.000960928721820e+00, -8.043539230921672e-01, -7.181743699201723e-01, -5.584484884167811e-01, -3.578789847314039e-01, -1.963019653604314e-01, -1.303184645925567e-01, -6.028024198977565e-02, -1.324229577186897e-02, -1.468490940724030e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optpbe_vdw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optpbe_vdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.185780771657598e-06, -3.449773897819687e-06, -3.867292661640089e-06, -4.555379393290448e-06, -5.758009216665102e-06, -8.042935926603429e-06, -1.292564833395611e-05, -2.520142356066230e-05, -6.348837389283397e-05, -2.187317528528310e-04, -1.113566389261273e-03, -5.883003760543045e-03, -1.066800032723405e-02, -2.377225375106445e-02, -9.360721492687139e-02, -5.725050387587617e-01, -2.842513056569612e+00, -5.731732781860742e+00, -7.162895006830257e+00, -7.925031335440316e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optpbe_vdw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optpbe_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.204781415433362e-02, -1.260773044108226e-02, -1.345987869186032e-02, -1.478919182261590e-02, -1.693747960762467e-02, -2.058816166034266e-02, -2.724009631660474e-02, -4.049892086629344e-02, -6.921403338157164e-02, -1.275115853766690e-01, -2.587950057143738e-01, -5.640605022988124e-01, -6.684276625848876e-01, -1.185940212066879e+00, -2.709522365697153e+00, -1.569915576397434e+00, 6.808299025054568e+01, -3.262318389207699e+02, -1.508722086490859e+04, -1.267476655632663e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optpbe_vdw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optpbe_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.130388271773740e-08, 2.441851898565879e-08, 2.969375529794977e-08, 3.928337183169823e-08, 5.856149181659791e-08, 1.032272714191417e-07, 2.292094955585757e-07, 6.904183514014633e-07, 2.968149762077539e-06, 1.574568913804827e-05, 1.361416687678463e-04, 1.052359240294418e-02, 3.202935954778619e-02, 1.168143906683023e-01, 8.753491064632418e-01, -2.169192809096388e+01, -7.613852748539925e+03, -6.716781698702100e+05, -1.000405883386454e+08, -8.210482699902672e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optpbe_vdw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optpbe_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.591079708119129e-14, 3.299952973072313e-14, 4.669972301232318e-14, 7.685367850421061e-14, 1.569018060827674e-13, 4.352962629871582e-13, 1.863292233754627e-12, 1.462693378659864e-11, 2.627115358195427e-10, 1.357294347219499e-08, 2.098885789677354e-06, 1.718533666588030e-04, 9.526454709650723e-04, 1.173375115017448e-02, 9.305061429149067e-01, 4.672784117548522e+02, 7.777561885504152e+05, 2.048609203337862e+09, 3.634193528966880e+13, 2.314664202875832e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
