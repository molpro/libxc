
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_gombas_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gombas", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.184526062526675e-01, -1.178550356905735e-01, -1.169977322635701e-01, -1.157693549189037e-01, -1.140126281295473e-01, -1.115075195334954e-01, -1.079509892096382e-01, -1.029376451697026e-01, -9.596405200461885e-02, -8.659028032693863e-02, -7.557723951762875e-02, -6.804220334713133e-02, -6.495851070782410e-02, -6.022815579704396e-02, -5.245850494043674e-02, -4.206846234801302e-02, -2.943436002291713e-02, -1.518182325128246e-02, -4.230262312874873e-03, -5.107086534824674e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_gombas_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gombas", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.282192444977933e-01, -1.282192444977933e-01, -1.276102952429235e-01, -1.276102952429235e-01, -1.267362995488394e-01, -1.267362995488394e-01, -1.254832296314003e-01, -1.254832296314003e-01, -1.236895435519587e-01, -1.236895435519587e-01, -1.211282012450542e-01, -1.211282012450542e-01, -1.174841693496118e-01, -1.174841693496118e-01, -1.123305798557296e-01, -1.123305798557296e-01, -1.051242247967741e-01, -1.051242247967741e-01, -9.535557913136958e-02, -9.535557913136958e-02, -8.373517420193252e-02, -8.373517420193252e-02, -7.568619886673499e-02, -7.568619886673499e-02, -7.236984410908666e-02, -7.236984410908666e-02, -6.726110751685957e-02, -6.726110751685957e-02, -5.883543200383820e-02, -5.883543200383820e-02, -4.760549884371863e-02, -4.760549884371863e-02, -3.417003581487014e-02, -3.417003581487014e-02, -1.866075446273486e-02, -1.866075446273486e-02, -5.508169264239134e-03, -5.508169264239134e-03, -6.789823074731498e-04, -6.789823074731498e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_gombas_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gombas", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.556478776502127e-05, -5.556478776502127e-05, -5.556478776502127e-05, -5.902413665903924e-05, -5.902413665903924e-05, -5.902413665903924e-05, -6.437278109793239e-05, -6.437278109793239e-05, -6.437278109793239e-05, -7.290707276534223e-05, -7.290707276534223e-05, -7.290707276534223e-05, -8.715292702784966e-05, -8.715292702784966e-05, -8.715292702784966e-05, -1.125190480360523e-04, -1.125190480360523e-04, -1.125190480360523e-04, -1.620475008883751e-04, -1.620475008883751e-04, -1.620475008883751e-04, -2.722742712068631e-04, -2.722742712068631e-04, -2.722742712068631e-04, -5.666318717518586e-04, -5.666318717518586e-04, -5.666318717518586e-04, -1.557981635924922e-03, -1.557981635924922e-03, -1.557981635924922e-03, -5.396976095332593e-03, -5.396976095332593e-03, -5.396976095332593e-03, -1.324882282837076e-02, -1.324882282837076e-02, -1.324882282837076e-02, -1.941960081808737e-02, -1.941960081808737e-02, -1.941960081808737e-02, -3.563763640138379e-02, -3.563763640138379e-02, -3.563763640138379e-02, -1.032866341980849e-01, -1.032866341980849e-01, -1.032866341980849e-01, -5.105961551260202e-01, -5.105961551260202e-01, -5.105961551260202e-01, -5.109292766663705e+00, -5.109292766663705e+00, -5.109292766663705e+00, -1.230241539685641e+02, -1.230241539685641e+02, -1.230241539685641e+02, -5.689172633306925e+03, -5.689172633306925e+03, -5.689172633306925e+03, -5.777902516824685e+05, -5.777902516824685e+05, -5.777902516824685e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
