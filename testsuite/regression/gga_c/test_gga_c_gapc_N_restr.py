
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_gapc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gapc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.794964194596094e-02, -5.707100612265423e-02, -5.582443341256461e-02, -5.406662720192584e-02, -5.161015273071558e-02, -4.822379052941497e-02, -4.365528530797485e-02, -3.771416339413436e-02, -3.050549699533176e-02, -2.307386967515566e-02, -2.012963534167025e-02, -4.522976148785481e-02, -5.338256605519286e-02, -3.954223463593541e-02, -2.534261396385789e-02, -1.195750451797791e-02, -2.522492365627440e-03, -4.523755549361947e-05, -5.036673309290839e-08, -4.570144009388769e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_gapc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gapc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.234322014129344e-01, -1.220050011060480e-01, -1.199514024711669e-01, -1.169983376318358e-01, -1.127594698673787e-01, -1.067028063288030e-01, -9.814541596923763e-02, -8.637793360547066e-02, -7.122984622606263e-02, -5.493391421072388e-02, -4.934670242151570e-02, -8.424771183703773e-02, -8.092357691720986e-02, -7.438829589919316e-02, -5.716787086850418e-02, -3.344406334419844e-02, -1.026080874426132e-02, -2.612165938930989e-04, -2.636797587321193e-07, -2.069640935262442e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gapc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gapc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.190881391113574e-07, 7.596834947044938e-07, 8.217497241481165e-07, 9.191237205687153e-07, 1.077527032703589e-06, 1.348555223833596e-06, 1.845987594494248e-06, 2.854219472941496e-06, 5.238070466564005e-06, 1.295567889829401e-05, 7.792841464058959e-05, 2.945768216625979e-03, 8.500711965123846e-03, 1.202156410244842e-02, 2.868321558287003e-02, 1.100408657529010e-01, 5.041897020968623e-01, 4.542847941015771e-01, 5.084385182549797e-02, 2.756329584922603e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_gapc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gapc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.390881513561689e-04, -5.774303982738246e-04, -6.366542507278405e-04, -7.308989208087839e-04, -8.872086988711295e-04, -1.161538500117540e-03, -1.680836506973870e-03, -2.766312781114050e-03, -5.353988122534651e-03, -1.284407075706416e-02, -4.216629250150988e-02, -4.138002398198073e-02, -3.416881812483201e-03, -1.075047010798778e-01, -6.311862429465129e-01, -3.773811481953697e+00, -2.502978563494476e+01, -3.937175204196178e+01, -4.133895178171906e+00, -1.933165091079776e-01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_gapc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gapc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.760566346209612e-09, 6.582791006875620e-09, 7.964743916955080e-09, 1.044784298319747e-08, 1.535168424054745e-08, 2.641237592209018e-08, 5.643919027939806e-08, 1.618372047872398e-07, 6.924486540608849e-07, 5.304831077350513e-06, 1.141387639199937e-04, 2.282608929943611e-03, -7.931081181840461e-03, 2.654268494164172e-02, 5.344953868219975e-01, 1.924063777637324e+01, 1.651478260157904e+03, 8.352167626116512e+04, 1.002483530957775e+06, 3.334051831882229e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_gapc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_gapc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.319585319381330e-13, -1.592775198055834e-13, -2.086010689306352e-13, -3.069242556289330e-13, -5.327727195542350e-13, -1.167899432721446e-12, -3.550158828880301e-12, -1.700983238529593e-11, -1.543089977819394e-10, -3.651694104810677e-09, -5.233476042026358e-07, -7.520960519134226e-04, -7.847087821314241e-03, -4.093567718768022e-02, -1.131493655822706e+00, -1.843148555389257e+02, -1.680234896485202e+05, -2.324990013065729e+08, -3.309299834091440e+11, -8.575075556936287e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
