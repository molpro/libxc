
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_b86_mgc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_mgc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.318161302455765e+00, -4.236638803317721e+00, -4.122520977980008e+00, -3.964679307402086e+00, -3.750100757176441e+00, -3.465553029197978e+00, -3.101428918715674e+00, -2.658435934686377e+00, -2.155364835297247e+00, -1.627121100630949e+00, -1.095174896037782e+00, -6.678700230483765e-01, -5.642040246638751e-01, -4.749529828901011e-01, -3.527562259420024e-01, -2.317639096221179e-01, -1.277864074049916e-01, -5.341009874497773e-02, -1.648562744650844e-02, -3.610444875566587e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_b86_mgc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_mgc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.364927455953434e+00, -5.250523013121335e+00, -5.090152853650512e+00, -4.867887435304524e+00, -4.564842317979067e+00, -4.161333369623141e+00, -3.642335139054937e+00, -3.008670451015212e+00, -2.297371953490298e+00, -1.606963972835251e+00, -1.050309476784238e+00, -7.967509014545170e-01, -7.137548416739358e-01, -5.531635381602353e-01, -3.617539415858522e-01, -2.150065122278670e-01, -1.255678039926813e-01, -5.415310592343028e-02, -1.576249922638135e-02, -3.175107830603748e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_mgc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_mgc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.212747369377988e-06, -4.552719336732719e-06, -5.088467769724626e-06, -5.966594835003933e-06, -7.488464977049264e-06, -1.034125267632760e-05, -1.630287824620488e-05, -3.072300104587171e-05, -7.273276807097895e-05, -2.263661096290143e-04, -1.091810904586020e-03, -7.522190810264555e-03, -1.430958132185227e-02, -2.976178448019881e-02, -1.023179426929923e-01, -5.034136378271323e-01, -3.037913010629482e+00, -3.844349564489772e+01, -1.693049428015245e+03, -3.465035207691026e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_mgc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_mgc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.231523269381324e-02, -1.287884043883301e-02, -1.373330260810070e-02, -1.505787390705028e-02, -1.717567437638126e-02, -2.070535704506412e-02, -2.689751790390970e-02, -3.827721383394755e-02, -5.857083397474979e-02, -8.254962855581602e-02, -1.342395967316474e-01, -5.645749677430995e-01, -6.848339105549698e-01, -1.161235165791007e+00, -2.057790877014068e+00, 5.483585665884736e-01, 1.770139195488525e+01, -6.643383691068263e+01, -8.290828093877362e+02, 6.548670650666942e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_mgc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_mgc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.499523947471876e-08, 2.844901808047105e-08, 3.423027061678909e-08, 4.455100553255014e-08, 6.470907187268920e-08, 1.092165230726016e-07, 2.243003765839259e-07, 5.764842954014658e-07, 1.625600367321443e-06, -3.348223485768684e-06, -2.228760352073035e-04, 1.089323368881116e-02, 3.945554043623060e-02, 1.107000980418983e-01, 2.430822713862806e-01, -3.590273773634576e+01, -4.089211149035275e+03, -1.114108816228902e+06, -4.782869653338003e+09, -7.180732332623858e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_mgc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_mgc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.834288421258503e-14, 8.671340117751509e-14, 1.220243378767659e-13, 1.990996375365701e-13, 4.010664669452595e-13, 1.088865834392996e-12, 4.493318114146103e-12, 3.303538584677957e-11, 5.248898576332352e-10, 2.195134398213283e-08, 3.007021529976538e-06, 4.253647303460787e-04, 2.580808408081504e-03, 2.789643272391703e-02, 1.689609214077099e+00, 5.009997210774816e+02, 5.568075136796171e+05, 6.099244986677485e+09, 3.454113488624808e+15, 4.048406846058229e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
