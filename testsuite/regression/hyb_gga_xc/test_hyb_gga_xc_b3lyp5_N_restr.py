
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b3lyp5_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp5", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.517627859109246e+00, -3.451805774491728e+00, -3.359621175635588e+00, -3.232022204619899e+00, -3.058358090487788e+00, -2.827644267033215e+00, -2.531524280805607e+00, -2.169496369884905e+00, -1.755454721676197e+00, -1.319129001907496e+00, -8.904392364177911e-01, -5.776048223423410e-01, -4.960928231104804e-01, -4.163636029714202e-01, -3.040033371766602e-01, -1.896135841308918e-01, -1.061339661545571e-01, -7.207915949399425e-02, -4.385866551479725e-02, -2.942456156153259e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b3lyp5_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp5", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.395869887572926e+00, -4.304974865787098e+00, -4.177588751742520e+00, -4.001091967457234e+00, -3.760542249054750e+00, -3.440366194715649e+00, -3.028521589065390e+00, -2.524554786473297e+00, -1.952882127615013e+00, -1.380902218831041e+00, -9.205653831798231e-01, -7.036879078536099e-01, -6.277331693881162e-01, -5.026071312863318e-01, -3.474662830894916e-01, -2.111802107099862e-01, -1.066374772676634e-01, -3.787515923574380e-02, -1.381159773697290e-02, -5.057509493143399e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp5_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp5", 1)
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


def test_hyb_gga_xc_b3lyp5_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp5", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.418355623905144e-03, -9.834759915067267e-03, -1.046501313824551e-02, -1.144004011083720e-02, -1.299581051398891e-02, -1.558760235259334e-02, -2.016521220277685e-02, -2.886926501690370e-02, -4.668672819452607e-02, -8.335777591321454e-02, -1.651230644923848e-01, -4.162901181148739e-01, -5.322498923597975e-01, -8.435038201254750e-01, -1.552217461849883e+00, -1.215236795020094e+00, 9.604468674852935e+00, 1.659221877845231e+01, 1.078676101947772e+04, 7.251936469743128e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp5_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp5", 1)
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


def test_hyb_gga_xc_b3lyp5_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp5", 1)
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
