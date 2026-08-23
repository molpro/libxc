
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_revm11_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.079315702000362e-01, -2.978255015714990e-01, -2.834053659609672e-01, -2.628888242010880e-01, -2.338080258755821e-01, -1.928779973556814e-01, -1.367593177535281e-01, -6.854652142806862e-02, -1.827449297642648e-02, -1.608847305715738e-02, -1.875561223798543e-02, -5.813322373207385e-02, -5.350388104529911e-02, -3.725918372321255e-02, -1.872177221404096e-02, -1.073529343819278e-02, -2.604310167577027e-02, -2.278418202240336e-02, -7.053173857695768e-03, -9.605168726282610e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_revm11_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.959897597042845e-01, -4.970242776118137e-01, -4.983896655714131e-01, -4.999716380981602e-01, -5.007939861640093e-01, -4.959337690983588e-01, -4.650551460849899e-01, -3.491581819051565e-01, -1.161815814634457e-01, -3.495776689765226e-02, -5.897092415914280e-02, -5.476927970993849e-02, -1.045852495848014e-01, -1.188854255067275e-01, -4.005312618531170e-02, -2.913362531706706e-02, -5.350824878077420e-03, -2.519132983816203e-02, -9.015700533170468e-03, -1.263412084788167e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm11_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.534031426732924e-06, -4.542472212670659e-06, -4.530121876538896e-06, -4.456208676936993e-06, -4.218297067295986e-06, -3.564924436553819e-06, -1.916966540954364e-06, 1.784085164895612e-06, 8.229190215542617e-06, 2.071969421674074e-05, 1.805188536566069e-04, 4.696299710539743e-03, 8.600989692057699e-03, 1.449549690522355e-02, 4.246163276757042e-02, 2.259656012405454e-01, 5.748591756865866e-01, 2.847873769476527e-01, 3.605393076878996e-02, 8.999509242008996e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm11_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.365539630985961e-02, 1.339619245607453e-02, 1.303031566739701e-02, 1.252069553657504e-02, 1.182145430479940e-02, 1.085105033533094e-02, 9.316957582277224e-03, 6.203749216851338e-03, 8.633302751724982e-04, -8.461196510748020e-04, -8.508649374016921e-04, -5.683292381674104e-03, 9.135258783166775e-03, 2.343350904841790e-02, -1.501814087595740e-02, -1.630494336785711e-02, -2.620693741379053e-02, -2.801165091570378e-03, -4.467382255253137e-05, -8.478173045198157e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm11_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.508679233456943e-03, 4.684703007718173e-03, 4.925442830945590e-03, 5.219142367761029e-03, 5.424291627303259e-03, 4.820193633536679e-03, 3.889632714046595e-04, -1.662750670783841e-02, -4.019831885597481e-02, 8.597062850629491e-03, -8.441920744207253e-02, 4.817445681975651e-02, 5.506819295606162e-02, -7.221706033317083e-01, -7.851688751235809e-01, -1.021497196364906e+01, 1.946819120888972e+01, 7.382916351374072e+01, -8.342929470417614e+03, -1.024580931630840e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm11_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.386089610344835e-08, -9.296951689058067e-08, -1.074363401751335e-07, -1.312142981474818e-07, -1.717591058204130e-07, -2.421774983344584e-07, -3.534020814448326e-07, -3.997255778152343e-07, 6.514860310914028e-07, 7.510557167172196e-06, 1.784145435100061e-04, -7.915321594096773e-03, -6.304300355820647e-02, -1.128315994446109e-01, 8.336361072068867e-01, 4.428221263869228e+01, 3.107528904867356e+03, 5.588840412944420e+04, 8.243808445272396e+05, 1.542000246833741e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revm11_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.115958737388670e-05, 6.398038188298066e-05, 6.814836878245610e-05, 7.474432744024610e-05, 8.719232824765921e-05, 1.191652087827873e-04, 2.267188819631570e-04, 5.683160793274497e-04, 8.893496433807310e-04, -7.048884576550211e-04, 5.297958771294988e-04, 3.269758388901300e-03, 2.932845852092245e-02, 5.510674774664606e-01, -7.463983949529515e-02, 1.312655686060697e+00, -4.970813453076311e+01, -2.428496225912364e+02, -4.607729498348202e+02, -6.548421619596006e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revm11_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.260394503820855e-13, 7.146803407277368e-13, 8.600302288498225e-13, 1.108586876993264e-12, 1.548567354477603e-12, 2.292248364574889e-12, 2.767367415328844e-12, -8.308596905044316e-12, -2.102404773891548e-10, -6.080254096091536e-09, -1.410589915397319e-06, -1.022312014487403e-03, -6.833463058920399e-03, -4.277302725347912e-02, -1.773521548794809e+00, -5.488432806181689e+02, -2.901728569868532e+05, -1.578222753395357e+08, -2.747935082905993e+11, -3.942800666423953e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revm11_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.616797440303106e-09, 1.805241964634415e-09, 2.108054078168807e-09, 2.614740454952850e-09, 3.504052472777127e-09, 5.132297440610561e-09, 8.063470243225264e-09, 1.173039892272016e-08, 5.363764805716263e-09, 4.675496291896028e-08, 5.191443261244257e-06, 7.971149082167564e-04, 2.045873851105554e-02, 7.337357845103443e-02, 3.442918504361710e-02, 1.827449000429265e+01, 1.720757947125966e+02, 3.476918992115415e+02, 2.589357246522574e+02, 6.667762970591573e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revm11_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.033037258651534e-06, -6.326606351396606e-06, -6.757703850781135e-06, -7.400568932205293e-06, -8.397940347343576e-06, -1.011588902265740e-05, -1.373203309996281e-05, -2.189075467585913e-05, -2.456357973272986e-05, 1.765167848457406e-05, -6.634947313678671e-05, -6.595690998253168e-04, -3.688206436367503e-02, -4.651123651692661e-01, 9.779472829935944e-02, -2.651558048019023e+00, 4.610405890555495e+01, 2.438896672444766e+02, 5.003965285409794e+02, 7.515349871675492e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
