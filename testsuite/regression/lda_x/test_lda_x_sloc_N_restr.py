
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_sloc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_sloc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.091049126888526e+00, -5.980201158272486e+00, -5.824466328699595e+00, -5.607915190220627e+00, -5.311224026845882e+00, -4.913253015937448e+00, -4.395297638503298e+00, -3.749518225295293e+00, -2.992734723123411e+00, -2.187319594955830e+00, -1.480960073848765e+00, -1.112628926357618e+00, -9.839678593016269e-01, -8.084408512997538e-01, -5.709426581654571e-01, -3.377327933809903e-01, -1.608470557501673e-01, -5.768589974028208e-02, -1.398002420484721e-02, -1.926531978641127e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_sloc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_sloc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.918363864955085e+00, -7.774261505754231e+00, -7.571806227309473e+00, -7.290289747286816e+00, -6.904591234899646e+00, -6.387228920718683e+00, -5.713886930054286e+00, -4.874373692883881e+00, -3.890555140060435e+00, -2.843515473442579e+00, -1.925248096003395e+00, -1.446417604264904e+00, -1.279158217092115e+00, -1.050973106689680e+00, -7.422254556150941e-01, -4.390526313952874e-01, -2.091011724752174e-01, -7.499166966236670e-02, -1.817403146630137e-02, -2.504491572233466e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_sloc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_sloc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.326457779522724e-02, -1.384537809266885e-02, -1.472461717128109e-02, -1.608563895488559e-02, -1.826084579809100e-02, -2.190014723104165e-02, -2.840113266261614e-02, -4.114959599530521e-02, -6.963311398273786e-02, -1.447148509019997e-01, -3.595068633327129e-01, -7.006334390958637e-01, -9.332962915991044e-01, -1.476145220918325e+00, -3.323475795942642e+00, -1.131455457765835e+01, -6.387698362539352e+01, -6.990031045197027e+02, -1.908929320828630e+04, -1.946094018510993e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
