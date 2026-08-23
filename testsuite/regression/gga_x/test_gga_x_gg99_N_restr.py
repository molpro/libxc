
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_gg99_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gg99", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.293594125365622e+00, -4.213777721858786e+00, -4.102081729795152e+00, -3.947659935454011e+00, -3.737876818590678e+00, -3.459991140509190e+00, -3.105005761333603e+00, -2.674302169649816e+00, -2.187099698987626e+00, -1.676559256390210e+00, -1.139714854752773e+00, -6.673329454220890e-01, -5.598114888093255e-01, -4.760027976656673e-01, -3.603734834672632e-01, -2.489406278143506e-01, -1.646846706862677e-01, -1.085425182051662e-01, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_gg99_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gg99", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.248953845484650e+00, -5.135506638504494e+00, -4.976466412439445e+00, -4.756023355307434e+00, -4.455431594749490e+00, -4.055160336341411e+00, -3.540357606693819e+00, -2.911949273986248e+00, -2.205540590877074e+00, -1.512094330565491e+00, -9.712907702297761e-01, -7.758388990810201e-01, -6.998233258095228e-01, -5.371640274827194e-01, -3.446228461428447e-01, -1.868342203775323e-01, -8.990102349530815e-02, -4.139022501314109e-02, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_gg99_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gg99", 1)
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


def test_gga_x_gg99_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gg99", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.263399065594580e-02, -1.322321337718859e-02, -1.411720302311155e-02, -1.550449023604638e-02, -1.772560242720615e-02, -2.143454287465016e-02, -2.796624982724863e-02, -4.015818888001121e-02, -6.400536929741545e-02, -1.128759775607299e-01, -2.448203123678735e-01, -5.852318470969086e-01, -6.975902446779696e-01, -1.209373441085758e+00, -2.412913713659246e+00, -4.998882871467774e+00, -4.125352963503433e+00, 3.110281228858605e+02, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_gg99_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gg99", 1)
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


def test_gga_x_gg99_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_gg99", 1)
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
