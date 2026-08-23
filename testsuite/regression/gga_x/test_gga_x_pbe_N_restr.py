
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.303465370005826e+00, -4.221751040152878e+00, -4.107359584618374e+00, -3.949129752940183e+00, -3.734006474306125e+00, -3.448712001496324e+00, -3.083622048240847e+00, -2.639580419735368e+00, -2.136055810676289e+00, -1.609600834163063e+00, -1.082696369817873e+00, -6.644479715386727e-01, -5.627473422354771e-01, -4.720754774540962e-01, -3.492476622815413e-01, -2.286348313253200e-01, -1.207835351923150e-01, -4.187677949014101e-02, -8.769442268893961e-03, -9.701617071056947e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.379093129866169e+00, -5.264670723394535e+00, -5.104251941212826e+00, -4.881866870677398e+00, -4.578538975567790e+00, -4.174371317684204e+00, -3.653844533186242e+00, -3.016700325144817e+00, -2.298392867110720e+00, -1.600228410813913e+00, -1.044793908951196e+00, -7.992730147569335e-01, -7.153009281948203e-01, -5.548829717441768e-01, -3.611011816958036e-01, -2.158505578456021e-01, -1.361093552854844e-01, -5.452649052429740e-02, -1.167947240950978e-02, -1.293530283543515e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.850506364390367e-06, -4.164136689085136e-06, -4.658974152382802e-06, -5.471524512341848e-06, -6.883670439766943e-06, -9.542307789272064e-06, -1.513691506319217e-05, -2.882138013975522e-05, -6.935555763038405e-05, -2.196761833380944e-04, -1.062186780965607e-03, -6.953680213108549e-03, -1.301362653411861e-02, -2.769755219404153e-02, -9.852503614609466e-02, -4.765532645273435e-01, -1.690349595816810e+00, -2.950161759603995e+00, -3.571405998112574e+00, -3.945220307491249e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.223535497533079e-02, -1.279907524239410e-02, -1.365490093281410e-02, -1.498454415970466e-02, -1.711831932818702e-02, -2.069750968883913e-02, -2.705056096494429e-02, -3.898832341064511e-02, -6.112802347144328e-02, -8.713682810921683e-02, -1.333480954058640e-01, -5.652810526362548e-01, -6.795294761037594e-01, -1.170891987098614e+00, -2.176638353958302e+00, 2.182617501697707e+00, 2.863518970103297e+01, -4.078004517013541e+02, -1.344733885148243e+04, -1.116614216317468e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.385525926672213e-08, 2.721736066459458e-08, 3.286765138088211e-08, 4.301637167099657e-08, 6.302995901740392e-08, 1.079217804419960e-07, 2.272599009311218e-07, 6.129331778831194e-07, 1.945689715950356e-06, -1.349035321673633e-06, -2.222025201863163e-04, 1.084096725144023e-02, 3.701923256613257e-02, 1.132909092649686e-01, 3.581277303850239e-01, -4.478324804635766e+01, -5.072960611223915e+03, -3.535935813567124e+05, -4.993287975538571e+07, -4.087378616760579e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.163688576451837e-14, 6.563660898918558e-14, 9.261723556761176e-14, 1.517458766056212e-13, 3.076544906084024e-13, 8.439496884336762e-13, 3.543491687281260e-12, 2.685548436924499e-11, 4.506067643958339e-10, 2.053793587204021e-08, 2.939744764237688e-06, 3.313475137708196e-04, 1.924666022940885e-03, 2.214646264617367e-02, 1.510082154665420e+00, 5.320791590928269e+02, 4.994683637990815e+05, 1.072181297640959e+09, 1.813440463988309e+13, 1.152292398138968e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
