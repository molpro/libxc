
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_wigner_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_wigner", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.562539220034685e-02, -5.560944076496794e-02, -5.558596234621236e-02, -5.555105944171639e-02, -5.549842915687043e-02, -5.541743527854924e-02, -5.528908753651549e-02, -5.507670127707873e-02, -5.469855777948440e-02, -5.387331706898291e-02, -5.019402974797009e-02, -3.703191167585436e-02, -3.472313314520385e-02, -3.484575652082440e-02, -3.131066586286234e-02, -2.379256321702831e-02, -1.300068193043395e-02, -3.630150413011232e-03, -3.377905446400659e-04, -8.722450966575393e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_wigner_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_wigner", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.588201939963000e-02, -5.588472769543231e-02, -5.586970092192816e-02, -5.587547876295150e-02, -5.585046531655270e-02, -5.586295934853073e-02, -5.581932242738308e-02, -5.584687287887646e-02, -5.576621682250560e-02, -5.582871505853280e-02, -5.566871743907584e-02, -5.581646711920169e-02, -5.547014612657381e-02, -5.584113985953357e-02, -5.500393188565202e-02, -5.602142486311579e-02, -5.368581136538602e-02, -5.685632072849046e-02, -4.910155992065004e-02, -6.079200019833898e-02, -3.294661672005032e-02, -8.008609364456995e-02, -1.238836128007025e-02, -1.220392081841385e-01, -1.078505052514974e-02, -1.258447440019130e-01, -1.154416074058269e-02, -1.206370232131385e-01, -1.003524018555700e-02, -1.194532256150282e-01, -7.004203685496373e-03, -1.165585524958338e-01, -3.657707629410472e-03, -9.953988464839239e-02, -1.095657399674433e-03, -5.783622134905918e-02, -1.108713068366810e-04, -1.667671580918599e-02, -2.918590735648741e-06, -2.032517801943191e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_wigner_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_wigner", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.202231793038773e-04, -6.221856743047395e-04, 6.202532846720818e-04, 6.591513271089448e-04, -6.612979158220013e-04, 6.592196018410262e-04, 7.193723188552262e-04, -7.218271787224329e-04, 7.195335078300071e-04, 8.155309839635460e-04, -8.185404568007915e-04, 8.159341838765164e-04, 9.761922486318105e-04, -9.803118076183428e-04, 9.772882550382583e-04, 1.262548155065179e-03, -1.269267246576560e-03, 1.265905643620761e-03, 1.821891042547321e-03, -1.836238555320683e-03, 1.834103214811904e-03, 3.063124045233169e-03, -3.108054848263377e-03, 3.119937881612740e-03, 6.319572884535510e-03, -6.549171375720830e-03, 6.694077107752795e-03, 1.633965770128738e-02, -1.836924080183337e-02, 2.025030803233253e-02, 3.970391438033434e-02, -6.309410181011214e-02, 9.714328913772874e-02, 3.773349772013510e-02, -1.234930559693396e-01, 3.817539952676685e-01, 4.895695820194841e-02, -1.759730340973398e-01, 5.905957186664039e-01, 9.960749395706582e-02, -3.419930781660944e-01, 1.081133289338240e+00, 2.662087575970946e-01, -1.006152155745241e+00, 3.354206276568459e+00, 9.811654563276689e-01, -4.770726328778085e+00, 1.817314680361325e+01, 5.037837953144694e+00, -3.943088584845555e+01, 1.713758117484055e+02, 3.396979840307088e+01, -6.257456957921946e+02, 2.720332340770159e+03, 2.946491189106409e+02, -1.997390504760457e+04, 8.058543260695170e+04, 5.150153081812234e+03, -1.776645298155459e+06, 7.046203183048478e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
