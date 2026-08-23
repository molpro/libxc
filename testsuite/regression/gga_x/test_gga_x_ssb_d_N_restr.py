
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ssb_d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.515661441681432e+00, -4.427141874316534e+00, -4.303506749218458e+00, -4.133150543917491e+00, -3.903131581664526e+00, -3.602028650609288e+00, -3.226466871043382e+00, -2.791465327978399e+00, -2.332074549939338e+00, -1.864529604066574e+00, -1.280331440601925e+00, -6.863374020140517e-01, -5.898158654317487e-01, -4.805369982453220e-01, -3.564273719019109e-01, -2.334798086872519e-01, -1.217027780719320e-01, -4.191789596237831e-02, -8.769842343835167e-03, -9.701621398012670e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ssb_d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.841888204854293e+00, -5.707576667572940e+00, -5.517450516642780e+00, -5.250003662551191e+00, -4.877078837225382e+00, -4.364174873655605e+00, -3.678691715963585e+00, -2.831380038027047e+00, -1.964073896466397e+00, -1.262660716274218e+00, -8.311690383414002e-01, -8.443654541232419e-01, -7.912023316019273e-01, -5.753165796155731e-01, -3.470617514514662e-01, -2.220357994676544e-01, -1.389492274520399e-01, -5.468030320819148e-02, -1.168101506095558e-02, -1.293532299625711e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.920903444292295e-06, -2.232348257907386e-06, -2.761112432323284e-06, -3.721176917764225e-06, -5.628277765741368e-06, -9.873637830769831e-06, -2.062066847609166e-05, -5.108025116552146e-05, -1.446981522071665e-04, -4.951720216132695e-04, -2.408095260581686e-03, -6.239175986342999e-03, 6.775833467730771e-04, -2.666853324141351e-02, -1.251584511603280e-01, -4.832958634029534e-01, -1.586301437802383e+00, -2.732480324138929e+00, -3.302011423522203e+00, -3.646315168183145e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.697742614310590e-02, -1.823062245176887e-02, -2.021999607580529e-02, -2.350178828248345e-02, -2.917448899830970e-02, -3.940352827626632e-02, -5.765312214497154e-02, -8.413973159129025e-02, -1.055565006730836e-01, -1.540107881176344e-01, -2.775163611617628e-01, -1.036977881726877e+00, -7.331038296806265e-01, -2.244359025844926e+00, -1.644606393176993e+00, 3.754075639698084e+00, 2.338471160409553e+01, -4.214278684207662e+02, -1.346351993034945e+04, -1.116631130742122e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.549912042160544e-08, 7.928662001701524e-08, 1.038732108127050e-07, 1.516323241322834e-07, 2.553703518685484e-07, 5.127889383834102e-07, 1.235175416990742e-06, 3.302920530269031e-06, 8.419311710533106e-06, 3.451402641577467e-05, 3.897304181178148e-04, 4.838159976029494e-02, 3.796898596603140e-02, 5.102179931247248e-01, -6.036052246100297e-02, -5.413391357147250e+01, -4.782372820835718e+03, -3.264754484206955e+05, -4.601748650886215e+07, -3.766551883390014e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ssb_d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ssb_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.493944062523573e-13, -7.043271645782253e-13, -1.001538823297951e-12, -1.642351872072360e-12, -3.255554222306024e-12, -8.157566776848218e-12, -2.579556643873619e-11, -7.958662390792067e-11, 3.863112844484854e-10, 3.065860630585240e-08, 3.953067115491797e-06, -2.998596807254056e-03, -1.756940865353203e-02, -1.387062215509142e-01, 2.239403017314748e+00, 5.798190926425598e+02, 4.692032533712859e+05, 9.897481493603694e+08, 1.671228389118642e+13, 1.061846485707880e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
