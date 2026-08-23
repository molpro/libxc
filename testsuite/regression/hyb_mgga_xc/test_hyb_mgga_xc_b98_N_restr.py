
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_b98_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.184222490999993e+00, -2.451541279998100e+00, -2.667525329256371e+00, -2.789008676722291e+00, -2.798087577359595e+00, -2.690967171194201e+00, -2.472010575844983e+00, -2.154724879228921e+00, -1.770574719762907e+00, -1.373970029086279e+00, -9.695956596111512e-01, -5.701886882405373e-01, -4.959054150222536e-01, -4.058638627006849e-01, -3.053910420187744e-01, -2.137660223425108e-01, -1.156739227539613e-01, -3.745754179123015e-02, -7.716544616981862e-03, -8.503674904872356e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_b98_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.380633214255300e+00, -4.738899976190943e+00, -4.807667301019998e+00, -4.660887844542216e+00, -4.358138282978317e+00, -3.917693350273260e+00, -3.400538824229430e+00, -2.801399914848344e+00, -2.109176704674106e+00, -1.390873481613758e+00, -8.835172446640497e-01, -7.662316603216356e-01, -6.107800190713839e-01, -5.406855191961437e-01, -3.526777463618885e-01, -1.856422349199155e-01, -1.478395263873565e-01, -5.107347540399040e-02, -1.064582972180235e-02, -1.186004101131452e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.543847752760356e-06, 2.168287998074245e-06, 1.781168608490992e-06, 1.252933051987590e-06, -1.080290133965206e-07, -3.961394251906763e-06, -9.274855709936567e-06, -1.862434193183275e-05, -4.977266704690071e-05, -1.938329957762502e-04, -1.003224572959640e-03, -3.950541154182831e-03, 9.444819475421808e-03, -1.444472567027297e-02, -5.873276532504296e-02, -4.542757187093043e-01, -7.041597611983262e-02, 6.674399208726687e+00, 2.558272107498028e+02, 2.933081022327456e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.296917233637103e-04, -4.948192848397552e-04, -6.408125824402910e-04, -7.590978764593810e-04, -8.617407751394207e-04, -9.706535114759513e-04, -1.124999649078571e-03, -1.355321785424564e-03, -1.737361201206023e-03, -2.368421128039482e-03, -3.315478278307948e-03, -4.912579870775911e-03, 3.364574414412756e-03, -6.274105978062984e-03, -8.906735448795342e-03, -1.162889667392742e-02, -9.205960272472412e-04, -3.344648565598519e-06, -1.250011185340727e-09, -2.031436064904680e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.606772981122581e-03, -2.883029604513365e-03, -2.157839495970337e-03, -1.321851469465172e-03, 1.338753595408168e-04, 2.787423988229903e-03, 4.478699019122161e-03, 5.298295053163529e-03, 6.689120791323898e-03, 9.186544188046090e-03, 1.305076001557550e-02, 1.963981218280322e-02, -1.704500735535576e-02, 2.485804416200836e-02, 3.244274896833604e-02, 4.291560846059864e-02, 8.519637342326023e-04, -1.613248392710056e-03, -5.645813910150272e-04, -8.901886324928093e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.311563763046334e-02, -1.852503863782991e-02, -1.448318753309139e-02, -1.244432619894744e-02, -1.127269960449334e-02, -1.322585776796547e-02, -2.251495289919098e-02, -3.558594235403229e-02, -6.958922413803320e-02, -1.701693809829602e-01, -3.498567339779584e-01, -4.757184775105602e-01, -1.602284581968758e-01, -9.940365420517945e-01, -2.929735066946947e+00, -7.672793564437482e-01, -3.101201491903113e+00, -5.294085978551069e+02, -1.270733238731533e+04, -1.062856527034073e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.443797993357578e-09, 8.403709915345687e-11, 5.404456992959999e-09, 6.804959343324666e-09, -1.228222823510613e-08, 1.572095627701328e-09, 1.962629276344731e-07, 6.707185261418817e-07, 3.924055728783040e-06, 3.829490418897848e-05, 4.738645657458694e-04, 7.299161364988737e-03, -4.376233375288641e-02, 7.805887426194821e-02, 1.264339312901456e+00, -1.680344677206705e+01, -2.363495467427626e+03, 3.868283160559642e+04, 2.428932567331713e+08, 2.344485225300584e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.473104331115716e-06, -3.056972626047259e-06, -1.818024979399942e-06, -1.585009745571667e-07, 2.930573225885830e-06, 7.676592955122459e-06, 5.870067391926728e-06, 1.041430014831959e-05, 3.150545680837305e-05, 5.376173295067567e-05, -5.366483715355379e-04, 1.012334089103608e-03, 2.131382704872639e-02, 2.877298971410725e-03, 4.421345506723903e-02, -1.398046464163999e+00, -5.728697220970330e+00, -6.788041846789281e-01, -2.810535685650854e-02, -3.333041613416207e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.230989236151576e-05, 1.164126895447796e-05, 9.922966525072610e-06, 1.479701595813484e-05, 4.096339640229789e-05, 4.230226531572970e-05, -2.026467661559497e-05, -3.822331868826901e-05, -1.123694145006124e-04, -2.009995867887110e-04, 2.156808153986648e-03, -4.102384013221411e-03, -4.523696209415295e-02, -1.402671743699155e-02, -1.530952955764341e-01, 5.565217083364855e+00, 2.237520041620749e+01, -8.799156132014403e+00, -5.360170480758214e+02, -7.115500983473577e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.096182039812759e-15, -1.534788595219307e-14, -3.348349834538998e-14, -1.284055042433805e-13, -8.655443411537995e-13, -3.822907322668873e-12, -1.516306112730214e-12, 6.384213126003048e-12, 3.909387915715634e-11, 3.103893059214168e-09, 9.412925745777624e-07, -2.462541157875470e-04, -9.039476840281262e-03, -3.057108815316414e-03, 6.111274249683563e-02, 3.607429772523430e+02, 1.650017167319304e+05, 1.823455024259086e+07, 9.761399748855858e+09, 6.413488698949248e+13]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_xc_b98_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.783373323345895e-12, -4.686270853607159e-12, -7.989233258296978e-12, -2.111540512478370e-11, -1.030900506770095e-10, -3.446468031202022e-10, -1.183183772663288e-10, 1.569392726778105e-10, 4.739555353128777e-10, 3.407316714060462e-08, 2.996852613952746e-06, -3.318120091533568e-04, -2.557604590814840e-03, -3.889261777618088e-03, -4.041319580013588e-03, 8.366108738836983e+00, 3.239575598458441e+02, 1.173107947374772e+03, 5.570879636481226e+03, 4.945755590934111e+04]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_xc_b98_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.753616343889317e-10, -8.590934925095416e-10, -9.802035210415775e-10, -1.079939881669713e-09, -5.584541063287791e-10, 1.907491448646097e-09, 6.963987106826493e-10, -2.310820842295750e-09, -1.028618881273306e-08, -1.972575387357542e-07, -1.298440578215513e-05, 1.308944173972366e-03, 5.561070520000340e-03, 8.505350140287199e-03, -1.408177759271781e-01, -3.799281661974224e+01, -1.817283485137149e+03, -3.083889075492297e+05, -1.435220278810753e+09, -1.300021439935769e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.552160890807626e-10, -1.415596104722445e-09, -1.742485547965224e-09, -1.988750080012192e-09, -2.227366471758101e-09, -3.555425203330155e-09, -6.470328430173994e-09, -9.940726568239992e-09, -1.215708094391557e-08, 3.719941656063581e-07, 9.540456131081912e-06, -4.441824093746455e-04, 1.906526697203739e-03, -2.764974581597233e-03, -2.180336895102631e-03, 1.940181712379895e-01, 6.360448106252017e-01, 7.547111442102090e-02, 3.179326145786433e-03, 3.813908079758244e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.986450520214205e-09, 6.310091653894683e-09, 9.835373875884056e-09, 2.282779652072510e-08, 9.264437775197300e-08, 2.382574807996910e-07, 5.657227168546060e-08, -4.225231719011562e-08, -5.746519959934361e-08, -1.590467776071558e-06, -3.836587566697887e-05, 1.758554012742371e-03, -4.359250228774634e-03, 8.519875999400985e-03, 3.687929782848497e-03, -7.786937862525889e-01, -2.545046962238163e+00, -3.020427436905041e-01, -1.272866161334237e-02, -1.527530060784669e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b98_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b98", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.221164673913198e-06, 2.324465128825210e-06, 2.449045471460043e-06, 2.476557889884389e-06, 1.700288241744152e-06, -8.111395296658150e-07, -3.195306586090561e-07, 7.894818309979775e-07, 1.979603037855670e-06, 1.102363455264299e-05, 1.680526480946348e-04, -6.956586769604498e-03, 1.594955825741396e-02, -2.174505193669845e-02, 1.036772863563978e-01, 3.828769385924323e+00, 1.758861648768644e+01, 1.480926982694314e+02, 6.334688405910782e+03, 7.891117212041337e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
