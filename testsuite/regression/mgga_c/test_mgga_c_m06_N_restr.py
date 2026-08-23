
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m06_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.009000646259122e-01, -9.911266822564657e-02, -9.654281501927775e-02, -9.285532267869606e-02, -8.759133622869959e-02, -8.017373597105232e-02, -7.005715622621578e-02, -5.735175965513055e-02, -4.425473546947502e-02, -3.539654668655412e-02, -5.539285898880242e-02, -1.074527132650714e-01, -4.629136120397109e-02, -3.000409454130248e-02, -2.480273578005692e-02, -1.105449656777722e-03, 9.209707025061862e-03, -1.285854371630841e-03, -5.127173846079460e-04, -4.704011805621754e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m06_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.190768917760805e-01, -1.185308486136215e-01, -1.175956385494947e-01, -1.159400122213262e-01, -1.129329586733964e-01, -1.074501638433856e-01, -9.798611540306618e-02, -8.524277141774143e-02, -8.460700343856062e-02, -1.341487252486088e-01, -1.822424302546654e-01, 9.536373777984533e-03, -4.592397523725483e-02, -4.759326533105260e-02, -4.644098088260417e-02, -1.102270736985607e-01, -1.471234986918534e-02, -3.000157332936320e-02, -1.125131102680997e-02, -1.636492106211041e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.262722037864407e-06, -1.315548782948713e-06, -1.395831674282033e-06, -1.520736996684672e-06, -1.720908433307347e-06, -2.049172550575745e-06, -2.553029819529943e-06, -2.760291978530666e-06, 3.791466049438182e-06, 7.472606031399901e-05, 7.272620620058757e-04, 5.550998665330545e-03, 1.054926699628895e-02, 6.975410891725195e-03, 5.216178566563304e-02, 9.737398055216866e-01, 6.711231255049015e+00, 1.847846759285374e+02, 7.715528099502719e+03, 8.878440117585968e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.118341681053327e-03, 3.093321940103772e-03, 3.056924741001813e-03, 3.002933995913774e-03, 2.919095801993054e-03, 2.775645851252875e-03, 2.486635196521707e-03, 1.797673723900044e-03, 1.574887838009129e-04, -2.370848623069869e-03, -4.792650027540938e-03, -1.735146375905975e-02, -1.370917872936111e-02, -2.924006145915252e-03, -2.308260367257145e-02, -4.975084939133894e-02, -5.637782641188063e-02, -4.669447264187625e-02, -1.705730540601847e-02, -2.694652734649309e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.268467626391136e-05, -1.184225686687574e-04, -1.934374572311754e-04, -3.201419317233532e-04, -5.366353385379621e-04, -8.818480171875543e-04, -1.189179377291074e-03, 5.082238783492806e-04, 1.792253101584776e-02, 1.001817017297580e-01, 2.805893335896719e-01, -1.842215949478917e-01, 4.744013561821057e-02, -4.863243291458005e-01, 3.334651846094796e+00, -3.351747518820965e+00, 5.955592110458208e+01, 3.693951081736574e+02, -1.947813188109897e+04, -2.565929309568929e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.215887114994718e-10, 1.630708173869593e-09, 2.923412000947500e-09, 5.425776276284804e-09, 1.047688390472725e-08, 1.990408710463787e-08, 2.180907218826555e-08, -2.203191215603764e-07, -4.164215328310057e-06, -5.457552573982591e-05, -3.374572062014446e-04, -1.065470657471025e-02, -6.624511707295887e-02, 1.287664800806706e-01, -4.227411305095319e+00, -4.220906555814042e+00, -1.123338957275037e+04, -1.429911565082346e+06, 6.788698514692940e+09, 7.091693876691886e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.532910189990896e-06, -1.882138222149650e-06, -2.392699027204248e-06, -3.079517800069156e-06, -3.687108602406983e-06, -2.461472612586319e-06, 1.000821267351218e-05, 7.942425389768450e-05, 3.744640707773267e-04, 8.688339636082527e-04, -5.222141143344572e-03, 2.786634019850473e-02, 4.725398070805527e-02, 6.601688406002525e-02, 6.573694433689551e-01, 1.777997887615199e+00, 7.999556505388318e+01, 5.140016465503566e+01, -1.551350887148862e+04, -2.152980749637296e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.846254214353358e-13, -2.341770788072051e-13, -3.273262831785313e-13, -5.218295175701706e-13, -9.868372966983933e-13, -2.283173767619090e-12, -6.207522293460645e-12, -8.569183686012590e-12, 4.434038957142730e-10, 1.891611638325758e-08, -3.079233068463504e-06, 4.286954667752762e-04, 1.820036933077689e-03, -1.606565606732958e-01, 2.410323995110399e+00, -5.063810356807159e+01, 2.001663439957497e+06, 1.107017837888620e+10, 2.668765707883218e+14, 2.030977665792110e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.698629333964189e-10, 7.631296486501250e-10, 9.199228048286030e-10, 1.201072454756427e-09, 1.750828319568794e-09, 2.947742438232133e-09, 5.835512792376114e-09, 1.246688042351733e-08, 7.524070558004496e-09, -3.209965210363835e-07, 2.481286088122058e-05, -7.387150684696064e-04, 8.691390118445611e-03, 1.481327119852551e-01, 2.986615362734313e-01, -7.657423462410638e+01, -2.192403551311544e+04, -1.025426263186380e+07, -4.371252430967403e+10, -3.935634517287978e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.734699911768945e-06, -1.848451044140927e-06, -2.025750213650904e-06, -2.311546901844654e-06, -2.793695670479045e-06, -3.654663809017669e-06, -5.276836994477642e-06, -8.262268836390608e-06, -1.125118820256836e-05, 4.059468653267297e-06, -7.672638944140191e-05, -2.959542082486536e-04, -2.101852216300371e-02, -2.674292842126830e-01, -4.924741718073296e-01, 1.001972431833385e+01, 2.089592296406352e+02, 4.480096140586686e+03, 1.919729851909958e+05, 2.388783990139160e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
