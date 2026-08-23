
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.968515060033967e+00, -1.934821202763125e+00, -1.887956044321921e+00, -1.822879313785364e+00, -1.731377708534853e+00, -1.598486759699046e+00, -1.405346747893747e+00, -1.182108047522447e+00, -1.006214956670116e+00, -7.251980553141478e-01, -5.229888684246458e-01, -3.069265589020667e-01, -2.570514132483802e-01, -2.171722558576951e-01, -1.590847801199156e-01, -1.099110311756534e-01, -4.978391225640599e-02, -2.153578574979170e-02, -4.735383161464277e-03, -5.251911042479069e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.308727778742559e+00, -2.249427952519786e+00, -2.178123780793832e+00, -2.104270007786832e+00, -2.049196154845403e+00, -2.022568631061553e+00, -1.886587738244606e+00, -1.285859161127766e+00, -9.852043300149548e-01, -7.280590163261940e-01, -4.714481363969367e-01, -2.946870460691339e-01, -2.705173709184313e-01, -2.062856573312763e-01, -1.924872881214348e-01, -1.190934196969905e-01, -4.810395158844591e-02, -2.629186747546332e-02, -6.286733729044583e-03, -7.002155752660288e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.761320032894516e-06, -1.908416645277597e-06, -2.141506783158350e-06, -2.525601707817216e-06, -3.191808486225914e-06, -4.422883862585917e-06, -6.898580313802291e-06, -1.290734889120141e-05, -3.267077529860689e-05, -9.897406709437708e-05, -5.130818557434217e-04, -3.212093694217225e-03, -5.944356980511602e-03, -1.274190289263893e-02, -4.487885075368938e-02, -2.290922184109208e-01, -6.967192658072628e-01, -1.517166610126212e+00, -1.928512134255468e+00, -2.135720874795217e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.705426779554423e-03, -3.993892071372089e-03, -4.118347856054492e-03, -3.667625212744455e-03, -1.822989649169907e-03, 2.182791791191818e-03, 5.555529276213680e-03, -1.651003117795691e-03, -2.495643819315281e-03, 1.854903747761468e-04, -1.044745569776499e-03, -6.492078866497534e-03, -2.238873609057553e-02, -2.862835513390733e-02, 1.737505565661658e-02, 1.046119669215432e-02, -6.163771721440632e-03, -1.525138639900047e-03, -1.925388079474415e-05, -2.990784032152682e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.521005506205125e-03, -7.290079117499959e-03, -5.043883961938334e-03, -1.056600879901133e-03, 4.974740492695653e-03, 8.300391935132495e-03, -1.551287009850630e-02, -7.209650823480832e-02, 7.904903083100662e-02, -2.709337213579074e-01, 4.752984563783126e-01, -3.582325077831447e-01, -4.206596689974779e-01, -2.409599820440111e-01, -3.822615174493139e+00, 1.424198835037524e+01, -6.211724977339935e+00, -4.617853020793264e+01, -7.028685419871029e+03, -6.042207919017926e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.167045682559646e-08, 1.343021694826687e-08, 1.634335712035236e-08, 2.137580451013938e-08, 3.042458044036670e-08, 4.724747082710661e-08, 8.556873755577180e-08, 2.945098927055870e-07, 1.105371878532686e-06, -7.718071680374292e-07, -8.704006256249287e-05, 6.266940414649695e-03, 2.007138875384928e-02, 6.557275412395028e-02, 4.521843731225123e-02, -2.427300266050491e+01, -1.976984921400220e+03, -1.780121913474892e+05, -2.693453981352450e+07, -2.212646723955169e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.654879124335376e-05, 4.067822648831578e-05, -2.372698697702727e-05, -1.377287116624574e-04, -3.154345438390150e-04, -4.504245044302162e-04, 6.290429649201716e-05, 1.391454073147345e-03, -2.749625170512716e-03, 6.066736696396500e-03, -1.699006659599519e-02, 1.058756102076400e-02, 5.867407933062962e-02, -1.504843067502741e-01, 1.747830481983706e+00, -8.953578096720245e+00, 1.468141957190681e+01, -1.282744852449314e+02, -2.013436758067085e+02, -2.323830223728458e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.362003142610867e-14, 3.008114442133239e-14, 4.257169748494428e-14, 7.004439882246718e-14, 1.426527057827387e-13, 3.911728211077194e-13, 1.614930247936889e-12, 1.202694335646743e-11, 2.122637730932056e-10, 9.253270027232961e-09, 1.420023037450999e-06, 1.530584132372713e-04, 8.791478592555922e-04, 1.018819549381357e-02, 6.878531010589776e-01, 2.557850381062680e+02, 2.058682018093989e+05, 5.513859229878328e+08, 9.792339323503266e+12, 6.237864394797665e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.851290151396563e-11, -2.338584692945158e-11, -3.028125485646200e-11, -3.737353416794683e-11, -2.962721765082843e-11, 6.902749327153769e-11, 4.518397512873599e-10, -5.072864575417700e-10, -4.834307397509227e-09, 4.294596992796180e-09, -6.379754669639136e-07, -1.097017179838487e-04, -1.259181934204487e-03, -7.863983098863324e-03, 7.316017237148112e-02, 1.873052910935977e+00, -8.783791542116326e+01, -3.338310321260844e+03, -2.745382413248418e+04, -3.150178571305948e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_pi_m06_2x_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.658005920896562e-06, -7.512681810859407e-07, 8.588061031447444e-07, 3.672277804667291e-06, 7.969579385776916e-06, 1.092285323236156e-05, -2.691561681770739e-06, -3.465130153576249e-05, 7.264523152602983e-05, -1.594156345745289e-04, 5.484740805089853e-04, -4.988766471891802e-04, -1.478891947084759e-02, 1.264392999964285e-01, -1.186284406487872e+00, 5.667506432082775e+00, -8.704737942586634e+00, 1.269051139786241e+02, 2.152675969250325e+02, 2.651072459887440e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
