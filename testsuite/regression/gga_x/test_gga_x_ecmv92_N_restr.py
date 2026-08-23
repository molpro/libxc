
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ecmv92_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ecmv92", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.319391350529377e+00, -4.237544093776166e+00, -4.122967063058848e+00, -3.964484084268661e+00, -3.749031406196170e+00, -3.463352937239950e+00, -3.097948343620744e+00, -2.654091494070930e+00, -2.152463089798455e+00, -1.631257657774977e+00, -1.102156168164165e+00, -6.673427504615245e-01, -5.646511395101144e-01, -4.743482258182474e-01, -3.527293274204196e-01, -2.361282582845032e-01, -1.313615771474569e-01, -4.706108811409516e-02, -9.907140666503760e-03, -1.096309923613511e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ecmv92_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ecmv92", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.387249315024732e+00, -5.272625835532446e+00, -5.111872928345701e+00, -4.888914218174902e+00, -4.584567815524689e+00, -4.178530482770189e+00, -3.654459168210701e+00, -3.010416572496606e+00, -2.278914176491627e+00, -1.561737174388080e+00, -1.009342753505354e+00, -7.999065211944446e-01, -7.162852143299581e-01, -5.547493453919458e-01, -3.556839481869331e-01, -2.047125705848092e-01, -1.381208256159046e-01, -6.060784810449656e-02, -1.318775880504647e-02, -1.461715585989055e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ecmv92_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ecmv92", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.990835680860931e-06, -4.313890040049621e-06, -4.824053667733034e-06, -5.662995251927515e-06, -7.124592561272196e-06, -9.888110561125060e-06, -1.574837929871413e-05, -3.029081761984513e-05, -7.457349418854018e-05, -2.467851082702897e-04, -1.225716030947434e-03, -7.212560577852550e-03, -1.359099643142776e-02, -2.887304119138502e-02, -1.080036665333958e-01, -5.896955791180433e-01, -2.510097078424824e+00, -4.822843193920826e+00, -5.925102008452359e+00, -6.550006720984810e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ecmv92_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ecmv92", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.225886291370034e-02, -1.283586589996952e-02, -1.371401364183093e-02, -1.508350110410079e-02, -1.729442334409458e-02, -2.104017151700462e-02, -2.780850594315714e-02, -4.098780892817543e-02, -6.758995366323838e-02, -1.095665610640119e-01, -1.922485089525179e-01, -5.764461414901705e-01, -6.765985693286314e-01, -1.209252315402833e+00, -2.528389799116022e+00, 1.353211326682598e+00, 5.548657295697866e+01, -3.738362556172721e+02, -1.508689427189971e+04, -1.261694326292591e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ecmv92_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ecmv92", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.394460490502510e-08, 2.745794173917780e-08, 3.340142568129663e-08, 4.418129873066956e-08, 6.575475168144487e-08, 1.152784711354452e-07, 2.522168067154885e-07, 7.309398777062551e-07, 2.809893287720210e-06, 8.552711536373628e-06, -4.573344828146381e-05, 1.170952934191188e-02, 3.563392026938380e-02, 1.276202038206061e-01, 7.149652404662186e-01, -3.863420240044469e+01, -6.939478966248960e+03, -5.720528403194438e+05, -8.280015382554537e+07, -6.785980854499381e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ecmv92_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ecmv92", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.188848764123870e-14, 7.643468047015359e-14, 1.037944389869939e-13, 1.619107646708143e-13, 3.094969978301718e-13, 7.969697450072955e-13, 3.164818412159468e-12, 2.325105199731598e-11, 3.939376543302545e-10, 1.902088046079697e-08, 2.831203000308093e-06, 3.063734068432060e-04, 3.134892926355565e-03, 1.954899642141507e-02, 1.351590462126794e+00, 5.685436679868699e+02, 7.014460431946194e+05, 1.739269726052567e+09, 3.007467398095638e+13, 1.913071224475985e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
