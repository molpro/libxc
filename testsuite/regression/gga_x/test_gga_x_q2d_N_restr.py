
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_q2d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q2d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.243233070579578e+00, -4.160533880234111e+00, -4.044711635054661e+00, -3.884393646621826e+00, -3.666202811223756e+00, -3.376361821110301e+00, -3.004461279501959e+00, -2.550116225228630e+00, -2.030781596305209e+00, -1.478366777858793e+00, -9.635544639822177e-01, -6.496031226443169e-01, -5.569110536552880e-01, -4.591072642654017e-01, -3.274840821487854e-01, -1.677602361358317e-01, -1.609650260569814e-02, -3.323487299368187e-03, -3.427503634411881e-04, -1.285905401985998e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_q2d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q2d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.450324735170266e+00, -5.336767317028750e+00, -5.177581182658639e+00, -4.956944795665422e+00, -4.656081304815193e+00, -4.255358889933835e+00, -3.739661898015377e+00, -3.110014033841021e+00, -2.411340596474179e+00, -1.812892115788357e+00, -1.311632026845695e+00, -8.157274274588324e-01, -7.224152591966843e-01, -5.687923830576587e-01, -3.878905369169186e-01, -4.188620428639216e-01, -4.273648506549309e-02, -6.125518006002696e-03, -6.797902670250433e-04, -2.570968635711646e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_q2d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q2d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.224496909647049e-06, -2.407191793398954e-06, -2.695642763852868e-06, -3.169716763359896e-06, -3.994421950912775e-06, -5.547780968014026e-06, -8.807477906426983e-06, -1.663336561103928e-05, -3.739398163410927e-05, -6.368631003525328e-05, 7.162744476305102e-05, -4.045062933379980e-03, -7.479572274360444e-03, -1.610584071714488e-02, -4.593984396226908e-02, 1.045154961820889e+00, 1.442181456553980e+00, 3.817682372778586e+00, 6.065835469218693e+01, 1.810788205230028e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_q2d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q2d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.147890867166562e-02, -1.199054744118204e-02, -1.276567912209226e-02, -1.396613740340764e-02, -1.588284510831730e-02, -1.906852534954796e-02, -2.460204873816547e-02, -3.418352850117261e-02, -4.221342659502451e-02, 1.143056782689687e-01, 9.176302145318804e-01, -5.189716473924707e-01, -6.449063311392357e-01, -1.058594750288171e+00, -5.320098420535064e-01, 7.240988141855316e+01, -1.876285699182455e+02, -1.311827170171347e+02, -2.300985974394926e+03, -6.650465882950756e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_q2d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q2d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.431614438913832e-08, 1.634565020205547e-08, 1.975455883049720e-08, 2.586658428118859e-08, 3.785566162304313e-08, 6.430783515761876e-08, 1.305987337632307e-07, 2.873022789847034e-07, -7.242481417821785e-07, -8.725002510913200e-05, -3.168888257671094e-03, 6.414322105959056e-03, 2.201364534032409e-02, 6.350492578683382e-02, -1.317129340752702e+00, -4.519619378470103e+02, 1.173585947081204e+04, 1.526491184358952e+05, 4.104767817857937e+08, 9.368141297634715e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_q2d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_q2d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.409534274662266e-14, 3.094905526859064e-14, 4.435519967007461e-14, 7.440603033053059e-14, 1.564876061014395e-13, 4.554689152421592e-13, 2.115820574452110e-12, 1.930732428726809e-11, 4.666942807572226e-10, 4.090675579882617e-08, 8.281842681272107e-06, 1.840865507096597e-04, 8.324451626824264e-04, 1.375940775634455e-02, 2.102539044990741e+00, 1.779152407225560e+03, -9.283005208229180e+05, -7.003605691268256e+08, -1.888571815420518e+14, -3.302979690250732e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
