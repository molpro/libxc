
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_r2scan01_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.656281228904532e-02, -2.651920039790874e-02, -2.645485045820515e-02, -2.635889432212916e-02, -2.621375130133958e-02, -2.599020861151006e-02, -2.563948353903692e-02, -2.508898758281608e-02, -2.433268534420108e-02, -2.490188529722698e-02, -3.134241002797702e-02, -5.591004887084493e-02, -4.770374726770506e-02, -2.987895180217690e-02, -2.394118154210802e-02, -1.807116601266179e-02, -9.671625792300784e-03, -3.360769069844474e-03, -5.338416808432813e-04, -2.543492214354046e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_r2scan01_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.641385797293784e-02, -3.659706129150095e-02, -3.686451132383828e-02, -3.725750564309716e-02, -3.784048987139969e-02, -3.871752225955476e-02, -4.006573204142224e-02, -4.222987012880533e-02, -4.633599463470447e-02, -6.020534923861384e-02, -6.112691645949719e-02, -8.241941159906734e-02, -3.275165694291536e-02, -4.054884770237342e-02, -4.890538771735180e-02, -5.026262243558391e-02, -2.217531408866189e-02, -9.022201888508552e-03, -2.461223298781387e-03, -5.195007821782680e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan01_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.370039686884368e-07, 2.579541533999246e-07, 2.912635860325309e-07, 3.465764722366007e-07, 4.443186537005492e-07, 6.330823343770374e-07, 1.047122037440009e-06, 2.141914370903756e-06, 6.103906820617655e-06, 3.512769467823738e-05, 9.427735954741082e-05, 3.309937564960545e-03, 1.243141845613547e-02, 1.787717021896436e-02, 6.401285614349926e-02, 4.083379191319113e-01, 1.348367366585905e+00, 2.210812200171772e+01, 1.139607387232257e+03, 4.563665899499491e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan01_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.045378349963603e-04, -3.113090255443982e-04, -3.212071299733613e-04, -3.357709153604326e-04, -3.573961576494795e-04, -3.899321590533672e-04, -4.399355031561562e-04, -5.208580606261359e-04, -6.848989875967642e-04, -1.374402691260839e-03, -2.048548851523107e-04, -1.636633853599952e-03, -2.092394180516574e-02, -2.300490810479050e-02, -2.767667871576606e-02, -3.114289397351880e-02, -6.597321508045998e-03, -4.145852101701483e-03, -2.301081164699594e-03, -2.965372516921645e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan01_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.853253746730274e-05, 3.990232378874100e-05, 4.172128061253596e-05, 4.387095752379827e-05, 4.537949353034605e-05, 4.144293433062451e-05, 8.079958473493153e-06, -1.916163893171851e-04, -1.550406449613365e-03, -6.628903063495483e-03, -3.328042283602488e-02, 4.083718861313424e-02, 2.055063887453775e-01, 1.523640647156354e-01, 1.784610151823793e-01, 6.626590021293687e+00, -2.461104752397524e+02, 2.319595420767064e+03, 2.653339464022931e+05, -4.463940829050463e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan01_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.395921580709289e-10, 3.244287941593199e-10, 4.850235914227230e-10, 8.239502565933506e-10, 1.655048037240433e-09, 4.167545527132132e-09, 1.438317093331094e-08, 7.772785810645106e-08, 8.059800510549476e-07, 1.261515027280928e-05, 7.097335771793542e-05, 3.481219857383538e-03, -2.212289290172421e-02, -3.064556161336984e-02, 4.955051200952288e-01, -1.198194234655382e+02, 5.000185905068294e+04, -1.515754740783819e+07, -1.967453276853309e+11, 2.511433609052534e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan01_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.543987982046439e-06, -1.732779994385802e-06, -2.043015639799604e-06, -2.583091333858993e-06, -3.604687416259671e-06, -5.785723069841073e-06, -1.135672897244250e-05, -2.998531541014893e-05, -1.251335137947113e-04, -6.535559910203896e-04, 1.642808701997744e-04, -8.514258208477798e-03, -6.099452329009632e-02, -4.957735884023785e-02, -4.749782894103226e-01, 1.047251459054146e+01, -3.808173507209469e+02, 3.804619575430561e+03, 4.378169046646362e+05, -7.616464071595117e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan01_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.322828488693561e-14, -5.434629262309088e-14, -7.549687423854707e-14, -1.210122004695151e-13, -2.380873498408761e-13, -6.284822921137622e-13, -2.535437661096296e-12, -1.904548734350967e-11, -3.684760884876527e-10, -1.985863500743666e-08, -1.571393903750228e-06, -9.755993677675688e-04, -9.812185699152723e-03, -8.508050452578073e-02, -3.508439197362773e+00, 2.179437328290794e+03, -1.050184863583289e+07, 9.505025342579414e+10, 1.447347375233056e+17, -1.415543935791794e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan01_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.953091045372229e-11, 4.693519335935525e-11, 6.006483915042453e-11, 8.559720469064777e-11, 1.423472344177823e-10, 2.956490635755802e-10, 8.484482200927562e-10, 3.942866204099587e-09, 3.882728262779559e-08, 7.059908726238315e-07, 1.333657274282756e-05, 5.539931863709716e-05, 1.424447026202846e-03, 7.630190101886589e-02, 1.078079511976414e+00, -2.334969630424085e+02, 7.921956300189966e+04, -2.448224527029753e+07, -3.275320083555771e+11, 4.293659901729694e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_r2scan01_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_r2scan01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.575469064359113e-08, -2.919781274992563e-08, -3.496381066983056e-08, -4.528837537240401e-08, -6.565674294160684e-08, -1.119419184519728e-07, -2.417060665908033e-07, -7.451242204766674e-07, -4.003042786791351e-06, -2.490610907633891e-05, -1.600429946942053e-04, 8.124696907377078e-04, 3.361151399814264e-02, -5.616771840445765e-02, -2.703828144409459e-01, 2.365735806506302e+01, -6.042207650154885e+02, 6.218075661263287e+03, 7.392503279451608e+05, -1.302965368322679e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
