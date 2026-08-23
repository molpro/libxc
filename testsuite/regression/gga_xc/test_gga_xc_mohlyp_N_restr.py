
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_mohlyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.270563830088840e+00, -4.187053188333556e+00, -4.070116849623730e+00, -3.908315986033465e+00, -3.688272035664525e+00, -3.396454697380834e+00, -3.023522505213275e+00, -2.572782997142197e+00, -2.073234077882545e+00, -1.581531738253323e+00, -1.088467488527460e+00, -6.910473695880087e-01, -6.031187038967382e-01, -4.960015878756435e-01, -3.633143752346074e-01, -2.519410616685527e-01, -1.523894461141511e-01, -6.230940111685006e-02, -1.373647929857613e-02, -1.558406812707550e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_mohlyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.583193416409318e+00, -5.467453313232533e+00, -5.304868438935896e+00, -5.078774628519390e+00, -4.768783784078576e+00, -4.351976816829414e+00, -3.806082901164520e+00, -3.115843275184967e+00, -2.290320364610560e+00, -1.442031842540924e+00, -8.999368008321411e-01, -8.802520144165620e-01, -7.888961574721619e-01, -6.216192777469898e-01, -3.834915689334457e-01, -1.957504421584160e-01, -1.658905245672392e-01, -7.925445223696755e-02, -1.820138545322022e-02, -2.074459274174383e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mohlyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.279962404049861e-07, -1.040273495215325e-06, -1.225145101086011e-06, -1.547842562584093e-06, -2.159787501841713e-06, -3.463822718041271e-06, -6.729196114283786e-06, -1.686153432967894e-05, -5.751555296130042e-05, -2.624576053262442e-04, -1.440220154220279e-03, -2.382297424932620e-03, -1.654375658816040e-03, -1.141389214448495e-02, -8.918120095272761e-02, -7.260710981225871e-01, -1.969542997554810e+00, -4.955137339108239e+00, -9.233686139749700e+00, -1.020329539299117e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mohlyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.198351616333354e-02, -1.259919277638504e-02, -1.355046652942249e-02, -1.506932683204942e-02, -1.761530492050027e-02, -2.220277147007042e-02, -3.139090087403360e-02, -5.262260108492404e-02, -1.087188936293194e-01, -2.396804094560456e-01, -4.877916996406052e-01, -6.189295185057985e-01, -6.559761956421932e-01, -1.398472761179613e+00, -4.617025530721603e+00, 8.245238192303821e-01, 1.324312861620616e+02, -4.099872580315638e+02, -2.035983888668119e+04, -1.777523032792869e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mohlyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.871241124329475e-08, 2.219237186018733e-08, 2.833150209648582e-08, 4.016113404681401e-08, 6.600080647236418e-08, 1.333338779524081e-07, 3.571488108159906e-07, 1.381967147565057e-06, 8.156726989517327e-06, 6.531150818542511e-05, 8.391997281295208e-04, 1.361357523240800e-02, 1.844941426220396e-02, 1.808065191933494e-01, 2.690501378726696e+00, -3.272270933043124e+01, -1.319285052670610e+04, -8.219199751974964e+05, -1.290720575443696e+08, -1.057092311535013e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mohlyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mohlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.272223825332692e-13, -1.602610990222526e-13, -2.230799336714538e-13, -3.579133959835671e-13, -7.018672343471115e-13, -1.821565989491092e-12, -6.929600111431599e-12, -4.320200027498843e-11, -4.559836357783177e-10, -2.606411662665588e-09, 9.052782864686435e-07, -6.955740420445589e-04, -5.048939121620078e-03, -4.160438098682366e-02, -8.914792035749581e-01, 6.226330445465260e+02, 1.153666307268469e+06, 2.744050523720246e+09, 4.687826375651961e+13, 2.980101327674494e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
