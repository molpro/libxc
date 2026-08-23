
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hapbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hapbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.525713195168997e+00, -3.459581539157906e+00, -3.366979516741423e+00, -3.238838340913042e+00, -3.064516246311134e+00, -2.833111130534899e+00, -2.536522667454919e+00, -2.174832315872031e+00, -1.762729104562383e+00, -1.328877027117119e+00, -8.952257436742345e-01, -5.776311922656810e-01, -5.038939356862280e-01, -4.164321107416757e-01, -3.009911565803378e-01, -1.909698586370116e-01, -9.804591795521808e-02, -3.356519601702110e-02, -7.016169062115520e-03, -7.761302374022589e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hapbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hapbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.413605964169100e+00, -4.320983185538234e+00, -4.191096110629380e+00, -4.010974367044487e+00, -3.765171306629703e+00, -3.437424549560506e+00, -3.014921776439661e+00, -2.497131397049219e+00, -1.912207450004845e+00, -1.339806276246338e+00, -8.846664780185777e-01, -7.260065668481120e-01, -6.537009969585569e-01, -5.223753442665520e-01, -3.469445673224270e-01, -1.962015172102319e-01, -1.138299695286641e-01, -4.387388035848496e-02, -9.346041134588900e-03, -1.034827713835286e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hapbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hapbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.869748716567706e-06, -3.111385447974366e-06, -3.493353465935264e-06, -4.122174631391853e-06, -5.218693768581391e-06, -7.291687588466786e-06, -1.167371273688894e-05, -2.243103348672972e-05, -5.431468902263742e-05, -1.723205060320397e-04, -8.159107025083943e-04, -2.633125397874880e-03, -2.039819013920949e-03, -8.704383156493446e-03, -4.641348057824125e-02, -3.062552632819640e-01, -1.140999328436087e+00, -1.981148113251521e+00, -2.409739489962397e+00, -2.664650466240261e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hapbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hapbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.025252670378940e-02, -1.073457082233406e-02, -1.146707223542291e-02, -1.260655156122267e-02, -1.443823312346530e-02, -1.751728222360029e-02, -2.299708188519417e-02, -3.333860187519257e-02, -5.291882071778147e-02, -7.962433219304040e-02, -1.423576198750098e-01, -4.760423065279034e-01, -5.362354939574085e-01, -1.003017543450341e+00, -2.886265079119594e+00, -2.606139104356362e+00, 1.143892529885567e+01, -3.492925010505407e+02, -1.078379262481818e+04, -8.933184707074827e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hapbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hapbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.422678224916041e-08, 2.762706265262952e-08, 3.333750632403053e-08, 4.358429697020405e-08, 6.376552051401430e-08, 1.089703303386747e-07, 2.291119881967890e-07, 6.206461372684332e-07, 2.083614496197900e-06, 2.717487796679120e-06, -9.000442417865708e-05, 9.708969097725006e-03, 1.829555842332002e-02, 1.025972059239005e-01, 1.323019352895964e+00, -1.320671443672619e+01, -3.366210246592120e+03, -2.365866975497085e+05, -3.366946183034618e+07, -2.760617082831406e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hapbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hapbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.281341985955620e-14, -4.898850843054660e-14, -5.877294704923324e-14, -7.400097690258023e-14, -9.289685194305511e-14, -6.754195236650148e-14, 5.815998870250431e-13, 1.076166294473107e-11, 2.639146647813438e-10, 1.422952875506592e-08, 2.002244884467656e-06, -4.243171212090984e-04, -5.403279407746008e-03, -2.343293035810649e-02, -5.244463307395444e-01, 2.459552275895946e+02, 3.316213706090779e+05, 7.176211564427663e+08, 1.222948605010221e+13, 7.782619290414966e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
