
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_mpbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.304483385131909e+00, -4.222825275687820e+00, -4.108519607269377e+00, -3.950424055955146e+00, -3.735518668221398e+00, -3.450595886488618e+00, -3.086183639700813e+00, -2.643478506188743e+00, -2.142725996066967e+00, -1.621029543093977e+00, -1.093402697818028e+00, -6.648615810081391e-01, -5.628192553073755e-01, -4.725268688757528e-01, -3.509104144506554e-01, -2.325964130604084e-01, -1.233865447487036e-01, -4.181973393286289e-02, -8.702430211530903e-03, -9.624266145403960e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_mpbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.375264379317530e+00, -5.260641013628556e+00, -5.099917357434320e+00, -4.877059282671612e+00, -4.572974476337020e+00, -4.167544768523809e+00, -3.644806722713469e+00, -3.003622725057784e+00, -2.278250830825516e+00, -1.572792066368586e+00, -1.023199534226411e+00, -7.977855877540159e-01, -7.150254368989973e-01, -5.533072107196966e-01, -3.565339796602228e-01, -2.119736762559135e-01, -1.421015319196710e-01, -5.511560924594976e-02, -1.159803715999623e-02, -1.283228177136301e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mpbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.906152264955237e-06, -4.226565180658076e-06, -4.732587021262684e-06, -5.564703793838303e-06, -7.014084589161322e-06, -9.752516473083772e-06, -1.554880929523148e-05, -2.986906259933118e-05, -7.301909955800542e-05, -2.368487326668782e-04, -1.157723307154568e-03, -7.117288483814073e-03, -1.315159678068055e-02, -2.850659085611897e-02, -1.049175275216230e-01, -5.255976322384034e-01, -1.519419153821427e+00, -1.451258732466845e+00, -1.416639574124891e+00, -1.545360517110975e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mpbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.233339830671686e-02, -1.290838964466454e-02, -1.378260967059886e-02, -1.514393488945364e-02, -1.733657010505070e-02, -2.103714788794425e-02, -2.767763409361534e-02, -4.041634689354130e-02, -6.504484099836157e-02, -9.635027276006797e-02, -1.473495182266269e-01, -5.756222160164929e-01, -6.826790705104706e-01, -1.201303914751968e+00, -2.362132680832609e+00, 3.257551448371574e+00, 3.508086047396611e+01, -4.837004489763046e+02, -1.346233619727636e+04, -1.107837173815132e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mpbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.498371070132237e-08, 2.855791484171459e-08, 3.458334185377985e-08, 4.545772484270603e-08, 6.706590119232719e-08, 1.161525125094901e-07, 2.496513933245687e-07, 7.018321238743562e-07, 2.490430519693503e-06, 2.982834148363634e-06, -1.729770782445894e-04, 1.173501374167649e-02, 3.827231552765277e-02, 1.255033337676916e-01, 5.543227234098116e-01, -4.994484911423874e+01, -5.647784613374914e+03, -1.963106229901050e+05, -1.997319435068348e+07, -1.601220909967751e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_mpbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_mpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.397411353064340e-14, 5.596242096761715e-14, 7.910623105198517e-14, 1.299590567869086e-13, 2.645945578612528e-13, 7.307822845718634e-13, 3.103849254627045e-12, 2.401257346912805e-11, 4.186445471706447e-10, 2.035782015559473e-08, 3.019814828226889e-06, 2.878700306056852e-04, 1.625346347681279e-03, 1.948558556586684e-02, 1.445086653073261e+00, 5.897977807726626e+02, 5.227031943760164e+05, 5.778389377593954e+08, 7.238619298049640e+12, 4.513953940548616e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
