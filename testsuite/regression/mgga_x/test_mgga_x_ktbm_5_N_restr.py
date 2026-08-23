
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_5_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.712305958579291e+00, -4.619748942171817e+00, -4.490100787649214e+00, -4.310600786840147e+00, -4.066198460095700e+00, -3.741272956441808e+00, -3.323606269317390e+00, -2.810931459222092e+00, -2.216719727961624e+00, -1.570383577484730e+00, -9.735884789945310e-01, -6.412062164042583e-01, -5.686728301412287e-01, -4.842780813053610e-01, -3.445500696746845e-01, -1.992560182914082e-01, -8.808341522145635e-02, -2.824285818217401e-02, -5.861793415904089e-03, -6.492939407960624e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_5_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.912579729584341e+00, -5.782893054231157e+00, -5.600960257961439e+00, -5.348528949302100e+00, -5.003815055287786e+00, -4.543909517855915e+00, -3.951484453788322e+00, -3.231240414855346e+00, -2.447775131080969e+00, -1.741992476519511e+00, -1.151989764073257e+00, -7.911821962092920e-01, -7.770772539759389e-01, -6.021842330228494e-01, -3.901769201087393e-01, -2.319825295622191e-01, -1.075508086047956e-01, -3.478718384513249e-02, -7.205536930843801e-03, -7.963751269146492e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_5_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.287807694356636e-06, -7.893504840405169e-06, -8.850962956169398e-06, -1.042719086807228e-05, -1.317542437312390e-05, -1.836649736088818e-05, -2.929102911301172e-05, -5.556184561016394e-05, -1.265876818908850e-04, -3.112753268211461e-04, -7.557583100512339e-04, -3.825537266567266e-03, -1.788272937396765e-02, -4.421386002903514e-02, -1.398786737140461e-01, -4.520082624850382e-01, -1.832829279510460e+00, -1.735223087894448e+01, -4.431796107448175e+02, -3.910163170909146e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_5_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.535403799399367e-03, 7.673064439389966e-03, 7.873835181159973e-03, 8.168045559671315e-03, 8.601407152846543e-03, 9.241644591640416e-03, 1.017919163992505e-02, 1.146952737567413e-02, 1.268353118691477e-02, 1.104202409030185e-02, 4.326572516368113e-03, -1.401334027544934e-03, 2.667572436851788e-02, 4.412019202095747e-02, 4.915773350490956e-02, 3.461552185475452e-02, 1.321367417952483e-02, 4.211734360502182e-03, 9.782527417382040e-04, 1.186736081126736e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_5_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.534410314340203e-02, -1.611591901615473e-02, -1.729497818805687e-02, -1.914256698845225e-02, -2.214069794274985e-02, -2.723036174138780e-02, -3.628796013501188e-02, -5.239981742399926e-02, -7.358024050661910e-02, -7.441461513515404e-02, -1.203202304661050e-01, -4.536266674476732e-01, -9.223143437604374e-01, -1.440677033392604e+00, -2.002720862127996e+00, -3.071812007723851e+00, -3.269832043109925e+01, -3.799827468047452e+02, -9.070568238313050e+03, -7.444520879000506e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_5_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.343281650521474e-08, 6.137905022076175e-08, 7.486110610432064e-08, 9.941534344583924e-08, 1.488250161101070e-07, 2.629011625791655e-07, 5.780414359688909e-07, 1.634567144803522e-06, 5.143116448164830e-06, -1.551647145725831e-06, -2.934795738703409e-04, -3.805537904691598e-03, 2.991373616693630e-02, 1.561142637109018e-01, 2.491711144535463e-01, -2.026072787733980e+01, -2.444859069724711e+02, 1.319485405588118e+05, 4.816624361539419e+08, 3.207061138324652e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_5_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.564133416747428e-05, -1.705281592757238e-05, -1.931635360609867e-05, -2.312681944915316e-05, -3.001034096189204e-05, -4.378296403362792e-05, -7.559112264994484e-05, -1.627626901397189e-04, -4.060324395700572e-04, -5.298706618546535e-04, -2.674648208053566e-04, 6.553749526560045e-03, 8.436173912388105e-02, 4.716870649235370e-02, -1.259197257040765e-01, 1.453364410860798e-01, -1.546855747389013e-01, -3.387760383238309e+01, -1.065076153191497e+03, -9.733636092225787e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_5_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.115062608212130e-14, -7.766591255538464e-14, -1.094396929150800e-13, -1.788660092040682e-13, -3.609280310614038e-13, -9.803219222084059e-13, -4.021545735055422e-12, -2.864852278169495e-11, -4.000957365770051e-10, -1.097613947880863e-08, -5.972868622904289e-07, -4.897664376865756e-05, -1.231836364793871e-03, -1.721412687821285e-02, -8.416459215257807e-01, -1.543506750671756e+02, -1.662609737111171e+05, -2.012912868732838e+09, -7.275715249888428e+14, -3.711831605653122e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_5_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.592770541999549e-10, 1.930179976826702e-10, 2.543945458399286e-10, 3.781806581605345e-10, 6.677929699891097e-10, 1.505996082384081e-09, 4.784032952729964e-09, 2.407498676541862e-08, 2.073055225675148e-07, 2.598547503828432e-06, 3.599476636445851e-05, 1.102216704812525e-03, 1.250160921811637e-02, 9.715309940770972e-02, 2.126821042634003e+00, 6.883276407717628e+01, 3.996873623749054e+03, 1.290563840102839e+06, 4.094990557913187e+09, 2.859657749224949e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_5_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_5", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.228953295793573e-07, -3.671703823085416e-07, -4.416372936401866e-07, -5.757584510722936e-07, -8.422298818788252e-07, -1.451132332623763e-06, -3.143814405952758e-06, -9.245523408960266e-06, -3.812565252227497e-05, -1.715697035525707e-04, -4.446729416689136e-04, -1.701930935278575e-03, -5.561125536803364e-02, -2.206527156881089e-01, -1.474106855865926e+00, -9.548597361731369e+00, -4.878269873854448e+01, -5.078469404522426e+02, -1.453313795267901e+04, -1.393908474675292e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
