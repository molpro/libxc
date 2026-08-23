
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_airy_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_airy", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.140615886064177e+00, -4.056946709924950e+00, -3.939816656305274e+00, -3.777812783567549e+00, -3.557644624145229e+00, -3.266012484803111e+00, -2.894030271972253e+00, -2.445107841585815e+00, -1.943255688082975e+00, -1.430182787146992e+00, -9.513880303835338e-01, -6.275193138668362e-01, -5.465453739120965e-01, -4.416625257518477e-01, -3.141325803662005e-01, -1.978333889014076e-01, -1.166716313926470e-01, -6.421824593256875e-02, -3.861312736725720e-02, -2.735581046729999e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_airy_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_airy", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.525253052419656e+00, -5.408777632748831e+00, -5.244996281067182e+00, -5.016923479875211e+00, -4.703680721353749e+00, -4.281947962747286e+00, -3.731195381948613e+00, -3.049878068340361e+00, -2.294040999987674e+00, -1.579458116164403e+00, -1.014599127127422e+00, -8.189706963819968e-01, -7.325304520386884e-01, -5.654325542699808e-01, -3.588265808026435e-01, -1.903957353918036e-01, -8.738595236353276e-02, -3.674383611365240e-02, -1.072129750914079e-02, -4.176524401798612e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_airy_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_airy", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.755312478166214e-08, -5.539300381444548e-09, -1.012907047469799e-07, -2.875282933605344e-07, -6.854736501065903e-07, -1.637283593249149e-06, -4.217472998907854e-06, -1.205423366439050e-05, -3.746948237063447e-05, -1.317689484937762e-04, -6.762982928563911e-04, -1.422046866112810e-03, 1.412964973984938e-03, -8.712561117156965e-03, -5.655154318206181e-02, -3.929449950265766e-01, -4.621615991763696e+00, -1.101463905771605e+02, -1.109839392113274e+04, -6.828902213473713e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_airy_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_airy", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.210661070796387e-02, -1.277020491211465e-02, -1.379807679561043e-02, -1.544065272267170e-02, -1.817778465402326e-02, -2.297334546242985e-02, -3.170921136496824e-02, -4.694661933889693e-02, -6.800305399375814e-02, -1.119288244866119e-01, -2.734552181836618e-01, -6.392548409166652e-01, -6.391922503098837e-01, -1.390826368506690e+00, -2.372616487511486e+00, -8.063937527857933e+00, 3.943004053038031e+00, -1.135066457942289e+02, 4.589570173808502e+03, 7.497693462076810e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_airy_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_airy", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.955484707297540e-08, 2.362813908478965e-08, 3.085330447786266e-08, 4.479917934234412e-08, 7.492990093472918e-08, 1.499257152654469e-07, 3.672161125921854e-07, 1.051329801276106e-06, 2.824059912237635e-06, 9.100058859500416e-06, 1.676517290282544e-04, 1.592615470687928e-02, 1.684431188247217e-02, 1.888852944815594e-01, 5.534535464310604e-01, 1.398770954358477e+01, -2.277996534814250e+03, -6.017433003532495e+05, -4.656327772525302e+09, -2.347692978078283e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_airy_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_airy", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.136185542974861e-13, -2.695579454908854e-13, -3.752168901150686e-13, -5.987187762832747e-13, -1.150429768986094e-12, -2.813215029802804e-12, -9.064145677688581e-12, -3.434288158054134e-11, 1.974759418028451e-11, 8.331775435621575e-09, 1.048397416097265e-06, -1.032303691521119e-03, -7.960079443163742e-03, -4.996920039767952e-02, 5.389513933503755e-01, 1.660959175744584e+02, 5.797871810903788e+05, 1.163821610384817e+10, 1.537401446845478e+16, 5.482810192968830e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
