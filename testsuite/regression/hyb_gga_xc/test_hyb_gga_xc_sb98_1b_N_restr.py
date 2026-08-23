
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_sb98_1b_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1b", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.434642192896444e+00, -3.367361538518197e+00, -3.273130167314824e+00, -3.142692284849854e+00, -2.965163252521820e+00, -2.729361069498031e+00, -2.427022103585722e+00, -2.058985867219801e+00, -1.645125450509015e+00, -1.231958587866578e+00, -8.437764787090642e-01, -5.683970004534248e-01, -4.966135730608649e-01, -4.118022346494302e-01, -3.003543069480390e-01, -1.974691233760149e-01, -1.140637453512171e-01, -4.097574172327419e-02, -8.408733030921024e-03, -9.436416342865143e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_sb98_1b_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.522495175806529e+00, -4.430092098908225e+00, -4.300514020323815e+00, -4.120789737645849e+00, -3.875351658812128e+00, -3.547329347501380e+00, -3.121524447488033e+00, -2.589147798197025e+00, -1.955213658357202e+00, -1.275290641945058e+00, -8.039357485516736e-01, -7.198727098442074e-01, -6.456940907370416e-01, -5.135231654206522e-01, -3.469330788324928e-01, -1.829465602892725e-01, -1.102736065538095e-01, -5.262916187636461e-02, -1.120127591202103e-02, -1.255100155659957e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1b_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.192472809248605e-07, -3.720151574284973e-07, -4.583925588677623e-07, -6.078627573898489e-07, -8.879438951152221e-07, -1.476640204243219e-06, -2.938024508196594e-06, -7.534177997792428e-06, -2.718236611866881e-05, -1.402200522990979e-04, -8.162939942599679e-04, -1.944922941738447e-03, -1.600142927158144e-03, -8.849775019076358e-03, -4.146383334191970e-02, -4.076534496738667e-01, -2.880777833077331e+00, -5.601675539513009e+00, -5.226801420782545e+00, -4.534179908512868e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1b_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.266942138304280e-03, -9.682042289683423e-03, -1.031616439328431e-02, -1.131313682534484e-02, -1.295137686987857e-02, -1.583682084279014e-02, -2.151291242132806e-02, -3.475463321307366e-02, -7.324316732969233e-02, -1.977490111455263e-01, -4.920488089928476e-01, -4.227398552156762e-01, -6.337819983442742e-01, -8.543381907509991e-01, -2.645561243572112e+00, -9.912080438227157e+00, 5.301053779629611e+01, -2.717550357382594e+02, -1.289137186208027e+04, -1.072640999206919e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1b_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.062743645500774e-08, 1.216103883482754e-08, 1.480797382629406e-08, 1.978833942077885e-08, 3.045711293557875e-08, 5.820816303061032e-08, 1.539485483212730e-07, 6.388645046555087e-07, 4.537771679265569e-06, 5.269472442148944e-05, 9.154322578747656e-04, 4.498450982476540e-03, 5.294883896545520e-02, 3.958090357996989e-02, 1.061051621405782e+00, 3.152355273510549e+01, -5.914398358373383e+03, -6.550223146582083e+05, -7.391029788284324e+07, -4.722259752437105e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_1b_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_1b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.545816515895495e-14, -1.014667983304215e-13, -1.303993796110148e-13, -1.888345472507508e-13, -3.290133788106847e-13, -7.689496308465800e-13, -2.845138409190488e-12, -2.008647227801043e-11, -3.008958535515763e-10, -8.714969341693217e-09, -6.905971528860515e-07, 7.170186098276918e-06, -1.743196436853114e-02, 7.334040152014769e-03, -2.543993164104176e-01, 5.918836332466353e+01, 6.465804157023119e+05, 1.967158857566308e+09, 2.648580723617410e+13, 1.324268435347616e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
