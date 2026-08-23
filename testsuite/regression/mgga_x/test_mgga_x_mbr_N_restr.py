
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mbr_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.204562767490215e+00, -4.127861375693990e+00, -4.020578396710952e+00, -3.872372376657394e+00, -3.671274211011725e+00, -3.405364539051998e+00, -3.066362925797256e+00, -2.654584583378784e+00, -2.180745041538413e+00, -1.665080426583471e+00, -1.141799719720669e+00, -7.045565529635003e-01, -5.569188399397274e-01, -4.755750946884269e-01, -3.609956912174910e-01, -2.387452500100823e-01, -1.424093840854339e-01, -8.240365004412560e-02, -4.974806086262148e-02, -3.167954860497953e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mbr_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.068486888399454e+00, -4.958035295636725e+00, -4.803165604254184e+00, -4.588505198968685e+00, -4.296045362047525e+00, -3.908101532490650e+00, -3.416150517247282e+00, -2.841320183707809e+00, -2.245332541939363e+00, -1.659798457916777e+00, -1.118093925266445e+00, -7.484811176397000e-01, -6.682233502198630e-01, -5.184780886535945e-01, -3.655957789617159e-01, -2.232406147855361e-01, -1.121750961534134e-01, -4.915649965198922e-02, -2.166724002661212e-02, -1.058335130647993e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbr_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.269352954146840e-06, -5.692371356964389e-06, -6.358882858066949e-06, -7.450343328453956e-06, -9.335716160538354e-06, -1.283204068276265e-05, -1.989483248607722e-05, -3.539762638480210e-05, -7.260961198027715e-05, -1.899432916585716e-04, -8.313645779320722e-04, -8.487238323079672e-03, -1.947090368797524e-02, -3.562805914551082e-02, -9.102320165319389e-02, -4.182981616244505e-01, -4.241767541408030e+00, -1.088167949272787e+02, -9.658888379952059e+03, -5.328421444843476e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbr_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.135058608083971e-03, -1.167159985427191e-03, -1.214615157379643e-03, -1.285372993192980e-03, -1.391645476526661e-03, -1.550665732962322e-03, -1.777609691960924e-03, -2.044786354785240e-03, -2.223613110267265e-03, -2.311943261061510e-03, -2.897532647434117e-03, -7.419013776286571e-03, -8.731753664999887e-03, -1.152893828259989e-02, -1.187015240120077e-02, -1.158145793795472e-02, -1.166273745527351e-02, -1.083289615743459e-02, -8.832914808972678e-03, -6.627325834390770e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbr_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.241365162376314e-02, -1.300147197485981e-02, -1.388731012905294e-02, -1.524135764576607e-02, -1.733192287271213e-02, -2.050274341204687e-02, -2.468710875997018e-02, -2.729679016699989e-02, -2.558930167580471e-02, -4.172169880973282e-02, -1.077626368467583e-01, -2.842001497344996e-01, -7.130625698140370e-01, -9.311065539613030e-01, -8.142618207579858e-01, -3.240528632264576e+00, -1.458087954382072e+01, 2.253883132778649e+01, 1.481119611896632e+04, 8.227539940263329e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbr_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.967605106141532e-08, 3.381823635172327e-08, 4.068378684857792e-08, 5.266710720726539e-08, 7.480940823940942e-08, 1.167615647300493e-07, 1.799999186618283e-07, 6.495927464092890e-08, -1.875445559380268e-06, -1.514268579123774e-05, -1.907234815602173e-04, -4.028147390853535e-03, 4.784639593650426e-02, 4.428994547203696e-02, -6.916355651507071e-01, -9.773894599835916e+00, -6.075821437466341e+02, -3.052437312931645e+05, -1.788521315183568e+09, -1.109534171784090e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbr_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.221993947273257e-06, 5.663216962741397e-06, 6.334994423757600e-06, 7.361085615806110e-06, 8.871662166318276e-06, 1.062182754554080e-05, 9.490468626705911e-06, -1.236855625569359e-05, -1.074968691229601e-04, -3.798435529819321e-04, -1.654024360007717e-03, -5.962775240956779e-03, 1.694752909666020e-02, 1.608555722125881e-03, -1.679287037820555e-01, -9.052617093417387e-01, -1.120046898701496e+01, -3.454262958553674e+02, -3.223445302001881e+04, -1.729030269052571e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbr_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.159231218585361e-13, 1.447991840444523e-13, 2.002939641408708e-13, 3.225212713040303e-13, 6.527379909321172e-13, 1.859989006084473e-12, 8.570363034739529e-12, 6.879729317956497e-11, 8.834230135353576e-10, 2.072241183298021e-08, 1.952797954005587e-06, 1.381789366462052e-03, 8.092849625602173e-03, 6.296557589571787e-02, 2.087447001664380e+00, 2.661914809978504e+02, 3.588107067557299e+05, 8.726259506740719e+09, 1.015799620303935e+16, 3.116574914460173e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbr_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.047650533854245e-11, -3.497771072083709e-11, -4.231454146831838e-11, -5.458005749575356e-11, -7.453420445192769e-11, -9.565905853735552e-11, 9.675094483376661e-12, 1.599639206681903e-09, 1.663243514944565e-08, 1.730848986277775e-07, 4.637330301335803e-06, 4.425611963706125e-04, -2.584980448184001e-03, 5.048496670694327e-03, 1.785244195876876e-01, 5.441216713342643e+00, 8.275165334450487e+02, 8.201713681145124e+05, 9.200322958122536e+09, 3.873468486595046e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbr_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.564870493559603e-09, -7.171806225407529e-09, -8.082533456295329e-09, -9.416442810632178e-09, -1.111057648801279e-08, -1.155975326049065e-08, 8.644728090233420e-10, 9.240507786722686e-08, 5.093554399384943e-07, 2.106747026861618e-06, 1.616236282098833e-05, 3.868593631682114e-04, -1.159238054077749e-03, 1.633650777849898e-03, 2.328100999914023e-02, 1.506514450174685e-01, 2.275256240530342e+00, 8.164944821268833e+01, 8.413563311571803e+03, 4.817700333135709e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
