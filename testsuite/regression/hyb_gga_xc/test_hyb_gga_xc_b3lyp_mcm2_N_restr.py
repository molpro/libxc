
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b3lyp_mcm2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.540299401054618e+00, -3.473905052280379e+00, -3.380920921338384e+00, -3.252219039411847e+00, -3.077060980558881e+00, -2.844375057873604e+00, -2.545743053847087e+00, -2.180660534658338e+00, -1.763082154959631e+00, -1.322745509405410e+00, -8.902760255301643e-01, -5.770516896851001e-01, -4.952362518963602e-01, -4.148354411814673e-01, -3.013228702838516e-01, -1.853104083919150e-01, -1.017138185566378e-01, -7.142974529404784e-02, -4.399497670137666e-02, -2.974052041685796e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b3lyp_mcm2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.425853815402237e+00, -4.334159479315149e+00, -4.205657851831685e+00, -4.027625332990678e+00, -3.785003303462031e+00, -3.462113338475712e+00, -3.046874791735240e+00, -2.538974906883847e+00, -1.963364371031388e+00, -1.388630141083512e+00, -9.264020170836991e-01, -7.046421934142385e-01, -6.279075580631102e-01, -5.025535718591355e-01, -3.476295363403909e-01, -2.123409446457847e-01, -1.068744720865045e-01, -3.646137472217753e-02, -1.345167359504335e-02, -5.051939793161806e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_mcm2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.962849653289907e-06, -3.193243711135868e-06, -3.555069820988228e-06, -4.145246077359853e-06, -5.161111212033039e-06, -7.047713630687676e-06, -1.094362715730174e-05, -2.025009873780812e-05, -4.723281654660360e-05, -1.473839159789509e-04, -6.817477282961392e-04, -4.523421432671012e-03, -9.050510216582179e-03, -1.656644992077543e-02, -4.813825437718898e-02, -1.718848622836513e-01, -1.106110237219722e+00, -1.277589474137042e+02, -1.230393087513896e+04, -7.315879086000484e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_mcm2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.500814768956686e-03, -9.920407945433699e-03, -1.055540499874118e-02, -1.153756975034080e-02, -1.310420427135377e-02, -1.571257483465593e-02, -2.031435708314905e-02, -2.904313286993467e-02, -4.679350721098377e-02, -8.245520180245104e-02, -1.586921132170098e-01, -4.161473589723941e-01, -5.337978047167082e-01, -8.389996371683727e-01, -1.492791445975607e+00, -5.646623159998256e-01, 1.359659094139313e+01, 2.607515473347871e+01, 1.145443555516486e+04, 7.400512941461359e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_mcm2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.481273027495268e-08, 1.678907376192905e-08, 2.008372037871496e-08, 2.593415530621754e-08, 3.729038647671280e-08, 6.223827648583498e-08, 1.270259008911763e-07, 3.347740380214928e-07, 1.149554328130375e-06, 3.309789099354696e-06, -4.824683278416603e-05, 4.672006904700599e-03, 1.942659954247693e-02, 3.857174242335484e-02, -1.119429286097238e-01, -2.972661644600114e+01, -4.408729901516101e+03, -8.086601643341932e+05, -7.368802681099449e+09, -2.486160804986026e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b3lyp_mcm2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b3lyp_mcm2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.666697157667546e-14, 9.563056377599213e-14, 1.313141690019544e-13, 2.068438533800128e-13, 3.961510048271815e-13, 1.000764624807295e-12, 3.731354228985008e-12, 2.390458556509838e-11, 3.213240634107114e-10, 1.168044971902569e-08, 1.554263678992778e-06, 3.787896597238231e-04, 3.332201654659112e-03, 2.239209004674173e-02, 9.541959652606389e-01, 2.685618632960464e+02, 5.477496135565654e+05, 1.455767318686588e+10, 1.764479061873830e+16, 5.867674894651740e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
