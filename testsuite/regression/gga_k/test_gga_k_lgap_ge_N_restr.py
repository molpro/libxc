
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_lgap_ge_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap_ge", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.456848411239304e+01, 9.090752264485300e+01, 8.590190483154234e+01, 7.920760987557402e+01, 7.053433361499096e+01, 5.979439474114928e+01, 4.732439000862733e+01, 3.410523554108828e+01, 2.176941219631529e+01, 1.205372179120040e+01, 5.445457729725078e+00, 2.212989405322165e+00, 1.630480569995719e+00, 1.104970407555134e+00, 5.735182948804576e-01, 2.551304571333345e-01, 1.507931013607612e-01, 1.925824048901295e-01, 5.778978618648072e-01, 4.358217476974053e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_lgap_ge_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap_ge", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.491298820268343e+02, 1.430450870402555e+02, 1.347263012634575e+02, 1.236027210958909e+02, 1.091932569384817e+02, 9.135357676178903e+01, 7.064343814093992e+01, 4.869462536865721e+01, 2.826356578760714e+01, 1.264946227627731e+01, 4.849582099761461e+00, 3.358833166601270e+00, 2.610484584867752e+00, 1.634140594870568e+00, 6.824413260943428e-01, 1.150897479630044e-01, -1.301879046098859e-01, -3.407647366296254e-01, -1.258348437401587e+00, -1.008402773411369e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lgap_ge_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap_ge", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.103446082183267e-05, 9.677917798997381e-05, 1.056833110462823e-04, 1.199441595674095e-04, 1.438879212706752e-04, 1.869186026611180e-04, 2.722269133673148e-04, 4.670807556551932e-04, 1.011763096934048e-03, 2.993934789845215e-03, 1.125621685669760e-02, 2.643871551753786e-02, 3.974543172391068e-02, 7.708277931282391e-02, 2.576353431941918e-01, 1.660665101512461e+00, 2.586226463229515e+01, 1.491142261650375e+03, 6.048447711700991e+05, 3.667914815490530e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lgap_ge_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.023475035298050e-01, 6.163872290126928e-01, 6.372538729133242e-01, 6.687358340505448e-01, 7.173094710122513e-01, 7.948559358746459e-01, 9.254639335757859e-01, 1.165423673309666e+00, 1.673792926256922e+00, 2.967286507396408e+00, 5.307693706843163e+00, 4.173179769419460e+00, 4.483441441666231e+00, 6.142423609542427e+00, 1.161312745784477e+01, 4.218757055942464e+01, 5.294895521878581e+02, 3.292950433977740e+04, 1.437613553157232e+07, 8.684301698548276e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lgap_ge_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.064229893706724e-07, -5.745675817590507e-07, -6.888755195924740e-07, -8.940231772020481e-07, -1.299864453586597e-06, -2.223878151815969e-06, -4.801223325885870e-06, -1.444161455529173e-05, -6.935250832124286e-05, -6.183743139396929e-04, -8.776871599815578e-03, -4.474683328906963e-02, -9.320256076032112e-02, -3.870934320213749e-01, -4.544059696712416e+00, -1.906122709046761e+02, -4.188481284604521e+04, -9.010807082303219e+07, -4.713841679022099e+12, -2.204329783177094e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lgap_ge_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap_ge", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.042173279338747e-14, 5.257320976947939e-16, 4.773576149198846e-14, 1.690780750469802e-13, 5.397971869411600e-13, 1.971000493544626e-12, 9.619463653843718e-12, 7.440787370010628e-11, 1.134400559908911e-09, 4.445541499577286e-08, 4.715700315224794e-06, 1.651248417816647e-04, -1.285673311563463e-03, 9.735615207141403e-03, 6.583252622093095e-01, 2.568099242112869e+02, 1.054110761291078e+06, 9.864830413302373e+10, 7.068485095728159e+17, 2.652005235844608e+27]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
