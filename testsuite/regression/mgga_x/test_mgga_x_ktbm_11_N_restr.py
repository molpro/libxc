
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_11_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.947672465692257e+00, -4.849843874484758e+00, -4.712717714935343e+00, -4.522655486913485e+00, -4.263394353844651e+00, -3.917582869701666e+00, -3.470288786617389e+00, -2.914399670934245e+00, -2.256200303145059e+00, -1.537066581553274e+00, -9.232774536052862e-01, -6.143500144023245e-01, -5.733292388526799e-01, -4.924551155639588e-01, -3.401517479175407e-01, -1.872600528545859e-01, -8.082552634301111e-02, -2.576069021817010e-02, -5.337263326275148e-03, -5.907218271609407e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_11_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.169117605918822e+00, -6.033546193439617e+00, -5.843528334846081e+00, -5.580257369621777e+00, -5.221600042001648e+00, -4.745079651562494e+00, -4.135805977552914e+00, -3.403964395124028e+00, -2.610610122356216e+00, -1.832699514164848e+00, -1.140607987975627e+00, -7.844363224221219e-01, -8.169810858705379e-01, -6.358678464460041e-01, -4.115837366659688e-01, -2.297517874363534e-01, -1.022192737908068e-01, -3.284491159626568e-02, -6.797648999447629e-03, -7.511873772751091e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_11_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.500294197460390e-06, -1.027861603468068e-05, -1.150626124998030e-05, -1.352044793972159e-05, -1.701326982281256e-05, -2.355083791362083e-05, -3.708458072111696e-05, -6.858684595782592e-05, -1.479165224549349e-04, -3.254419967106177e-04, -6.923095989698195e-04, -3.826885434342973e-03, -2.140268708983313e-02, -5.282230168194765e-02, -1.510902589506116e-01, -3.944276822526222e-01, -1.175752938936735e+00, -9.271648599966884e+00, -2.317083687541679e+02, -2.054718628405892e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_11_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.117026380893851e-02, 1.140237004831984e-02, 1.174305754357275e-02, 1.224688756279162e-02, 1.299856670537309e-02, 1.412788276055603e-02, 1.581029826881361e-02, 1.810936294390532e-02, 1.983234266256213e-02, 1.550234727359565e-02, 5.328731433420017e-03, 1.132043898557510e-03, 4.386829407679338e-02, 7.097778166794931e-02, 7.346136811761650e-02, 3.667031347833608e-02, 9.092140869395660e-03, 2.277271589768041e-03, 5.117724562128139e-04, 6.236129261708189e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_11_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.650601923843543e-02, -1.731837165160215e-02, -1.855330130647218e-02, -2.047326644392631e-02, -2.354802140524797e-02, -2.864800462070065e-02, -3.734264373591761e-02, -5.163054878817090e-02, -6.926116383453559e-02, -8.959438545613523e-02, -1.697851975665577e-01, -5.750667090546487e-01, -1.003014847236836e+00, -1.475677325737933e+00, -2.233637399904131e+00, -4.268597795465445e+00, -3.211792413120870e+01, -3.651311792634467e+02, -8.709133866861970e+03, -7.146722627417275e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_11_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.768868501896948e-08, 7.755414838375664e-08, 9.421512535537216e-08, 1.243382201149599e-07, 1.842292907965778e-07, 3.196041201465029e-07, 6.783011447242005e-07, 1.766095663912941e-06, 4.135519161754445e-06, -1.890394603739531e-05, -4.264752976928770e-04, -5.698855368646869e-03, 2.692256204854314e-02, 1.423992242659566e-01, -3.810492527083887e-01, -3.003681697433452e+01, -3.188273899840784e+02, 1.556551686393082e+05, 5.638410683110682e+08, 3.727631583890445e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_11_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.136548635178439e-05, -3.438023667874566e-05, -3.921722255038791e-05, -4.734522158686162e-05, -6.190338636446735e-05, -9.025044621289359e-05, -1.507447312785695e-04, -2.814772427839616e-04, -3.950635588500807e-04, 8.624681977528074e-04, 2.931642748213258e-03, 1.950548073338534e-02, 1.068241511872702e-01, 5.847762358765426e-02, 3.662670758705960e-01, 2.251708722190382e+00, 1.638071375054115e+00, -3.846062008042705e+01, -1.245077652248521e+03, -1.131340680430263e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_11_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.235264733131538e-14, -1.171292019837655e-13, -1.646904169545432e-13, -2.682473686133729e-13, -5.382482958573865e-13, -1.447617656280210e-12, -5.828109686105082e-12, -3.988955177652302e-11, -5.068909275056663e-10, -1.138085266501463e-08, -5.111071364535362e-07, -4.347977922951415e-05, -1.569171687798750e-03, -2.226127858147829e-02, -9.145790284963534e-01, -1.311269034504731e+02, -1.371733585029305e+05, -1.682027626217812e+09, -6.085296630509769e+14, -3.102151063096864e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_11_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.843594683444236e-10, 3.435290567206963e-10, 4.506821711764525e-10, 6.653410231844632e-10, 1.162370664887073e-09, 2.577271670842040e-09, 7.959521130095189e-09, 3.809783152813179e-08, 2.982063714890989e-07, 3.163173246064572e-06, 3.750320295916257e-05, 1.261447328136273e-03, 1.860025742940446e-02, 1.445178294961932e-01, 2.704317887038309e+00, 6.804386627281214e+01, 3.035825767517705e+03, 8.499965225643157e+05, 2.646567004219314e+09, 1.852242155981975e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_11_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.887715113136639e-07, -4.459115388798691e-07, -5.431368404378295e-07, -7.212263693481040e-07, -1.083838072098224e-06, -1.942201865887464e-06, -4.447693889852332e-06, -1.401497616993194e-05, -6.049022930729669e-05, -2.513752826363509e-04, -5.695871177948788e-04, -3.121949501777337e-03, -7.664536513438774e-02, -3.262739405691917e-01, -2.234792819568331e+00, -1.092576832862896e+01, -3.815899344568383e+01, -3.159159531719856e+02, -8.722289240901657e+03, -8.385700357263566e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
