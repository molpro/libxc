
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mbeefvdw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.778544978209795e+00, -4.681959007542689e+00, -4.546609260438957e+00, -4.359099063229256e+00, -4.103566199306178e+00, -3.763451957143589e+00, -3.325790869371242e+00, -2.789244279264068e+00, -2.175996507981901e+00, -1.525494108525656e+00, -9.144869413704542e-01, -5.934492676682330e-01, -5.749113985078828e-01, -4.907816041177096e-01, -3.343803762817464e-01, -1.900264532226157e-01, -8.879496480908836e-02, -2.887371045798852e-02, -5.966391444544623e-03, -6.595895094404845e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mbeefvdw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.375117541979032e+00, -6.245846434811144e+00, -6.064606345882093e+00, -5.813323985175739e+00, -5.470424315979293e+00, -5.012890106177625e+00, -4.421108798689157e+00, -3.686559996044378e+00, -2.813230346323157e+00, -1.669670857096673e+00, -1.075366846317814e+00, -8.504400666422607e-01, -8.162158518007475e-01, -6.597529468735518e-01, -3.867817846021022e-01, -2.124208475670669e-01, -1.117039080770013e-01, -3.926052261097569e-02, -7.959745607332305e-03, -8.794568057038410e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeefvdw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.945254649228959e-08, 2.459055479043291e-08, 1.512340263119475e-08, -5.047748112098240e-09, -5.325520941773692e-08, -1.872940980830174e-07, -6.468131529191112e-07, -2.796368936037681e-06, -1.982231220758698e-05, -4.248146683119424e-04, -1.134210632292283e-03, -5.200819725597452e-03, -1.205884792222281e-02, -5.106112355052508e-02, -2.235205020974409e-01, -3.428615352191035e-01, -6.180228617360668e-01, 4.400201881799903e+00, 2.195721062313527e+00, 9.791932635294062e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeefvdw_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.390379759658966e-05, 2.647581351474289e-05, 3.069073742496696e-05, 3.801176656237589e-05, 5.185204053526533e-05, 8.146800358274575e-05, 1.575273687137779e-04, 4.142979958925645e-04, 1.766600758869837e-03, 1.810382055445704e-02, 8.862101033551348e-03, 1.080179502565781e-02, 3.270699691301579e-02, 8.347159527023797e-02, 1.105416338251139e-01, 1.575261166429015e-02, 1.871009197387302e-03, -1.037959964083048e-03, -3.372105869240118e-06, -5.182198208439165e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeefvdw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.161767248817350e-02, -1.208498985705915e-02, -1.278722770124149e-02, -1.386182907519502e-02, -1.554749043687640e-02, -1.827755070340699e-02, -2.285389610261553e-02, -3.054216360786072e-02, -3.906718188507323e-02, -5.335451888442710e-02, -4.312453521382313e-01, -1.209401844807792e+00, -1.855048312620507e+00, -1.719989770071787e+00, -4.983024792103686e+00, -4.704642052353981e+01, -1.558947880399819e+02, 4.216524132255958e+02, -8.769439457927207e+03, -7.592191922250855e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeefvdw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.021064762049465e-08, -1.217106252750263e-08, -1.566783821266078e-08, -2.252664715505151e-08, -3.796139550563121e-08, -8.035020225168981e-08, -2.359283847012295e-07, -1.111945271390602e-06, -1.091816389362732e-05, -2.557595454428698e-04, -2.116619920622553e-04, 6.423780854530909e-05, -1.580858774054420e-01, 3.262012509057661e-01, 1.338357507248329e+00, 8.132563589824706e+02, 3.461122086118365e+04, -5.348698399941190e+06, -4.099522306473379e+08, -6.376619696170799e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeefvdw_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.716687082308978e-05, 1.932749447304423e-05, 2.291253753124722e-05, 2.924499864377560e-05, 4.148296390014101e-05, 6.840177735060252e-05, 1.397878667227932e-04, 3.892704489245248e-04, 1.783226744215115e-03, 1.556772669205263e-02, 9.041382144036200e-03, 6.541687585495000e-02, 6.447213391732899e-01, -1.096684588780135e-01, 1.016527461931375e+00, -7.569479538948376e+01, -3.025985683297243e+02, 1.347393978611021e+03, 9.475127866324727e+02, 2.215683625306183e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeefvdw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.263826021072379e-13, 4.166196309358529e-13, 5.916391291567281e-13, 9.790185967645254e-13, 2.016900409930438e-12, 5.685552076660289e-12, 2.511184848040710e-11, 2.123128937486711e-10, 4.915049718299421e-09, 4.988687607025408e-07, -2.571614030457716e-06, 5.023476070351740e-07, -3.392443380846326e-02, 2.867540759254674e-01, 8.986052434563648e+00, -1.604562831822398e+04, -8.661537317416230e+06, 3.478055662178356e+10, 3.149658688260244e+14, 3.922087165516913e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeefvdw_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.985973880507714e-10, -5.983609508717988e-10, -7.776122905864950e-10, -1.132817727701454e-09, -1.943547743827160e-09, -4.213799065728906e-09, -1.277467835648686e-08, -6.302526283285112e-08, -6.773966991543946e-07, -2.324931851704149e-05, 6.660053182409719e-05, 9.693059834877643e-04, 1.148976581072606e-01, -4.554743256980257e-01, -3.987608500206873e+00, 1.516832190277538e+03, 7.245214760075860e+04, -8.952950159275668e+06, -7.278844627501613e+08, -1.284578461468559e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbeefvdw_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbeefvdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.141304577058029e-07, 8.061102636259598e-07, 9.593610584072935e-07, 1.231710630883650e-06, 1.762866519838122e-06, 2.947726891833665e-06, 6.163091025767237e-06, 1.789982175388605e-05, 9.089426482411934e-05, 1.078436412488754e-03, -1.128157904425514e-03, -7.257976191303139e-03, -3.904898425001201e-01, 7.045060311310140e-01, 1.653831938737243e+00, -1.419723809980207e+02, -5.910449243884398e+02, 2.298720194150926e+03, 1.663036379834414e+03, 3.967595774876957e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
