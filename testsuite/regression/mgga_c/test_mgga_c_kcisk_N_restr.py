
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_kcisk_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.458367639934837e-02, -4.411483701252183e-02, -4.344129798659296e-02, -4.247440488757189e-02, -4.108844070548897e-02, -3.910851692415637e-02, -3.630490172714910e-02, -3.243119008913260e-02, -2.744365054240368e-02, -2.226845268587469e-02, -2.183020644556044e-02, -4.809906408186554e-02, -5.194697566223127e-02, -3.616391726057064e-02, -2.472626389421442e-02, -1.309720785037344e-02, -4.317496702221498e-03, -7.467421729713039e-04, -3.675887434772899e-05, -4.763967348792766e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_kcisk_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.897906215609423e-02, -9.822479093161723e-02, -9.714079956528306e-02, -9.558181825618872e-02, -9.333481755250073e-02, -9.007945705748063e-02, -8.531646075929311e-02, -7.826656760535407e-02, -6.802941539227836e-02, -5.579740503994711e-02, -5.327236275208495e-02, -8.101988975288299e-02, -7.482945465201384e-02, -6.347995443610392e-02, -5.255280006038856e-02, -3.447382194690200e-02, -1.314991589145560e-02, -2.732336412350094e-03, -1.408060793362590e-04, -1.841021629777414e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcisk_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.030935789032804e-06, 1.086910931235739e-06, 1.172696971946567e-06, 1.307789123127325e-06, 1.528852280974562e-06, 1.910612050227504e-06, 2.620996702182010e-06, 4.085448911243311e-06, 7.579467365843066e-06, 1.864415505695693e-05, 1.026180325583328e-04, 2.828911999986228e-03, 1.000386436677755e-02, 1.588921997425233e-02, 3.724949975581929e-02, 1.439540955413439e-01, 7.145279227653208e-01, 5.005366271206888e+00, 3.159889635637129e+01, 3.222423830916704e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcisk_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.049107674098158e-03, -1.032970164401011e-03, -1.009999041493104e-03, -9.774172308589953e-04, -9.314221757447907e-04, -8.669438225158422e-04, -7.776774371472035e-04, -6.573191608131949e-04, -5.043675158313886e-04, -3.357016920668666e-04, -2.247223752263240e-04, -3.834048592497540e-04, -3.294376425352980e-03, -9.915478088666997e-03, -8.908259463883969e-03, -4.719546770984457e-03, -1.457293830228053e-03, -2.179172113834447e-04, -1.169362396640451e-05, -1.639250050361013e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcisk_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.793535650491333e-04, -4.033034862926043e-04, -4.405417629256085e-04, -5.005017699525713e-04, -6.021002288705578e-04, -7.875088487772119e-04, -1.163588686725895e-03, -2.041341354730461e-03, -4.426305215825561e-03, -1.165984318613301e-02, -3.799211807352811e-02, -2.434871062701072e-02, -1.688818510807990e-02, -9.981580564922671e-02, -4.122604249422994e-01, -3.196465380618136e+00, -2.312826350400634e+01, -2.102645145283220e+02, -1.355352132717363e+03, -1.335268031121119e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcisk_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.716712006895158e-09, 7.586261418443881e-09, 9.037031987459590e-09, 1.162075325137815e-08, 1.667647734458158e-08, 2.801040308724471e-08, 5.892974984518333e-08, 1.706168511005128e-07, 7.650699930999764e-07, 6.070831447307387e-06, 1.209057664865264e-04, 1.426866300858139e-03, 1.674587258871075e-03, 4.991804318402671e-02, 5.908152218019603e-01, 2.149205860172380e+01, 1.815294183371708e+03, 5.134603121524610e+05, 3.988992055087472e+08, 3.055570816661275e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcisk_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.595107743345426e-06, -6.973825250139073e-06, -7.552293314873347e-06, -8.458099296524119e-06, -9.925868440926592e-06, -1.241693541864810e-05, -1.691182516768009e-05, -2.570007710048729e-05, -4.486356223634613e-05, -9.346964110653296e-05, -2.425531396554985e-04, -6.275454119688318e-04, -4.829628741478886e-03, -4.432451304740562e-02, -1.941998144966752e-01, -7.954281045325187e-01, -3.454553266830682e+00, -1.748960170496472e+01, -1.086054517925944e+02, -1.131666376155758e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcisk_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.300701334810930e-13, -1.566949779636153e-13, -2.047604564392065e-13, -3.006402480863802e-13, -5.214621177865305e-13, -1.146971794332254e-12, -3.533375773220248e-12, -1.749423151973780e-11, -1.680852787774728e-10, -4.178934567490994e-09, -5.737140530895438e-07, -5.805482745374962e-04, -7.628187364191801e-03, -4.181486324288863e-02, -1.121613390593478e+00, -2.052342399485645e+02, -1.979226039734616e+05, -1.725884744377220e+09, -1.585447172613392e+14, -9.400162789706253e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcisk_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.724360631504561e-11, -1.075977981863411e-10, -1.244154624608451e-10, -1.532085179911144e-10, -2.063526531311145e-10, -3.155216663634918e-10, -5.765701722899157e-10, -1.350250629114291e-09, -4.443250980138396e-09, -2.344906696671816e-08, -3.493667215569293e-07, -8.282037870051143e-05, -6.286753107459518e-03, -2.887430745674439e-02, -1.593925007936386e-01, -1.639486226780091e+00, -3.731874683163178e+01, -1.405605117514598e+03, -1.748679316168870e+05, -1.366831165592533e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_kcisk_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_kcisk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.766309275352704e-07, 4.997323387665135e-07, 5.348012593942224e-07, 5.892345160890019e-07, 6.763541069383470e-07, 8.216991523698574e-07, 1.077899118943152e-06, 1.562765497885534e-06, 2.567848545168975e-06, 4.970866146900405e-06, 1.465802783568823e-05, 1.797752263347077e-04, 1.063616186849428e-02, 9.044327889301250e-02, 2.749960161424182e-01, 9.222965686583791e-01, 3.812578284369505e+00, 1.967785415267517e+01, 1.312020081037907e+02, 1.453120585148711e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
