
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_zvpbeint_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbeint", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.030867133091318e-02, -6.927946885295853e-02, -6.780239372967087e-02, -6.568454596829798e-02, -6.265235221916654e-02, -5.832234137473739e-02, -5.217502722733705e-02, -4.358842476737312e-02, -3.221274501157791e-02, -1.976488158637066e-02, -1.498164245286625e-02, -4.688660181109190e-02, -5.469296581835577e-02, -4.024501217850669e-02, -2.309748045150333e-02, -7.183468744630804e-03, -5.740696037209457e-04, -6.734294450083066e-06, -6.846602267029348e-09, -2.197378745320874e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_zvpbeint_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.360913981549133e-01, -1.352080774041992e-01, -1.339268260665179e-01, -1.320604648890023e-01, -1.293232245901978e-01, -1.252631916051703e-01, -1.191242788619965e-01, -1.095412546670811e-01, -9.400066401443100e-02, -7.041251012393943e-02, -5.772707975920664e-02, -8.889511819422380e-02, -8.129166240178333e-02, -7.934503521963644e-02, -6.472018111450464e-02, -3.086061767924567e-02, -3.332934738743384e-03, -4.292177244858050e-05, -4.473201586773890e-08, -1.453617103102650e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_zvpbeint_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.896115153934566e-07, 7.367218193402125e-07, 8.099640409945278e-07, 9.276950428001034e-07, 1.126073613383195e-06, 1.483138675290015e-06, 2.186750433065838e-06, 3.749424305625472e-06, 7.768099292001842e-06, 2.039836446655421e-05, 1.140152040890304e-04, 3.121981272952588e-03, 7.939522495229924e-03, 1.341973484702019e-02, 3.807828198467192e-02, 1.256288979194956e-01, 1.853980350360540e-01, 7.983828064422004e-02, 9.934590417155510e-03, 2.477853408034232e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_zvpbeint_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.356300757309316e-04, -2.551898220891228e-04, -2.861568770875241e-04, -3.373150079049518e-04, -4.272157839098102e-04, -6.000892221480516e-04, -9.792113779541062e-04, -1.982958345078113e-03, -5.365345724521948e-03, -1.897371058680373e-02, -6.866094175817881e-02, -1.145353907472595e-02, 1.121314726860512e-02, -3.228163706562066e-02, -6.637230821844990e-01, -6.391402181719451e+00, -1.543705779750897e+01, -7.121939253049801e+00, -8.659916418332700e-01, -2.113725434437583e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_zvpbeint_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.188262105207601e-09, 2.537558658537636e-09, 3.138400649231679e-09, 4.256453900569133e-09, 6.586700185782879e-09, 1.230812439909013e-08, 3.011905829957061e-08, 1.082195331938693e-07, 6.595435876472255e-07, 7.564323637892616e-06, 1.815055622644559e-04, -2.822887882358168e-04, -1.341650693202251e-02, -3.711390622669000e-03, 5.438589691268821e-01, 3.349304414129258e+01, 1.036466081332011e+03, 1.571977678696645e+04, 2.271860904140894e+05, 4.245626492225247e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_zvpbeint_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.939855128414397e-14, -1.088058065900819e-13, -1.442919718970746e-13, -2.164058525845508e-13, -3.870626369815816e-13, -8.902214950905721e-13, -2.928522701086992e-12, -1.600325221792839e-11, -1.785562905605906e-10, -5.333212567494547e-09, -7.942234621319732e-07, -5.825044283476736e-04, -5.203762543843850e-03, -3.334497959495950e-02, -1.339814381740721e+00, -2.719444778240779e+02, -9.096588490101650e+04, -4.410697015484203e+07, -7.570650436503371e+10, -1.085576784612766e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
