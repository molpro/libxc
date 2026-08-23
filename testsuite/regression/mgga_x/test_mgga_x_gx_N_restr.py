
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_gx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.129842886902600e+00, -5.026080343156289e+00, -4.880643851254769e+00, -4.679091295462356e+00, -4.404258675192446e+00, -4.038042836785150e+00, -3.565656255158056e+00, -2.983050031835660e+00, -2.305170110927043e+00, -1.556599818565328e+00, -8.205377030787656e-01, -5.847838582685155e-01, -5.910368739986942e-01, -5.071862410346800e-01, -3.415721743871917e-01, -1.754412035800065e-01, -6.854934958529529e-02, -2.046752435749028e-02, -4.152353218338864e-03, -4.582188491831881e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_gx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.628211788444942e+00, -6.486045272170116e+00, -6.286556077678696e+00, -6.009622143996043e+00, -5.631003718506716e+00, -5.124391795330446e+00, -4.466561868942470e+00, -3.646971656352423e+00, -2.683567434183884e+00, -1.660995421557503e+00, -1.112026488306432e+00, -8.337497543281219e-01, -9.315144098148922e-01, -6.881998985171716e-01, -4.070212306306656e-01, -5.831422951832956e-02, -5.747822188627560e-02, -2.147006427434360e-02, -5.315252700189000e-03, -6.096477434913299e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.132259287427417e-06, -6.653907056597179e-06, -7.482006518109594e-06, -8.854543891955118e-06, -1.127494740729433e-05, -1.594074428816372e-05, -2.616205315138919e-05, -5.306409205622100e-05, -1.450979852311692e-04, -6.058221580801400e-04, -5.386309269381195e-04, -1.216807272819295e-03, -2.576669636895570e-02, -5.153529332421868e-02, -2.451881769297512e-01, -3.491807107562992e+00, -7.440894406694450e+00, -3.920106489127348e+01, -1.706738977824549e+02, -7.614506357368488e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gx_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.785647507527371e-03, 8.966899390697419e-03, 9.233892258809204e-03, 9.631277797563469e-03, 1.023158343088322e-02, 1.115797243125266e-02, 1.263220156809099e-02, 1.508569159522960e-02, 1.945666410587864e-02, 2.856925331300244e-02, 6.922804134015859e-03, 6.028869404833247e-03, 8.475683021826472e-02, 8.805996574579271e-02, 1.314177692320474e-01, 3.251925660976576e-01, 5.845860551570194e-02, 1.009352876311245e-02, 3.899777017321763e-04, 2.351845304576456e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.589812013189741e-02, -1.668979140107490e-02, -1.790392184441309e-02, -1.982044213504176e-02, -2.297655346121667e-02, -2.851047194635713e-02, -3.916934640310377e-02, -6.282525624965382e-02, -1.274880069629650e-01, -3.517739344069819e-01, -3.576860016394178e-01, -6.389188162723072e-01, -4.094058994048830e-01, -1.702876858520677e+00, -5.976300490051863e+00, 4.677948989708703e+01, -5.331572437751591e+02, -5.484314158786268e+03, -4.963935748501240e+04, -9.096022017922123e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.495909940443113e-08, 5.183175744107641e-08, 6.358231111084471e-08, 8.525485862189407e-08, 1.298328367413826e-07, 2.370948971310140e-07, 5.604199663389984e-07, 1.905902347959872e-06, 1.070763453811538e-05, 1.063563306356957e-04, 3.027594374400370e-04, -1.766443927199662e-03, 1.550605228174717e-01, 3.299661320849749e-01, 4.001042335137800e+00, -1.777244502687873e+03, 9.573250218010297e+04, 3.301978048304644e+07, 3.241599594933850e+10, 2.191954441610329e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gx_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.535453141558175e-05, -1.661795398312079e-05, -1.861383543709337e-05, -2.189719189027269e-05, -2.761875312058769e-05, -3.843231451547986e-05, -6.129923242369587e-05, -1.173198648031513e-04, -2.750379060596804e-04, -1.689556122047091e-04, 4.178035594628830e-04, 1.848659172575113e-02, -3.039216653816439e-01, -1.515410919549073e-01, -1.830027940155030e-01, 1.934495275985855e+02, -6.925851949691189e+02, -8.188357052001041e+03, -7.270285102660903e+04, -6.709237547290169e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.019274744748220e-14, 2.580689231061269e-14, 3.671428411714478e-14, 6.091762923386753e-14, 1.260160776273241e-13, 3.575098627548154e-13, 1.594763404069137e-12, 1.366135797906340e-11, 3.104483637206938e-10, 4.483702226340902e-08, -4.322626484819870e-06, -9.876358225438155e-05, 1.284259330292077e-02, 3.561598044398516e-02, 4.449293963181606e+00, 4.329139507831850e+04, -1.878379718835686e+07, -2.114700044879317e+11, -2.439482015894606e+16, -1.258116711970758e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gx_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.893001632299318e-11, -3.477773358832716e-11, -4.531080574127605e-11, -6.626141527780069e-11, -1.143547694991892e-10, -2.502446009049352e-10, -7.700226223470754e-10, -3.883813427464805e-09, -4.162903796017450e-08, -2.114416301482675e-06, 5.555695932468306e-05, 4.893402206460997e-04, -4.224435622446832e-02, -6.085813848324897e-02, -2.384765426378895e+00, -4.031734692610573e+03, 1.475729300678135e+05, 5.444950484775255e+07, 5.574042676333321e+10, 3.885866979143433e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_gx_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_gx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.144784391650523e-08, 4.686696635081764e-08, 5.592017293249945e-08, 7.207396626945869e-08, 1.037725784949935e-07, 1.751626089404349e-07, 3.718011320132862e-07, 1.104136701671442e-06, 5.582174055356868e-06, 9.971126694611493e-05, -7.140509919707092e-04, -2.424515657251288e-03, 1.389583544947975e-01, 1.039902025292074e-01, 1.278204179340259e+00, 3.754761102568523e+02, -1.159391228004673e+03, -1.401971208798372e+04, -1.273629055477631e+05, -1.200203608768872e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
