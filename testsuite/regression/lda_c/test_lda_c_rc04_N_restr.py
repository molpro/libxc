
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_rc04_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rc04", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.832031774353909e-02, -7.821649642485043e-02, -7.806407471935209e-02, -7.783834006362274e-02, -7.749987991928360e-02, -7.698354490824473e-02, -7.617676051290402e-02, -7.487488711733713e-02, -7.268912666767981e-02, -6.890320688515836e-02, -6.285866147452487e-02, -5.748725836323955e-02, -5.496079554082456e-02, -5.069838638412738e-02, -4.271956512160968e-02, -3.074402803517277e-02, -1.695617717324754e-02, -6.283132033162624e-03, -1.382081985366808e-03, -1.550618828518949e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_rc04_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rc04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.000114936175787e-02, -7.992746094695945e-02, -7.981912590878656e-02, -7.965835056801869e-02, -7.941654346235241e-02, -7.904593060642456e-02, -7.846265420889441e-02, -7.751064806911828e-02, -7.588220795734520e-02, -7.297208168196741e-02, -6.808963840871055e-02, -6.350640076936494e-02, -6.127090812207272e-02, -5.738358037018382e-02, -4.971552642265215e-02, -3.724843640648273e-02, -2.147312895105106e-02, -8.222110866240541e-03, -1.835268234218999e-03, -2.066547095828679e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_rc04_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rc04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.657736839724327e-06, -7.213150888763335e-06, -8.092776869735144e-06, -9.545610327748778e-06, -1.209406104900196e-05, -1.696656865476170e-05, -2.750143520107693e-05, -5.461838763260336e-05, -1.435725303352873e-04, -5.409506945238248e-04, -2.708403184845787e-03, -8.501250554232806e-03, -1.373422943471322e-02, -2.907903569654275e-02, -1.036928732749238e-01, -6.084814854856680e-01, -5.515526902257487e+00, -7.734329022626889e+01, -2.098353926856555e+03, -1.780139276633296e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
