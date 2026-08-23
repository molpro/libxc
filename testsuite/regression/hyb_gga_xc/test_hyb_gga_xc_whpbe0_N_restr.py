
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_whpbe0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_whpbe0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.111875772376490e+00, -1.090404578548218e+00, -1.060311923734074e+00, -1.018614500513624e+00, -9.617770339902955e-01, -8.861048946961648e-01, -7.886982165986132e-01, -6.692227137144965e-01, -5.324332981221266e-01, -3.895623347883239e-01, -2.538628334005154e-01, -1.818299708675031e-01, -1.665218491355122e-01, -1.278272197892897e-01, -7.978700624979009e-02, -3.650058772741126e-02, -8.745718742259849e-03, -2.452081493599876e-04, -1.410969767903263e-06, -1.895316994292588e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_whpbe0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_whpbe0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.448873545746501e+00, -1.419298236001454e+00, -1.377785961074907e+00, -1.320137015863748e+00, -1.241289354573055e+00, -1.135762613768760e+00, -9.988215301854643e-01, -8.288157054097871e-01, -6.315371844746194e-01, -4.319384498249698e-01, -2.804408938825515e-01, -2.621253152138572e-01, -2.353015194118851e-01, -1.922692717539249e-01, -1.251585705836449e-01, -5.298261164364972e-02, -1.339254302277450e-02, -5.539195847670828e-04, -2.846307402511459e-06, -3.791262567495282e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_whpbe0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_whpbe0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.436919009628485e-07, -2.739698780369065e-07, -3.230040530657773e-07, -4.064739825771597e-07, -5.588170169511872e-07, -8.649514190875290e-07, -1.566087068762444e-06, -3.476327374458765e-06, -9.956466307882188e-06, -3.685872929379276e-05, -1.689620021249707e-04, 1.837745635578894e-03, 6.624456597032046e-03, 8.700889217408431e-03, 1.535709810232330e-02, -6.805239033951457e-03, -1.577804400483462e-01, 8.260130667071451e-03, 6.020401501827910e-03, 1.504916946270976e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_whpbe0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_whpbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.346895681003797e-03, -3.511206021868980e-03, -3.762130045361810e-03, -4.155494573810119e-03, -4.795748824643139e-03, -5.895123376577421e-03, -7.930406315962479e-03, -1.210632892666551e-02, -2.165925947297283e-02, -4.145931225155532e-02, -1.060634292450691e-01, -1.663788555218541e-01, -1.568119559899907e-01, -3.656321730526572e-01, -1.521059356136920e+00, -5.684079281209641e+00, -6.561693945857610e+00, -2.235840631378154e+01, -1.045764433302288e+01, -9.830535314784822e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_whpbe0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_whpbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.780270052803915e-09, 1.005891447462651e-08, 1.222266826696228e-08, 1.615126748641618e-08, 2.403619325220703e-08, 4.227310223702325e-08, 9.372039167460723e-08, 2.845418214398217e-07, 1.280669691785140e-06, 7.551399140319120e-06, 1.380646142041621e-04, 3.714732594207904e-03, -4.309695347209826e-03, 4.270139378711073e-02, 9.665403253315445e-01, 2.253758022102976e+01, -1.517383948326634e+02, 3.295411685129374e+03, 1.377436597439955e+05, 2.578578059254265e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_whpbe0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_whpbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.665330115143442e-14, -1.046220741672171e-13, -1.370771877576756e-13, -2.017943333259538e-13, -3.503943763411816e-13, -7.669883512263758e-13, -2.309654054749991e-12, -1.062673542980840e-11, -7.881639375815402e-11, -7.859975784994075e-11, -4.652210026489856e-08, -7.077327398873416e-04, -7.449171671733879e-03, -4.139843372647000e-02, -1.347037505449398e+00, -1.341350917871764e+02, 1.616382003589205e+04, -1.268818414537674e+07, -4.592746248018844e+10, -6.593242752136225e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
