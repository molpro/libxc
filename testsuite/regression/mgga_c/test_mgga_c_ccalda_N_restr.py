
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_ccalda_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.180998797157020e-01, -1.175098656931561e-01, -1.166632986818886e-01, -1.154500655249541e-01, -1.137144305843195e-01, -1.112380065810363e-01, -1.077186175411979e-01, -1.027479542481948e-01, -9.580639105839087e-02, -8.639742121513858e-02, -7.515586214518184e-02, -6.728759024268981e-02, -6.401356051572259e-02, -5.892116813594958e-02, -5.036264915094507e-02, -3.864262651589247e-02, -2.484783425258910e-02, -1.174260332593087e-02, -3.358560025091710e-03, -4.555973634625633e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_ccalda_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.277425546703642e-01, -1.271422370254157e-01, -1.262806479504995e-01, -1.250453885201946e-01, -1.232771983613306e-01, -1.207521203201795e-01, -1.171589063600753e-01, -1.120739647225770e-01, -1.049513187129480e-01, -9.525185440158444e-02, -8.358501704869702e-02, -7.536143692422870e-02, -7.192417489465444e-02, -6.655852799559506e-02, -5.748199352730099e-02, -4.490048996859790e-02, -2.971425655334096e-02, -1.457546364456100e-02, -4.315135422127157e-03, -5.993073626680452e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_ccalda_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.571712013324739e-135, -5.205535369133162e-135, 1.865439759763752e-135, -3.470909693460296e-135, -6.553431731803473e-135, -4.232053883106065e-135, 1.467769291104896e-134, -9.787918561011483e-135, 4.402767581519552e-135, -4.625285893833408e-135, 6.660215905878241e-135, 2.256044357627913e-134, 1.501232401216195e-133, 5.436475608705807e-134, -1.219844649020775e-131, 1.066127238352519e-130, -1.036246611764031e-129, -3.087994733706373e-128, -5.456956448341664e-128, -6.813576091368953e-124]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_ccalda_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.281234322555346e-131, -6.025746681208752e-132, -2.546947085330776e-132, 0.000000000000000e+00, -8.895597751672211e-132, -1.203784215639058e-132, 7.473459550730785e-133, 1.344525788673577e-133, -1.063690631254893e-132, 2.759965116923058e-133, -2.952728096570722e-133, 2.251517623596673e-133, -2.239615290217584e-132, 1.750839009549686e-132, -7.512125159941142e-132, 2.562608737675273e-132, -8.012317697165165e-132, 2.704344341386711e-132, -2.095776221854383e-132, 2.620264557411325e-133]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_ccalda_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.477774620409495e-05, -5.818693195045975e-05, -6.345836743771690e-05, -7.187042783083637e-05, -8.591514276026259e-05, -1.109328576358254e-04, -1.598189167583845e-04, -2.687937831155541e-04, -5.608715545530386e-04, -1.552974351048727e-03, -5.466992483587993e-03, -1.366768590973045e-02, -2.022618078531379e-02, -3.776201919969042e-02, -1.131996544665042e-01, -5.822888415509768e-01, -5.566286735164374e+00, -1.049701326764461e+02, -4.221519382060530e+03, -4.863190484314538e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_ccalda_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.301881470392117e-134, 4.495650264803593e-135, 3.328429527684735e-135, -3.473462486381171e-134, 4.514387938826183e-135, -1.768192655424975e-134, -1.873239377543345e-134, 1.385736656280633e-134, -2.275333343965695e-134, 2.735514792815345e-134, -1.899300970670607e-134, 9.505653831248334e-134, -3.074584604345223e-133, -3.272636665145650e-131, -9.803277866902988e-130, 4.456477876286632e-128, -1.712922981331475e-125, 3.681499480887473e-122, -1.605588729704950e-120, 1.587967260638999e-114]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_ccalda_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.154269339514647e-134, -1.533189753745825e-131, 9.746787308112685e-132, 1.459097363347688e-131, -3.511810404437868e-132, 9.014623407024641e-132, 2.409352983048510e-131, 2.301700310284078e-132, 2.565122336450476e-133, -8.175640760801755e-135, 8.160377452875753e-134, -4.754909435539799e-133, 3.493100217094179e-133, -8.614204085545265e-132, -1.499271482742376e-130, -2.187753208062652e-129, 5.382584749768573e-129, -8.139921114324564e-126, -4.521601095963857e-124, 2.634704578661514e-121]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_ccalda_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.056048525729413e-139, 3.591624904399367e-139, -6.325411511785725e-140, 4.236950309399775e-139, -1.674375612799534e-139, -7.749122100413937e-139, -1.158177544587853e-138, 1.387150234327799e-138, -5.938035720759466e-139, 3.016410093701555e-137, -4.718462390781305e-137, 2.872166976208854e-135, 2.345896604349847e-133, 4.753536726833791e-132, 3.228896781812322e-129, 5.284834296277597e-127, 2.560577214491427e-123, -5.166431346243934e-119, -2.575964261712833e-113, 5.683921758401175e-104]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_ccalda_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.714640016655924e-136, -4.668007260363976e-136, -6.736310243591327e-136, 2.626017202289040e-136, -1.809813995701541e-136, -9.184144711601703e-136, 7.095569777440794e-137, -1.017585435763694e-135, -1.514507006942148e-135, 7.895260060642428e-137, 2.533939095206572e-135, -2.689995055659396e-134, -6.045943019499982e-133, -2.404979263872882e-131, -9.433347298126854e-130, 3.030533712861613e-128, 1.129705673977261e-125, -1.092331935185529e-122, -1.933269730213304e-118, -5.646354395557634e-113]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_ccalda_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_ccalda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.235813337365596e-133, 1.448496798367488e-133, 6.632674701382229e-133, 3.156701026473364e-133, 9.168708208960394e-133, 3.761825673872058e-133, 6.902570279494405e-133, 1.772329448706079e-133, -1.873709784053334e-134, 1.241857582453901e-134, -7.771870805093050e-135, -1.367007107816146e-134, 2.845482422276951e-133, 1.711461294329871e-132, -6.065508278743563e-130, -5.304903499862355e-129, 1.340421551272561e-127, 3.899084206783478e-126, -8.672618539374848e-125, -6.283770521685856e-121]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
