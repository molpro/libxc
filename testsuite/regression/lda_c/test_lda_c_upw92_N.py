
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_upw92_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_upw92", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.181785815592766e-01, -1.175894747573477e-01, -1.167442216360736e-01, -1.155328960577992e-01, -1.138000386405729e-01, -1.113276674891070e-01, -1.078141658684203e-01, -1.028516670867878e-01, -9.591708896802346e-02, -8.645016190276215e-02, -7.407301705831516e-02, -6.083337576914338e-02, -5.697667870170989e-02, -5.282097963986922e-02, -4.438437121782902e-02, -3.250001330203237e-02, -1.919257101523016e-02, -8.226686523699820e-03, -2.312798305633819e-03, -3.396899930601929e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_upw92_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_upw92", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.278055893678294e-01, -1.278073845601336e-01, -1.272050704975606e-01, -1.272088843703305e-01, -1.263424633606782e-01, -1.263506609913993e-01, -1.251040545842311e-01, -1.251219747802297e-01, -1.233272630140274e-01, -1.233674084131246e-01, -1.207793731459774e-01, -1.208725740350409e-01, -1.171243706859847e-01, -1.173523282477225e-01, -1.118613373909636e-01, -1.124631577329323e-01, -1.041701323833306e-01, -1.059445639998606e-01, -9.242035509648033e-02, -9.846916388901819e-02, -7.370907622705192e-02, -9.599891364014512e-02, -5.575459459976448e-02, -1.088007615193121e-01, -5.210771878988652e-02, -1.070779584287908e-01, -4.868282593597899e-02, -9.752089257013467e-02, -4.116115172659390e-02, -8.667260015945615e-02, -3.059769499857148e-02, -7.257705279246027e-02, -1.895444766244847e-02, -5.282944905378606e-02, -8.982874538836611e-03, -2.792641698148290e-02, -2.824544684463705e-03, -7.997164676617088e-03, -4.407797405012253e-04, -8.641074360581873e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_upw92_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_upw92", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.570563168669186e-04, -4.664743554708860e-04, 3.570749059433872e-04, 3.776871818281741e-04, -4.939246071696833e-04, 3.777291551143745e-04, 4.094084802456001e-04, -5.362003387567079e-04, 4.095069514123501e-04, 4.596147003010606e-04, -6.032764478926792e-04, 4.598587870823709e-04, 5.424319374365849e-04, -7.143423343819686e-04, 5.430867787747121e-04, 6.873166848443955e-04, -9.098342168121014e-04, 6.892850255777045e-04, 9.627010309308234e-04, -1.285312682421276e-03, 9.696666660917189e-04, 1.549582293095668e-03, -2.101767119304190e-03, 1.580725406043973e-03, 2.997694843604983e-03, -4.212973606189462e-03, 3.191534750211100e-03, 7.035687638225445e-03, -1.102178010645863e-02, 8.904212717623140e-03, 1.495065361451838e-02, -3.600396048982591e-02, 4.066658358449784e-02, 1.546790576091996e-02, -9.415929171294062e-02, 2.234033608793526e-01, 1.973029735185492e-02, -1.388352909554031e-01, 3.596916753894971e-01, 3.544129357770499e-02, -2.447037419025817e-01, 5.918324979892482e-01, 7.985929644549006e-02, -6.892058950995141e-01, 1.768479798114482e+00, 1.913135120146684e-01, -3.225069898136185e+00, 9.831750840108720e+00, -4.700041542996397e-01, -2.582509265100897e+01, 1.023889201308706e+02, -3.988426302998185e+01, -3.727379429703340e+02, 2.109510292475060e+03, -2.357445840551032e+03, -1.114795559258400e+04, 9.456553320854956e+04, -3.391555720557863e+05, -8.751073462251506e+05, 1.471827690070997e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
