
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mpwlyp1m_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpwlyp1m", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.169572714313726e+00, -4.091766544259481e+00, -3.982811353028159e+00, -3.832026220312949e+00, -3.626860416941213e+00, -3.354405360298380e+00, -3.004915062363138e+00, -2.577967535989218e+00, -2.089936271883950e+00, -1.574362088806941e+00, -1.061079089870902e+00, -6.762030776607140e-01, -5.778231996222855e-01, -4.858109861677958e-01, -3.553131015147611e-01, -2.213394320129499e-01, -1.166221167542611e-01, -3.710169042463225e-02, -1.563197960641944e-03, -1.039974891365652e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mpwlyp1m_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpwlyp1m", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.176788610229788e+00, -5.068889824711180e+00, -4.917685051995051e+00, -4.708212304323963e+00, -4.422776770473687e+00, -4.042992116771460e+00, -3.554806879249799e+00, -2.958299422453241e+00, -2.284034362577215e+00, -1.615037749459189e+00, -1.076845831030138e+00, -8.171128235331050e-01, -7.292559198882942e-01, -5.809108578407112e-01, -3.995546443741721e-01, -2.461123127397783e-01, -1.503481809097222e-01, -9.139088623236505e-02, -3.611043783686572e-03, -1.422896053151491e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpwlyp1m_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpwlyp1m", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.903064722612826e-06, -4.206094206369263e-06, -4.681900161747467e-06, -5.457762404008808e-06, -6.792642645892463e-06, -9.269913737941776e-06, -1.437944341636121e-05, -2.655890247922652e-05, -6.172554146538733e-05, -1.912531117291988e-04, -8.879415750574831e-04, -6.094523029740807e-03, -1.225207070366006e-02, -2.259445023165854e-02, -6.711605045109392e-02, -2.484850871841568e-01, 5.367728130955491e-01, 9.932040640156167e+01, 4.172230577287326e+02, 7.817493280172730e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpwlyp1m_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpwlyp1m", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.131010598760640e-02, -1.181102694603826e-02, -1.256895127709460e-02, -1.374083725918448e-02, -1.560881154750296e-02, -1.871435896046549e-02, -2.417472703160392e-02, -3.444190810132792e-02, -5.477681447119126e-02, -9.176442318775328e-02, -1.654714383745490e-01, -4.968505042767533e-01, -6.342841828903125e-01, -1.002100350267843e+00, -1.741547251669005e+00, 9.668424256441965e-01, 1.182051430444421e+02, -1.515245162570862e+03, -2.385465279304825e+04, -1.574968811625941e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpwlyp1m_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpwlyp1m", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.926333851227372e-08, 2.181996512485853e-08, 2.607696411630042e-08, 3.362275306752240e-08, 4.822784530944984e-08, 8.015484768304804e-08, 1.622841821395871e-07, 4.199354284761667e-07, 1.358386845288630e-06, 1.974142308814908e-06, -1.115666772557251e-04, 6.342480443047601e-03, 2.651020310286537e-02, 5.423225937790618e-02, -1.184561047018474e-01, -4.322539996260144e+01, -1.257394600668964e+04, 1.383888368104529e+06, 5.356282817211849e+09, 7.390386498499282e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpwlyp1m_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpwlyp1m", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.039556529508840e-13, 1.296760017192995e-13, 1.780831885316565e-13, 2.805708776224969e-13, 5.375422457457313e-13, 1.358766588836787e-12, 5.071742276057523e-12, 3.256416666709557e-11, 4.399613491554260e-10, 1.618618028207944e-08, 2.173704469963081e-06, 5.144512103322665e-04, 4.535785855322027e-03, 3.044969720740655e-02, 1.312886119276694e+00, 3.880681341955132e+02, 9.590956024750608e+05, -1.153130229218481e+10, -1.988637895010994e+15, -2.133414846813857e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
