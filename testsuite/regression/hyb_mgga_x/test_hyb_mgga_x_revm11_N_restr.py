
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_revm11_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.695026296687275e+00, -2.619195046642160e+00, -2.514712468074104e+00, -2.374173538143950e+00, -2.192790215830729e+00, -1.975863349175620e+00, -1.753324566028663e+00, -1.590374150178278e+00, -1.515747754986057e+00, -1.309659853385619e+00, -8.429799691860587e-01, -3.945686752314201e-01, -2.748203869514740e-01, -2.045862690502141e-01, -1.439307468975695e-01, -5.615579664061677e-02, -9.708628798327863e-03, -6.199228561596542e-04, -6.029362000984919e-06, -8.185879740158630e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_revm11_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.564415851452852e+00, -4.427903591525843e+00, -4.228453755378483e+00, -3.936008876436760e+00, -3.507364514092286e+00, -2.888816332503266e+00, -2.052030317645388e+00, -1.141712441318345e+00, -7.105998589769286e-01, -9.490949608888122e-01, -6.614545844192333e-01, -5.206914369345222e-01, -2.742872186300868e-01, -1.693341442415139e-01, -1.308650751464449e-01, -7.273979326924247e-02, -8.868751063347379e-03, -1.106983470594914e-03, -1.199903958885341e-05, -1.637071728155116e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm11_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.146510274593600e-06, 3.486627027211583e-06, 3.995875067970105e-06, 4.757793699715539e-06, 5.865479142402906e-06, 7.269404181715727e-06, 7.911179384301624e-06, 1.249214583704529e-06, -4.560341326571178e-05, -2.538629572887040e-04, -1.257041600828396e-03, -9.998016179048559e-03, -1.844505067588563e-03, -5.797671414415518e-03, -5.750135062314798e-02, -1.035015760672401e-01, -5.311987173455098e-01, -2.369279332089677e-01, -1.271223565336435e-02, -1.719554891565541e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm11_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.533754856847962e-02, 1.421755909343414e-02, 1.244251899900042e-02, 9.566498254608348e-03, 4.836980082536435e-03, -2.856274623645007e-03, -1.434113260385478e-02, -2.664170970295824e-02, -2.588949483866635e-02, -6.374992110153169e-03, -2.162714984530841e-03, 5.918186448221965e-03, -5.115756617016304e-02, -7.397477944046772e-02, -2.513738111393980e-02, -5.704659990548640e-03, -1.681879259181723e-03, -2.092325504820200e-05, -1.098905116442908e-08, -2.083823484259236e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm11_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.659170675923912e-02, -1.872182605550699e-02, -2.211463755127089e-02, -2.768238406176125e-02, -3.705655348846564e-02, -5.276294347934712e-02, -7.585948838303333e-02, -8.867431768754265e-02, -7.261361643405899e-03, 1.451471421331832e-01, 7.320840681400394e-02, -7.625228062687966e-01, -2.847313584492340e-01, -6.646346029604322e-01, 1.022169071508084e+00, 2.405749735813045e+00, -1.268840048191148e+01, -1.697070821214162e+01, -4.108891898324062e+01, -4.239048835859933e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm11_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.838332350693753e-08, -3.925628597948085e-08, -3.914436399614691e-08, -3.479892173806856e-08, -1.436902719127295e-08, 6.924310816354218e-08, 4.275457675688557e-07, 2.132576340683899e-06, 1.006740584233237e-05, -1.243888764569391e-06, -1.260289120180659e-03, 2.459904569937713e-02, 6.892343867568589e-02, 2.433648171828674e-01, 6.254088159255570e-01, -4.223199096991848e+01, 5.443785265334543e+02, -3.294410562298074e+04, -2.073019691833882e+05, -2.078427929339351e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm11_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.757970233954663e-04, 3.178443831297073e-04, 3.843275848586843e-04, 4.920184347688947e-04, 6.687570545454993e-04, 9.475981150187052e-04, 1.278936055764631e-03, 1.019690398971068e-03, -2.230529038136864e-03, -5.254773406375540e-03, 7.596636080538488e-03, 8.345406164026736e-03, -7.479558596061095e-02, -1.993418008967684e-01, -1.668424873648276e+00, 6.901556067843275e-01, -2.734066495386362e+00, -2.197843170934720e+00, -1.405749425545888e-01, -1.978953216756632e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm11_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.060507474137723e-13, -1.373181501190516e-13, -1.974642762344251e-13, -3.275683681080097e-13, -6.570227061786231e-13, -1.676207438286941e-12, -5.577367087047594e-12, -1.949079915494070e-11, 2.662387276503610e-10, 3.759889737732506e-08, 6.882845300517783e-06, 7.365418555085496e-04, -2.800125534572862e-04, -2.391304248587974e-04, 1.276320038166129e+00, 2.696733237841299e+02, 7.800316317753300e+02, 8.610698856479047e+07, 6.454847719919346e+10, 5.022355849798444e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm11_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.141995079101504e-10, 5.882424236589283e-10, 5.117874182798041e-10, 2.905110737795018e-10, -3.775161629021918e-10, -2.577775288932356e-09, -1.079686680781417e-08, -4.659513031632841e-08, -2.217504810949476e-07, -9.769409926670649e-07, -1.110581850318322e-05, -1.250264975596550e-03, -2.503508839387512e-02, -1.237146551871952e-01, -6.682935136920009e-01, -2.186568912135622e-01, -1.277389576048225e+02, -2.759028476136727e+02, -8.851879339409174e+01, -1.236231523605826e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm11_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.787565792973652e-06, -9.678161759115191e-06, -1.104099498423886e-05, -1.314145300081505e-05, -1.631194815660178e-05, -2.047436891135956e-05, -2.207512458627346e-05, 4.856566512087240e-07, 1.136540491092854e-04, 2.089422958923647e-04, -9.755554812240818e-05, 4.610251745166143e-04, 6.569857580603963e-02, 3.402978664855711e-01, 1.487367765025176e+00, -4.838535743050322e-01, 3.191854684732585e+00, 1.837501853598096e+00, 1.231384852535495e-01, 1.847183767381063e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
