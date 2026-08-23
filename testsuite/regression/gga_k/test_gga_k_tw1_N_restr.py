
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_tw1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.449280770071296e+01, 9.083254739366792e+01, 8.582717258406628e+01, 7.913164578569240e+01, 7.045332545271687e+01, 5.969933133808116e+01, 4.719488092593994e+01, 3.389647166016355e+01, 2.139048873180962e+01, 1.140514129962865e+01, 4.979265142449955e+00, 2.208855633234332e+00, 1.629260480686886e+00, 1.101298939495490e+00, 5.557050432973237e-01, 2.038125087835830e-01, 4.720738143168207e-02, 5.228830894385228e-03, 2.266242438712376e-04, 2.772062282083675e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_tw1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.491525349060837e+02, 1.430970906231816e+02, 1.348214687599281e+02, 1.237620059590618e+02, 1.094491915839628e+02, 9.175832263459105e+01, 7.128402304253684e+01, 4.972055375263871e+01, 2.991142317583921e+01, 1.501676035261693e+01, 6.416848499679621e+00, 3.377719831269407e+00, 2.607995512694312e+00, 1.652535260713689e+00, 7.535194531349850e-01, 2.593650623631391e-01, 6.908428593615910e-02, 8.555708509510368e-03, 3.773779099717018e-04, 4.620052036835623e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.943807750235167e-05, 9.475657757441084e-05, 1.029331768545909e-04, 1.158667288823274e-04, 1.371623161483991e-04, 1.742412269906133e-04, 2.439002098854320e-04, 3.883188533458161e-04, 7.241623654742758e-04, 1.606330019684029e-03, 5.012415832523333e-03, 2.437034514027044e-02, 3.991468866699655e-02, 6.797529990397784e-02, 1.626866474885278e-01, 4.301089574076924e-01, 6.504165101743730e-01, 3.583093812736392e-01, 8.962033494357537e-02, 1.094527562104891e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.909439645258677e-01, 6.036488072929461e-01, 6.223546323619763e-01, 6.501586523803187e-01, 6.920133964792030e-01, 7.560140596423602e-01, 8.553642923707316e-01, 1.009189130842695e+00, 1.226263814157154e+00, 1.419572922231573e+00, 1.823152544370797e+00, 3.938896160944929e+00, 4.445327101974151e+00, 5.605779366986607e+00, 7.173827765242769e+00, 4.630682334412246e+00, 1.451251026766319e+01, 1.564861556063256e+02, 8.758645742922497e+02, 7.977135442453609e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.831603885437825e-07, -4.266207973370216e-07, -4.972420593400738e-07, -6.179337263101078e-07, -8.388113042930582e-07, -1.280122002105020e-06, -2.248634276481983e-06, -4.381538049052825e-06, -4.616397017594509e-06, 1.121723630162264e-04, 2.236214560716430e-03, -2.431582490049809e-02, -8.054195733428009e-02, -1.663860483824489e-01, 3.053441210028878e-01, 5.473928495980510e+01, 2.195391224455539e+03, 4.671833076712572e+04, 1.357685799905169e+06, 1.228466973491956e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.247359980768361e-12, -1.553205261099171e-12, -2.127708040624142e-12, -3.340847121535360e-12, -6.371832856872176e-12, -1.601156390117121e-11, -5.928472482520827e-11, -3.752607915696979e-10, -4.868691897229705e-09, -1.547958333274768e-07, -1.426584587459924e-05, -1.206337638826610e-03, -6.142163735954313e-03, -5.642095287504637e-02, -2.575727027280822e+00, -4.909592789330861e+02, -1.937211455036020e+05, -1.303605805533668e+08, -4.550850755404459e+11, -3.196821749326052e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
