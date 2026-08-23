
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_revtm_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.762075295499744e-02, -3.722336568797458e-02, -3.664825626334257e-02, -3.581337018590804e-02, -3.459556890500139e-02, -3.280626779422299e-02, -3.015035460708266e-02, -2.617171139483377e-02, -2.033090316915916e-02, -1.320207139531383e-02, -1.106381028086801e-02, -4.357555565580277e-02, -5.208880595867822e-02, -3.297205778605040e-02, -1.737919212722764e-02, -5.534643389363267e-03, -5.218939306660208e-04, -8.218040344184656e-06, -1.027366810881368e-08, -3.407276455804571e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_revtm_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.119045025324229e-01, -1.107561578216186e-01, -1.091130010401972e-01, -1.067681079530105e-01, -1.034360671900568e-01, -9.873403175631396e-02, -9.216918539997480e-02, -8.310602112050842e-02, -7.046974989554697e-02, -5.306838176709691e-02, -4.642358080510705e-02, -8.837148658615050e-02, -8.232645463815257e-02, -7.533391496528893e-02, -5.486103584502729e-02, -2.514308519166094e-02, -3.093109631399794e-03, -5.387400570703615e-05, -7.046784640547726e-08, -2.408118170383739e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtm_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.653403303017581e-06, 1.733095437266351e-06, 1.853870507558125e-06, 2.040952858779940e-06, 2.339722967170188e-06, 2.837472992518322e-06, 3.716934136594427e-06, 5.407497133026250e-06, 9.112143708161319e-06, 1.958172140825427e-05, 1.016875531833324e-04, 3.486119769298801e-03, 1.075264791393558e-02, 2.104438575371571e-02, 4.572240596392241e-02, 1.207455965982784e-01, 1.903326438399871e-01, 1.104785545291829e-01, 1.749466591289646e-02, 4.709221257997812e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtm_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.965818313680169e-03, -1.926753720265543e-03, -1.870653426547926e-03, -1.790097828692665e-03, -1.674470057706688e-03, -1.508891683411650e-03, -1.274270629272629e-03, -9.541707177511255e-04, -5.662742875339647e-04, -2.259962811815191e-04, -8.083301724830310e-05, -8.769065450776696e-05, -1.317990052361423e-03, -9.557905665199888e-03, -7.209909773934599e-03, -1.951427765635226e-03, -1.670055506486023e-04, -3.240895860429763e-06, -5.720398012605933e-09, -2.631521969775810e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtm_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.990201916363797e-04, -7.413621435252973e-04, -8.065059245047506e-04, -9.096546998606758e-04, -1.079769658572039e-03, -1.377020379683568e-03, -1.942003053611787e-03, -3.169670770253626e-03, -6.546091953100948e-03, -1.879984341923910e-02, -6.698903589409767e-02, -2.370114229559655e-02, 6.074003324005356e-03, -1.355938833667139e-01, -9.050199098743505e-01, -5.778429036641493e+00, -1.447252666718527e+01, -9.074961306469756e+00, -1.413870155982232e+00, -3.684262254384568e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtm_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.282019375776079e-08, 1.446018872608619e-08, 1.718821408439687e-08, 2.202179729982535e-08, 3.139313912468915e-08, 5.204084335108355e-08, 1.065385540462349e-07, 2.923051141652897e-07, 1.214937182115865e-06, 9.358898658503749e-06, 1.923446283660218e-04, 8.666489539370529e-04, -1.200707629869902e-02, 5.975728104369808e-02, 1.135373540362652e+00, 3.522099552937475e+01, 1.048115902807001e+03, 2.142942579650112e+04, 3.983414625990854e+05, 8.064777242430246e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revtm_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.253421832118892e-05, -1.325834810540326e-05, -1.437148222262251e-05, -1.613035118033071e-05, -1.901578244136567e-05, -2.398562113082657e-05, -3.303790003784855e-05, -5.019300204868419e-05, -8.070559239089957e-05, -1.177559417886602e-04, -1.626157558324958e-04, -8.805916304128543e-05, 5.177181574053523e-04, -3.588934626453015e-02, -2.239073544741584e-01, -5.696419115469584e-01, -6.837203159128709e-01, -4.321679387621664e-01, -8.957799961093477e-02, -3.130164703685168e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_revtm_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.981221839491006e-13, -2.376726878766017e-13, -3.088145629178292e-13, -4.500333830976285e-13, -7.731650452784707e-13, -1.680655044048326e-12, -5.103364666848583e-12, -2.482125181282090e-11, -2.340122032355288e-10, -5.717259604717060e-09, -7.798789511585150e-07, -7.118097843434361e-04, -4.402013187489814e-03, -4.095549395043684e-02, -1.759729057871423e+00, -2.741483909344096e+02, -9.310852219906436e+04, -6.085834627906366e+07, -1.332823368749415e+11, -2.063155622807617e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revtm_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.324512625825670e-10, -2.584312477444785e-10, -3.005709944159838e-10, -3.724070162230454e-10, -5.034831823200363e-10, -7.650917066711179e-10, -1.347795102351347e-09, -2.799376026783170e-09, -6.653247036881518e-09, -1.780589956685499e-08, -1.559756752971760e-07, -4.371851646429849e-05, -5.610104419324158e-03, -5.965034122058247e-02, -2.193509776255615e-01, -7.689918456431210e-01, -2.723299935055695e+00, -9.686525167773850e+00, -1.542503364934113e+01, -6.728969636540860e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_revtm_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_revtm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.009992556326057e-06, 1.059958705207395e-06, 1.135338474466491e-06, 1.251108837236566e-06, 1.432907723924549e-06, 1.725347507772546e-06, 2.203295843985984e-06, 2.965736493064527e-06, 4.005727839520576e-06, 4.945733870316679e-06, 8.083759348242245e-06, 6.299973751817613e-05, 6.561371929341434e-03, 1.311836109103922e-01, 3.284346382466216e-01, 5.705823473869593e-01, 6.555403974030076e-01, 4.389766640535154e-01, 9.627396407280349e-02, 3.499086741255585e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
