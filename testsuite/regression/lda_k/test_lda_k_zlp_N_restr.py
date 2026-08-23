
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_k_zlp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_zlp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.575233670918277e+02, 1.513493473857858e+02, 1.428970035419694e+02, 1.315732302205870e+02, 1.168659209755889e+02, 9.859324581350367e+01, 7.728306860451022e+01, 5.456883350662356e+01, 3.326913361702076e+01, 1.668797885897506e+01, 7.058239025431120e+00, 3.751018878428114e+00, 2.857996551149640e+00, 1.849863783225089e+00, 8.559225174480862e-01, 2.671206706496357e-01, 5.147122177836618e-02, 5.276835953500252e-03, 2.262860301172669e-04, 2.766784918737559e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_k_zlp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_zlp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.603852236673088e+02, 2.502116201485714e+02, 2.362808218452508e+02, 2.176119004834539e+02, 1.933546976861277e+02, 1.631999980446576e+02, 1.280060333530426e+02, 9.045647506643971e+01, 5.520253727681841e+01, 2.771983664515059e+01, 1.173589948577013e+01, 6.240300559935037e+00, 4.755569940545357e+00, 3.078917903136863e+00, 1.425135624678973e+00, 4.449344053328761e-01, 8.576011203225181e-02, 8.793773816982556e-03, 3.771333950287372e-04, 4.611291797455467e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_k_zlp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_k_zlp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.463674599829213e-01, 9.671641860835670e-01, 9.978104395789230e-01, 1.043446615111014e+00, 1.112429968147898e+00, 1.218957839961477e+00, 1.388550623908469e+00, 1.670424645565946e+00, 2.167357777521805e+00, 3.104404629434032e+00, 4.836431623616645e+00, 6.681555713230744e+00, 7.673948631547121e+00, 9.571908077558078e+00, 1.414007354151771e+01, 2.543560276880663e+01, 5.816816341155403e+01, 1.820917976562900e+02, 8.802116291138450e+02, 7.962505812017785e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
