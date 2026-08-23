
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_tm_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.783414672102261e-02, -5.666623495240614e-02, -5.499667555523494e-02, -5.261656527499328e-02, -4.923792407350122e-02, -4.447668499025106e-02, -3.786475085783125e-02, -2.900528226543940e-02, -1.828936807125369e-02, -8.735148694954167e-03, -6.296967346680570e-03, -5.170453793223746e-02, -6.747290165779091e-02, -4.653518463424468e-02, -2.116529394524173e-02, -4.405298192098008e-03, -2.770681339641412e-04, -4.090345456659305e-06, -5.704880232875256e-09, -2.091022234765221e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_tm_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.422209466783640e-01, -1.408244536594988e-01, -1.388060345627662e-01, -1.358784247578897e-01, -1.316040598811393e-01, -1.252849107993584e-01, -1.157210777901411e-01, -1.006770805996040e-01, -7.646198911446021e-02, -4.457033277198982e-02, -3.403985405888088e-02, -1.290031680298426e-01, -8.972231526421248e-02, -1.193768904097235e-01, -8.526632654425803e-02, -2.542608052738846e-02, -1.750103558246521e-03, -2.605555339579806e-05, -3.706428357895394e-08, -1.381847892233844e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tm_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.192771679112366e-07, 9.766065555172390e-07, 1.065097671947073e-06, 1.205811863298613e-06, 1.439006933343793e-06, 1.847675454628101e-06, 2.616636752764360e-06, 4.177789166766522e-06, 7.472028027466886e-06, 1.471338162678679e-05, 7.571377479167964e-05, 6.346492042644491e-03, 6.054718559823619e-03, 2.764197345151244e-02, 6.259602210700704e-02, 1.165195684887456e-01, 1.022988020529556e-01, 4.951840526138506e-02, 8.289109551843959e-03, 2.357972552899320e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tm_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.744764850224751e-04, -6.142182510642275e-04, -6.766021705499922e-04, -7.785094836033685e-04, -9.550954400423354e-04, -1.289210647104092e-03, -2.009267773504666e-03, -3.864169470561507e-03, -9.480903956959417e-03, -2.498992950680563e-02, -8.000367732806656e-02, -4.936529704526758e-02, 2.599301351146055e-01, -5.285541715205679e-02, -2.259380289347388e+00, -9.412452403337429e+00, -9.486230417661297e+00, -4.353551298773367e+00, -7.129610804751162e-01, -2.006850918999702e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_tm_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.301086701457038e-09, 7.175856292731661e-09, 8.655468303405647e-09, 1.134619809506457e-08, 1.678580393318046e-08, 2.963471480434325e-08, 6.782202432680118e-08, 2.259189593488231e-07, 1.219692263475184e-06, 1.026729969541483e-05, 2.184868411445077e-04, 3.098151632991340e-03, -1.186078688950863e-01, 3.624406714584935e-03, 2.199748600291446e+00, 5.226071724753297e+01, 6.598105267205525e+02, 9.827477867107940e+03, 1.885995053023275e+05, 4.036130234581963e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_tm_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_tm_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.602384904345486e-13, -1.934663280644474e-13, -2.536971780405786e-13, -3.746197918562524e-13, -6.560539086452634e-13, -1.467526653761447e-12, -4.660873132603231e-12, -2.435134779864686e-11, -2.498398422537626e-10, -5.875673755529367e-09, -8.032572612902243e-07, -1.521211540928562e-03, 4.185946425649269e-02, -7.367902125950618e-02, -3.577290350318805e+00, -3.775701029994684e+02, -5.745553537012130e+04, -2.793605340768450e+07, -6.325248804324837e+10, -1.033077939603532e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
