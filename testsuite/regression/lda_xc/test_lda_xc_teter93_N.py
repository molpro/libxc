
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_teter93_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_teter93", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.281622589680986e+00, -4.197037343782188e+00, -4.078470665198248e+00, -3.914139239167056e+00, -3.690039125183681e+00, -3.391424420373649e+00, -3.006408577945631e+00, -2.532663297102270e+00, -1.987596310611316e+00, -1.422318136463796e+00, -9.487892387494281e-01, -7.308395042037251e-01, -6.460581223869502e-01, -5.242850211538458e-01, -3.672238754921328e-01, -2.165259666824707e-01, -1.028082783938627e-01, -3.617230960723434e-02, -8.291754638966841e-03, -9.708779926688155e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_teter93_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_teter93", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.677326160882584e+00, -5.677282622676174e+00, -5.564797144121817e+00, -5.564706165668672e+00, -5.407085923048925e+00, -5.406894964032267e+00, -5.188555295328864e+00, -5.188151848212939e+00, -4.890661990843740e+00, -4.889801278666882e+00, -4.493982388685636e+00, -4.492119100456644e+00, -3.983140449094983e+00, -3.979015885710029e+00, -3.356064519288302e+00, -3.346616265316763e+00, -2.638468375925616e+00, -2.615674383378890e+00, -1.904684405959974e+00, -1.845840714631191e+00, -1.308508240195346e+00, -1.155821725287328e+00, -1.023324457637314e+00, -7.612609611192248e-01, -9.019663077884033e-01, -6.625378163689324e-01, -7.292274679977436e-01, -5.492133605870355e-01, -5.064688602890449e-01, -3.860522760348508e-01, -2.943126446365053e-01, -2.291719526404486e-01, -1.372131794814058e-01, -1.134495931877116e-01, -4.763828213693501e-02, -4.320865445003668e-02, -1.092721193180359e-02, -1.060899244044046e-02, -1.291517247369093e-03, -1.281869163895383e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_teter93_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_teter93", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.035673220135786e-02, -3.838488980542224e-04, -2.035705157097670e-02, -2.119954965770785e-02, -4.074431087902550e-04, -2.120025898408869e-02, -2.247161495173264e-02, -4.438758316335935e-04, -2.247324011095954e-02, -2.443214292407089e-02, -5.018958820056281e-04, -2.443603669158904e-02, -2.754558802162459e-02, -5.984648704845819e-04, -2.755553755168020e-02, -3.270589542425982e-02, -7.696511064387215e-04, -3.273378766656891e-02, -4.179447131742707e-02, -1.101573968335518e-03, -4.188382178126378e-02, -5.922726447909220e-02, -1.832056581353184e-03, -5.957394477332075e-02, -9.673492724245469e-02, -3.748220172082122e-03, -9.850030940199464e-02, -1.882907740864172e-01, -1.005660401628382e-02, -2.011609421154100e-01, -4.046335094792570e-01, -3.568856325367670e-02, -5.271931015875745e-01, -6.630145535222530e-01, -1.029699914849887e-01, -1.251335946893701e+00, -8.593464631979756e-01, -1.499123373001489e-01, -1.675573350569065e+00, -1.334069904804672e+00, -2.615818461379607e-01, -2.477597952189481e+00, -2.845292782256404e+00, -7.188600026308039e-01, -5.216478861791629e+00, -8.916954386838947e+00, -3.247915482761118e+00, -1.602465277209857e+01, -4.599112283695332e+01, -2.531885767420565e+01, -7.624181708308296e+01, -4.665402219883454e+02, -3.619615222545405e+02, -6.924057972058458e+02, -1.207846525016289e+04, -1.129644045957403e+04, -1.642308553905613e+04, -1.102311467978316e+06, -1.089002865288927e+06, -1.422585027438696e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
