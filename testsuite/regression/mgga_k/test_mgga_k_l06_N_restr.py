
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_l06_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.210367743556847e+02, 1.066150947194837e+02, 9.438575979496682e+01, 8.342283477254517e+01, 7.243080956623366e+01, 6.049294803182275e+01, 4.742242821213429e+01, 3.390634926523661e+01, 2.142399371616311e+01, 1.169219129415661e+01, 5.415616023647567e+00, 2.253939564030171e+00, 1.630020560082363e+00, 1.096413535018786e+00, 5.588822508128032e-01, 2.477568088719338e-01, 6.289281124562261e-02, 6.524025328999475e-03, 2.796833805312809e-04, 3.419240752584602e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_l06_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.317135772301247e+02, 1.259727680147449e+02, 1.221850003558301e+02, 1.157680509372919e+02, 1.046953282395346e+02, 8.888652491905783e+01, 6.935003068624562e+01, 4.808408110557303e+01, 2.803618210276876e+01, 1.246916240967597e+01, 4.920753057372442e+00, 3.303391883637888e+00, 2.593582863872151e+00, 1.626743570519435e+00, 6.852986124188040e-01, 1.588264637737014e-01, 1.008351144769011e-01, 1.086875026139855e-02, 4.661385766928361e-04, 5.698734586897370e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l06_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.703905699310466e-04, 1.490752063201294e-04, 1.440187359996016e-04, 1.493751334754079e-04, 1.666760492767752e-04, 2.043806069195392e-04, 2.846739031964330e-04, 4.720613774616985e-04, 9.978266840368916e-04, 2.903576099342508e-03, 7.757506580266096e-03, 1.585064330743576e-02, 3.847909379350202e-02, 7.407784464030216e-02, 2.383176999834976e-01, 1.253903513310287e+00, 2.236728562806602e-01, 7.884683170318265e-03, 7.462204915335450e-05, 1.033634186531422e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l06_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.251315147438343e-02, -1.331736564709705e-02, -1.232699283226027e-02, -1.040716373630214e-02, -8.407600614609514e-03, -6.737589506781823e-03, -5.487959938901390e-03, -4.592631523396942e-03, -3.791733862592494e-03, -1.536923037855249e-03, 8.899177372180028e-03, 7.735418328432852e-03, -3.361031470533479e-03, -3.134369690213870e-03, -1.468373133484205e-03, 3.009810196881491e-03, 9.582006624117590e-05, 1.577629884400105e-07, 1.662605038312691e-11, 3.657457256927431e-17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l06_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.860121699303426e-01, 7.119238382170666e-01, 7.831143273845967e-01, 8.063184768372696e-01, 8.292601405394847e-01, 8.860257355791176e-01, 1.007813224948486e+00, 1.259796250980755e+00, 1.866070769257987e+00, 3.800814027740904e+00, 5.258390549870237e+00, 4.260391975782113e+00, 4.607430761943861e+00, 6.348536777234231e+00, 1.311139159067600e+01, -1.374387325748922e+01, 4.369534794758800e+01, 2.242927834164342e+02, 1.088022852557773e+03, 9.840341252479006e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l06_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.005643702655067e-06, -1.590967340973197e-06, -1.504685096710886e-06, -1.679733280772550e-06, -2.173452577025977e-06, -3.375010595388400e-06, -6.775192684262519e-06, -1.973986333336706e-05, -1.008579753896003e-04, -1.088759263452215e-03, -9.281883505959033e-03, -1.469728342683728e-02, -1.158586855869014e-01, -4.667163668405717e-01, -6.654561936727371e+00, 4.538957497437410e+01, 1.168510475982213e+03, 1.119327387676673e+03, 1.083870584459625e+03, 1.025577827386237e+03]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_l06_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.108700305002478e-05, 2.554068363363440e-05, 7.039663614858180e-05, 9.833182124978899e-05, 1.162840951515512e-04, 1.388043255625216e-04, 1.876990806505663e-04, 3.203905272811235e-04, 7.711761384523702e-04, 2.448835741071334e-03, 2.002974649342434e-03, -1.577612072816193e-02, 1.554826118025753e-02, 3.813216633348120e-02, 1.675190953206935e-01, 2.168411333913395e+00, 1.049229587828332e+00, 4.768066684517971e-02, 5.345579438734340e-04, 8.337402635894241e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l06_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.916567890722449e-13, 9.119999656585006e-13, 1.437874093750472e-12, 2.175624118670224e-12, 4.123602742003751e-12, 1.077877832066524e-11, 4.370239899613653e-11, 3.315825157447006e-10, 6.207146789635148e-09, 3.501835763111321e-07, 3.265142382571279e-05, 5.553799630861614e-04, 3.395055273399306e-03, 4.259394524914269e-02, 4.304484502475246e+00, 1.153766500837317e+02, -4.600374178703246e+04, -8.314286863221271e+05, -2.810081300834613e+07, 2.555612182495203e+10]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_l06_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.521164428142175e-10, -2.156203968912000e-10, -2.381270613512012e-10, -3.485410511963900e-10, -6.163878464991550e-10, -1.321948330609625e-09, -3.744748494579485e-09, -1.606122929570346e-08, -1.254150789480368e-07, -2.130302063659876e-06, -5.824220919073350e-05, -5.391229103785217e-04, -2.259207252217176e-03, -1.344684845743073e-02, -3.199751543759643e-01, -2.636694260748458e+01, -1.001369731760534e+02, -1.394259760631927e+02, -1.768098109772615e+02, -2.030196641102905e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_l06_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.030556535453038e-08, 2.298585997996228e-09, 2.681215982436092e-08, 6.009649708289855e-08, 1.067919284948375e-07, 1.889395296334778e-07, 3.782969101482563e-07, 9.613445478343356e-07, 3.551797596571436e-06, 2.211702922614107e-05, 1.482151775860520e-04, 6.806651695922648e-04, 1.628117298038419e-03, 4.965324373149538e-03, 3.743384607160490e-02, 4.160169034013823e-01, 5.971450382261839e-02, 1.988205866206090e-03, 1.634948061264503e-05, 1.815453449997024e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
