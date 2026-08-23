
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_mohlyp2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.433330861550398e+00, -4.346196724996025e+00, -4.224242667900586e+00, -4.055620776124954e+00, -3.826570511946543e+00, -3.523425326417051e+00, -3.137474272012649e+00, -2.674567301805452e+00, -2.170035775859840e+00, -1.686522309292948e+00, -1.169430978800164e+00, -6.927149777148244e-01, -5.997903478776168e-01, -4.924773324437866e-01, -3.652596074793205e-01, -2.691598740494139e-01, -1.751630825527037e-01, -7.116009485030665e-02, -1.522019993995890e-02, -1.685708319930276e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_mohlyp2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.776773676165657e+00, -5.654109896696623e+00, -5.481670093360056e+00, -5.241591861584568e+00, -4.911809819977186e+00, -4.467007442644668e+00, -3.881324508139236e+00, -3.134023933212769e+00, -2.229005443501867e+00, -1.301125985594803e+00, -7.702031865269472e-01, -8.748237237352781e-01, -7.883969501660240e-01, -6.072168827081926e-01, -3.443135185743563e-01, -1.516572181892407e-01, -1.719361587398208e-01, -9.015234441741096e-02, -2.024223366807637e-02, -2.247506470518980e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mohlyp2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.340076029332024e-06, -1.502076848423184e-06, -1.768802505843964e-06, -2.234334108137959e-06, -3.117036486381903e-06, -4.997793705400908e-06, -9.706785715063424e-06, -2.431924258357275e-05, -8.298552157078035e-05, -3.795302671393791e-04, -2.095508839150075e-03, -3.572902840842104e-03, -2.684355048393604e-03, -1.724199456441405e-02, -1.330619240351940e-01, -1.102663152110825e+00, -3.733934509815760e+00, -8.226381533363076e+00, -1.321986844644014e+01, -1.460805801414546e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mohlyp2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.319886182406375e-02, -1.391526249402484e-02, -1.502797618935392e-02, -1.681821416429298e-02, -1.985252593700458e-02, -2.540711948977393e-02, -3.677509525560147e-02, -6.374286631956980e-02, -1.366910900944489e-01, -3.063984738922608e-01, -6.159455958876715e-01, -7.080879486033631e-01, -6.994495240804487e-01, -1.637111971594630e+00, -5.868343112409042e+00, 3.058338121900381e+00, 2.011717430552127e+02, -3.730779458732454e+02, -2.292905608740900e+04, -1.939581960788517e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mohlyp2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.689904991337313e-08, 3.190079110951808e-08, 4.072445707134734e-08, 5.772681977738591e-08, 9.486535110753242e-08, 1.916438446028584e-07, 5.133733377128800e-07, 1.987104271477077e-06, 1.174290833760250e-05, 9.458841719414298e-05, 1.236308796971480e-03, 1.991889281743669e-02, 2.765629039328275e-02, 2.655311022790019e-01, 3.972204329360503e+00, -3.978613793062770e+01, -1.814418014244716e+04, -1.212103898644618e+06, -1.847924647925448e+08, -1.513439062424677e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mohlyp2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.821442850728815e-13, -2.294458154701590e-13, -3.193835410374203e-13, -5.124246090296730e-13, -1.004863319414759e-12, -2.607936027154397e-12, -9.921108479536619e-12, -6.185230379370093e-11, -6.528317713438174e-10, -3.731599577438322e-09, 1.296086922737157e-06, -9.958533559951950e-04, -7.228566140423465e-03, -5.956499225883543e-02, -1.276330775758267e+00, 8.914237298772611e+02, 1.651704052116267e+06, 3.928657134810275e+09, 6.711561022020911e+13, 4.266611070831573e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
