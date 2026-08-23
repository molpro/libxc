
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_1d_css_HO1D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_css", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.791422133094030e-03, -5.791471284548830e-03, -5.791600612906568e-03, -5.791940475012785e-03, -5.792831802805128e-03, -5.795162010288206e-03, -5.801224109731580e-03, -5.816879680444803e-03, -5.856894772283120e-03, -5.957842721065238e-03, -6.209241529139260e-03, -6.832899034723736e-03, -8.417711539408401e-03, -1.278156534078937e-02, -2.706503645927265e-02, -6.831981466407734e-02, -3.643656479231356e-02, -3.040819615310688e-03, -2.435613989735931e-05, -4.681346314546483e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_1d_css_HO1D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_css", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.850805383878618e-03, 3.850828247787375e-03, 3.850888407157410e-03, 3.851046495632398e-03, 3.851461070804192e-03, 3.852544692478611e-03, 3.855362365318764e-03, 3.862629755173579e-03, 3.881143856475521e-03, 3.927461925335903e-03, 4.040424271015218e-03, 4.306404036442869e-03, 4.898215093566046e-03, 6.049066452140677e-03, 8.237973899866042e-03, -4.908114661710397e-02, -5.990105283371664e-02, -5.594137127072804e-03, -4.659127697145390e-05, -9.135682356882242e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_1d_css_HO1D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO1D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_1d_css", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.975017403622167e-03, -3.975044243833725e-03, -3.975114865065326e-03, -3.975300441637940e-03, -3.975787075615270e-03, -3.977058862984257e-03, -3.980364573280281e-03, -3.988882426049540e-03, -4.010527518351193e-03, -4.064324741621835e-03, -4.193255607249132e-03, -4.482030293204187e-03, -5.026027466289868e-03, -5.664140618799227e-03, -9.436577879272476e-03, 6.908773854264441e-01, -1.471818880853309e+00, -5.131874439340500e+00, -1.112093463213652e+01, -2.130769664973931e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
