
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_thakkar_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_thakkar", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.361143603946297e+01, 9.001066361913763e+01, 8.508589937034299e+01, 7.849668424342526e+01, 6.995306030037094e+01, 5.935975698365266e+01, 4.703007156665428e+01, 3.389578610077142e+01, 2.151151663494409e+01, 1.158626318521573e+01, 5.096135919859840e+00, 2.197741780983436e+00, 1.610677403353378e+00, 1.098330539217369e+00, 5.612654456194291e-01, 2.146521655969405e-01, 6.201584183363377e-02, 1.293831174690246e-02, 1.787398950978638e-03, 1.390491356135692e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_thakkar_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_thakkar", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.459725304368734e+02, 1.400428345502289e+02, 1.319407489662564e+02, 1.211163105978357e+02, 1.071130473473701e+02, 8.981300021250840e+01, 6.979986648479803e+01, 4.871862267161266e+01, 2.929596771810942e+01, 1.455203239396993e+01, 6.136790979198700e+00, 3.306441381308175e+00, 2.553466509402334e+00, 1.618397471351562e+00, 7.357998913334778e-01, 2.351538813360114e-01, 5.499946118251793e-02, 9.440417014615022e-03, 1.052748195506531e-03, 6.867155418625534e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_thakkar_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_thakkar", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.077973336733990e-04, 1.140090859181044e-04, 1.235260787389432e-04, 1.385068420780278e-04, 1.630080400883672e-04, 2.052909427508349e-04, 2.839038117256697e-04, 4.456926287089372e-04, 8.272678567935469e-04, 1.914814009793931e-03, 6.277133666838316e-03, 2.860360181789902e-02, 4.866646337370559e-02, 7.882028100639055e-02, 1.881153485639638e-01, 6.564944133416176e-01, 3.278307480166845e+00, 2.731872484010454e+01, 5.244547476650838e+02, 3.448017616405921e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_thakkar_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_thakkar", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.798569282272600e-01, 5.919557557763969e-01, 6.097499867909622e-01, 6.361635081433270e-01, 6.758722771346760e-01, 7.365852736212304e-01, 8.313782294646588e-01, 9.826099435943467e-01, 1.226230973812146e+00, 1.612767896498745e+00, 2.355698676041440e+00, 3.834124532882340e+00, 4.382873273717138e+00, 5.446919363780535e+00, 7.496233540713352e+00, 1.026007656990581e+01, 9.888545705222407e+00, -1.795979588404585e+01, -9.442352707378102e+02, -7.763586251536504e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_thakkar_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_thakkar", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.912165808201936e-07, -4.311298417165049e-07, -4.952934086061077e-07, -6.033474128031687e-07, -7.973318016131512e-07, -1.176427802643670e-06, -1.997508173501665e-06, -3.935355540480482e-06, -7.700830650882791e-06, 1.327950615323472e-05, 5.082773653987286e-04, -2.206536005216970e-02, -9.018565027355635e-02, -1.469522093416513e-01, -1.645840039160575e-01, 1.717064755056445e+01, 1.860678081012509e+03, 4.811057360494445e+05, 9.261148195564518e+08, 4.148672439265658e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_thakkar_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_thakkar", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.260895961235523e-12, -2.807963081240302e-12, -3.822891303662058e-12, -5.923727997240844e-12, -1.100520461325969e-11, -2.633394265599144e-11, -8.951297944383308e-11, -4.933969661542927e-10, -5.255647110134153e-09, -1.360595129630673e-07, -1.176027794909846e-05, -1.935399131525326e-03, -1.046697992512475e-02, -8.250507174864706e-02, -2.490559509913657e+00, -3.939208490949454e+02, -3.524302095046281e+05, -2.996784307196743e+09, -7.520939426662199e+14, -2.765466553363416e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
