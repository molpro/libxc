
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.521901045322691e+00, -3.456075330924951e+00, -3.363885462706220e+00, -3.236278812499528e+00, -3.062603446342241e+00, -2.831873010430186e+00, -2.535728239916821e+00, -2.173662829337304e+00, -1.759563467573691e+00, -1.323148137820197e+00, -8.943303637790471e-01, -5.813892312429397e-01, -4.998277419705086e-01, -4.200145581530491e-01, -3.074900435951972e-01, -1.928109035281597e-01, -1.088329101482755e-01, -7.396318344965261e-02, -4.471230625270831e-02, -2.959367664677377e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.400202111190749e+00, -4.309303965881400e+00, -4.181913313996319e+00, -4.005409909536425e+00, -3.764850476296501e+00, -3.444660049082456e+00, -3.032793939303969e+00, -2.528794477107173e+00, -1.957071314400493e+00, -1.385012563384852e+00, -9.245625321563995e-01, -7.075903896227298e-01, -6.315916870332260e-01, -5.063909790666964e-01, -3.511037211183979e-01, -2.145579129716358e-01, -1.095579475680577e-01, -4.000456680334481e-02, -1.483939689057970e-02, -5.273730520975077e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.932669388605008e-06, -3.160918657737280e-06, -3.519419112322407e-06, -4.104276958575015e-06, -5.111273396826152e-06, -6.982269671971079e-06, -1.084903736821495e-05, -2.009976787391290e-05, -4.700717050442343e-05, -1.476682953910483e-04, -6.920534190017271e-04, -4.558084913309869e-03, -9.115020120026912e-03, -1.686463413662666e-02, -5.054728293987276e-02, -2.050062084870619e-01, -1.602649745154709e+00, -1.268135248832186e+02, -1.215203049396450e+04, -7.225559591111589e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.418639215430617e-03, -9.835064184819168e-03, -1.046534976110872e-02, -1.144042924352698e-02, -1.299628946895599e-02, -1.558824695634240e-02, -2.016619693784695e-02, -2.887106345334815e-02, -4.669093808683902e-02, -8.337142423347232e-02, -1.651815370950854e-01, -4.164594064851297e-01, -5.325170359944574e-01, -8.440575215322291e-01, -1.554226682896078e+00, -1.229230003775291e+00, 9.393669369528919e+00, 8.887289334674733e+00, 1.009613230607527e+04, 7.099391344089304e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.469040737555899e-08, 1.665322452395131e-08, 1.992632488164462e-08, 2.574130008013380e-08, 3.703762817354010e-08, 6.188833916494730e-08, 1.265981239847248e-07, 3.354083917621358e-07, 1.171596416523641e-06, 3.872769449205334e-06, -2.821397293015969e-05, 4.853389225502935e-03, 1.988009122440288e-02, 4.181840365525070e-02, -4.346794928883768e-02, -2.541767403325562e+01, -3.939050161749658e+03, -8.184122513227419e+05, -7.277829808496783e+09, -2.455467461714594e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.572046575474118e-14, 9.444993953184407e-14, 1.296930064216833e-13, 2.042902255605065e-13, 3.912602516811669e-13, 9.884095059825132e-13, 3.685288127392601e-12, 2.360946722478852e-11, 3.173570996649001e-10, 1.153624663607475e-08, 1.535075238511385e-06, 3.741132441716771e-04, 3.291063362626283e-03, 2.211564449060911e-02, 9.424157681586556e-01, 2.652462847368359e+02, 5.409872726484596e+05, 1.437794882653420e+10, 1.742695369751931e+16, 5.795234463853570e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
