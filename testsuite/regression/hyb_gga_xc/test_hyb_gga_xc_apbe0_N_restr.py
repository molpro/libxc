
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_apbe0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apbe0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.305947441060089e+00, -3.243889553129003e+00, -3.156992381888002e+00, -3.036746989541982e+00, -2.873170994129083e+00, -2.656046168088596e+00, -2.377810670887225e+00, -2.038664026739369e+00, -1.652698559289737e+00, -1.246868192886820e+00, -8.407131732336659e-01, -5.429994943880301e-01, -4.746664355939721e-01, -3.919253641649576e-01, -2.839630009980142e-01, -1.798390305243684e-01, -9.198158638801708e-02, -3.146810218757379e-02, -6.577659236882946e-03, -7.276220975884005e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_apbe0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apbe0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.143218041496827e+00, -4.056238872614495e+00, -3.934255640353916e+00, -3.765072392813825e+00, -3.534148180083700e+00, -3.226134169524881e+00, -2.828839134988508e+00, -2.341510909084586e+00, -1.790873551298392e+00, -1.255749976734067e+00, -8.325673161367533e-01, -6.833084349121535e-01, -6.179121196231253e-01, -4.913659575785774e-01, -3.262911847987635e-01, -1.869895442461965e-01, -1.070825280865386e-01, -4.113641818935671e-02, -8.761918405792747e-03, -9.701509818779091e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_apbe0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apbe0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.635631578934588e-06, -2.859543099886779e-06, -3.213768904278323e-06, -3.797582994896477e-06, -4.817316700549289e-06, -6.749883065508652e-06, -1.084991393671621e-05, -2.096696232429765e-05, -5.110409045687981e-05, -1.619213960793534e-04, -7.596155961875508e-04, -2.356760542847652e-03, -8.806668038258570e-04, -8.112028244741800e-03, -4.455554139393703e-02, -2.757025127819446e-01, -1.049411798600395e+00, -1.848674337393096e+00, -2.258055429056703e+00, -2.498082993657978e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_apbe0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.669458642267459e-03, -1.012617742495962e-02, -1.082053404966726e-02, -1.190147904421278e-02, -1.364107155918380e-02, -1.657058209713425e-02, -2.179810279845702e-02, -3.168506309425895e-02, -5.011785590064580e-02, -7.193977075769076e-02, -1.251958128738760e-01, -4.666233305922279e-01, -5.118656794240719e-01, -9.943284661974237e-01, -2.522488358990903e+00, -2.650655473661207e+00, 9.067557366794482e+00, -3.282320938336559e+02, -1.010989931405041e+04, -8.374860685760021e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_apbe0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.334068810865581e-08, 2.662445439792971e-08, 3.214257506878212e-08, 4.205369510714143e-08, 6.160374773272692e-08, 1.055054563579363e-07, 2.226630626860793e-07, 6.063821395474147e-07, 2.018690660129103e-06, 1.555494169169069e-06, -1.042011680230347e-04, 1.072095829850595e-02, 2.008371418507610e-02, 1.167202390693796e-01, 1.060110913033586e+00, -1.167749320066580e+01, -3.045802680448259e+03, -2.201018003114747e+05, -3.154053333464117e+07, -2.588032563737605e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_apbe0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_apbe0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.231159156791432e-14, -6.064504703863914e-14, -7.443065690646436e-14, -9.796057771675835e-14, -1.371328119442922e-13, -1.744383830629993e-13, 2.041593232439826e-13, 8.554470892969354e-12, 2.417488143685719e-10, 1.375578636632839e-08, 1.910838458746824e-06, -5.473777412535000e-04, -7.511505877177856e-03, -2.976711648752754e-02, -2.914940875353060e-01, 2.200862132939121e+02, 3.012487635072042e+05, 6.680064533201028e+08, 1.145695004032648e+13, 7.296088090276516e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
