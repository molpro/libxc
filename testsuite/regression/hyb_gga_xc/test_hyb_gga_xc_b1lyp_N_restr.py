
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b1lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.303378167236378e+00, -3.241911219993130e+00, -3.155834410031807e+00, -3.036706709397615e+00, -2.874606455095748e+00, -2.659322405122291e+00, -2.383128949199353e+00, -2.045644878722575e+00, -1.659727383895794e+00, -1.251732135686942e+00, -8.448057725646783e-01, -5.422622305906148e-01, -4.646763697336282e-01, -3.906117133374202e-01, -2.851072642617914e-01, -1.761254231601981e-01, -9.762815788854431e-02, -7.130288678866338e-02, -4.475941390308298e-02, -3.053360020263735e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b1lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.101686830380213e+00, -4.016476644685134e+00, -3.897063049109823e+00, -3.731624421177683e+00, -3.506173540101817e+00, -3.206160317346839e+00, -2.820419190030143e+00, -2.348850918026120e+00, -1.815225255784960e+00, -1.284666025641166e+00, -8.603189757433231e-01, -6.567684304125002e-01, -5.864305103236366e-01, -4.692645274814435e-01, -3.254297714023072e-01, -2.008879199633374e-01, -1.022395015233365e-01, -3.465813457531915e-02, -1.318116395131374e-02, -5.113567463263560e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.046565495612116e-06, -3.283417783733309e-06, -3.655375432890912e-06, -4.262050202761709e-06, -5.306241094826927e-06, -7.245227688488217e-06, -1.124852989244410e-05, -2.080798448487755e-05, -4.850215279692117e-05, -1.510923119888834e-04, -6.966058790758801e-04, -4.630614845875919e-03, -9.266221142468764e-03, -1.691530818671156e-02, -4.875806514890477e-02, -1.678370201269433e-01, -1.007697173283738e+00, -1.312779063165897e+02, -1.265836509787956e+04, -7.526624574074572e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.932561202532224e-03, -9.329059348194949e-03, -9.929201654089639e-03, -1.085763778037461e-02, -1.233886574588075e-02, -1.480523924570796e-02, -1.915465438706155e-02, -2.738674992667186e-02, -4.398777887000392e-02, -7.625557479509440e-02, -1.419346252921943e-01, -3.906498076091381e-01, -5.004603992821056e-01, -7.861437502978236e-01, -1.358066380520858e+00, 8.879305345107191e-02, 1.752211445922697e+01, 5.342692644316686e+01, 1.249349375712903e+04, 7.682594544971005e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.522397315633060e-08, 1.725447198045376e-08, 2.063914175416813e-08, 2.664871920079789e-08, 3.831158100292129e-08, 6.392430255383037e-08, 1.303938753376134e-07, 3.432004064147030e-07, 1.173416823508057e-06, 3.250944168647649e-06, -5.459987640067233e-05, 4.745548079033886e-03, 1.980917540959463e-02, 3.873224614172328e-02, -1.322995457378759e-01, -3.158949932795166e+01, -4.641763043922084e+03, -8.269155080923261e+05, -7.581072717179610e+09, -2.557778605952702e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.887548516118874e-14, 9.838535367900426e-14, 1.350968816892535e-13, 2.128023182921942e-13, 4.075627621678822e-13, 1.029593235398451e-12, 3.838841799367293e-12, 2.459319502582138e-11, 3.305803121509376e-10, 1.201692357924454e-08, 1.599036706782693e-06, 3.897012960121637e-04, 3.428191002735712e-03, 2.303712967771783e-02, 9.816830918319330e-01, 2.762982132675374e+02, 5.635284090088122e+05, 1.497703002763980e+10, 1.815307676824928e+16, 6.036702566514136e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
