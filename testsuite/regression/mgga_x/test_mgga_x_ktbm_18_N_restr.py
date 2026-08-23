
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_18_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.209454785104861e+00, -5.108748878129066e+00, -4.967440788778016e+00, -4.771233573321721e+00, -4.502735863915957e+00, -4.142395246785276e+00, -3.670274679769077e+00, -3.066728625213512e+00, -2.312359536224997e+00, -1.457088021233335e+00, -8.018662436117168e-01, -5.523499922636714e-01, -5.794335907125666e-01, -5.036936302642148e-01, -3.285560455898268e-01, -1.602236619252856e-01, -6.437643250939792e-02, -2.015884461911341e-02, -4.166722786457243e-03, -4.610591389305513e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_18_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.289306341763002e+00, -6.151265288588601e+00, -5.958269131198024e+00, -5.691957615674061e+00, -5.331668150202438e+00, -4.858946172238413e+00, -4.268765169971186e+00, -3.589666925159983e+00, -2.871314971790952e+00, -1.998750686007346e+00, -1.112242585161678e+00, -7.970654657595546e-01, -8.741126878394743e-01, -6.863747070406010e-01, -4.534611177215475e-01, -2.175716732173151e-01, -8.374569958007898e-02, -2.594346401963574e-02, -5.340497471625710e-03, -5.895969501599102e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_18_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.298841467337579e-05, -1.405186115743114e-05, -1.572831107153775e-05, -1.847611163461601e-05, -2.323188696688608e-05, -3.209681535166879e-05, -5.027095174953276e-05, -9.149197052596067e-05, -1.877490517728497e-04, -3.641179466063148e-04, -6.359179101715910e-04, -3.532848901346847e-03, -2.609971321369586e-02, -6.619984062960727e-02, -1.725409864831217e-01, -3.732579025481370e-01, -9.028677729390924e-01, -6.262511021620697e+00, -1.569826259078208e+02, -1.418033231925770e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_18_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.351918717430091e-02, 1.391180476901185e-02, 1.449823798201567e-02, 1.538781623598727e-02, 1.676508806887009e-02, 1.894856909722053e-02, 2.246067665482964e-02, 2.779512910777020e-02, 3.267188728238797e-02, 2.515964198806291e-02, 8.860565434653580e-03, 9.114976649537121e-03, 6.841480347135011e-02, 1.127850279743761e-01, 1.231630156139609e-01, 5.026194493719067e-02, 8.655157970563236e-03, 1.607913466530129e-03, 3.474839076287680e-04, 4.303888266387863e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_18_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.774155272410286e-02, -1.857313841328672e-02, -1.982260018171721e-02, -2.172778066992812e-02, -2.467629663080508e-02, -2.925818012944245e-02, -3.605975268465053e-02, -4.415647903304910e-02, -5.427053743475200e-02, -1.440909196960861e-01, -3.448071772268468e-01, -8.574899720964823e-01, -9.411252235733329e-01, -1.250436663621197e+00, -2.839979810733546e+00, -8.958816838926554e+00, -3.429097229592987e+01, -3.259029938385692e+02, -7.649430589977907e+03, -6.285478605396047e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_18_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.505950520981678e-08, 1.089384663139190e-07, 1.323652252402999e-07, 1.746695356565116e-07, 2.585344775981771e-07, 4.466885232416766e-07, 9.348047378826355e-07, 2.312298076955443e-06, 4.106573475612083e-06, -3.248383762523650e-05, -4.854823795532585e-04, -7.849258765223072e-03, 1.958229934625503e-02, 1.323776514807256e-01, -9.747135356755394e-01, -3.051033568669432e+01, 1.238387217571341e+02, 3.122925122545629e+05, 1.024290653496706e+09, 6.737467791140254e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_18_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.893279027484168e-05, -7.653056904980112e-05, -8.888118199430014e-05, -1.100087947307056e-04, -1.487472860295817e-04, -2.263195015076560e-04, -3.959991459402761e-04, -7.565552790035880e-04, -9.056993105402180e-04, 2.927296984648645e-03, 9.315440971775463e-03, 4.585270111447234e-02, 7.159964103831538e-02, -1.034740987089090e-01, 1.004129668645588e+00, 5.751080095513534e+00, 3.112891749884448e+00, -7.095056954237874e+01, -2.254793109149952e+03, -2.044751082006070e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_18_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.000880350688901e-13, -2.540309505945950e-13, -3.577122917198254e-13, -5.838677006947556e-13, -1.174958713631300e-12, -3.171762978348112e-12, -1.281369079894332e-11, -8.749064093265574e-11, -1.079339883938408e-09, -2.202436479356506e-08, -8.632041865623864e-07, -7.159120047250296e-05, -3.021038440614482e-03, -4.519074595546363e-02, -1.775950150375644e+00, -2.255265161442651e+02, -2.072059562402634e+05, -2.439533593691529e+09, -8.795725211398385e+14, -4.489244184630312e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_18_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.952427493447525e-10, 5.992480298206359e-10, 7.879387146816504e-10, 1.166876727790652e-09, 2.047063321580051e-09, 4.561122699906926e-09, 1.413340761137360e-08, 6.708177513952459e-08, 4.962181068436444e-07, 4.440449138021638e-06, 4.204288142233402e-05, 1.424162424452109e-03, 2.914580244773578e-02, 2.352563824336601e-01, 3.904742237464404e+00, 7.874375382271270e+01, 3.205341066011143e+03, 8.978347966411029e+05, 2.825589014297139e+09, 1.991028598822572e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_18_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.824452738416686e-08, -8.380564573654046e-08, -1.322790348322596e-07, -2.344012586211090e-07, -4.821323882554908e-07, -1.206479564792794e-06, -3.898994002869608e-06, -1.709075632977082e-05, -9.413159404350439e-05, -4.028598444297790e-04, -8.469000756544267e-04, -5.968290319381155e-03, -8.184675368288478e-02, -4.124995046353690e-01, -3.574459647467041e+00, -1.494337259845520e+01, -4.110883121245005e+01, -3.000538204409613e+02, -8.199367355979575e+03, -7.950539303024230e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
