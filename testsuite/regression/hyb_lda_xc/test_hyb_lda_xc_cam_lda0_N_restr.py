
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_xc_cam_lda0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_cam_lda0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.194092692341194e+00, -3.130448931916835e+00, -3.041236373406339e+00, -2.917588638513672e+00, -2.748968650639318e+00, -2.524282221939901e+00, -2.234590373567363e+00, -1.878152561319198e+00, -1.468059183881240e+00, -1.042368354433835e+00, -6.805439578466685e-01, -4.974328545965846e-01, -4.346194321438999e-01, -3.501111321894256e-01, -2.386298162824182e-01, -1.346609985803017e-01, -6.309159974220299e-02, -2.354519883810606e-02, -5.790984493464973e-03, -7.244918108066187e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_xc_cam_lda0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_cam_lda0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.244231308803283e+00, -4.159548883463605e+00, -4.040850587249148e+00, -3.876346431638480e+00, -3.652031199490123e+00, -3.353172801924203e+00, -2.967931593001521e+00, -2.494083337248594e+00, -1.949178180021102e+00, -1.383973282394767e+00, -9.040145622171826e-01, -6.612431128232639e-01, -5.779475230652686e-01, -4.658060098847832e-01, -3.174700075582931e-01, -1.778679868079455e-01, -8.161434492997208e-02, -3.034920170127556e-02, -7.558704153358803e-03, -9.578337472933647e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_xc_cam_lda0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_cam_lda0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.802404979104120e-03, -8.128523470020087e-03, -8.621102348619378e-03, -9.381128837904540e-03, -1.059020063419462e-02, -1.259973310391706e-02, -1.615575787408675e-02, -2.303681508428971e-02, -3.812694317562685e-02, -7.690691518148240e-02, -1.844326469616859e-01, -3.506924500192585e-01, -4.623355526479784e-01, -7.192823878196025e-01, -1.570596525188728e+00, -5.018405928946923e+00, -2.489138071696635e+01, -2.706107601375224e+02, -8.009336480210226e+03, -7.958657361142901e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
