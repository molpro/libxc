
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_th_fl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_th_fl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.896328581377952e+00, -4.813226088746502e+00, -4.694679436860497e+00, -4.526569226253570e+00, -4.290639128965560e+00, -3.965460067507064e+00, -3.530850045313032e+00, -2.978800241347313e+00, -2.332671981322374e+00, -1.669578966903901e+00, -1.132041241485245e+00, -8.750821497100337e-01, -7.895472005925923e-01, -6.762302853087582e-01, -5.277289158579678e-01, -3.813839382761520e-01, -2.551736005169370e-01, -1.511738999449832e-01, -7.254256598505075e-02, -2.501616125281822e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_th_fl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_th_fl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.257229220260164e+00, -6.166981713861203e+00, -6.036128461847807e+00, -5.846635337882139e+00, -5.573706008735174e+00, -5.185854045450023e+00, -4.649593532491324e+00, -3.944160892383375e+00, -3.090912749859065e+00, -2.191764207537682e+00, -1.452553844112664e+00, -1.099824116716266e+00, -9.833122485145763e-01, -8.303268965245206e-01, -6.337354085549840e-01, -4.473165618335069e-01, -2.948814982366665e-01, -1.742914049093849e-01, -8.401572957886136e-02, -2.910517940351652e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_th_fl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_th_fl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.193999431603195e-03, -8.788077498271226e-03, -9.685388439420540e-03, -1.106908346860272e-02, -1.326595704073067e-02, -1.689917763012027e-02, -2.325842296518005e-02, -3.529421944048928e-02, -6.061819647818129e-02, -1.213205895142289e-01, -2.746653639013255e-01, -4.956835333761205e-01, -6.398612707170271e-01, -9.674579961072477e-01, -2.061609679596424e+00, -7.024875183809635e+00, -4.758101200067462e+01, -8.247662025627635e+02, -4.623846750881266e+04, -1.228958912541601e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
