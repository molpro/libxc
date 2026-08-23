
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vwn_3_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_3", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.185824110986134e-01, -1.179948578930092e-01, -1.171517400884268e-01, -1.159432736542591e-01, -1.142140701865407e-01, -1.117459499694952e-01, -1.082363244257652e-01, -1.032743310696884e-01, -9.632891052950822e-02, -8.682106483109575e-02, -7.434616643456328e-02, -6.100826779723308e-02, -5.711942832624657e-02, -5.291812493553102e-02, -4.441377641117756e-02, -3.250991125159656e-02, -1.927980738106131e-02, -8.240949259245138e-03, -2.181240179828684e-03, -3.313041002879219e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vwn_3_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_3", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.281835920525961e-01, -1.281854019755253e-01, -1.275855069093995e-01, -1.275893522590389e-01, -1.267263321959475e-01, -1.267345980304644e-01, -1.254927107150795e-01, -1.255107816514230e-01, -1.237224688298829e-01, -1.237629568555662e-01, -1.211832239357818e-01, -1.212772347630170e-01, -1.175388009464111e-01, -1.177687790347920e-01, -1.122863529985983e-01, -1.128935822192900e-01, -1.045983040728727e-01, -1.063884210548424e-01, -9.282226580740768e-02, -9.891806736010118e-02, -7.402598591359059e-02, -9.641769996070539e-02, -5.595169739077171e-02, -1.092095254789684e-01, -5.228311574580387e-02, -1.074215132739092e-01, -4.886367136287548e-02, -9.764318664741981e-02, -4.131610037807217e-02, -8.646468920430903e-02, -3.072060252799195e-02, -7.202498634986738e-02, -1.907950048439958e-02, -5.252850182310755e-02, -9.066450042855700e-03, -2.771000881004220e-02, -2.809353168677804e-03, -3.815898824055323e-03, -4.227483620328420e-04, -3.501765360262112e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vwn_3_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_3", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.606592519423885e-04, -4.696289735067737e-04, 3.606780093220702e-04, 3.815191300618701e-04, -4.972862769962942e-04, 3.815614846451665e-04, 4.135936641310632e-04, -5.398825238800160e-04, 4.136930338266715e-04, 4.643611479591984e-04, -6.074706896527029e-04, 4.646074745033092e-04, 5.481081494806202e-04, -7.193920109341797e-04, 5.487690379752899e-04, 6.946244648257222e-04, -9.164054784092456e-04, 6.966110797173007e-04, 9.731020700612370e-04, -1.294835724191198e-03, 9.801323122119962e-04, 1.566442175656208e-03, -2.117722572204796e-03, 1.597867746545219e-03, 3.029360115991906e-03, -4.245100996393356e-03, 3.224807890730065e-03, 7.099762319278016e-03, -1.109966814114091e-02, 8.979489898369308e-03, 1.505094756103732e-02, -3.620454846844366e-02, 4.079732356525598e-02, 1.590231567905240e-02, -9.560220511095271e-02, 2.263083109115138e-01, 2.039978145997419e-02, -1.412802952320505e-01, 3.651775669512080e-01, 3.649612854310899e-02, -2.485041379206466e-01, 5.984632775861974e-01, 8.277923491942142e-02, -7.006370439069292e-01, 1.789398457166501e+00, 2.084024304777916e-01, -3.299685868163797e+00, 1.010034548503076e+01, -3.243023176819452e-01, -2.670930602331470e+01, 1.096698403941680e+02, -4.103223206737535e+01, -3.695470258460051e+02, 1.918159245107641e+03, -2.407064948394371e+03, -9.680677502918754e+03, -1.696526264954259e+05, -3.211405040091268e+05, -4.815949521181340e+06, 1.246691433591317e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
