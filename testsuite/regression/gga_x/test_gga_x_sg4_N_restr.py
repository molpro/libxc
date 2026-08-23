
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_sg4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sg4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.318385258800231e+00, -4.236544487553217e+00, -4.121935473666372e+00, -3.963314654691517e+00, -3.747454502364076e+00, -3.460699643792988e+00, -3.092568034128466e+00, -2.641963598115279e+00, -2.124750017511631e+00, -1.577698040003024e+00, -1.051863697317836e+00, -6.666772207308420e-01, -5.644499946311968e-01, -4.732869007298361e-01, -3.452210572544324e-01, -2.187233413730373e-01, -1.246634920620993e-01, -4.233247090028189e-02, -8.773911357049358e-03, -9.701680570171680e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_sg4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sg4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.386096083221522e+00, -5.273038356997835e+00, -5.114691256283381e+00, -4.895515199551983e+00, -4.597285192394135e+00, -4.201446942562220e+00, -3.694815906960851e+00, -3.080319959163627e+00, -2.391758903612672e+00, -1.698634907570292e+00, -1.105926099498872e+00, -8.054831656340582e-01, -7.150743301879864e-01, -5.622251438900244e-01, -3.803216516340405e-01, -2.135321177498029e-01, -1.245304329179272e-01, -5.630528170290171e-02, -1.169733267883065e-02, -1.293555682895965e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sg4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sg4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.988816075249202e-06, -4.293941700730939e-06, -4.771562343183118e-06, -5.546612939637237e-06, -6.869640918640556e-06, -9.292622921640671e-06, -1.417629909910157e-05, -2.535632293893600e-05, -5.567318762809982e-05, -1.629595683931122e-04, -7.898693111977962e-04, -6.693867436728217e-03, -1.394121701277234e-02, -2.556985096682719e-02, -7.535552099542077e-02, -4.182028843482948e-01, -2.825968787674000e+00, -3.109955446047022e-01, -3.310217332107893e-01, -3.650340146102811e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sg4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sg4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.168300970755224e-02, -1.217689896037390e-02, -1.291910846190853e-02, -1.405443636056641e-02, -1.583279175351724e-02, -1.870339121232226e-02, -2.349770138816549e-02, -3.176163959704859e-02, -4.671662890263449e-02, -8.380175403292481e-02, -2.060375907462955e-01, -5.050008165545493e-01, -6.643365524308203e-01, -1.002048409706644e+00, -1.723605272132927e+00, -7.426882662747058e+00, 1.611194277978020e+02, -5.632589592511613e+02, -1.363456094859269e+04, -1.116811574772950e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sg4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sg4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.778884218034274e-08, 1.991691412428598e-08, 2.337579824125827e-08, 2.927381592810565e-08, 3.996693605815243e-08, 6.071194702078620e-08, 1.022641819560009e-07, 1.644266478084729e-07, -1.069267866671852e-07, -4.930347609072256e-06, -6.238029964336987e-05, 5.735687302074414e-03, 3.144313260093454e-02, 4.630427859457732e-02, -1.588527487776887e-01, 7.028979344761732e+00, -1.378754495005021e+04, -4.479918960594683e+04, -4.633617034808408e+06, -3.781929721619971e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sg4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sg4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.277773025802442e-13, 1.608205808996363e-13, 2.236014269269270e-13, 3.582462292718533e-13, 7.015779207877147e-13, 1.821001019790100e-12, 6.975852261809553e-12, 4.511447215821914e-11, 5.722676165235276e-10, 1.681669476743596e-08, 1.912119997384405e-06, 6.961281460887413e-04, 5.113735662238039e-03, 4.209904599501655e-02, 1.562740168960201e+00, 2.188492883336933e+02, 1.194743542748498e+06, 1.299813579407422e+08, 1.682316329386387e+12, 1.066177847460438e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
