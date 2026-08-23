
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hse12_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.030331726286568e+00, -2.973440173809617e+00, -2.893805125973964e+00, -2.783668384201113e+00, -2.633970572173288e+00, -2.435529985777800e+00, -2.181719959469843e+00, -1.872801711615441e+00, -1.519192126210510e+00, -1.139919299305238e+00, -7.710215793560780e-01, -5.162220304685536e-01, -4.549958806026351e-01, -3.782366215189835e-01, -2.774533137588343e-01, -1.791047600389878e-01, -9.903073560652334e-02, -4.027657347806654e-02, -8.765785903309398e-03, -9.701587792203246e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hse12_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.826184602478722e+00, -3.745335738137234e+00, -3.631876590335319e+00, -3.474386733288900e+00, -3.259240823444941e+00, -2.972226285546495e+00, -2.603268821763282e+00, -2.158458197506779e+00, -1.682468431320775e+00, -1.215953766766042e+00, -7.978032622863064e-01, -6.476533951704972e-01, -5.896631183320313e-01, -4.708804781925094e-01, -3.308290349922323e-01, -1.857133608827074e-01, -1.120748178942050e-01, -5.195502346501058e-02, -1.168117529221987e-02, -1.293538409813128e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse12_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.019658815752231e-06, -2.212006096748425e-06, -2.519069309216002e-06, -3.031318554834149e-06, -3.939737367418732e-06, -5.689416421875230e-06, -9.431460013948386e-06, -1.838276214222416e-05, -4.145421521737956e-05, -1.178893562171605e-04, -5.875494810578224e-04, -1.858876659612538e-03, 4.680577337833301e-04, -6.704010217439486e-03, -2.628806848052075e-02, -2.466966218324979e-01, -1.032729414484937e+00, -8.016020626812445e-01, 6.036659648291788e-03, 1.504922553420553e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse12_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.287358226331768e-03, -9.749626809959874e-03, -1.045264616329559e-02, -1.154541763571058e-02, -1.329113870164096e-02, -1.615738275519158e-02, -2.086188818701349e-02, -2.746166080177475e-02, -3.121804314525437e-02, -8.178904641358996e-02, -2.814152771590123e-01, -4.439643196602912e-01, -4.797435434620542e-01, -9.065267645963498e-01, -1.669883036461154e+00, -3.903914686683382e+00, -4.011017977768994e-01, -2.970967320576186e+02, -1.358342139857414e+04, -1.116780167970269e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse12_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.594161273461953e-08, 2.977211769388255e-08, 3.622069980234010e-08, 4.779802068467919e-08, 7.044614542424571e-08, 1.196483322302469e-07, 2.365707337845939e-07, 4.740351683114482e-07, -3.726583465441013e-08, 6.965740328667989e-06, 3.439681608273064e-04, 1.108171866622372e-02, 2.109977557993549e-02, 1.042967245256217e-01, 3.170587343029210e-01, -1.854176878777164e+00, -2.172119511746014e+03, -3.758780098638987e+05, 1.380746113142922e+05, 2.578585853613300e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_hse12_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.288310610152390e-13, -1.545011574407333e-13, -1.997407455094752e-13, -2.858258713877121e-13, -4.647625651279772e-13, -8.529612566669842e-13, -1.284803410000026e-12, 1.058671092896227e-11, 4.037392468649484e-10, 7.535711435693038e-09, 3.311259656847194e-07, -6.471568855409290e-04, -9.194807008846922e-03, -2.744196037895342e-02, 7.420135263558003e-02, 1.488201841505764e+02, 2.418342692506539e+05, 9.261657483224295e+08, -4.600982050329903e+10, -6.593259128892691e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
