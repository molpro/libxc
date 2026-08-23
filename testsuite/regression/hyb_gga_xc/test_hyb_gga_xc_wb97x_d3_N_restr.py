
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_wb97x_d3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.429444212172604e+00, -3.362461942000660e+00, -3.268685186696422e+00, -3.138967212393780e+00, -2.962637115972249e+00, -2.728919406436656e+00, -2.430139740924432e+00, -2.066917385132427e+00, -1.653025619563210e+00, -1.216229330557041e+00, -7.839500316424599e-01, -4.682870358562868e-01, -3.970207169408158e-01, -3.097624563412824e-01, -1.997399288796576e-01, -8.889126726178374e-02, -1.967471740692051e-02, 1.136110125497586e-02, 3.947344177258004e-03, 4.761538947070074e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_wb97x_d3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.362706399022444e+00, -4.268331598434265e+00, -4.135637242175713e+00, -3.951001768984989e+00, -3.698090636585762e+00, -3.359943789716187e+00, -2.925014848023227e+00, -2.400002909091481e+00, -1.824150864116173e+00, -1.230111167560258e+00, -7.404673830696132e-01, -6.096676823579433e-01, -5.562595840474081e-01, -4.023973769722166e-01, -2.566646946342254e-01, -9.829408588866743e-02, -1.650937446244286e-02, 9.902495818229844e-03, 5.102436982905899e-03, 6.331053412835445e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_d3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.429317059244338e-06, -2.649707535439346e-06, -3.003840953660176e-06, -3.599344725051298e-06, -4.664351612686965e-06, -6.728590167943308e-06, -1.114823808973475e-05, -2.177193974475858e-05, -5.132808562233970e-05, -1.706604938878665e-04, -9.071849839825341e-04, -3.111588174999827e-03, 2.154640884369575e-03, -1.270924919540795e-02, -3.193346117785690e-02, -2.423418901375473e-01, -2.155974636628006e+00, 5.169547367837503e+00, 1.135873502759557e+01, 1.426729883706569e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_d3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.052336453229581e-02, -1.110049959344526e-02, -1.197388882873944e-02, -1.331787455500336e-02, -1.542394282776342e-02, -1.877197720239298e-02, -2.408527478597479e-02, -3.226094102643594e-02, -4.728387971869353e-02, -1.620736719317877e-01, -6.560325790440917e-01, -6.021329100866329e-01, -4.966569712765163e-01, -1.160003317731906e+00, -8.307459340003825e-01, -2.604975601310209e+01, 2.437516947845219e+01, -2.826907275362565e+02, 4.702757699595752e+03, 5.385145009564839e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_d3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.590763892051670e-08, 3.043939412449261e-08, 3.807514231372005e-08, 5.171893391945766e-08, 7.796599941031696e-08, 1.329240877902087e-07, 2.571225323776967e-07, 5.394869646528956e-07, 1.315677397647803e-06, 3.715688874863908e-05, 1.341968412436500e-03, 1.984976598308159e-02, 4.286780436546424e-03, 1.660505749358341e-01, -6.137995978820662e-01, 1.270092415792600e+02, -1.980377103903835e+03, 5.539217186140713e+05, 1.570328516854027e+08, 1.475025829148993e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_d3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_d3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.465303433872899e-14, -1.210195272787385e-13, -1.680841558283341e-13, -2.575974052017046e-13, -4.361267216855976e-13, -7.590042001698314e-13, -5.583552209379047e-13, 1.491668147009071e-11, 3.336665831867194e-10, -2.803049463283671e-10, -1.741074024871611e-06, -1.140135361758844e-03, -6.747153661324594e-03, -3.676446432850745e-02, 9.920018480816103e-01, -6.279553427372031e+02, 1.523414811191121e+05, -1.857034840133145e+09, -5.761456870754879e+13, -4.167035023470130e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
