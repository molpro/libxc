
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_opbe_d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opbe_d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.373731305887476e+00, -4.291029405824037e+00, -4.175229159614027e+00, -4.014998568827563e+00, -3.797055378145075e+00, -3.507843058987046e+00, -3.137474533227705e+00, -2.686852291254564e+00, -2.176909071153681e+00, -1.648704300680304e+00, -1.118265784943039e+00, -7.126091103255093e-01, -6.180009593695053e-01, -5.137120287216094e-01, -3.760903250949931e-01, -2.461111565013840e-01, -1.379842317381602e-01, -5.056753539309874e-02, -1.069394778637142e-02, -1.183654185610759e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_opbe_d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opbe_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.514755378411003e+00, -5.399143777026289e+00, -5.236968297790667e+00, -5.011954802854795e+00, -4.704616769428403e+00, -4.294145258097488e+00, -3.763252328760959e+00, -3.107985377154108e+00, -2.356459987345441e+00, -1.606316902256812e+00, -1.043969857928417e+00, -8.862672203881894e-01, -7.959821810662561e-01, -6.318619155880598e-01, -4.172528897579293e-01, -2.290932597181637e-01, -1.401406353397060e-01, -6.452713450817193e-02, -1.422837346258770e-02, -1.578162467114604e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_opbe_d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opbe_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.157290473769160e-06, -3.427646460289100e-06, -3.856262935487373e-06, -4.565045205058399e-06, -5.809720356123448e-06, -8.189853787926825e-06, -1.331963476349431e-05, -2.635430088479253e-05, -6.747567792558596e-05, -2.352610340674570e-04, -1.175671797438854e-03, -4.099938470467723e-03, -5.551294932935154e-03, -1.576221388053945e-02, -7.288897341565773e-02, -5.172593127146263e-01, -2.957931516624241e+00, -6.522145930157670e+00, -8.228588570605584e+00, -9.115739345889910e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_opbe_d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opbe_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.258707354026622e-02, -1.318817383962002e-02, -1.410471982884966e-02, -1.553839023072347e-02, -1.786451506669643e-02, -2.184017690498202e-02, -2.914458054861003e-02, -4.387647823688780e-02, -7.630213173443159e-02, -1.436314656859792e-01, -3.068438761891511e-01, -5.905530973845365e-01, -6.719920676647575e-01, -1.248536766777717e+00, -3.306012194014051e+00, -6.333832036291650e+00, 5.645091847346436e+01, -3.312308631234355e+02, -1.618369666095549e+04, -1.362106468439168e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_opbe_d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opbe_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.729833545934537e-08, 3.130370161789547e-08, 3.809083763348695e-08, 5.043771868472205e-08, 7.528615396510286e-08, 1.329622054677566e-07, 2.961888824531526e-07, 8.982964361857856e-07, 3.938995115064772e-06, 2.285984597824590e-05, 2.728671753389778e-04, 1.170430326441109e-02, 2.498708379656014e-02, 1.272366505055522e-01, 1.380061685976366e+00, 3.083768768862669e+00, -6.971193882247660e+03, -7.586842273929350e+05, -1.148295197391094e+08, -9.443884591574571e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_opbe_d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opbe_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.099732636859038e-14, -6.023451825146426e-14, -7.619209383873159e-14, -1.056954700493626e-13, -1.645090191561013e-13, -2.841654006717535e-13, -3.882909161786118e-13, 3.491859104867444e-12, 1.629136303007502e-10, 1.176896277782766e-08, 1.810692693593695e-06, -2.894996021093914e-04, -3.120231129654747e-03, -1.390535486421301e-02, -4.014004557872686e-02, 2.844035629986957e+02, 7.404564530593804e+05, 2.316912956621586e+09, 4.172145173398662e+13, 2.662392403215176e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
