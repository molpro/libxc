
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_22_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.247992344530460e+00, -5.145820687238971e+00, -5.002446746356627e+00, -4.803354900161931e+00, -4.530886301163094e+00, -4.165206742611395e+00, -3.686228069791217e+00, -3.074836324559261e+00, -2.314588768157370e+00, -1.460979751932119e+00, -8.102378761362571e-01, -5.573600356619611e-01, -5.796905570263540e-01, -5.041665317167318e-01, -3.291833511436482e-01, -1.617419405940490e-01, -6.537114148857896e-02, -2.049518489805472e-02, -4.235214813322404e-03, -4.685046556040608e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_22_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.358852307647137e+00, -6.219129435988828e+00, -6.023755909481160e+00, -5.754101909338514e+00, -5.389134523850991e+00, -4.909856262380951e+00, -4.310293602840258e+00, -3.617027342670661e+00, -2.877949325431939e+00, -1.993600493056879e+00, -1.114737619568082e+00, -7.921219236740807e-01, -8.762683384214809e-01, -6.885580557897839e-01, -4.520447486178433e-01, -2.191256801616104e-01, -8.575815652361696e-02, -2.670156897070072e-02, -5.500025568901475e-03, -6.072257812568549e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_22_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.330429522157157e-05, -1.438934645099613e-05, -1.609893577055316e-05, -1.889877361197267e-05, -2.373851100568821e-05, -3.274185148359956e-05, -5.113855748763523e-05, -9.262645191581215e-05, -1.885180789183578e-04, -3.604202924718729e-04, -6.132457505079180e-04, -3.474171438810435e-03, -2.631916949192040e-02, -6.669948234476551e-02, -1.715438295851544e-01, -3.562816327158668e-01, -7.472660941085553e-01, -4.364365972611297e+00, -1.074194185503134e+02, -9.837989075302072e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_22_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.468109770115833e-02, 1.508440042449842e-02, 1.568488706682849e-02, 1.659151939864172e-02, 1.798534962918103e-02, 2.017136598666572e-02, 2.362738729024383e-02, 2.871619217427107e-02, 3.292167869411307e-02, 2.464828792294085e-02, 8.320481697287998e-03, 8.038623208524810e-03, 6.937210018176700e-02, 1.144786409925040e-01, 1.211086235735640e-01, 4.777725080161233e-02, 7.414834562812631e-03, 1.143454175664134e-03, 2.380466621910844e-04, 2.985980640552786e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_22_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.798878317225054e-02, -1.883390617841165e-02, -2.010440910947693e-02, -2.204358914762033e-02, -2.505055828579399e-02, -2.974368690566508e-02, -3.679358695787505e-02, -4.554421714186711e-02, -5.676336903570307e-02, -1.404650156564441e-01, -3.244122329120573e-01, -8.286761464320156e-01, -9.910928462331451e-01, -1.315534548835508e+00, -2.833925672842054e+00, -8.455996263247767e+00, -3.426635477998271e+01, -3.347385805286668e+02, -7.881700423855094e+03, -6.476130485966203e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_22_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.654546586813057e-08, 1.105723816737665e-07, 1.342247245078793e-07, 1.768695230606339e-07, 2.611998155504267e-07, 4.496162903500023e-07, 9.347259408255632e-07, 2.280103947608407e-06, 3.799317668762171e-06, -3.482173959069688e-05, -5.037393498267535e-04, -8.076150701548780e-03, 1.815877340867167e-02, 1.250301279215891e-01, -1.066212298684786e+00, -3.190686833138930e+01, 1.208883730908248e+02, 3.228610646206032e+05, 1.058363305327863e+09, 6.954298733957279e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_22_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.943815557548801e-05, -7.693341426514841e-05, -8.908347792176907e-05, -1.097825305515660e-04, -1.475003946381621e-04, -2.223018270827869e-04, -3.832785618388144e-04, -7.136525180738033e-04, -7.829140833004021e-04, 2.992109848165045e-03, 8.873489880672119e-03, 4.382057714043426e-02, 9.232941371245049e-02, -5.585837349668207e-02, 1.064996452222324e+00, 5.555537448047522e+00, 2.600963245955921e+00, -7.418180444325677e+01, -2.330794483602358e+03, -2.110568269179953e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_22_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.075800535926245e-13, -2.634411940562380e-13, -3.707488501976294e-13, -6.046124171659006e-13, -1.215024937557848e-12, -3.272590286630603e-12, -1.317111746546305e-11, -8.933252835628220e-11, -1.088949338991980e-09, -2.177972019006011e-08, -8.375598033467156e-07, -6.920833796127553e-05, -3.038801667987218e-03, -4.561294775060167e-02, -1.761890511422155e+00, -2.193245557732430e+02, -2.023503540656278e+05, -2.391895719244626e+09, -8.624285257778554e+14, -4.400123053064933e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_22_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.334198868412863e-10, 6.447383057396968e-10, 8.463935504572972e-10, 1.250466423364145e-09, 2.185906145798541e-09, 4.844269370809139e-09, 1.488761026774489e-08, 6.979099810189432e-08, 5.076001408782866e-07, 4.463847931024542e-06, 4.172261121962571e-05, 1.430336822365056e-03, 3.001518057576374e-02, 2.420380223476953e-01, 3.939943374414212e+00, 7.757939973996379e+01, 2.989571994045415e+03, 8.016270736384580e+05, 2.509857568310792e+09, 1.771517255048615e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_22_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_22", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.855447708684983e-07, -2.279900280545444e-07, -3.046034281890474e-07, -4.566503382033945e-07, -8.009873152683793e-07, -1.735273978842747e-06, -4.952223153076033e-06, -1.959496770291558e-05, -9.971167879688770e-05, -4.053224515210105e-04, -8.257030402108129e-04, -5.747486053167878e-03, -9.134347272028967e-02, -4.525434053640128e-01, -3.629063218316059e+00, -1.461296146313767e+01, -3.793643519166917e+01, -2.558172097445557e+02, -6.888659518651234e+03, -6.700191207029574e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
