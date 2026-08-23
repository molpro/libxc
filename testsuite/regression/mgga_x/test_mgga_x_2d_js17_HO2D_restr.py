
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_2d_js17_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.685082953631416e-01, -8.685212336521306e-01, -8.685398192438216e-01, -8.685636029597686e-01, -8.685853397840940e-01, -8.685760570500054e-01, -8.684433274442713e-01, -8.679180818483169e-01, -8.662568135215539e-01, -8.614990871113020e-01, -8.488463079741002e-01, -8.183368421924315e-01, -7.559043052055654e-01, -6.552622708820957e-01, -5.393066537102197e-01, -4.964880251918504e-01, -6.884065937893458e-01, -1.289361281130277e+00, -3.100241144960073e+00, -1.064476891915807e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_2d_js17_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.315819367691861e+00, -1.315808447252278e+00, -1.315787457306601e+00, -1.315744891371774e+00, -1.315653853180649e+00, -1.315450081293203e+00, -1.314979221060563e+00, -1.313875167566124e+00, -1.311296115338490e+00, -1.305376762845668e+00, -1.291843539704784e+00, -1.258486154077934e+00, -1.169014355859571e+00, -9.638613330030922e-01, -6.161440467870333e-01, -1.747013533255965e-01, 1.504469525617120e-01, 4.094440402874491e-01, 1.017614053020610e+00, 3.494816934415548e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_js17_HO2D_restr_1_vsigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.640297943493676e-02, 7.640970713195069e-02, 7.642107396947388e-02, 7.644056701246363e-02, 7.647440498132053e-02, 7.653288016642167e-02, 7.662824242019110e-02, 7.675024561124438e-02, 7.674159199534027e-02, 7.581580390995922e-02, 7.119112459982649e-02, 5.653999110382939e-02, 2.707387986532832e-02, -1.216282390621917e-02, -7.164140602447537e-02, -2.770598972454723e-01, -1.883839145311228e+00, -5.103051400308269e+01, -1.669717377901201e+04, -3.146934205359225e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_js17_HO2D_restr_1_vtau():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.552949639883966e-03, 6.552965996536950e-03, 6.553008472754456e-03, 6.553117720020620e-03, 6.553394258186529e-03, 6.554075825432658e-03, 6.555680387200369e-03, 6.559157685395055e-03, 6.565530788155089e-03, 6.572850710164870e-03, 6.565039468067105e-03, 6.493562014549200e-03, 6.310338513240696e-03, 6.121454200686654e-03, 6.245758394397047e-03, 7.062274094350922e-03, 8.248297959966587e-03, 9.336894590005442e-03, 1.290964802934421e-02, 2.603349364218975e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_js17_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.023190409985872e+00, -1.023210828276335e+00, -1.023246277291391e+00, -1.023309637419943e+00, -1.023426763751945e+00, -1.023650205863812e+00, -1.024083525231609e+00, -1.024908300564576e+00, -1.026358669094439e+00, -1.028686360626430e+00, -1.035309417827311e+00, -1.081756675823966e+00, -1.298498247861172e+00, -1.824216531687252e+00, -2.990050482894429e+00, -6.816775865434920e+00, -2.446658394004940e+01, -1.042640041670676e+03, -5.874806238895756e+05, -1.884631475597115e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_js17_HO2D_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.716701653311936e-01, -1.717060849068131e-01, -1.717656967360330e-01, -1.718649956379553e-01, -1.720291306191280e-01, -1.722881238407140e-01, -1.726283889637150e-01, -1.727385487421000e-01, -1.709377979141679e-01, -1.604165388394208e-01, -1.202020749177702e-01, -1.565625318701774e-02, 1.364356741966771e-01, 2.728036091392780e-01, 5.703100375304002e-01, 2.676679760169398e+00, 4.437202349146973e+01, 2.838821558644650e+04, 2.191204902108712e+09, 3.860175269784114e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_js17_HO2D_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.146690170860706e-03, -5.146727626029147e-03, -5.146823092485632e-03, -5.147060919478570e-03, -5.147629891964360e-03, -5.148890346118987e-03, -5.151245904641133e-03, -5.153682856858862e-03, -5.146209312924773e-03, -5.080423078094751e-03, -4.787554366837284e-03, -3.900562508955884e-03, -2.222191769060106e-03, -2.288837202297322e-04, 2.691575628479167e-03, 2.151408672270880e-02, 3.789495164960731e-01, 1.278962969457247e+01, 4.206018183375809e+03, 7.927551459552732e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_js17_HO2D_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.609020077428670e-01, -3.609336283280382e-01, -3.609925288146071e-01, -3.611071446327917e-01, -3.613393440938938e-01, -3.618217858283833e-01, -3.628188139470241e-01, -3.647548006749916e-01, -3.678471973842801e-01, -3.698929391008989e-01, -3.588603967108358e-01, -3.052080123117766e-01, -2.004263783132779e-01, -1.056608436097198e-01, -2.865987650777230e-02, 1.215688961859300e+00, 2.832955064087360e+02, 2.654780967524433e+06, 2.784856097363707e+13, 2.692611213382885e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_js17_HO2D_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.190980224883614e-03, -4.191053681393141e-03, -4.191244824279565e-03, -4.191738099922911e-03, -4.192993937750416e-03, -4.196120513062032e-03, -4.203618653602398e-03, -4.220474069241449e-03, -4.254068200177531e-03, -4.305346513112348e-03, -4.330781139872886e-03, -4.183044074927720e-03, -3.781461065868703e-03, -3.685746449065354e-03, -5.913130534974500e-03, -3.089697145591400e-02, -1.088012566604378e+00, -4.638120928544582e+02, -2.060080794711668e+07, -2.131455531931395e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_2d_js17_HO2D_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_2d_js17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
