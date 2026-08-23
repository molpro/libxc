
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_absp4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.957912502274731e+01, 4.799425522745656e+01, 4.582540450355996e+01, 4.292129281026220e+01, 3.915190904044217e+01, 3.447179464998961e+01, 2.901373038739627e+01, 2.317490460268636e+01, 1.756843589398920e+01, 1.249165774716038e+01, 6.386421371780196e+00, 1.299052114887335e+00, 8.123944648500271e-01, 6.932458811568425e-01, 5.215059038349097e-01, 3.856984710651755e-01, 3.141030355350307e-01, 2.784008755679809e-01, 2.585380117106327e-01, 2.462408636611534e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_absp4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.473688316016709e+01, 5.214995074885058e+01, 4.861545482124494e+01, 4.389353854661505e+01, 3.778492890370845e+01, 3.023748653979354e+01, 2.150513621317655e+01, 1.231393297814059e+01, 3.935606912985982e+00, -1.777666833753802e+00, -1.882653948636788e+00, 1.086514249341313e+00, 1.003090935040730e+00, 4.799340439374603e-01, 2.010220838721869e-02, -2.170526078775772e-01, -2.816642696852893e-01, -2.750787792249434e-01, -2.583956158946013e-01, -2.462391228161099e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_absp4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.993079061462737e-04, 3.182041850204811e-04, 3.474599343257774e-04, 3.942336940630189e-04, 4.725449526380672e-04, 6.126250698306268e-04, 8.881048271483517e-04, 1.508366806567291e-03, 3.197896874412852e-03, 9.093220405196589e-03, 3.336419843665532e-02, 8.654806733534839e-02, 1.303633425554996e-01, 2.509560638465776e-01, 8.000495540733951e-01, 4.604485286105099e+00, 5.458183648617075e+01, 1.665429655602464e+03, 1.876716988040674e+05, 1.388367553066988e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_absp4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.595256128901039e-01, 3.716619202628888e-01, 3.900381155985679e-01, 4.185211622872573e-01, 4.642241356508812e-01, 5.414418055989382e-01, 6.824200302195832e-01, 9.714014808163425e-01, 1.668621035194394e+00, 3.632395970416860e+00, 7.015914593899016e+00, 2.911060730528555e+00, 2.479792846788911e+00, 4.660448702869774e+00, 1.287307571829717e+01, 6.143501775588933e+01, 6.286783188881432e+02, 1.726556662933842e+04, 1.810222048947373e+06, 1.275594382922327e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_absp4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.671301914349171e-06, -1.888992821169018e-06, -2.252309141620981e-06, -2.899519354453011e-06, -4.165861149111833e-06, -7.001773587706995e-06, -1.471455031278242e-05, -4.244557941436117e-05, -1.907864126879438e-04, -1.542602279288095e-03, -2.076729461945149e-02, -1.397440358521335e-01, -3.170512777903167e-01, -1.174935216228393e+00, -1.194131921508100e+01, -3.955311682952230e+02, -5.557952376513267e+04, -5.174532517485320e+07, -6.570767548210774e+11, -3.596064261070634e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_absp4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_absp4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
