
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_mn12_sx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.837553672018063e-01, -2.770456661446600e-01, -2.672311718774523e-01, -2.527624761374391e-01, -2.312711109496966e-01, -1.994278759186440e-01, -1.537831971935147e-01, -9.120490449961210e-02, 8.075603019801132e-03, 1.349393255066773e-01, 5.567406940174729e-02, -1.599553313943354e-01, -3.947759852641840e-02, -3.186180814889936e-02, 1.968351431974555e-02, -1.012766339393772e-03, -2.611655286247879e-01, -2.250468569369507e-01, -6.918913114951261e-02, -9.418792751935400e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_mn12_sx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.302863832693401e-01, -4.323438342943569e-01, -4.351003347495943e-01, -4.380762086313519e-01, -4.387152029755647e-01, -4.289526525807852e-01, -3.956443665350154e-01, -3.629760621619528e-01, -4.128820360608926e-01, -1.980535930295122e-01, 1.682063498710899e-01, 1.489999247436542e-02, -2.202248801024010e-02, -1.055564469065587e-01, -1.630947572501023e-01, 1.223021525809915e-01, -1.209970221370214e-02, -2.507886580819380e-01, -8.848386300860613e-02, -1.238905051957277e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_sx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.228701349244802e-06, -2.285508781698255e-06, -2.373727528137506e-06, -2.513944195833580e-06, -2.739751723698206e-06, -3.086084482104395e-06, -3.429697898937985e-06, -2.255966090261962e-06, 1.159906416736102e-05, 1.082030838204065e-04, 1.044127401603591e-03, 2.877323396050224e-02, 2.208537216343734e-03, 6.981690909491606e-03, 1.785135188436859e-01, 1.186548815849918e+00, 9.608513110147902e-01, 6.516444886233487e-02, 8.979288606520323e-04, 1.329099877399262e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_sx_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.768754875032211e-03, 7.831711970933535e-03, 7.941080120874836e-03, 8.117975123904967e-03, 8.354042522010883e-03, 8.507837154866927e-03, 8.198178844543564e-03, 7.628185542866275e-03, 8.543596753248180e-03, 2.308274836448746e-03, -1.519301802344485e-02, -4.620702167438377e-02, -1.109626297201628e-02, 3.032653278416862e-02, 3.256876392534293e-03, -2.295941418983685e-01, -2.419718998983727e-01, -2.491705268553952e-02, -3.956277968874964e-04, -7.506485573205107e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_sx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.210012231918045e-03, 2.265410175868750e-03, 2.302826971069765e-03, 2.241297419431388e-03, 1.852133991112095e-03, 6.940720134050787e-04, -6.253705123627353e-04, 7.504428474131838e-03, 1.927767639160779e-02, -1.862214866145335e-01, -9.061049916851182e-01, 7.653952481597203e-01, -3.835538178979916e-03, 1.369711645422795e+00, -9.680594077897424e-01, -7.462670018183353e+01, 5.104693413055522e+02, 6.784676979806303e+02, -8.231149232403895e+04, -1.004767323643180e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_sx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.993135053812965e-08, -3.217826923428903e-08, -3.581948027752747e-08, -4.218886540381620e-08, -5.492439594030777e-08, -8.661542491339948e-08, -1.928381184623265e-07, -6.689700181547865e-07, -2.804893930540470e-06, 1.050986537234506e-05, 1.452209620120284e-03, -6.140491264274954e-02, -1.687658919170255e-01, -5.232257056747248e-01, -2.994402115844413e+00, 3.231901046600791e+02, 6.619826552629110e+03, 1.589913982416747e+04, 2.269060616214598e+04, 2.282529083226644e+05]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn12_sx_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.132723244535634e-06, 3.041670455099725e-06, 2.673753888487217e-06, 5.573680853872133e-06, 1.927951227982143e-05, 6.131791321814802e-05, 1.384447913631383e-04, 6.712386401723698e-05, -3.959658129681164e-06, 4.154341506346526e-03, 1.252201417922397e-02, -2.109467723788277e-03, 1.676051057215854e-01, -6.129816416895208e-02, 2.308964690552958e+00, 1.268475369371004e+01, -4.652078429045787e+02, -2.164996123119304e+03, -4.081094300915768e+03, -5.797913739884192e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_sx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.077294434971316e-13, 3.595857318145295e-13, 4.506451448522512e-13, 6.254028361414404e-13, 1.005782667983702e-12, 1.984354011689007e-12, 4.951173641881905e-12, 1.050617607513831e-11, -2.963344781127561e-10, -3.175250738387837e-08, -8.158901706154990e-06, -6.263489254628028e-03, -1.754676847952971e-03, -2.060143625979730e-02, -7.456085689249873e+00, -2.881984430946302e+03, -4.850109067559427e+05, -3.611256124105144e+07, -6.843775881090535e+09, -5.822957387378574e+13]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn12_sx_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.191498918369523e-10, 5.513838615880851e-10, 6.028169759475183e-10, 6.922724432021384e-10, 8.764363463256441e-10, 1.382015959779029e-09, 3.397988010362979e-09, 1.493410847482778e-08, 1.028777878311840e-07, 9.960085324699247e-07, 1.681566839627275e-05, 6.008421596610187e-03, 6.601792416597331e-02, 3.093902925916747e-01, 4.177229447047918e+00, 3.408329352501802e+01, -8.112976608216638e+02, -2.632786505540049e+03, -2.069431704173240e+03, -5.342904793559428e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn12_sx_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.828552572366892e-06, -1.846346098228500e-06, -1.911560347612189e-06, -2.116704102080321e-06, -2.722972549305767e-06, -4.374205696609823e-06, -7.892061284472571e-06, -1.112110702548039e-05, -2.733694568543156e-05, -1.769191663299455e-04, -4.196771245635846e-04, -2.381664987673794e-03, -1.267296435227478e-01, -4.666183626519516e-01, -4.066427707045364e+00, -6.037753117045844e+00, 4.569131374313840e+02, 2.175795252976634e+03, 4.431992401855699e+03, 6.654022150915824e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
