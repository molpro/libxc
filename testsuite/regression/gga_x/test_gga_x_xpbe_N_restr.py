
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_xpbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_xpbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.312015454166888e+00, -4.230464107295730e+00, -4.116311708514368e+00, -3.958435751981922e+00, -3.743843489289477e+00, -3.459361770581667e+00, -3.095549991716543e+00, -2.653579988208669e+00, -2.153411116728724e+00, -1.631190946803980e+00, -1.100778363396148e+00, -6.666482104172389e-01, -5.635599717270700e-01, -4.740465359164159e-01, -3.528970637812785e-01, -2.344579861796869e-01, -1.267333724602493e-01, -4.447299397957757e-02, -9.330244075169698e-03, -1.032296020510764e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_xpbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_xpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.367441974740253e+00, -5.252792259672241e+00, -5.092040144407274e+00, -4.869161983329817e+00, -4.565095567953261e+00, -4.159803194304007e+00, -3.637531307639201e+00, -2.997666339625755e+00, -2.275476462062780e+00, -1.574608357009585e+00, -1.025342546997471e+00, -7.962627206062637e-01, -7.141978518466529e-01, -5.521891035289467e-01, -3.564673745909212e-01, -2.116922105472346e-01, -1.391036467245183e-01, -5.768495099010709e-02, -1.242410367139454e-02, -1.376371613967422e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_xpbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_xpbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.097842036398815e-06, -4.432684173983967e-06, -4.961221378332220e-06, -5.829688318931912e-06, -7.340580587318782e-06, -1.018987561031670e-05, -1.620250368836989e-05, -3.098267173860737e-05, -7.516673316134026e-05, -2.415698663772908e-04, -1.178208447184843e-03, -7.430641183073315e-03, -1.382596712240382e-02, -2.967478771399897e-02, -1.074762096564143e-01, -5.403959016319625e-01, -2.025148903789064e+00, -3.633294278337255e+00, -4.416654086996018e+00, -4.879928247477273e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_xpbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_xpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.239105180369792e-02, -1.296782128596232e-02, -1.384429301601177e-02, -1.520797683411918e-02, -1.740126096859991e-02, -2.109338017939436e-02, -2.768598714481852e-02, -4.020669430679917e-02, -6.392600894122152e-02, -9.332004142808176e-02, -1.445730283103436e-01, -5.768061894193213e-01, -6.859400533682185e-01, -1.200371867046271e+00, -2.301107178513248e+00, 2.527317879458341e+00, 4.037911617003910e+01, -4.047413482047307e+02, -1.427300037894203e+04, -1.188091922600776e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_xpbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_xpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.575854563010617e-08, 2.941470615938881e-08, 3.556843724407501e-08, 4.664723150969168e-08, 6.857710593061558e-08, 1.180822052461751e-07, 2.512566622268284e-07, 6.930160493564656e-07, 2.356224317182506e-06, 1.722119103909547e-06, -1.815563775985929e-04, 1.189578901893361e-02, 3.973305978224918e-02, 1.258053403835586e-01, 4.971330186134010e-01, -4.599145352819503e+01, -5.937969763081009e+03, -4.341981488505275e+05, -6.174208780707817e+07, -5.055758040383497e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_xpbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_xpbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.097349738703022e-14, 6.481674134947292e-14, 9.150980104473268e-14, 1.500550853011299e-13, 3.046190846265690e-13, 8.373713327995299e-13, 3.528392495411162e-12, 2.691333187831032e-11, 4.571330882815957e-10, 2.129486098350983e-08, 3.087946904081059e-06, 3.291011644529672e-04, 1.895088470752125e-03, 2.208269398624759e-02, 1.546954438038464e+00, 5.777041455407181e+02, 5.889208971047193e+05, 1.317585129851748e+09, 2.242398970564323e+13, 1.425293486233883e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
