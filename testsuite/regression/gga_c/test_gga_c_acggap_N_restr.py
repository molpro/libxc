
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_acggap_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acggap", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.691442202079509e-02, -6.589510520246496e-02, -6.443326977731763e-02, -6.233951031862863e-02, -5.934663734292966e-02, -5.508346878250163e-02, -4.905551711960354e-02, -4.069365609119997e-02, -2.975139738820119e-02, -1.801562145924553e-02, -1.352213373471052e-02, -4.445713856747385e-02, -5.318095379625753e-02, -3.821230320503867e-02, -2.164302994919700e-02, -7.187806373545992e-03, -7.821644070177717e-04, -1.439956905002489e-05, -2.042034632954975e-08, -7.999283653426075e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_acggap_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acggap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.317821346097610e-01, -1.308499360558626e-01, -1.294986221496674e-01, -1.275318444687599e-01, -1.246505686255841e-01, -1.203835453023575e-01, -1.139474217715536e-01, -1.039507331367251e-01, -8.795378576184126e-02, -6.444543276452155e-02, -5.216106449453502e-02, -8.767776245870236e-02, -8.172529587672157e-02, -7.814223432588641e-02, -6.158580615023521e-02, -2.965873503990968e-02, -4.239992615829392e-03, -8.719946518417090e-05, -1.288458679155275e-07, -5.195450260201427e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_acggap_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acggap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.789314822725369e-07, 7.246116537999755e-07, 7.955388960443977e-07, 9.093302906444726e-07, 1.100515846354187e-06, 1.443094999834918e-06, 2.113329847192614e-06, 3.584087986056175e-06, 7.290299350678642e-06, 1.863377600270487e-05, 1.028861107210741e-04, 3.256660611625039e-03, 8.831021289629952e-03, 1.392884327462360e-02, 3.698981344598366e-02, 1.210601259660153e-01, 2.362158986467229e-01, 1.615283578939940e-01, 2.832189468724711e-02, 8.791668004673062e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_acggap_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acggap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.661766556761922e-04, -2.874410170777310e-04, -3.210251850003849e-04, -3.763154674893814e-04, -4.729994264271209e-04, -6.575888879814231e-04, -1.058008216262429e-03, -2.098806046508715e-03, -5.486683823277015e-03, -1.835871365995142e-02, -6.505999163836641e-02, -2.262256765740273e-02, 6.540782573970607e-03, -6.303070831632296e-02, -7.414587343689578e-01, -5.902030934311367e+00, -1.789643961351826e+01, -1.357598540415315e+01, -2.387602936047703e+00, -7.373108719783306e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_acggap_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acggap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.555622765831155e-09, 2.950225396810405e-09, 3.626107236689460e-09, 4.876320861761755e-09, 7.460612198344536e-09, 1.373414814944641e-08, 3.295776241296088e-08, 1.153242056555584e-07, 6.754498072225088e-07, 7.307170089282219e-06, 1.719359442971602e-04, 7.033769138921796e-04, -1.162367385325935e-02, 8.755201490297605e-03, 6.312249945838542e-01, 3.138713147271113e+01, 1.221716714312792e+03, 3.015314278052363e+04, 6.238113008784873e+05, 1.474260838028852e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_acggap_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_acggap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.282399633956180e-14, -1.128113825390059e-13, -1.492975155666677e-13, -2.232671088992012e-13, -3.977192067107327e-13, -9.095413258731044e-13, -2.967871909019611e-12, -1.601897795463944e-11, -1.749179275735543e-10, -5.031719056709855e-09, -7.387731296418850e-07, -6.940223209575342e-04, -7.074121299375584e-03, -3.954088298422689e-02, -1.404604441184495e+00, -2.591761082583112e+02, -1.103409942974687e+05, -8.590923580996746e+07, -2.089580287150328e+11, -3.775224743233697e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
