
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_p86vwn_ft_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn_ft", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.022698722960510e-02, -6.924075495060285e-02, -6.782919553068811e-02, -6.581350335674015e-02, -6.294530375772929e-02, -5.888804562697435e-02, -5.321123305446759e-02, -4.544959947239221e-02, -3.539695456419364e-02, -2.391686803778129e-02, -1.477708650718221e-02, -4.654372234795837e-02, -5.453704845980248e-02, -4.004700436710692e-02, -2.241405209464428e-02, -3.564637206094669e-03, 3.983303593472333e-03, -8.727297991935086e-03, -3.350399040159466e-03, -4.454830836828051e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_p86vwn_ft_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn_ft", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.296392658850457e-01, -1.284661370770721e-01, -1.267572292482811e-01, -1.242537891284375e-01, -1.205565617169227e-01, -1.150336596725546e-01, -1.066599205757544e-01, -9.377860072311739e-02, -7.413845419300391e-02, -4.849942915013538e-02, -4.695409739289785e-02, -8.956651264584477e-02, -8.124209520281263e-02, -7.979514645506709e-02, -6.921087231285830e-02, -4.442045207487186e-02, 2.705227510918281e-03, 1.503792069668399e-04, -4.275006326726455e-03, -5.873120727225231e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86vwn_ft_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn_ft", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.095311086439197e-07, 6.469815559341004e-07, 7.044830424680751e-07, 7.951790649111474e-07, 9.435833442320319e-07, 1.198430847024705e-06, 1.662495273690508e-06, 2.556585947186969e-06, 4.285963567701269e-06, 7.407276290509370e-06, 7.460062281650209e-05, 3.220818492501487e-03, 7.989644322613365e-03, 1.374989030593661e-02, 4.373594551285392e-02, 2.303771460861370e-01, 3.480028142080381e-01, -2.514504767096048e+01, -1.191140949462840e+01, -1.648632154419437e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86vwn_ft_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn_ft", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.568495763990354e-04, -4.969129515493209e-04, -5.603429167451701e-04, -6.650034712384717e-04, -8.481152784858251e-04, -1.196008320787423e-03, -1.936979470457137e-03, -3.777410305543870e-03, -9.318700080318274e-03, -2.960965818756916e-02, -1.007639408570945e-01, -4.209878140654933e-03, 9.234990375089708e-03, -6.095839949118677e-03, -3.272084810155238e-01, -5.483106813904214e+00, -9.094657440364330e+01, 9.430887884015008e+02, -2.548796231169040e+03, -4.813344864792496e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86vwn_ft_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn_ft", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.935827217364744e-09, 5.736519472432164e-09, 7.113923863634285e-09, 9.674628224526262e-09, 1.499256457955734e-08, 2.791873956606100e-08, 6.715946221143481e-08, 2.297003583983022e-07, 1.261161307146675e-06, 1.287896636834434e-05, 2.889826904953331e-04, -9.408858162405069e-04, -1.282610201591751e-02, -1.482416766563113e-02, 2.061334351301363e-01, 2.831129347116194e+01, 6.644031115045719e+03, -2.074504303017197e+06, -5.229056749479468e+08, -1.820315816350740e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_p86vwn_ft_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_p86vwn_ft", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.163183162688041e-13, -1.419945039978503e-13, -1.890748518051808e-13, -2.850971043114367e-13, -5.133131734966851e-13, -1.188945435656427e-12, -3.928661912282663e-12, -2.133332138791640e-11, -2.308218512596177e-10, -6.678520468118902e-09, -1.062653668283646e-06, -5.418913950632707e-04, -5.427618562125485e-03, -2.946419648556693e-02, -1.124045107296651e+00, -3.179696553437656e+02, -5.062495721650185e+05, 7.125027083633419e+09, 1.779422201939266e+14, 4.535412913400841e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
