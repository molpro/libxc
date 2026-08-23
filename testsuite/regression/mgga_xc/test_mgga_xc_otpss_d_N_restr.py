
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_xc_otpss_d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.613225229755837e+00, -4.523093453699765e+00, -4.396800501672370e+00, -4.221860198832307e+00, -3.983495094214912e+00, -3.666274711956493e+00, -3.258033098553654e+00, -2.757025235975289e+00, -2.182729512310434e+00, -1.592860343301419e+00, -1.030811107903990e+00, -6.861192566143631e-01, -6.096147115497770e-01, -5.179229292116011e-01, -3.642566976112359e-01, -2.238637828684485e-01, -1.223864441468979e-01, -4.151053830904895e-02, -8.645469091265038e-03, -9.561827684878081e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_xc_otpss_d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.752539771290203e+00, -5.638566233503449e+00, -5.478847753185160e+00, -5.257571106417709e+00, -4.956003316978610e+00, -4.554542078546301e+00, -4.037562313530211e+00, -3.401535292891046e+00, -2.661426105790603e+00, -1.847641574877943e+00, -1.035062042328318e+00, -9.115397311618330e-01, -8.286431035126927e-01, -6.614468942138720e-01, -4.427520895247988e-01, -2.003891068585156e-01, -1.399179460887515e-01, -5.464324278174315e-02, -1.152078784341583e-02, -1.274901130927241e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_otpss_d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.356320841810941e-06, -8.677694210889796e-06, -9.159646449786674e-06, -9.895018346930115e-06, -1.104436095368465e-05, -1.290186338026721e-05, -1.605399713409713e-05, -2.189269303471866e-05, -3.555578740118450e-05, -9.562283628106584e-05, -1.109750150853847e-03, 2.165297039123815e-04, -4.401200892960106e-03, -2.384539903722215e-02, -9.531173105255765e-02, -6.079868908680535e-01, -1.588709895897101e+00, -1.590443786324067e+00, -1.771383831849834e+00, -1.950933482139479e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_otpss_d_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.721332243704431e-03, 9.404692578086363e-03, 8.959048321706600e-03, 8.337582982660158e-03, 7.482454750431996e-03, 6.329806731592386e-03, 4.829957057020814e-03, 3.008076801351317e-03, 1.050683796625749e-03, -8.902013321722602e-04, 2.525059965603510e-03, 4.298198790241038e-04, 1.595559673843932e-02, 2.579612244210053e-02, 3.929477118310668e-02, 1.146811253052891e-02, 1.952674873695542e-04, 2.019830147610937e-06, 2.054812583748444e-09, 5.973344496461924e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_otpss_d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.918890049891796e-03, -9.233107806291328e-03, -9.701819069088969e-03, -1.041229969233053e-02, -1.151546053659786e-02, -1.329661498674070e-02, -1.640370395778581e-02, -2.305695461419355e-02, -4.752964961896990e-02, -1.109884579952240e-01, -5.339237559900708e-01, -5.261929876740067e-01, -1.189031985002806e+00, -1.096989989974245e+00, -1.464781291844737e+00, -1.593853407359914e+01, 4.922349275198023e+01, -4.765614390351143e+02, -1.335441402544438e+04, -1.100627907336349e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_otpss_d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.381355049972065e-08, -5.015588812748828e-08, -6.083818473063398e-08, -8.007499541140901e-08, -1.181011266604742e-07, -2.033817750022037e-07, -4.273920031517956e-07, -1.100571348853028e-06, -2.054620816865504e-06, -6.486874564555156e-05, 5.247238576851374e-04, 8.305202631348596e-03, -5.669814127341913e-02, 1.715158862827410e-01, -9.507569431963274e+00, 1.062151835624390e+02, -6.605049212804874e+03, -2.018198249773958e+05, -2.481765500774958e+07, -2.021259500823802e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_otpss_d_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.056342345052409e-05, 6.503420987087486e-05, 7.195124190965428e-05, 8.296472588135458e-05, 1.011636026922543e-04, 1.325496793255307e-04, 1.884009475053500e-04, 2.814541122333882e-04, 3.141472777016761e-04, 4.465299310861591e-03, 4.086499459561575e-03, -2.867821800475675e-03, 2.841426312716250e-01, -1.842982979404855e-01, 5.933640259758699e+00, -6.229492379987072e+00, 9.127985552623104e-01, 2.807321554791713e-01, 3.286790304275489e-02, 7.178695894454817e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_otpss_d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.848528687926559e-13, 7.333187254108497e-13, 1.010241973557633e-12, 1.586484517482049e-12, 2.983456761658448e-12, 7.160522299825078e-12, 2.364203315641773e-11, 1.130373134815605e-10, 5.088616059332055e-10, 1.248857297847948e-07, 1.605800535701118e-06, -1.261692870251247e-03, -4.464065855481197e-02, 5.885013272253764e-01, 4.950042051022253e+01, -1.649447016550543e+03, 5.921942816639483e+05, 6.028415110367442e+08, 9.008071292814637e+12, 5.698206957011071e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_otpss_d_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.232402537705833e-09, 1.308871147523602e-09, 1.420305667898852e-09, 1.578944967660014e-09, 1.784472818883100e-09, 1.947072792599260e-09, 1.508020883754232e-09, -1.759810860301909e-09, 1.954548096155672e-08, -5.879034407950412e-06, -6.951753417868752e-06, 4.960427100547778e-04, 7.468530525184899e-02, -9.463439433425460e-01, -2.558099287271410e+01, 1.841151254956429e+02, 3.866614284322318e+00, -1.024426926679087e+01, -3.627315068841535e-01, 7.389891999692050e-01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_xc_otpss_d_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_otpss_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.715573098640518e-06, -4.837313583761967e-06, -5.012013580789778e-06, -5.260380964586895e-06, -5.605074441290704e-06, -6.055232148879015e-06, -6.563165158602007e-06, -7.128470718389736e-06, -1.268132615180382e-05, 2.666828705501004e-04, -6.340332369018340e-05, -3.089430071754045e-04, -1.982952532245066e-01, 1.572707583349509e+00, 1.303302790012073e+01, -1.947037540532818e+01, -8.333953395394587e-01, -2.697325198730742e-01, -3.456844271900004e-02, -7.942618138044798e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
