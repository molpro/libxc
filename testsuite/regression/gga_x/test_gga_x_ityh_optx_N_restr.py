
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ityh_optx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_optx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.011966557312022e+01, -9.913591260280789e+00, -9.624048090703585e+00, -9.221486238357119e+00, -8.670286023460141e+00, -7.932153137857796e+00, -6.975048010831683e+00, -5.790667215849125e+00, -4.422070775855237e+00, -3.000951747990515e+00, -1.802226131515232e+00, -1.196462499756251e+00, -9.849082857979881e-01, -7.363421699885121e-01, -4.053958396133889e-01, -1.330518258276203e-01, -1.694961265013727e-02, -6.232097240893125e-04, -5.604690626306914e-06, -7.580602262498405e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ityh_optx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_optx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.312057370045651e+01, -1.287552418418331e+01, -1.252925669456620e+01, -1.204414638444626e+01, -1.137328505964823e+01, -1.046362920259056e+01, -9.266417215820139e+00, -7.760101320634943e+00, -5.989827776292877e+00, -4.123201790286855e+00, -2.527617072647292e+00, -1.686135979386131e+00, -1.370715561974645e+00, -1.077804650767907e+00, -6.294697442520780e-01, -2.291593226029980e-01, -3.252569316617643e-02, -1.240666759083866e-03, -1.120713696452357e-05, -1.516116739504595e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_optx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_optx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.576937118495921e-06, -5.601763372141315e-06, -5.637470472913623e-06, -5.688519846339659e-06, -5.760572651148091e-06, -5.859895867875672e-06, -5.992301923976443e-06, -6.168511964627927e-06, -6.472488474026628e-06, -7.676854585432587e-06, -2.216005871989362e-05, -2.554953458970776e-03, -2.163974959568720e-02, -5.260327661813443e-03, -2.322854744694935e-03, -8.378683547464641e-04, -8.138626143951509e-05, -1.265512990915475e-06, -2.741978255252340e-09, -4.520978415978587e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_optx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_optx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.390104217872397e-02, -1.496546718744560e-02, -1.657825542367098e-02, -1.907710315556022e-02, -2.307343461737975e-02, -2.975699581810825e-02, -4.165937006022115e-02, -6.479744212783133e-02, -1.155231402282673e-01, -2.445680896973154e-01, -5.901269543545277e-01, -9.030667711195836e-01, -8.219934164917491e-01, -1.969330190193589e+00, -4.611948851312741e+00, -1.300503363778836e+01, -2.960812707230258e+01, -3.807429392682245e+01, -3.921751593419386e+01, -3.926926702397907e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_optx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_optx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.211197375362566e-07, -1.295221415577480e-07, -1.426085909543267e-07, -1.637006993914035e-07, -1.993943168699682e-07, -2.641285799594625e-07, -3.936922867674313e-07, -6.927494409027638e-07, -1.552506764509716e-06, -5.282974171011131e-06, -5.662202489888332e-05, -1.689080444025601e-02, -2.120516510022412e-01, -1.033991195873661e-01, -1.519937944969195e-01, -3.423055317707930e-01, -4.288333066662475e-01, -2.090109035660111e-01, -5.119385138287484e-02, -6.245301203251188e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ityh_optx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ityh_optx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.737720825709613e-12, 1.978574623953833e-12, 2.384164066836451e-12, 3.115809918297231e-12, 4.572481957840880e-12, 7.912946049319538e-12, 1.729395242214361e-11, 5.259662805502265e-11, 2.583894554587264e-10, 2.786336712933818e-09, 1.954868793128514e-07, 1.741588018558409e-03, 1.010722087764464e-01, 4.830876797546908e-02, 1.736528655819023e-01, 2.053975498025726e+00, 2.995995688554900e+01, 4.725436613732496e+02, 1.394040147319552e+04, 1.320477170610867e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
