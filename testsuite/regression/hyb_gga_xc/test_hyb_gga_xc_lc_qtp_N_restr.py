
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_qtp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_qtp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.107178051744003e+00, -4.024871787638629e+00, -3.909577357271629e+00, -3.749938435679718e+00, -3.532549363480606e+00, -3.243469715945212e+00, -2.871761842778258e+00, -2.415610173922835e+00, -1.889581055716881e+00, -1.326606336683141e+00, -7.851626170024179e-01, -4.617933488270213e-01, -3.751626262464757e-01, -2.762213939251810e-01, -1.445324294431392e-01, -3.405121898523715e-02, 8.888780353389684e-03, -3.347576840195156e-03, -9.118268895638392e-04, -1.023974860282954e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_qtp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_qtp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.203925189436080e+00, -5.091047128530621e+00, -4.932915304972830e+00, -4.713952687796732e+00, -4.415811175191358e+00, -4.019598936862822e+00, -3.511310963096067e+00, -2.892339680061115e+00, -2.196622294049616e+00, -1.511164718468587e+00, -9.553944304282715e-01, -6.415275307371552e-01, -5.405520222402612e-01, -4.053992203344542e-01, -2.426660762044786e-01, -1.119951929894884e-01, -3.962622057509295e-02, -4.711082894869216e-03, -1.210808957516669e-03, -1.364598120606271e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_qtp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_qtp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.685854161604991e-06, -3.964008348386785e-06, -4.399281937174041e-06, -5.105473221457753e-06, -6.311177443384287e-06, -8.522015447978750e-06, -1.299394914268772e-05, -2.330110940035124e-05, -5.122270968794599e-05, -1.405547283823688e-04, -4.853911790969598e-04, -2.675703849564512e-03, -4.677413494176366e-03, -5.091809612462170e-03, 8.870057237369035e-03, 2.759852309871039e-01, 4.230223655643314e+00, 5.244525491119981e+00, -6.588161601853624e-06, -1.486333696324757e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_qtp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_qtp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.165662857561754e-02, -1.216248806379019e-02, -1.292644413505354e-02, -1.410427964631186e-02, -1.597344480426087e-02, -1.905923634420775e-02, -2.442260232556798e-02, -3.430815673430597e-02, -5.318076626691205e-02, -8.501641630896904e-02, -1.366636277244234e-01, -4.351423635030321e-01, -5.802116572358529e-01, -7.973486009796616e-01, -1.079630160232364e+00, 9.785148666898742e-01, 1.718120559979344e+01, -8.068280842030349e+01, -1.385167701294173e+03, -1.175147199522315e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_qtp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_qtp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.766309774949446e-08, 1.994474270204032e-08, 2.372471616154640e-08, 3.037307456530919e-08, 4.308392704290772e-08, 7.030958809711482e-08, 1.378225495703870e-07, 3.337660569513095e-07, 8.857912180926503e-07, -2.325713544135928e-06, -2.127969632384761e-04, 4.838790869009660e-04, 3.673949781949517e-03, -2.297871570826247e-02, -7.005680624363608e-01, -3.534930618905977e+01, -3.461185276816374e+03, 1.637836593796955e+05, -8.359417853497311e+01, -1.464504699494543e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_qtp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_qtp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.616061949058092e-14, 1.197267807419226e-13, 1.639589241385038e-13, 2.572294329539669e-13, 4.896617468463456e-13, 1.225387760736501e-12, 4.500370888318908e-12, 2.810670052432392e-11, 3.607534070822563e-10, 1.196039861092936e-08, 1.332437188303822e-06, 2.725284266578059e-04, 2.141240683605064e-03, 1.174616362753149e-02, 2.825637866102145e-01, 1.600726261764057e+01, 9.781620192416134e+02, 8.740603167460395e+04, 2.276804750970982e+07, 3.096474621473813e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
