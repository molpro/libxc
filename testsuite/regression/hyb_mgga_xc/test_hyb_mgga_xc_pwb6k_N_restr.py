
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_pwb6k_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.411153809582365e+00, -2.366795633464967e+00, -2.304669014502550e+00, -2.218669600814596e+00, -2.101609048939848e+00, -1.946056426055977e+00, -1.746300744705841e+00, -1.501772122996168e+00, -1.221184154075652e+00, -9.231798083203246e-01, -6.269919154661865e-01, -4.292954622078125e-01, -3.526261532337862e-01, -2.900661822970579e-01, -2.132889939858092e-01, -1.364305051534012e-01, -6.744528732690934e-02, -6.717336410139429e-03, -5.269228592663588e-05, -5.814457769478389e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_pwb6k_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.968246682836902e+00, -2.906952535191251e+00, -2.821073245737224e+00, -2.702131793728099e+00, -2.540122434878493e+00, -2.324688988783843e+00, -2.047998280896433e+00, -1.710256520480836e+00, -1.328542938031950e+00, -9.475032140437170e-01, -6.389196393694334e-01, -5.322123461094338e-01, -4.362953735119731e-01, -3.500452490810678e-01, -2.403142429286184e-01, -1.423043924922547e-01, -1.008862510615321e-01, -2.613837342123207e-02, -2.214914394872738e-04, -2.403128269605121e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pwb6k_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.351182017195117e-06, -2.528740878226862e-06, -2.806934581178491e-06, -3.259191643001299e-06, -4.034054472809289e-06, -5.463938532484451e-06, -8.391494941624550e-06, -1.530637947026574e-05, -3.506883108842589e-05, -1.073071464914474e-04, -4.805716886709650e-04, 2.978860988112775e-03, 1.917190675732060e-03, -6.276417129714726e-03, -3.103489568115027e-02, -1.907221321363560e-01, 7.841210589766188e-01, 3.878206072589154e+01, 4.126515670784578e+01, 3.453283951417134e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pwb6k_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.226964846428948e-04, -3.269644978775100e-04, -3.328324728582951e-04, -3.406548761455243e-04, -3.504667839384235e-04, -3.611770546861238e-04, -3.686168506755101e-04, -3.620383930809724e-04, -3.238687518667765e-04, -2.584769166846159e-04, -3.457006863974455e-04, -5.545669347757470e-03, -1.172997277117937e-02, -7.987630758632536e-03, -4.559640792162641e-03, -1.684230932077707e-03, -2.900115080352166e-04, -1.806507346166229e-05, -2.740557952246207e-07, -5.358950255987504e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pwb6k_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.446184286747327e-03, -6.730181321609193e-03, -7.159767722435054e-03, -7.823738862160017e-03, -8.881599031910853e-03, -1.063933780081389e-02, -1.372849436039800e-02, -1.954155259915102e-02, -3.117525390096189e-02, -5.421917825749283e-02, -1.257462975134304e-01, -1.632622827309900e-01, -2.653667644910659e-01, -5.864238283274827e-01, -1.440730070038412e+00, -2.434713947943496e+00, 9.608759858667457e+01, -2.032010184872272e+03, -2.498194393786692e+03, -1.953404684443050e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pwb6k_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.184103978601257e-08, 1.343649228775771e-08, 1.610299727613290e-08, 2.085673961871133e-08, 3.014074093053065e-08, 5.072888997298704e-08, 1.049515383698226e-07, 2.823515222545725e-07, 1.003279894351343e-06, 3.678686268979489e-06, 7.427513436129121e-05, 6.294625584165305e-03, -4.983622467617320e-03, 7.946972041194499e-02, 6.810287401079074e-01, -1.948097793237018e+00, -8.652159340232402e+03, 3.978308556821757e+06, 6.113113976797163e+08, 3.706155747435602e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pwb6k_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.702451081967323e-06, -1.917432128873100e-06, -2.267147936699155e-06, -2.864919129949028e-06, -3.956987774920588e-06, -6.131303972700465e-06, -1.093419621603302e-05, -2.277853835331583e-05, -5.485236218151003e-05, -1.531019823515951e-04, -8.071282833994258e-04, -1.444041703066780e-02, -1.880419130020446e-02, -7.249538032668944e-02, -2.191386188457480e-01, -6.094457248393539e-01, -1.393120502352482e+00, -2.738300100761171e+00, -4.737322434115499e+00, -6.905872203941175e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pwb6k_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.281476519898384e-14, 5.281245292589533e-14, 7.141905966327517e-14, 1.102422521646393e-13, 2.058995476475879e-13, 5.064478960404932e-13, 1.856371323404165e-12, 1.208873978762774e-11, 1.745127360180858e-10, 6.908904239564618e-09, 6.093407463321244e-07, -2.653458475788080e-03, -1.445201944282626e-02, -4.078805071659569e-02, -4.932531769041290e-01, 9.135141000025777e+01, 5.023043257857217e+05, -1.260621081567476e+10, -2.193191022455437e+14, -1.039068619147848e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pwb6k_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.955151410087000e-11, 3.485642987353767e-11, 4.411613060383707e-11, 6.166232000650906e-11, 9.896269759274775e-11, 1.918805685837031e-10, 4.783107084265741e-10, 1.641283166047352e-09, 8.309332546089801e-09, 7.153084495782177e-08, 2.466355112658176e-06, 1.550006186030584e-03, 1.271935020624495e-02, 3.436709691235663e-02, 2.400700364572572e-01, 3.654683760218470e+00, 1.039795344862706e+02, 6.725436422670373e+03, 1.393126890649945e+06, 1.565227337740128e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_pwb6k_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_pwb6k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, -3.256046006393622e-138, -2.960051208472817e-138, -7.743822011897285e-138, -4.241166238933286e-138, -6.397921113563909e-138, -1.708547779116992e-137, 9.587572716536120e-138, -3.369153414520278e-137, -4.265924166075194e-137, -3.228035394732914e-136, 0.000000000000000e+00, 0.000000000000000e+00, 5.489076604171861e-133, 0.000000000000000e+00, -5.005130872864918e-132, -1.749655682672519e-131, -3.589032619196331e-131, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
