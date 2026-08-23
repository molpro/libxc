
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pz_mod_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz_mod", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.184008294513353e-01, -1.177980522232994e-01, -1.169330210822064e-01, -1.156930243120896e-01, -1.139185102244373e-01, -1.113855023467721e-01, -1.077837925060020e-01, -1.026943429749576e-01, -9.558717218124098e-02, -8.597612772892017e-02, -7.460500652161821e-02, -6.681499103660826e-02, -6.364538179575116e-02, -5.883547873596629e-02, -5.063186290258634e-02, -3.893787321242278e-02, -2.491619914399709e-02, -1.171018693721203e-02, -3.338439473370628e-03, -4.506436826536623e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pz_mod_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz_mod", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.282513784405045e-01, -1.276395034666607e-01, -1.267611282012236e-01, -1.255013933233706e-01, -1.236973303726553e-01, -1.211193231100288e-01, -1.174474012060362e-01, -1.122446064628571e-01, -1.049459105488831e-01, -9.499535530618337e-02, -8.304790288351407e-02, -7.469400121686551e-02, -7.123710778315143e-02, -6.598983546959553e-02, -5.759694239754544e-02, -4.527227409792776e-02, -2.985475396284676e-02, -1.454556849493558e-02, -4.291750431458102e-03, -5.930727728571926e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pz_mod_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz_mod", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.582714003208892e-05, -5.931266119951083e-05, -6.470335129769300e-05, -7.330848849766280e-05, -8.768209304666455e-05, -1.133017941128892e-04, -1.634063508555286e-04, -2.752119361292272e-04, -5.751418680744182e-04, -1.593174404091568e-03, -5.580397347242245e-03, -1.379702934345716e-02, -2.025793482120065e-02, -3.386977481737976e-02, -1.076270793229305e-01, -5.840811650377246e-01, -5.670636286313350e+00, -1.052591643187800e+02, -4.209217212278357e+03, -4.822901161174321e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
