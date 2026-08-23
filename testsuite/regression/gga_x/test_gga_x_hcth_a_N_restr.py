
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_hcth_a_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hcth_a", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.456890732132845e+00, -4.364750410329342e+00, -4.235776926927549e+00, -4.057419936880590e+00, -3.815073904253608e+00, -3.494145664037061e+00, -3.085031353906845e+00, -2.592772059022544e+00, -2.051975385817671e+00, -1.532507658027281e+00, -1.040612949825650e+00, -6.706241534138783e-01, -5.904659748823241e-01, -4.702084478104099e-01, -3.327452141812994e-01, -2.345790763055772e-01, -1.979376372396869e-01, -1.751949984726015e-01, -1.372172246202126e-01, -1.009748141783458e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_hcth_a_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hcth_a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.091812099916293e+00, -5.963070199867810e+00, -5.782099462014272e+00, -5.530205546258146e+00, -5.184424550454567e+00, -4.718849960564160e+00, -4.108465753946814e+00, -3.337441467912746e+00, -2.419013167382384e+00, -1.462726962482318e+00, -8.522456162648984e-01, -9.024128335443107e-01, -8.080896614183125e-01, -6.221587677873055e-01, -3.596651328664313e-01, -1.187682737256015e-01, -1.531996563687188e-02, -2.551355463014940e-02, -2.627896707570141e-02, -1.536409611088102e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hcth_a_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hcth_a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.601865089204185e-06, 1.639032054087375e-06, 1.682174587564730e-06, 1.715912308257477e-06, 1.680064281488628e-06, 1.350363037117910e-06, -1.623788681588106e-07, -6.855806161901325e-06, -3.999137769659152e-05, -2.336439359570239e-04, -1.425579944046001e-03, 6.617890109717170e-04, 7.728069871289594e-03, -1.778054752469915e-03, -7.914535232878959e-02, -1.038847567972788e+00, -1.685219988781543e+01, -4.688830964995119e+02, -4.265810172299041e+04, -2.521763116277101e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hcth_a_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hcth_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.347935591610073e-02, -1.420532885252331e-02, -1.532821397230074e-02, -1.712241891815386e-02, -2.012813168102071e-02, -2.552071150729138e-02, -3.618997467760100e-02, -6.029756385355130e-02, -1.239163706116843e-01, -3.099015734043814e-01, -7.866384845401698e-01, -7.135642108027307e-01, -7.142768593901170e-01, -1.616874675492699e+00, -5.544023606976600e+00, -2.133373082446757e+01, -1.618388561553164e+01, 1.317613005105068e+03, 6.847044406965986e+04, 2.748936069405767e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hcth_a_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hcth_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.296919067437184e-08, 2.749460395601527e-08, 3.547936884056015e-08, 5.083777193087074e-08, 8.417897713045645e-08, 1.697998282246840e-07, 4.465027862261883e-07, 1.662084973810248e-06, 9.565292917555141e-06, 9.142183392730020e-05, 1.624208091971911e-03, 1.828527761189269e-02, 2.198224332596835e-02, 2.399776556366918e-01, 3.537815517711747e+00, 9.602697179424177e+01, 7.445896311740321e+02, -3.564512614859259e+06, -2.699251193679190e+10, -8.616905301156615e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hcth_a_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hcth_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.744206367180028e-13, -4.625301086669959e-13, -6.260527657386404e-13, -9.650449552832433e-13, -1.787890809396541e-12, -4.285432706186781e-12, -1.464952201725078e-11, -8.053829165490097e-11, -8.055096475791651e-10, -1.552231852337697e-08, -1.174810210949033e-06, -1.581593593028349e-03, -1.747679515988212e-02, -8.503396556204246e-02, -1.849419431215780e+00, 1.229321849384574e+02, 1.500564596786787e+06, 5.180284099755025e+10, 6.156835521223743e+16, 2.023568685788564e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
