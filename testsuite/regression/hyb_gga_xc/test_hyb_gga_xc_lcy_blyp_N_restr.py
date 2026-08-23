
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lcy_blyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_blyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.023169138150292e+00, -3.941141215721294e+00, -3.826251096874242e+00, -3.667201933028045e+00, -3.450678373645051e+00, -3.162880671395450e+00, -2.793100682681851e+00, -2.339935088187871e+00, -1.818854538072409e+00, -1.265396657275854e+00, -7.438326345936424e-01, -4.392903371656181e-01, -3.582315862372025e-01, -2.670130075504183e-01, -1.469021921035825e-01, -4.126102284967478e-02, 7.204154644256713e-03, -3.414528822986039e-03, -9.124277495838630e-04, -1.023982983647265e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lcy_blyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_blyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.123233677907773e+00, -5.010805192947326e+00, -4.853328271297929e+00, -4.635324245754327e+00, -4.338594304034443e+00, -3.944474360103829e+00, -3.439301019401685e+00, -2.824932041948631e+00, -2.135691824079777e+00, -1.457937805491839e+00, -9.102116791562980e-01, -6.075152805744208e-01, -5.118321268068070e-01, -3.843269783043778e-01, -2.344767791783033e-01, -1.179280584240625e-01, -4.254833729491909e-02, -4.843802671875952e-03, -1.212010514073404e-03, -1.364614367330314e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lcy_blyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_blyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.575385252140227e-06, -3.843197334871694e-06, -4.261953772124096e-06, -4.940553381686432e-06, -6.097140235268877e-06, -8.212391063557747e-06, -1.247397925402102e-05, -2.223575980997778e-05, -4.842529727963253e-05, -1.310548141146487e-04, -4.484641721506242e-04, -2.528193138123030e-03, -4.500194768166031e-03, -5.282191773618414e-03, 5.114430063462259e-03, 2.566946011670843e-01, 4.214653605930679e+00, 5.242999794064824e+00, -3.391647317894261e-05, -7.652362695388141e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lcy_blyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.156491923258826e-02, -1.206352508003174e-02, -1.281612462860410e-02, -1.397553704085272e-02, -1.581330987870881e-02, -1.884195353905315e-02, -2.409220237712132e-02, -3.373307856699592e-02, -5.206498839392745e-02, -8.320535203652062e-02, -1.360521457164875e-01, -4.172002417956200e-01, -5.504722116911335e-01, -7.524804433261636e-01, -9.597538529267047e-01, 1.456243052476603e+00, 1.546465302438299e+01, -8.468102447103216e+01, -1.389372497789268e+03, -1.175189280742623e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lcy_blyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.694565216069958e-08, 1.911813649550686e-08, 2.271242005382354e-08, 2.902132391254549e-08, 4.104519130524444e-08, 6.666854983383311e-08, 1.296481751462140e-07, 3.091671851904292e-07, 7.846323525711784e-07, -2.690532215247110e-06, -2.022440698511114e-04, 5.884710497749590e-04, 4.178459310243713e-03, -1.777058776745780e-02, -6.447354647057379e-01, -3.676369702501603e+01, -3.501899636424489e+03, 1.636263242880407e+05, -4.303978384913761e+02, -7.539975309832790e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lcy_blyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lcy_blyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.354815310293734e-14, 1.164219793454876e-13, 1.593291220653992e-13, 2.497263664348346e-13, 4.747046742811036e-13, 1.185436305677007e-12, 4.339631460607982e-12, 2.696868621263781e-11, 3.435168618439368e-10, 1.126926684901246e-08, 1.248177394341749e-06, 2.579688699630271e-04, 2.052676011675641e-03, 1.162581815508397e-02, 3.226647374325447e-01, 3.090715882717763e+01, 3.945924985207941e+03, 4.432244275159957e+05, 1.171956688225582e+08, 1.594214312211136e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
