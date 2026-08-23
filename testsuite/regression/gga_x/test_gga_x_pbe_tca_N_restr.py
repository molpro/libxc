
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_tca_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_tca", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.305527504079285e+00, -4.223928769659130e+00, -4.109714043683363e+00, -3.951761661508861e+00, -3.737090682440970e+00, -3.452573631756687e+00, -3.088919782346306e+00, -2.647780140110711e+00, -2.150587076673997e+00, -1.636353143252383e+00, -1.109029026931110e+00, -6.652979348390929e-01, -5.628922602597431e-01, -4.730123599057389e-01, -3.529822859073522e-01, -2.400331477690917e-01, -1.389054181958758e-01, -5.116015405950834e-02, -1.082030843798239e-02, -1.197636532766033e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_tca_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_tca", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.371228815699847e+00, -5.256381035960469e+00, -5.095314591032325e+00, -4.871919114090037e+00, -4.566960151740022e+00, -4.160033377006133e+00, -3.634547636577368e+00, -2.987881351308164e+00, -2.250890713319782e+00, -1.524707806212234e+00, -9.775881887475659e-01, -7.961343699909964e-01, -7.147409713830790e-01, -5.514961970486515e-01, -3.496321849251749e-01, -1.948422978267117e-01, -1.375452106092576e-01, -6.524823597584438e-02, -1.439656768378038e-02, -1.596805252914264e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_tca_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_tca", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.964390682022750e-06, -4.292071412599947e-06, -4.810130908138656e-06, -5.663449840040852e-06, -7.153609368382602e-06, -9.980958139011461e-06, -1.600879521518875e-05, -3.110030180186288e-05, -7.779372296000464e-05, -2.644199124226931e-04, -1.334700038577281e-03, -7.296473280664516e-03, -1.329344191524407e-02, -2.941992353912141e-02, -1.140238106014722e-01, -6.704284643188588e-01, -3.230972843030241e+00, -6.681958079769432e+00, -8.306936462392660e+00, -9.188421142836445e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_tca_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_tca", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.244122692962496e-02, -1.302919508700969e-02, -1.392477207700916e-02, -1.532335978637141e-02, -1.758664860960586e-02, -2.143792030724819e-02, -2.845699553344375e-02, -4.237905295386703e-02, -7.177534160547319e-02, -1.250978116234799e-01, -2.362415844497849e-01, -5.880051812162533e-01, -6.860289759665850e-01, -1.239901393615520e+00, -2.760205333113212e+00, 3.701868047808101e-01, 7.680829920529354e+01, -3.269780153154737e+02, -1.637557389880543e+04, -1.378198696252090e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_tca_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_tca", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.622128677100288e-08, 3.003501441052934e-08, 3.648719417355594e-08, 4.819643710666569e-08, 7.167212604389680e-08, 1.258181151388072e-07, 2.773029405292235e-07, 8.228160865886428e-07, 3.408296633545940e-06, 1.564519859004235e-05, 8.898789945726375e-05, 1.279997463656880e-02, 3.960251920626861e-02, 1.408932953270081e-01, 9.617664851494349e-01, -3.185693992550226e+01, -8.371618515414923e+03, -7.859383625569915e+05, -1.160391394940342e+08, -9.519399885632687e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_tca_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_tca", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.534755913254036e-14, 4.500601549321459e-14, 6.366535900698984e-14, 1.047098285916137e-13, 2.135661759863726e-13, 5.915701656398310e-13, 2.525368837269767e-12, 1.972510032021803e-11, 3.507552055170563e-10, 1.777194879668926e-08, 2.713284180291992e-06, 2.333687098843520e-04, 1.302043579283442e-03, 1.588605565075464e-02, 1.231928445180251e+00, 5.817671949029217e+02, 8.648775652698159e+05, 2.394785332440151e+09, 4.215191265001216e+13, 2.683667035501460e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
