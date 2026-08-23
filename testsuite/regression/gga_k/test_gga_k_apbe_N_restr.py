
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_apbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.456176025308299e+01, 9.090100209294646e+01, 8.589488929570769e+01, 7.919825707668183e+01, 7.051825835434275e+01, 5.976166927838002e+01, 4.725310332502388e+01, 3.394793639166301e+01, 2.143056125748622e+01, 1.142784021193880e+01, 4.988222958142784e+00, 2.211287854566506e+00, 1.630160641117273e+00, 1.102732020732228e+00, 5.568166125692550e-01, 2.039414641335929e-01, 4.697118252901030e-02, 5.183488983577943e-03, 2.245274739729389e-04, 2.746335457367986e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_apbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.491081394020842e+02, 1.430539666549884e+02, 1.347802230775331e+02, 1.237235629391146e+02, 1.094149856528876e+02, 9.173062543597128e+01, 7.126648304480379e+01, 4.971886422141566e+01, 2.993244400951957e+01, 1.505716296786842e+01, 6.442437496856976e+00, 3.376738379511814e+00, 2.607328070011206e+00, 1.652184944152334e+00, 7.546651880392441e-01, 2.610324135544909e-01, 6.914078363345154e-02, 8.489732712125964e-03, 3.739037993364389e-04, 4.577177225492281e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_apbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.114751214479863e-05, 9.655347630342983e-05, 1.048620507484872e-04, 1.179983763872453e-04, 1.396125398800631e-04, 1.772034223018966e-04, 2.476898777602621e-04, 3.933330444380150e-04, 7.299369374025381e-04, 1.605295394231386e-03, 4.984025319308237e-03, 2.477438177346920e-02, 4.072001798909150e-02, 6.899282683633776e-02, 1.633527134256402e-01, 4.223315396836658e-01, 6.199003230822501e-01, 3.366903186174082e-01, 8.403726093141463e-02, 1.026237260419811e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_apbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.909912981287790e-01, 6.036712769201507e-01, 6.223346282120024e-01, 6.500615104625390e-01, 6.917647095573357e-01, 7.554368458574919e-01, 8.539853828657671e-01, 1.005589465343284e+00, 1.216033237704699e+00, 1.393365226127367e+00, 1.778922283573418e+00, 3.935004866273940e+00, 4.446662171757279e+00, 5.594613124958655e+00, 7.082388609292305e+00, 4.518317150504682e+00, 1.574010224346164e+01, 1.563440370276946e+02, 8.680658818817751e+02, 7.903137226371206e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_apbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.854415452858908e-07, -4.288282731237495e-07, -4.992226408696497e-07, -6.192366096878087e-07, -8.379915345162571e-07, -1.271879300140640e-06, -2.209434586001974e-06, -4.176991433094042e-06, -3.220073437968332e-06, 1.245572492333945e-04, 2.382301310167752e-03, -2.408834893383292e-02, -8.143999098234696e-02, -1.626437428925083e-01, 4.022460218394606e-01, 5.585227704713740e+01, 2.114773630005290e+03, 4.395912981548708e+04, 1.273186996172503e+06, 1.151820798193995e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_apbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.325302758161286e-12, -1.649895450529064e-12, -2.259416206535482e-12, -3.545865681333651e-12, -6.757538856673265e-12, -1.695919677409668e-11, -6.265802263085245e-11, -3.950762069703650e-10, -5.088340049097568e-09, -1.597089638668428e-07, -1.460787344077896e-05, -1.276939575510164e-03, -6.536179369126000e-03, -5.958121800152203e-02, -2.676401407281996e+00, -4.933416305259626e+02, -1.861496555262700e+05, -1.226294301043892e+08, -4.267566840317014e+11, -2.997366062750628e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
