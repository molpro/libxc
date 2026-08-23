
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_tau_hcth_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tau_hcth", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.490990698136642e-02, -7.579344047065785e-02, -7.709611633874698e-02, -7.902590889531945e-02, -8.188705146595607e-02, -8.608214810583863e-02, -9.197031118423628e-02, -9.913049213433291e-02, -1.035364781935446e-01, -9.142428235616326e-02, -7.023896717027352e-02, -5.390294145455389e-02, -3.590866058296854e-02, -5.211105363570294e-02, -5.561807282403067e-02, -1.229009255630249e-02, 6.315680925179150e-02, 5.026891374738481e-02, 1.400646410834435e-02, 1.707497834528465e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_tau_hcth_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.384992871052412e-03, 5.296130823367429e-03, 6.364525719912442e-03, 7.387535663769363e-03, 7.766878823400712e-03, 5.996408828144217e-03, -1.422487029842688e-03, -2.224463804350591e-02, -7.259085940887831e-02, -1.678520384001172e-01, -2.008666499435679e-01, 5.786452637710317e-04, -5.976463226376258e-03, -5.337526938623344e-03, -6.670503872838363e-02, -1.596028567978588e-01, -3.357979526499633e-02, 5.378800361150142e-02, 1.815675935209962e-02, 2.266715188517585e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tau_hcth_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.158848242460369e-07, -9.972312471316953e-07, -1.123530374805136e-06, -1.325377118664699e-06, -1.659926795827442e-06, -2.237291649343090e-06, -3.259832077487117e-06, -4.920828227073065e-06, -5.146170949715398e-06, 2.699080320227465e-05, 3.269082281473952e-04, -4.887224939422857e-03, -1.275223892956501e-02, -1.987368390467867e-02, 3.053447851612014e-03, 7.782118484586611e-01, 7.430309537325015e+00, 2.135480126836938e+01, 3.372803953306151e+01, 4.200788904884727e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tau_hcth_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.892847647928075e-04, -3.607215231748776e-04, -3.074732779925845e-04, -2.018339921912272e-04, 2.355446806135991e-05, 5.491610900677550e-04, 1.928758352695776e-03, 6.223960071257389e-03, 2.291716723663944e-02, 9.360443174394104e-02, 3.182413618565645e-01, 7.110534628422387e-02, -1.605643591452836e-01, 3.737058402526394e-01, 3.944807202274152e+00, 1.191472996056156e+01, -2.741434348485284e+02, -6.875366067314612e+02, 1.737236409253887e+04, 1.915116049444915e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tau_hcth_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.225591968734410e-09, 4.183646074861700e-09, 3.929371219337755e-09, 2.994210171950586e-09, -2.285857036213809e-10, -1.208947010019946e-08, -6.353664204146522e-08, -3.589937419406133e-07, -2.937937192454217e-06, -3.878233249697862e-05, -8.835634985248789e-04, -5.628727944621419e-03, 5.931977516541823e-02, -1.390843662348910e-01, -3.840127039176509e+00, -7.565234571144796e+01, 1.805160609934325e+04, 2.476042055379473e+06, 4.674582563007883e+08, 4.342793492718239e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tau_hcth_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.163112826246683e-14, 5.939982930369215e-14, 9.522044485479042e-14, 1.774332897889076e-13, 4.023035778751344e-13, 1.182142800098416e-12, 4.922011720335519e-12, 3.308897090887637e-11, 4.315018221892431e-10, 1.271853142855229e-08, 1.509485703832537e-06, 1.430904657697332e-03, -4.258124900994987e-03, 1.047999370376629e-01, 3.552170031082469e+00, -1.334340598431466e+02, -1.975258029997951e+06, -7.690267801601512e+09, -1.711899507729488e+14, -1.226930667136594e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
