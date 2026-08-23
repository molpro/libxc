
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_fr_b88_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_b88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.474603146785179e+01, 9.107646228496789e+01, 8.605766596907431e+01, 7.934280700249209e+01, 7.063673678497300e+01, 5.984328225112294e+01, 4.728406691938272e+01, 3.391453215705261e+01, 2.133369294900195e+01, 1.132013699403349e+01, 4.936508864392603e+00, 2.213900145201249e+00, 1.633335106193469e+00, 1.103098524242231e+00, 5.528640849596291e-01, 2.034661476001199e-01, 5.506754218176528e-02, 1.065491919381219e-02, 1.395549174167420e-03, 1.063735352447488e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_fr_b88_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.495030799578901e+02, 1.434602857757723e+02, 1.352021836112309e+02, 1.241664242146573e+02, 1.098843066994290e+02, 9.222962758197734e+01, 7.178804152065749e+01, 5.022367706332352e+01, 3.030264754905269e+01, 1.510405082002603e+01, 6.374630967493632e+00, 3.396979870890021e+00, 2.610897394528954e+00, 1.665407201074341e+00, 7.625269327181095e-01, 2.438094886114349e-01, 5.484279859828493e-02, 8.532927789051485e-03, 8.584001609335951e-04, 5.300593480903968e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_fr_b88_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.020520040296670e-05, 9.525181629850042e-05, 1.029762434018465e-04, 1.151182098496016e-04, 1.349356988792180e-04, 1.690326765059678e-04, 2.321461062024350e-04, 3.612011495134850e-04, 6.628564025606949e-04, 1.514193273512029e-03, 4.935061467198778e-03, 2.349950473881018e-02, 4.135955676930680e-02, 6.430737111452788e-02, 1.497377110585802e-01, 5.103144667410512e-01, 2.503893985000043e+00, 2.078805369556419e+01, 3.995562644675646e+02, 2.627782960349926e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_fr_b88_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.818565087270922e-01, 5.939612629377296e-01, 6.117618604499678e-01, 6.381811605634278e-01, 6.778956247130178e-01, 7.386303369470717e-01, 8.335713719199596e-01, 9.857078846319609e-01, 1.234401166732793e+00, 1.645358356812559e+00, 2.432524547495817e+00, 3.844498984683248e+00, 4.399827673259028e+00, 5.461442116931380e+00, 7.583216487857039e+00, 1.110206743541064e+01, 1.569718573957622e+01, 1.451472821125250e+01, -5.848258847361705e+02, -5.799605643138556e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_fr_b88_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.716520172540343e-07, -2.994678221320894e-07, -3.440652368151860e-07, -4.188277784202669e-07, -5.519455441779760e-07, -8.079762564886433e-07, -1.343692388660631e-06, -2.494288879595765e-06, -3.679815044041555e-06, 2.528743604255610e-05, 5.665232769427090e-04, -1.507749435368964e-02, -6.189042081737163e-02, -9.783470273733005e-02, 4.046806714553323e-03, 1.531625706891354e+01, 1.459705204642882e+03, 3.655708034703663e+05, 7.047495823624030e+08, 3.161470979460970e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_fr_b88_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.489784830818411e-12, -3.040109194756091e-12, -4.048435222133533e-12, -6.102010114234259e-12, -1.096918345763037e-11, -2.529962353499493e-11, -8.277453912760953e-11, -4.397069653651095e-10, -4.525381140759519e-09, -1.135430047117413e-07, -9.690466888617925e-06, -1.834820966156557e-03, -1.437691791711839e-02, -7.550942054633436e-02, -2.109713433092759e+00, -3.167508057042190e+02, -2.717920543976428e+05, -2.279207273839255e+09, -5.727623589983842e+14, -2.107539636290950e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
