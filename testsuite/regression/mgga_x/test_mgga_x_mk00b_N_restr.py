
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mk00b_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.275020163556745e+00, -1.704937629603824e+00, -2.230142673233955e+00, -2.818358024996277e+00, -3.383297100542505e+00, -3.767906143494883e+00, -3.765533882486654e+00, -3.224051485237371e+00, -2.228571420395630e+00, -1.189119385721731e+00, -5.359162394861556e-01, -3.475061920471610e-01, -5.050719834619091e-01, -4.911622527357019e-01, -2.783045526900205e-01, -1.090788051220423e-01, -6.192715454760284e-02, -6.017616681578462e-02, -5.242945321050282e-02, -3.995929239854035e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mk00b_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.545594880425512e+00, -4.830770730173415e+00, -6.399727413375429e+00, -8.154633852735980e+00, -9.835092483655943e+00, -1.096752001985066e+01, -1.092809124242483e+01, -9.254486782621596e+00, -6.195951992116207e+00, -3.001161471051867e+00, -1.147964076333211e+00, -9.735031154767159e-01, -1.488125093034845e+00, -1.413073509731673e+00, -7.356068918609509e-01, -1.849960689546882e-01, -6.080510682287814e-03, 4.730980189914238e-04, -7.549938414992186e-03, -5.792508484966504e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.816283328058031e-06, -1.965598908144313e-06, -2.201630783038815e-06, -2.590376733849916e-06, -3.269365541003770e-06, -4.558899612358294e-06, -7.317243164019059e-06, -1.429281760099018e-05, -3.652588686667068e-05, -1.325309736473580e-04, -7.057664881432759e-04, -3.332732752057388e-03, -6.115251522971678e-03, -1.345736112735744e-02, -5.490661695419064e-02, -4.283950736972650e-01, -6.270156933814542e+00, -1.837304379158162e+02, -1.698063319224777e+04, -1.004032042500273e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.329326321385070e-04, -8.446769115471888e-04, -1.606337474704498e-03, -2.944492336989487e-03, -5.119269326902897e-03, -8.245633626934938e-03, -1.188524395367305e-02, -1.456060013833982e-02, -1.406989060383674e-02, -9.865881716604243e-03, -5.798266845014523e-03, -9.385869562035193e-03, -3.208785903013932e-02, -5.642995565428639e-02, -5.095861634153937e-02, -2.345163699241189e-02, -4.982224097268282e-03, -4.062845566906168e-04, -8.886121703191007e-06, -2.962470687596100e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.463461057108056e-03, 6.757415292377510e-03, 1.285069979763598e-02, 2.355593869591590e-02, 4.095415461522318e-02, 6.596506901547951e-02, 9.508195162938436e-02, 1.164848011067186e-01, 1.125591248306939e-01, 7.892705373283394e-02, 4.638613476011618e-02, 7.508695649628154e-02, 2.567028722411146e-01, 4.514396452342911e-01, 4.076689307323150e-01, 1.876130959392951e-01, 3.985779277814626e-02, 3.250276453524934e-03, 7.108897362552805e-05, 2.369976550076880e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.144355488821638e-02, -5.934471260177372e-02, -8.518232917555210e-02, -1.225298765959486e-01, -1.766130546224533e-01, -2.550650370383136e-01, -3.688860034709630e-01, -5.333121109645198e-01, -7.680494108211602e-01, -1.101577969438138e+00, -1.659438298172542e+00, -3.269393753488815e+00, -7.318229123138039e+00, -1.354181757822878e+01, -2.333674803342721e+01, -3.978523422914645e+01, -5.853212242223062e+01, 4.429002150568302e+02, 3.023192271126706e+04, 1.123145385913567e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.171894573909644e-08, 1.343292044357936e-08, 1.633918747236201e-08, 2.163358403147340e-08, 3.232156159413584e-08, 5.730435364612033e-08, 1.292154314133537e-07, 4.065565251173100e-07, 2.005568930374304e-06, 1.761730352837152e-05, 3.119766582182681e-04, 5.863860340442252e-03, 1.767088042236179e-02, 6.636567185218858e-02, 7.018903774426813e-01, 1.968962151267665e+01, 5.133759338478851e+02, -1.160779303059068e+06, -1.066315395543044e+10, -3.432176190164362e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.252342374047113e-06, -1.504306383038763e-05, -3.123786274085724e-05, -6.496866692557369e-05, -1.353913426546671e-04, -2.827213376638838e-04, -5.907614105563294e-04, -1.229209844982934e-03, -2.518227504485124e-03, -5.021036864296071e-03, -1.082726288910228e-02, -4.546442224405847e-02, -2.341186527047677e-01, -7.925874489603226e-01, -2.281782802308796e+00, -6.043576731172829e+00, -1.521987865070273e+01, -3.787009513506938e+01, -9.333635357199655e+01, -2.301962821142003e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.801873899237691e-05, 1.203445106431010e-04, 2.499029019268579e-04, 5.197493354045895e-04, 1.083130741237337e-03, 2.261770701311070e-03, 4.726091284450635e-03, 9.833678759863474e-03, 2.014582003588099e-02, 4.016829491436857e-02, 8.661810311281820e-02, 3.637153779524677e-01, 1.872949221638142e+00, 6.340699591682581e+00, 1.825426241847037e+01, 4.834861384938263e+01, 1.217590292056218e+02, 3.029607610805550e+02, 7.466908285759724e+02, 1.841570256913603e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.935248073203771e-14, 2.429046711656731e-14, 3.366176016980552e-14, 5.375075130642448e-14, 1.050754754765672e-13, 2.739036809128262e-13, 1.072697039539955e-12, 7.436188254732261e-12, 1.135493276372470e-10, 4.973740138404195e-09, 7.291335517575393e-07, 1.052010033781924e-04, 8.022119406838065e-04, 6.554149190083000e-03, 3.682396668313143e-01, 1.573053205598256e+02, 5.422902133299507e+05, 1.976707063693170e+10, 2.448590334880862e+16, 8.057067295818427e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.731470113356202e-09, -5.172517867059025e-09, -1.547816672743466e-08, -4.642516816754188e-08, -1.396638130074324e-07, -4.214396887319324e-07, -1.272962852290336e-06, -3.820644211920167e-06, -1.120314602244488e-05, -3.154188667034194e-05, -9.987931946709565e-05, -8.594192295075723e-04, -1.004272513333207e-02, -6.255590885513616e-02, -3.055687980272394e-01, -1.317160240355821e+00, -5.263981286909566e+00, -2.066056273268561e+01, -7.994177686628699e+01, -3.096314094370908e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.385176090684961e-08, 4.138014293647220e-08, 1.238253338194773e-07, 3.714013453403350e-07, 1.117310504059459e-06, 3.371517509855459e-06, 1.018370281832269e-05, 3.056515369536134e-05, 8.962516817955903e-05, 2.523350933627355e-04, 7.990345557367652e-04, 6.875353836060578e-03, 8.034180106665655e-02, 5.004472708410893e-01, 2.444550384217915e+00, 1.053728192284657e+01, 4.211185029527653e+01, 1.652845018614849e+02, 6.395342149302959e+02, 2.477051275496726e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mk00b_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mk00b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.108140872547969e-07, -3.310411434917776e-07, -9.906026705558184e-07, -2.971210762722680e-06, -8.938484032475672e-06, -2.697214007884367e-05, -8.146962254658154e-05, -2.445212295628907e-04, -7.170013454364723e-04, -2.018680746901884e-03, -6.392276445894122e-03, -5.500283068848463e-02, -6.427344085332524e-01, -4.003578166728714e+00, -1.955640307374332e+01, -8.429825538277255e+01, -3.368948023622122e+02, -1.322276014891879e+03, -5.116273719442367e+03, -1.981641020397381e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
