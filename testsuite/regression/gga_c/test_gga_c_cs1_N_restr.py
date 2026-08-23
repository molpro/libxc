
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_cs1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_cs1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.453561802405087e-02, -5.443159398482225e-02, -5.427581607889706e-02, -5.403812483904621e-02, -5.366511468625965e-02, -5.305426636726778e-02, -5.198694726507044e-02, -4.993610947150725e-02, -4.551977670608145e-02, -3.599513593892297e-02, -2.810640030362295e-02, -3.984653670678103e-02, -3.877814523149763e-02, -3.486957810638116e-02, -2.556666896873819e-02, -7.270400821985510e-03, 8.376574823612133e-03, 5.614353574440370e-03, 1.307772869080596e-03, 1.467446203652390e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_cs1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_cs1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.790418881622413e-02, -5.798062194769972e-02, -5.810338128788102e-02, -5.830895897319816e-02, -5.867258635747621e-02, -5.936186417471824e-02, -6.078040317882578e-02, -6.394947654078134e-02, -7.119563417800992e-02, -8.373902695785265e-02, -8.423290276297035e-02, -4.794935415060126e-02, -4.393703942769859e-02, -4.466976155107702e-02, -4.904085921798967e-02, -4.602073008808356e-02, -6.488159377898181e-03, 6.270637420779844e-03, 1.726345934496252e-03, 1.955728573128153e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_cs1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_cs1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.391209633108887e-08, 2.730956541278283e-08, 3.303493523258616e-08, 4.336785939664906e-08, 6.392712537191943e-08, 1.108768610718880e-07, 2.407581256199818e-07, 7.059036355250350e-07, 2.998059748367153e-06, 1.841819370311596e-05, 1.438544007107217e-04, 3.250808605236239e-04, 3.069900660278122e-04, 1.982392879022922e-03, 1.833129656522961e-02, 2.004211892820655e-01, 1.169258981097922e+00, 2.491962859112251e+00, 3.211882436865240e+00, 3.596806798324408e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_cs1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_cs1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.332038968942129e-05, 4.938986917115373e-05, 5.954445787451282e-05, 7.766275265911913e-05, 1.130466001708718e-04, 1.913362616147603e-04, 3.960153622866579e-04, 1.053018369150736e-03, 3.598778960370125e-03, 1.280497807799313e-02, 3.698032445874863e-02, 1.646329623536282e-02, -1.831045637435793e-03, 5.958219762056993e-02, 5.069624999841351e-01, -1.126563648051061e+00, -4.891361702863517e+01, -7.086955076026661e+01, 1.818017200429558e+03, 1.683769957151939e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_cs1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_cs1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.164580678477121e-10, -6.243290468057321e-10, -8.192277599739195e-10, -1.207960439418312e-09, -2.100508449154459e-09, -4.600773342491724e-09, -1.383424251402925e-08, -6.316516323687531e-08, -4.736339014380873e-07, -5.461075913213871e-06, -1.094962437335260e-04, -1.837859377712008e-03, -2.901119363708086e-03, -3.062003125779133e-02, -5.805615362699237e-01, 1.627720956062485e+00, 3.195362206078541e+03, 2.953144484601868e+05, 4.484004255482102e+07, 3.725882750733710e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_cs1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_cs1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.188233168085846e-15, 4.093019693888181e-15, 5.854348629071359e-15, 9.765610207691871e-15, 2.024578135943465e-14, 5.687764961966881e-14, 2.421036615398098e-13, 1.767921460866210e-12, 2.324863662011123e-11, 1.839652720016820e-10, -8.417247122005291e-08, 8.205129270914524e-05, 6.498336370955106e-04, 6.115838066721722e-03, 1.619925379121297e-01, -1.421066090800166e+02, -3.292062306041651e+05, -9.020283869499296e+08, -1.630598667908486e+13, -1.050527838813014e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
