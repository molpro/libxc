
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_hle16_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hle16", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.593564194388239e+00, -5.479470088150711e+00, -5.319670592755305e+00, -5.098480161545461e+00, -4.797495367121385e+00, -4.397966743101893e+00, -3.886611376568716e+00, -3.267176501448495e+00, -2.580101061975938e+00, -1.917599410686539e+00, -1.305866715029850e+00, -8.617881102458124e-01, -7.561385635072594e-01, -6.096652947706561e-01, -4.344662449939911e-01, -3.016269451575995e-01, -1.941133204902109e-01, -6.937359096215380e-02, -1.290389151444153e-02, -1.324551372548543e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_hle16_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hle16", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.569292888066458e+00, -7.413540235474559e+00, -7.194791616494072e+00, -6.890697723383174e+00, -6.473999578103137e+00, -5.914214407611480e+00, -5.181782507703560e+00, -4.254661113301125e+00, -3.130839021305562e+00, -1.914046866912673e+00, -1.127825113849391e+00, -1.141297981769222e+00, -1.017362423408607e+00, -7.941427825758496e-01, -4.814927570548334e-01, -1.994990953584543e-01, -1.636955807582911e-01, -8.933392349543968e-02, -1.743830418208072e-02, -1.772730800235268e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hle16_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hle16", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.303424012375567e-06, 1.346879424475493e-06, 1.403780010239251e-06, 1.468833459958894e-06, 1.507673112819322e-06, 1.365311103495583e-06, 3.381718079756768e-07, -5.198703910393244e-06, -3.762402791212798e-05, -2.543763333122209e-04, -1.609719864899990e-03, -1.792942681504661e-04, 5.085666821101658e-03, -5.138770013940855e-03, -8.747768937397180e-02, -1.068739535420770e+00, -6.656420040858891e+00, -1.241714112770483e+01, -7.978071772308577e+00, -3.360530360454458e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hle16_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hle16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.527716842055681e-02, -1.603782118620321e-02, -1.720983921409220e-02, -1.907453200700578e-02, -2.218859137464844e-02, -2.779262795104252e-02, -3.912537638304996e-02, -6.642562070703242e-02, -1.474904075068143e-01, -4.019733458177240e-01, -9.931762870372446e-01, -7.907823775868353e-01, -9.083732734774085e-01, -1.739575850893542e+00, -6.573008624206239e+00, -1.160507455173964e+01, 1.483979832923794e+02, -3.651501014494504e+02, -2.131503347322352e+04, -1.557577838661804e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hle16_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hle16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.320680215805228e-08, 1.612897249637878e-08, 2.138325905147082e-08, 3.177371736180561e-08, 5.528848748182431e-08, 1.196852700295979e-07, 3.499049394651876e-07, 1.527635548356632e-06, 1.080206204499369e-05, 1.188492388725232e-04, 2.039375201000445e-03, 1.452061542003929e-02, 3.528466908858927e-02, 1.898742126331506e-01, 3.991118138807374e+00, 3.562998067720776e+01, -1.333957265987276e+04, -1.441551376447312e+06, -1.154799787435146e+08, -3.590437034992888e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hle16_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hle16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.434329895342375e-13, -3.030767787100880e-13, -4.150011042977299e-13, -6.511137286677032e-13, -1.241022809264844e-12, -3.124045988616500e-12, -1.168556521215629e-11, -7.569930392099913e-11, -9.795911292503210e-10, -2.460214382649588e-08, -1.874370371522608e-06, -1.096229658831561e-03, -1.903831282822388e-02, -5.638691348519118e-02, -2.093328721576842e+00, 4.522148481737678e+02, 1.464502365147519e+06, 4.277083458122929e+09, 4.036109939992328e+13, 9.814291398759643e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
