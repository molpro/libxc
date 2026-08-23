
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_g96_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_g96", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.343184138499479e+00, -4.260672618260741e+00, -4.145105804924465e+00, -3.985128266845424e+00, -3.767380244131486e+00, -3.478105994437557e+00, -3.106965247208850e+00, -2.653966576587427e+00, -2.138986609191852e+00, -1.605934938783157e+00, -1.081849799065666e+00, -6.699466626893437e-01, -5.678295477264219e-01, -4.754469952197090e-01, -3.488831444308174e-01, -2.334933631370853e-01, -1.684312757675905e-01, -1.810113038976373e-01, -3.334081174784324e-01, -9.532711953247194e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_g96_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_g96", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.430538908333731e+00, -5.317361465855984e+00, -5.158701799373532e+00, -4.938769872728383e+00, -4.638771929768276e+00, -4.238848048372195e+00, -3.722809564192644e+00, -3.087000640088608e+00, -2.354260683678601e+00, -1.597686823894110e+00, -1.008776920252122e+00, -8.124578553860129e-01, -7.198381718430753e-01, -5.659992966447052e-01, -3.673449204940803e-01, -1.791092840946980e-01, -3.453505471730851e-02, 7.368838618187398e-02, 2.125443982159768e-01, 6.344385551561216e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_g96_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_g96", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.866736052220526e-06, -4.155046708481998e-06, -4.607386717704882e-06, -5.344520281011244e-06, -6.612983285866040e-06, -8.973144515284459e-06, -1.388532424005047e-05, -2.589081386984017e-05, -6.279954223678371e-05, -2.187320273958541e-04, -1.155109795111768e-03, -6.483996780440101e-03, -1.384545216106828e-02, -2.523769776064220e-02, -9.218384365069304e-02, -7.079831386100338e-01, -1.288267041735802e+01, -7.098980430451413e+02, -1.789036740758597e+05, -4.028822543553212e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_g96_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_g96", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.144936363252443e-02, -1.196075721075296e-02, -1.273736111690245e-02, -1.394533145729188e-02, -1.589069857703422e-02, -1.918609091416408e-02, -2.519752167545334e-02, -3.742860585969022e-02, -6.661439897745959e-02, -1.518196416134247e-01, -3.892663761423925e-01, -5.242558617135042e-01, -6.439879817809383e-01, -1.095330211806056e+00, -2.801111366666312e+00, -1.270020849991298e+01, -1.407312182177729e+02, -5.762343433405248e+03, -1.285679996299449e+06, -2.742520737902070e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_g96_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_g96", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.439428145988870e-08, 1.644406070783191e-08, 1.991070662272887e-08, 2.620533662889065e-08, 3.886581935611879e-08, 6.837017654007826e-08, 1.533725118130231e-07, 4.857132413813467e-07, 2.497745623103370e-06, 2.473758902997841e-05, 4.793262750079147e-04, 6.979550258009176e-03, 2.244863324919510e-02, 7.877251345912929e-02, 9.172737679405115e-01, 4.054443736889722e+01, 8.745432946377510e+03, 1.470447579089309e+07, 4.175854123146596e+11, 6.956805605289334e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_g96_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_g96", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.544478759169899e-13, 1.879482661649281e-13, 2.492117489401435e-13, 3.737445028760442e-13, 6.686208576970821e-13, 1.539022879778534e-12, 5.072826214707698e-12, 2.784524692482975e-11, 3.151507293913251e-10, 9.954568730334042e-09, 1.276661073790379e-06, 5.600611222366587e-04, 8.339926483271944e-03, 2.926595023307919e-02, 8.643112513580228e-01, 2.171064900441593e+02, 5.928464658805975e+05, 3.313479210563293e+10, 1.136948192929455e+17, 1.470911748470527e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
