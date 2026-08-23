
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ml1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.374945926451329e-02, -9.362248385846551e-02, -9.343612734334102e-02, -9.316026142069141e-02, -9.274691385349820e-02, -9.211696756760593e-02, -9.113416314269619e-02, -8.955201293427431e-02, -8.690575020828031e-02, -8.235033365165720e-02, -7.514378839389194e-02, -6.879856464173881e-02, -6.583009031915962e-02, -6.084105474973646e-02, -5.154797442859842e-02, -3.762524730195700e-02, -2.138291215406189e-02, -8.286943859884708e-03, -1.897994343240469e-03, -2.170627840724019e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ml1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.580540844253149e-02, -9.571476041969516e-02, -9.558152326228538e-02, -9.538385950090936e-02, -9.508672059943230e-02, -9.463163858557762e-02, -9.391622553743845e-02, -9.275060792081898e-02, -9.076260326372718e-02, -8.722799192467699e-02, -8.134821031580888e-02, -7.588204820210336e-02, -7.323282954901589e-02, -6.864948482809327e-02, -5.967951847739210e-02, -4.520677242502817e-02, -2.679035910352493e-02, -1.074708051045167e-02, -2.509879086682698e-03, -2.890280047152184e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ml1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.190828409868753e-06, -8.872423617250398e-06, -9.951614536552558e-06, -1.173339424680558e-05, -1.485710816417598e-05, -2.082437803783022e-05, -3.370888993233499e-05, -6.680123050851989e-05, -1.749517106909553e-04, -6.549040265580462e-04, -3.244848067498409e-03, -1.009470935450343e-02, -1.624435734383653e-02, -3.418314066322704e-02, -1.207904311185145e-01, -7.055782866568229e-01, -6.519973244438785e+00, -9.684163599474380e+01, -2.813780432676228e+03, -2.479143831116472e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
