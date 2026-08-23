
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b97_1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.475570520698585e+00, -3.409926117576478e+00, -3.317982629488436e+00, -3.190713484590969e+00, -3.017526312884280e+00, -2.787610684472236e+00, -2.493158272596877e+00, -2.135274419959492e+00, -1.731684176973131e+00, -1.315701261989371e+00, -8.942788896832119e-01, -5.705662178591784e-01, -4.961730277806547e-01, -4.111032791206152e-01, -3.002715294930406e-01, -1.902970487788321e-01, -9.085904831071073e-02, -2.517862570192076e-02, -3.916370852526234e-03, -3.465702520169008e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b97_1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.395798937816751e+00, -4.305057780436272e+00, -4.177583455079568e+00, -4.000335493308014e+00, -3.757471438584169e+00, -3.431622370912601e+00, -3.007514495234252e+00, -2.480020997126604e+00, -1.871122558956442e+00, -1.265580224903208e+00, -8.287683222084657e-01, -7.139990448203238e-01, -6.381781644867314e-01, -5.090256731101104e-01, -3.351410320943436e-01, -2.000512215696288e-01, -1.100947616884045e-01, -3.495307016764358e-02, -5.424596403728409e-03, -4.688415397420247e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.299294229211677e-06, -2.489213758831783e-06, -2.792174570986946e-06, -3.297861011243150e-06, -4.198394786335039e-06, -5.956039430504445e-06, -9.852716081199292e-06, -2.010616072923125e-05, -5.362735947390600e-05, -1.935246876766147e-04, -9.562912049036155e-04, -2.900067225404811e-03, -4.499451332031813e-03, -1.140287604026418e-02, -5.699196139362483e-02, -2.901326520637837e-01, -1.017234115658320e+00, -6.410859208012045e-01, 1.464481304227121e+00, 3.167932745425409e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.533262126328546e-03, -1.002899192279056e-02, -1.078993691499705e-02, -1.199086643383234e-02, -1.396157878196670e-02, -1.737482970662684e-02, -2.373129824987420e-02, -3.669603913383939e-02, -6.551227572493429e-02, -1.262561130608193e-01, -2.553553099561195e-01, -4.981163316342949e-01, -4.195406017552978e-01, -1.105368677059620e+00, -2.320094132201429e+00, -3.041390677399729e+00, -4.728206239454172e+00, -3.919537960704660e+02, -7.428579973471992e+03, -4.314662291244571e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.662098904172440e-08, 1.966064547301225e-08, 2.493510794099492e-08, 3.482841011741725e-08, 5.549830586481890e-08, 1.055449004529128e-07, 2.532983047676615e-07, 8.189133080558344e-07, 3.784904970110076e-06, 2.395970080181873e-05, 2.652590964750605e-04, 1.148848482352185e-02, -2.227306604511850e-02, 1.419729684158093e-01, 7.999663263984756e-01, -9.163514451943660e+00, -2.224283149990164e+03, -8.147916771440867e+04, 1.929206976714948e+07, 3.250929872301018e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.104437154598067e-16, -6.674920115536634e-15, -1.978816546362635e-14, -5.052462593999505e-14, -1.333619544839604e-13, -3.969522081287699e-13, -1.387664514800275e-12, -4.817290957261397e-12, 4.728098831592683e-11, 7.429146527145518e-09, 1.315556208009677e-06, -4.818406558529984e-04, 1.288058107791401e-02, -2.972471119595479e-02, 2.158521193958998e-01, 1.974911227368915e+02, 2.206320148982015e+05, 2.050394385609625e+08, -7.457395009978816e+12, -9.252841523923204e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
