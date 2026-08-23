
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_yt65_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_yt65", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.610318323537625e+01, 9.244540713911020e+01, 8.744379384409388e+01, 8.075414698397762e+01, 7.208546220219000e+01, 6.134825814512745e+01, 4.887500292644236e+01, 3.563676627823945e+01, 2.323814684871640e+01, 1.332161721629484e+01, 6.129462617029412e+00, 2.274820134797815e+00, 1.649014364169626e+00, 1.144086554567525e+00, 6.221393888592029e-01, 2.978744127908416e-01, 1.691918163620174e-01, 1.321703069664953e-01, 1.206817487747346e-01, 1.148479567067544e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_yt65_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_yt65", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.471617478471801e+02, 1.410908811976380e+02, 1.327922901013511e+02, 1.216980397402601e+02, 1.073312438835692e+02, 8.955378558944686e+01, 6.893499398609343e+01, 4.712320296024898e+01, 2.690928097714972e+01, 1.166340959376930e+01, 4.373323013741016e+00, 3.288320626583392e+00, 2.584697588375619e+00, 1.591769030752388e+00, 6.408907288428005e-01, 9.540774016263755e-02, -9.354461440042057e-02, -1.244231782945319e-01, -1.203496817317495e-01, -1.148438970561129e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_yt65_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_yt65", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.395972074266220e-04, 1.484104318935524e-04, 1.620553133695426e-04, 1.838705949109920e-04, 2.203949659103945e-04, 2.857283325690044e-04, 4.142120913819912e-04, 7.035022785829846e-04, 1.491499102226154e-03, 4.241077996983689e-03, 1.556106215085604e-02, 4.036601860520649e-02, 6.080146296788502e-02, 1.170459081780438e-01, 3.731431120198315e-01, 2.147531937439418e+00, 2.545696853715004e+01, 7.767563913729892e+02, 8.753008032221702e+04, 6.475346267504433e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_yt65_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_yt65", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.204708131046716e-01, 6.354660718089311e-01, 6.577861451026383e-01, 6.915316569443346e-01, 7.437479878212534e-01, 8.274216492984765e-01, 9.689250381857120e-01, 1.229352676449200e+00, 1.775509431897734e+00, 3.106995446711898e+00, 5.451349232694986e+00, 4.351876637749136e+00, 4.588787123733972e+00, 6.443242630055035e+00, 1.228788236426846e+01, 3.991443873324719e+01, 3.188922137995606e+02, 8.132895365399926e+03, 8.446751083616528e+05, 5.949407252141237e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_yt65_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_yt65", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.794952128524536e-07, -8.810262517932301e-07, -1.050476983652026e-06, -1.352335826916885e-06, -1.942957639945758e-06, -3.265627201306543e-06, -6.862866265881721e-06, -1.979661823885805e-05, -8.898278287765699e-05, -7.194697030599673e-04, -9.685866210512177e-03, -6.517661832143506e-02, -1.478727159614037e-01, -5.479897848489225e-01, -5.569431281913779e+00, -1.844757368928920e+02, -2.592228988405787e+04, -2.413401966155153e+07, -3.064605984485505e+11, -1.677204371363343e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_yt65_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_yt65", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
