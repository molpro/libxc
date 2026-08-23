
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_th1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.756722827280403e+00, -4.652725854496026e+00, -4.507084314729276e+00, -4.305695623774453e+00, -4.032499101212926e+00, -3.672520531985294e+00, -3.218917737941579e+00, -2.685570224307347e+00, -2.122190888091777e+00, -1.606054972881683e+00, -1.109097890317964e+00, -7.070380020182440e-01, -6.147824680856594e-01, -5.084991951945413e-01, -3.747301098331656e-01, -2.479122305964557e-01, -1.449464663792894e-01, -6.193517715280852e-02, 1.599075338291650e-02, 1.438340901002828e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_th1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.719725530413251e+00, -6.585192288000052e+00, -6.393406479517643e+00, -6.121627004985998e+00, -5.740409908641170e+00, -5.214953233844758e+00, -4.511670909693101e+00, -3.615102373347037e+00, -2.561732457237168e+00, -1.508427729456336e+00, -8.987233653900842e-01, -8.968346453318305e-01, -8.040237302130714e-01, -6.253150695553682e-01, -4.075560002052388e-01, -2.130580434532478e-01, -7.025421036196709e-02, 2.060591353130150e-02, 5.665121927927756e-02, -1.959148714798372e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.473726959016754e-06, 3.769615779378361e-06, 4.197460787997905e-06, 4.809020882831565e-06, 5.649176329819263e-06, 6.649278634432812e-06, 7.095857606950430e-06, 2.870871692810453e-06, -2.975418076830621e-05, -2.435039452274085e-04, -1.519942786099384e-03, -2.872001158635452e-03, -2.851532658987393e-03, -1.557976376329982e-02, -7.927846085674831e-02, -6.388306496064466e-01, -9.462738970379799e+00, -3.027081024209687e+02, -2.026705504767663e+04, 3.839871234915388e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.124307891046131e-02, -1.212013264610000e-02, -1.346941818296129e-02, -1.560698266444018e-02, -1.913915904485061e-02, -2.534114637837904e-02, -3.722854371087331e-02, -6.307887581714898e-02, -1.300307895358455e-01, -3.378673085585457e-01, -8.113710989771334e-01, -6.738688204858220e-01, -7.656332352890558e-01, -1.322632674936803e+00, -3.338321315783047e+00, -1.374915956395362e+01, -1.089810805234139e+02, -1.751880942576153e+03, 9.430403472504523e+04, 7.325398512785994e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.496964440167169e-08, -1.328865596501473e-08, -9.744684481408061e-09, -1.575528045642232e-09, 1.948834446788898e-08, 8.238309688764410e-08, 3.115276094575605e-07, 1.412253741875489e-06, 9.194584361344997e-06, 1.010065520392983e-04, 1.737328556047780e-03, 1.524045733778769e-02, 4.082977878406073e-02, 1.420752465113655e-01, 1.446405854215622e+00, 4.757646371631211e+01, 6.084529690466591e+03, 3.683348086968221e+06, -3.381008864280233e+10, -1.876891587255379e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.675648219217218e-13, -2.326176037426703e-13, -3.581229959135328e-13, -6.297612820769983e-13, -1.317538301458188e-12, -3.474462563364668e-12, -1.254366917180940e-11, -6.974575305725163e-11, -7.067226604438041e-10, -1.672710391355344e-08, -1.394428953243027e-06, -6.317479005402946e-04, -9.069836584436936e-03, -1.370702519791043e-02, 7.425068403490502e-02, 1.045015023748788e+02, 3.618733044391022e+05, 1.633305863111271e+10, 3.107296914186154e+16, 1.474581593500469e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
