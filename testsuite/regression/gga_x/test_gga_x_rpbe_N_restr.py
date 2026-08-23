
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_rpbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.306453652553500e+00, -4.224906683576045e+00, -4.110771066147022e+00, -3.952942793355896e+00, -3.738473911230778e+00, -3.454303538722290e+00, -3.091287604394670e+00, -2.651425661416988e+00, -2.156951976366422e+00, -1.647523002707534e+00, -1.119514676594776e+00, -6.656784620279729e-01, -5.629574100994720e-01, -4.734306759612779e-01, -3.545898226878630e-01, -2.435892417874267e-01, -1.314221077632599e-01, -4.238120640772890e-02, -8.774367452886237e-03, -9.701687044429635e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_rpbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.367706297653794e+00, -5.252669211520759e+00, -5.091314815452698e+00, -4.867470815040472e+00, -4.561789722416929e+00, -4.153647212950307e+00, -3.625997484979228e+00, -2.975271681781840e+00, -2.230881741153691e+00, -1.497115244426831e+00, -9.569115711369954e-01, -7.947383428239112e-01, -7.144896426350010e-01, -5.499991016496825e-01, -3.450294296636506e-01, -1.947637804952149e-01, -1.642579263302345e-01, -5.650827521030492e-02, -1.169915660384832e-02, -1.293558272590618e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rpbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.015436484596593e-06, -4.349398732862157e-06, -4.877834228880915e-06, -5.749352801797784e-06, -7.274286039885074e-06, -1.017663226389392e-05, -1.639601475109518e-05, -3.210185287098375e-05, -8.138911679443232e-05, -2.815164409929949e-04, -1.427008478207484e-03, -7.449207838297108e-03, -1.341908533782757e-02, -3.018335153302100e-02, -1.203804326541200e-01, -6.962383693088999e-01, -7.437533499100274e-01, -6.148154980139533e-13, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rpbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.253300896605349e-02, -1.313171974533096e-02, -1.404488319108967e-02, -1.547390384405564e-02, -1.779414209932829e-02, -2.176420850863191e-02, -2.906983163630063e-02, -4.381463627445904e-02, -7.586223028929023e-02, -1.335511123972557e-01, -2.379923117215595e-01, -5.979898401010857e-01, -6.889383291010553e-01, -1.269814497775251e+00, -2.953195998998915e+00, 4.408692966191256e+00, 5.048989050095715e+01, -5.852421858000966e+02, -1.365370822982718e+04, -1.116831697629218e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rpbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.727643983666774e-08, 3.129077527847306e-08, 3.809873439993031e-08, 5.049905508147891e-08, 7.550308556908290e-08, 1.337105705864633e-07, 2.991344604963692e-07, 9.118968005490288e-07, 3.974162125382721e-06, 1.967473591021917e-05, 1.050770729687241e-04, 1.366146670988502e-02, 4.075907250229721e-02, 1.528747836588296e-01, 1.165191658349328e+00, -5.347020787830162e+01, -7.202157996674689e+03, -1.831039134132653e-06, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_rpbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_rpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.810378365895892e-14, 3.583948708288897e-14, 5.081865755489454e-14, 8.388399921650517e-14, 1.720635638178397e-13, 4.810316486799504e-13, 2.086218432151406e-12, 1.677254145339659e-11, 3.154436170616800e-10, 1.770657406730987e-08, 2.874475453279717e-06, 1.906250420678719e-04, 1.023735453826982e-03, 1.320519570489729e-02, 1.159447609086001e+00, 7.133309290423089e+02, 5.566824310661309e+05, 4.183423058319253e-03, 1.976262583364986e-323, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
