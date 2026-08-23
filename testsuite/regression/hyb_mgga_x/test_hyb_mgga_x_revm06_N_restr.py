
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_revm06_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.267745210183572e+00, -2.238395148668432e+00, -2.197521242529596e+00, -2.140459678617008e+00, -2.059647978974930e+00, -1.942716543881684e+00, -1.775658285948299e+00, -1.561811561018878e+00, -1.305012537659802e+00, -9.877233816902634e-01, -6.438127969951147e-01, -3.870468538588640e-01, -3.355624805930665e-01, -2.839285953869780e-01, -2.128780124249619e-01, -1.359824026151430e-01, -1.064668641243231e-01, -6.880049529905015e-02, -1.582100267972141e-02, -1.758412268376770e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_revm06_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.247448331105268e+00, -2.194153067697433e+00, -2.134075597179361e+00, -2.075908939582887e+00, -2.030719369851305e+00, -1.987723000116683e+00, -1.859905605984479e+00, -1.556238149287206e+00, -1.318689481541518e+00, -8.974874379145846e-01, -7.191101523945105e-01, -4.982776662777593e-01, -3.923594509380952e-01, -3.027829522032807e-01, -2.129088908145847e-01, -1.508643453859610e-01, -1.433984595633589e-02, -7.773449647632961e-02, -2.093894595692489e-02, -2.344324577731882e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm06_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.151916412251156e-06, -2.343859713402784e-06, -2.650104839799251e-06, -3.160034807237475e-06, -4.060415271547478e-06, -5.783326750890564e-06, -9.481454229347106e-06, -1.893248955552817e-05, -4.901840742161474e-05, -1.712402182225482e-04, -9.374214884566499e-04, -5.584757888914159e-03, -8.792816130554677e-03, -1.891361329402212e-02, -7.419450356278175e-02, -4.451355034846323e-01, -3.049589795326392e+00, -9.418977429658661e+00, -1.240904217986467e+01, -1.373024857165194e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm06_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.405110424633444e-02, -1.430960915740423e-02, -1.431687797620284e-02, -1.368354028246418e-02, -1.184767026156270e-02, -8.599237771145060e-03, -5.545754797604455e-03, -4.966136543062560e-03, -8.404614217947323e-04, 1.587696066093325e-04, 6.685260572515552e-03, 4.513956967467828e-03, -1.250096376210210e-02, -1.454205572931131e-02, 4.847388169638444e-03, 3.595534226083826e-02, -6.368866266546720e-02, -8.561600576766807e-03, -1.058937318655587e-04, -1.644559238822234e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm06_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.757767611475555e-03, -5.896466539887169e-03, -3.167320287695636e-03, 5.503132132116376e-04, 4.473784763792982e-03, 4.706135079310143e-03, -7.004294931797785e-03, -1.925061811039118e-02, 1.019074985115963e-03, -1.113655119603162e-01, 1.470014197625392e-01, 3.249339704313023e-02, -1.385822920349979e-02, -5.457034811318664e-02, -2.636801414524222e+00, -1.046217489085488e+00, 1.287079109018057e+02, 5.174940688993523e+02, -2.263941112770399e+04, -2.022114144112619e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm06_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.693458228100608e-08, 1.961539677688774e-08, 2.411296491810933e-08, 3.213285984040796e-08, 4.770737545679502e-08, 8.213088135769287e-08, 1.771580779627360e-07, 5.388978409590838e-07, 2.060595437778772e-06, 9.211162369166430e-06, -1.133122371544403e-05, 1.139542780395437e-02, 3.025040861340882e-02, 9.954076314758639e-02, 5.811677447675958e-01, -2.750713082436007e+01, -6.450410735502054e+03, -1.120935722429941e+06, -1.800739205867188e+08, -1.480627112140897e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm06_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.872795856341655e-05, -3.949260461029418e-06, -8.259337347505340e-05, -1.940795139434754e-04, -3.265388091063916e-04, -3.962549994299491e-04, -2.164307925929809e-04, -1.203211757585507e-04, -1.115566960986424e-03, 9.878401245597731e-04, -9.178204281946918e-03, -3.856664113531215e-02, -1.535851849139205e-01, -4.008820499765985e-01, 5.961135182960061e-01, 1.271695102868487e+00, -2.961413042536301e+01, -7.194196902289819e+02, -1.092484354561816e+03, -1.260170670304193e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm06_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.846333017827021e-14, 3.643185824696503e-14, 5.193499688762969e-14, 8.635609486926360e-14, 1.786824808088472e-13, 5.029874035999903e-13, 2.177655544222759e-12, 1.723539056513666e-11, 3.086352774713366e-10, 1.526512278495770e-08, 2.416299687445130e-06, 2.509812395130656e-04, 1.268830578755459e-03, 1.472846939564226e-02, 1.089436862571564e+00, 4.636441484674235e+02, 8.911479578978042e+05, 3.642488370751444e+09, 6.802121679053927e+13, 4.338170671302731e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm06_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.703944409887487e-11, -1.039228062447797e-10, -1.312918067339469e-10, -1.770254990599895e-10, -2.561561432526136e-10, -4.066339525770461e-10, -8.417405052072668e-10, -3.274498321259327e-09, -1.555155732515700e-08, -2.202939665038034e-07, -3.706127916994008e-06, -2.178012976438499e-04, -2.052145493079153e-03, -1.234228929586627e-02, -1.618303890363826e-01, -5.524275421488642e+00, -1.969325886218101e+03, -9.182649838252901e+04, -1.137300512443357e+07, -9.956370488038574e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_revm06_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_revm06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.530189175173602e-07, 1.011119509444614e-06, 3.039162111122459e-06, 5.902526941843574e-06, 9.297304998473591e-06, 1.112282647115649e-05, 6.839067714119424e-06, 5.678106149214514e-06, 3.214323868286079e-05, -1.176723186820450e-05, 2.886807085776012e-04, 3.384734739535674e-03, 6.740164221119770e-02, 2.669875955326383e-01, -2.782696873493834e-01, -8.664658321048825e-01, 6.187949737930776e+01, 7.400972245490642e+02, 1.209263763581634e+03, 1.487981205512387e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
