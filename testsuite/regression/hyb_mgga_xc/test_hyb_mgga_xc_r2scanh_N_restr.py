
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_r2scanh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.422587616942350e+00, -4.333541638814466e+00, -4.208725712061947e+00, -4.035737257193388e+00, -3.799830694889589e+00, -3.485449810225424e+00, -3.079923358895165e+00, -2.580138214003566e+00, -2.001443179793150e+00, -1.378081480854709e+00, -7.812837173769095e-01, -5.651143426541199e-01, -5.661201786113396e-01, -4.734415195034011e-01, -3.235839429678653e-01, -1.759335026941301e-01, -6.936598589324347e-02, -1.868931819344961e-02, -2.580281941402764e-03, -1.219901178718153e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_r2scanh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.800033383493095e+00, -5.680499753163344e+00, -5.512932070939054e+00, -5.280643664561120e+00, -4.963731321080640e+00, -4.541017471309315e+00, -3.994810663833307e+00, -3.319532524309793e+00, -2.530557384045690e+00, -1.652135172753258e+00, -1.072103089721614e+00, -7.893562752444124e-01, -8.071187076948081e-01, -6.369627040495706e-01, -4.198557602216115e-01, -2.006079317830582e-01, -7.889484261995314e-02, -2.981964409957167e-02, -4.635185968067527e-03, -2.337876130353590e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scanh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.759774000477596e-06, -2.976517629900181e-06, -3.317899601625767e-06, -3.877841217336391e-06, -4.852345849914686e-06, -6.702112519128768e-06, -1.068454316236719e-05, -2.099912033854877e-05, -5.754280945313274e-05, -3.042934071257688e-04, -5.897555760956637e-04, -1.605813826161460e-03, -1.003061496749762e-02, -1.967093405502138e-02, -8.822523467317553e-02, -8.795819640723610e-01, -4.846467611328999e+00, 5.957028094000557e+00, 3.017035356403950e+02, 1.429751122487180e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scanh_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.126828967466596e-03, 4.191999577460907e-03, 4.287349744767649e-03, 4.428432604944090e-03, 4.641305335029588e-03, 4.972672370015654e-03, 5.509581582588309e-03, 6.429768035614110e-03, 8.339854282302182e-03, 1.515382391980367e-02, 8.217022636451713e-03, 6.140349398926397e-03, 3.627014884551117e-02, 3.899259707725650e-02, 5.485412047847124e-02, 9.199215279901579e-02, 4.623603994873290e-02, 2.437396801909888e-03, 1.299495680084171e-04, 4.506340731241515e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scanh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.175171982998703e-02, -1.225642892521501e-02, -1.302265453400257e-02, -1.421465300731898e-02, -1.613453966877061e-02, -1.937201420379515e-02, -2.512446574602958e-02, -3.602051025892210e-02, -5.884776049330330e-02, -1.669267780482267e-01, -3.205735741148439e-01, -6.400725837612655e-01, -7.335944559624009e-01, -1.176027650758500e+00, -3.531667326662003e+00, -2.867684937800488e+01, -6.942343644386219e+02, -2.033864020695134e+03, -2.903620055157809e+04, -1.583731203583531e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scanh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.051138992529583e-09, 8.868483488702828e-09, 1.021878475742292e-08, 1.260395524502075e-08, 1.718426700613325e-08, 2.630082429985642e-08, 3.743320905896770e-08, -5.920942532223525e-08, -2.355245625672279e-06, -1.395380304150069e-05, 1.702931305293183e-04, -1.395483866084446e-02, 5.202594586645494e-02, 1.370066155674845e-01, 1.674044901689894e+00, 2.261202403105609e+02, 1.315738893693603e+05, 9.911601798672732e+06, 1.403362689664518e+10, 6.552088995811270e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scanh_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.619649401256781e-06, 7.573052570350536e-06, 9.092258409582940e-06, 1.162701809880567e-05, 1.621541877019321e-05, 2.600584493600388e-05, 5.375716411752744e-05, 1.595287025117004e-04, 7.184775521817927e-04, 2.916337709874589e-03, 1.428738128387788e-03, 3.658909948354085e-02, -1.650911524830951e-02, -8.096184370745048e-02, -9.385774273822056e-02, -1.246590170829470e+01, -9.772705131024850e+02, -2.297051709693712e+03, -2.643092251273291e+04, -1.753555823583417e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scanh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.600289251552191e-13, 3.274375392786802e-13, 4.546191195453338e-13, 7.246779130479297e-13, 1.406898266901488e-12, 3.653650355804968e-12, 1.484836914992655e-11, 1.168928368767289e-10, 2.328729276480298e-09, 1.082555377953217e-07, -3.599537623556519e-06, 5.897664193521906e-04, -9.012125856108773e-03, 1.686170447353226e-02, 1.714182061034605e+00, -2.211730270578141e+03, -2.704837290403466e+07, -6.231133458311864e+10, -9.844834681855854e+15, -3.554979052469034e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scanh_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.964282615688763e-10, -3.527113672349860e-10, -4.519773267917980e-10, -6.435322384844419e-10, -1.065856799641985e-09, -2.206959099564697e-09, -6.416772117877530e-09, -3.068338029991694e-08, -2.979273027039802e-07, -4.925607190973912e-06, 5.197417913253084e-05, 7.971921643976718e-04, 5.498608250790603e-05, -4.509229124228291e-02, -1.213878470053593e+00, 1.908150796920564e+02, 2.108663155441573e+05, 1.519547117374543e+07, 1.983436235505187e+10, 1.000103034179844e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_r2scanh_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_r2scanh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.379430965540727e-07, 3.803186728756014e-07, 4.506906926049854e-07, 5.752481775078101e-07, 8.171286184765959e-07, 1.354925997526740e-06, 2.812476121277132e-06, 8.108724786714193e-06, 3.813746518821588e-05, 2.236506714750013e-04, -7.104429065112314e-04, -4.287135721800807e-03, -1.103246464679845e-03, 9.668903901281008e-02, 7.485559484513270e-01, -1.717818050136845e+01, -1.654369047213886e+03, -3.889595246534692e+03, -4.465312545664811e+04, -3.052634400385257e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
