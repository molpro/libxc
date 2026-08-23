
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_hcth_a_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hcth_a", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.062458184623119e-02, -7.090562655938704e-02, -7.131667811276837e-02, -7.191839988388514e-02, -7.279430331686886e-02, -7.404016073220060e-02, -7.569077498377735e-02, -7.741631488170346e-02, -7.743505453417655e-02, -6.996318102368583e-02, -5.733833773916033e-02, -4.577425104865785e-02, -3.599559843333092e-02, -4.227097236451654e-02, -4.133148341892734e-02, -1.924355003306558e-02, 2.199791382182986e-02, 2.148680843001288e-02, 6.064666309277409e-03, 7.109978548079792e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_hcth_a_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hcth_a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.347726911246315e-02, -3.324424109691178e-02, -3.299890794175529e-02, -3.283562333259229e-02, -3.299988502816025e-02, -3.406766109589499e-02, -3.730108012979787e-02, -4.536557264453391e-02, -6.396493700988012e-02, -1.007303973662765e-01, -1.125677640875659e-01, -2.326244711305578e-02, -2.150105152688500e-02, -2.361255778759459e-02, -4.613219037206522e-02, -8.655891379399665e-02, -2.989370069727247e-02, 2.183398394649196e-02, 7.873133467147573e-03, 9.481180577402750e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_hcth_a_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hcth_a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.590695094734562e-07, -4.954133607806001e-07, -5.515898800407967e-07, -6.408506050435774e-07, -7.877688862480857e-07, -1.039612712932818e-06, -1.485337592568478e-06, -2.234238377985992e-06, -2.621518929590779e-06, 9.511848008813726e-06, 1.299469068644549e-04, -2.248064903570821e-03, -7.042094235544940e-03, -8.985325812121820e-03, -1.055668232521439e-03, 3.437075951222218e-01, 3.826297426586217e+00, 1.166941530350227e+01, 1.860326877748873e+01, 2.259895358730991e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_hcth_a_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hcth_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.932975891842618e-05, -4.278158419350210e-05, -1.389394848782120e-05, 3.959328888083579e-05, 1.459832467600256e-04, 3.772294891237555e-04, 9.434726431404830e-04, 2.610938345952052e-03, 9.133131448306540e-03, 4.028160654684142e-02, 1.468669100401527e-01, 3.975227868215676e-02, -4.329117084463075e-02, 1.679592690549139e-01, 1.584485944373230e+00, 7.295876571737175e+00, -1.350963379792800e+02, -4.312836049250366e+02, 7.424973210035590e+03, 8.163255840712708e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_hcth_a_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hcth_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.039487585482249e-10, 3.395484419291314e-10, -4.000270416566837e-12, -7.948780916434030e-10, -2.849705819176800e-09, -9.097479661457669e-09, -3.268024729743501e-08, -1.553466263077987e-07, -1.193469420430798e-06, -1.686880123984309e-05, -4.111622342261535e-04, -3.492460552275891e-03, 1.401786507417848e-02, -6.698932679793007e-02, -1.579493705679266e+00, -4.554013441434938e+01, 8.726132002191376e+03, 1.345014674290411e+06, 2.579190754221539e+08, 2.338631724564631e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_hcth_a_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hcth_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.817951226366859e-14, 4.937669784555710e-14, 7.093515739129025e-14, 1.177667520490400e-13, 2.380656499965839e-13, 6.276080201292544e-13, 2.365977352918908e-12, 1.458452096604856e-11, 1.815553678208982e-10, 5.769568645188717e-09, 7.597894294053826e-07, 7.303207937245144e-04, 4.600069264784845e-03, 4.888444441350084e-02, 1.510978350667597e+00, 6.612160032180405e+00, -9.784615661779497e+05, -4.186476517718106e+09, -9.440648496370248e+13, -6.600495450714612e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
