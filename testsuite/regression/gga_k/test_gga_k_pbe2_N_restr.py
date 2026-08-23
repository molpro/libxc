
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_pbe2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.196097468664927e+02, 1.158555236950276e+02, 1.107110034283173e+02, 1.038077638499651e+02, 9.481648028326384e+01, 8.358518987574207e+01, 7.033737601871394e+01, 5.582764149889752e+01, 4.116205060244284e+01, 2.691637265884956e+01, 1.289151683000418e+01, 3.150570890615155e+00, 1.949228851326999e+00, 1.679335171088341e+00, 1.182310495880104e+00, 6.297375708427385e-01, 1.878044257419913e-01, 2.246195942434573e-02, 9.831331852644962e-04, 1.203131782950538e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_pbe2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.270671294738269e+02, 1.212083544540546e+02, 1.132243000164313e+02, 1.026018224031183e+02, 8.895339626518462e+01, 7.229221972894730e+01, 5.345590114226740e+01, 3.458331146257107e+01, 1.925278620220955e+01, 1.076319250773725e+01, 5.473061095097427e+00, 2.622355458941799e+00, 2.316295439233712e+00, 1.217267273373633e+00, 4.903301710223885e-01, 3.727222991979113e-01, 2.340016380458511e-01, 3.614159085695139e-02, 1.635878880519112e-03, 2.005177550087254e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.755767934073045e-04, 8.216041148566154e-04, 8.923496535065970e-04, 1.004214081368561e-03, 1.188302865532070e-03, 1.508549844522436e-03, 2.109306557606721e-03, 3.351586461790021e-03, 6.226769995859418e-03, 1.372102980686255e-02, 4.264927644544725e-02, 2.109268341770874e-01, 3.464045421160719e-01, 5.876129514473210e-01, 1.394722711291043e+00, 3.624330129777130e+00, 5.355740871594613e+00, 2.918147341646602e+00, 7.287036803357954e-01, 8.898908189276485e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.796060867715491e-01, 7.999679017263240e-01, 8.298588315209652e-01, 8.739687828629178e-01, 9.391986179301232e-01, 1.034448761815445e+00, 1.163714252240986e+00, 1.278551271529662e+00, 1.005686951297296e+00, -1.367890244221723e+00, -5.266387833353368e+00, 5.393984359009317e+00, 5.624252441683130e+00, 7.560760712284760e+00, 1.432730335038254e+00, -6.740004870374800e+01, -1.100327799222157e+02, 5.795906720357898e+02, 3.777814898627521e+03, 3.461986004551852e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.289619442288448e-06, -3.660569534533516e-06, -4.262644431892856e-06, -5.289688245273236e-06, -7.163490494072369e-06, -1.088644433076808e-05, -1.896064737112757e-05, -3.610360015402984e-05, -3.027419723478078e-05, 1.040284582663264e-03, 2.007574218502873e-02, -2.063219754626728e-01, -6.942343681592789e-01, -1.397452504907345e+00, 3.247306079261784e+00, 4.752094607708655e+02, 1.822754180613732e+04, 3.808852401963716e+05, 1.103989929796484e+07, 9.987890775946497e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.117096121134206e-11, -1.390765547292121e-11, -1.904700827696387e-11, -2.989531648080215e-11, -5.698336455253245e-11, -1.430513894220373e-10, -5.287852268741260e-10, -3.337116194173201e-09, -4.305244432229291e-08, -1.355290444828443e-06, -1.241765533340535e-04, -1.077256992943272e-02, -5.507352176658240e-02, -5.029165978270338e-01, -2.267508854991318e+01, -4.211769328255678e+03, -1.605329695319339e+06, -1.062588358599068e+09, -3.700448848308504e+12, -2.599133990228347e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
