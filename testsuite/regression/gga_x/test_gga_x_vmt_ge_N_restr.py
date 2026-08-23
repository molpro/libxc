
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_vmt_ge_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_ge", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.243836515827398e+00, -4.161185186322227e+00, -4.045438022889462e+00, -3.885242425995774e+00, -3.667262517507834e+00, -3.377815718023341e+00, -3.006744620434842e+00, -2.554474752136296e+00, -2.041727112142575e+00, -1.514073521423001e+00, -1.012393096162813e+00, -6.499365374087399e-01, -5.569461372519164e-01, -4.595309792496680e-01, -3.311308036970971e-01, -2.130562084782637e-01, -1.198737259205283e-01, -4.149496287502621e-02, -4.917157025465467e-03, -5.377875301790263e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_vmt_ge_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_ge", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.447118788938874e+00, -5.333316956936937e+00, -5.173747059865918e+00, -4.952483995455935e+00, -4.650536688130888e+00, -4.247774426609125e+00, -3.727724471612341e+00, -3.086884557029952e+00, -2.350937735151352e+00, -1.604753746038001e+00, -1.024984224037431e+00, -8.139883123577324e-01, -7.222222090195268e-01, -5.665718998971166e-01, -3.671716336822493e-01, -1.962532178850722e-01, -1.190491409167177e-01, -6.253183840231478e-02, -7.197116745399473e-03, -7.170500402387017e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt_ge_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_ge", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.267529232574214e-06, -2.456553384269235e-06, -2.755754858974858e-06, -3.249477936432445e-06, -4.114115006135919e-06, -5.762144951667854e-06, -9.303006588089992e-06, -1.829250300944418e-05, -4.685664347773591e-05, -1.666007323452101e-04, -8.652832900558965e-04, -4.220287349403273e-03, -7.568671259514938e-03, -1.714069972587142e-02, -7.004400847017364e-02, -4.702659127168842e-01, -2.764615242593589e+00, 1.623611144744073e+01, 1.744980700692504e+02, 2.429034919192088e-145]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt_ge_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.158824984756319e-02, -1.211571310904655e-02, -1.291769812588723e-02, -1.416719599514908e-02, -1.618354795216517e-02, -1.960590150569362e-02, -2.584690068293388e-02, -3.839917004420804e-02, -6.666399497184497e-02, -1.329244612789716e-01, -2.946685382151896e-01, -5.364523552065978e-01, -6.477806037342293e-01, -1.124433881312163e+00, -2.680801612723397e+00, -4.383550535406818e+00, 6.306100048421803e+01, 3.341011989677723e+00, -3.237403470778260e+04, -6.190863068898107e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt_ge_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.555338128298668e-08, 1.785427418833764e-08, 2.176099313283280e-08, 2.889008534126469e-08, 4.330904738344370e-08, 7.705467472562697e-08, 1.739530517541065e-07, 5.414167238431060e-07, 2.512341228014924e-06, 1.697323502134717e-05, 2.184133682604510e-04, 7.892138049891447e-03, 2.313961351310755e-02, 8.925325243004757e-02, 8.047229493544571e-01, -6.618061188100743e+00, -7.014114753965315e+03, -1.466878607493051e+06, 6.527473717805463e+09, 5.888402236890656e-133]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_vmt_ge_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_vmt_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.425768274449913e-14, 1.817177507774773e-14, 2.574460576376362e-14, 4.243986095993997e-14, 8.687498592821257e-14, 2.420686443544469e-13, 1.043938092124208e-12, 8.308068929012786e-12, 1.532947222425344e-10, 8.333970087167604e-09, 1.330939854549359e-06, 9.577227594756482e-05, 5.214740550443670e-04, 6.593334180038936e-03, 5.551994487635066e-01, 3.238569346995860e+02, 7.299308459266821e+05, 1.789782186843050e+09, -1.999007162614560e+15, -1.246787618163384e-124]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
