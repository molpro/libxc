
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_kgg99_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kgg99", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.083324946478277e+00, -4.007755980981563e+00, -3.902012590429349e+00, -3.755838515350129e+00, -3.557297792909751e+00, -3.294382334257838e+00, -2.958677929321460e+00, -2.551658248816726e+00, -2.091631177476694e+00, -1.609172310187299e+00, -1.096024243925826e+00, -6.355352320493657e-01, -5.320721235475974e-01, -4.537039484749540e-01, -3.452224338935652e-01, -2.404861267102332e-01, -1.609767340814336e-01, -1.073559129962429e-01, 2.456680922301996e-04, 2.716315404406136e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_kgg99_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kgg99", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.968594940301522e+00, -4.860810984001532e+00, -4.709707559951707e+00, -4.500261461835590e+00, -4.214659560508254e+00, -3.834348594672941e+00, -3.345253830677630e+00, -2.748424046208794e+00, -2.078249228862498e+00, -1.422245068961609e+00, -9.130366224605132e-01, -7.334419479173890e-01, -6.628375054605520e-01, -5.074322285617684e-01, -3.244214467112474e-01, -1.755615522387091e-01, -8.495710802219607e-02, -3.980808473457681e-02, 3.275574563069328e-04, 3.621753872541515e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_kgg99_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kgg99", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.105653815826536e-06, -5.518915844291696e-06, -6.170317661020909e-06, -7.238373550519245e-06, -9.090302244418833e-06, -1.256429157815844e-05, -1.983354503737659e-05, -3.748067289424345e-05, -8.965832730449830e-05, -2.910679310150395e-04, -1.460446406814590e-03, -9.142773422120920e-03, -1.730946328464615e-02, -3.622604420120194e-02, -1.280298306903988e-01, -7.769067262992382e-01, -8.790812654013632e+00, -2.328489580184930e+02, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_kgg99_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kgg99", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.211215971940247e-02, -1.267964403420104e-02, -1.354080716399155e-02, -1.487746234926998e-02, -1.701806983682250e-02, -2.059331393120230e-02, -2.688872525257944e-02, -3.862431727538135e-02, -6.147396993520367e-02, -1.077952078749505e-01, -2.327336935147714e-01, -5.624132321705730e-01, -6.676063515275056e-01, -1.162973635666162e+00, -2.312406872978421e+00, -4.676104006824061e+00, -2.447258288178851e+00, 3.274139571981730e+02, 3.822817394758256e+02, 3.126948056050856e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_kgg99_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kgg99", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.073160072950847e-08, 3.498635677886380e-08, 4.210997600232950e-08, 5.483206622687456e-08, 7.970076747393450e-08, 1.347357033390772e-07, 2.782769924574815e-07, 7.363291191832404e-07, 2.541719235891340e-06, 1.101407385534829e-05, 1.153169489130407e-04, 1.345395344550352e-02, 4.839054971527646e-02, 1.378612824127329e-01, 6.580108129642305e-01, -1.878901882541560e+00, -1.788918965658281e+03, -1.666818133568685e+06, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_kgg99_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_kgg99", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.812301713052417e-14, 9.940388726982431e-14, 1.404319236071631e-13, 2.303416017886364e-13, 4.670745032938094e-13, 1.276991337954939e-12, 5.287799063570254e-12, 3.840729355870025e-11, 5.791765209083392e-10, 2.206106461021303e-08, 2.921115216347757e-06, 4.998430976176995e-04, 2.875358378247812e-03, 3.279744937644149e-02, 1.780785084613735e+00, 4.865455940082142e+02, 9.303567543684030e+05, 2.549262461765340e+10, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
