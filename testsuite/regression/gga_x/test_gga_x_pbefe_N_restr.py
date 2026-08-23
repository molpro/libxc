
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbefe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbefe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.368053095314696e+00, -4.286850344439681e+00, -4.173149276089057e+00, -4.015811362073325e+00, -3.801738785934820e+00, -3.517399163346891e+00, -3.152281056117501e+00, -2.704536012555810e+00, -2.186603607583949e+00, -1.625952298589131e+00, -1.080170408756799e+00, -6.781865757441918e-01, -5.693789794077003e-01, -4.829181191994022e-01, -3.559206515222755e-01, -2.191589027398848e-01, -1.029840439789209e-01, -3.366308074478774e-02, -6.988414264994316e-03, -7.727993693432746e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbefe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbefe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.338890446917302e+00, -5.225970155402930e+00, -5.067910150227076e+00, -4.849344036033789e+00, -4.552436625802168e+00, -4.159540603335978e+00, -3.659654463498251e+00, -3.061000314151455e+00, -2.408643502222624e+00, -1.779252927671476e+00, -1.193050790560052e+00, -7.974708125410720e-01, -7.098759802689129e-01, -5.571263747489631e-01, -3.890410201856928e-01, -2.518688877532997e-01, -1.311469702010988e-01, -4.462990395495209e-02, -9.315423053567988e-03, -1.030395661746588e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbefe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbefe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.205891951900901e-06, -5.598541501357762e-06, -6.211784606335785e-06, -7.203401157061172e-06, -8.886344215962295e-06, -1.193769373833142e-05, -1.797263085156748e-05, -3.124680690453614e-05, -6.394854799456606e-05, -1.564087881088236e-04, -6.583417843972696e-04, -8.568199835629045e-03, -1.831403038782226e-02, -3.223515397792962e-02, -8.058201364263078e-02, -2.160277441574447e-01, -4.179268098447717e-01, -5.728178977371654e-01, -6.704942654136592e-01, -7.394678470858298e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbefe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbefe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.192088214756740e-02, -1.240906875143617e-02, -1.313750829846969e-02, -1.423865335024834e-02, -1.592762647442285e-02, -1.854498244985242e-02, -2.253592446277193e-02, -2.785625240117270e-02, -3.033182424334050e-02, -1.252451820794415e-02, 1.439227196547904e-02, -4.965094311453641e-01, -6.815672838875011e-01, -9.457715750581390e-01, -7.316315265732206e-01, 1.249264258647257e+00, -2.202109050022148e+01, -4.310229756289722e+02, -1.083726098087958e+04, -8.895862591439884e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbefe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbefe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.128392805403301e-08, 2.363504628614207e-08, 2.737457898113255e-08, 3.351553093049829e-08, 4.386566609678180e-08, 6.073991100284321e-08, 7.687611218215546e-08, -4.907460796557290e-08, -2.216630765173664e-06, -3.544725340230054e-05, -6.976303668546845e-04, 5.400348904594186e-03, 3.941018357223017e-02, 2.835233145519289e-02, -1.134427060485063e+00, -4.530794643235664e+01, -1.524826862282900e+03, -7.030069130755210e+04, -9.384704559184622e+06, -7.661239575114059e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbefe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbefe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.875022941744675e-13, 2.363478252231720e-13, 3.293529303740069e-13, 5.294700076103220e-13, 1.042313681345435e-12, 2.727706650275007e-12, 1.058945052727250e-11, 7.002447830402856e-11, 9.215150323531908e-10, 2.850064215818207e-08, 3.313340008797840e-06, 1.046831089700192e-03, 7.421887270040685e-03, 6.422697897919240e-02, 2.579992429660930e+00, 3.751059543228482e+02, 1.418319647552058e+05, 2.118873059605217e+08, 3.407357132871103e+12, 2.159808950865114e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
