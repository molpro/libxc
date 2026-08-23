
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_sol_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_sol", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.243475594585494e+00, -4.160803654907014e+00, -4.045024914901155e+00, -3.884779586999215e+00, -3.666718203627142e+00, -3.377130243533625e+00, -3.005794864605264e+00, -2.552977943633377e+00, -2.038979965018538e+00, -1.508678659952524e+00, -1.006867623555198e+00, -6.497852317589098e-01, -5.569209504314759e-01, -4.593623656273628e-01, -3.304043504524081e-01, -2.103990693959148e-01, -1.144766120846490e-01, -4.150255685891203e-02, -8.765618698077316e-03, -9.701562628351950e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_sol_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_sol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.448519353050491e+00, -5.334795733191182e+00, -5.175345352885791e+00, -4.954269775448037e+00, -4.652627733415858e+00, -4.250389068378598e+00, -3.731302597650354e+00, -3.092393988903822e+00, -2.360577263979212e+00, -1.621895991092721e+00, -1.041356644256632e+00, -8.145634135101413e-01, -7.223207683631985e-01, -5.672040179142042e-01, -3.696161625822794e-01, -2.024905636565263e-01, -1.193183728721817e-01, -5.310267219240222e-02, -1.166421377925057e-02, -1.293508507114218e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_sol_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_sol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.247337961118129e-06, -2.433837320986343e-06, -2.728855668773381e-06, -3.215207429791495e-06, -4.065656763354118e-06, -5.682715464357761e-06, -9.142774877502085e-06, -1.786224194944163e-05, -4.517822659032659e-05, -1.568080096714738e-04, -8.020537651697960e-04, -4.157951096092695e-03, -7.519579065676017e-03, -1.682232659671470e-02, -6.682794631625107e-02, -4.178951173198077e-01, -2.258542370976571e+00, -5.034212408082167e+00, -6.337786843424605e+00, -7.014706263934668e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_sol_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.155070965471410e-02, -1.207364238940519e-02, -1.286816750650024e-02, -1.410464004564514e-02, -1.609626598584234e-02, -1.946578405640172e-02, -2.557362460260770e-02, -3.770730163465209e-02, -6.426690335122009e-02, -1.224927859847445e-01, -2.620638032952186e-01, -5.321194044376288e-01, -6.466168858622277e-01, -1.110884563834969e+00, -2.537839048833812e+00, -3.309025121661040e+00, 4.015479419759549e+01, -2.895398540704580e+02, -1.328789855365683e+04, -1.116445015683525e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_sol_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.512261106692224e-08, 1.733997937752719e-08, 2.109781913123272e-08, 2.793546269534637e-08, 4.170179842518664e-08, 7.367638575909899e-08, 1.642607798864870e-07, 4.987902327666986e-07, 2.185703109336854e-06, 1.238538549478823e-05, 1.225246821549455e-04, 7.519610973839937e-03, 2.267759485368111e-02, 8.385283761856892e-02, 6.585550159285956e-01, -1.332826328164497e+01, -5.467514761409073e+03, -5.868511491789753e+05, -8.849475118884538e+07, -7.267345492887062e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_sol_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.726677666781102e-14, 2.199487035871356e-14, 3.113526942619748e-14, 5.126173328629241e-14, 1.047260291406614e-13, 2.908678425024301e-13, 1.247434678423968e-12, 9.826304034839507e-12, 1.776621815338683e-10, 9.288810690633740e-09, 1.446568242551109e-06, 1.148963220593232e-04, 6.339771169351856e-04, 7.861343824548776e-03, 6.326204986264679e-01, 3.276690612227625e+02, 5.785101251099597e+05, 1.792347455202012e+09, 3.214965567793030e+13, 2.048780624539191e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
