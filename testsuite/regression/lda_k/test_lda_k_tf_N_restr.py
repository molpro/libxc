
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_k_tf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_tf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.122434915595863e+01, 8.757610812628059e+01, 8.258853147954189e+01, 7.591957002158917e+01, 6.728126478215972e+01, 5.658826640046536e+01, 4.417874884220092e+01, 3.103498846443316e+01, 1.880528543469980e+01, 9.369385053774051e+00, 3.938544611538910e+00, 2.086177785517952e+00, 1.587641982204467e+00, 1.025945844494968e+00, 4.736362941382513e-01, 1.474808073575547e-01, 2.836770073559879e-02, 2.905173251986283e-03, 1.245251411194332e-04, 1.522368990539936e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_k_tf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_tf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.520405819265977e+02, 1.459601802104676e+02, 1.376475524659031e+02, 1.265326167026486e+02, 1.121354413035995e+02, 9.431377733410893e+01, 7.363124807033486e+01, 5.172498077405527e+01, 3.134214239116633e+01, 1.561564175629009e+01, 6.564241019231517e+00, 3.476962975863254e+00, 2.646069970340778e+00, 1.709909740824946e+00, 7.893938235637521e-01, 2.458013455959245e-01, 4.727950122599799e-02, 4.841955419977137e-03, 2.075419018657219e-04, 2.537281650899892e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_k_tf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_tf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.659850840659089e-01, 5.776536902478997e-01, 5.948404599843329e-01, 6.204167335669472e-01, 6.590423136921031e-01, 7.186164889589147e-01, 8.133054201141230e-01, 9.703637822455721e-01, 1.246580726353837e+00, 1.766057457636843e+00, 2.723908332625606e+00, 3.742697391288273e+00, 4.290264674989531e+00, 5.337011693795715e+00, 7.854849811568326e+00, 1.407643306487551e+01, 3.209580733766339e+01, 1.002938618456087e+02, 4.844309157475286e+02, 4.381273938069894e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
