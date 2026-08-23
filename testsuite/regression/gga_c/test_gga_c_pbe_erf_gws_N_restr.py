
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pbe_erf_gws_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_erf_gws", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.272253696936617e-02, -6.167710864034029e-02, -6.017907845216781e-02, -5.803627273549741e-02, -5.497973242935487e-02, -5.064138794598782e-02, -4.454668728522073e-02, -3.619910873109741e-02, -2.556669865885276e-02, -1.479244987679492e-02, -1.129507055991742e-02, -3.839863588772948e-02, -4.310345004812483e-02, -3.134707886896659e-02, -1.865779903484219e-02, -8.511268478263239e-03, -2.179916476112108e-03, -1.003594764756275e-04, -8.971543659926488e-07, -1.212900479621126e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pbe_erf_gws_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_erf_gws", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.299036962755793e-01, -1.289117067974069e-01, -1.274713964103113e-01, -1.253700349320801e-01, -1.222804243964721e-01, -1.176798346460145e-01, -1.106853658666316e-01, -9.971794809259858e-02, -8.214474426313020e-02, -5.732063905939451e-02, -4.592482194328075e-02, -7.353615007401028e-02, -6.515064291318827e-02, -5.941361255308476e-02, -4.378342412830535e-02, -2.164145525200612e-02, -4.616187607302045e-03, -2.024361040020850e-04, -1.794947024895822e-06, -2.425815570795929e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_erf_gws_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_erf_gws", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.054239044520975e-07, 7.524950177619455e-07, 8.254915093229862e-07, 9.423754766918571e-07, 1.138137050023408e-06, 1.487017912924927e-06, 2.162803383449290e-06, 3.616571190422673e-06, 7.133042596175526e-06, 1.723782895561345e-05, 9.365376967675940e-05, 2.488752364882477e-03, 5.424752422103367e-03, 8.762614635811043e-03, 2.179833730205061e-02, 6.559898528736115e-02, 7.772055603190882e-02, 7.620272341656897e-03, 2.625526329502153e-04, 4.787688379925521e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_erf_gws_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_erf_gws", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.797101976129349e-04, -3.025873251644328e-04, -3.388240914776559e-04, -3.987358176930602e-04, -5.041484917454350e-04, -7.071419339628636e-04, -1.152174048894064e-03, -2.317257819932321e-03, -6.042188565738821e-03, -1.907464154223198e-02, -6.312086361568375e-02, -1.652867015244015e-02, -9.755515855132048e-03, -4.331750370687094e-02, -3.050871925877205e-01, -1.560481640749792e+00, -4.213821870636773e+00, -6.327744928676300e+00, -6.286987839382386e+00, -6.283233114901080e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_erf_gws_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_erf_gws", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.670520227425991e-09, 3.089165133989789e-09, 3.808334377613478e-09, 5.144384353445238e-09, 7.923753284120833e-09, 1.473330937537198e-08, 3.585835931903576e-08, 1.274551113630956e-07, 7.463115187968474e-07, 7.642446658718171e-06, 1.682646581183183e-04, -3.943125318606650e-04, -8.762789863364703e-03, -7.938249945166464e-03, 1.246947036225513e-01, 4.634955811738592e+00, 5.219443926587518e+01, 1.851009623066359e+02, 6.024280807007730e+02, 7.065606153772675e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_erf_gws_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_erf_gws", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.620126675429974e-14, -1.169484999239460e-13, -1.548387261618673e-13, -2.317078358073649e-13, -4.131920850515741e-13, -9.465206113328494e-13, -3.096241848335550e-12, -1.674836523957294e-11, -1.816485578371304e-10, -5.017487759916924e-09, -7.057130212056767e-07, -3.984021179247160e-04, -2.521853928162748e-03, -1.558560290151379e-02, -4.796029614216922e-01, -5.130625135750058e+01, -2.010384025029331e+03, -1.351721757783827e+03, -6.573048171104820e+02, -2.058007888805856e+03]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
