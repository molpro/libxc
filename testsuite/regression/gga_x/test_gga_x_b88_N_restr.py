
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_b88_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.322854093434036e+00, -4.241122383748296e+00, -4.126686631982516e+00, -3.968352585618511e+00, -3.752994112140284e+00, -3.467181958165918e+00, -3.100978869584120e+00, -2.654660394307861e+00, -2.147215516271833e+00, -1.617616953612773e+00, -1.089640013317294e+00, -6.680731775676256e-01, -5.648783017930552e-01, -4.747588853263802e-01, -3.509396684638344e-01, -2.331332763357188e-01, -1.464411431667579e-01, -9.075621279207406e-02, -5.846477495628764e-02, -4.057493874739779e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_b88_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.378626078498024e+00, -5.264924253161032e+00, -5.105569699987646e+00, -4.884767513426062e+00, -4.583805328681359e+00, -4.183152977896851e+00, -3.667627760603533e+00, -3.036358056225545e+00, -2.319054503931975e+00, -1.598326715267790e+00, -1.026329835963002e+00, -8.013374988564269e-01, -7.146645705978429e-01, -5.573301363945710e-01, -3.636478987182616e-01, -1.962082841069470e-01, -9.213593553174576e-02, -4.022728163599630e-02, -1.596312448236549e-02, -6.636147118775232e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.132900774748393e-06, -4.456446692562663e-06, -4.965022326051273e-06, -5.795700394115836e-06, -7.228605422367479e-06, -9.898979949294432e-06, -1.544647249186866e-05, -2.884711503255185e-05, -6.862601545704256e-05, -2.247424238226912e-04, -1.136023617335683e-03, -7.175883450225559e-03, -1.430560884113080e-02, -2.811764004791372e-02, -9.825111261564357e-02, -6.138508638598922e-01, -6.990355864843389e+00, -1.820304068158301e+02, -1.687782013050708e+04, -1.003549943209943e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.196547179074747e-02, -1.250027419656556e-02, -1.331047907319828e-02, -1.456566123517898e-02, -1.657285768936258e-02, -1.992874098920413e-02, -2.589376116717243e-02, -3.738358513337738e-02, -6.169662915420078e-02, -1.177615287951307e-01, -2.663813344054595e-01, -5.431169808365875e-01, -6.711178096049800e-01, -1.119683961816935e+00, -2.410104651520154e+00, -5.900081266504094e+00, -7.772800357595749e+00, 1.695989851981302e+02, 1.849560037834291e+04, 1.040013640392899e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.096879216827732e-08, 2.379646417585565e-08, 2.852106720683055e-08, 3.694077802211115e-08, 5.337997832154542e-08, 8.986359196750836e-08, 1.864807552111823e-07, 5.103650005886789e-07, 1.965589239841020e-06, 1.101781931200655e-05, 1.423282395945326e-04, 8.973291390982121e-03, 3.408585904561098e-02, 9.284697138182083e-02, 5.661749578563722e-01, 1.509514865646448e+00, -1.593085299313514e+03, -1.320983909048513e+06, -1.010809695627821e+10, -3.410371474603602e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b88_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.051673135482516e-13, 1.311804715720056e-13, 1.801291755856713e-13, 2.837364243895923e-13, 5.434170162238428e-13, 1.372790980531268e-12, 5.118455732489723e-12, 3.279092670109517e-11, 4.407737495345834e-10, 1.602256477232604e-08, 2.132048942376924e-06, 5.196017280162181e-04, 4.570921336980948e-03, 3.071617290362377e-02, 1.308910789109244e+00, 3.683976176900498e+02, 7.513712120117494e+05, 1.996937337018639e+10, 2.420410235766570e+16, 8.048936755352179e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
