
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_pbe1w_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbe1w", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.381782287021760e+00, -4.299143222474985e+00, -4.183425771657922e+00, -4.023297246613510e+00, -3.805461213557378e+00, -3.516305774947916e+00, -3.145763993446720e+00, -2.694174100356215e+00, -2.180777858588232e+00, -1.643521486759305e+00, -1.110697446272166e+00, -7.138874358698672e-01, -6.183255304028388e-01, -5.145981206577629e-01, -3.766629555906190e-01, -2.425209617005976e-01, -1.274959784216750e-01, -4.493730734536314e-02, -9.641329164446610e-03, -1.085987308962024e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_pbe1w_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbe1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.510255454855033e+00, -5.394960432841005e+00, -5.233277169003086e+00, -5.009052636005763e+00, -4.703031838706032e+00, -4.294879730545115e+00, -3.768350048852056e+00, -3.121900126813129e+00, -2.388793455811097e+00, -1.669296275480598e+00, -1.101711027148018e+00, -8.846147196576245e-01, -7.952767968153696e-01, -6.308267384020567e-01, -4.207063810272453e-01, -2.454186593497279e-01, -1.454141381644060e-01, -5.833727945684795e-02, -1.280186302243097e-02, -1.446231423106498e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_pbe1w_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbe1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.319134795647908e-06, -3.597182852408818e-06, -4.036816273001318e-06, -4.760913505117479e-06, -6.024760365866000e-06, -8.418656466715231e-06, -1.349899289814331e-05, -2.607168239689978e-05, -6.389658024785738e-05, -2.064266113072866e-04, -9.908168886330422e-04, -4.391062785486632e-03, -6.018364804082277e-03, -1.668375180752250e-02, -7.051666795664205e-02, -4.017873699063020e-01, -1.600676086518911e+00, -2.913954568644987e+00, -3.566938869972838e+00, -3.945108943222295e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_pbe1w_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbe1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.246131524782386e-02, -1.304319212794491e-02, -1.392773249261142e-02, -1.530474514536992e-02, -1.752160535867633e-02, -2.126012734132313e-02, -2.796081166137619e-02, -4.080600369499846e-02, -6.586674352117870e-02, -1.023645613545306e-01, -1.858776730789848e-01, -5.873846565360228e-01, -6.776764748739157e-01, -1.235461911541596e+00, -2.878835375605993e+00, -2.418691577850633e+00, 1.946121656407954e+01, -4.381510477243138e+02, -1.455373823398655e+04, -1.241761192497893e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_pbe1w_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbe1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.592056631390411e-08, 2.960500781473896e-08, 3.580857884831382e-08, 4.698394655430934e-08, 6.912961315593679e-08, 1.192328211202892e-07, 2.546927198218715e-07, 7.101559071390364e-07, 2.516847914766463e-06, 4.595502907151262e-06, -8.637719326456888e-05, 1.151448699165724e-02, 2.752646876632137e-02, 1.229446424611246e-01, 9.446088290633379e-01, -2.127185513173244e+01, -4.553385135511164e+03, -3.464373625711636e+05, -4.983070454301313e+07, -4.087187801407410e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_pbe1w_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbe1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.173260234330874e-14, -2.356388409088204e-14, -2.549759621125998e-14, -2.503535029988890e-14, -7.657608007628667e-15, 1.214412728070029e-13, 1.178957757469174e-12, 1.404996891200908e-11, 3.111400634328006e-10, 1.664981070141445e-08, 2.382054260735953e-06, -2.264947761735752e-04, -3.633050510985897e-03, -1.035284297798853e-02, 3.402391389133084e-01, 3.504817891529557e+02, 4.542036807435657e+05, 1.052116148258112e+09, 1.810035737271064e+13, 1.152243608021414e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
