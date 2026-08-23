
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_epc17_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.759541560504464e-03, -1.871602570027789e-03, -2.045326320249888e-03, -2.323648245241131e-03, -2.791209966496387e-03, -3.632484570898208e-03, -5.305222492671791e-03, -9.159083343169791e-03, -2.024384613033630e-02, -6.387565843806819e-02, -1.568783649537646e-01, -5.726438687523577e-02, -3.442074580235388e-02, -1.729365736098224e-02, -4.861387786761304e-03, -7.088057310179335e-04, -4.335702807968837e-05, -7.712613713019134e-07, -2.379262949863836e-09, -7.000105399321222e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_epc17_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.453555060428453e-05, 1.453590446291186e-05, 1.642253560930747e-05, 1.642338878516519e-05, 1.956921959064152e-05, 1.957141899660646e-05, 2.516714677702079e-05, 2.517338835217636e-05, 3.609470162461234e-05, 3.611503094122645e-05, 6.046027877164349e-05, 6.054092975188938e-05, 1.261195139927946e-04, 1.265433592891132e-04, 3.566424893741141e-04, 3.599520300785777e-04, 1.486034886067335e-03, 1.529726591431486e-03, 6.225633352528184e-03, 6.937647758890836e-03, -1.487145744980174e-01, -2.341264454699232e-01, -7.843708373719979e-02, -2.562592479596986e-01, -4.641414277204324e-02, -1.667208361121604e-01, -2.319049299797119e-02, -7.937843670677586e-02, -6.235852643581593e-03, -2.345000273249540e-02, -8.580010080400522e-04, -4.129010503812676e-03, -4.913946663989516e-05, -3.689563268659062e-04, -8.204080295915765e-07, -1.287554923690351e-05, -2.427757879495393e-09, -1.191110146708879e-07, -7.030188653334563e-13, -1.635862319835031e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_epc17_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.430179507922625e-07, -8.069210917955196e-08, -2.430297831675964e-07, -2.918557026749849e-07, -9.688375201232448e-08, -2.918860281635038e-07, -3.796572078450145e-07, -1.259819398636786e-07, -3.797425528173190e-07, -5.537510033984035e-07, -1.836425706544863e-07, -5.540257033572641e-07, -9.511950838347445e-07, -3.151443555886144e-07, -9.522668528589993e-07, -2.062287327369119e-06, -6.820993732448462e-07, -2.067792972821548e-06, -6.212911103961888e-06, -2.047549923684539e-06, -6.254740284943545e-06, -2.951359015329890e-05, -9.622432772168112e-06, -3.006388707856162e-05, -2.485374586798409e-04, -7.592461979557001e-05, -2.633670720663055e-04, -1.219104315748767e-03, 8.745290081325959e-04, -1.513903804132966e-03, 1.776513274408156e-01, 4.138604997382469e-02, 4.403138381359320e-01, -3.328988879502953e-03, -5.512903655085907e-01, -3.553272888380265e-02, -8.966774760697212e-03, -5.505656346154584e-01, -1.156952029671115e-01, -7.250338691067240e-03, -5.050280310832745e-01, -8.494609427309092e-02, -2.296499093577000e-03, -4.517189122057653e-01, -3.247583943913369e-02, -2.964446598902878e-04, -4.298172584537342e-01, -6.865307758908393e-03, -1.372580426416420e-05, -4.258411165776226e-01, -7.737966563570997e-04, -1.586203020416261e-07, -4.255393831085632e-01, -3.906883812487622e-05, -2.654829887344165e-10, -4.255319539691139e-01, -6.390425880831719e-07, -3.530057156843457e-14, -4.255319149182594e-01, -1.911354646757439e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
