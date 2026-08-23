
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_gl_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gl", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.439021690062489e-01, -1.432323786645081e-01, -1.422704297828803e-01, -1.408899211129790e-01, -1.389109469079834e-01, -1.360787750147871e-01, -1.320355348393846e-01, -1.262852761970385e-01, -1.181647964375505e-01, -1.069057850266657e-01, -9.204123002091925e-02, -7.698867784942556e-02, -7.241906856575514e-02, -6.698363893811486e-02, -5.636737056025285e-02, -4.144508114967650e-02, -2.458977713092441e-02, -1.023267324683002e-02, -2.459616890639754e-03, -2.832699009133918e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_gl_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gl", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.548433623808988e-01, -1.548454231371752e-01, -1.541692224119244e-01, -1.541735969822450e-01, -1.532000666889586e-01, -1.532094585804221e-01, -1.518070244730602e-01, -1.518275204635147e-01, -1.498048790214185e-01, -1.498506797407138e-01, -1.469264867446184e-01, -1.470324196467619e-01, -1.427819720966557e-01, -1.430396039435745e-01, -1.367825759354074e-01, -1.374567702746187e-01, -1.279580709862986e-01, -1.299180007219944e-01, -1.144342711534203e-01, -1.209608434875597e-01, -9.326979413033527e-02, -1.164153781780713e-01, -7.428268579015361e-02, -1.250964481573791e-01, -7.022502872100557e-02, -1.214964191367734e-01, -6.571381583722657e-02, -1.104263547249143e-01, -5.644690034999245e-02, -9.556016592636367e-02, -4.312776702026726e-02, -7.502467304544466e-02, -2.736170612677508e-02, -4.848524291611819e-02, -1.242286904657872e-02, -2.160801934299915e-02, -3.187343873948628e-03, -5.400364903860255e-03, -3.758381433512022e-04, -6.480732013745753e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_gl_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_gl", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.112843560976100e-04, -5.340718965616420e-04, 4.113053968293575e-04, 4.346130192250594e-04, -5.651393561221572e-04, 4.346604827040899e-04, 4.704270465888576e-04, -6.129423244920931e-04, 4.705382425220456e-04, 5.269825642859665e-04, -6.886873771767828e-04, 5.272576290475293e-04, 6.199600206261636e-04, -8.138629111608051e-04, 6.206957418863877e-04, 7.817992104537211e-04, -1.033553605017196e-03, 7.840006879674392e-04, 1.087032768619330e-03, -1.453682774578159e-03, 1.094770079683688e-03, 1.729605389124062e-03, -2.361181456671025e-03, 1.763830277930249e-03, 3.283345799618290e-03, -4.683482423572624e-03, 3.492726433393425e-03, 7.461852979694787e-03, -1.204876480458374e-02, 9.423097344218870e-03, 1.483492565688659e-02, -3.818523653392528e-02, 4.042456917235230e-02, 9.564007242808602e-03, -8.449290121526415e-02, 1.721900107991275e-01, 1.001075415899451e-02, -1.203540266891763e-01, 2.615150754225654e-01, 1.722738201082255e-02, -2.148417542252921e-01, 4.297258229220223e-01, 1.899698198737634e-02, -5.835367543608011e-01, 1.173051252337599e+00, -1.474699670560127e-01, -2.544133992561656e+00, 5.477438989253219e+00, -3.532574588594418e+00, -1.893510208944192e+01, 4.593449681373164e+01, -8.742911565866750e+01, -2.563240187472702e+02, 7.993952516129195e+02, -3.373024561236329e+03, -7.090551882545111e+03, 4.141036151391636e+04, -3.203050486549818e+05, -6.036585076358084e+05, 1.005884765509736e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
