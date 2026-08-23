
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_b97_d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.523370787834001e+00, -4.432441507824382e+00, -4.305110912866881e+00, -4.128908914212389e+00, -3.889224318614577e+00, -3.571204357969215e+00, -3.164387174600937e+00, -2.671893889685694e+00, -2.125974962454536e+00, -1.598803027372248e+00, -1.098508163427395e+00, -7.165132913814853e-01, -6.198844991090630e-01, -5.137995907579949e-01, -3.755927709598179e-01, -2.509220648163716e-01, -1.439571616499809e-01, -4.526418313747517e-02, -7.268961564111702e-03, -6.675135728437863e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_b97_d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.052739281461060e+00, -5.928110380290573e+00, -5.753198963729967e+00, -5.510281655789501e+00, -5.177831775189210e+00, -4.731878377246994e+00, -4.149152674966346e+00, -3.411706254947408e+00, -2.515198784295821e+00, -1.535625289053382e+00, -9.224236837319653e-01, -9.078981999649806e-01, -8.019194692326427e-01, -6.352140438953902e-01, -4.166496317257747e-01, -2.105654878057836e-01, -1.313938197311069e-01, -5.996183707855223e-02, -1.001088201935301e-02, -8.994792869692711e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.001512608597414e-07, 3.895021172824663e-07, 3.654272208298368e-07, 3.078403994984198e-07, 1.591062173439586e-07, -2.683783684999476e-07, -1.694199213030005e-06, -7.505842690338638e-06, -3.776425964339694e-05, -2.331299941062032e-04, -1.412215988994285e-03, -3.033729850235855e-03, -6.805040635471536e-03, -1.522434329542722e-02, -7.112201499701712e-02, -6.573796336844250e-01, -4.569104449403446e+00, -7.806054333501868e+00, -4.804720188070159e+00, -1.846819568561253e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.213134980214989e-02, -1.270674491428186e-02, -1.359367282426278e-02, -1.500697114231923e-02, -1.737663013421533e-02, -2.167753350793800e-02, -3.051088753359009e-02, -5.231729914657569e-02, -1.197432777157134e-01, -3.483300201562476e-01, -8.675923670161454e-01, -5.502325851567860e-01, -7.522730153038868e-01, -1.118465602823801e+00, -3.603876509182941e+00, -1.456678080252333e+01, 8.475111550384949e+01, -3.352621574057489e+02, -1.320447784472683e+04, -8.145936281698118e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.209229574160625e-09, 1.106599613963590e-08, 1.443760195758295e-08, 2.122004119445689e-08, 3.700555057439473e-08, 8.207393425325672e-08, 2.520850986196258e-07, 1.174562815034128e-06, 8.921274841442092e-06, 1.075907825476138e-04, 1.865582932876997e-03, 5.024427455280401e-03, 3.854402309098202e-02, 5.033929842983852e-02, 1.610949188593172e+00, 5.611916860412408e+01, -8.630100898803506e+03, -9.145606104427499e+05, -6.965190222301733e+07, -1.982368844786724e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.188387346857033e-13, -1.471048472394329e-13, -2.007586248392616e-13, -3.164020907471269e-13, -6.167115103365473e-13, -1.639134405577981e-12, -6.749761454682601e-12, -4.970946692345166e-11, -7.407962999844663e-10, -2.250537155211299e-08, -1.958200273679307e-06, 2.304810696656342e-04, -3.887551342371115e-03, 2.219475502910399e-02, -2.054526360973767e-01, 5.066737510984108e+01, 9.533038218062354e+05, 2.702111462458608e+09, 2.429317135598473e+13, 5.393252630558632e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
