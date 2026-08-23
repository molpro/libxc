
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_cam_o3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_o3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.353631506900102e+00, -8.179763472017919e+00, -7.935502036845957e+00, -7.595954166621191e+00, -7.131137410451017e+00, -6.508857235643799e+00, -5.702238678606814e+00, -4.704417117237472e+00, -3.551649547973482e+00, -2.354686979797864e+00, -1.352602390757062e+00, -8.731840234133966e-01, -7.073413117012436e-01, -5.047169100257788e-01, -2.509850815590644e-01, -6.594236968546480e-02, -7.520316438413867e-04, -5.059336535590011e-03, -1.376741466554973e-03, -1.675851232904226e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_cam_o3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_o3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.091448197656112e+01, -1.070637280338496e+01, -1.041244572337802e+01, -1.000093275336942e+01, -9.432348681714217e+00, -8.662267327968882e+00, -7.650292355200625e+00, -6.379673889856921e+00, -4.891119434335872e+00, -3.330443063293255e+00, -2.000802146372122e+00, -1.285737463734886e+00, -1.035340022865464e+00, -7.837058945683162e-01, -4.310198510347832e-01, -1.586762987031879e-01, -4.411585914970836e-02, -6.812987245173863e-03, -1.802980450856858e-03, -2.221244889982881e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_o3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_o3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.299909954610043e-06, -4.310436729655077e-06, -4.324461737588422e-06, -4.341760610552797e-06, -4.358960363845061e-06, -4.362127246704063e-06, -4.300870898533147e-06, -3.976609167244721e-06, -2.359237512706475e-06, 8.750398909664464e-06, 1.116580874952656e-04, -8.710662974212902e-04, -1.066793136156526e-02, 8.326204292973980e-04, 1.935861497168355e-02, 2.367945361291980e-01, 3.430396052051829e+00, 4.248367882967114e+00, 3.011733376780076e-10, -4.960794928729704e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_o3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_o3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.235925784344204e-02, -1.326048815984070e-02, -1.462496606130180e-02, -1.673670895786700e-02, -2.010827972351743e-02, -2.573231407967710e-02, -3.570486143184812e-02, -5.493685216221631e-02, -9.634752769352066e-02, -1.966943411097528e-01, -4.476043417499644e-01, -7.785156876961111e-01, -8.172830795324082e-01, -1.620370021814446e+00, -3.149824061411688e+00, -3.878986325466072e+00, 6.554539960533383e+00, -9.215856444004856e+01, -1.937333675335535e+03, -1.866475918758231e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_o3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_o3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.511716467418217e-08, -1.016728660518213e-07, -1.118834568821763e-07, -1.283456984193990e-07, -1.562374400228254e-07, -2.070136490039279e-07, -3.098765826956117e-07, -5.575232506728629e-07, -1.396344725919114e-06, -7.822509059057329e-06, -1.678389085936754e-04, -1.172139320498761e-02, -1.258005862132024e-01, -7.766060868551217e-02, -5.095500043171103e-01, -2.657911829185959e+01, -2.792084706290085e+03, 1.326961398209656e+05, 1.790990353939960e-02, -6.852873421676012e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_o3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_o3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.353521496913974e-12, 1.539668968215476e-12, 1.852704824892761e-12, 2.416237354982939e-12, 3.534727189482089e-12, 6.087356552654927e-12, 1.320088683230169e-11, 3.962708542893215e-11, 1.901599369584750e-10, 1.958640775484870e-09, 1.255079368659036e-07, 1.009784628619381e-03, 5.554149148238480e-02, 2.342878215170261e-02, 6.246475585559419e-02, 4.214445019583492e-01, 3.837894744873303e+00, 5.272870488878116e+01, 1.530751602885602e+03, 1.448937784864926e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
