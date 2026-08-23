
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_sogga11_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.105406110123905e-01, -1.132242604603675e-01, -1.172409188142907e-01, -1.232823846530904e-01, -1.323295025598456e-01, -1.454907823985239e-01, -1.629813208777073e-01, -1.809400405684318e-01, -1.879201735927042e-01, -1.796656333439338e-01, -1.557185991615996e-01, -5.154841604474145e-02, -6.626569925806051e-02, -4.464013859494325e-02, -4.659658940901829e-02, -7.485256074201890e-02, -8.820904270805037e-02, -1.040205264937243e-01, -3.565897804601425e-02, -4.895925353330624e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_sogga11_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.082181921999963e-01, 2.174856596495898e-01, 2.287418754369763e-01, 2.404215642064677e-01, 2.474465159335209e-01, 2.370332673234232e-01, 1.834406317686692e-01, 5.633140723440730e-02, -1.050332798373480e-01, -1.024236580496177e-01, -9.501675282814830e-02, -1.295694303493808e-01, -8.078422201070440e-02, -1.122313937513608e-01, 8.750406926862686e-02, -3.702645108961505e-02, 9.685741541467445e-02, -7.727635037645017e-02, -4.467105187011679e-02, -6.437755604476909e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sogga11_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.883603948011514e-06, -4.290358537900705e-06, -4.913772466762165e-06, -5.885597789759363e-06, -7.418184706101276e-06, -9.801613283869628e-06, -1.314117146024431e-05, -1.599929140649808e-05, -1.396737575531503e-05, -4.214019875258145e-05, -2.270222606099580e-04, 6.265594940766953e-03, 2.552276178835758e-03, 2.486131553337994e-02, -1.428479988625569e-01, -2.858306937875888e-01, -1.446224749131088e+01, -1.209905952267739e+02, -3.173047766447891e+02, -5.324577622933961e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sogga11_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.148944796538419e-03, -5.872267980864120e-03, -5.300269088749453e-03, -4.069881808472692e-03, -1.323054078151310e-03, 4.966361809589813e-03, 1.910503467331354e-02, 4.563815193795524e-02, 5.582013903820445e-02, -1.388038529654474e-01, -4.011796327896994e-01, -4.338107351754731e-01, 3.267166579744857e-01, -1.255024804875397e+00, -7.492055679942002e+00, 4.178962957085475e+01, -1.136668820927337e+02, 4.791309009468445e+03, -2.817953775934703e+04, -5.198348192211245e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sogga11_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.396898171935022e-08, 7.542695782749413e-08, 7.490519402827416e-08, 6.634928840735080e-08, 2.856200565307280e-08, -1.175245347651848e-07, -6.862793311661575e-07, -2.868285777683173e-06, -7.807939226680178e-06, 6.043844704554404e-05, 1.147657430576176e-03, 3.574572048869724e-02, -1.409288529411310e-01, 4.786937860189252e-01, 7.792893309494262e+00, -2.417483280392169e+02, 9.513349399448980e+03, -1.246334650198417e+07, -4.301497904209146e+09, -5.466500075888936e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sogga11_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.338118546875304e-13, -5.232838147677863e-13, -4.481447296083109e-13, -1.358679916548901e-13, 1.112702261902242e-12, 6.623199869890755e-12, 3.557881950315407e-11, 2.187466074068446e-10, 1.235565251706070e-09, -2.242663172404753e-08, -2.785977231135606e-06, -4.294302345244257e-03, 5.348931843953874e-02, -2.549845576425112e-01, -5.026092618996468e+00, 1.570767550018681e+03, 7.234705199079579e+05, 4.078775556696127e+10, 1.603632505606526e+15, 1.555045756094192e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
