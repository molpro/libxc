
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m05_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.003807841820742e+00, -2.909425162050676e+00, -2.781412821748749e+00, -2.616276013229720e+00, -2.422832550827749e+00, -2.233034789903179e+00, -2.081600565243921e+00, -1.893285991693410e+00, -1.522856760464689e+00, -1.234518214278687e+00, -8.596607332397146e-01, -5.231722566021811e-01, -4.058980010637597e-01, -3.398860646795813e-01, -2.597488876505901e-01, -1.876256977024893e-01, -1.255947517817107e-01, -1.149537703670801e-02, -6.121281481406649e-04, -5.711190997786468e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m05_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.396005309811279e+00, -5.187219200718951e+00, -4.840851312666445e+00, -4.277864822394508e+00, -3.430069083416628e+00, -2.389993792628658e+00, -1.685335706032350e+00, -1.887643378589950e+00, -1.711352999569268e+00, -9.167434064706180e-01, -7.089802537490079e-01, -6.077648021346101e-01, -5.334795592100813e-01, -4.226673775834013e-01, -1.917904172769681e-01, -1.025461502280868e-01, -2.013371312903993e-01, -2.872271584063302e-02, -9.765185484570070e-04, -7.638295225211032e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.687643612273519e-06, -2.869720157871737e-06, -3.154953973877003e-06, -3.624853887563630e-06, -4.466510951547645e-06, -6.178627052697756e-06, -1.021818188437374e-05, -2.067264739194416e-05, -4.944560871740012e-05, -1.684854057093686e-04, -8.433761231840355e-04, -5.475180487581931e-03, -9.386459251510338e-03, -1.994175183015195e-02, -7.327684995082891e-02, -3.910761900583594e-01, -1.757681935479854e+00, -8.098335678824111e-01, -2.492927227125518e-01, -2.322489801380465e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.006492207910489e-02, 3.811628985159032e-02, 3.392501815167494e-02, 2.566341512017805e-02, 1.134860556464055e-02, -7.784685715454973e-03, -1.960540918892775e-02, -6.999070215307992e-03, 1.862780091846595e-03, -8.132910852304167e-03, -3.790948600358522e-03, -1.878814495997404e-03, 6.988468924462901e-03, 1.353729514848003e-02, -4.763604967337001e-02, -5.090527661637999e-02, 4.609688299558855e-02, 1.199281384633321e-02, 1.550353888521742e-04, 2.411137406949922e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.012707737296260e-02, -4.023197347553541e-02, -5.447468670714219e-02, -7.273338428535410e-02, -8.955778221216938e-02, -8.344556091365742e-02, -1.322711612885841e-02, 7.342741864021381e-02, -1.299014514364752e-01, 1.686930507212359e-01, -9.985413473503277e-01, 3.642929574250144e-01, 3.795037626168231e-01, -2.442989292846793e-02, -1.523907217863450e+00, -2.901638297018210e+01, 1.314085493751629e+02, -1.380888553798310e+03, -2.811247324906761e+03, -6.776074664184995e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.450154471889585e-09, 9.627927876804005e-09, 1.207832973209764e-08, 1.786312612550009e-08, 3.343353310150231e-08, 7.977427715476648e-08, 2.169476036054125e-07, 5.244834308353977e-07, 1.246193218348747e-06, 6.156232405949692e-06, -1.027927808802027e-04, 8.900362715605851e-03, 2.571428552329280e-02, 7.520522256752456e-02, 5.896229430148104e-01, -2.339582509848885e+01, -6.127310872444426e+03, -1.271707152651544e+05, -3.715377982646267e+06, -2.408649716888691e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.709918417705910e-04, 7.120557205689498e-04, 1.054973184727895e-03, 1.499819383740482e-03, 1.915947149607691e-03, 1.761332389489570e-03, -6.625350570858252e-05, -2.541777622206568e-03, 2.201489061211666e-03, -6.175399168555789e-03, 2.798069717767442e-02, -6.989786625425867e-02, -3.509418808384504e-01, -4.895658265348243e-01, -3.477708885301155e-02, 2.078109994010099e+01, -8.429170359423657e+01, 9.938259728804696e+02, 1.620147305547960e+03, 1.873429881036585e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.604241443830931e-14, 4.523355354888547e-14, 6.271833795302209e-14, 1.005307806800283e-13, 1.996234659429403e-13, 5.464558984289416e-13, 2.392035789013043e-12, 1.926257369401550e-11, 3.212507622888639e-10, 1.575201464834274e-08, 2.334156842132293e-06, 2.608960128173293e-04, 1.388221734328773e-03, 1.594506470866887e-02, 1.123106042780462e+00, 4.366426711059473e+02, 5.193638774877833e+05, 2.943189141608028e+08, 1.265825030768481e+12, 6.783366033588553e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.001707227647249e-10, 2.231862313899906e-10, 2.494427757360804e-10, 2.615132316484612e-10, 1.844374745902196e-10, -2.461789269196414e-10, -1.594538120740399e-09, -2.150531090668164e-09, 3.608388147479172e-09, -1.882985816980322e-07, -2.314948513318239e-06, -3.174779330662531e-05, 3.930437958548888e-04, 3.718588083528557e-03, -2.005784426867745e-01, -9.114471255455975e+00, 6.569117567513350e+02, 2.625055401310792e+04, 2.210626701823541e+05, 2.539639542739166e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.377194377004712e-05, -1.972986532922462e-05, -2.813772859604932e-05, -3.887844339938974e-05, -4.843363152685120e-05, -4.280995276888354e-05, 5.590052461381457e-06, 6.703928084464678e-05, -5.804133254872429e-05, 1.860027153951221e-04, -8.275981773156384e-04, 6.212062618117864e-03, 1.370860040590020e-01, 2.679421576775703e-01, 3.007081061374280e-01, -1.202628897324684e+01, 4.544067272877019e+01, -9.849605407395852e+02, -1.732307657109593e+03, -2.137248551028687e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
