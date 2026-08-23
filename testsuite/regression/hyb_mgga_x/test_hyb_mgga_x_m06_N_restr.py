
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m06_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.095024265669367e+00, -3.011249031471733e+00, -2.895095630883453e+00, -2.741245697787575e+00, -2.555380761721924e+00, -2.365193280229547e+00, -2.195741845946331e+00, -1.949060842918751e+00, -1.541491725072539e+00, -1.221773204469440e+00, -7.494538809289447e-01, -4.414851660427852e-01, -4.127635139310366e-01, -3.442047276875221e-01, -2.598380102059255e-01, -1.682818486208101e-01, -1.745457375018222e-01, -9.935646192272857e-02, -2.232158457613944e-02, -2.477980731915558e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m06_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.971275688204489e+00, -4.855167495745633e+00, -4.623343482565987e+00, -4.188666775555022e+00, -3.463868229418477e+00, -2.529715172224353e+00, -1.960721958282428e+00, -2.233776549013635e+00, -1.657675259150500e+00, -1.013164577166511e+00, -7.961639430763197e-01, -7.397751446595666e-01, -5.915305476954296e-01, -4.530717260047440e-01, -2.189741075191436e-01, -1.190370156106970e-01, -2.661037230689441e-02, -1.146232025837009e-01, -2.956941008589701e-02, -3.303697662301478e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.879558843246079e-06, -2.022193921428164e-06, -2.247155426822035e-06, -2.623298185346368e-06, -3.317729564070390e-06, -4.805034486862421e-06, -8.545147866711868e-06, -1.889435370503219e-05, -5.352580244978778e-05, -2.430154906636357e-04, -1.661024935135010e-03, -8.714932915261514e-03, -9.194065538346554e-03, -1.982043549922385e-02, -9.846322638078754e-02, -8.503936342981838e-01, -7.928766362739174e+00, -2.327856554114884e+01, -3.025898434501638e+01, -3.334972272394921e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.489084913820492e-02, 2.486613391677466e-02, 2.310291854355625e-02, 1.764589488967716e-02, 6.166535288931500e-03, -1.021064402858134e-02, -1.778300670195924e-02, -8.970331700258924e-04, 6.803484642592896e-04, -3.132069497202948e-04, 1.322047793970946e-02, 2.262808227914083e-02, 2.625558754643696e-02, 2.775154690336353e-02, -1.425823149276173e-02, 3.649336111372002e-02, -6.871845575653948e-02, -6.558000986443662e-03, -7.841557498665266e-05, -1.220946983572523e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.156977893209964e-03, -1.926826051499894e-02, -3.532803750510907e-02, -5.662417669938845e-02, -7.740673853232384e-02, -7.245845290199811e-02, 5.055487803529041e-03, 5.704448213658537e-02, -1.710556375211643e-01, 4.987046189214484e-02, -7.689301559637145e-01, 2.577640641216420e-01, -4.635809657548139e-01, -1.570289808561933e+00, -8.298653581321446e-01, -2.936228956151527e+01, 3.346122634011051e+02, 6.892016657375260e+02, -3.205216285522954e+04, -2.849730145018898e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.246430303596861e-09, 1.048390443072969e-08, 1.308088862443361e-08, 1.931055955789652e-08, 3.645461077848333e-08, 8.873519028428111e-08, 2.480041564827682e-07, 6.920555893632140e-07, 3.720499068115491e-06, 3.672386540648262e-05, 6.026480412237651e-04, 2.430044667162655e-02, 3.701189048897936e-02, 1.284936653024361e-01, 1.744892907468553e+00, -5.568415249991171e+00, -1.783374214397644e+04, -2.910554483376284e+06, -4.605249422704143e+08, -3.774240866478392e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.778732960214007e-05, 2.137642217150919e-04, 5.953229084909984e-04, 1.106576923846339e-03, 1.608891096404029e-03, 1.464839275474634e-03, -5.868219612546736e-04, -2.282911969208387e-03, 2.780368367025085e-03, -5.195842471375995e-03, 1.186697057447347e-02, -8.352678780373872e-02, -4.603397808022556e-02, 3.023885787152180e-01, -1.310055269875411e+00, 1.842275126278283e+01, -6.209984767608179e+01, -5.097839266973746e+02, -7.363184075949632e+02, -8.518115527691347e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.826925494062753e-14, 3.574274120136723e-14, 5.007505632176312e-14, 8.146805098214165e-14, 1.655054427463525e-13, 4.702296486400238e-13, 2.175860015294694e-12, 1.872764502990471e-11, 3.593080162611570e-10, 2.247792383666930e-08, 4.279794396863850e-06, 3.792082529127009e-04, 1.391539714238780e-03, 1.636757013689259e-02, 1.498275853156457e+00, 9.167637908727348e+02, 2.472773232139021e+06, 9.784094577859261e+09, 1.813679137727248e+14, 1.154014892967391e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.156569558990100e-11, 5.855314974081500e-11, 5.735418694199121e-11, 1.727319428457359e-11, -1.748847168464754e-10, -9.056312207724545e-10, -3.137489521668944e-09, -7.852494500698347e-09, -5.914953851220358e-08, -9.849665257186557e-07, -2.612433409205269e-05, -8.942169737252006e-04, -4.358280485547722e-03, -2.853460856467781e-02, -8.534323048284700e-01, -4.657027043515000e+01, -6.072677524169831e+03, -4.072131012970081e+05, -6.187183964382788e+07, -5.462540532312807e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.171452677076896e-08, -6.554371663779024e-06, -1.592449108284690e-05, -2.830420294832395e-05, -3.995359769767504e-05, -3.447477339861715e-05, 1.957278099448902e-05, 6.154822820156667e-05, -5.952551330791657e-05, 2.006147252591033e-04, -1.509484668899509e-04, 7.186688515056566e-03, 1.452832472482786e-02, -1.571624175670144e-01, 1.418837549806502e+00, -7.350847286312085e+00, 1.348901196504583e+02, 6.612563459354312e+02, 1.014334689375142e+03, 1.248069310745092e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
