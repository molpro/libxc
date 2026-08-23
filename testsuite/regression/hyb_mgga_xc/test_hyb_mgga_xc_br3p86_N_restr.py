
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_br3p86_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.824911355315003e+00, -2.806747916124907e+00, -2.777788954266617e+00, -2.731182304208782e+00, -2.656167142840539e+00, -2.537008975955571e+00, -2.353457194167191e+00, -2.087030919957443e+00, -1.738505717794401e+00, -1.339273895227082e+00, -9.242935264403596e-01, -5.607152983301879e-01, -4.635537517740747e-01, -4.008616546715633e-01, -3.071971330717318e-01, -1.999799108558939e-01, -1.215686009986988e-01, -8.557070534674985e-02, -5.305338845561534e-02, -3.391759067006556e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_br3p86_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.942598907153943e+00, -3.970916246205682e+00, -3.994410553368817e+00, -3.995139656240126e+00, -3.934780608238604e+00, -3.742679781582660e+00, -3.332063700678730e+00, -2.717092663121271e+00, -2.054855118143556e+00, -1.441967661473124e+00, -9.671034323633301e-01, -7.905612527808313e-01, -6.876826799092698e-01, -5.654226073832449e-01, -3.792365856743385e-01, -2.225181574011250e-01, -9.201211339791851e-02, -4.597942341285422e-02, -2.705736109330745e-02, -1.352744316283511e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.194476783067444e-07, 3.364223523400608e-07, 1.287117654619613e-07, -3.833022215812426e-07, -1.647716284243059e-06, -4.735904087366025e-06, -1.171952339918626e-05, -2.552042089908271e-05, -5.535111089144151e-05, -1.549453188928394e-04, -6.563866504376931e-04, -3.510072046769988e-03, 5.720971604938098e-04, -1.411848781351449e-02, -3.948275548368096e-02, -1.799776800585746e-01, -3.556004110540717e+00, -1.166612044872430e+02, -8.203359920643192e+03, -4.463302519222969e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.544059839796289e-05, -7.203985743498328e-05, -1.451517403787740e-04, -2.881419376385057e-04, -5.558827957293386e-04, -1.007122934584722e-03, -1.585387275272439e-03, -1.968403322633398e-03, -1.977836606795653e-03, -1.901124457622496e-03, -2.313127435777667e-03, -7.739680749603631e-03, -5.115017815124437e-03, -1.102493176550648e-02, -1.027359556062499e-02, -8.751978815339550e-03, -7.567513178224217e-03, -6.132713029825704e-03, -4.680223559652975e-03, -3.446381347681729e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.417623935918516e-04, 2.881594297399331e-04, 5.806069615150961e-04, 1.152567750554023e-03, 2.223531182917354e-03, 4.028491738338889e-03, 6.341549101089756e-03, 7.873613290533594e-03, 7.911346427182610e-03, 7.604497830489984e-03, 9.252509743110669e-03, 3.095872299841452e-02, 2.046007126049775e-02, 4.409972706202593e-02, 4.109438224249998e-02, 3.500791526135820e-02, 3.027005271289687e-02, 2.453085211930282e-02, 1.872089423861190e-02, 1.378552539072692e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.915249330535681e-03, -1.143625489002606e-02, -1.351814334999854e-02, -1.618937116134544e-02, -1.911247029079132e-02, -2.150522318546494e-02, -2.589700067665133e-02, -4.205123658263391e-02, -6.820058733568589e-02, -1.247586947893642e-01, -2.986241595764255e-01, -4.993716081450410e-01, -7.648574264930817e-01, -1.082314484227051e+00, -2.449195019402672e+00, -9.756484496894545e+00, -9.183549038331564e+01, 8.542617503166666e+02, 1.279826351081710e+04, 8.560279011379534e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.182875624501034e-09, 2.666394409791398e-09, 1.204143530327316e-09, -2.065521808664531e-09, -5.226999704190422e-09, 2.500240097742607e-08, 2.869499530726611e-07, 1.166877052516996e-06, 3.131198719533811e-06, 1.693756732247698e-05, 3.266168576009439e-04, 1.227597184881515e-02, -1.860267812421600e-02, 1.450331203118456e-01, 5.675368003482810e-01, 2.642761963527910e+01, 5.563585742493028e+03, -1.824260565489589e+06, 4.473831238647765e+08, 1.012567105273272e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.602786461157464e-07, -1.171791692016355e-06, -2.434735650052971e-06, -4.916782917952215e-06, -8.977138755721628e-06, -1.128773378607944e-05, 1.479847727488144e-06, 1.366487208424226e-05, -4.897208809303134e-05, -2.519268330228863e-04, -1.179753970471028e-03, 3.701613130038954e-03, -1.876899333731089e-02, 1.572963936837711e-02, -1.007417633652083e-01, -6.966807933700246e-01, -7.874824290623195e+00, -1.944633194299469e+02, -1.587632285443524e+04, -8.144741749903030e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.241114584462986e-06, 4.687166768065418e-06, 9.738942600211886e-06, 1.966713167180886e-05, 3.590855502288651e-05, 4.515093514431776e-05, -5.919390909952577e-06, -5.465948833696905e-05, 1.958883523721254e-04, 1.007707332091545e-03, 4.719015881884111e-03, -1.480645252015582e-02, 7.507597334924354e-02, -6.291855747350844e-02, 4.029670534608333e-01, 2.786723173480099e+00, 3.149929716249278e+01, 7.778532777197876e+02, 6.350529141774097e+04, 3.257896699961212e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.000414162786208e-13, -1.248400450446217e-13, -1.766036293280474e-13, -3.094132600881826e-13, -7.492323728003264e-13, -2.504190853537206e-12, -8.059965007024457e-12, 2.618540976740687e-12, 3.535584993220681e-10, 8.173736443198160e-09, 3.965622153264705e-07, -5.684130037299720e-04, -7.305384400075110e-03, -3.370967422022061e-02, 4.378919146418867e-01, -7.136855016453646e+01, -1.452317518976763e+05, 1.264953080145673e+10, 7.188449904080562e+15, 2.028390840771358e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.133560854080058e-13, -1.389283872987494e-12, -4.893679709529143e-12, -1.822872625631626e-11, -7.096957155329321e-11, -2.613248124308939e-10, -5.697241490869455e-10, 1.475302004646369e-09, 1.843233704490052e-08, 1.633252835101204e-07, 4.177808136473706e-06, -1.335607269794125e-04, -2.214153459453716e-03, -3.702169414533018e-03, 1.867048288785891e-01, 4.631987648194758e+00, 5.604309988292886e+02, 4.243118427466848e+05, 4.019655862328683e+09, 1.566241214706655e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.653424341632023e-12, 5.557135491949976e-12, 1.957471883811657e-11, 7.291490502526503e-11, 2.838782862131728e-10, 1.045299249723576e-09, 2.278896596347782e-09, -5.901208018585475e-09, -7.372934817960206e-08, -6.533011340404814e-07, -1.671123254589483e-05, 5.342429079176501e-04, 8.856613837814865e-03, 1.480867765813207e-02, -7.468193155143565e-01, -1.852795059277903e+01, -2.241723995317154e+03, -1.697247370986739e+06, -1.607862344931473e+10, -6.264964858826620e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.480531355275436e-10, -4.680546560176983e-10, -1.509879438007024e-09, -4.956944383940350e-09, -1.610054278239439e-08, -4.572959392603867e-08, -6.877203260606163e-08, 1.048541027911072e-07, 6.179131122971887e-07, 1.925516149741640e-06, 1.342391700506086e-05, -1.654370824698891e-04, -1.820806072234824e-03, -1.581503135035478e-03, 2.501785814401772e-02, 1.078444415061331e-01, 1.100741822443306e+00, 2.731305770118442e+01, 2.296156845470418e+03, 1.209388000273132e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.922125421101745e-10, 1.872218624070793e-09, 6.039517752028096e-09, 1.982777753576140e-08, 6.440217112957756e-08, 1.829183757041547e-07, 2.750881304242465e-07, -4.194164111644289e-07, -2.471652449188755e-06, -7.702064598966559e-06, -5.369566802024344e-05, 6.617483298795566e-04, 7.283224288939297e-03, 6.326012540141911e-03, -1.000714325760709e-01, -4.313777660245323e-01, -4.402967289773223e+00, -1.092522308047377e+02, -9.184627381881674e+03, -4.837552001092528e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_br3p86_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_br3p86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.368850168440698e-09, -7.488874496283173e-09, -2.415807100811239e-08, -7.931111014304560e-08, -2.576086845183102e-07, -7.316735028166187e-07, -1.100352521696986e-06, 1.677665644657716e-06, 9.886609796755019e-06, 3.080825839586623e-05, 2.147826720809738e-04, -2.646993319518226e-03, -2.913289715575719e-02, -2.530405016056764e-02, 4.002857303042835e-01, 1.725511064098129e+00, 1.761186915909289e+01, 4.370089232189507e+02, 3.673850952752669e+04, 1.935020800437011e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
