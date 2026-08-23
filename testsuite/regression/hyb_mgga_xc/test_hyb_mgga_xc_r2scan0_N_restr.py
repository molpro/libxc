
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_r2scan0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.689916838000780e+00, -3.615704590093140e+00, -3.511680596932537e+00, -3.367507565675807e+00, -3.170894586723430e+00, -2.908873287563186e+00, -2.570876195695366e+00, -2.154297060217180e+00, -1.671926303560464e+00, -1.152565268710483e+00, -6.563013063877718e-01, -4.802534228560636e-01, -4.797230662652067e-01, -3.995230823093523e-01, -2.736580852939117e-01, -1.496524563539138e-01, -5.944093092802048e-02, -1.615225156452585e-02, -2.246308463711213e-03, -1.066624112707402e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_r2scan0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.839432927986715e+00, -4.739852289365444e+00, -4.600257414704913e+00, -4.406749691403934e+00, -4.142753969846312e+00, -3.790639861313188e+00, -3.335694569723366e+00, -2.773328498269175e+00, -2.116547938973619e+00, -1.386901237961006e+00, -9.035866573406367e-01, -6.715357583705521e-01, -6.780446535980864e-01, -5.375529435860403e-01, -3.580567052593095e-01, -1.755200298045644e-01, -6.985229600632736e-02, -2.608519420782794e-02, -4.073571746673607e-03, -2.104401861555980e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.260229774973160e-06, -2.437346678304196e-06, -2.716261562106009e-06, -3.173627798950127e-06, -3.969360430515989e-06, -5.479229875320264e-06, -8.728535707329369e-06, -1.714020015673656e-05, -4.692504631928332e-05, -2.476043283194216e-04, -4.750073147755994e-04, -7.877576761787437e-04, -6.294305286620668e-03, -1.340378966625846e-02, -6.273023623306911e-02, -6.656761750228295e-01, -3.728004096938530e+00, 6.867515313266431e+00, 2.883077399199314e+02, 1.586466236704036e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan0_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.388150806440457e-03, 3.441323023123902e-03, 3.519119338204043e-03, 3.634241317577702e-03, 3.807998456658053e-03, 4.078658126465700e-03, 4.517640013619324e-03, 5.270731890691050e-03, 6.834366795905247e-03, 1.239331113310299e-02, 6.803714077462773e-03, 4.845107624701667e-03, 2.673798436480846e-02, 2.863533718885184e-02, 4.102481752462177e-02, 7.152228821691997e-02, 3.674916791328460e-02, 1.778466132052163e-03, 6.542619253547291e-05, -6.092004184942041e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.786576786459040e-03, -1.020692795058219e-02, -1.084512773513119e-02, -1.183807059739288e-02, -1.343766930268351e-02, -1.613611133458663e-02, -2.093513130531788e-02, -3.004781072770382e-02, -4.929569564422247e-02, -1.401353303558851e-01, -2.725436973537538e-01, -5.264859234908166e-01, -5.770722340659062e-01, -9.544695188016472e-01, -2.909292102682555e+00, -2.259918404786961e+01, -5.654209951189014e+02, -1.584286628629104e+03, -1.969155356246324e+04, 3.346064525852483e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.747605209098893e-09, 7.442579656524993e-09, 8.594104730753127e-09, 1.063732294540459e-08, 1.459089765767409e-08, 2.260238931295055e-08, 3.356986117691712e-08, -3.643409391166105e-08, -1.827748043033623e-06, -9.567266359002053e-06, 1.525416523595198e-04, -1.105574742164497e-02, 3.971957656061700e-02, 1.088575057210841e-01, 1.468865761091256e+00, 1.644857872386512e+02, 1.066654541087593e+05, 7.420837379542313e+06, 8.053580976848492e+09, -4.030705536070570e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan0_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.260224549780067e-06, 6.023368386079248e-06, 7.237827297361508e-06, 9.260353018001319e-06, 1.291409170973190e-05, 2.070963643873392e-05, 4.290672624974831e-05, 1.279329529062902e-04, 5.776832888196106e-04, 2.322084647108359e-03, 1.227501998564872e-03, 2.907039688448432e-02, -2.397975759213742e-02, -7.549793978855335e-02, -1.541412154798895e-01, -8.268034522849446e+00, -7.909785409383136e+02, -1.691571076330006e+03, -1.366890454351793e+04, 1.436529362365738e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.094950825352099e-13, 2.638174429976830e-13, 3.662792780002588e-13, 5.837452137748187e-13, 1.132748179429135e-12, 2.939922355436748e-12, 1.195034733110913e-11, 9.422179323105913e-11, 1.878453429002557e-09, 8.689627709909667e-08, -3.262209777756104e-06, 3.294923179888479e-04, -9.136497261301738e-03, -1.249190758889629e-07, 8.610234745849259e-01, -1.399301778645378e+03, -2.191726111353927e+07, -4.641790011602554e+10, -5.486212299472374e+15, 2.429619372073329e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan0_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.404343485312394e-10, -2.861016744829238e-10, -3.666323189153963e-10, -5.219990394325499e-10, -8.644563015765143e-10, -1.789739766800220e-09, -5.205308865610082e-09, -2.490708903073557e-08, -2.416921120355275e-07, -3.986334892077874e-06, 4.555674574378621e-05, 6.737711498985362e-04, 2.641653239929922e-04, -2.497911345176358e-02, -8.395862800258536e-01, 1.126123880280900e+02, 1.705532106628723e+05, 1.118467851817513e+07, 1.025320751805350e+10, -8.250066149143300e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scan0_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.773063631375419e-07, 3.120417499628593e-07, 3.697175083681748e-07, 4.717819495531728e-07, 6.699264143143119e-07, 1.110303065840039e-06, 2.303043081852776e-06, 6.631291114469497e-06, 3.109810578444420e-05, 1.821782466008922e-04, -6.191503829644031e-04, -3.437375898516315e-03, 4.725259328783982e-03, 7.130106136493559e-02, 5.821835706677131e-01, -9.675955351905653e+00, -1.337110714082111e+03, -2.859678756522438e+03, -2.301865461688150e+04, 2.544133915276460e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
