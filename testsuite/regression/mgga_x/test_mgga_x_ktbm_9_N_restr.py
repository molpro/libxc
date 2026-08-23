
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_9_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.995392537725272e+00, -4.896747834946138e+00, -4.758367848816834e+00, -4.566319131156740e+00, -4.303765886004987e+00, -3.952138838382365e+00, -3.493676773751958e+00, -2.914442100770838e+00, -2.207673518709937e+00, -1.421328263810351e+00, -7.961122666153353e-01, -5.470452196376169e-01, -5.729987073096274e-01, -4.888926896921130e-01, -3.197770498973068e-01, -1.605621975709453e-01, -6.611859347933183e-02, -2.089032360829007e-02, -4.330305479802925e-03, -4.797882599566751e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_9_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.245810475079643e+00, -6.111860658601987e+00, -5.924368077810199e+00, -5.665142285531565e+00, -5.313191351919736e+00, -4.848199169358065e+00, -4.259115805118071e+00, -3.559691991969074e+00, -2.787985894872581e+00, -1.906392413167462e+00, -1.080840383424777e+00, -8.014822914942541e-01, -8.606087700509534e-01, -6.735513255977033e-01, -4.365422690470071e-01, -2.083407444941083e-01, -8.141015323486644e-02, -2.539300972832551e-02, -5.234060972500670e-03, -5.780205416562376e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_9_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.916342255741467e-06, -9.653477516185734e-06, -1.081745887629497e-05, -1.273034784227064e-05, -1.605566742829808e-05, -2.230260691143900e-05, -3.530504683734575e-05, -6.580009966087325e-05, -1.432920165532374e-04, -3.192707436948022e-04, -6.808851409141854e-04, -3.406517848442411e-03, -1.983564168770890e-02, -4.990930069550743e-02, -1.457524626198541e-01, -4.188987442292789e-01, -1.617892260447590e+00, -1.526774785978255e+01, -3.924186221421385e+02, -3.478715506908625e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_9_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.016078286712518e-02, 1.045086965252106e-02, 1.088391284899409e-02, 1.154037840539908e-02, 1.255621250378655e-02, 1.416751404584220e-02, 1.677208463779615e-02, 2.082295375393545e-02, 2.509150688173608e-02, 2.107137727228562e-02, 8.645306572949119e-03, 9.978814685700492e-03, 5.973881837087535e-02, 9.119644141963211e-02, 1.022882581540950e-01, 4.947099858716579e-02, 1.319448891497539e-02, 3.761976446110221e-03, 8.667997469192227e-04, 1.055800696596177e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_9_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.583380733643841e-02, -1.657382098755738e-02, -1.769195553655527e-02, -1.941418366525421e-02, -2.213230777520608e-02, -2.653835208242956e-02, -3.380535809979814e-02, -4.567173039566426e-02, -6.897199064361313e-02, -1.643428238373892e-01, -3.620203528373505e-01, -9.000115591147468e-01, -8.694632589573452e-01, -1.292872651431386e+00, -3.243458340904823e+00, -8.999321364024535e+00, -3.243046148116878e+01, -3.076445447584873e+02, -7.227220566867551e+03, -5.940143040635620e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_9_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.566608583474028e-08, 7.537078885127959e-08, 9.180469417426563e-08, 1.216386289872171e-07, 1.813284144891323e-07, 3.176091407165697e-07, 6.850014042135517e-07, 1.840868699209379e-06, 4.873443504078333e-06, -8.901017234701947e-06, -3.057689029746465e-04, -5.011225036675064e-03, 2.408556819307016e-02, 1.425073413820344e-01, -1.033905266641738e-01, -1.817350375494725e+01, 1.256152008076795e+02, 2.449837153647038e+05, 8.090769753898981e+08, 5.354007064188713e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_9_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.665656420099554e-05, -5.170158129982161e-05, -5.988638393303967e-05, -7.385079165219946e-05, -9.937093664252158e-05, -1.503049987937138e-04, -2.616943841014073e-04, -5.025935771888373e-04, -6.425004893278454e-04, 2.059768475425541e-03, 7.940183419214658e-03, 4.626882670580887e-02, 4.259249150098166e-02, -8.291035040585254e-02, 7.329471252607428e-01, 4.386747623845283e+00, 2.269688976293268e+00, -5.585585398516341e+01, -1.781352856865877e+03, -1.624889189160826e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_9_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.062880915210913e-13, -1.350516216045393e-13, -1.904153345348067e-13, -3.114587896106100e-13, -6.290998259491987e-13, -1.710262583112689e-12, -7.013500078590173e-12, -4.964816100684182e-11, -6.740977297521608e-10, -1.709744659023526e-08, -8.337076524593221e-07, -6.772950923761880e-05, -1.958893284897815e-03, -2.827383268431368e-02, -1.319848151130428e+00, -2.186210914428669e+02, -2.160557087902913e+05, -2.553001055884154e+09, -9.221177291773968e+14, -4.712299233149221e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_9_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.593094143608231e-10, 3.142725507450614e-10, 4.142280835430820e-10, 6.157019623878263e-10, 1.086406761885960e-09, 2.443951681977832e-09, 7.704205990847482e-09, 3.786693602737940e-08, 3.038237690678770e-07, 3.236681770605914e-06, 3.721817348923358e-05, 1.149026238447488e-03, 1.812413883571506e-02, 1.432852094565115e-01, 2.732993946676226e+00, 7.301162008048860e+01, 4.052854647416113e+03, 1.325692299813895e+06, 4.239352242894487e+09, 2.972067944770748e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_9_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_9", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.731371675014533e-08, 8.617626212269278e-08, 8.024342066056037e-08, 5.871996452725180e-08, -1.674808942065584e-08, -3.045227052358767e-07, -1.602801434357652e-06, -8.953579684452447e-06, -5.797289434354716e-05, -2.957570564235164e-04, -7.453130936785423e-04, -5.746332588539722e-03, -5.567845828003732e-02, -2.601390332893147e-01, -2.570176883924285e+00, -1.326620374771120e+01, -5.128283208422275e+01, -4.982150980032559e+02, -1.422921740686517e+04, -1.369994100897936e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
