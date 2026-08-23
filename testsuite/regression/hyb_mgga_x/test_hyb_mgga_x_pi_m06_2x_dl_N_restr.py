
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.979480365969360e+00, -1.941917808007739e+00, -1.889330648660116e+00, -1.816579140853159e+00, -1.717637010963125e+00, -1.586349710705722e+00, -1.418271374617067e+00, -1.214041545268359e+00, -9.825675252870008e-01, -7.401181462792004e-01, -4.982577738532891e-01, -3.056439535472083e-01, -2.588582832010306e-01, -2.171547630373502e-01, -1.605822715135532e-01, -1.052193242412082e-01, -5.553924769638038e-02, -1.924867294744346e-02, -4.030437787926225e-03, -4.458838824725747e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.473186059465244e+00, -2.420650148628170e+00, -2.347054418754436e+00, -2.245132335797379e+00, -2.106232722239413e+00, -1.921049714257890e+00, -1.681454357323114e+00, -1.386603069682916e+00, -1.058146196528011e+00, -7.348766011571105e-01, -4.804272148442239e-01, -3.668516381141612e-01, -3.288304915623931e-01, -2.551252919786956e-01, -1.661077766735232e-01, -9.938871162900162e-02, -6.260735046292427e-02, -2.506637766257460e-02, -5.367928916019321e-03, -5.945033268057680e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.771131191266092e-06, -1.915416402957761e-06, -2.143065995579241e-06, -2.516872809860675e-06, -3.166477401679828e-06, -4.389301627508726e-06, -6.962024852034840e-06, -1.325602835209059e-05, -3.190296727509699e-05, -1.010103412865212e-04, -4.888192439301723e-04, -3.198670780972938e-03, -5.986141150768373e-03, -1.274087655611508e-02, -4.530130281170107e-02, -2.193130948939354e-01, -7.772644238808432e-01, -1.356042645687232e+00, -1.641419060580094e+00, -1.813213338590569e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.574290971510427e-05, -2.418061806913982e-05, -2.042372728878385e-05, -1.232020590322664e-05, 2.770337924776438e-06, 2.261191908535402e-05, 2.300506642602201e-05, -2.255799670393678e-05, 2.316921343395364e-05, -2.440417109497748e-05, -1.219202072852332e-05, -7.068968612976638e-05, -8.002962406022430e-05, -7.067853213747237e-05, 4.673249954139553e-05, 3.603381530783410e-05, 1.611900529419791e-05, 2.843796160347364e-06, 3.900473546751479e-08, 6.084368057146320e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.612678758335628e-03, -5.862200145129013e-03, -6.241021810927241e-03, -6.831932153302544e-03, -7.793786831236560e-03, -9.461740246830327e-03, -1.254789056301633e-02, -1.808742078069392e-02, -2.749212461265896e-02, -4.178028277745871e-02, -5.757507093749190e-02, -2.578306220924598e-01, -3.083412595114979e-01, -5.295063597417751e-01, -1.038707366917325e+00, 1.076731335606291e+00, 1.312071252491406e+01, -1.877364784267527e+02, -6.180870585438438e+03, -5.131935992505383e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.097805820026027e-08, 1.252521202117156e-08, 1.512480940280498e-08, 1.979241269471547e-08, 2.899185840516719e-08, 4.961346790908363e-08, 1.044506472068175e-07, 2.821843026832159e-07, 8.932476564097755e-07, -5.987287684415261e-07, -1.020209656836872e-04, 5.000521422573926e-03, 1.703978743450263e-02, 5.214704610935003e-02, 1.643481430675900e-01, -2.061901260092646e+01, -2.332970396782165e+03, -1.625365239626173e+05, -2.294922146371512e+07, -1.878549002690882e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.365806870245022e-07, -5.784004718701138e-07, -9.493400317109635e-07, -1.475637805057616e-06, -1.997529745387732e-06, -1.516438765877096e-06, 2.598329501400969e-06, 4.025333363022354e-06, -1.613773056472979e-05, 4.484468680146197e-05, -1.194723379251325e-04, -1.682305201313741e-04, -1.634102403995343e-03, -5.263073180806262e-03, 2.349224434022619e-02, -4.915388698221887e-02, 3.372261761813614e-02, 2.269355507873080e-01, 4.069132736246570e-01, 4.727389001147595e-01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.375160312502492e-14, 3.019147710063090e-14, 4.260269356677740e-14, 6.980231377483034e-14, 1.415205740253026e-13, 3.882027097409320e-13, 1.629782362313689e-12, 1.235183951919038e-11, 2.072752833315807e-10, 9.443645097213954e-09, 1.352872996306737e-06, 1.524188024420162e-04, 8.853275796109551e-04, 1.018737485365994e-02, 6.943279762679466e-01, 2.448664940422730e+02, 2.296678692950529e+05, 4.928284216200328e+08, 8.334576758819103e+12, 5.295906903588619e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.286156711740348e-13, -1.415872594249059e-13, -1.501709211477445e-13, -1.255443535180167e-13, 4.502351656306419e-14, 7.150677855850830e-13, 1.871037479144979e-12, -6.931159677310261e-12, 4.488104393397097e-11, -5.650216617582213e-10, -7.445075952011321e-09, -1.194498737868553e-06, -4.501006953234436e-06, -1.941483468336767e-05, 1.967739148217743e-04, 6.451770733369975e-03, 2.297067262857873e-01, 6.224663007863822e+00, 5.561627597442745e+01, 6.408635885274871e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_x_pi_m06_2x_dl_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x_dl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.677670952308551e-09, 1.561351245166400e-08, 2.463983485312956e-08, 3.724499771679663e-08, 4.909475687296810e-08, 3.479371699221943e-08, -6.981788655719507e-08, -9.359945817045456e-08, 3.922429897188622e-07, -1.101384105276096e-06, 3.923342109362874e-06, 1.926767805320882e-05, 6.814492302796410e-04, 3.171158941688116e-03, -1.485002109776255e-02, 3.202022632098869e-02, -3.282132242779463e-02, -2.259511357699252e-01, -4.351580176750385e-01, -5.393117605585336e-01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
