
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_wpbeh_whs_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbeh_whs", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.123536053350747e+00, -3.061213164713088e+00, -2.973932529211357e+00, -2.853131012924723e+00, -2.688746582029988e+00, -2.470445704483548e+00, -2.190512914144730e+00, -1.849025425168528e+00, -1.460513644780355e+00, -1.054725960351102e+00, -6.569733568565361e-01, -3.868186676559067e-01, -3.266228472607854e-01, -2.433603205518087e-01, -1.382590243277921e-01, -5.054108109361003e-02, -6.447453869762186e-03, -1.308158902991654e-04, -1.056050011296448e-06, -1.421510779959636e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_wpbeh_whs_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbeh_whs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.999807866371646e+00, -3.913046703951158e+00, -3.791361945319001e+00, -3.622574830255106e+00, -3.392145211499028e+00, -3.084663589341734e+00, -2.687669831795731e+00, -2.199366657521202e+00, -1.642581029917205e+00, -1.094380940192250e+00, -6.660456278855150e-01, -5.408238673947934e-01, -4.713899134594160e-01, -3.564187644249204e-01, -2.023884860780559e-01, -6.824004144295370e-02, -1.194563850594138e-02, -2.868377092289847e-04, -2.131329156161131e-06, -2.843639718211981e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbeh_whs_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbeh_whs", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.147115231718039e-06, -2.332509278986672e-06, -2.626285203165324e-06, -3.111635810416634e-06, -3.962385939019841e-06, -5.583195053208482e-06, -9.049729741954907e-06, -1.772281656373726e-05, -4.431552062731413e-05, -1.455370541982128e-04, -6.912931159825945e-04, -6.339795459197879e-04, 2.788342945423123e-03, 8.797544545622558e-04, -1.007458381187681e-02, -1.060463633543859e-01, -1.123394898562563e-01, 4.421879042501795e-02, 6.035413682403963e-03, 1.504921541881090e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbeh_whs_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbeh_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.477833001904289e-03, -9.925223511978522e-03, -1.060592907902136e-02, -1.166702608722375e-02, -1.337876720275615e-02, -1.627513275462280e-02, -2.150130640127716e-02, -3.172176699159046e-02, -5.293435040671710e-02, -8.569970371015494e-02, -1.855535646552630e-01, -4.292988563103132e-01, -4.626088779616934e-01, -8.722914203526690e-01, -2.837740501045026e+00, -6.398586374582399e+00, -1.003148913966150e+01, -1.292598194074254e+01, -7.897290104865996e+00, -7.375987170837486e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_wpbeh_whs_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbeh_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.092707425195216e-08, 2.392179312595922e-08, 2.896992862701446e-08, 3.807978791671992e-08, 5.618206725284672e-08, 9.733309249504656e-08, 2.097539729200595e-07, 6.007498004796148e-07, 2.358016084100052e-06, 7.256487590677884e-06, 6.595996859166644e-05, 8.288864372100545e-03, 6.329350072416215e-03, 8.288711832525050e-02, 1.534470861622293e+00, 1.870555097802330e+01, -5.117024475298240e+01, 8.874490758956079e+03, 1.380499384333310e+05, 2.578584454015978e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_lc_wpbeh_whs_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_wpbeh_whs", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.602343343371314e-14, -7.818100716379893e-14, -9.933206496915013e-14, -1.389534988970244e-13, -2.202081819520723e-13, -3.998510697993641e-13, -7.198073820824226e-13, 1.665446547992241e-12, 1.276969611798838e-10, 9.870505502225102e-09, 1.285326441426706e-06, -7.099306658279912e-04, -7.662605288163675e-03, -4.267478338619790e-02, -1.576621760690120e+00, -8.690985646897033e+01, -4.004899603261576e+03, -2.545876552825649e+07, -4.600350388366793e+10, -6.593256174472180e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
