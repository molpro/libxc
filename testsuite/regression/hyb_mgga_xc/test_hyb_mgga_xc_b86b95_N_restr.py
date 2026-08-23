
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_b86b95_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.163068674024431e+00, -3.103980756908188e+00, -3.021254925230581e+00, -2.906807758863686e+00, -2.751173083551093e+00, -2.544699126049518e+00, -2.280334379321815e+00, -1.958536480507376e+00, -1.593156211175648e+00, -1.210085382520600e+00, -8.235695455167927e-01, -5.469792403247072e-01, -4.521083285591642e-01, -3.723465986671308e-01, -2.752309612991790e-01, -1.797765365282867e-01, -9.487273255304923e-02, -3.290062192405287e-02, -6.885682710493514e-03, -7.617072538350785e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_b86b95_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.940592393057387e+00, -3.857934623441369e+00, -3.742030579875318e+00, -3.581314146475608e+00, -3.362009286444148e+00, -3.069589813279682e+00, -2.692502117364717e+00, -2.229824514791787e+00, -1.705908049428448e+00, -1.194256340281855e+00, -7.992587226492899e-01, -6.742330646393464e-01, -5.652787377754959e-01, -4.475462991096411e-01, -2.981461700706872e-01, -1.775179837261077e-01, -1.078231747319496e-01, -4.290804124342066e-02, -9.172104157702438e-03, -1.015597940249647e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b86b95_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.667552063112557e-06, -2.885125705744110e-06, -3.228726564729308e-06, -3.793781729212291e-06, -4.778229255910158e-06, -6.639410067555540e-06, -1.058412570344309e-05, -2.035052774883464e-05, -4.982718240163658e-05, -1.613047819644604e-04, -7.466252268638360e-04, 2.164413695903798e-03, 1.003709421398782e-03, -1.037256271653453e-02, -5.339659790096204e-02, -3.089982558383914e-01, -1.218474020152098e+00, -2.086772186280136e+00, -2.293635745853579e+00, -2.346535541352091e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b86b95_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.375567663333887e-04, -3.424569951505815e-04, -3.492532570038715e-04, -3.584443056041141e-04, -3.702743158825234e-04, -3.839209698517952e-04, -3.954169130397691e-04, -3.935947374396980e-04, -3.585826108127490e-04, -2.919286190495680e-04, -3.934739840274066e-04, -5.911249725741185e-03, -1.215099559354933e-02, -8.595759447999490e-03, -5.100653368791454e-03, -1.941883042677229e-03, -3.394174606475803e-04, -2.122505356273373e-05, -3.221485433594406e-07, -6.299510954859021e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b86b95_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.909910249397593e-03, -9.328013396445459e-03, -9.964258634995459e-03, -1.095633120415240e-02, -1.255749028494121e-02, -1.526840882865073e-02, -2.015755936566061e-02, -2.961905231131278e-02, -4.835622759985386e-02, -7.688370493192283e-02, -1.501238150652879e-01, -2.739194395607950e-01, -3.942628418995544e-01, -8.625578729232031e-01, -2.046042176885979e+00, -1.081410735419194e+00, 1.556404838060190e+01, -3.312557664786054e+02, -1.058344065716440e+04, -8.767282048421636e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b86b95_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.881698138797387e-08, 2.157573395644895e-08, 2.624723476058696e-08, 3.473334164256593e-08, 5.175863419003662e-08, 9.098832708344680e-08, 1.999885601458671e-07, 5.825119044285687e-07, 2.243360768369017e-06, 7.447887893279588e-06, 5.953982944511916e-05, 9.009423531920106e-03, 2.503912680808240e-03, 1.263462079272617e-01, 1.011016953419109e+00, -1.381950516813820e+01, -3.326100748116062e+03, -2.439500354655904e+05, -3.117682588119151e+07, -2.327768677073129e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b86b95_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.617578248211794e-06, -1.829183131956684e-06, -2.174872864687964e-06, -2.769351600943677e-06, -3.864806628696993e-06, -6.072754570443859e-06, -1.103528589734494e-05, -2.357149524392739e-05, -5.858087267398961e-05, -1.689407216062556e-04, -9.018020406182861e-04, -1.440910780837978e-02, -1.730638894015353e-02, -7.371400611027794e-02, -2.381614667286154e-01, -6.950994680341143e-01, -1.626510888596801e+00, -3.216408521515742e+00, -5.568582976990760e+00, -8.117935153904899e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b86b95_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.576013563229963e-15, -7.774482672246326e-15, -9.714273383727362e-15, -1.272957861472418e-14, -1.564092761053723e-14, 1.420534150435220e-15, 2.986971659464932e-13, 5.554850409545410e-12, 1.630075094808076e-10, 1.018319482089412e-08, 1.209486761032201e-06, -2.754497167582093e-03, -1.576616255352355e-02, -4.939624061879926e-02, -4.196446218206638e-01, 2.230383103144524e+02, 3.237205363192223e+05, 7.197161997218926e+08, 1.089888576335961e+13, 6.247306708220972e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b86b95_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.916050179873967e-11, 3.446096601149646e-11, 4.373770127880464e-11, 6.138564941131548e-11, 9.912267028079563e-11, 1.939545178257547e-10, 4.901359636795507e-10, 1.715978639403007e-09, 8.928588069670853e-09, 7.918849669045711e-08, 2.762267028323555e-06, 1.573286494359455e-03, 1.236868686480504e-02, 3.538576891525784e-02, 2.619793796742148e-01, 4.173191644341568e+00, 1.214262748700988e+02, 7.899879129525616e+03, 1.637581142200523e+06, 1.839943426341288e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b86b95_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b86b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.479281294991928e-138, -3.256046006393622e-138, 0.000000000000000e+00, -5.162548007931523e-138, -4.241166238933286e-138, 0.000000000000000e+00, -8.542738895584960e-138, 0.000000000000000e+00, -3.369153414520278e-137, -1.279777249822558e-136, 0.000000000000000e+00, 0.000000000000000e+00, -1.436969208310206e-133, 5.489076604171861e-133, 0.000000000000000e+00, -5.005130872864918e-132, -1.749655682672519e-131, 0.000000000000000e+00, -4.991570423523757e-131, 1.604205400755743e-130]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
