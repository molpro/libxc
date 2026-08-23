
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mcam_b3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mcam_b3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.536824059644363e+00, -3.470313635357276e+00, -3.377168370440612e+00, -3.248246271281960e+00, -3.072793701726761e+00, -2.839724566025253e+00, -2.540605477763091e+00, -2.174885721543622e+00, -1.756271153679291e+00, -1.313349536767369e+00, -8.736042154458805e-01, -5.528920934167803e-01, -4.706067002816891e-01, -3.904320265305314e-01, -2.772984809853910e-01, -1.636111637089852e-01, -8.687995670511496e-02, -6.116805704497354e-02, -3.762347217612377e-02, -2.532404521342344e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mcam_b3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mcam_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.403762819179809e+00, -4.311703001956466e+00, -4.182691653447600e+00, -4.003958869517532e+00, -3.760397353117948e+00, -3.436295837019166e+00, -3.019604364481976e+00, -2.510217224438258e+00, -1.933684369268675e+00, -1.359614511097794e+00, -8.995347714354218e-01, -6.794427656400437e-01, -6.027605536380777e-01, -4.778422307793069e-01, -3.244219296477941e-01, -1.910310469076935e-01, -9.201270729694540e-02, -3.143418832519524e-02, -1.169725837324707e-02, -4.336531836136592e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mcam_b3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mcam_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.252118021378029e-06, -3.504197337900229e-06, -3.899938382292429e-06, -4.545094337018608e-06, -5.654726487754112e-06, -7.713032188485747e-06, -1.195580598142290e-05, -2.206208805861108e-05, -5.123293990578615e-05, -1.587733855249911e-04, -7.250558607970577e-04, -4.670731403580714e-03, -9.228433351704307e-03, -1.660993658207104e-02, -4.637384992646758e-02, -1.528891578555087e-01, -9.073280720521422e-01, -1.086107876327038e+02, -1.046424848628739e+04, -6.222009647901659e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mcam_b3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mcam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.633250417513992e-03, -1.006010919531425e-02, -1.070611694962474e-02, -1.170531144843145e-02, -1.329898457054871e-02, -1.595160180913233e-02, -2.062754064048587e-02, -2.947763863652495e-02, -4.738012080324988e-02, -8.300799125826419e-02, -1.593272875333297e-01, -4.162163695520901e-01, -5.333724623979035e-01, -8.316328058998831e-01, -1.463679842440222e+00, -8.980696715698606e-01, 1.090182293482668e+01, 2.288663431780475e+01, 9.539946989835307e+03, 6.261446993303138e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mcam_b3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mcam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.620282881031414e-08, 1.835906408978070e-08, 2.195202772424422e-08, 2.832808548911962e-08, 4.069273436108480e-08, 6.781687452082602e-08, 1.381038184390118e-07, 3.627924916534963e-07, 1.241918482387182e-06, 3.695830064379855e-06, -4.395585792314592e-05, 4.706779836971774e-03, 1.930027278610023e-02, 3.693364438300521e-02, -1.230418012673744e-01, -2.677068843571764e+01, -3.790339942807848e+03, -6.863453192725496e+05, -6.267020181066573e+09, -2.114430314254353e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mcam_b3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mcam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.398632644967197e-14, 1.047309123416372e-13, 1.437507115084835e-13, 2.262943481351492e-13, 4.330005398735631e-13, 1.092289654764590e-12, 4.063347167203594e-12, 2.593313569306521e-11, 3.462603226551575e-10, 1.242700221144234e-08, 1.616597883147328e-06, 3.861271081454839e-04, 3.356596880474502e-03, 2.212732095641099e-02, 9.029458658980678e-01, 2.367527904623577e+02, 4.665889279289316e+05, 1.238108247123816e+10, 1.500654348032102e+16, 4.990340788318377e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
