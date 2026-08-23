
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.181005011884106e-01, -1.175104822067875e-01, -1.166639080915098e-01, -1.154506647774307e-01, -1.137150153558131e-01, -1.112385707952570e-01, -1.077191527608338e-01, -1.027484489869595e-01, -9.580683027705426e-02, -8.639778734297576e-02, -7.515614494109685e-02, -6.728781798214682e-02, -6.401376631667918e-02, -5.892134114546935e-02, -5.036277141941004e-02, -3.864269092959546e-02, -2.484785365645267e-02, -1.174260537123911e-02, -3.358560066475415e-03, -4.555973635505379e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.277432572428230e-01, -1.271429344462565e-01, -1.262813379876873e-01, -1.250460679924261e-01, -1.232778627544222e-01, -1.207527632715596e-01, -1.171595189944789e-01, -1.120745348690601e-01, -1.049518302379465e-01, -9.525228800144497e-02, -8.358536041193310e-02, -7.536171952253776e-02, -7.192443293536149e-02, -6.655874885997350e-02, -5.748215537563645e-02, -4.490058092257824e-02, -2.971428683828055e-02, -1.457546721392367e-02, -4.315135500204937e-03, -5.993073628406838e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.477821653936588e-05, -5.818743100302824e-05, -6.345891082367964e-05, -7.187104179908716e-05, -8.591587417055009e-05, -1.109337971872867e-04, -1.598202599407623e-04, -2.687960155817162e-04, -5.608761267566032e-04, -1.552986632884381e-03, -5.467033732056635e-03, -1.366778461715822e-02, -2.022632367448800e-02, -3.776227541845071e-02, -1.132003551035780e-01, -5.822917512919116e-01, -5.566302815691706e+00, -1.049702125439140e+02, -4.221519621669958e+03, -4.863190488603624e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
