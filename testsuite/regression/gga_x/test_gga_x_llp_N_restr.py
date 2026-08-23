
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_llp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_llp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.318582841989024e+00, -4.236785985241662e+00, -4.122255809366273e+00, -3.963784414498315e+00, -3.748225136601263e+00, -3.462117473499550e+00, -3.095476906486527e+00, -2.648513955402227e+00, -2.140176363561648e+00, -1.609758371775292e+00, -1.083373587952958e+00, -6.670362780463875e-01, -5.644607958662936e-01, -4.738598528890790e-01, -3.495356566986349e-01, -2.312740660333137e-01, -1.443129532726856e-01, -8.875338079616402e-02, -5.685552252246297e-02, -3.937097036830789e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_llp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_llp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.383361238743616e+00, -5.269708538021586e+00, -5.110423569365074e+00, -4.889719150631878e+00, -4.588892434279727e+00, -4.188422912579658e+00, -3.673130635108775e+00, -3.042114670773582e+00, -2.324943990000162e+00, -1.603797591389250e+00, -1.030249792534976e+00, -8.024039177014781e-01, -7.151445055016378e-01, -5.582161658154016e-01, -3.647283227030321e-01, -1.970803345197855e-01, -9.238908459825555e-02, -3.999174754566737e-02, -1.568286104044783e-02, -6.458424946294070e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_llp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_llp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.020987137553882e-06, -4.335680324654691e-06, -4.830324678260895e-06, -5.638210120149234e-06, -7.031700779964244e-06, -9.628349858477448e-06, -1.502182580134827e-05, -2.804727444248693e-05, -6.669870364428211e-05, -2.183244471338810e-04, -1.103329274123619e-03, -6.979371856052078e-03, -1.392049645147512e-02, -2.734310747286732e-02, -9.546914400780016e-02, -5.959070138811889e-01, -6.780837172757177e+00, -1.765436291544021e+02, -1.636993109692774e+04, -9.733661471912013e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_llp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_llp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.191836040774111e-02, -1.245003099292065e-02, -1.325540714809280e-02, -1.450292547709189e-02, -1.649746310505039e-02, -1.983129078696305e-02, -2.575522241098671e-02, -3.716290029404914e-02, -6.130715598158261e-02, -1.170834739526616e-01, -2.650956603860581e-01, -5.403816524969484e-01, -6.689241457233763e-01, -1.113529664861366e+00, -2.395082083908393e+00, -5.898786145516929e+00, -8.493464782669168e+00, 1.542934606386437e+02, 1.770002663936443e+04, 1.006821623986949e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_llp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_llp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.036872853423683e-08, 2.311400128062860e-08, 2.770048919497477e-08, 3.587289606983188e-08, 5.182576993919304e-08, 8.721803870717924e-08, 1.808933558751018e-07, 4.946178701871182e-07, 1.901670043235795e-06, 1.062047486457145e-05, 1.367376872195386e-04, 8.707743570256677e-03, 3.312634113542094e-02, 9.004677141354669e-02, 5.469547775724527e-01, 1.368870518537261e+00, -1.550056810297947e+03, -1.280997898074954e+06, -9.802433395571186e+09, -3.307749023953952e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_llp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_llp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.026656155650934e-13, 1.280552906572092e-13, 1.758284287383761e-13, 2.769400001117275e-13, 5.303375577080945e-13, 1.339508901305809e-12, 4.992981561707831e-12, 3.197325008469064e-11, 4.294948045181162e-10, 1.559829020422039e-08, 2.074669607815142e-06, 5.069623870002578e-04, 4.463441839902929e-03, 2.996020158021892e-02, 1.274854008692347e+00, 3.581455984362901e+02, 7.291706982258946e+05, 1.936707429046980e+10, 2.347534451597308e+16, 7.806838408031046e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
