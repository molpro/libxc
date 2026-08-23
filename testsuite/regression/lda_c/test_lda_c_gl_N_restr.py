
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_gl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.439021690125198e-01, -1.432323786929155e-01, -1.422704299148185e-01, -1.408899217482884e-01, -1.389109501315701e-01, -1.360787926666605e-01, -1.320356428845602e-01, -1.262860546251248e-01, -1.181718950599688e-01, -1.069940182118608e-01, -9.332608348024879e-02, -8.353330129777460e-02, -7.940110344656845e-02, -7.290757899245638e-02, -6.182588092716530e-02, -4.640937522079711e-02, -2.831349780090443e-02, -1.199692246466551e-02, -2.885324267465864e-03, -3.324186081772853e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_gl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.548443927533038e-01, -1.541714096711249e-01, -1.532047625141998e-01, -1.518172718886598e-01, -1.498277764441693e-01, -1.469794371473229e-01, -1.429106900975275e-01, -1.371189709741814e-01, -1.289316805221555e-01, -1.176194582793344e-01, -1.037139729335307e-01, -9.368171050298822e-02, -8.942594688213104e-02, -8.270543006226763e-02, -7.112180574179619e-02, -5.467458507725181e-02, -3.460128456328149e-02, -1.532794238647680e-02, -3.804197935687188e-03, -4.426373093870335e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_gl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.138851011012415e-05, -6.525130287257900e-05, -7.122984145673543e-05, -8.078364837464883e-05, -9.676756422696728e-05, -1.253271765716340e-04, -1.813937539780268e-04, -3.072692053829820e-04, -6.484378027066240e-04, -1.827972976811109e-03, -6.602352534936810e-03, -1.684700436495779e-02, -2.515501457478785e-02, -4.763222406950855e-02, -1.461007746044634e-01, -7.688906937228788e-01, -7.304146529605454e+00, -1.272278306183108e+02, -4.195544834500945e+03, -3.796352560947022e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
