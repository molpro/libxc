
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_bc95_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.688836639135335e-02, -5.648525282701960e-02, -5.590168557835599e-02, -5.505432590573493e-02, -5.381830245744256e-02, -5.200288150352120e-02, -4.930958548723056e-02, -4.526521843997539e-02, -3.919072092149260e-02, -3.092913183559275e-02, -2.692595355974284e-02, -6.658641208276124e-02, -4.620183176673922e-02, -3.066237438142215e-02, -2.038090429038095e-02, -9.545246162469481e-03, -1.959435439020319e-03, -1.148454748804341e-04, -1.425097798436954e-06, -2.277294026177689e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_bc95_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.831786755689392e-02, -7.826315591804713e-02, -7.818260723041211e-02, -7.806174866097597e-02, -7.787395682789787e-02, -7.756386971987805e-02, -7.700178828687240e-02, -7.585893773750205e-02, -7.329672379383825e-02, -6.777495564494343e-02, -6.685693742505469e-02, -1.015573814372022e-01, -5.126521273454505e-02, -5.055957547338309e-02, -4.271841947503225e-02, -2.657273819316925e-02, -7.058985011555646e-03, -4.589999827785069e-04, -5.851161412017061e-06, -9.457404269769751e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_bc95_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.292749120421454e-07, 3.569341562608395e-07, 4.005031604784854e-07, 4.718214141611831e-07, 5.950141811931847e-07, 8.242587237211695e-07, 1.296465485769346e-06, 2.412514308298274e-06, 5.606469009087910e-06, 1.805867780825671e-05, 1.317527321527048e-04, 7.608758214242842e-03, 1.110701698917026e-02, 1.139591419755509e-02, 2.610414954119541e-02, 9.812454293137250e-02, 3.488277655311262e-01, 7.644928907517419e-01, 1.179719099651213e+00, 1.491546162626117e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_bc95_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
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


def test_mgga_c_bc95_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.613410044321765e-05, 4.646904055386091e-05, 4.634338326090798e-05, 4.459778264636505e-05, 3.776581552937243e-05, 1.495904613203368e-05, -6.093736255705002e-05, -3.318386012474226e-04, -1.446473447544923e-03, -7.234831308411639e-03, -4.041505262963427e-02, 1.442249814297214e-01, 1.009563716801914e-01, 9.402696690777278e-03, -3.460294365997293e-01, -2.906859233649055e+00, -1.722830629669454e+01, -4.260902446870729e+01, -6.412713098212490e+01, -7.799178833043736e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_bc95_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.448193999663939e-10, -8.608978593109809e-11, 3.789482285582010e-11, 3.283576547273864e-10, 1.103521660810027e-09, 3.545099053391720e-09, 1.305865851448802e-08, 6.179927764128403e-08, 4.210821241909655e-07, 5.053997368306691e-06, 1.720720583336050e-04, 1.888882326605409e-04, -2.666552310423282e-02, 3.256653095351675e-02, 6.066004414115475e-01, 1.909941626502296e+01, 1.215398000999302e+03, 9.628226574785959e+04, 1.737512285181863e+07, 1.648600235760001e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_bc95_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.617578248211794e-06, -1.829183131956684e-06, -2.174872864687964e-06, -2.769351600943677e-06, -3.864806628696993e-06, -6.072754570443859e-06, -1.103528589734494e-05, -2.357149524392739e-05, -5.858087267398961e-05, -1.689407216062556e-04, -9.018020406182862e-04, -1.440910780837978e-02, -1.730638894015352e-02, -7.371400611027794e-02, -2.381614667286154e-01, -6.950994680341143e-01, -1.626510888596801e+00, -3.216408521515743e+00, -5.568582976990760e+00, -8.117935153904899e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_bc95_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.252225059838772e-14, -5.349044550714197e-14, -7.427311181850518e-14, -1.186312228381182e-13, -2.307533967080027e-13, -5.904716711297252e-13, -2.199404400521989e-12, -1.355617266707796e-11, -1.634402491945199e-10, -5.179271606248451e-09, -1.031855024572246e-06, -2.987230024279002e-03, -1.710100770483347e-02, -6.504075208035968e-02, -1.529369047015916e+00, -2.029276218229124e+02, -1.283953663216590e+05, -3.131249487212433e+08, -6.734911929259316e+12, -4.962671972652310e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_bc95_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.916050179873967e-11, 3.446096601149646e-11, 4.373770127880464e-11, 6.138564941131548e-11, 9.912267028079563e-11, 1.939545178257547e-10, 4.901359636795507e-10, 1.715978639403007e-09, 8.928588069670853e-09, 7.918849669045711e-08, 2.762267028323555e-06, 1.573286494359455e-03, 1.236868686480504e-02, 3.538576891525784e-02, 2.619793796742148e-01, 4.173191644341568e+00, 1.214262748700988e+02, 7.899879129525617e+03, 1.637581142200523e+06, 1.839943426341288e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_bc95_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_bc95", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.479281294991928e-138, 0.000000000000000e+00, -2.960051208472817e-138, -5.162548007931523e-138, 0.000000000000000e+00, 0.000000000000000e+00, -8.542738895584960e-138, 0.000000000000000e+00, -3.369153414520278e-137, -8.531848332150388e-137, -3.228035394732914e-136, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 2.349654702716079e-132, -5.005130872864918e-132, -1.749655682672519e-131, -3.589032619196331e-131, -9.983140847047514e-131, 8.021027003778716e-131]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
