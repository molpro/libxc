
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_tfvw_opt_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tfvw_opt", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.819547942955892e+01, 7.562409790744226e+01, 7.210571722307390e+01, 6.739549830740107e+01, 6.128361282615602e+01, 5.369819695638729e+01, 4.485786892531713e+01, 3.541371151205973e+01, 2.638370388296548e+01, 1.836739670923028e+01, 9.306965020686672e+00, 2.019049752599201e+00, 1.290396745582165e+00, 1.068915680280303e+00, 7.748912657036112e-01, 5.532229710009098e-01, 4.415405137138359e-01, 3.891739812315890e-01, 3.611556788060377e-01, 3.439661319327891e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_tfvw_opt_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tfvw_opt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.136017753498284e+01, 8.715069506327123e+01, 8.139883328690127e+01, 7.371367583939264e+01, 6.376983131561817e+01, 5.148052752661099e+01, 3.725569892272031e+01, 2.226998704716670e+01, 8.569053311663202e+00, -9.528330226155768e-01, -1.986523436039684e+00, 1.858459358083500e+00, 1.660500485341870e+00, 8.379756626876769e-01, 1.054407263346851e-01, -2.791053103923349e-01, -3.888144139466029e-01, -3.837742325472305e-01, -3.609242280770771e-01, -3.439633023562920e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tfvw_opt_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tfvw_opt", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.180936362427330e-04, 4.444892435211894e-04, 4.853556635417799e-04, 5.506924317584210e-04, 6.600829229016316e-04, 8.557563560441680e-04, 1.240565213689064e-03, 2.106989324356039e-03, 4.467039811167332e-03, 1.270202860096615e-02, 4.660538114181383e-02, 1.208962257225934e-01, 1.821003815888156e-01, 3.505524949932411e-01, 1.117563620499395e+00, 6.431858152631056e+00, 7.624362076876436e+01, 2.326385392162103e+03, 2.621525905650400e+05, 1.939366207117577e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tfvw_opt_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tfvw_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.576763620650327e-01, 5.757727048780750e-01, 6.031261275384049e-01, 6.454196588114374e-01, 7.130459866602011e-01, 8.267471480213511e-01, 1.032954633943953e+00, 1.452015294365029e+00, 2.453008239372598e+00, 5.247051325252669e+00, 1.006724960354784e+01, 4.433151924878212e+00, 3.884389212457306e+00, 7.033058804672274e+00, 1.875176281400003e+01, 8.719610082299140e+01, 8.813260150677336e+02, 2.412754632485157e+04, 2.528688727298762e+06, 1.781837403848791e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tfvw_opt_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tfvw_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.334588162493098e-06, -2.638673624120724e-06, -3.146178566037816e-06, -4.050245801616069e-06, -5.819158131637546e-06, -9.780553467913093e-06, -2.055428446631575e-05, -5.929087162537986e-05, -2.665034347185826e-04, -2.154811760664602e-03, -2.900916930048397e-02, -1.952039718726980e-01, -4.428787843044041e-01, -1.641229405622523e+00, -1.668044668933177e+01, -5.525048319942116e+02, -7.763725820275334e+04, -7.228138888634683e+07, -9.178494923534086e+11, -5.023227092233213e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tfvw_opt_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tfvw_opt", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
