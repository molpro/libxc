
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_mpw1b95_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.040837030428706e+00, -2.984044207914941e+00, -2.904506341071445e+00, -2.794415300210114e+00, -2.644586393726882e+00, -2.445554357737589e+00, -2.190140094005961e+00, -1.877990889564503e+00, -1.521325628692547e+00, -1.146435911990760e+00, -7.775757386471051e-01, -5.277938372086713e-01, -4.360921831362967e-01, -3.584257653386442e-01, -2.625422791688898e-01, -1.693811794383992e-01, -9.552693355074852e-02, -2.471222929458239e-02, -4.752482973716321e-04, -1.165360939103774e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_mpw1b95_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.789117050418930e+00, -3.710645677211527e+00, -3.600668398529796e+00, -3.448285777680892e+00, -3.240584995300734e+00, -2.964085561998413e+00, -2.608291126890968e+00, -2.172527108423221e+00, -1.677074607448000e+00, -1.178396602577067e+00, -7.832034850658506e-01, -6.545361045018530e-01, -5.443056841913846e-01, -4.352483265597885e-01, -2.946488930932292e-01, -1.663018098153684e-01, -9.219091702659205e-02, -6.357817565645194e-02, -1.750623797160856e-03, -4.245680542984712e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1b95_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.544157316971311e-06, -2.740810996391778e-06, -3.049708541250522e-06, -3.553774767749810e-06, -4.422270425449332e-06, -6.038641800366015e-06, -9.391829089014690e-06, -1.747855458164527e-05, -4.138100591750282e-05, -1.335362234012805e-04, -6.260513227931079e-04, 2.636530495970736e-03, 1.145555123373217e-03, -8.045650787506776e-03, -4.075054586628466e-02, -2.948386026654397e-01, -2.337303676000186e+00, 6.909301946794369e+01, 3.042154136599801e+02, 5.692884265120139e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1b95_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
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


def test_hyb_mgga_xc_mpw1b95_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.198747534728356e-03, -8.565583106008835e-03, -9.121656785427024e-03, -9.983967827441990e-03, -1.136509361327532e-02, -1.368021575923200e-02, -1.781238107702649e-02, -2.582032749286371e-02, -4.289114729187984e-02, -8.264819608990083e-02, -2.026179385050554e-01, -2.287660904477401e-01, -3.618245516463769e-01, -7.573830972245669e-01, -1.937430445288047e+00, -5.483109747967594e+00, 5.166523637566615e+01, -1.089573515605178e+03, -1.638912494553988e+04, -2.912272336615098e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1b95_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.421150906601704e-08, 1.619271072001058e-08, 1.952394714854645e-08, 2.551671133312996e-08, 3.738390182176209e-08, 6.428560956112410e-08, 1.378040295830656e-07, 3.955477545118644e-07, 1.626157646976569e-06, 1.012844811638964e-05, 2.082276071759041e-04, 6.236847838979186e-03, -3.230637667958614e-03, 9.440160129357832e-02, 9.250715098384235e-01, 1.147036627035317e+01, -5.413683985005287e+03, 9.824354253723060e+05, 3.907727905858271e+09, 5.384240406530763e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1b95_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
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


def test_hyb_mgga_xc_mpw1b95_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.298238154488592e-14, 4.069528205740192e-14, 5.507151985185586e-14, 8.515183564559001e-14, 1.596720238862653e-13, 3.964219565517307e-13, 1.484282094719790e-12, 1.009569575428619e-11, 1.561106254552105e-10, 6.577006703893455e-09, 5.469408536114655e-07, -2.613575987300829e-03, -1.380659482044169e-02, -4.292465621392756e-02, -5.757991288044219e-01, 7.893239143488145e+01, 5.682109133707536e+05, -8.688491876729158e+09, -1.451114014621455e+15, -1.554495560711138e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_mpw1b95_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
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


def test_hyb_mgga_xc_mpw1b95_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_mpw1b95", 1)
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
