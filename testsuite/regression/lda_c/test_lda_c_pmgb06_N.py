
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pmgb06_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pmgb06", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.651479030519082e-03, -1.679754699306149e-03, -1.721155525957561e-03, -1.782237150203203e-03, -1.873333714867532e-03, -2.011282928993264e-03, -2.224702797855212e-03, -2.564791685034704e-03, -3.128018868761769e-03, -4.094628018314686e-03, -5.621463174680674e-03, -6.761107773463809e-03, -7.389347595224263e-03, -8.653506713359200e-03, -1.117502380942506e-02, -1.567860351155740e-02, -1.684010212474387e-02, -8.220853436711318e-03, -2.295584637574311e-03, -3.268687232639716e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pmgb06_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pmgb06", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.193191434034768e-03, -1.193203401433148e-03, -1.214274046625336e-03, -1.214300071457706e-03, -1.245162616200564e-03, -1.245220461421381e-03, -1.290774501367816e-03, -1.290907186665971e-03, -1.358877479464882e-03, -1.359195970401466e-03, -1.462148080175249e-03, -1.462964341159405e-03, -1.622110116678929e-03, -1.624409742715558e-03, -1.876875365223226e-03, -1.884300899527159e-03, -2.295194540895227e-03, -2.324294855945886e-03, -2.983151043568821e-03, -3.129696520863705e-03, -3.904822916766202e-03, -4.775710774553255e-03, -4.371679824305560e-03, -7.670604967171257e-03, -4.760019501031718e-03, -8.803901229321499e-03, -5.676229551557576e-03, -9.965262246894627e-03, -7.604614458363224e-03, -1.280193405166199e-02, -1.164473579185114e-02, -1.962828540797574e-02, -1.570363158265570e-02, -3.786578321471763e-02, -8.976613041485483e-03, -2.743253667611467e-02, -2.803589382150101e-03, -8.327343284526346e-03, -4.244147289645968e-04, -1.033091566258303e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pmgb06_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pmgb06", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.652922466944738e-06, -8.370040947702810e-07, 4.653097325160427e-06, 5.035344932981317e-06, -9.122384088301532e-07, 5.035749105017552e-06, 5.640140834064624e-06, -1.032247998118722e-06, 5.641121464773344e-06, 6.637001657614472e-06, -1.232519787543523e-06, 6.639552632883833e-06, 8.380388630851744e-06, -1.589079917150951e-06, 8.387723111495134e-06, 1.169890024810932e-05, -2.285528868550176e-06, 1.172324481222532e-05, 1.882512457720678e-05, -3.838285451113652e-06, 1.892439080796310e-05, 3.695860015455364e-05, -8.014746593072489e-06, 3.750155088075091e-05, 9.503130029991036e-05, -2.258637920206025e-05, 9.951975712387476e-05, 3.364993234145198e-04, -9.304941017862770e-05, 4.000636185778909e-04, 1.379294968595469e-03, -5.562250481000985e-04, 2.803544371306812e-03, 3.316504696426508e-03, -3.354952071933519e-03, 2.388819007100470e-02, 5.527681466824051e-03, -6.673700407117394e-03, 4.731766088764011e-02, 1.448368682204460e-02, -1.882522233181473e-02, 1.066624514683597e-01, 7.483672052705154e-02, -1.274354840041113e-01, 6.037685924875466e-01, 6.962495556604557e-01, -1.706813359768352e+00, 9.759072378294313e+00, 2.997686663791191e+00, -2.272769797433539e+01, 1.681619444133077e+02, -3.881212198116617e+01, -3.650814768328577e+02, 2.280685479378121e+03, -2.372919998752674e+03, -1.144621331094915e+04, 1.100837348560886e+05, -3.301227713689348e+05, -1.008237097612435e+06, 2.235301558152225e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
