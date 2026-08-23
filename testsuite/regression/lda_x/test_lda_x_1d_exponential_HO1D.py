
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_1d_exponential_HO1D_2_zk():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_exponential", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.278718253605853e-01, -3.278716728096215e-01, -3.278712691284915e-01, -3.278701986734190e-01, -3.278673512089519e-01, -3.278597429633677e-01, -3.278392960670148e-01, -3.277839975935459e-01, -3.276337920085248e-01, -3.272267890602749e-01, -3.261409649678803e-01, -3.233378321172439e-01, -3.164345424279392e-01, -3.002286989202127e-01, -2.632593889133841e-01, -1.825703232351238e-01, -6.348331706934690e-02, -5.279943552136649e-03, -4.258797015828780e-05, -8.239636356419814e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_1d_exponential_HO1D_2_vrho():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_exponential", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.994134407936654e-01, -3.992050188409207e-01, -3.994775759543155e-01, -3.991396664308569e-01, -3.995806881389208e-01, -3.990333599554880e-01, -3.997454464358670e-01, -3.988602434605123e-01, -4.000060972256262e-01, -3.985778229280105e-01, -4.004118817934185e-01, -3.981157446138080e-01, -4.010274981680932e-01, -3.973561642194195e-01, -4.019234395433529e-01, -3.960980601593367e-01, -4.031423982270858e-01, -3.939888436448347e-01, -4.046227229706624e-01, -3.903841702277354e-01, -4.060643467418994e-01, -3.840374219302154e-01, -4.067253204076768e-01, -3.723592469890548e-01, -4.050289193213299e-01, -3.496027007519407e-01, -3.972579577329394e-01, -3.031823366719768e-01, -3.720068571806211e-01, -2.142468131089617e-01, -2.903057421352493e-01, -9.443510375898440e-02, -1.149390336693838e-01, -1.736011959134545e-02, -1.018965492267301e-02, -7.679430393102045e-04, -8.405098959047544e-05, -3.447172283797928e-06, -1.639512344304837e-08, -3.830881232549496e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_1d_exponential_HO1D_2_v2rho2():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_1d_exponential", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.372406239650126e-02, 5.551115123125783e-17, -7.441471600935279e-02, -7.351214877664142e-02, -8.326672684688674e-17, -7.463190306436207e-02, -7.317205327638787e-02, -8.326672684688674e-17, -7.498583274274112e-02, -7.263017890479562e-02, -8.326672684688674e-17, -7.556388853233342e-02, -7.177681756559134e-02, 5.551115123125783e-17, -7.651142288983437e-02, -7.045780248671979e-02, 0.000000000000000e+00, -7.807373439713644e-02, -6.847887336911634e-02, 2.775557561562891e-17, -8.067425987987836e-02, -6.564666357261340e-02, -5.551115123125783e-17, -8.506970889240129e-02, -6.188476332234832e-02, 2.775557561562891e-17, -9.268389136763439e-02, -5.745866084520498e-02, 1.387778780781446e-17, -1.064004855051844e-01, -5.329927481228100e-02, 4.163336342344337e-17, -1.326721536476113e-01, -5.144229401393741e-02, 0.000000000000000e+00, -1.878654711842140e-01, -5.627158300395210e-02, -1.110223024625157e-16, -3.195788972564227e-01, -8.101341356042988e-02, -2.775557561562891e-17, -6.795256474545603e-01, -1.896654360113088e-01, 0.000000000000000e+00, -1.702347898207978e+00, -8.000688294654229e-01, -3.330669073875470e-16, -4.132328610835621e+00, -3.568129958307171e+00, -4.440892098500626e-16, -8.571386513111378e+00, -9.867721037329751e+00, 8.881784197001252e-16, -1.585521227268812e+01, -2.076571545423115e+01, -1.776356839400250e-15, -2.768417064144575e+01, -3.902810882268052e+01, 2.131628207280301e-14, -4.689176008812916e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
