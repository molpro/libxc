
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ityh_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.110966496479021e+00, -4.028962689061296e+00, -3.914136104234732e+00, -3.755239633703012e+00, -3.539067128148504e+00, -3.252058095692346e+00, -2.884021635779655e+00, -2.434597874456079e+00, -1.920760598457541e+00, -1.376402918533220e+00, -8.443827029241789e-01, -4.844127017665008e-01, -3.931959567075333e-01, -2.979923913358501e-01, -1.699419397528733e-01, -5.596299165822129e-02, -6.561509088118326e-03, -2.303977847685132e-04, -2.059240091764711e-06, -2.784436578799619e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ityh_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.209478081730732e+00, -5.095611473602324e+00, -4.936019290903114e+00, -4.714880869927106e+00, -4.413469555418144e+00, -4.012323526086973e+00, -3.496702469534879e+00, -2.867693846612091e+00, -2.162334654969756e+00, -1.478884243501317e+00, -9.266374066434525e-01, -6.458490071925401e-01, -5.531136758022033e-01, -4.092337226736580e-01, -2.374000550355512e-01, -9.224065577967569e-02, -1.270030216197364e-02, -4.596003916378910e-04, -4.118043998312477e-06, -5.568865965002184e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.593575083102450e-06, -3.880507843733465e-06, -4.332124596488995e-06, -5.071019263193578e-06, -6.348101351473226e-06, -8.731910582416117e-06, -1.367911942927521e-05, -2.549704041744150e-05, -5.900583288868285e-05, -1.728566128241054e-04, -7.224015089010025e-04, -4.240516141655896e-03, -7.400882671621044e-03, -1.328788252644178e-02, -2.992708297929161e-02, -3.885818029402496e-02, -6.775586244998804e-03, -1.206404993803386e-04, -2.658619100316841e-07, -4.387242012686151e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.203500590781845e-02, -1.257948601744334e-02, -1.340454604586955e-02, -1.468272593080970e-02, -1.672480475333575e-02, -2.012581998849127e-02, -2.609101616257406e-02, -3.706728182804849e-02, -5.665895318698153e-02, -7.870937268584362e-02, -1.244670855247352e-01, -4.895309943067496e-01, -6.151909173190429e-01, -9.375708499795411e-01, -1.561063715067535e+00, -3.878638140068689e+00, -1.156414023332977e+01, -1.417583205659278e+01, -1.441402564897752e+01, -1.442408449505701e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.173736933050085e-08, 2.474399103076714e-08, 2.977833804730004e-08, 3.877018490887089e-08, 5.634684442018577e-08, 9.520419760236729e-08, 1.958510272881110e-07, 5.037329920665234e-07, 1.385039730369613e-06, -4.742568607581748e-06, -2.465839616617262e-04, 5.153647123726292e-03, 1.702002518026837e-02, 3.344636402288314e-02, -1.850856620214001e-01, -8.300475421561787e+00, -3.152203475385369e+01, -1.965449689774581e+01, -4.960618240736713e+00, -6.060507761339904e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.881892942078599e-14, 6.197751248582442e-14, 8.729322754270262e-14, 1.426290983279649e-13, 2.879567456448513e-13, 7.847234228740139e-13, 3.259574136886360e-12, 2.424838120322737e-11, 3.928622820293524e-10, 1.666016381934730e-08, 2.089829580245045e-06, 2.211987099895569e-04, 1.222508718551837e-03, 1.211219380658735e-02, 5.445034782117506e-01, 5.256243355311219e+01, 2.181388553184666e+03, 4.436892573332203e+04, 1.350715768017330e+06, 1.281404253265286e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
