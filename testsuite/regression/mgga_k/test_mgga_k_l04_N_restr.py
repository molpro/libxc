
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_l04_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.175143180367733e+02, 1.051517488945155e+02, 9.388949907941905e+01, 8.328106936336921e+01, 7.239901528231907e+01, 6.049259801224433e+01, 4.743273250206095e+01, 3.392749199032003e+01, 2.147864782232157e+01, 1.183553258273701e+01, 5.474282270785400e+00, 2.253778788540961e+00, 1.630010218462345e+00, 1.096663883624192e+00, 5.621355251474254e-01, 2.378214994738579e-01, 5.094777805693173e-02, 5.240652094562021e-03, 2.246433298734567e-04, 2.746353658885472e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_l04_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.365190378883224e+02, 1.292487761874893e+02, 1.236484538187775e+02, 1.162341212404802e+02, 1.047821337981161e+02, 8.884947722539452e+01, 6.925776534345263e+01, 4.791036938456293e+01, 2.762510442061363e+01, 1.186445797788569e+01, 5.187140851408562e+00, 3.300748789397040e+00, 2.593590906107178e+00, 1.624574486030017e+00, 6.638499060231046e-01, 2.672438293932395e-01, 8.377305724875365e-02, 8.733053922977818e-03, 3.744054317782917e-04, 4.577256097914062e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l04_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.839119931610830e-04, 1.563299743331438e-04, 1.468536877193355e-04, 1.506960041956066e-04, 1.678435289440028e-04, 2.060972501470997e-04, 2.882826527634294e-04, 4.838592066112531e-04, 1.062309500721716e-03, 3.240368232479460e-03, 8.095371632114833e-03, 1.644325750678024e-02, 3.850762250816219e-02, 7.503327383591595e-02, 2.638701907049664e-01, 6.552947936009702e-01, 6.868723307833542e-02, 2.591995231394439e-03, 2.588869023517864e-05, 3.748816592854856e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l04_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.754050281275737e-03, -1.113098458260733e-02, -1.101327684292423e-02, -9.760635944049889e-03, -8.131961838972022e-03, -6.643691323213065e-03, -5.489644899049350e-03, -4.668058826337636e-03, -3.933521311658147e-03, -1.485136277739393e-03, 6.694606351018293e-03, 7.583818527275828e-03, -3.343478055222015e-03, -3.171996386831264e-03, -1.522206687265098e-03, 1.019005664088369e-03, 1.767357628757428e-05, 3.025225057309878e-08, 3.263800118125135e-12, 7.334379043144109e-18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l04_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.717420804587817e-01, 6.854022038166409e-01, 7.594750265342334e-01, 7.962906132151805e-01, 8.287981935087434e-01, 8.916217885530265e-01, 1.021724740138525e+00, 1.301670498092357e+00, 2.041449551160615e+00, 3.561402757670801e+00, 1.273492163636117e+00, 4.307657781922871e+00, 4.608319984990671e+00, 6.443592169846484e+00, 1.480947202239318e+01, -3.603819664441497e+01, 4.945223149798947e+01, 1.806292259693081e+02, 8.739104946371787e+02, 7.903818180213571e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l04_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.817645311152581e-06, -1.714662730979129e-06, -1.620564796244625e-06, -1.764828731447899e-06, -2.265310465943611e-06, -3.538350350053875e-06, -7.254718279093023e-06, -2.229458939969813e-05, -1.252719796646197e-04, -1.000546369831395e-03, -1.844823794161019e-03, -1.950179308987452e-02, -1.165800227222230e-01, -5.043502243391567e-01, -8.455540760666620e+00, 2.363923628705679e+02, 4.056139265405099e+02, 4.385825024477977e+02, 4.704475934454062e+02, 4.846297248895897e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_l04_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.447051789921107e-05, 8.217677231973200e-06, 4.992576753208816e-05, 8.346529586755085e-05, 1.079062524773762e-04, 1.355531440083678e-04, 1.898963608786876e-04, 3.340166309468800e-04, 7.993267927129263e-04, 2.074205088261149e-03, 1.172647489967960e-02, -1.548068882637750e-02, 1.536503072832359e-02, 3.948956472007782e-02, 1.674825944811348e-01, 1.086474248406492e+00, 2.000754572984863e-01, 9.565491097116846e-03, 1.107499457313879e-04, 1.777648396748435e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_l04_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.368540981300699e-12, -1.933977607764177e-13, 1.515892220222995e-12, 2.756850423416745e-12, 5.248521554430459e-12, 1.364268636588181e-11, 5.666202878150253e-11, 4.571229565810370e-10, 8.835189490964769e-09, 2.816909542601058e-07, 1.476813830311958e-05, 5.239749977523589e-04, 3.636331767964871e-03, 5.484117395605585e-02, 5.665729732122970e+00, -1.184346836598855e+03, -2.263353024552204e+04, -6.991366363911551e+05, -7.831964639097206e+07, -5.425779714399460e+10]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_l04_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.768815126334732e-10, -2.766847023570850e-10, -2.857631251721555e-10, -3.767031336853786e-10, -6.378591416296318e-10, -1.360861901724286e-09, -3.886513069899696e-09, -1.684726578945603e-08, -1.295875672763783e-07, -1.937043970807159e-06, -6.520390678117066e-05, -4.108548854193957e-04, -2.259638593659690e-03, -1.394872328329149e-02, -3.254291433958471e-01, -1.079560164816623e+01, -1.976887850311954e+01, -2.925627666508407e+01, -3.892775893779377e+01, -4.667333530368585e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_l04_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_l04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.162117517192344e-08, -5.505900466517738e-09, 1.414148957649980e-08, 4.639988145782812e-08, 9.401486734059566e-08, 1.771896856955997e-07, 3.676872600545563e-07, 9.593139768260529e-07, 3.630205933426822e-06, 2.129591929910062e-05, 9.516673889535788e-05, 6.233571891033111e-04, 1.596406450988195e-03, 4.982094731595067e-03, 3.870105892813823e-02, 1.403426719750474e-01, 1.277410694174792e-02, 4.787606406728721e-04, 4.587978616571674e-06, 6.170349001184138e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
