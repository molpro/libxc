
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hjs_b97x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b97x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.250481379303440e+00, -3.187292136248791e+00, -3.098762153314784e+00, -2.976158478488527e+00, -2.809177257987857e+00, -2.587156686056154e+00, -2.302012941526536e+00, -1.953783395986642e+00, -1.559028641032002e+00, -1.157524147404630e+00, -7.831802857526732e-01, -5.429128444055260e-01, -4.840409427913416e-01, -3.940552444093213e-01, -2.804211495710604e-01, -1.826808392741617e-01, -1.185093011873700e-01, -5.426602560696645e-02, -1.237471068500857e-02, -1.371867679231180e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hjs_b97x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b97x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.244655039683896e+00, -4.158291724462861e+00, -4.037119839215489e+00, -3.868936534450289e+00, -3.639062290588797e+00, -3.331611479435965e+00, -2.932676563939051e+00, -2.436297801101746e+00, -1.854517667345109e+00, -1.240584590243730e+00, -7.888788544423664e-01, -7.160155893164774e-01, -6.405327883359984e-01, -5.198416299436570e-01, -3.460582749018659e-01, -1.661028385899037e-01, -9.535584791435824e-02, -6.480273798974376e-02, -1.642247272319817e-02, -1.829050458754639e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_b97x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b97x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.855496824727529e-07, -7.579486584410345e-07, -8.748290067028379e-07, -1.073195029109028e-06, -1.434744692212170e-06, -2.164001465742157e-06, -3.861101415107615e-06, -8.679229676252588e-06, -2.652377578495400e-05, -1.176648323114771e-04, -6.561041162161846e-04, 7.150536524878374e-04, 4.734512493382841e-03, 3.373587478794847e-03, -1.640375058696478e-02, -3.809539313308745e-01, -3.954159268768122e+00, -1.281672458042077e+01, -1.937321145558959e+01, -2.162324628102166e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_b97x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.921119222034857e-03, -9.342457306631580e-03, -9.986109717887963e-03, -1.099633484873563e-02, -1.264605559832940e-02, -1.550273834711399e-02, -2.090026998679441e-02, -3.250096372364471e-02, -6.241179667815776e-02, -1.574183275450594e-01, -3.932567145156586e-01, -4.311411493793629e-01, -4.729717691542737e-01, -9.386209521450922e-01, -3.348044569729200e+00, -1.390679702996805e+01, 7.663179894385557e+01, 5.051728563445612e+01, -1.812300760880604e+04, -1.578083877958872e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_b97x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.361779375000769e-08, 1.573695803833407e-08, 1.937175437155949e-08, 2.610686886201801e-08, 4.005368562841805e-08, 7.393311580860571e-08, 1.773269344928249e-07, 6.125144065216531e-07, 3.462116395522859e-06, 3.679548268432219e-05, 6.456892886797716e-04, 7.023975705774808e-03, 2.811859188650000e-03, 8.682446016491212e-02, 1.811336361200898e+00, 5.427135241560646e+01, -7.085346912429889e+03, -1.446233957633674e+06, -2.698022707851588e+08, -2.239414658049560e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_b97x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.031631709737592e-13, -1.256161635057148e-13, -1.667046522192596e-13, -2.502979909245992e-13, -4.484012148107251e-13, -1.033085672011398e-12, -3.394935512690219e-12, -1.822127218641959e-11, -1.876091776734411e-10, -4.487219738610010e-09, -3.206678823729187e-07, -7.670128798276576e-04, -7.591337326268538e-03, -4.440315825438217e-02, -1.513690509907065e+00, -6.856194971805590e+01, 8.465670359842787e+05, 4.516351708328348e+09, 9.810983584668078e+13, 6.313821780725527e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
