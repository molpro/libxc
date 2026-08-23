
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbe50_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe50", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.215902266258133e+00, -2.174001897459456e+00, -2.115310514723196e+00, -2.034054393196556e+00, -1.923434426696089e+00, -1.776436841811073e+00, -1.587757613010624e+00, -1.357279631832781e+00, -1.094615534315274e+00, -8.201054837736328e-01, -5.526296528569172e-01, -3.752704711473507e-01, -3.338809545778665e-01, -2.727170761813841e-01, -1.939404991831056e-01, -1.195209663025156e-01, -6.075721034198932e-02, -2.094250423046526e-02, -4.384725294044279e-03, -4.850808536863047e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbe50_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe50", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.821755153806782e+00, -2.763574520833208e+00, -2.681957466402119e+00, -2.568710883251778e+00, -2.414025918169110e+00, -2.207440465592646e+00, -1.940321663081630e+00, -1.610953645967788e+00, -1.234296240131360e+00, -8.597913445239560e-01, -5.697657345820173e-01, -4.883277459342353e-01, -4.403106337410838e-01, -3.565612897228045e-01, -2.408282976403594e-01, -1.321026467656767e-01, -7.022195684716094e-02, -2.728953459085299e-02, -5.839763384882190e-03, -6.467651426546107e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe50_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe50", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.207183494705374e-06, -1.315914511196193e-06, -1.488733185135341e-06, -1.775477111273127e-06, -2.281145930828143e-06, -3.252706161451123e-06, -5.355049200448972e-06, -1.069488230926215e-05, -2.730078235231816e-05, -9.193326460038806e-05, -4.346475900333912e-04, -1.384358274087241e-05, 2.946243124881687e-03, 1.034737938815762e-03, -1.141337187108434e-02, -1.372416395325346e-01, -7.239943799382715e-01, -1.426152243370905e+00, -1.779666339407995e+00, -1.972459661490282e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe50_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.403887525374999e-03, -6.709091552857199e-03, -7.173964610611582e-03, -7.899856883316224e-03, -9.074108413606842e-03, -1.107026182834836e-02, -1.469944474263002e-02, -2.185638801653596e-02, -3.677104181389223e-02, -6.360037389134833e-02, -1.357285639337977e-01, -3.076628849701619e-01, -3.300755125079008e-01, -6.592560434301196e-01, -1.996816110645844e+00, -4.919269895567567e+00, 3.873318774411707e+00, -2.082808273686912e+02, -6.724195735009113e+03, -5.583071209964658e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe50_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.471858510252590e-08, 1.683523053519511e-08, 2.040805199778122e-08, 2.686977351565069e-08, 3.975775537158422e-08, 6.924608032679963e-08, 1.507013273449524e-07, 4.378486555036096e-07, 1.744680261780727e-06, 7.358642107845475e-06, 7.244647899028437e-05, 6.330645436824178e-03, 5.681557094132228e-03, 6.969104003269511e-02, 9.716058904334768e-01, 9.380528564152556e+00, -1.834351284378510e+03, -1.671262247519389e+05, -2.482836526637856e+07, -2.043431449794926e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe50_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.332951402020989e-14, -8.772290237036345e-14, -1.133060197552100e-13, -1.630206115695004e-13, -2.722701852580029e-13, -5.543878796029907e-13, -1.423570277727054e-12, -3.877008433263870e-12, 3.683486738300705e-11, 5.014744732471773e-09, 7.162365665759592e-07, -5.881671754718805e-04, -6.548094737079263e-03, -3.284474925010533e-02, -8.258278628728463e-01, 2.063772827631729e+01, 1.885656912839789e+05, 5.089755820869027e+08, 9.021192499438244e+12, 5.760802664781951e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
