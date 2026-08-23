
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_chachiyo_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.171614826588828e-01, -1.165590907597755e-01, -1.156946809256508e-01, -1.144557184039359e-01, -1.126829871650517e-01, -1.101531621830447e-01, -1.065573061999240e-01, -1.014787569874482e-01, -9.439105197805880e-02, -8.480657943193808e-02, -7.342497404436539e-02, -6.553188046496185e-02, -6.227080188248438e-02, -5.722984854292860e-02, -4.885115540329743e-02, -3.756153483219661e-02, -2.439394599445647e-02, -1.155365228292872e-02, -3.084414101271124e-03, -3.692802720374511e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_chachiyo_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270060501091262e-01, -1.263939339170480e-01, -1.255152658153989e-01, -1.242552264633739e-01, -1.224509811486468e-01, -1.198732818374460e-01, -1.162031029585521e-01, -1.110058346689766e-01, -1.037220498597038e-01, -9.380691907767107e-02, -8.191813242604289e-02, -7.359198864178891e-02, -7.013179445740149e-02, -6.475992676293192e-02, -5.577094902751559e-02, -4.354360856231530e-02, -2.906344735586543e-02, -1.440363171466903e-02, -4.026773893827894e-03, -4.910657757280199e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_chachiyo_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_chachiyo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.585050584493490e-05, -5.933458572087503e-05, -6.472253909592584e-05, -7.332209720327181e-05, -8.768331959305368e-05, -1.132725336370315e-04, -1.632916042753341e-04, -2.748146354956290e-04, -5.736048632168145e-04, -1.586157017163524e-03, -5.553605047700986e-03, -1.378517800969660e-02, -2.032037192067382e-02, -3.766589911516041e-02, -1.112558342103030e-01, -5.597302834708404e-01, -5.296192355040326e+00, -1.045774684307292e+02, -4.222046719101233e+03, -4.183634594402182e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
