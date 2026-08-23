
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_c09x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_c09x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.223934518754031e+00, -4.140962359333056e+00, -4.024750253214943e+00, -3.863878884257653e+00, -3.644913435265255e+00, -3.354026312111094e+00, -2.980863595610655e+00, -2.525684517151483e+00, -2.009674901082844e+00, -1.482143888469285e+00, -9.897140397618606e-01, -6.450624096716844e-01, -5.550155633193403e-01, -4.553028968244929e-01, -3.249902820027810e-01, -2.094822260722987e-01, -1.338779088476653e-01, -5.188384162593863e-02, -1.091932091559291e-02, -1.207333005251914e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_c09x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_c09x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.470362535344584e+00, -5.356800912829671e+00, -5.197563657908977e+00, -4.976749373588931e+00, -4.675375714725028e+00, -4.273252580367880e+00, -3.753597583821221e+00, -3.111701869993984e+00, -2.368933454625192e+00, -1.599554099145545e+00, -1.006993888033329e+00, -8.191101046111942e-01, -7.245663597536257e-01, -5.706772527131529e-01, -3.688597153360236e-01, -1.792357388144865e-01, -9.273320989707980e-02, -6.362328814556242e-02, -1.455909455412388e-02, -1.609777340335886e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_c09x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_c09x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.733402154762802e-06, -1.879958426736975e-06, -2.112404693432815e-06, -2.497147968352784e-06, -3.174163777661830e-06, -4.474623803056807e-06, -7.305888244192242e-06, -1.466909109931448e-05, -3.919383978794557e-05, -1.515615117399119e-04, -8.326602860653779e-04, -3.287811414631501e-03, -5.741484845816251e-03, -1.352100839195626e-02, -6.073876331396892e-02, -5.358735674824636e-01, -5.814330525158561e+00, -1.251791074094294e+01, -1.064274017481650e-25, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_c09x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_c09x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.135658784470004e-02, -1.187030627130498e-02, -1.265171504341485e-02, -1.387018603388018e-02, -1.584006386154860e-02, -1.919751932834928e-02, -2.538298150607413e-02, -3.816450201629024e-02, -6.926328376904115e-02, -1.598184465414436e-01, -4.046808676591478e-01, -5.255729187219810e-01, -6.366631049684345e-01, -1.106329711992283e+00, -2.941209837913228e+00, -1.139217821726212e+01, 1.309960948084677e+02, -1.582191702787604e+02, -1.699144954321620e+04, -1.389848758967625e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_c09x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_c09x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.260348349036153e-08, 1.451825021364368e-08, 1.778770879131446e-08, 2.380564009011293e-08, 3.614427963606716e-08, 6.567699670260274e-08, 1.538826271964837e-07, 5.146181856630483e-07, 2.795149570837060e-06, 2.791387064270955e-05, 5.213673162074182e-04, 6.797938025489468e-03, 1.830332472132243e-02, 8.014679346612828e-02, 1.042181764934891e+00, 3.352083567996354e+01, -1.101386957564317e+04, -1.128293839040182e+06, -6.920016972374197e-17, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_c09x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_c09x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.240564932575404e-15, 4.137955763227873e-15, 5.878978785936263e-15, 9.733505045409885e-15, 2.006087455507146e-14, 5.652521776938842e-14, 2.485279014601845e-13, 2.050522374949547e-12, 4.070222319977656e-11, 2.562506207736508e-09, 4.519256805770372e-07, 2.248742158434069e-05, 1.169684731785838e-04, 1.581731681730345e-03, 1.569602243629348e-01, 1.491598403376493e+02, 1.281760436391226e+06, 3.711033921097077e+09, 1.897620888238475e-11, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
