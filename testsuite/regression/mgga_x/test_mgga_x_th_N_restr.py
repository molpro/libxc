
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_th_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.942434405254373e+01, -1.829902033415634e+01, -1.679595578593194e+01, -1.485143833808979e+01, -1.244758210298829e+01, -9.661786783936083e+00, -6.716683362537875e+00, -3.985591400160156e+00, -1.888489656361566e+00, -6.675238999285326e-01, -2.050701286542132e-01, -1.974681067830763e-01, -6.093064305384275e-01, -5.070410833131082e-01, -1.761697095926482e-01, -3.430670385420875e-02, -3.302597029255999e-03, -1.233291157908028e-04, -1.213474866657548e-06, -1.757897603114461e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_th_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.429811457223477e+01, -5.115345210048574e+01, -4.695320731514852e+01, -4.151933405334560e+01, -3.480183848582357e+01, -2.701698460686873e+01, -1.878685357877415e+01, -1.115457518286150e+01, -5.293610463213792e+00, -1.880591677927548e+00, -5.886469148842821e-01, -5.856333038603954e-01, -1.797357959137156e+00, -1.455300789973773e+00, -4.992612573023526e-01, -9.669325252021985e-02, -9.280429068402443e-03, -3.458373402542361e-04, -3.397415837674458e-06, -4.916782260726952e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_th_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.137336063575559e-04, -1.141007386319914e-04, -1.146395122934650e-04, -1.154276287604889e-04, -1.165654206315180e-04, -1.181558182535813e-04, -1.202346522914414e-04, -1.226371327791654e-04, -1.251170690579000e-04, -1.308948375248796e-04, -1.886678658703373e-04, -1.448873906669423e-03, -3.027703448063790e-02, -6.521248772289591e-02, -7.349100571180657e-02, -8.891587261955146e-02, -1.134090927349358e-01, -1.451178043274484e-01, -1.764355203434836e-01, -2.012356240873233e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_th_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.519137311370838e-01, 8.981702305477430e-01, 8.262801140412089e-01, 7.330427911831230e-01, 6.172964519391703e-01, 4.822412682613603e-01, 3.379642497935226e-01, 2.022540180218241e-01, 9.644609600812486e-02, 3.445613685045788e-02, 1.213672628872157e-02, 2.965550103317359e-02, 4.247153242821609e-01, 5.580429188831766e-01, 2.124250547890878e-01, 4.610578918582483e-02, 5.048507383858158e-03, 2.143097493155547e-04, 2.333724854775829e-06, 3.618882155244608e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_th_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.619982214513947e-01, -5.628892244076278e-01, -5.641929452505948e-01, -5.660912718294621e-01, -5.688117370911566e-01, -5.725677794633777e-01, -5.773671547568203e-01, -5.826336176797037e-01, -5.872630900605385e-01, -5.966727359836319e-01, -6.997292322424953e-01, -1.869309268951428e+00, -8.593905573407454e+00, -1.301062024236192e+01, -1.403058059827002e+01, -1.554235754068523e+01, -1.762246844937454e+01, -1.998981536297356e+01, -2.208844037413239e+01, -2.362139861705112e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_th_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270151507045881e-06, -1.354699191979774e-06, -1.486235367139920e-06, -1.697899741548497e-06, -2.055234552513137e-06, -2.700837194633770e-06, -3.984211742577959e-06, -6.902040187922152e-06, -1.492895969384205e-05, -4.441081722764172e-05, -2.348697909342152e-04, -4.678821685857290e-03, -1.472710392601506e-01, -6.106283880060707e-01, -2.193813006141657e+00, -1.527597409566255e+01, -2.309641364463992e+02, -9.017694561068829e+03, -1.235473221388582e+06, -1.042456277858219e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_th_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.414025402525661e-02, 1.418464933843464e-02, 1.424969443287019e-02, 1.434456795912805e-02, 1.448079827516897e-02, 1.466915044135580e-02, 1.490920813968156e-02, 1.516712452823049e-02, 1.536869652253349e-02, 1.572953380937057e-02, 2.093057945665125e-02, 1.404740696362295e-01, 3.000127823158490e+00, 7.237602269175700e+00, 8.608918143162990e+00, 1.066478216588164e+01, 1.378105606625661e+01, 1.779523822039899e+01, 2.178598597539181e+01, 2.495636844561009e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_th_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
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


def test_mgga_x_th_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.167148771143319e-08, 5.519987985772642e-08, 6.070238983618196e-08, 6.958537339904895e-08, 8.464421722413999e-08, 1.119894198274428e-07, 1.666511326942990e-07, 2.915677669121731e-07, 6.369991596832738e-07, 1.938211013028945e-06, 1.230629049217769e-05, 6.793644582690949e-04, 9.775186501328337e-02, 5.948307445881250e-01, 2.268651230353268e+00, 1.737599142367900e+01, 2.967013482405259e+02, 1.310409109213172e+04, 1.979599706336368e+06, 1.783862247020444e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_th_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_th", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.059396311330573e-04, -5.083150010188522e-04, -5.118011163850713e-04, -5.168980051816701e-04, -5.242403606664659e-04, -5.344323016086004e-04, -5.474670417922079e-04, -5.614234341802574e-04, -5.718098023990696e-04, -5.890333076705365e-04, -8.824305554975863e-04, -1.436619922930165e-02, -1.436720441320263e+00, -5.675007698966775e+00, -7.491190305030503e+00, -1.039416005838804e+01, -1.531638380968697e+01, -2.252104756899791e+01, -3.055305393876580e+01, -3.749375679908982e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
