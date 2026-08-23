
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_rpa_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpa", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.207970908700662e-01, -1.202277145116027e-01, -1.194112988314625e-01, -1.182424061725456e-01, -1.165725791484686e-01, -1.141950682773659e-01, -1.108269094717897e-01, -1.060925481717893e-01, -9.952882151922264e-02, -9.072525496663868e-02, -8.032769580897052e-02, -7.306380269472626e-02, -7.001322570678439e-02, -6.518017074658293e-02, -5.649786812305937e-02, -4.114845723640429e-02, -5.352795848955133e-04, 2.147317147407939e-01, 2.251313857853902e+00, 3.656348636015712e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_rpa_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpa", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.301049821550780e-01, -1.301049821550780e-01, -1.295206542214551e-01, -1.295206542214551e-01, -1.286824659077242e-01, -1.286824659077242e-01, -1.274817064854914e-01, -1.274817064854914e-01, -1.257649121564299e-01, -1.257649121564299e-01, -1.233175256004375e-01, -1.233175256004375e-01, -1.198441490954935e-01, -1.198441490954935e-01, -1.149491453773993e-01, -1.149491453773993e-01, -1.081377277959407e-01, -1.081377277959407e-01, -9.896054322378502e-02, -9.896054322378502e-02, -8.809553912890597e-02, -8.809553912890597e-02, -8.055336589092138e-02, -8.055336589092138e-02, -7.742358973522984e-02, -7.742358973522984e-02, -7.254895298102959e-02, -7.254895298102959e-02, -6.422318603632009e-02, -6.422318603632009e-02, -5.157202099990489e-02, -5.157202099990489e-02, -2.646379685044773e-02, -2.646379685044773e-02, 8.907547644786006e-02, 8.907547644786006e-02, 1.239035108992052e+00, 1.239035108992052e+00, 2.186340579631004e+01, 2.186340579631004e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_rpa_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpa", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.333037602059662e-05, -5.333037602059662e-05, -5.333037602059662e-05, -5.662465350918834e-05, -5.662465350918834e-05, -5.662465350918834e-05, -6.171498082328027e-05, -6.171498082328027e-05, -6.171498082328027e-05, -6.982999356583284e-05, -6.982999356583284e-05, -6.982999356583284e-05, -8.335889362494433e-05, -8.335889362494433e-05, -8.335889362494433e-05, -1.074047978566020e-04, -1.074047978566020e-04, -1.074047978566020e-04, -1.542343619512917e-04, -1.542343619512917e-04, -1.542343619512917e-04, -2.580802359978306e-04, -2.580802359978306e-04, -2.580802359978306e-04, -5.341014764291253e-04, -5.341014764291253e-04, -5.341014764291253e-04, -1.459327015481266e-03, -1.459327015481266e-03, -1.459327015481266e-03, -5.044554010825627e-03, -5.044554010825627e-03, -5.044554010825627e-03, -1.246635858672292e-02, -1.246635858672292e-02, -1.246635858672292e-02, -1.839013285215405e-02, -1.839013285215405e-02, -1.839013285215405e-02, -3.431920726032620e-02, -3.431920726032620e-02, -3.431920726032620e-02, -1.056499651001614e-01, -1.056499651001614e-01, -1.056499651001614e-01, -6.586408373660205e-01, -6.586408373660205e-01, -6.586408373660205e-01, -1.476520405364399e+01, -1.476520405364399e+01, -1.476520405364399e+01, -2.104205109039626e+03, -2.104205109039626e+03, -2.104205109039626e+03, -2.045087073295461e+06, -2.045087073295461e+06, -2.045087073295461e+06, -2.318579180157438e+10, -2.318579180157438e+10, -2.318579180157438e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
