
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_sogga_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.243299068184653e+00, -4.160617155930685e+00, -4.044823154629761e+00, -3.884553832517283e+00, -3.666453241811391e+00, -3.376797627103794e+00, -3.005336392622827e+00, -2.552261561528937e+00, -2.037682110126506e+00, -1.506151699192005e+00, -1.004261603008701e+00, -6.497119245300942e-01, -5.569085801026379e-01, -4.592811292167718e-01, -3.300633664741381e-01, -2.090458513569304e-01, -1.085312246229152e-01, -3.625084299182127e-02, -7.546616343163538e-03, -8.346433144832625e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_sogga_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.449197473507711e+00, -5.335511068791559e+00, -5.176117455617977e+00, -4.955130692711627e+00, -4.653632681445610e+00, -4.251639568291961e+00, -3.733000830068077e+00, -3.094978322864638e+00, -2.365039364920136e+00, -1.629966685952391e+00, -1.049407577864778e+00, -8.148378384722705e-01, -7.223688070439782e-01, -5.675031991365255e-01, -3.707478655670385e-01, -2.064872372614166e-01, -1.286768209695074e-01, -4.779221870937762e-02, -1.005666113729694e-02, -1.112849933186603e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sogga_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.237536399655633e-06, -2.422819221420829e-06, -2.715824566932880e-06, -3.198635903553293e-06, -4.042290699702839e-06, -5.644583530659562e-06, -9.066386768291718e-06, -1.765932688694694e-05, -4.439688431274541e-05, -1.522044880441214e-04, -7.713558440152989e-04, -4.128087167471774e-03, -7.495604514343970e-03, -1.667093152366964e-02, -6.533319227140728e-02, -3.868322370609124e-01, -1.086762135879395e+00, -1.221870399909835e+00, -1.495832545325098e+00, -1.653306548865043e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sogga_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.153276743438626e-02, -1.205356116193830e-02, -1.284457126547201e-02, -1.407492457538786e-02, -1.605498545072766e-02, -1.939995228164296e-02, -2.544649713285912e-02, -3.738958541697968e-02, -6.316872366510347e-02, -1.172170941132884e-01, -2.430374624183487e-01, -5.300898079815114e-01, -6.460552738709043e-01, -1.104602625722272e+00, -2.470676429495255e+00, -1.990854163507340e+00, 3.284839840844422e+01, -4.304943647073399e+02, -1.166002019228290e+04, -9.607308097065382e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sogga_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.491655150746548e-08, 1.709428127135476e-08, 2.078159613622601e-08, 2.748155398267772e-08, 4.094083266745412e-08, 7.208726335421751e-08, 1.597457998545720e-07, 4.791863060004859e-07, 2.035945094395604e-06, 1.007876231389087e-05, 6.739993067851201e-05, 7.344897901094605e-03, 2.245448125850858e-02, 8.134547404047630e-02, 5.899649062978428e-01, -2.099957681315454e+01, -5.187552361746209e+03, -1.452930442013922e+05, -2.090592122458949e+07, -1.712872062158322e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sogga_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.869475452404530e-14, 2.380631041720948e-14, 3.368357042414596e-14, 5.541774119032051e-14, 1.130922022764657e-13, 3.135588788435237e-13, 1.340953693537387e-12, 1.051370394752121e-11, 1.887156455648022e-10, 9.797995388180555e-09, 1.525533727503313e-06, 1.237568019415323e-04, 6.879838420629720e-04, 8.441772585127662e-03, 6.692207974463571e-01, 3.496960794706713e+02, 4.516835788342832e+05, 4.414632797907498e+08, 7.593225875796243e+12, 4.828845066337470e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
