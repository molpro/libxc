
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbe38_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe38", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.753835437508861e+00, -2.701720777478566e+00, -2.628730462800492e+00, -2.527695612314079e+00, -2.390185235984355e+00, -2.207525841998113e+00, -1.973210369040730e+00, -1.687227184299702e+00, -1.361622510649810e+00, -1.021305588044016e+00, -6.879666990841513e-01, -4.583264675896848e-01, -4.042243723573011e-01, -3.317265108631461e-01, -2.375964569682983e-01, -1.481003202181806e-01, -7.585515224102869e-02, -2.617710166673288e-02, -5.480905577656024e-03, -6.063510670745166e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbe38_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe38", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.494141795040054e+00, -3.421658361257525e+00, -3.319988959053722e+00, -3.178944242086453e+00, -2.986343290115083e+00, -2.729236880303171e+00, -2.397052229729910e+00, -1.988041186610891e+00, -1.521595348520201e+00, -1.059819895875695e+00, -7.003649732009168e-01, -5.882368727788521e-01, -5.297232497654363e-01, -4.259216611908266e-01, -2.859659453523348e-01, -1.590839664963769e-01, -8.723562625784649e-02, -3.410534590639017e-02, -7.299697436070913e-03, -8.084564280975501e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe38_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe38", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.688496790254169e-06, -1.836431597331835e-06, -2.071104954183191e-06, -2.459417675315858e-06, -3.141604735799010e-06, -4.445494635110131e-06, -7.247163583347994e-06, -1.429755482673155e-05, -3.597022705611617e-05, -1.193927875176499e-04, -5.674209376540922e-04, -8.830536093794414e-04, 1.319539808116860e-03, -2.427456085439428e-03, -2.372900138934617e-02, -1.968107975984525e-01, -9.352880794153726e-01, -1.794922463321404e+00, -2.226092089172067e+00, -2.465612199926688e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe38_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe38", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.933306897291348e-03, -8.308975958156460e-03, -8.880827227213343e-03, -9.772924903279308e-03, -1.121389832963022e-02, -1.365745053945325e-02, -1.808076486324806e-02, -2.672992844286660e-02, -4.441204474782264e-02, -7.449247740500044e-02, -1.523970758595307e-01, -3.783230165496937e-01, -4.150166970208708e-01, -8.056175418174463e-01, -2.268895904890632e+00, -4.646442707855353e+00, 7.452717487040827e+00, -2.592558838313605e+02, -8.405113091444417e+03, -6.978838980361492e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe38_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe38", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.770049251086617e-08, 2.023740061826943e-08, 2.451650842039148e-08, 3.224681997452526e-08, 4.763650024875971e-08, 8.273630288204913e-08, 1.791088149613427e-07, 5.144653027389995e-07, 1.987891476274522e-06, 7.190012692636270e-06, 4.467116396699483e-05, 7.685766343254207e-03, 1.030896116489880e-02, 8.385240369081617e-02, 1.016371856731605e+00, 3.782622558357847e+00, -2.468471360781499e+03, -2.113254224215279e+05, -3.106997523580177e+07, -2.554353776889999e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe38_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe38", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.687490329964510e-14, -7.951832624671526e-14, -1.017288653092585e-13, -1.440523769937977e-13, -2.338133739319526e-13, -4.488941685487811e-13, -9.806338168168963e-13, -5.200728871082467e-13, 9.316071293248628e-11, 7.581986716476801e-09, 1.083704662105670e-06, -5.467487362505281e-04, -6.307511484211652e-03, -3.007644141933362e-02, -6.370675935396688e-01, 8.714762316292061e+01, 2.509992367588641e+05, 6.429982442920226e+08, 1.128799307942363e+13, 7.201168162455661e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
