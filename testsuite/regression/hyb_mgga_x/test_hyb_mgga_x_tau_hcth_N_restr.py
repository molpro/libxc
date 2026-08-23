
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_tau_hcth_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.658609277781012e+00, -3.586998224467833e+00, -3.486802952889505e+00, -3.348333919116837e+00, -3.160370039412190e+00, -2.911752455609717e+00, -2.594769101685827e+00, -2.209478886244150e+00, -1.765704329326829e+00, -1.310899902718179e+00, -8.974905784798664e-01, -5.610212806012842e-01, -4.812898018252530e-01, -3.964736798621672e-01, -2.850001019577050e-01, -2.054411992779740e-01, -1.442592138432948e-01, -5.763235104626248e-02, -1.236295872914533e-02, -1.369363854436355e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_tau_hcth_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.718731238981577e+00, -4.617109488270083e+00, -4.474255828602336e+00, -4.275491811056158e+00, -4.003150810628829e+00, -3.638982200413591e+00, -3.172544767386487e+00, -2.622089568639818e+00, -2.027492306137779e+00, -1.261276779681575e+00, -6.852372350059833e-01, -7.109336862655152e-01, -6.245037765359776e-01, -4.883017401228328e-01, -3.108096066467974e-01, -8.673676659028169e-02, -1.104988146549414e-01, -7.128551887769208e-02, -1.642520271662490e-02, -1.825734680372083e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_tau_hcth_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.775376883059943e-06, -1.953661585206044e-06, -2.242658565676925e-06, -2.735687234487948e-06, -3.638594018424454e-06, -5.455009280537399e-06, -9.540519628114709e-06, -1.971907816549513e-05, -4.815659308528710e-05, -1.990237986358959e-04, -1.287192490187817e-03, -2.993109768044322e-03, -5.335681369460993e-03, -1.540081227485933e-02, -6.989336743106574e-02, -9.982125867826538e-01, -6.093462293137531e+00, -1.277254760496196e+01, -1.600972991216944e+01, -1.771683843213985e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_tau_hcth_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.476163448921812e-04, 1.314308258065618e-04, 1.068904288603783e-04, 7.035321240875069e-05, 2.049799938307876e-05, -2.534810246283057e-05, 3.267565713032140e-05, 5.090457276286522e-04, 1.405193689851765e-03, 2.093306292151834e-04, -8.845491688046169e-04, 1.793036639823740e-05, -1.136562689121123e-03, 6.564507931830483e-04, 3.093469344762290e-03, -5.252047696153844e-04, 6.198170662468991e-03, 9.639080388075400e-05, 5.698814618102308e-08, 1.155363202008572e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_tau_hcth_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.105742399274101e-02, -1.165713734156936e-02, -1.257762712188856e-02, -1.402362786444055e-02, -1.635175467965036e-02, -2.013937675414239e-02, -2.596163670263636e-02, -3.320746966707359e-02, -5.784035203488309e-02, -3.141072517367097e-01, -7.997171603636722e-01, -4.724875646426987e-01, -5.608577621277423e-01, -9.015341104534400e-01, -4.156487360331749e+00, -1.329225222940221e+01, 1.710071709464752e+02, -9.033296753244169e+01, -1.834915229402110e+04, -1.575433800080594e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_tau_hcth_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.240102543990764e-08, 2.644854405469624e-08, 3.350551764575595e-08, 4.680881594700116e-08, 7.462048026937782e-08, 1.405706908133599e-07, 3.171972735911500e-07, 8.135770411466666e-07, 3.288313787252706e-06, 8.443696906631510e-05, 1.763117391858999e-03, 6.723423749545749e-03, 2.255740725712370e-02, 9.282569928754759e-02, 2.131959821068848e+00, 8.378141983718362e+01, -1.503044281462313e+04, -1.493321224553704e+06, -2.235686296243283e+08, -1.835494703474207e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_tau_hcth_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.557862048008684e-06, 5.054066250872705e-06, 5.710355431504092e-06, 6.387673584448987e-06, 6.190876071125595e-06, 7.746393400411165e-07, -2.886041305226069e-05, -1.414138286743827e-04, -2.186705056208853e-04, 8.629472606839162e-04, -1.390869880977294e-04, 5.284059275055143e-04, -2.443971045408618e-03, -6.450645021976185e-02, 2.156339069738574e-01, -3.301478479938581e+00, 1.018166329451272e+01, 1.285946507159486e+01, 9.276402396238617e-01, 1.396456320777260e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_tau_hcth_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.377357776202640e-14, -1.193070836942629e-13, -1.680639282425523e-13, -2.728412586924340e-13, -5.375367244055971e-13, -1.364309692953394e-12, -4.690584071932304e-12, -2.195677727365514e-11, -2.061677323443347e-10, -1.640134988049869e-08, -1.775877475994852e-06, 2.573130012331608e-05, -1.815421764492466e-03, -1.497329855289102e-02, -9.556285645884227e-01, 2.830748196093644e+01, 1.485562351493158e+06, 4.551952176825247e+09, 8.121882783325598e+13, 5.174550599831924e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_tau_hcth_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.082477068537522e-11, -1.335857625069425e-11, -1.702931554945671e-11, -2.092713605079652e-11, -1.494710117724000e-11, 7.876620371035379e-11, 8.879490782755327e-10, 7.839182073215675e-09, 5.571783862604661e-08, 3.505063860431956e-08, -8.830150998770921e-07, -5.230341999877964e-05, -1.467850645368747e-04, 2.549218413530653e-02, 1.694947602370687e-01, 1.724122989639759e+01, 1.070716977174984e+03, 2.088715227441257e+03, 7.865685564495293e+02, 1.176726689614456e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_x_tau_hcth_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.333367853307654e-08, -1.013466805845104e-07, -1.122554550451482e-07, -1.252323581999298e-07, -1.330000889577577e-07, -1.039241243154125e-07, 4.601683035559898e-08, -2.593160678342896e-09, -6.422553578279476e-06, -2.518764631422844e-05, 2.056482729847859e-05, 9.910357590829277e-06, 1.497617696523442e-03, -3.000135627023500e-03, -2.549537561833523e-01, 6.601880481331768e-02, -2.164350186418554e+01, -1.289064728256065e+01, -9.585330748382785e-01, -1.536253359441923e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
