
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pw_rpa_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_rpa", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.409519107331729e-01, -1.403424243718187e-01, -1.394674456994103e-01, -1.382125062363461e-01, -1.364151259366782e-01, -1.338461961170224e-01, -1.301859297817041e-01, -1.249959892671868e-01, -1.177040398678320e-01, -1.077258127874367e-01, -9.563643134830800e-02, -8.704908968455301e-02, -8.344237961288395e-02, -7.779132229681256e-02, -6.817594762134398e-02, -5.475109494926957e-02, -3.843358970658876e-02, -2.166172455547538e-02, -8.626139464538685e-03, -2.028252382175107e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pw_rpa_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_rpa", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.509106379686113e-01, -1.502948881443339e-01, -1.494107572665854e-01, -1.481423544848172e-01, -1.463249800087616e-01, -1.437259576260559e-01, -1.400195482467542e-01, -1.347570325960405e-01, -1.273472066142649e-01, -1.171723528620132e-01, -1.047776255243018e-01, -9.591839664401582e-02, -9.218149583600183e-02, -8.630503115470682e-02, -7.623786043959266e-02, -6.200703417092523e-02, -4.434318400225060e-02, -2.557758429316640e-02, -1.041203996997167e-02, -2.492365702212446e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pw_rpa_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_rpa", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.617574804438903e-05, -5.969355887570347e-05, -6.513588917373217e-05, -7.382752209934031e-05, -8.835593340707272e-05, -1.142802849001876e-04, -1.650714532336328e-04, -2.787539656263583e-04, -5.854113407003732e-04, -1.637810464976043e-03, -5.853644686952654e-03, -1.481780450407745e-02, -2.205145729446125e-02, -4.154776955335359e-02, -1.265792717613501e-01, -6.662657017159891e-01, -6.607273875611285e+00, -1.389946725918730e+02, -7.413224941056205e+03, -1.465240913158430e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
