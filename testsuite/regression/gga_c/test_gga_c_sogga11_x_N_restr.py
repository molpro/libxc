
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_sogga11_x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11_x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.121905580784947e-01, -1.121005324051750e-01, -1.119146217699040e-01, -1.115322135329073e-01, -1.107661716495967e-01, -1.093636356990395e-01, -1.075270784564634e-01, -1.088959868811536e-01, -1.290663343858112e-01, -1.813331720704254e-01, -1.542173199697595e-01, -5.469336123314008e-02, -5.542084955914518e-02, -4.794781411252071e-02, -4.775812284151915e-02, -4.912687618533192e-02, -9.774014811151310e-02, -4.597581052455709e-02, -1.218393310519190e-02, -1.642158508764400e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_sogga11_x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11_x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.126985958202012e-02, -7.426988395069666e-02, -7.861934475524264e-02, -8.463964318704961e-02, -9.179700825613293e-02, -9.568739465231006e-02, -7.840439614176903e-02, 1.093894197460761e-02, 2.271612545781491e-01, 3.751984163904193e-01, 3.247566152736359e-01, -5.407533641766635e-02, -7.610222498318694e-02, -4.670662799061501e-02, -3.214278411233017e-02, 7.439954772430106e-02, -4.653214040998742e-02, -6.456345556816816e-02, -1.586003643283209e-02, -2.160603246229732e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sogga11_x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11_x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.933607636665487e-07, -5.933421722286305e-07, -5.874894517544180e-07, -5.691575140251763e-07, -5.367451118892416e-07, -5.715189122439945e-07, -1.404309604684677e-06, -8.180747032467152e-06, -5.105553789015861e-05, -2.533634746033079e-04, -1.441337441829535e-03, -6.263080360372338e-04, 5.577714527392094e-03, -2.999279070224001e-03, -2.270995881483847e-02, -7.524168505326199e-01, -5.028234896074104e+00, 1.749585829547449e+01, 5.710158288157023e+01, 9.692815181730946e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sogga11_x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11_x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.862858227550429e-03, 2.025686717906903e-03, 2.220091574840787e-03, 2.367323149691347e-03, 2.116486489920453e-03, 6.248592772820130e-05, -9.177277954684078e-03, -4.307330454942632e-02, -1.194988188566639e-01, -4.101484574365008e-02, -1.941546761703126e-01, -2.558629530127001e-01, -3.954020436662412e-02, -6.653253509891689e-01, 2.179826867429346e+00, -7.349388854928429e+01, 5.647352917936647e+02, -1.062654552122261e+03, -1.828699100230320e+04, -1.757937083625819e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sogga11_x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11_x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.242444961294316e-08, -2.598164547562600e-08, -3.120920302534900e-08, -3.801345325326292e-08, -4.136545240050039e-08, -3.713631870995121e-09, 3.305168924967472e-07, 2.718780231047387e-06, 1.673239400303529e-05, 2.091377577840997e-05, 6.290435725839919e-04, 2.146548428570619e-02, 7.255691359282546e-03, 2.570346568750242e-01, -2.275850287134933e+00, 4.264749488438243e+02, -4.095496641954577e+04, 1.392309087299791e+06, 7.678931948286139e+08, 9.949962755379938e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_sogga11_x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_sogga11_x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.180268533848801e-13, 3.871278012735853e-13, 5.013536415212546e-13, 6.861388866731341e-13, 9.047197259100220e-13, 3.082900938659243e-13, -1.091112110728324e-11, -1.521029129194991e-10, -1.755350918637078e-09, 1.603346131002074e-08, 1.647213575407355e-06, -1.754639989656072e-03, -1.021894903835180e-02, -9.586190392902190e-02, 2.769687980810553e+00, -1.947375620130407e+03, 3.415169510551541e+06, -4.941292337593294e+09, -2.868683997684899e+14, -2.830534990806225e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
