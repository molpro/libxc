
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_pbe3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.009452941978410e+02, 9.810965809397145e+01, 9.423681325141790e+01, 8.905539553608752e+01, 8.230781240190753e+01, 7.380257381711677e+01, 6.343535227115784e+01, 5.111659155250236e+01, 3.681118838445591e+01, 2.165847584435954e+01, 9.655193143998904e+00, 2.801735689175131e+00, 1.612116207502177e+00, 1.523051581900662e+00, 1.013453690385455e+00, 3.960190330030954e-01, 8.382641635141277e-02, 8.787300691286505e-03, 3.777190751120630e-04, 4.618386803681876e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_pbe3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.429120532805842e+01, 7.921496811323355e+01, 7.253175478908227e+01, 6.411517308146816e+01, 5.424113071295245e+01, 4.395368885035729e+01, 3.528539381595252e+01, 3.039017620825629e+01, 2.826515614662706e+01, 2.253733715456060e+01, 1.118268235248975e+01, 1.616521827024004e+00, 1.759292042265062e+00, 8.470843246902799e-01, 9.143757471478424e-01, 5.387724813512456e-01, 1.339086324239610e-01, 1.457611985708898e-02, 6.293943601942524e-04, 7.697289771867980e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.007775902198973e-04, 9.635242327495496e-04, 1.058012154433217e-03, 1.202448996472337e-03, 1.426817954297736e-03, 1.779440825183888e-03, 2.329823349247567e-03, 3.141843305068646e-03, 4.174699287276931e-03, 5.456682626220921e-03, 1.307568660066077e-02, 2.449853689772186e-01, 3.446023361034812e-01, 6.283730597636742e-01, 7.299825011080137e-01, 6.493163984960822e-01, 3.933174804791295e-01, 1.563425191326597e-01, 3.741813577650971e-02, 4.560144510743634e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.009283122844072e+00, 9.924395049994752e-01, 9.596481453938016e-01, 8.935343551585205e-01, 7.561892677035590e-01, 4.655921191564469e-01, -1.428975068939500e-01, -1.316353442714992e+00, -3.056441790848802e+00, -4.246081412702348e+00, -5.286655036184539e+00, 1.510069110811698e+00, 8.953456849537977e+00, -2.503147680779523e+00, -2.057746182473625e+01, -7.773699802377921e+00, 6.610423410635578e+01, 2.926142503935733e+02, 1.467006947237202e+03, 1.329112235228807e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.462595815329451e-06, -7.759951509798531e-06, -8.088192285264393e-06, -8.260122644662994e-06, -7.524786652973303e-06, -2.941860558428699e-06, 1.761743219899862e-05, 1.081489191084893e-04, 5.274884357657919e-04, 2.734332977671242e-03, 2.644016297534844e-02, 1.845583646529582e-02, -2.266588008855794e+00, 1.912271279480684e+00, 2.796248141314338e+01, 2.068436571038077e+02, 1.681172062988556e+03, 2.097506711290287e+04, 5.676109436648480e+05, 5.118265179366496e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pbe3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pbe3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.610298723713821e-11, 2.331708406229590e-11, 1.539441412430061e-11, -8.324502388687334e-12, -8.694129709930565e-11, -3.915776840946787e-10, -1.859456953927548e-09, -1.126854303034204e-08, -9.798058018825746e-08, -1.472816811346010e-06, -9.209947080646457e-05, -3.322220578404526e-02, 5.307023741982493e-01, -1.803460295562220e+00, -3.661437512075960e+01, -1.406276082562343e+03, -1.411154807082126e+05, -5.821085593667875e+07, -1.902111729514435e+11, -1.331914456073050e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
