
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_teter93_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_teter93", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.281622589548499e+00, -4.197037343191394e+00, -4.078470662515637e+00, -3.914139226661499e+00, -3.690039064604277e+00, -3.391424109889111e+00, -3.006406848193624e+00, -2.532652388095874e+00, -1.987513753069121e+00, -1.421522538174832e+00, -9.402937679249715e-01, -6.965625750937834e-01, -6.128436804272881e-01, -4.999748059264383e-01, -3.499915245080378e-01, -2.059723133576740e-01, -9.831279735355333e-02, -3.521788076957931e-02, -8.220729906836546e-03, -9.688330433653111e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_teter93_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_teter93", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.677304391866401e+00, -5.564751655283206e+00, -5.406990445301600e+00, -5.188353579976006e+00, -4.890231674472449e+00, -4.493050947900471e+00, -3.981079298212567e+00, -3.351347504527561e+00, -2.627124964931344e+00, -1.875775191475385e+00, -1.237602695124915e+00, -9.147758287399106e-01, -8.039978618004658e-01, -6.547923823573892e-01, -4.569513676603547e-01, -2.678937755789774e-01, -1.276732018061356e-01, -4.587753747396270e-02, -1.080752699437263e-02, -1.288463268024871e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_teter93_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_teter93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.037037039130753e-02, -1.080367371103776e-02, -1.145815166262657e-02, -1.246799274522280e-02, -1.407451325036082e-02, -1.674474249063682e-02, -2.147032936584350e-02, -3.061600107560526e-02, -5.067766790800390e-02, -1.022488902564408e-01, -2.452445939379077e-01, -4.663642829270679e-01, -6.149430146222062e-01, -9.574919415346962e-01, -2.101972954978111e+00, -6.955667281767377e+00, -3.878539571916153e+01, -4.296502937289490e+02, -1.181230999264944e+04, -1.098372346715575e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
