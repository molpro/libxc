
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_rmspbel_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.608439346208613e+00, -4.517751902125539e+00, -4.390723092196087e+00, -4.214854922756963e+00, -3.975423842216190e+00, -3.657222164982685e+00, -3.248694524940841e+00, -2.749433461140495e+00, -2.179757632760018e+00, -1.567478227182386e+00, -9.864951808309497e-01, -6.152924351448006e-01, -5.593047033164010e-01, -4.780663887156367e-01, -3.393272215086976e-01, -2.104659247952216e-01, -1.140894804553547e-01, -4.149743604054626e-02, -8.765616185125410e-03, -9.701562627895080e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_rmspbel_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.978138773986767e+00, -5.854305322301303e+00, -5.680668350564104e+00, -5.439888040403328e+00, -5.111247505067514e+00, -4.672615837969842e+00, -4.105060626499094e+00, -3.399768710367657e+00, -2.554892326169329e+00, -1.510489918354635e+00, -1.007219258009405e+00, -8.124963557166807e-01, -7.575454189180653e-01, -6.059588957366995e-01, -3.567369451920860e-01, -1.973225843284408e-01, -1.135130633958597e-01, -5.306656449843745e-02, -1.166419654303122e-02, -1.293508506757255e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmspbel_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.807598883296335e-06, -1.961252011235422e-06, -2.205497833832319e-06, -2.611374066842943e-06, -3.331009450078563e-06, -4.735669529772587e-06, -7.913655618125868e-06, -1.711123062307263e-05, -5.985654575614579e-05, -4.853493872244417e-04, -1.293517039338896e-03, -5.865525389069421e-03, -1.316588742314060e-02, -5.435617105775529e-02, -2.155093766713408e-01, -5.237700394822458e-01, -3.200314893102242e+00, -5.114553001949885e+00, -6.341804894292306e+00, -7.014787322552180e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmspbel_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.926053414163609e-05, 5.454217704834500e-05, 6.318973611510977e-05, 7.818739749043346e-05, 1.064647386752693e-04, 1.666612898613578e-04, 3.194928366324580e-04, 8.195425155920591e-04, 3.147551174566983e-03, 1.640887421221767e-02, 5.581683390207097e-03, 5.680510999645064e-03, 1.881526629701284e-02, 6.712291758340384e-02, 8.253206016675795e-02, 9.906191327256907e-03, 6.631353696354361e-03, 5.556927189125398e-06, 8.384493514819328e-10, 8.966113301617957e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmspbel_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.141742231391908e-02, -1.186019601715503e-02, -1.251880444273573e-02, -1.350926424110506e-02, -1.501412283325716e-02, -1.729715804113615e-02, -2.055578591969053e-02, -2.350359617328178e-02, -1.417665060154301e-02, -1.177757325035077e-01, -3.732958959269117e-01, -8.706620319088223e-01, -1.364621528900752e+00, -1.653136543153384e+00, -4.747371947097641e+00, -2.870337986879310e+01, -5.205517378921371e+00, -2.877218471731335e+02, -1.328770210011061e+04, -1.116445032950987e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmspbel_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.243725334694581e-08, -1.546492338992882e-08, -2.103863105708634e-08, -3.242985159544016e-08, -5.940701305522922e-08, -1.379863109242362e-07, -4.436700406342997e-07, -2.217961553426200e-06, -1.955000277238582e-05, -1.041773569209909e-04, 9.187158690124226e-05, 5.125274090075682e-03, -7.718484096174320e-02, 2.775966668715721e-01, 3.449653383080193e+00, 4.795062106173989e+02, 6.036443742587046e+03, -5.732764524145809e+05, -8.847657603270067e+07, -7.266180707436295e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmspbel_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.537977034308183e-05, 3.981942091181793e-05, 4.717978153812787e-05, 6.016248065569065e-05, 8.518917146895949e-05, 1.399633213253351e-04, 2.835484193229968e-04, 7.680476496810810e-04, 3.028958633715372e-03, 7.626490177241396e-03, 4.081364470639615e-03, 3.219026677991894e-02, 3.816253911480368e-01, -2.321082708298290e-02, -4.272038494500907e-01, -4.538106935323206e+01, -9.432019549234997e+01, -6.511457441233544e+00, -2.337044352542062e-01, -3.851649916369611e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmspbel_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.295114393455874e-13, 9.304374632469542e-13, 1.319613585179062e-12, 2.179109389974460e-12, 4.473339690952203e-12, 1.252731480278268e-11, 5.456009050090465e-11, 4.439690217714313e-10, 8.622141573185906e-09, 2.404655193930434e-07, -7.587678617450075e-07, 4.444506001767103e-05, -1.994771357650704e-02, 3.849641356664276e-02, -4.284743422469805e+00, -9.425312095793432e+03, -2.211647056782652e+06, 1.648718169768650e+09, 3.209860140553811e+13, 2.048080447001151e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmspbel_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.027466471931080e-09, -1.232618849973870e-09, -1.600954691783831e-09, -2.329933223130482e-09, -3.989976429231492e-09, -8.617180351432022e-09, -2.587683653842227e-08, -1.237988621454994e-07, -1.127065323369288e-06, -1.004507131730406e-05, 3.981683661560932e-05, 6.053501165810984e-04, 6.912548936458397e-02, -2.448865850155131e-02, 3.342145602168964e+00, 9.149725147661273e+02, 2.384305303023442e+04, 4.664013093018847e+04, 1.808332672914233e+05, 2.232882531687611e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_rmspbel_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_rmspbel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.471526465137460e-06, 1.660460055474081e-06, 1.974962545247867e-06, 2.533022820120097e-06, 3.618372470059667e-06, 6.026020798774667e-06, 1.247434993475810e-05, 3.507225015328354e-05, 1.495384729654275e-04, 4.296574165656756e-04, -6.346904290519676e-04, -3.727996684106674e-03, -2.321592153339895e-01, -9.134271168652819e-03, -2.190472746507779e+00, -8.583785569137237e+01, -2.001340144522272e+02, -1.241917195397995e+01, -4.147873884512489e-01, -6.896217338782684e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
