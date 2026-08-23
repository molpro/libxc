
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_rel_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rel", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.118489125863512e+00, -4.037023582436518e+00, -3.922677698138036e+00, -3.763915124142558e+00, -3.546916762866573e+00, -3.256967844112094e+00, -2.881985057728893e+00, -2.419267644918905e+00, -1.885928094055508e+00, -1.332677303175510e+00, -8.646020733714881e-01, -6.293891003902087e-01, -5.490924387405862e-01, -4.414283870571188e-01, -2.999500299144801e-01, -1.673828418657928e-01, -7.341103951205127e-02, -2.349290013170796e-02, -4.863839979816230e-03, -5.377875300821431e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_rel_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.461931317027140e+00, -5.355034543756225e+00, -5.204876021953733e+00, -4.996170133201875e+00, -4.710514387610330e+00, -4.328160911141476e+00, -3.832643874492418e+00, -3.219784228781712e+00, -2.511777859814277e+00, -1.775918882686036e+00, -1.152534219498476e+00, -8.390819025074702e-01, -7.320544878875203e-01, -5.885354579761148e-01, -3.999221659116356e-01, -2.231751750334782e-01, -9.788122172603152e-02, -3.132386145790061e-02, -6.485119925306431e-03, -7.170500400449351e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_rel_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.840174888801614e-03, -1.027014370880133e-02, -1.091948535584896e-02, -1.192115346292457e-02, -1.351402394497074e-02, -1.615976324075049e-02, -2.083660050587051e-02, -2.987001412201394e-02, -4.961805018797200e-02, -1.000904402747953e-01, -2.387945407415603e-01, -4.512708858587595e-01, -5.931320138296501e-01, -9.181410716597582e-01, -1.989374810930039e+00, -6.390009639595330e+00, -3.322312117266853e+01, -3.244131266109017e+02, -7.568573904895644e+03, -6.190863063879285e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
