
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_k_lp_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.431844964255870e+01, 9.054646947926858e+01, 8.538972689311574e+01, 7.849457155665186e+01, 6.956327912301188e+01, 5.850761250820555e+01, 4.567725229591409e+01, 3.208799745143981e+01, 1.944538067490298e+01, 9.702918862458457e+00, 4.184943122454992e+00, 2.499013622700091e+00, 1.935807823653328e+00, 1.239729193396207e+00, 5.824371427283297e-01, 1.895878884884408e-01, 3.911327232887544e-02, 4.345360833728092e-03, 1.979177366492363e-04, 2.481063068743360e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_k_lp_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.571986916631953e+02, 1.571961404476135e+02, 1.509133956783849e+02, 1.509081691167500e+02, 1.423215425808203e+02, 1.423108797970649e+02, 1.308350982663329e+02, 1.308134709076606e+02, 1.159605526963418e+02, 1.159170321279522e+02, 9.755598873534790e+01, 9.746932853034549e+01, 7.621374888246388e+01, 7.604347313076788e+01, 5.364389595307594e+01, 5.331457460455149e+01, 3.271742439438077e+01, 3.209144209130389e+01, 1.672236790352765e+01, 1.555769680276173e+01, 7.762085108830383e+00, 5.735620933105233e+00, 4.775934254494614e+00, 2.169133427229279e+00, 3.686922148233787e+00, 1.571945929384859e+00, 2.365575835636220e+00, 1.041538116874681e+00, 1.107121168137318e+00, 4.578224854937943e-01, 3.557082005708078e-01, 1.247924806773727e-01, 7.139123132750252e-02, 1.861866438080403e-02, 7.626212655331387e-03, 1.216610807774904e-03, 3.360751398387744e-04, 2.507679444514772e-05, 4.152404205725744e-06, 1.097605924248462e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_k_lp_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_lp", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.170359000611005e+00, 3.862796856653209e-131, 1.170368497746226e+00, 1.194482158879280e+00, 3.862796856653209e-131, 1.194502843579808e+00, 1.230008865913244e+00, 0.000000000000000e+00, 1.230054944866986e+00, 1.282866400013104e+00, 1.287598952217736e-131, 1.282972443621973e+00, 1.362662877217538e+00, -1.287598952217736e-131, 1.362918656271525e+00, 1.485650301940218e+00, -2.575197904435473e-131, 1.486310602760606e+00, 1.680842035578743e+00, 6.437994761088682e-131, 1.682722845270296e+00, 2.003472599821655e+00, 5.150395808870946e-131, 2.009650746899107e+00, 2.565393613578088e+00, 0.000000000000000e+00, 2.590293324340425e+00, 3.588349003626890e+00, 5.150395808870946e-131, 3.720239599855156e+00, 5.266891390993386e+00, 5.150395808870946e-131, 6.127077059564783e+00, 6.714511054392384e+00, -5.150395808870946e-131, 9.963236271986784e+00, 7.642079993368137e+00, -1.030079161774189e-130, 1.170374258604286e+01, 9.540587641211570e+00, 0.000000000000000e+00, 1.437824828666981e+01, 1.394588198462317e+01, 4.120316647096757e-130, 2.168677649318185e+01, 2.460348479537273e+01, -4.120316647096757e-130, 4.153836077884837e+01, 5.491881107374561e+01, 0.000000000000000e+00, 1.075398190238541e+02, 1.680308821214652e+02, -3.296253317677405e-129, 4.206953656551340e+02, 8.004337071806566e+02, 2.637002654141924e-128, 2.930269420747477e+03, 7.201015601855755e+03, 4.219204246627079e-127, 4.429149522566688e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
