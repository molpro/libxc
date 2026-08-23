
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_m11_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.847823325412509e+00, -5.801501120076381e+00, -5.719978278153580e+00, -5.573770454413011e+00, -5.310690742275611e+00, -4.848723015993684e+00, -4.092898629946132e+00, -3.021760789398357e+00, -1.896154745391829e+00, -1.286404753628862e+00, -8.529245158701289e-01, -6.666039454017049e-01, -5.653779861499841e-01, -4.653302360758814e-01, -3.855638076969215e-01, -3.090598071631007e-01, -2.359544709747993e-01, -1.580918889931325e-01, -3.559154326664186e-02, -3.950935950368039e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_m11_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.602707261789756e+00, -3.035340922962553e+00, -3.629873615972930e+00, -4.412077518895257e+00, -5.350231658902037e+00, -6.254603894128448e+00, -6.656868474829578e+00, -5.895021867716676e+00, -3.516429480556150e+00, -1.632704744147204e+00, -1.112101846078306e+00, -9.583366288303973e-01, -9.002996123605119e-01, -5.166682960905877e-01, -2.944400323975262e-01, -3.027072594174461e-01, 4.778755248432306e-02, -1.739535884659889e-01, -4.708383931895205e-02, -5.267383121342085e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m11_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.137655612745885e-05, -5.186397786850730e-05, -5.237327602244983e-05, -5.269639387358878e-05, -5.231938866983653e-05, -5.026274710594314e-05, -4.574157760471118e-05, -4.215197695769517e-05, -3.889947253487449e-05, 3.329470639951029e-05, -4.818104013202007e-04, -2.511768234411711e-04, -8.275325812456005e-03, -2.210931787437177e-02, -2.279090388122390e-01, -5.002942951761491e-01, -1.898653802652452e+01, -6.828031068113995e+01, -8.215469969395117e+01, -9.072725310121737e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m11_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.119824793551490e-02, -5.374078076864771e-03, 3.018065727686607e-03, 1.479143262263540e-02, 3.028557593761221e-02, 4.796282765960927e-02, 6.253939066904596e-02, 6.470457873706059e-02, 3.391687683692288e-02, -2.795353297342180e-03, 6.850279658574762e-03, 4.924152242564732e-03, 6.578418353935507e-02, -2.658848793519500e-02, 3.573924629747080e-02, 1.478080546389668e-02, -6.371834094198171e-02, -6.707139423783144e-03, -7.985406089017091e-05, -1.237234300561619e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m11_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.275840123214193e-01, 1.337965674579725e-01, 1.414186049393166e-01, 1.490943566916823e-01, 1.519842482922348e-01, 1.373386762487928e-01, 8.050707404736628e-02, -5.974546962915029e-02, -3.491295196346051e-01, -9.830139189601661e-03, -2.026213682120459e+00, 2.633794864141533e+00, -1.618396139969062e+00, -2.153497029153808e+00, -3.814353143587018e-01, 4.502680338354527e+01, -4.748617668807175e+02, 2.428128031214013e+03, -4.995422793259959e+04, -4.542462553904902e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m11_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.044523917308244e-07, -5.707198262356473e-07, -6.758950290462099e-07, -8.472507484708386e-07, -1.130881256146015e-06, -1.584893274347849e-06, -2.171740258297567e-06, -2.625691174947435e-06, -9.617474908001968e-06, 3.529095786740825e-05, 2.207582945291784e-03, 9.297573694773553e-03, 1.940209028485382e-01, 9.553867036513031e-01, -1.372494804848244e+00, -3.598225088365352e+02, 3.768638689456839e+04, -8.171477405555482e+06, -1.148565296298184e+09, -9.399635647363923e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m11_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.050606376648545e-03, -2.161908729169151e-03, -2.298393008953808e-03, -2.435716407521720e-03, -2.489105497817630e-03, -2.247983436310357e-03, -1.351535899176041e-03, 1.065137031738617e-03, 8.820265336502568e-03, -4.586754848947370e-03, 2.968673171058515e-02, -2.959909701998968e-01, 4.602130429757868e-02, -1.148457261868196e+00, 3.817224505953727e-02, 1.229407157195630e+01, -3.476621122027540e+01, -5.730007182563464e+02, -8.355049739975899e+02, -9.613336237596810e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m11_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.219133379747477e-12, 1.443560888684326e-12, 1.831961691067953e-12, 2.554720790018572e-12, 4.033300726868293e-12, 7.434665307584838e-12, 1.649297216913279e-11, 4.829279460426032e-11, 6.413270147115236e-11, -4.166087269497418e-08, -1.476114088174819e-06, -2.861206685774570e-04, 6.357360647695806e-04, 1.359930487261077e-02, 6.278176390500277e+00, 2.195600309440363e+03, -5.861616013871044e+05, 2.481519106343758e+10, 4.171540635811089e+14, 2.649898253228723e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m11_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.852235646423772e-08, 2.050261811652631e-08, 2.359674102518228e-08, 2.853684212099821e-08, 3.651631588174276e-08, 4.898148247909888e-08, 6.515957353627033e-08, 8.210931772051395e-08, 3.222225419265104e-07, 1.824802512601695e-06, -3.425670477730000e-05, 3.835179612316464e-04, -6.911640002756364e-02, -5.019721388353775e-01, 3.344510386634134e-01, 6.984128984087106e+00, -2.717046005239033e+03, -2.821944012009215e+04, -1.919048779067191e+05, -2.183390613960782e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m11_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.218439582837531e-06, 9.045189655516773e-06, 9.753065964321080e-06, 9.625729668165739e-06, 6.832321613390629e-06, -2.256749403875136e-06, -2.207515988412459e-05, -7.288141489163961e-05, -3.021756849897653e-04, 5.953267857456703e-07, -5.724578724332259e-04, 2.502420157717786e-02, 7.480562896373441e-02, 1.740508697227555e+00, -5.283941695747241e-01, -9.934778369379199e+00, 6.456182176918490e+01, 5.648527937878249e+02, 8.930916939451995e+02, 1.096706072374868e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
