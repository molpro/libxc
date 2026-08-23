
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_hl_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_hl", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.108298367024687e-01, -1.103742924438904e-01, -1.097199361406300e-01, -1.087806329130307e-01, -1.074336475712103e-01, -1.055048835626541e-01, -1.027490449196966e-01, -9.882465167375916e-02, -9.327329017029473e-02, -8.559360809890068e-02, -7.613186181894314e-02, -6.928408594521167e-02, -6.637186384769740e-02, -6.176178880435187e-02, -5.377392192128989e-02, -4.229427863512925e-02, -2.788185302446941e-02, -1.315649657610255e-02, -3.462932373936784e-03, -4.119140534627789e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_hl_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_hl", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.182714787749142e-01, -1.182714787749142e-01, -1.178147437320752e-01, -1.178147437320752e-01, -1.171586344034284e-01, -1.171586344034284e-01, -1.162167243900338e-01, -1.162167243900338e-01, -1.148658066749971e-01, -1.148658066749971e-01, -1.129309879643007e-01, -1.129309879643007e-01, -1.101655515932456e-01, -1.101655515932456e-01, -1.062253079456563e-01, -1.062253079456563e-01, -1.006462764151432e-01, -1.006462764151432e-01, -9.291524782149693e-02, -9.291524782149693e-02, -8.336108733422577e-02, -8.336108733422577e-02, -7.641805010677505e-02, -7.641805010677505e-02, -7.345584871046849e-02, -7.345584871046849e-02, -6.875248184360055e-02, -6.875248184360055e-02, -6.055140745709283e-02, -6.055140745709283e-02, -4.860255969503910e-02, -4.860255969503910e-02, -3.315540560356092e-02, -3.315540560356092e-02, -1.644360446403879e-02, -1.644360446403879e-02, -4.528190802396591e-03, -4.528190802396591e-03, -5.478882169759834e-04, -5.478882169759834e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_hl_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_hl", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.166082659211178e-05, -4.166082659211178e-05, -4.166082659211178e-05, -4.428624966699449e-05, -4.428624966699449e-05, -4.428624966699449e-05, -4.835028168583709e-05, -4.835028168583709e-05, -4.835028168583709e-05, -5.484609835646235e-05, -5.484609835646235e-05, -5.484609835646235e-05, -6.571745154784127e-05, -6.571745154784127e-05, -6.571745154784127e-05, -8.515189107905073e-05, -8.515189107905073e-05, -8.515189107905073e-05, -1.233348084227981e-04, -1.233348084227981e-04, -1.233348084227981e-04, -2.091712442262456e-04, -2.091712442262456e-04, -2.091712442262456e-04, -4.423438325917311e-04, -4.423438325917311e-04, -4.423438325917311e-04, -1.251851905004072e-03, -1.251851905004072e-03, -1.251851905004072e-03, -4.553469781265818e-03, -4.553469781265818e-03, -4.553469781265818e-03, -1.170418710717803e-02, -1.170418710717803e-02, -1.170418710717803e-02, -1.754350403771024e-02, -1.754350403771024e-02, -1.754350403771024e-02, -3.346021736127051e-02, -3.346021736127051e-02, -3.346021736127051e-02, -1.043530553189551e-01, -1.043530553189551e-01, -1.043530553189551e-01, -5.699687191693690e-01, -5.699687191693690e-01, -5.699687191693690e-01, -5.887392683536135e+00, -5.887392683536135e+00, -5.887392683536135e+00, -1.208219676996783e+02, -1.208219676996783e+02, -1.208219676996783e+02, -4.786873368464970e+03, -4.786873368464970e+03, -4.786873368464970e+03, -4.673225751061625e+05, -4.673225751061625e+05, -4.673225751061625e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
