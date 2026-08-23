
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_wpbeh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wpbeh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.292405094858156e+00, -4.211111947775038e+00, -4.097371836695414e+00, -3.940172958567680e+00, -3.726723726543464e+00, -3.444204890618193e+00, -3.083686607637440e+00, -2.646333748783062e+00, -2.147486892605856e+00, -1.611841810483507e+00, -1.080743452000735e+00, -6.638182078954437e-01, -5.612352107024537e-01, -4.723482480692601e-01, -3.508747273421823e-01, -2.285137228917797e-01, -1.202086557272461e-01, -4.235119028379575e-02, -8.774367439460052e-03, -9.701687029584501e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_wpbeh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wpbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.351840489172627e+00, -5.235567591681631e+00, -5.072464882792286e+00, -4.846211691761702e+00, -4.537441480588721e+00, -4.126213854010292e+00, -3.599135272660007e+00, -2.967378894779101e+00, -2.299999185877807e+00, -1.657938828507796e+00, -1.067210550034897e+00, -7.891467835745714e-01, -7.138362437606350e-01, -5.460815494504466e-01, -3.692603894628210e-01, -2.107088098600303e-01, -1.361869120644121e-01, -5.601698696861852e-02, -1.169915658594674e-02, -1.293558270611267e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_wpbeh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wpbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.984689127789038e-06, -4.334639051037005e-06, -4.890154106936422e-06, -5.809719884433112e-06, -7.423633658927012e-06, -1.049106516699664e-05, -1.694928178065775e-05, -3.216511897311269e-05, -7.107595668661719e-05, -1.976555093889602e-04, -9.955458720785817e-04, -7.698861974692542e-03, -1.280874128024821e-02, -3.110262117112449e-02, -9.288109311475765e-02, -5.032215086921438e-01, -1.633131204123095e+00, -1.016876081115951e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_wpbeh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wpbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.310255939379418e-02, -1.374149251415535e-02, -1.471106164726507e-02, -1.621289139220073e-02, -1.859782930674880e-02, -2.246953034004425e-02, -2.865904037204681e-02, -3.653749193420919e-02, -3.641169414579237e-02, -8.990355235659606e-02, -3.091400275955075e-01, -6.112632316996728e-01, -7.111039817016575e-01, -1.218591584936689e+00, -1.138099888381802e+00, 3.011635429725803e+00, 1.383485071626431e+01, -3.744628305232672e+02, -1.365370820893483e+04, -1.116831695920287e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_wpbeh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wpbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.370446816471769e-08, 3.864699059832458e-08, 4.694672936975243e-08, 6.178193768375772e-08, 9.056006064552299e-08, 1.519400774022596e-07, 2.904543414732675e-07, 4.989527982852325e-07, -1.176900676864035e-06, -1.548897603100529e-06, 2.336225575219138e-04, 1.496805351768002e-02, 4.919065860598687e-02, 1.361156173417945e-01, -6.586966784225449e-01, -4.843408452161852e+01, -4.071441058537189e+03, -4.635007332278909e+05, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_wpbeh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_wpbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.332399078318760e-14, -4.957403799590347e-14, -5.859424539791244e-14, -6.859120131803642e-14, -5.676602433792315e-14, 1.785422272018693e-13, 2.777573202062790e-12, 4.058211556013443e-11, 8.618638657098830e-10, 1.861402509467782e-08, 1.578370973484262e-06, 1.289086028026337e-04, -2.843988072185802e-03, 2.156363646339080e-02, 2.362361414615264e+00, 5.679844753779511e+02, 4.263098339155696e+05, 1.139370171121305e+09, 1.442249570307408e-15, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
