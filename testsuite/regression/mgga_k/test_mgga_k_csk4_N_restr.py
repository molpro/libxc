
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_csk4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.441270484913559e+01, 2.441433631107824e+01, 2.450811654661213e+01, 2.488909019962695e+01, 2.592676262300382e+01, 2.786447121091206e+01, 2.984850309717553e+01, 2.991915507167398e+01, 2.761340948868281e+01, 2.442877222867898e+01, 1.855801913527932e+01, 5.495795824661357e+00, 1.040261479709540e+00, 1.052541328628666e+00, 1.015784129451174e+00, 8.934075670226326e-01, 8.232647558565594e-01, 7.886012831121799e-01, 7.695092523802779e-01, 7.603747199823221e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_csk4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.423620819176292e+01, -2.376275825311345e+01, -2.225612890218498e+01, -1.783608242628447e+01, -6.944080093968489e+00, 1.257233656609367e+01, 3.198688562248517e+01, 3.544272715076206e+01, 2.525902951773988e+01, 1.341989979494419e+01, 5.347064349514572e+00, 3.372161670707775e+00, 2.611840524214175e+00, 1.643989553899431e+00, 7.068921042734749e-01, 1.622493425774317e-01, -3.095611856645676e-02, -6.697200775475011e-02, -6.676869345014272e-02, -6.380103735044013e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.978848126217819e-04, 7.414790931603428e-04, 8.071541210645773e-04, 9.033251008458048e-04, 1.027366534619228e-03, 1.132805198925679e-03, 1.137696215214393e-03, 1.131895867456958e-03, 1.417886091682884e-03, 2.356197262015091e-03, 8.645034528253355e-03, 2.242556589178138e-02, 3.380025672998627e-02, 6.512868415168610e-02, 2.073017289013445e-01, 1.193073298577454e+00, 1.414276029841669e+01, 4.315313285405495e+02, 4.862782240123167e+04, 3.597414593058018e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk4_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.719194205089950e-05, 1.448010510718940e-04, 7.225416706983871e-04, 3.268849292537894e-03, 1.269453251085333e-02, 3.882662701745249e-02, 8.450057299584028e-02, 1.271645948110756e-01, 1.518508143191319e-01, 1.666662880549693e-01, 1.666666666666667e-01, 1.666666666666667e-01, 1.666533037939568e-01, 1.666336092503713e-01, 1.666666666665221e-01, 1.666666666666667e-01, 1.666666666666667e-01, 1.666666666666667e-01, 1.666666666666667e-01, 1.666666666666667e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.790439620030275e-01, 3.152922222243891e-01, 4.149670654442036e-01, 7.156132364786196e-01, 1.578601298627711e+00, 3.551949506848219e+00, 6.359459290506368e+00, 8.448160198411884e+00, 9.977530722977843e+00, 2.514162156963880e+00, 4.239153277108595e+00, 4.081130305988752e+00, 4.484816012921278e+00, 6.092838818992838e+00, 1.031764568191105e+01, 2.843088065841533e+01, 1.914271442609397e+02, 4.562850252709118e+03, 4.694792517190282e+05, 3.305245723518189e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.901754109821383e-06, -4.431215854714262e-06, -5.410117453993448e-06, -7.694739873608829e-06, -1.492316365535075e-05, -4.174284134471748e-05, -1.319668471500616e-04, -3.992232440473222e-04, -1.392407439566247e-03, -4.020334672424489e-04, -5.381036783617875e-03, -3.620923240079726e-02, -8.678850816357524e-02, -3.549267008083325e-01, -3.094128502849839e+00, -1.024865204960511e+02, -1.440127215780993e+04, -1.340778870086196e+07, -1.702558880269725e+11, -9.317802063129685e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk4_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.301048212007629e-06, 7.450593962484035e-06, 4.118336724682802e-05, 2.143374787229242e-04, 9.981127182494816e-04, 3.779270784231099e-03, 1.024085381231278e-02, 1.958264399187382e-02, 3.288175980885836e-02, 2.052083808069843e-05, 2.817681462947307e-132, 0.000000000000000e+00, 2.827423238400936e-03, 1.602091292245299e-02, 1.294035066567081e-09, -1.803316136286277e-130, -2.885305818058042e-129, -9.232978617785736e-128, -1.181821263076574e-125, -6.050924866952060e-123]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_csk4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.858127268452021e-15, 3.590163270725906e-14, 3.401251811732459e-13, 3.275124519842128e-12, 3.148495731115951e-11, 2.878179027452820e-10, 2.353733579197967e-09, 1.867298587293031e-08, 2.060091662060396e-07, 1.722145799532601e-09, 0.000000000000000e+00, 0.000000000000000e+00, 7.302132966576299e-04, 1.775305099743103e-02, 2.148395776655394e-08, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk4_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.036408788069778e-12, -9.071540385300262e-12, -7.870580747273356e-11, -6.679543814688427e-10, -5.357136422292470e-09, -3.777424260277545e-08, -2.130913390901589e-07, -9.953584964150011e-07, -5.179583226832611e-06, -1.522737085439198e-08, 0.000000000000000e+00, 0.000000000000000e+00, -4.503674301245789e-04, -5.687848663543005e-03, -2.159086930172129e-09, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk4_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.784105088423483e-10, 2.292175557394486e-09, 1.821271835436296e-08, 1.362278145518971e-07, 9.115118170060384e-07, 4.957625604951100e-06, 1.929186854304462e-05, 5.305731729930652e-05, 1.302276150996780e-04, 1.346418074474982e-07, 0.000000000000000e+00, 0.000000000000000e+00, 2.777692806272156e-04, 1.822313382868635e-03, 2.169831286532009e-10, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
