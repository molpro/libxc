
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pw91_mod_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91_mod", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.322468758699906e+00, -4.240715336077606e+00, -4.126246326235841e+00, -3.967859914222851e+00, -3.752415651876916e+00, -3.466454725297497e+00, -3.099972025703012e+00, -2.653067493694208e+00, -2.144231263227631e+00, -1.611348287842312e+00, -1.082849803153343e+00, -6.679127306275275e-01, -5.648511571160281e-01, -4.745800799609028e-01, -3.501299180612027e-01, -2.291490978694535e-01, -1.205905876623874e-01, -1.389857563834572e-02, -1.259686023427537e-04, -1.664332566414041e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pw91_mod_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91_mod", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.380102063309951e+00, -5.266482346011213e+00, -5.107253257304619e+00, -4.886648126678359e+00, -4.586007858438469e+00, -4.185911673325235e+00, -3.671426081720589e+00, -3.042317878796579e+00, -2.330083091688898e+00, -1.621087553958850e+00, -1.050741044801396e+00, -8.019451171292765e-01, -7.147665879529109e-01, -5.580033716099578e-01, -3.666158071280043e-01, -2.101260679324106e-01, -1.626955625972391e-01, -5.168299921645847e-02, -5.149565645480936e-04, -6.683455192568624e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw91_mod_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91_mod", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.111550984216491e-06, -4.432435223497865e-06, -4.936602034677947e-06, -5.759510062111494e-06, -7.177446036095461e-06, -9.815054476168075e-06, -1.527644018726290e-05, -2.838368861858322e-05, -6.673244652695321e-05, -2.122199092634027e-04, -1.046891770586125e-03, -7.109959886020261e-03, -1.425426213435150e-02, -2.777894220725382e-02, -9.443724017589171e-02, -5.108783526311046e-01, 1.293495345914227e-01, 7.470311971215746e+01, 9.447629733536908e+01, 9.439185217037181e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw91_mod_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91_mod", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.192601835101068e-02, -1.245607794536747e-02, -1.325843181230118e-02, -1.449982787014667e-02, -1.648066585769376e-02, -1.977955030092932e-02, -2.559746208598737e-02, -3.659979705610217e-02, -5.865604649263187e-02, -1.002262415319161e-01, -1.981195402841008e-01, -5.384817804526605e-01, -6.697483544122812e-01, -1.104869647402135e+00, -2.207001202092042e+00, -7.173363392639622e-01, 1.947914214218456e+02, -3.652808898287346e+03, -5.598413867841591e+03, -5.228280122548463e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw91_mod_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91_mod", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.051598692732876e-08, 2.325608159631420e-08, 2.782408778266214e-08, 3.593609651221869e-08, 5.168262746590635e-08, 8.626870940360198e-08, 1.759867702961396e-07, 4.622266913638979e-07, 1.554273838867091e-06, 3.443577498927852e-06, -5.297355609232828e-05, 8.575106504768868e-03, 3.354636511437771e-02, 8.695273869992275e-02, 3.608850260690358e-01, -2.837691555145319e+01, -1.694830348382594e+04, 7.025008645615453e+06, 1.360634923077353e+09, 9.834355414173450e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw91_mod_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91_mod", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.083202902987001e-13, 1.351845463187171e-13, 1.857784122459748e-13, 2.930037355038458e-13, 5.622718999560789e-13, 1.424923480887742e-12, 5.341308092477851e-12, 3.455380862710392e-11, 4.736658651747448e-10, 1.793068178964799e-08, 2.455203069866433e-06, 5.401649232396568e-04, 4.709491306723077e-03, 3.212051060361430e-02, 1.430830108726654e+00, 4.652787912279469e+02, 1.137007975703727e+06, -2.280362331358483e+10, -4.905372823601261e+14, -2.768570288802283e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
