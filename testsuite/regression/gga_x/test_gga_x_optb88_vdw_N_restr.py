
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_optb88_vdw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb88_vdw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.292312749390728e+00, -4.210159157485233e+00, -4.095115059815424e+00, -3.935902788498297e+00, -3.719274757678311e+00, -3.431626077581438e+00, -3.062776268599864e+00, -2.612727987019264e+00, -2.100524303356526e+00, -1.567553041517516e+00, -1.050535166002770e+00, -6.608174570589481e-01, -5.618605792179528e-01, -4.685416060419053e-01, -3.418036443952420e-01, -2.220608146610167e-01, -1.351011500996079e-01, -8.097988687573579e-02, -5.088491036560079e-02, -3.494423265068566e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_optb88_vdw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb88_vdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.409541085623778e+00, -5.296041792028340e+00, -5.136964053029990e+00, -4.916529259433749e+00, -4.616029268143927e+00, -4.215895803659299e+00, -3.700785818821465e+00, -3.069342550674041e+00, -2.350041558863265e+00, -1.623395806860512e+00, -1.042883470463082e+00, -8.079034296245405e-01, -7.178890058093996e-01, -5.626087730542387e-01, -3.689864278646504e-01, -1.991155229726098e-01, -9.170287298662973e-02, -3.846451607502591e-02, -1.455410772680663e-02, -5.799331262111736e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optb88_vdw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb88_vdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.364251675992415e-06, -3.628926006488901e-06, -4.045189715505557e-06, -4.725637601433846e-06, -5.900800755818202e-06, -8.094776481062180e-06, -1.266501835185043e-05, -2.375092762155847e-05, -5.686129219350704e-05, -1.877930590601040e-04, -9.530621694607115e-04, -5.872716601466521e-03, -1.161286887899338e-02, -2.307666299670959e-02, -8.174280012517013e-02, -5.192291336811646e-01, -5.994739805813430e+00, -1.566295354092270e+02, -1.450978432600187e+04, -8.625060894410286e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optb88_vdw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb88_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.170232104358765e-02, -1.222206576429831e-02, -1.300946299237500e-02, -1.422941484014520e-02, -1.618084991666890e-02, -1.944618729639612e-02, -2.526255184346556e-02, -3.652511677291072e-02, -6.065967391771999e-02, -1.177598700791598e-01, -2.697010172018379e-01, -5.298913130749056e-01, -6.580586760268322e-01, -1.092554150392040e+00, -2.385980735199691e+00, -6.218383867673766e+00, -1.211084040891492e+01, 1.069893254091145e+02, 1.501792212870320e+04, 8.859369925224891e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optb88_vdw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb88_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.752782076555959e-08, 1.991288491212774e-08, 2.390435451077416e-08, 3.103462473032987e-08, 4.500710819539919e-08, 7.619330437970972e-08, 1.595464448211510e-07, 4.434130287865307e-07, 1.757000274868001e-06, 1.044670040460589e-05, 1.420222652207009e-04, 7.628452981056497e-03, 2.826310705895458e-02, 7.970698431620941e-02, 5.184170382624312e-01, 2.768195353520228e+00, -1.289048222099522e+03, -1.138761551885515e+06, -8.713518050955217e+09, -2.931840058035687e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optb88_vdw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb88_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.068443608570656e-14, 1.007043506063484e-13, 1.384073448431845e-13, 2.183110193366180e-13, 4.189566436417881e-13, 1.061617692549988e-12, 3.976975755270813e-12, 2.566741587951818e-11, 3.490130278132931e-10, 1.288923054477433e-08, 1.728435220484853e-06, 4.023913580423238e-04, 3.490151063240588e-03, 2.390684511529031e-02, 1.044348935741660e+00, 3.036252300784666e+02, 6.391264282034287e+05, 1.718756401945720e+10, 2.081459010836682e+16, 6.917864231161923e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
