
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_zlp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_zlp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.417876871606998e+00, -4.339975066352500e+00, -4.230181745807650e+00, -4.076845698816356e+00, -3.865518071850500e+00, -3.579833064191553e+00, -3.204346089628672e+00, -2.730773901494492e+00, -2.169212514180822e+00, -1.566269579735137e+00, -1.037159332215219e+00, -7.636467906983275e-01, -6.689692589711341e-01, -5.409006067575186e-01, -3.705166637511241e-01, -2.084889205279671e-01, -9.205276811407179e-02, -2.958065446418792e-02, -6.135503698105760e-03, -6.787478724170122e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_zlp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_zlp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.700385023535581e+00, -5.602466148841624e+00, -5.464318505249844e+00, -5.271102531582603e+00, -5.004272709206775e+00, -4.642552030189097e+00, -4.165345486081823e+00, -3.560530111644934e+00, -2.838930116201764e+00, -2.058563753710047e+00, -1.368651898006205e+00, -1.009992934203950e+00, -8.854975095166864e-01, -7.167985729326106e-01, -4.918039683244212e-01, -2.772068095687971e-01, -1.225633941565715e-01, -3.941970096662236e-02, -8.179563103257261e-03, -9.049801744116150e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_zlp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_zlp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.997666000985971e-03, -9.424484978247558e-03, -1.007203047975187e-02, -1.107739305540167e-02, -1.269058105935817e-02, -1.540338086928544e-02, -2.027912668266941e-02, -2.990304718136573e-02, -5.151722855828075e-02, -1.085077583688921e-01, -2.700292086894888e-01, -5.226504877706306e-01, -6.929705587943140e-01, -1.085916769409330e+00, -2.394059414226260e+00, -7.830339058203412e+00, -4.131641366621312e+01, -4.071945448906662e+02, -9.539784751836860e+03, -7.812693412468695e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
