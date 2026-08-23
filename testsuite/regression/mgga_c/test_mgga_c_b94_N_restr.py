
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_b94_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.001802199773095e-01, -9.519282536069729e-02, -8.882586555863375e-02, -8.103092695567000e-02, -7.196943170243431e-02, -6.206118905508311e-02, -5.194054084991863e-02, -4.218821992724021e-02, -3.286463165810119e-02, -2.437290813609540e-02, -2.285255657905252e-02, -6.103795149676180e-02, -5.335688455871726e-02, -3.301715435715685e-02, -1.786721358496236e-02, -7.702379663014966e-03, -1.866856851983629e-03, -1.731571937566425e-04, -3.952148707753116e-06, -1.258977133121685e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_b94_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.600699207983607e-02, -8.489680494229739e-02, -7.216268575117094e-02, -5.915390098674076e-02, -4.849147481272170e-02, -4.406720020035506e-02, -4.875273941782944e-02, -5.752768704806020e-02, -5.981854643334112e-02, -5.395068542035686e-02, -4.925557672382018e-02, -1.582545398402175e-02, -1.444837209738369e-02, -3.353334797346947e-02, -3.560655521327868e-02, -2.180498476781290e-02, -7.539018681273523e-03, -1.028032899297014e-03, -3.689425318860062e-05, -2.019810079549088e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.387477676098253e-07, 3.576997943128811e-07, 3.959345388052396e-07, 4.740934820443863e-07, 6.365019577232457e-07, 9.771565258541513e-07, 1.674485980440761e-06, 3.072460963903048e-06, 6.469512141128382e-06, 1.904489915690096e-05, 1.196172243368218e-04, 4.006986111325057e-03, 5.767328805461011e-03, 1.259723136603548e-02, 2.869653915888724e-02, 1.152614832899571e-01, 6.362334712724318e-01, 3.636657384043077e+00, 1.921193828710692e+01, 9.422545197832974e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.489538451093123e-06, 8.701179850780062e-06, 1.646249051943619e-05, 3.015892376119540e-05, 5.277419632959835e-05, 8.559881279567956e-05, 1.203565219148035e-04, 1.353212948633672e-04, 1.257622105164456e-04, 1.169940551853614e-04, 2.136507842132045e-04, 3.814033285025692e-03, 2.381037132931874e-03, 3.285463315257703e-03, 2.006225509227408e-03, 1.038808971996317e-03, 3.313760432800017e-04, 3.836378438976919e-05, 9.997701182692196e-07, 3.409127836302372e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.853216964069785e-04, -4.820413090225919e-04, -4.886412306671747e-04, -5.156816752280431e-04, -5.776011762283417e-04, -6.839759411105406e-04, -8.085162240696306e-04, -8.734757675815042e-04, -8.675180737919635e-04, -8.981159587466179e-04, -1.537391511931484e-03, -1.985326395706624e-02, -1.897101985360872e-02, -2.152528279224126e-02, -1.538098291754725e-02, -1.073432075961465e-02, -4.998501454279282e-03, -9.363701218125665e-04, -4.389791078994478e-05, -2.910283036173254e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.884551670554483e-04, 5.784683228554295e-04, 6.737118662193183e-04, 7.518614882751245e-04, 7.716992025777371e-04, 7.167624010589452e-04, 8.612988332247118e-04, 1.535561776074958e-03, 1.415274125779726e-03, -1.433468761000741e-03, -6.744963854810951e-03, -2.147299656520771e-03, -1.182589612903595e-02, 1.270807227214531e-01, 3.594460965931781e-02, -1.500003236470949e+00, -1.385091123542176e+01, -9.119056360910697e+01, -4.913396239407160e+02, -2.389880364292135e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.472147376676705e-09, -3.892613728260827e-09, -4.555856808351329e-09, -5.755052828727751e-09, -8.548665898615983e-09, -1.735181584055424e-08, -4.652897032494803e-08, -1.008415993702524e-07, -5.579973519010416e-08, 1.749024622140196e-06, 4.655755448652796e-05, -1.578766889145778e-02, -2.331572613673210e-02, -9.873060872753928e-02, 8.263449339970144e-02, 1.167875452860246e+01, 1.359969093165310e+03, 3.184955436046000e+05, 2.206657912595412e+08, 8.682651731235537e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.222308441430768e-08, 1.189237142722091e-07, 2.181541076678321e-07, 3.698709918817513e-07, 5.144023490457786e-07, 2.990606041066659e-07, -8.388007935085945e-07, -1.248715521908111e-07, 9.434390744168785e-06, 4.287747291130858e-05, 2.714290586254734e-04, -1.005378412231687e-02, 5.129583027541503e-04, -1.010468006571171e-02, 5.128512432061109e-02, 2.899355652940748e-01, 1.763368401789876e+00, 9.780796315779879e+00, 4.736984032625205e+01, 2.139142386663308e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.264540545761539e-06, 2.384143037925229e-06, 2.455118485894552e-06, 2.467146860920019e-06, 2.665571598252991e-06, 4.328421751743312e-06, 9.070366180931381e-06, 4.088762254103525e-06, -4.427372786620690e-05, -2.348393845360153e-04, -1.555323098154939e-03, 4.616668265338359e-02, 3.055599168751733e-02, 6.792622470220414e-02, -2.738633591126782e-01, -2.009736182569265e+00, -1.577432213622599e+01, -1.110998050478800e+02, -6.579011244048774e+02, -3.435560350538461e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.405127583860149e-16, -1.375166844851327e-15, -3.014946326452900e-15, -6.909293551024803e-15, -1.830337178526658e-14, -8.153159520207261e-14, -7.990246562756963e-13, -9.715358941686475e-12, -1.321044825488300e-10, -3.870530868561690e-09, -5.689822716333523e-07, -4.846133153424497e-04, -4.433285709079209e-04, -2.681190713376723e-02, -1.114860298728084e+00, -1.740041690244783e+02, -1.780017714662699e+05, -1.191476461534065e+09, -9.243417897552936e+13, -2.696665869336197e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.061913562060403e-14, -1.571015767283330e-13, -2.303829283645054e-13, -1.880847220953701e-13, 2.888586781353201e-13, -1.176119652052590e-12, -5.216382770288497e-11, -5.108177413827313e-10, -3.374023156336053e-09, -3.329843056227457e-08, -1.371139773585679e-06, -4.766239045629687e-04, 1.153732052094407e-04, -7.655922313268916e-03, -1.103536602432827e-01, -2.663611315341735e+00, -2.088116276299192e+02, -4.263567258944449e+04, -2.795942422219619e+07, -1.071623964545947e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.176584119316203e-13, 1.853194317010905e-12, 3.720885497382949e-12, 7.515387171471819e-12, 1.660960967022100e-11, 5.706931088633462e-11, 3.858046024730004e-10, 2.761997860548638e-09, 1.771432277118450e-08, 1.825258045862143e-07, 7.312897617365427e-06, 2.401095436645036e-03, 1.458282578306001e-03, 4.581434336513913e-02, 5.975510536390832e-01, 1.620503667404825e+01, 1.398452225028342e+03, 3.067825317608315e+05, 2.112055161728615e+08, 8.329024450380408e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.725547832574677e-11, 5.023077687119706e-11, 1.448442225853479e-10, 4.086236163549234e-10, 1.073100684102967e-09, 2.085037964269949e-09, -9.507816106044112e-10, -2.353482196925412e-08, -7.775618558583224e-08, -2.471707664054568e-07, -2.936994705016704e-06, -4.372167012764929e-04, 4.895581668074539e-04, -1.648181831091471e-03, -9.556595683991099e-03, -2.970767139539693e-02, -1.335787466278708e-01, -5.520207064870579e-01, -1.780798892049979e+00, -4.709540924696998e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.298294389853567e-10, 2.117123098745705e-10, 2.843262878263696e-10, 2.045837967581691e-10, -2.621281996547604e-10, 8.232432825110569e-10, 2.518701350742506e-08, 1.452213466633358e-07, 4.524338165943399e-07, 1.570281451364811e-06, 1.762270159058840e-05, 2.361510602393136e-03, -3.795079906889090e-04, 1.308191363960054e-02, 5.914816952988145e-02, 2.480625567336295e-01, 1.640506624543255e+00, 1.097787493298432e+01, 6.388529319125847e+01, 3.309858408418199e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b94_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.314723165094802e-09, -2.497390908935717e-09, -4.592117863976523e-09, -8.174648235744126e-09, -1.507258534840939e-08, -3.994655368840764e-08, -1.862836022897299e-07, -7.852136217986207e-07, -2.375371563381404e-06, -8.607519348431181e-06, -9.398969744443997e-05, -1.189661759872121e-02, -4.796866743407991e-03, -7.828439981934075e-02, -3.202798252951941e-01, -1.509177711542685e+00, -1.098679305030011e+01, -7.899066816008165e+01, -4.825895632572681e+02, -2.572534071939407e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
