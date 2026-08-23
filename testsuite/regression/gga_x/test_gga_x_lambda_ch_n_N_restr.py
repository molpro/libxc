
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_lambda_ch_n_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_ch_n", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.303108911160065e+00, -4.221374845178102e+00, -4.106953257952937e+00, -3.948676222390000e+00, -3.733476244529443e+00, -3.448050633931471e+00, -3.082720578387853e+00, -2.638201441121938e+00, -2.133666584479921e+00, -1.605378792206513e+00, -1.078642545280647e+00, -6.643026718698097e-01, -5.627221758478826e-01, -4.719164591697842e-01, -3.486446848586707e-01, -2.269903619736328e-01, -1.185855859928511e-01, -4.085253058816383e-02, -8.546479199662933e-03, -9.454493536154588e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_lambda_ch_n_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_ch_n", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.380436868991229e+00, -5.266085582641479e+00, -5.105774819909259e+00, -4.883557638222038e+00, -4.580499180300984e+00, -4.176783005714588e+00, -3.657054639172090e+00, -3.021398364921808e+00, -2.305835739850031e+00, -1.611206093163732e+00, -1.054103384664381e+00, -7.997992737372838e-01, -7.153973535648082e-01, -5.554439326766126e-01, -3.628403118837747e-01, -2.183726592017117e-01, -1.354389491292368e-01, -5.330264604338596e-02, -1.138364324660240e-02, -1.260582550876841e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_ch_n_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_ch_n", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.830988654999461e-06, -4.142232492808496e-06, -4.633132054207987e-06, -5.438786099006843e-06, -6.837786145625464e-06, -9.468170354894069e-06, -1.499098511306526e-05, -2.844664172319066e-05, -6.801451556714657e-05, -2.129933883534059e-04, -1.022995261071744e-03, -6.895905794840728e-03, -1.296533725753011e-02, -2.741036890301273e-02, -9.612877224568452e-02, -4.513069439148769e-01, -1.537132790211393e+00, -2.630585584468767e+00, -3.175276415008366e+00, -3.507129874285246e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_ch_n_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_ch_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.220073622929702e-02, -1.276044653668709e-02, -1.360971808984185e-02, -1.492804577998453e-02, -1.704071664882583e-02, -2.057608794556390e-02, -2.682402441070226e-02, -3.846026077559479e-02, -5.958120868480722e-02, -8.240406342902576e-02, -1.220461817459386e-01, -5.615735175486580e-01, -6.784230575664225e-01, -1.159855549557776e+00, -2.096984978952522e+00, 2.232222965962724e+00, 2.320740926992767e+01, -4.118355846424925e+02, -1.312241231839487e+04, -1.088189285542514e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_ch_n_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_ch_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.345697048565688e-08, 2.674385213741879e-08, 3.226093575512281e-08, 4.215146513786585e-08, 6.159584033013115e-08, 1.049817393460845e-07, 2.191807738663224e-07, 5.801337591103722e-07, 1.731846291314334e-06, -3.503330018624289e-06, -2.574491426841044e-04, 1.052073489539613e-02, 3.657914397985904e-02, 1.088653492451008e-01, 2.749204654492524e-01, -4.543558168470253e+01, -4.689589688047227e+03, -3.159391578936105e+05, -4.439873845474353e+07, -3.633506931524791e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lambda_ch_n_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lambda_ch_n", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.435126790196676e-14, 6.906698282075827e-14, 9.741559509007861e-14, 1.595024838957725e-13, 3.230476095425187e-13, 8.846991874332833e-13, 3.704083121387451e-12, 2.792977526398270e-11, 4.641285949874998e-10, 2.079656571353005e-08, 2.946991120357297e-06, 3.470633319473835e-04, 2.029989097553343e-03, 2.312462571454515e-02, 1.543550602671867e+00, 5.200884461340896e+02, 4.593781898014965e+05, 9.574988136314632e+08, 1.612415187811527e+13, 1.024338951052832e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
