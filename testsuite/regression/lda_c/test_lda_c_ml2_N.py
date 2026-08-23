
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ml2_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml2", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.208372193699534e-02, -4.203949793949291e-02, -4.197454334431112e-02, -4.187828276266867e-02, -4.173380715978851e-02, -4.151305995789529e-02, -4.116728436491595e-02, -4.060706396710695e-02, -3.966001321652769e-02, -3.799860948113576e-02, -3.523836433237407e-02, -3.220378183818129e-02, -3.082353590846242e-02, -2.874845361514080e-02, -2.451383705313480e-02, -1.772038630756224e-02, -9.440119719806114e-03, -3.028218446954692e-03, -4.743070474483883e-04, -3.077642588319219e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ml2_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml2", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.279959105902870e-02, -4.279954199031465e-02, -4.276848596853189e-02, -4.276838286436727e-02, -4.272276640413570e-02, -4.272254845548599e-02, -4.265493628062127e-02, -4.265447199561657e-02, -4.255295641508443e-02, -4.255195850102485e-02, -4.239670924946057e-02, -4.239454871284119e-02, -4.215081268194090e-02, -4.214616120388062e-02, -4.174885344580486e-02, -4.173947932433208e-02, -4.105557137367588e-02, -4.104371656497087e-02, -3.976837000066875e-02, -3.983274121913359e-02, -3.723696651204520e-02, -3.827875352037161e-02, -3.366920301862458e-02, -4.012790538029106e-02, -3.220625324645716e-02, -4.039545216665309e-02, -3.020570140260220e-02, -3.868678456123635e-02, -2.584497317570519e-02, -3.674099398204241e-02, -1.864219354492757e-02, -3.345031573846598e-02, -9.793708550314795e-03, -2.721261726274897e-02, -3.057298809335130e-03, -1.786716867815102e-02, -4.653534948357324e-04, -8.664167095130753e-03, -2.979516301109913e-05, -2.651294905819232e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ml2_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ml2", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.406748069602596e-05, 8.442462985437686e-06, -1.406789230981657e-05, -1.482901996062624e-05, 8.734229195860056e-06, -1.482992964072226e-05, -1.598991735215138e-05, 9.151057628493195e-06, -1.599198271092238e-05, -1.780330994542704e-05, 9.735311531632821e-06, -1.780817251874536e-05, -2.073353604760721e-05, 1.050886216331585e-05, -2.074552273882939e-05, -2.569109012234619e-05, 1.134051631290338e-05, -2.572210520885357e-05, -3.459283762501115e-05, 1.130800911518536e-05, -3.467365344704547e-05, -5.171583358275115e-05, 5.322549043463122e-06, -5.185667043010776e-05, -8.650420232418014e-05, -3.708717221750071e-05, -8.491706501083963e-05, -1.572674978089664e-04, -3.386194870832556e-04, -9.664647960795945e-05, -3.287907424415694e-04, -2.935016893893822e-03, 2.023945587773347e-03, -1.625596962098965e-05, -2.004085461642935e-02, 5.572365828495816e-02, 2.022147560161626e-04, -3.564122786919362e-02, 1.102121938492842e-01, 3.587395731564172e-04, -7.073518434539826e-02, 1.980044338562335e-01, 2.272213607420740e-03, -2.686779556319457e-01, 7.951351007472999e-01, 1.827392978611373e-02, -1.868801882603043e+00, 6.769833929262989e+00, 1.910864455880984e-01, -2.283445190963259e+01, 1.220749206271790e+02, 2.786677299728610e+00, -5.226004689516234e+02, 5.582804756815185e+03, 5.984672949523420e+01, -2.955126379400696e+04, 9.614722775766419e+05, 2.621399306818178e+03, -6.608307840299924e+06, 1.004780964788882e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
