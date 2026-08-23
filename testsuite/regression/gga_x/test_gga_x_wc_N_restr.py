
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_wc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.295496968989504e+00, -4.213367579843132e+00, -4.098346794365785e+00, -3.939141342900450e+00, -3.722458527752534e+00, -3.434567185930610e+00, -3.064932410299618e+00, -2.612575453121817e+00, -2.094259584484865e+00, -1.550523124310094e+00, -1.034011846194377e+00, -6.613680022739643e-01, -5.621722455228702e-01, -4.688186599818068e-01, -3.396604647113251e-01, -2.165735368229610e-01, -1.194612766707567e-01, -4.169844815832215e-02, -8.765881096633081e-03, -9.701562716557644e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_wc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.407460445552658e+00, -5.294377742976818e+00, -5.135967122384272e+00, -4.916640702743607e+00, -4.618066511363280e+00, -4.221450445887125e+00, -3.713056888884552e+00, -3.094468887813214e+00, -2.395667858502842e+00, -1.676878164749929e+00, -1.075889955996014e+00, -8.093821390827335e-01, -7.174155558079369e-01, -5.649982018332844e-01, -3.790951852686358e-01, -2.011431578626448e-01, -1.298317627083726e-01, -5.408640617140598e-02, -1.166581686819803e-02, -1.293508563528540e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_wc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.432131297509742e-06, -3.696839788833293e-06, -4.111600975908669e-06, -4.785633188258380e-06, -5.938781947332415e-06, -8.058013705978650e-06, -1.235423669687473e-05, -2.229881117248656e-05, -5.005050953576374e-05, -1.571341382721628e-04, -8.064723873610109e-04, -5.812963603744792e-03, -1.194314453024712e-02, -2.232617395705669e-02, -6.952513341264958e-02, -4.691940528134262e-01, -1.996389735244384e+00, -3.406041644727102e+00, -5.996574972794891e+00, -7.005264940623149e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_wc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.156241330913228e-02, -1.205497033637325e-02, -1.279640184461424e-02, -1.393356923634913e-02, -1.572288971963133e-02, -1.863523814341597e-02, -2.358369812847759e-02, -3.250076460271704e-02, -5.123813112542173e-02, -1.151390951865264e-01, -3.118851134587575e-01, -5.041097427283570e-01, -6.566312659888144e-01, -1.009190664199176e+00, -2.072441920402698e+00, -7.093376995674237e+00, 6.112394620252240e+01, -4.015573460183220e+02, -1.331621500636052e+04, -1.116445802363215e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_wc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.606819083196288e-08, 1.804069440825417e-08, 2.126454298244364e-08, 2.681133302438795e-08, 3.702568548050020e-08, 5.746236751961982e-08, 1.017764860657787e-07, 1.991911314970316e-07, 4.537612762073972e-07, 8.175083208526902e-06, 2.361375871890350e-04, 5.495796038506184e-03, 2.787540107456851e-02, 4.734996763377869e-02, 1.755920471827587e-01, 7.142697851989858e+00, -7.130905526533392e+03, -3.573911176544614e+05, -8.129449772074398e+07, -7.251742171376047e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_wc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.017685756187274e-13, 1.282466390699887e-13, 1.786327831949523e-13, 2.869352811409597e-13, 5.639439084025440e-13, 1.470643191745968e-12, 5.660648354397475e-12, 3.654484249453969e-11, 4.450900730162032e-10, 1.101274850315719e-08, 1.153733248113492e-06, 5.632000371954132e-04, 4.032077038132936e-03, 3.418772955293515e-02, 1.138275035089761e+00, 2.495137329969121e+02, 6.671422036826022e+05, 1.123295369062232e+09, 2.975557654283148e+13, 2.044792137150006e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
