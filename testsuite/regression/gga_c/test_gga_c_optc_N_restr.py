
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_optc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_optc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.582704264486602e-02, -6.496814867781361e-02, -6.373489266009127e-02, -6.196515995351476e-02, -5.942752577392783e-02, -5.579294332783723e-02, -5.060000065189272e-02, -4.323878941410206e-02, -3.313326982568032e-02, -2.118087705581032e-02, -1.558017078977426e-02, -4.222289267858881e-02, -4.879186369367058e-02, -3.617814964069220e-02, -2.087700506938531e-02, -6.203345807153391e-03, -4.353321801617346e-04, -4.555786201519366e-06, -4.359990599372765e-09, -1.361026094779246e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_optc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_optc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.170325142437812e-01, -1.162883442973464e-01, -1.152154657434544e-01, -1.136668456652502e-01, -1.114270953769560e-01, -1.081763104629938e-01, -1.034250852366316e-01, -9.636884414770759e-02, -8.546378494894299e-02, -6.814164254701244e-02, -5.617762794560233e-02, -7.806821031119419e-02, -7.205766620879982e-02, -7.007620900708120e-02, -5.798996056295001e-02, -2.723676776474999e-02, -2.569220136224013e-03, -2.917391123483882e-05, -2.851991089360488e-08, -9.006583867004035e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_optc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_optc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.235373354593171e-07, 5.593015257231438e-07, 6.149816182132013e-07, 7.046928777676085e-07, 8.564834559770964e-07, 1.131810729884646e-06, 1.682764092289412e-06, 2.946688458471781e-06, 6.423304516586892e-06, 1.849340551833506e-05, 1.061447297603182e-04, 2.632387040923534e-03, 6.903631290768233e-03, 1.152600016484222e-02, 3.362424352317251e-02, 1.106183683686855e-01, 1.424550517632523e-01, 5.412992220575961e-02, 6.327318776061581e-03, 1.534750605309272e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_optc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_optc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.975579436637719e-04, -2.121406751755234e-04, -2.349465115821447e-04, -2.719578371116123e-04, -3.353392429475036e-04, -4.527808912770310e-04, -6.978082949272238e-04, -1.314797174179658e-03, -3.426505215222729e-03, -1.361857465006483e-02, -5.498722746096055e-02, -1.191229754725632e-02, 8.101946492550709e-03, -2.892423128889393e-02, -5.522507428746604e-01, -5.870304356509209e+00, -1.222570384765093e+01, -4.872925563664025e+00, -5.529629411620203e-01, -1.310202842890767e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_optc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_optc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.827803108214760e-09, 2.097751439680178e-09, 2.556078030161071e-09, 3.392968708047315e-09, 5.090063589431876e-09, 9.095645282248289e-09, 2.090387923651322e-08, 6.957507629043697e-08, 4.084922628297386e-07, 5.292550079213726e-06, 1.422632858950251e-04, -3.239638746587498e-05, -1.102350475075981e-02, -2.334567463706766e-03, 4.483042773918662e-01, 3.055399106375490e+01, 8.155429829857254e+02, 1.071842946924910e+04, 1.448754193137316e+05, 2.630589585799348e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_optc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_optc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.019020405216404e-14, -8.519918730020990e-14, -1.125493165781226e-13, -1.678536697844633e-13, -2.977862107892436e-13, -6.768711951236846e-13, -2.190173291760050e-12, -1.173554418883585e-11, -1.304886635132430e-10, -4.187731598372953e-09, -6.645615788602012e-07, -5.153156612415834e-04, -4.830297137453968e-03, -2.938443314747894e-02, -1.159659745485938e+00, -2.445041200382595e+02, -7.090691052605183e+04, -2.997142359138485e+07, -4.822389808509311e+10, -6.723937535302526e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
