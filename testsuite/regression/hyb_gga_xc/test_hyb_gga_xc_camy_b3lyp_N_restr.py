
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_camy_b3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_b3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.494910507656621e+00, -3.428372738859004e+00, -3.335185382696189e+00, -3.206196741461625e+00, -3.030635179998473e+00, -2.797379228095150e+00, -2.497921941187656e+00, -2.131554025838069e+00, -1.711660862789361e+00, -1.266596431160332e+00, -8.279115063209486e-01, -5.193213779512417e-01, -4.395055958651463e-01, -3.592722299533637e-01, -2.463967920521352e-01, -1.321849148149303e-01, -5.467477757195411e-02, -3.701218177474903e-02, -2.184116082649920e-02, -1.436881604901738e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_camy_b3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.366462122869303e+00, -4.274536308785010e+00, -4.145722273175080e+00, -3.967282889606556e+00, -3.724163609859282e+00, -3.400740838775094e+00, -2.985114614239174e+00, -2.477436011231562e+00, -1.903641796206160e+00, -1.333482477378556e+00, -8.757192346405480e-01, -6.494427108680014e-01, -5.719510879340518e-01, -4.504451331135537e-01, -3.022386905032480e-01, -1.756888307384132e-01, -7.872108515542912e-02, -2.125449841241881e-02, -7.393568364220320e-03, -2.544780708843877e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_b3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.193261518876234e-06, -3.439490277729933e-06, -3.825810775612101e-06, -4.455036808754181e-06, -5.535782801833775e-06, -7.536239823813851e-06, -1.164571409307122e-05, -2.137824693322995e-05, -4.917705289785059e-05, -1.495231140205085e-04, -6.584779793113636e-04, -4.172381042757092e-03, -8.146523153569722e-03, -1.410619074219990e-02, -3.486479940169293e-02, -4.489680654196007e-02, 8.727200107460074e-01, -5.948181118965760e+01, -5.907237414785520e+03, -3.512424801235634e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_b3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.591825075357656e-03, -1.001500517315459e-02, -1.065517368826626e-02, -1.164469884097477e-02, -1.322137220259899e-02, -1.584148481295997e-02, -2.044764728296436e-02, -2.912296512207838e-02, -4.649585278308795e-02, -8.019533161469711e-02, -1.496653771910617e-01, -4.027737301663859e-01, -5.196114046140279e-01, -7.912741847659965e-01, -1.308543780354952e+00, -1.627621558752428e-01, 8.086498462727882e+00, -4.254220434910258e+01, 4.523917541481878e+03, 3.453387902640758e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_b3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.578979163507731e-08, 1.787948791950478e-08, 2.135793071347406e-08, 2.752089719021711e-08, 3.944231571957897e-08, 6.548621436272913e-08, 1.324796491223208e-07, 3.434408034749858e-07, 1.134798284340932e-06, 2.598046172798670e-06, -6.871842014309383e-05, 3.853601224115478e-03, 1.604950197653025e-02, 2.545874285137868e-02, -2.409283623470697e-01, -3.009249294534056e+01, -3.578331784956203e+03, -3.316136542220609e+05, -3.537838617037818e+09, -1.193630016119473e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camy_b3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camy_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.263338665087471e-14, 1.030118724134255e-13, 1.413268145510424e-13, 2.223282682043129e-13, 4.249792377289447e-13, 1.070383281480020e-12, 3.972054431082323e-12, 2.524785619631062e-11, 3.347314270361615e-10, 1.185598246464093e-08, 1.507827051182953e-06, 3.531279239690657e-04, 3.034096491076484e-03, 1.962213366512368e-02, 7.646001293390251e-01, 1.788889889238886e+02, 2.820008115947487e+05, 6.993773538897689e+09, 8.471437100277262e+15, 2.817127864374999e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
