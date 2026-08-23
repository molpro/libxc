
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lrc_wpbeh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbeh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.416829392843285e+00, -3.350416621111660e+00, -3.257410566638219e+00, -3.128689464845376e+00, -2.953537891774289e+00, -2.720957812689324e+00, -2.422751797557120e+00, -2.059035955563175e+00, -1.645293770241121e+00, -1.212928324600013e+00, -7.875418373960912e-01, -4.871536389443785e-01, -4.173538936213577e-01, -3.283525609261878e-01, -2.128217503061914e-01, -1.053540693200338e-01, -2.718232593440149e-02, -7.756142100835044e-04, -4.505952143231538e-06, -6.064720775628972e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lrc_wpbeh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.345536450866669e+00, -4.253028205105585e+00, -4.123285784689150e+00, -3.943328065355219e+00, -3.697661787786303e+00, -3.369879789208834e+00, -2.946750224318766e+00, -2.426482593841484e+00, -1.833699415851581e+00, -1.250913333382504e+00, -7.931995441900427e-01, -6.436802838616521e-01, -5.711124889019501e-01, -4.411981011409841e-01, -2.678964709242570e-01, -1.163541480053528e-01, -3.808812342315712e-02, -1.714706148105215e-03, -9.048387407981189e-06, -1.213009793957003e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lrc_wpbeh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.359567395558697e-06, -2.562242043080128e-06, -2.883271530133820e-06, -3.413344063022064e-06, -4.341730890165523e-06, -6.108429554086892e-06, -9.880976948563477e-06, -1.929902467162205e-05, -4.809008440354549e-05, -1.573385532911870e-04, -7.528591677886140e-04, -1.737806318537026e-03, 4.015370482323612e-04, -4.900885383133380e-03, -3.412540771688401e-02, -2.440537489171464e-01, -7.714943276890012e-01, -8.121058201377465e-02, 5.984633579607373e-03, 1.504904610541906e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lrc_wpbeh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.008040409625103e-02, -1.055484062032841e-02, -1.127648502790782e-02, -1.240089606857182e-02, -1.421350898992871e-02, -1.727707944040439e-02, -2.279413883873260e-02, -3.354335468066014e-02, -5.565416414153778e-02, -8.859948756414920e-02, -1.874830378763163e-01, -4.773631486354573e-01, -5.231145553647236e-01, -1.007640844030716e+00, -2.868696685571421e+00, -4.965780677754726e+00, 1.979986740686156e+00, -6.190957686446972e+01, -3.230658147628974e+01, -3.142946999709483e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lrc_wpbeh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.195676213680989e-08, 2.509011587242963e-08, 3.036924057813092e-08, 3.988856306019649e-08, 5.878171150872150e-08, 1.016465089257108e-07, 2.183482242240818e-07, 6.214932821709195e-07, 2.400105125340240e-06, 6.491525757920140e-06, 3.800173946974517e-05, 9.884788317036361e-03, 1.443070510458348e-02, 1.079441722382905e-01, 1.349336585530820e+00, 2.221521015166186e+00, -2.030246710178107e+03, -1.072992764570404e+04, 1.370155662893428e+05, 2.578560911633706e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_lrc_wpbeh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lrc_wpbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.916505849915813e-14, -6.959998223219086e-14, -8.749479823872703e-14, -1.201760569239679e-13, -1.838476570549318e-13, -3.063647315207793e-13, -3.611975081910674e-13, 4.064897983963136e-12, 1.624182725667090e-10, 1.130777182268652e-08, 1.509128073346671e-06, -6.062947164534543e-04, -7.314408302739062e-03, -3.585543066368124e-02, -8.326083489858486e-01, 1.106517790752470e+02, 1.862949034690906e+05, 1.905095754866349e+07, -4.574627482934510e+10, -6.593206723271994e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
