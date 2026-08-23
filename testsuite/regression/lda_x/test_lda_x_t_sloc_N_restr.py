
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_t_sloc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_t_sloc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.427805347957756e+00, -5.342093229539470e+00, -5.221313415514878e+00, -5.052647742505885e+00, -4.820141418267515e+00, -4.505514116753764e+00, -4.090856954319176e+00, -3.564537453704733e+00, -2.931907304565541e+00, -2.234335506294611e+00, -1.593536490393578e+00, -1.243735631061012e+00, -1.118084345690314e+00, -9.430171548038541e-01, -6.975969978669133e-01, -4.425760520586522e-01, -2.326925485514432e-01, -9.567933701263805e-02, -2.801117388520600e-02, -5.027636092166514e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_t_sloc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_t_sloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.839034738426773e+00, -6.731037469219732e+00, -6.578854903548747e+00, -6.366336155557415e+00, -6.073378187017069e+00, -5.676947787109742e+00, -5.154479762442161e+00, -4.491317191667964e+00, -3.694203203752581e+00, -2.815262737931210e+00, -2.007855977895908e+00, -1.567106895136875e+00, -1.408786275569795e+00, -1.188201615052856e+00, -8.789722173123108e-01, -5.576458255939017e-01, -2.931926111748184e-01, -1.205559646359239e-01, -3.529407909535956e-02, -6.334821476129808e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_t_sloc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_t_sloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.928985570171574e-03, -1.038914425014528e-02, -1.108783928727638e-02, -1.217405296978728e-02, -1.392083657628103e-02, -1.686947418303852e-02, -2.220449756082810e-02, -3.286037953304437e-02, -5.730296792311476e-02, -1.241733880771084e-01, -3.249414652848630e-01, -6.578818072886016e-01, -8.908251722627042e-01, -1.446371026177791e+00, -3.411017256887627e+00, -1.245464709052383e+01, -7.762346881122305e+01, -9.738832069105358e+02, -3.212865321240123e+04, -4.266096910479464e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
