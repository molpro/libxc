
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_b88b95_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.169343313663859e+00, -3.110093369125793e+00, -3.027116060605767e+00, -2.912268187551063e+00, -2.755974063198447e+00, -2.548373891382982e+00, -2.282014371587797e+00, -1.956620702341635e+00, -1.585185892637212e+00, -1.195613338436789e+00, -8.114667631481945e-01, -5.475990999314517e-01, -4.529142090577389e-01, -3.724887718164159e-01, -2.730574655843417e-01, -1.774012051241871e-01, -1.073970585190860e-01, -6.545931868517377e-02, -4.209606306632554e-02, -2.921395817542044e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_b88b95_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.950928644075471e+00, -3.869008618193990e+00, -3.754192791221517e+00, -3.595094358327740e+00, -3.378213793478476e+00, -3.089434013805611e+00, -2.717693775921416e+00, -2.262036738219895e+00, -1.743015966624860e+00, -1.218570190637752e+00, -8.058144193184161e-01, -6.785203806138295e-01, -5.658237035649920e-01, -4.518372736774742e-01, -3.045449065521806e-01, -1.678427027501710e-01, -7.339685859441260e-02, -2.942264276069584e-02, -1.149930078871517e-02, -4.778035382922437e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b88b95_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.646413645776698e-06, -2.851707462384278e-06, -3.174312914278432e-06, -3.701082869602219e-06, -4.609581722911402e-06, -6.303006839770822e-06, -9.824994708376092e-06, -1.835740851513906e-05, -4.380426211998274e-05, -1.437558673440810e-04, -6.861842723289869e-04, 2.442122130080439e-03, 8.069786235560782e-04, -8.848786636942794e-03, -4.463665154206797e-02, -3.438480790477499e-01, -4.684228457156114e+00, -1.302974000166460e+02, -1.215085077486545e+04, -7.225558099565427e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b88b95_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
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


def test_hyb_mgga_xc_b88b95_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.569005588894960e-03, -8.953728380973341e-03, -9.537201549441853e-03, -1.044267830668250e-02, -1.189469172081168e-02, -1.433373446609494e-02, -1.870444540292120e-02, -2.724801989727913e-02, -4.586804643856949e-02, -9.202313204090572e-02, -2.322096134015651e-01, -2.468192447726216e-01, -3.822484512353942e-01, -7.967697558174155e-01, -2.081304785694240e+00, -7.154917745532002e+00, -2.282472255416348e+01, 7.950224487394654e+01, 1.325270514142477e+04, 7.488020219040545e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b88b95_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.495271096119328e-08, 1.704736442068497e-08, 2.057306321177382e-08, 2.692571783064742e-08, 3.953710605232273e-08, 6.824688526999774e-08, 1.473248022665393e-07, 4.292620780651329e-07, 1.836306376876500e-06, 1.298682727295141e-05, 2.745483908416684e-04, 6.649658034167670e-03, -2.123704591392911e-03, 9.941635034842775e-02, 1.014246411068136e+00, 2.018626696828841e+01, 6.837658549357138e+01, -8.548261487670700e+05, -7.260454685668496e+09, -2.455450975712236e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b88b95_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
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


def test_hyb_mgga_xc_b88b95_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.319821515635346e-14, 4.095949402470211e-14, 5.541989460317812e-14, 8.565900272238823e-14, 1.605068549731642e-13, 3.979378348527881e-13, 1.485883726870612e-12, 1.005329455771056e-11, 1.539168504703802e-10, 6.356975029826302e-09, 5.032202139391394e-07, -2.613116780107325e-03, -1.380994434220719e-02, -4.292510758975057e-02, -5.869532788572600e-01, 6.231866291392359e+01, 4.125919063268007e+05, 1.406482387781296e+10, 1.742021878559005e+16, 5.795229501181597e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_b88b95_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
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


def test_hyb_mgga_xc_b88b95_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_b88b95", 1)
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
