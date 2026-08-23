
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ml2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.208372193684603e-02, -4.203949793882338e-02, -4.197454334124936e-02, -4.187828274827734e-02, -4.173380708955244e-02, -4.151305959787935e-02, -4.116728241418147e-02, -4.060705314331275e-02, -3.965997023638880e-02, -3.799946944519921e-02, -3.529227808217822e-02, -3.282410886442819e-02, -3.164133985816080e-02, -2.961200006815801e-02, -2.568843792737509e-02, -1.944076593573729e-02, -1.154550239352943e-02, -4.651663442032633e-03, -1.090129441580824e-03, -1.257146950548544e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ml2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.279956652478383e-02, -4.276843441694712e-02, -4.272265743204884e-02, -4.265470414836553e-02, -4.255245750590386e-02, -4.239562920724561e-02, -4.214848796572621e-02, -4.174416927557603e-02, -4.104959593000455e-02, -3.979817329238821e-02, -3.766641401208988e-02, -3.562484339121390e-02, -3.461365317080947e-02, -3.282951248366953e-02, -2.920561646275219e-02, -2.296918529527811e-02, -1.429015279851195e-02, -5.995665276605018e-03, -1.438715812126221e-03, -1.673360025835255e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ml2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.812611757751896e-06, -3.047622797790752e-06, -3.419946179247340e-06, -4.035214737881856e-06, -5.115333018834145e-06, -7.183037417031793e-06, -1.166260331925640e-05, -2.323196072969591e-05, -6.141109260190750e-05, -2.338968963380609e-04, -1.194456820805690e-03, -3.825619998283255e-03, -6.244893790169371e-03, -1.347334137566123e-02, -5.001137105769698e-02, -3.162258936574588e-01, -3.227370562926819e+00, -5.229225634720494e+01, -1.597216161890297e+03, -1.432905882498689e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
