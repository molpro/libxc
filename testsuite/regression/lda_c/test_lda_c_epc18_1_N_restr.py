
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_epc18_1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.921528129418801e-03, -3.106843013358697e-03, -3.393951165718702e-03, -3.853473732312194e-03, -4.624185675074378e-03, -6.006942922593881e-03, -8.741109316519750e-03, -1.496274317727468e-02, -3.224564696944440e-02, -9.141346326937247e-02, -1.676106430198419e-01, -8.917001327729859e-02, -5.987924981690688e-02, -3.075095329838931e-02, -9.434509355899953e-03, -1.620977920192189e-03, -1.364254837857581e-04, -4.470187943356358e-06, -3.966890501897126e-08, -5.362218604347009e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_epc18_1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.297021410818073e-05, 1.461882162430157e-05, 1.735502820825604e-05, 2.218613856195050e-05, 3.149841882568946e-05, 5.179479864853236e-05, 1.040215361408160e-04, 2.674923489351090e-04, 7.703706760099678e-04, -7.043300969260632e-03, -2.068559979154974e-01, -1.721520294139378e-01, -1.198341205814401e-01, -6.223931046740878e-02, -1.898853471347315e-02, -3.246042492587695e-03, -2.728806764449002e-04, -8.940407856371449e-06, -7.933781255573604e-08, -1.072443720915407e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_epc18_1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.416592428783021e-07, -1.694851938248322e-07, -2.191786955905591e-07, -3.166624582452531e-07, -5.352196623339592e-07, -1.126274967822703e-06, -3.185940288844506e-06, -1.277073865886982e-05, -4.082355946337582e-05, 5.668594424884590e-03, 9.643895428791807e-02, -2.188432607104850e-01, -2.782273877253029e-01, -2.982858686857586e-01, -2.884726237044068e-01, -2.798840230525397e-01, -2.779592892347139e-01, -2.777837376105971e-01, -2.777778306696183e-01, -2.777777778492740e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
