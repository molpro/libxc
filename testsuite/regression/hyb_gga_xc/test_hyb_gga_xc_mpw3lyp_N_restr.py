
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mpw3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.441550530598669e+00, -3.377244574084085e+00, -3.287182880529360e+00, -3.162521120576750e+00, -2.992850984138681e+00, -2.767432255464592e+00, -2.478073917399223e+00, -2.124198479529091e+00, -1.719097410809764e+00, -1.291106697906017e+00, -8.708763883180245e-01, -5.670499986834195e-01, -4.872770028988233e-01, -4.092131242818878e-01, -2.986815592438336e-01, -1.847172690636221e-01, -9.590313879568059e-02, -3.260413889423824e-02, -2.647431740226924e-03, -3.019281999285170e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mpw3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.296637928423497e+00, -4.207855461428874e+00, -4.083437142169194e+00, -3.911067912483860e+00, -3.676178500923356e+00, -3.363616397103272e+00, -2.961757310560066e+00, -2.470493812745289e+00, -1.914503094423248e+00, -1.361047225885053e+00, -9.127155917180287e-01, -6.904817835737482e-01, -6.159493965424299e-01, -4.941057194231261e-01, -3.438725891969782e-01, -2.147560104621337e-01, -1.292880402844607e-01, -7.437948750528564e-02, -4.573803568938653e-03, -3.981176360871597e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.906296840748462e-06, -3.131728469208929e-06, -3.485648698751897e-06, -4.062650375996951e-06, -5.055091220432037e-06, -6.895963609112320e-06, -1.068967131364602e-05, -1.971817056663265e-05, -4.569676342062096e-05, -1.405576689418283e-04, -6.433074157760366e-04, -4.454763800600865e-03, -8.961502629259420e-03, -1.634229749600564e-02, -4.698135723128539e-02, -1.489718376099478e-01, 9.286483510024315e-01, 7.477834358000894e+01, 3.113801557155363e+02, 5.834318669097332e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.197145698416910e-03, -9.602286813046666e-03, -1.021514359955780e-02, -1.116241942858253e-02, -1.267172167096901e-02, -1.517969542909102e-02, -1.958737984912533e-02, -2.787602875394908e-02, -4.432958655408435e-02, -7.453376391034786e-02, -1.344982194240312e-01, -4.036007199687920e-01, -5.191721646458396e-01, -8.135716773040134e-01, -1.405161909178807e+00, 7.322179694373405e-01, 8.784446272513682e+01, -1.182413278991200e+03, -1.954510217633436e+04, -3.430493321225243e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.431386479086325e-08, 1.621066220356513e-08, 1.936793009605410e-08, 2.496141720701957e-08, 3.577832133690071e-08, 5.938775136144078e-08, 1.199349006101412e-07, 3.084702696732916e-07, 9.762836441682015e-07, 8.483639058902113e-07, -1.033812784409979e-04, 4.486067400143093e-03, 1.906739823603533e-02, 3.662127750977905e-02, -1.578461339419228e-01, -3.633966978500754e+01, -9.813914564229226e+03, 1.053243809550181e+06, 3.997478439375412e+09, 5.515562134143148e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.758374520229132e-14, 9.677924759892988e-14, 1.329062954409942e-13, 2.093944760361582e-13, 4.011762655091826e-13, 1.014068959458192e-12, 3.785121340762930e-12, 2.430315175470606e-11, 3.283501016328390e-10, 1.208000191578349e-08, 1.622269967582973e-06, 3.839430611848178e-04, 3.385128601498229e-03, 2.272508981058026e-02, 9.798276405970276e-01, 2.896213759417041e+02, 7.157881917419138e+05, -8.605992973851612e+09, -1.484151860592416e+15, -1.592201185674763e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
