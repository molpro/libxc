
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_fr_pw86_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_pw86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.410332432500444e+01, 9.046503602057032e+01, 8.549104408764089e+01, 7.883997919167149e+01, 7.022354282225689e+01, 5.955230040731546e+01, 4.714837291895233e+01, 3.394395325159751e+01, 2.146385459839661e+01, 1.140326628331534e+01, 4.956324993479332e+00, 2.204341646093461e+00, 1.622182428539700e+00, 1.100838540222672e+00, 5.572106194050291e-01, 2.005109162257588e-01, 4.809706071337132e-02, 7.084398783114583e-03, 5.517330090740858e-04, 1.610169612072462e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_fr_pw86_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_pw86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.480841879902012e+02, 1.420087423812693e+02, 1.337093265304278e+02, 1.226265373178140e+02, 1.083041890491560e+02, 9.065184152917813e+01, 7.033854417986700e+01, 4.917025480311113e+01, 2.997415761048251e+01, 1.541812996002075e+01, 6.631598720367504e+00, 3.335154070510820e+00, 2.597904749711145e+00, 1.630674538193632e+00, 7.644109067358829e-01, 2.639690679553163e-01, 6.111535371514919e-02, 8.354605981921545e-03, 6.268383776488466e-04, 1.824917506415588e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_fr_pw86_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_pw86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.393609837327913e-05, 1.001950937064090e-04, 1.098413676043664e-04, 1.251279666209712e-04, 1.502717823295341e-04, 1.936321348429100e-04, 2.726083413462403e-04, 4.244034598624694e-04, 7.316750231295803e-04, 1.443558715001737e-03, 4.338606384673450e-03, 2.718226174053085e-02, 3.928089346042531e-02, 7.581201967521378e-02, 1.547884653666769e-01, 3.759900303827056e-01, 1.291142403138867e+00, 7.780306990286679e+00, 7.969714511157107e+01, 1.815588653566524e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_fr_pw86_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_pw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.118458673716540e-01, 6.250391772908255e-01, 6.442291585483993e-01, 6.721608548154957e-01, 7.126422562644922e-01, 7.702379832117729e-01, 8.478805264544192e-01, 9.404437780102672e-01, 1.039432193843327e+00, 1.218878028401394e+00, 1.762581545518032e+00, 3.985387977344550e+00, 4.574884248663528e+00, 5.486704847996866e+00, 5.933137282485537e+00, 8.511429947513195e+00, 2.153053953419694e+01, 6.664240302747082e+01, 3.129184494474035e+02, 6.308153682518202e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_fr_pw86_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_pw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.501064520169761e-07, -7.203332204069113e-07, -8.311892346727135e-07, -1.011136278452621e-06, -1.309464147303560e-06, -1.790082011624607e-06, -2.346525886546167e-06, -1.032304730279652e-06, 1.927173279094130e-05, 2.111997768532236e-04, 2.634890539693739e-03, -3.172313117680148e-02, -1.347521907784828e-01, -1.474968670237607e-01, 1.576516054310671e+00, 3.537058108012651e+01, 1.352922599080372e+03, 2.397840251609753e+05, 3.131637289568095e+08, 5.328958278525913e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_fr_pw86_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_fr_pw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.347425374861548e-12, 1.434789928890180e-12, 1.491639528640393e-12, 1.295604323887813e-12, -2.632386701201325e-13, -9.521015849107444e-12, -7.177916525730403e-11, -6.254803731377415e-10, -7.939306277945812e-09, -1.835334508833232e-07, -1.421062818579391e-05, -9.762748074979393e-04, 1.457022193689685e-02, -7.707009161466764e-02, -3.662423240587905e+00, -3.623504054974314e+02, -1.808390791014484e+05, -1.085048550665658e+09, -1.612365467601300e+14, -2.121027398565958e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
