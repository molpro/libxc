
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ms2_rev_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.682544921902053e+00, -4.589766555876253e+00, -4.459788922589825e+00, -4.279795617444336e+00, -4.034656995561684e+00, -3.708671061018336e+00, -3.289711539193675e+00, -2.776735359379262e+00, -2.189378938926299e+00, -1.555396568403277e+00, -9.857714525838314e-01, -6.387198979408328e-01, -5.589877852345816e-01, -4.804827806915824e-01, -3.377564389425808e-01, -2.035590497820899e-01, -1.023785942898130e-01, -3.498122211551594e-02, -7.311774299684409e-03, -8.088275562690884e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ms2_rev_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.117484483591475e+00, -5.991610284508732e+00, -5.815133160588757e+00, -5.570458465394382e+00, -5.236592070834275e+00, -4.791160919318497e+00, -4.215110642476507e+00, -3.499529493510553e+00, -2.640743754564635e+00, -1.561473973175830e+00, -1.070342543292718e+00, -8.130709099527964e-01, -7.579800237564120e-01, -6.171956004882581e-01, -3.625204094198343e-01, -2.132653381708376e-01, -1.189538682283687e-01, -4.572833679110227e-02, -9.739867979440859e-03, -1.078423704256473e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_rev_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.377109216727588e-06, -1.494625208451614e-06, -1.681678955605011e-06, -1.993240487568848e-06, -2.548036944622194e-06, -3.640365192794237e-06, -6.159319091869948e-06, -1.378299520874271e-05, -5.264991310394351e-05, -4.813783050822327e-04, -7.659466557686851e-04, -4.534988396288262e-03, -1.304525044967674e-02, -6.106234407330549e-02, -2.271617870585854e-01, -3.568994166020268e-01, -1.280557144030996e+00, -2.059334387532596e+00, -2.495172145469826e+00, -2.756569372203389e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_rev_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.944791220506589e-05, 6.576598635680957e-05, 7.609611813811324e-05, 9.397407622474930e-05, 1.275711729182557e-04, 1.987129083225116e-04, 3.777126421726281e-04, 9.539488294368486e-04, 3.554775088117698e-03, 1.790733820061359e-02, 1.369352395077143e-03, 1.564670664700243e-03, 1.902731325612457e-02, 8.235746438720302e-02, 9.509298637608733e-02, 5.803775006829196e-03, 1.032326842796085e-03, 5.175606062485540e-07, 3.362088386015542e-12, 8.498875646072498e-20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_rev_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.119505787097796e-02, -1.160422153614876e-02, -1.220787123265766e-02, -1.310349406949358e-02, -1.443192121353421e-02, -1.635080282959009e-02, -1.874437766042037e-02, -1.922723403674017e-02, -1.201082657439729e-03, -5.875100473624854e-02, -2.177606615833041e-01, -6.175676529954377e-01, -1.528370851129117e+00, -1.745290417218106e+00, -4.478632361729487e+00, -1.893202741951196e+01, 1.204363554222386e+00, -3.646341483110248e+02, -1.123896305369718e+04, -9.309538490429720e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_rev_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.083080579665379e-08, -2.533760386125394e-08, -3.350457478193287e-08, -4.985487446940803e-08, -8.757569110876254e-08, -1.939883208344248e-07, -5.926675184014534e-07, -2.810371518865332e-06, -2.355503045507429e-05, -1.683775744975599e-04, -1.292194349969429e-04, 5.964370833544393e-03, -1.065193487609717e-01, 2.855262425020162e-01, 2.632541112372258e+00, 3.140318425871463e+02, -1.495237819258630e+03, -2.440231020257301e+05, -3.488334378075358e+07, -2.855894878936252e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_rev_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.271551879856337e-05, 4.803672292497309e-05, 5.684701116230725e-05, 7.235635412306632e-05, 1.021620287675676e-04, 1.670782105808981e-04, 3.358905142059596e-04, 8.978575442382862e-04, 3.465695292159617e-03, 1.018307257781811e-02, 1.389577221262520e-03, 9.202751942020089e-03, 4.781447205858145e-01, 7.926860156680435e-03, -7.374256372227987e-02, -3.127118577853497e+01, -1.504800836414717e+01, -5.849727187975015e-01, -8.811843401772563e-04, -3.516276879893816e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_rev_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.786788116347412e-13, 1.119769362887964e-12, 1.586186974528918e-12, 2.614411671138531e-12, 5.351302772256109e-12, 1.491568028502794e-11, 6.445022417459738e-11, 5.171948882196514e-10, 9.802605245012772e-09, 3.062958915364118e-07, 1.123597997837125e-06, 1.674679391922434e-04, -2.428546615749634e-02, 8.881699260785050e-02, -3.177948445529373e+00, -6.436041567785722e+03, -1.212713124355342e+05, 7.310679092968082e+08, 1.266879708952026e+13, 8.051190914782372e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_rev_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.240156825564970e-09, -1.486535017495184e-09, -1.928333170199718e-09, -2.801030947784986e-09, -4.782433325180866e-09, -1.027885884733718e-08, -3.061454049285783e-08, -1.443234042581434e-07, -1.278728702825194e-06, -1.267122319459320e-05, 1.078434233267490e-05, 1.491312720109962e-04, 8.530223124834820e-02, -8.381894677515885e-02, 3.264208799597647e+00, 6.338702052969483e+02, 3.871438000882385e+03, 4.275462334844053e+03, 7.081153222145587e+02, 2.081862901419542e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms2_rev_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms2_rev", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.775847557725358e-06, 2.002153778973534e-06, 2.378345686277683e-06, 3.044462342238833e-06, 4.335710805542513e-06, 7.184928213275950e-06, 1.474752995404323e-05, 4.082445659311456e-05, 1.689232527431330e-04, 5.313834322661161e-04, -1.799089049440591e-04, -1.037021003405482e-03, -2.880079214148712e-01, 5.210788819540922e-02, -2.397238975292839e+00, -5.956008304163323e+01, -3.269022667941017e+01, -1.148928191020725e+00, -1.656986821086473e-03, -6.506789369955284e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
