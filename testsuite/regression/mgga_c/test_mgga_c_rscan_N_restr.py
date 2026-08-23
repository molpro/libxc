
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_rscan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.650614761957699e-02, -2.645882253917780e-02, -2.638868337217597e-02, -2.628339011845200e-02, -2.612248330993839e-02, -2.587085235071131e-02, -2.546910090953976e-02, -2.485526493775772e-02, -2.418639873199510e-02, -2.495461660325190e-02, -3.139471384958642e-02, -5.593520258451094e-02, -4.744299057343394e-02, -2.987610740607012e-02, -2.399073835827151e-02, -1.803793182164137e-02, -8.496498012656646e-03, -2.365928272416311e-03, -3.259721486350463e-04, -1.395007486824711e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_rscan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.904640265449190e-02, -2.909507261602176e-02, -2.917332183801112e-02, -2.930765780483799e-02, -2.956583661908779e-02, -3.016721638824475e-02, -3.202351034569911e-02, -3.857656695984954e-02, -4.734838248100143e-02, -6.079580558358204e-02, -6.098819203107959e-02, -8.205691103601438e-02, -3.188265530369951e-02, -4.035027167286371e-02, -4.899276384296663e-02, -5.009604556918763e-02, -2.741428170641047e-02, -4.519871206292275e-03, -6.387056703121856e-04, -2.778624679302287e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rscan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.638166774385625e-08, 2.952966051963505e-08, 3.486384302181612e-08, 4.470654292737498e-08, 6.560628056821978e-08, 1.219913262025374e-07, 3.458178027716896e-07, 1.631904467299829e-06, 6.604347902925232e-06, 3.606277556834511e-05, 9.919764858403664e-05, 3.272495127188108e-03, 1.205766902341304e-02, 1.795780735971565e-02, 6.477403505017522e-02, 4.066408230289134e-01, 2.626122599911568e+00, 3.878636071321433e+00, 5.946645807895269e+01, 1.966818522180453e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rscan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.809737197787363e-06, -4.593557915045658e-06, -6.017000680778528e-06, -8.882673226760739e-06, -1.556946479940613e-05, -3.473127556854767e-05, -1.052443950924352e-04, -3.818921902982052e-04, -7.566846240142170e-04, -1.421204352262182e-03, -2.689932593728802e-04, -1.630360614344864e-03, -2.076987787817321e-02, -2.325052282375696e-02, -2.817811736175864e-02, -3.126438073341926e-02, -1.740061980496844e-02, -5.832596951055254e-05, -3.059908398326590e-12, -1.115813328367561e-22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rscan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.153188487100502e-04, -1.427725729201218e-04, -1.933963070618410e-04, -2.970996495702494e-04, -5.427024751350712e-04, -1.243048643331703e-03, -3.573085332358318e-03, -7.857379659502161e-03, -7.287973092408390e-04, -5.974869959349650e-03, -3.230547751895264e-02, 5.146490486709727e-02, 1.918535632681745e-01, 1.565155415535537e-01, 2.045645068695054e-01, 6.452250563204494e+00, -1.699768753219541e+01, -1.524694972571437e+02, -2.136833580429486e+03, -7.131545439242558e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rscan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.619677581656196e-09, 4.735433134534463e-09, 6.956942573643659e-09, 1.204908498039294e-08, 2.628295812812985e-08, 7.825744276774522e-08, 3.313037590747153e-07, 1.300872878529285e-06, 5.418825945682590e-07, 1.218628800602111e-05, 6.302153052447004e-05, 2.607787266985004e-03, -1.813015276819992e-02, -3.299876581099129e-02, 4.404698778477770e-01, -1.164001657261755e+02, 9.281218700232835e+02, 3.867239234589405e+05, 4.087212226769834e+08, 1.014818552338535e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rscan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.448928441171915e-06, -6.670692847503171e-06, -8.917575919772422e-06, -1.351141412679496e-05, -2.439730447911037e-05, -5.564735453336902e-05, -1.618614880438334e-04, -3.763932513794287e-04, -9.261133895984370e-05, -6.428483515139551e-04, 2.275394776073756e-04, -8.497639547057055e-03, -5.977831985970932e-02, -4.825005726435413e-02, -4.558879055975241e-01, 1.014477709754176e+01, -1.277441734739766e+01, -4.556577488273281e+01, -6.259526241470282e-04, -3.326767444677708e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rscan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.108463602591143e-13, -1.537283354959697e-13, -2.458876721948409e-13, -4.821730274167005e-13, -1.261319383202841e-12, -4.899594003934504e-12, -3.061503009484822e-11, -2.142206596529696e-10, -2.796302654197171e-10, -1.970877823675367e-08, -1.573155080238094e-06, -8.963265839530020e-04, -1.020789332623354e-02, -8.364406028019797e-02, -3.390030060737026e+00, 2.113280218321195e+03, 2.670852444720082e+04, -1.863432155222492e+09, -1.892637190656538e+14, -3.590719125194336e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rscan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.578701083784720e-10, 2.059813105063543e-10, 3.017942359454143e-10, 5.217098412825262e-10, 1.138729541048876e-09, 3.411117302906578e-09, 1.467906630370577e-08, 5.982845838989807e-08, 2.630497904973369e-08, 7.006529475205284e-07, 1.345034491571351e-05, 5.452826457335304e-05, 8.489134642315875e-04, 7.512005390737278e-02, 1.026562479509073e+00, -2.272470221283038e+02, -2.146697425453160e+03, 2.567911197673795e+05, 4.418798328356955e+02, 1.847969746417061e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_rscan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_rscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.257994764247715e-07, -2.770891148171253e-07, -3.717366076232093e-07, -5.662299784995938e-07, -1.030626404449429e-06, -2.379305909102273e-06, -7.047953157554050e-06, -1.673676462761773e-05, -2.224434752380215e-06, -2.470565585665216e-05, -1.625810700720572e-04, 8.114679557918988e-04, 3.363049988117178e-02, -5.477123952627552e-02, -2.472273417181083e-01, 2.310435117616018e+01, 2.630838295572850e+01, -6.535176464946642e+01, -1.005167831122546e-03, -5.695119722685999e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
