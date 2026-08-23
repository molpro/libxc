
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_cf22d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.173804498039055e-01, -1.168728262187189e-01, -1.159438464477273e-01, -1.141420981528231e-01, -1.104755199250507e-01, -1.028515880691368e-01, -8.736343962317891e-02, -5.798546221821238e-02, -5.839879684533353e-03, 5.766045024348371e-02, 3.341136867184066e-02, -8.022139746479481e-02, -4.750412305848094e-02, -3.305020903366813e-02, 1.246920525452248e-03, 9.809523169236832e-03, -2.843048548098267e-02, -2.186632089668666e-02, -6.592095672420536e-03, -8.965113926827628e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_cf22d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.181800078045713e-01, -2.181680881182164e-01, -2.188453435620636e-01, -2.208937851217639e-01, -2.249954013774941e-01, -2.305230917411129e-01, -2.330962402595994e-01, -2.295837396462055e-01, -2.300739789347632e-01, -1.168908859226432e-01, 2.483007714270844e-02, -9.832041751522508e-02, -1.128045155087369e-01, -1.190140098922508e-01, -1.046032562635228e-01, 1.677899413866716e-02, -6.707223308517297e-03, -2.512484553918107e-02, -8.441344162715586e-03, -1.179249559559367e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_cf22d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.168088439087955e-06, 2.215237574356299e-06, 2.277219825561088e-06, 2.352134677371491e-06, 2.424766146443470e-06, 2.446944882175359e-06, 2.343477374880295e-06, 2.546250520662891e-06, 9.030638373284994e-06, 5.776527378034414e-05, 4.293576037302037e-04, 1.374735935088704e-02, 7.273599730134734e-03, 1.233778162117474e-02, 1.011543812888554e-01, 4.549346910684212e-01, 4.169429047657717e-01, 1.390669203597914e-01, 1.667665678834861e-02, 4.151558575542900e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_cf22d_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.401758817145124e-03, -2.206765465228835e-03, -1.902149309597491e-03, -1.423500728109324e-03, -6.818504186469986e-04, 4.028396789915777e-04, 1.779937877966385e-03, 3.144138782954002e-03, 3.972157017092207e-03, 1.109386413194369e-03, -4.485920347341726e-03, -1.326158525671520e-02, 1.641666049902940e-02, 2.948086873606759e-02, 2.390741196835947e-03, -5.939022516015280e-02, -2.562404623243324e-02, -1.810789259894665e-03, -2.725854268031053e-05, -5.158234589841684e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_cf22d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.332048308155165e-03, -1.290477428697583e-03, -1.236956345796655e-03, -1.183850532952121e-03, -1.186242372732158e-03, -1.395612253841381e-03, -1.870509308215882e-03, -5.054272374683900e-04, 2.418611698704880e-03, -9.996973710022883e-02, -3.289220556087356e-01, 4.657706527148175e-01, -9.099720993485726e-01, -6.289831965041833e-01, -2.863901349770351e-01, -2.359288015408907e+01, 4.810484132355349e+01, -5.953897744264237e+00, -7.966131198322197e+03, -9.565355776272017e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_cf22d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.026414736972807e-08, 3.403456742733550e-08, 4.015273677625853e-08, 5.051510766732934e-08, 6.890461266207108e-08, 1.022825878664070e-07, 1.544447539797301e-07, 1.271573444832920e-07, -7.381306547832856e-07, 1.119095172002162e-05, 7.607542368893298e-04, -1.479003550807700e-02, -4.748921892905185e-02, -1.358048460966492e-01, -8.744455795285638e-01, 1.436938999790426e+02, 2.542774682933888e+03, 2.769729735211440e+04, 3.815794891280839e+05, 7.113456289712979e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_cf22d_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.323606902771788e-05, -3.808137186055937e-05, -4.505964519283470e-05, -5.472039174510874e-05, -6.658660898999603e-05, -7.613640227026433e-05, -7.112505339831494e-05, -5.401846033379458e-05, 5.186073051130394e-05, 1.878384080374316e-03, 1.820261316975519e-03, -2.631704056841874e-02, 3.970448167047066e-01, 5.299706144138469e-01, 6.153757700023632e-01, -1.278436474095193e+00, -6.575497286766173e+01, -1.625076967956852e+02, -2.816121942601012e+02, -3.984232778645344e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_cf22d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.993602750046242e-13, -3.485297587550989e-13, -4.323234431862508e-13, -5.851489069060238e-13, -8.901491850197724e-13, -1.573386898992322e-12, -3.383086134917832e-12, -1.185804893831121e-11, -2.307159845621659e-10, -1.695138638827052e-08, -3.355037402758388e-06, -2.992588100871513e-03, -5.778855322562065e-03, -3.640608341890041e-02, -4.224978251608962e+00, -1.104981673946059e+03, -2.104611337755575e+05, -7.706752325500213e+07, -1.271050597732747e+11, -1.818851170454997e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_cf22d_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.330234690812862e-10, -6.040021021018433e-10, -7.201863442376327e-10, -9.192295153522603e-10, -1.277174797924791e-09, -1.931861609514473e-09, -2.891015343619334e-09, -9.410551795264559e-10, 4.308638758130635e-08, 3.856087793895993e-07, 1.771954878765186e-06, 1.603284347426825e-03, 1.498177353502714e-02, 8.569551909060955e-02, 1.856792198870495e+00, -4.313536832672898e-01, -9.786821504390424e+01, -1.841692737783307e+02, -1.341900604055738e+02, -3.451462734936269e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_cf22d_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_cf22d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.140605546114931e-06, 2.331349531798223e-06, 2.605747422755684e-06, 2.986825415549333e-06, 3.460724426700018e-06, 3.844490786323619e-06, 3.435547182442292e-06, 4.738145734898214e-07, -1.316292559998516e-05, -7.610613048008697e-05, -2.866209247424305e-05, 1.679827123660803e-03, -1.816960318455894e-01, -4.799045598671354e-01, -1.557136594370271e+00, 2.682702485857791e+00, 6.122797257236878e+01, 1.626272706947838e+02, 3.057723656079947e+02, 4.572527214725349e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
