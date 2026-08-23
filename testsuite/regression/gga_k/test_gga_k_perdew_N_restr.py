
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_perdew_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_perdew", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.393993589674372e+01, 9.028639994247784e+01, 8.529102733263042e+01, 7.861057493551216e+01, 6.995538971477606e+01, 5.923782270929233e+01, 4.679287064189767e+01, 3.359656796923649e+01, 2.127288093903066e+01, 1.156946296031001e+01, 5.158161773134092e+00, 2.191182444580733e+00, 1.621800674781034e+00, 1.091707987341634e+00, 5.563026076396601e-01, 2.312008305107160e-01, 1.067610940806752e-01, 7.486405381907171e-02, 6.723592608196823e-02, 6.393386027960996e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_perdew_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_perdew", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.493241317214092e+02, 1.432490552759379e+02, 1.349442654911113e+02, 1.238408777543538e+02, 1.094606579005595e+02, 9.166365869559169e+01, 7.101667927156724e+01, 4.916308106508792e+01, 2.887434923530285e+01, 1.341546398814061e+01, 5.344581698738057e+00, 3.371937461082936e+00, 2.611896983030134e+00, 1.644137162492033e+00, 7.067224927276655e-01, 1.620797340543712e-01, -3.111419944354512e-02, -6.711695666318868e-02, -6.690386039008334e-02, -6.392980064548637e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_perdew_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_perdew", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.770986281232637e-05, 8.261598727738699e-05, 9.021178600013700e-05, 1.023558609227704e-04, 1.226881502088373e-04, 1.590577461798409e-04, 2.305817084239078e-04, 3.916228826016720e-04, 8.302824484057471e-04, 2.360909085726044e-03, 8.662480484543700e-03, 2.247075344374897e-02, 3.384624065404505e-02, 6.515660660162406e-02, 2.077200317342882e-01, 1.195481032419201e+00, 1.417130207322695e+01, 4.324022106386007e+02, 4.872595919336758e+04, 3.604674608224600e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_perdew_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_perdew", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.963154542704353e-01, 6.098358637563407e-01, 6.298801262422544e-01, 6.600038799731981e-01, 7.061948986189920e-01, 7.791843694202079e-01, 8.999333133632247e-01, 1.114534141518835e+00, 1.541018967596310e+00, 2.512520066872942e+00, 4.242201100243305e+00, 4.081805422078419e+00, 4.456444653330164e+00, 5.952811437366889e+00, 1.032258876866647e+01, 2.845979511502714e+01, 1.917485647536469e+02, 4.571855820415662e+03, 4.704257376837920e+05, 3.311916018180885e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_perdew_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_perdew", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.339414019926374e-07, -4.904621598783315e-07, -5.847926454928384e-07, -7.528323248634904e-07, -1.081620796993015e-06, -1.817925356100314e-06, -3.820434114808489e-06, -1.102037207638362e-05, -4.953474625380955e-05, -4.005123058670847e-04, -5.391898403138355e-03, -3.628277215513679e-02, -8.232217203267045e-02, -3.050556436562326e-01, -3.100376444499059e+00, -1.026933622953713e+02, -1.443033572640266e+04, -1.343484723129306e+07, -1.705994848789281e+11, -9.336606507974066e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_perdew_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_perdew", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.953733690284517e-16, 2.192845766990286e-16, 2.587842330820347e-16, 3.280757647225622e-16, 4.605271437811903e-16, 7.467105956658625e-16, 1.483342610841356e-15, 3.925067416569794e-15, 1.579676098438869e-14, 1.299020852724656e-13, 6.698882782374889e-12, 4.638790913678900e-08, 2.278897718797629e-06, 1.142779671516492e-06, 4.222922830893342e-06, 7.703620264992848e-05, 5.833886950407250e-03, 2.251935258915919e+00, 7.299841538879919e+03, 5.109617632029464e+08]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
