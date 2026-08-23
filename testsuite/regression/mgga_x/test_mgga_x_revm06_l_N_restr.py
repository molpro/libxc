
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_revm06_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.829579669874852e+00, -4.763998125854544e+00, -4.666954055338029e+00, -4.522139559325973e+00, -4.305000365131626e+00, -3.982379916925879e+00, -3.521779683719292e+00, -2.914900953490789e+00, -2.201760285645647e+00, -1.491705918681765e+00, -7.868952389330739e-01, -5.236789142392295e-01, -5.772645693965555e-01, -4.920153261674203e-01, -3.308116595303273e-01, -1.531133640163306e-01, -4.247216877961416e-02, -1.761208603894747e-02, -3.891662633778476e-03, -4.317501506565227e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_revm06_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.755475536461114e+00, -4.788619143436401e+00, -4.833028970979884e+00, -4.882238779221096e+00, -4.905614515140849e+00, -4.818695086650100e+00, -4.475974883265891e+00, -3.787964637913934e+00, -2.785186139897024e+00, -1.825327364226234e+00, -1.335031902889721e+00, -8.911373062144562e-01, -8.932061930407753e-01, -6.894407544513206e-01, -4.053150697129578e-01, -2.800866464764088e-01, -5.121625423384935e-02, -2.170214562034123e-02, -5.168231209887444e-03, -5.756366183479943e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revm06_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.993027770150621e-06, -7.582902562494535e-06, -8.511158448360103e-06, -1.002757139187660e-05, -1.263713267339380e-05, -1.746297740736258e-05, -2.731523407538295e-05, -5.025094840168201e-05, -1.127009216070724e-04, -3.141055019400804e-04, -1.146805848449683e-03, -8.641020332967526e-03, -2.166171797675756e-02, -4.613480018665844e-02, -1.457337738139927e-01, -4.697002683014109e-01, -3.015205456807077e-01, 7.091798899363159e-01, 1.072412272792277e+00, 1.138741863067018e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revm06_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.519540409340650e-02, -2.200168306493272e-02, -1.738884047219632e-02, -1.092262262396585e-02, -2.466398016528968e-03, 7.081448306960625e-03, 1.521165678357674e-02, 1.971867438614320e-02, 1.901462436108461e-02, 1.615533887378714e-02, 2.252230748614159e-02, 2.618687874504489e-02, 7.241316448193089e-02, 9.211198519289930e-02, 7.377164494445826e-02, 1.116894503239552e-01, -7.440992838594569e-04, -1.826922010804123e-03, -2.364142667905076e-05, -3.658736656634395e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revm06_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.038551434182339e-02, 2.161088331943044e-02, 2.269680858998158e-02, 2.270329466787644e-02, 1.929650250715975e-02, 8.024223311505266e-03, -1.505246003288477e-02, -4.728742667260278e-02, -1.158696070077953e-01, -4.313194696475064e-03, -4.845134197600789e-02, -3.050270866939872e-01, -1.159660030342101e+00, -1.954762328399395e+00, -2.527595267568651e+00, -5.080319472465059e+00, -4.345684281367095e+01, -9.360662818860634e+01, -5.845063024443203e+03, -4.967886034696323e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revm06_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.833182917362347e-08, 5.465309105999045e-08, 6.502869493728191e-08, 8.302460562023254e-08, 1.167581715122559e-07, 1.872649810618844e-07, 3.571006723849168e-07, 8.118523594948028e-07, 1.556768653220948e-06, -1.994104752555930e-05, -8.673976064370090e-04, 4.577288949365926e-03, 4.792142680993321e-02, 1.360219212328408e-01, -1.196402034615087e-01, -8.309920442246761e+01, -1.419841689114839e+03, 1.428816344327861e+05, 2.634170713980428e+07, 2.128839028437778e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revm06_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.235853147014806e-04, -8.769162007473163e-04, -9.394351276995004e-04, -9.957432066909255e-04, -1.000765895551503e-03, -8.633249044336464e-04, -5.135846869177040e-04, -6.096243856075435e-05, 1.232527208514269e-03, -1.292272991225509e-03, 3.053386274088744e-03, -2.018027607141906e-02, 1.220882947416879e-01, 2.996585001439999e-01, 3.958749103262787e-01, 8.585014115684686e+00, 3.623990179889145e+01, -1.696394397933620e+02, -2.724190224733663e+02, -3.130888158314817e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revm06_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.635949407469445e-14, 1.100943782976938e-13, 1.558929992715625e-13, 2.563146862225380e-13, 5.206517216700646e-13, 1.423514442305819e-12, 5.887560197397635e-12, 4.299950604513537e-11, 6.688255306267259e-10, 2.659257571325695e-08, 2.843523972213673e-06, 3.786090632088302e-04, 2.950293182186588e-03, 3.386739983299376e-02, 2.031242851344288e+00, 4.564037720083994e+02, -6.860142510946299e+03, -6.819732486796582e+08, -1.375033256518380e+13, -8.677570120220031e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revm06_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.053486166707392e-10, -1.042753127451133e-10, -9.611695686705487e-11, -6.544806552905771e-11, 3.753816748202772e-11, 3.884040031277249e-10, 1.714693416864855e-09, 8.199900753184943e-09, 5.395180829216437e-08, 6.521534276416960e-07, 2.362699253464124e-05, 8.108511389328061e-04, 5.727144067953869e-03, 3.554462060739956e-02, 5.361907412382116e-01, 3.525937050473863e+01, 1.487911373198197e+03, 1.136803674460446e+05, 1.841530007439631e+07, 1.624308845685029e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revm06_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revm06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.148707301793156e-05, 2.272645394243841e-05, 2.413057610083824e-05, 2.525655904640489e-05, 2.485492375341702e-05, 2.037804568672280e-05, 9.479813601658188e-06, -6.768271459377666e-06, -5.218200020527070e-05, -3.252016786866674e-05, -5.217771009312904e-04, -3.501162183176821e-04, -7.814057939587575e-02, -3.150811016670974e-01, -8.264345882333901e-01, -1.253568522869161e+01, -4.465578946095004e+01, 1.204184055378913e+02, 2.233991595511158e+02, 2.750132702023715e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
