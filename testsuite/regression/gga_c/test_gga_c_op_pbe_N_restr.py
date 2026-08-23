
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_op_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.913556036440770e-02, -5.883832351636815e-02, -5.839892622362339e-02, -5.774190448093153e-02, -5.674389897111768e-02, -5.519610050996530e-02, -5.273489057443193e-02, -4.873420339224877e-02, -4.229720876349643e-02, -3.333887156827502e-02, -2.760516614632947e-02, -4.015949458772193e-02, -4.139130315217426e-02, -3.398501142337843e-02, -2.294786314274198e-02, -1.124827878972307e-02, -4.156811873162102e-03, -1.339446226312757e-03, -2.915099403249686e-04, -3.274577344059554e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_op_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.494586710184886e-02, -7.508914373489844e-02, -7.529449241428868e-02, -7.558657411929355e-02, -7.599389194159341e-02, -7.653196207574667e-02, -7.712862417780847e-02, -7.733213059564240e-02, -7.537028902393425e-02, -6.722774011826757e-02, -5.788611615332769e-02, -5.858385129674311e-02, -5.329918429232469e-02, -5.256898443199698e-02, -4.394521976292367e-02, -2.400118893331658e-02, -7.130263575386001e-03, -1.832473660183123e-03, -3.877016120397283e-04, -4.363944009917051e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.550947000950604e-07, 1.700420347114773e-07, 1.939658583511958e-07, 2.340409685264405e-07, 3.056077676376515e-07, 4.452569058453936e-07, 7.523338647449912e-07, 1.538914446873304e-06, 3.940841296714938e-06, 1.289114173466490e-05, 7.498674704845579e-05, 1.121002408667036e-03, 2.515091602727358e-03, 5.151358207277012e-03, 1.621237700992158e-02, 5.608742528347249e-02, 1.305178042343469e-01, 1.974015333102240e-01, 2.397091446990459e-01, 2.666040602571414e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.988399178253244e-05, 8.566053095758674e-05, 9.445457329407707e-05, 1.080558985191540e-04, 1.292829660014536e-04, 1.614260773845033e-04, 1.995059304228108e-04, 1.599313928144764e-04, -6.330849470067651e-04, -6.386677513031861e-03, -2.849827282642627e-02, 6.135251329857909e-03, 4.707952727194500e-03, -3.128944042666308e-04, -2.719912562337781e-01, -2.471600734154142e+00, -8.748805509858080e+00, -2.756986068682646e+01, -4.539523825044108e+02, -3.759181820759631e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.410171260533653e-10, -1.076392056505566e-09, -1.302761295525553e-09, -1.704916216957469e-09, -2.478407946761143e-09, -4.110730307942679e-09, -7.766140064498619e-09, -1.329359730031919e-08, 5.613215294840059e-08, 2.314231769354485e-06, 6.841187317465265e-05, -1.252639141347887e-03, -6.898238868655178e-03, -1.169270619243404e-02, 1.551449780700368e-01, 1.097354415386963e+01, 4.714231883202182e+02, 2.414450275277996e+04, 3.352546306690613e+06, 2.761905221018676e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.109024940698966e-15, -6.570875769425555e-15, -9.425404532296842e-15, -1.579591712541291e-14, -3.301126999540669e-14, -9.413388288721250e-14, -4.133278921602604e-13, -3.258308445790109e-12, -5.483615462806124e-11, -2.334335614758179e-09, -3.770880066445924e-07, -1.212375586788478e-04, -8.719066423709571e-04, -9.049184259817069e-03, -4.804389191125748e-01, -9.560648043979661e+01, -4.443129535848089e+04, -7.305924995227304e+07, -1.218191491012415e+12, -7.786869496942559e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
