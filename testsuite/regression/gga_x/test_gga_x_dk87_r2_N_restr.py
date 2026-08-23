
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_dk87_r2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.311519665977385e+00, -4.230551601489834e+00, -4.117224287871723e+00, -3.960497033028130e+00, -3.747449484142666e+00, -3.464878620529193e+00, -3.102908304470724e+00, -2.661030665730157e+00, -2.154917486632271e+00, -1.617693833660115e+00, -1.084830557927441e+00, -6.678876649258663e-01, -5.629588340823904e-01, -4.752676846216144e-01, -3.519047302650461e-01, -2.283039439975290e-01, -1.343440112389320e-01, -8.040650217858571e-02, -5.772984933930178e-02, -4.980836670506420e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_dk87_r2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.327264539132488e+00, -5.212959001158652e+00, -5.052915768661750e+00, -4.831516087550848e+00, -4.530564682963794e+00, -4.131861558319007e+00, -3.623333958754869e+00, -3.010278670910452e+00, -2.329533481876884e+00, -1.652940407942180e+00, -1.078856564051625e+00, -7.914298079113943e-01, -7.098670821852102e-01, -5.508499363612451e-01, -3.700234947759631e-01, -2.129466789442999e-01, -9.850786593234202e-02, -3.343267944641034e-02, -8.090668425482696e-03, -2.054454876672954e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_dk87_r2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.521845255736538e-06, -4.889293879427791e-06, -5.466150123110233e-06, -6.405797558189953e-06, -8.017339623147774e-06, -1.098442616173893e-05, -1.699658735178085e-05, -3.082914039793967e-05, -6.859955875696356e-05, -2.028067636255738e-04, -9.790417054645860e-04, -7.951059655711960e-03, -1.513712529322620e-02, -3.077723786462782e-02, -9.345609082049325e-02, -4.897404555541804e-01, -5.464999824927712e+00, -1.662454432203778e+02, -1.875443698232492e+04, -1.360725490513952e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_dk87_r2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.252133203090078e-02, -1.305544845248384e-02, -1.385557175834894e-02, -1.507323576260338e-02, -1.696451180115198e-02, -1.997487942184414e-02, -2.489117097664949e-02, -3.310738326670343e-02, -4.746003305026244e-02, -7.852097739336450e-02, -1.741671051322567e-01, -5.381887448833824e-01, -7.069129500614979e-01, -1.057732680690457e+00, -1.707958563052104e+00, -4.352656031406327e+00, -2.562793747927435e+01, -2.661070945184003e+02, -2.920248925568012e+03, 2.672166611883212e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_dk87_r2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.795882506737253e-08, 3.131714897345920e-08, 3.676771838210671e-08, 4.604183031534856e-08, 6.280923547725416e-08, 9.530078173459045e-08, 1.614109739702038e-07, 2.792404770908517e-07, 1.430063327197460e-07, -6.015580818723758e-06, -1.323066912552345e-04, 9.005727107845427e-03, 4.882907115967378e-02, 7.358778835601837e-02, -1.253185218745128e-01, -9.343060135733353e+00, -5.293133385390879e+02, -1.806014684322253e+05, -1.775756531686140e+09, -9.400272175022884e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_dk87_r2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.123658784339672e-14, 8.438099146543935e-14, 1.311218328373413e-13, 2.392645217730134e-13, 5.406961178649419e-13, 1.622738189481273e-12, 7.080273123386465e-12, 5.030425282285772e-11, 6.704709130913043e-10, 2.088031848893203e-08, 2.516523080782877e-06, 6.509120841032408e-04, 9.538987390711560e-05, 4.403964480187560e-02, 1.870562307740020e+00, 3.503926285534392e+02, 5.388684450710017e+05, 1.592611706529284e+10, 2.432069140410357e+16, 1.013469537537320e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
