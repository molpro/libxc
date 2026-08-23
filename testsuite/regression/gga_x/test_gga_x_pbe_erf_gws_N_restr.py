
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_erf_gws_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_erf_gws", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.026994437218132e+00, -3.945342803927853e+00, -3.831037900944666e+00, -3.672923739487069e+00, -3.457944228801050e+00, -3.172794810553788e+00, -2.807731895585802e+00, -2.363152825148118e+00, -1.856971100820165e+00, -1.322090211050163e+00, -7.925521800477621e-01, -4.184631247188357e-01, -3.276228094873457e-01, -2.397084282763589e-01, -1.224242079317645e-01, -2.981037075147760e-02, -2.919181155893102e-03, -1.005282818248164e-04, -8.970660180569615e-07, -1.212901580281747e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_erf_gws_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_erf_gws", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.104686809056558e+00, -4.990560745117341e+00, -4.830592890125829e+00, -4.608911290807871e+00, -4.306720971274934e+00, -3.904489376004347e+00, -3.387497538742681e+00, -2.757388873094914e+00, -2.053980962894519e+00, -1.382851332766538e+00, -8.441250356958830e-01, -5.630073629554454e-01, -4.753545266021958e-01, -3.373832188070252e-01, -1.801522921175306e-01, -5.416588348600874e-02, -5.733455058807309e-03, -2.006691999400972e-04, -1.793983126639794e-06, -2.425800698591938e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_erf_gws_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_erf_gws", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.806794066471597e-06, -4.114544222881366e-06, -4.599537295774927e-06, -5.394481108865004e-06, -6.772021443400403e-06, -9.352877185483524e-06, -1.473637379201295e-05, -2.767901060445989e-05, -6.458949668777210e-05, -1.899786068611500e-04, -8.074149647245357e-04, -5.156609503394615e-03, -9.017343271624075e-03, -1.551830837252306e-02, -3.045194148660309e-02, -2.149334374846513e-02, -1.451689493918664e-06, -2.443739588584798e-54, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_erf_gws_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_erf_gws", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.216033427513191e-02, -1.271464091965931e-02, -1.355486645189375e-02, -1.485702440779228e-02, -1.693797621547967e-02, -2.040247916881185e-02, -2.646140478963556e-02, -3.746704061345587e-02, -5.596923828148315e-02, -6.843817168264300e-02, -8.464704338910353e-02, -4.839272037486265e-01, -6.018078833885147e-01, -8.823515981240234e-01, -1.435595338279085e+00, -3.474999977668964e+00, -5.561041327607367e+00, -6.202837151927219e+00, -6.279709352169502e+00, -6.283142794833213e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_erf_gws_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_erf_gws", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.317047790278313e-08, 2.639225404053333e-08, 3.178976371889916e-08, 4.143627910059097e-08, 6.030239800310152e-08, 1.019971658363809e-07, 2.095793345846046e-07, 5.323819974808606e-07, 1.334717390586477e-06, -8.488827140023111e-06, -3.436608201134293e-04, 5.909291130172027e-03, 1.970083505186029e-02, 3.332040668221548e-02, -1.283858209087831e-01, -2.480510084635948e+00, -1.229903436570885e-02, -6.206800670650746e-48, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_erf_gws_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_erf_gws", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.419048653907010e-14, 6.891373030763263e-14, 9.730179724799087e-14, 1.595519018722231e-13, 3.238045597355562e-13, 8.891186481166454e-13, 3.733551864791658e-12, 2.819086008273639e-11, 4.647456255502216e-10, 1.993546453530402e-08, 2.551515536488010e-06, 2.971064033872864e-04, 1.605436712624534e-03, 1.396832518490692e-02, 3.836586186046845e-01, 3.771643407098082e+00, 1.828646358421465e-06, 4.591349601207019e-99, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
