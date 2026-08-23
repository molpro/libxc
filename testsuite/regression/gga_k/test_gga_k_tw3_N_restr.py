
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_tw3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.447520793189717e+01, 9.081519339538089e+01, 8.581018317803529e+01, 7.911520366313204e+01, 7.043771804351198e+01, 5.968502464621817e+01, 4.718265903395575e+01, 3.388769567243699e+01, 2.138739217720619e+01, 1.140944561316312e+01, 4.983504747893145e+00, 2.208310777165272e+00, 1.629019968677087e+00, 1.101009641815725e+00, 5.557284625376794e-01, 2.043205678648752e-01, 4.760439648463310e-02, 5.291509564790690e-03, 2.294679829316333e-04, 2.806923292268579e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_tw3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.491558357241142e+02, 1.430997016734029e+02, 1.348230618072065e+02, 1.237620814318124e+02, 1.094469750434026e+02, 9.175259054992964e+01, 7.127282812994451e+01, 4.970096342048678e+01, 2.988049902319716e+01, 1.497937798071504e+01, 6.395459980578589e+00, 3.377426625181255e+00, 2.608100107520680e+00, 1.652202590703614e+00, 7.522680108593117e-01, 2.581921991229051e-01, 6.926831451377137e-02, 8.650321890974165e-03, 3.820964841869272e-04, 4.678150414695850e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.908792345925517e-05, 9.439615369357072e-05, 1.025588252277487e-04, 1.154748190508042e-04, 1.367529494118999e-04, 1.738335141229122e-04, 2.435967480060423e-04, 3.886034143767068e-04, 7.274130168280687e-04, 1.624259739164340e-03, 5.088203016296978e-03, 2.432100463947627e-02, 3.972690883281147e-02, 6.791975961020620e-02, 1.639026110679616e-01, 4.409236204367256e-01, 6.827969455723162e-01, 3.805075973133489e-01, 9.533546496451174e-02, 1.164423327433419e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.911658685880824e-01, 6.039000201981124e-01, 6.226533468289636e-01, 6.505382211839541e-01, 6.925401535666703e-01, 7.568339250121304e-01, 8.568383238019931e-01, 1.012319574834949e+00, 1.233893132630454e+00, 1.436478303999861e+00, 1.848893769116061e+00, 3.943849112804156e+00, 4.445927842852171e+00, 5.616984811208559e+00, 7.237462686849691e+00, 4.628835498597062e+00, 1.331889900926529e+01, 1.571859507522057e+02, 8.865606446640669e+02, 8.077420236833864e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.854095329364246e-07, -4.293739410492102e-07, -5.008947425015189e-07, -6.233419165669907e-07, -8.480973797973060e-07, -1.299560428629542e-06, -2.301478076723156e-06, -4.582071092934272e-06, -5.734207715321168e-06, 1.036682416453346e-04, 2.144014906327380e-03, -2.473859131915379e-02, -8.070213591975593e-02, -1.709349182410519e-01, 2.336499572213410e-01, 5.438951011138975e+01, 2.284774048355741e+03, 4.955754509736836e+04, 1.444190839584059e+06, 1.306915141814365e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.202247946793166e-12, -1.497283083214501e-12, -2.051616543796582e-12, -3.222605064535798e-12, -6.149996647255906e-12, -1.546910911875807e-11, -5.737060676859986e-11, -3.642235811136738e-10, -4.752122582305756e-09, -1.525977003047942e-07, -1.414592011266236e-05, -1.166020782246051e-03, -5.912989358882239e-03, -5.463432662316231e-02, -2.525273639858955e+00, -4.940608659405435e+02, -2.020155099530730e+05, -1.383125800052300e+08, -4.840855834220748e+11, -3.400966704073555e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
