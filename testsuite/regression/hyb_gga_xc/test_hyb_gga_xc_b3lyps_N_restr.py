
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b3lyps_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyps", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.730050920339359e+00, -3.660020577875696e+00, -3.561938104439299e+00, -3.426166863765161e+00, -3.241362415321972e+00, -2.995812644880117e+00, -2.680581233141784e+00, -2.295070621615976e+00, -1.854069761485520e+00, -1.389855890730602e+00, -9.375806167697778e-01, -6.128664553390791e-01, -5.272875220620258e-01, -4.420886571561618e-01, -3.224883856813962e-01, -2.011801916828119e-01, -1.125034744456680e-01, -7.513782886006638e-02, -4.495549825528276e-02, -2.962056602328272e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b3lyps_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyps", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.677735277879639e+00, -4.581230961815726e+00, -4.445983502973759e+00, -4.258593977890602e+00, -4.003195768269475e+00, -3.663246228349030e+00, -3.225931263603920e+00, -2.690671533478736e+00, -2.083079706282932e+00, -1.473956233932059e+00, -9.822295361440405e-01, -7.495600217509156e-01, -6.682047271552489e-01, -5.358231110708467e-01, -3.711015105666631e-01, -2.257169638445054e-01, -1.144520332979144e-01, -4.157076068389651e-02, -1.516365289401230e-02, -5.309583022987013e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyps_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyps", 1)
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


def test_hyb_gga_xc_b3lyps_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyps", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.935210615937768e-03, -1.037315489028756e-02, -1.103593612412597e-02, -1.206113731379722e-02, -1.369669083561315e-02, -1.642099715000197e-02, -2.123286113814301e-02, -3.038947516011749e-02, -4.919682346504728e-02, -8.840098482185534e-02, -1.771463348698233e-01, -4.390480325029966e-01, -5.621987213694023e-01, -8.899896631327870e-01, -1.653720514739319e+00, -1.548755578988606e+00, 7.732488216954547e+00, -7.333392089962508e+00, 9.717703585736384e+03, 7.068437028744813e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyps_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyps", 1)
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


def test_hyb_gga_xc_b3lyps_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyps", 1)
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
