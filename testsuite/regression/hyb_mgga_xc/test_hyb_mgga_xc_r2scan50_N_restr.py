
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_r2scan50_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.468798873098163e+00, -2.419309508890931e+00, -2.349938738383520e+00, -2.253791413146505e+00, -2.122667739779831e+00, -1.947912416459455e+00, -1.722464257029036e+00, -1.444561803906538e+00, -1.122731509839321e+00, -7.767049151367728e-01, -4.479972880725425e-01, -3.388185565259700e-01, -3.357278790216520e-01, -2.763256869859376e-01, -1.904483225039891e-01, -1.058507124535535e-01, -4.289917265264884e-02, -1.192380718298624e-02, -1.689686000891963e-03, -8.111623360228154e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_r2scan50_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.238432168809415e+00, -3.172106516368947e+00, -3.079132987648012e+00, -2.950259736141957e+00, -2.774458384455763e+00, -2.540010511319643e+00, -2.237167746206798e+00, -1.862988454868145e+00, -1.426532197186835e+00, -9.448446799739190e-01, -6.227259367056758e-01, -4.751682302474516e-01, -4.629212301035504e-01, -3.718700094801565e-01, -2.550582803221397e-01, -1.337068598404080e-01, -5.478138498361776e-02, -1.986111105492175e-02, -3.137548044350407e-03, -1.715278080226630e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan50_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.427656065799101e-06, -1.538728425644221e-06, -1.713531496239747e-06, -1.999938768306355e-06, -2.497718064851494e-06, -3.441092135639423e-06, -5.468523282266328e-06, -1.070866652038290e-05, -2.922877442953427e-05, -1.531225303088430e-04, -2.837602125754926e-04, 5.756692404591166e-04, -6.712248515907543e-05, -2.958549018320267e-03, -2.023857216622510e-02, -3.091665266069435e-01, -1.863898239621081e+00, 8.384994012042888e+00, 2.659814137191585e+02, 1.847658093732130e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan50_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.157020538063560e-03, 2.190195432562226e-03, 2.238735327264701e-03, 2.310589171967056e-03, 2.419153659372161e-03, 2.588634387215774e-03, 2.864404065337683e-03, 3.339004982485950e-03, 4.325220985243687e-03, 7.792456488601867e-03, 4.448199812481206e-03, 2.686371334327115e-03, 1.085104356363727e-02, 1.137323737484408e-02, 1.797597926820596e-02, 3.740584724676026e-02, 2.093771452087077e-02, 6.802483489559549e-04, -4.211276658610072e-05, -2.375591237858129e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan50_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.511338380579055e-03, -6.791092992860829e-03, -7.215916403678882e-03, -7.877099914182699e-03, -8.942885359205023e-03, -1.074293988590577e-02, -1.395290723746505e-02, -2.009331150900670e-02, -3.337558756242109e-02, -9.548291753531590e-02, -1.924939027519371e-01, -3.371748230400684e-01, -3.162018642384153e-01, -5.852059655402264e-01, -1.872000062716809e+00, -1.246974183097751e+01, -3.507320462527006e+02, -8.349909751857189e+02, -4.117141913938478e+03, 3.531835879533212e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan50_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.575048903381076e-09, 5.066073269561932e-09, 5.886304686303471e-09, 7.359602446044325e-09, 1.026861541024217e-08, 1.643833100144078e-08, 2.713094804016614e-08, 1.524791772629260e-09, -9.485854053025293e-07, -2.256371888170993e-06, 1.229558554098558e-04, -6.223928689645815e-03, 1.920896105088710e-02, 6.194232264375000e-02, 1.126900526760192e+00, 6.176169878546841e+01, 6.515139534109086e+04, 3.269563347658281e+06, -1.913162222812645e+09, -2.166869642254032e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan50_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.994516463985544e-06, 3.440561412293769e-06, 4.147108776992452e-06, 5.315911216660726e-06, 7.411879942296372e-06, 1.188262227661731e-05, 2.482266313678308e-05, 7.527337023060648e-05, 3.430261832159739e-04, 1.331662875831307e-03, 8.921084488600130e-04, 1.653922588605678e-02, -3.643082816518395e-02, -6.639143325705812e-02, -2.546136700493377e-01, -1.271589213774023e+00, -4.804919206646948e+02, -6.824366873904978e+02, 7.601125405173712e+03, 6.753338005614329e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan50_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.252720115018613e-13, 1.577839491960211e-13, 2.190462087584673e-13, 3.488573816529668e-13, 6.758313669752122e-13, 1.750375688156381e-12, 7.120310966413421e-12, 5.643672048827613e-11, 1.127993683206321e-09, 5.129750927205504e-08, -2.699996701422080e-06, -1.042978509500561e-04, -9.343782936623342e-03, -2.810317390675614e-02, -5.609075028312063e-01, -4.525429209077402e+01, -1.336540812938028e+07, -1.992884267087038e+10, 1.778158337833420e+15, 1.240395007964394e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan50_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.471111601351779e-10, -1.750855198961535e-10, -2.243906391213936e-10, -3.194437076793967e-10, -5.287888048007295e-10, -1.094374212192760e-09, -3.186203445164337e-09, -1.527993691543330e-08, -1.479667942547729e-07, -2.420881060584477e-06, 3.486102342921184e-05, 4.680694590666436e-04, 6.127973931348023e-04, 8.542849532435282e-03, -2.157659633129554e-01, -1.772543141185383e+01, 1.033647025273974e+05, 4.500024092224620e+06, -5.715383876943790e+09, -3.866856030071286e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan50_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan50", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.762451407766574e-07, 1.982468784416223e-07, 2.347622013068238e-07, 2.993382362954441e-07, 4.245894073771722e-07, 7.025981796955391e-07, 1.453988016145517e-06, 4.168901660728338e-06, 1.936584011149141e-05, 1.130575384773772e-04, -4.669961770530228e-04, -2.021109526375495e-03, 1.443943565122369e-02, 2.898776528514480e-02, 3.048962743616901e-01, 2.827753230532338e+00, -8.083468255291509e+02, -1.143151273168682e+03, 1.303879678272954e+04, 1.187208110804599e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
