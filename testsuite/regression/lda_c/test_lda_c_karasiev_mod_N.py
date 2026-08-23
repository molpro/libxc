
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_karasiev_mod_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev_mod", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.172577953912237e-01, -1.166571809046274e-01, -1.157953752192036e-01, -1.145602576739348e-01, -1.127932643623668e-01, -1.102721248396403e-01, -1.066896388700420e-01, -1.016318401840208e-01, -9.457338061412854e-02, -8.497411523430627e-02, -7.259612187091044e-02, -5.985148201730001e-02, -5.614769659967090e-02, -5.207827517637591e-02, -4.402640525468907e-02, -3.288030379076740e-02, -2.029957768710801e-02, -9.027512452897164e-03, -2.292800481965255e-03, -2.646898731265247e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_karasiev_mod_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev_mod", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270726485008233e-01, -1.270744783463187e-01, -1.264608139772218e-01, -1.264646980937101e-01, -1.255818407250762e-01, -1.255901788340980e-01, -1.243197205992142e-01, -1.243379145586877e-01, -1.225085189833726e-01, -1.225491689497583e-01, -1.199106708106583e-01, -1.200046736669666e-01, -1.161834576500621e-01, -1.164120455792333e-01, -1.108183277770834e-01, -1.114165933099761e-01, -1.029958206719811e-01, -1.047367758164258e-01, -9.115319947370294e-02, -9.697314022237334e-02, -7.273924216144276e-02, -9.369508916740438e-02, -5.574511919774339e-02, -1.040120872364499e-01, -5.231073241462814e-02, -1.017163784415820e-01, -4.892016042711261e-02, -9.244317315157355e-02, -4.175176168316110e-02, -8.141060310891708e-02, -3.179730898455879e-02, -6.744463320629723e-02, -2.060025016718489e-02, -4.964498031880394e-02, -1.005113018790826e-02, -2.841050732035017e-02, -2.832270818475890e-03, -1.001885229972415e-02, -3.452710877388379e-04, -1.829562603217639e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_karasiev_mod_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev_mod", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.639769882990815e-04, -4.754507136957135e-04, 3.639956471483195e-04, 3.846156513506014e-04, -5.030497686721286e-04, 3.846577408323741e-04, 4.163032517288540e-04, -5.455107251444653e-04, 4.164018551532456e-04, 4.663511098873930e-04, -6.127795835768360e-04, 4.665950200234854e-04, 5.486545078420000e-04, -7.239208854930185e-04, 5.493069061994329e-04, 6.919924854672939e-04, -9.189180705916826e-04, 6.939448346848692e-04, 9.626193161141422e-04, -1.291672616063195e-03, 9.694833925797061e-04, 1.533598618568138e-03, -2.096484056583093e-03, 1.563990498885711e-03, 2.921249679140858e-03, -4.155592961515287e-03, 3.107677821845629e-03, 6.707168205793951e-03, -1.069741290270414e-02, 8.467172064215494e-03, 1.399714570046453e-02, -3.441976851417596e-02, 3.775253586431369e-02, 1.241218443348584e-02, -8.313234290892729e-02, 1.862479246118068e-01, 1.510368533483924e-02, -1.205481451477212e-01, 2.937966533561760e-01, 2.747954291997807e-02, -2.137133483683297e-01, 4.874620071051296e-01, 5.856464990461939e-02, -5.946901959863031e-01, 1.441269218360288e+00, 1.169950110534767e-01, -2.780635884262725e+00, 8.152170027047191e+00, -6.882943330961839e-01, -2.429827835821169e+01, 1.012139074102876e+02, -4.298377604023766e+01, -4.561468473568011e+02, 3.501315255645482e+03, -2.509451520007429e+03, -2.040882436265263e+04, 4.578273750728816e+05, -2.810322156919787e+05, -2.977484952181421e+06, 3.263618849955577e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
