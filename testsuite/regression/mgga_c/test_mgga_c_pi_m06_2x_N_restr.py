
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_pi_m06_2x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.627706549189381e-02, -6.596196750334941e-02, -6.548386498006600e-02, -6.474019040950948e-02, -6.354141740007536e-02, -6.151412411304775e-02, -5.790002773277148e-02, -5.134544539581593e-02, -4.131461690548747e-02, -3.618685996017330e-02, -3.784967065456954e-02, -8.945975170189796e-02, -4.135362990982250e-02, -3.096278816594220e-02, -2.522186130699140e-02, -1.770414436219777e-02, 1.132175686842674e-03, 1.493106521879500e-02, 4.668588518355958e-03, 5.733050067314813e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_pi_m06_2x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.193882875876691e-02, -1.491371435585119e-02, -1.915988910140213e-02, -2.521010485173731e-02, -3.385269798285300e-02, -4.642211595331884e-02, -6.564999663308363e-02, -9.638784998644030e-02, -1.328361391031627e-01, -1.144535785867507e-01, -7.561620244694811e-02, -1.905103413199005e-01, 2.340045299712633e-02, -3.378198434005947e-02, -5.454835979858532e-02, -1.582593776757050e-02, -1.744258214042476e-02, 3.449310879674154e-02, 1.374971711547929e-02, 1.911601039643389e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.661866183346828e-06, -1.687984226739279e-06, -1.721597628525628e-06, -1.759444734090136e-06, -1.782072121025454e-06, -1.698920525892806e-06, -1.062759868686897e-06, 2.511424650341274e-06, 2.023922075980414e-05, 7.005158419711044e-05, 7.644279116538310e-05, 1.636631678055154e-02, 1.474341863540747e-03, 3.741212380240912e-03, 5.567099518242631e-02, 2.214061959527955e-02, -2.646854268370363e+00, -1.263449781303301e+02, -5.632898442113209e+03, -6.498692282450764e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.324227507253443e-03, 2.232563654328910e-03, 2.105343090311729e-03, 1.931329051092763e-03, 1.696256091977364e-03, 1.373489555833919e-03, 8.756704879267658e-04, -8.487429764341428e-05, -1.863074623414329e-03, -2.605457619533505e-03, 1.539284758981952e-04, -9.908511821893895e-03, -2.939082142304783e-02, -6.557355011016472e-03, -2.066918952031400e-02, -6.064496766485912e-03, 4.453517216448914e-02, 3.510688904099308e-02, 1.250088065776597e-02, 1.972469307121421e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.653936713749926e-03, 1.731673278987405e-03, 1.850887288575234e-03, 2.046402712926373e-03, 2.413511388074097e-03, 3.273679874052864e-03, 5.831400886127215e-03, 1.411511398067193e-02, 3.240004672327067e-02, 1.234688950978890e-02, -4.717987929767203e-02, 3.845886530048052e-01, 6.846223086665202e-01, -1.684239233519772e-02, 2.200538816725258e+00, -8.318970122662945e+00, -6.795853943642808e+01, -5.347740055468074e+02, 1.940544360242163e+04, 2.475452348042644e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.656676718145646e-08, -2.929727989460232e-08, -3.373017171873473e-08, -4.153040628549813e-08, -5.759348753076625e-08, -1.018214423018857e-07, -2.847898137375272e-07, -1.358054746324138e-06, -8.070485701298900e-06, -2.546344326017817e-05, 1.860749565106932e-04, 2.785357389144628e-03, -2.000090983561381e-01, 8.544074789180792e-02, -4.220224040455438e+00, 5.896706517625885e+01, 4.536281608256160e+03, 1.010023398533904e+06, -5.023325708806461e+09, -5.192315925483765e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.999972405305994e-05, 2.022577896489855e-05, 2.050943233773306e-05, 2.099248914859872e-05, 2.257224350779339e-05, 3.009629317575394e-05, 6.754121533049490e-05, 2.367193735863618e-04, 7.891757677292254e-04, 1.282361755886018e-03, -8.785861211830488e-04, -3.968544024129985e-02, -5.487356835536210e-02, -1.354091443568983e-01, 1.344877225416600e+00, -1.973203705675839e+00, -2.540802414772505e+00, 2.872922392529460e+02, 1.208254481746909e+04, 1.577123242277000e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.666769845988169e-13, 3.057463960674608e-13, 3.715638635639924e-13, 4.945338176534300e-13, 7.819659476108921e-13, 1.845817875453437e-12, 9.296368688200621e-12, 9.844080279285794e-11, 1.587653689815571e-09, 2.940424970096725e-08, -4.363340073879469e-07, -5.896295398091365e-03, 3.178629702116009e-02, -1.189650392054073e-01, 7.703311793911483e+00, 3.148104909054671e+02, -4.088511465980028e+05, -4.996007850253486e+09, -8.174341878354067e+13, -2.245828973120370e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.005852200335461e-10, 4.502302686467381e-10, 5.320704124895775e-10, 6.721420045670787e-10, 9.139398648581572e-10, 1.256450217933757e-09, 7.907185827803520e-10, -1.192209624273195e-08, -1.640568216057849e-07, -1.732919261239999e-06, -3.027418796201092e-06, 2.603217274825010e-03, 4.338375185044761e-02, 1.214942485886815e-01, -3.239879778638803e+00, -8.231304294035979e+01, 4.294517360760607e+03, 6.000969206223641e+06, 3.158123864070961e+10, 2.880278143583823e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_pi_m06_2x_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_pi_m06_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.584426009773350e-06, -1.646649906221950e-06, -1.739377125778383e-06, -1.878556467432863e-06, -2.085510458149020e-06, -2.364132637715352e-06, -2.505930892739599e-06, -6.955347415916311e-07, 1.470119125284673e-05, 8.569710230592654e-05, 6.193275697138216e-05, 1.390541646689199e-03, -9.271271693471188e-03, -1.024823837026546e-01, 1.399136964960128e+00, 1.201602142593488e+01, -6.384109111535815e+01, -2.992134641522351e+03, -1.397739012485723e+05, -1.748411147484272e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
