
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_sregtm_v2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.654456665137251e+00, -4.561794241986298e+00, -4.432018871879482e+00, -4.252390129499654e+00, -4.007927729348585e+00, -3.683221337126170e+00, -3.266684917666492e+00, -2.758102011704934e+00, -2.177944876323393e+00, -1.568784341038653e+00, -9.972504937544440e-01, -6.678969073637724e-01, -5.602931306437209e-01, -4.779073581222549e-01, -3.429367262825015e-01, -2.093289670013864e-01, -1.087746829215935e-01, -4.828816056074503e-02, -1.774529397069893e-02, -4.666581678185211e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_sregtm_v2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.061464719311410e+00, -5.932223624534872e+00, -5.750838253373718e+00, -5.498996169966048e+00, -5.154692767269373e+00, -4.694326126823673e+00, -4.098266595729806e+00, -3.362548846148237e+00, -2.520638274856675e+00, -1.679106627290294e+00, -1.082014494080491e+00, -7.612381713955232e-01, -7.446776293902613e-01, -5.847150536620807e-01, -3.777290418823088e-01, -2.057505026181839e-01, -9.238417786956934e-02, -3.246334074135492e-02, -9.883714843649789e-03, -2.420244623168666e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.461321115915729e-06, -2.725789629898014e-06, -3.151808894887489e-06, -3.871670161229556e-06, -5.172182041994647e-06, -7.749088974265801e-06, -1.353623133463271e-05, -2.886444960060282e-05, -7.883586275608030e-05, -2.820584238648322e-04, -7.755261530989414e-04, -8.848263631635547e-04, -1.336978103990844e-02, -4.965402493725724e-02, -1.366672115977394e-01, -6.324329510557951e-01, -5.556916181632127e+00, -1.106056734525991e+02, -5.835957036873512e+03, -1.268539878334478e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v2_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.072637255394452e-03, 2.159199772392670e-03, 2.286215059613487e-03, 2.473926060788642e-03, 2.753760771928156e-03, 3.174861680695432e-03, 3.813270907834353e-03, 4.779563043550977e-03, 6.183462189834100e-03, 7.549931472369687e-03, 1.368195923661116e-03, -1.030317236067420e-02, 1.338434287099605e-02, 4.743296184560938e-02, 4.065421664115360e-02, 3.054213447512044e-02, 2.260264423014159e-02, 1.496466209596022e-02, 7.362241342178702e-03, 2.256545255722762e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.033062200723389e-02, -1.075484395017283e-02, -1.139722745288754e-02, -1.239193324468262e-02, -1.398162241974611e-02, -1.663529248888089e-02, -2.132247129246292e-02, -3.014056463846236e-02, -4.768438566760509e-02, -8.980741531149289e-02, -1.937072911754729e-01, -5.357997946945414e-01, -7.813042359178259e-01, -1.322190499242161e+00, -2.123772688100445e+00, -6.203845181030959e+00, -7.645692966144651e+01, -1.452684274860393e+03, -5.932147507119953e+04, -1.063272831377819e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.232165953272107e-08, -8.218418963365475e-08, -9.863738958201420e-08, -1.278837716964147e-07, -1.847569632025002e-07, -3.102803091688185e-07, -6.411904614735774e-07, -1.758449436747333e-06, -6.963128936405085e-06, -3.383344911989527e-05, 2.572220148976335e-04, -6.321124919885211e-03, 2.715731711892662e-03, 6.869508945201115e-02, -8.614253422579562e-01, 6.463855721824813e+00, 9.097933981218426e+03, 7.658515772951031e+06, 4.196629319550329e+10, 5.981740980269621e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v2_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.412952566996656e-04, 1.517406671203989e-04, 1.679086565923898e-04, 1.936998322111837e-04, 2.365729816023371e-04, 3.118631286535868e-04, 4.536055236066777e-04, 7.419582780019482e-04, 1.350310706073128e-03, 2.066979776882612e-03, -4.004059564821657e-03, 1.784788835234290e-02, 6.782024968791664e-02, 1.313769088147815e-01, 7.189303638662599e-01, -6.106069358094324e-01, -6.868334867999292e+01, -1.989838281148194e+03, -1.022427210854205e+05, -2.027582084574586e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.900716231738038e-12, 3.529206525047078e-12, 4.672817914015063e-12, 6.976890115918335e-12, 1.234451506803539e-11, 2.771259433313915e-11, 8.657625538534576e-11, 4.249931730359951e-10, 3.776818988472903e-09, 5.705776437969330e-08, -5.516872546849492e-06, -1.448011939866803e-04, -1.536398144403937e-02, 1.672801328377296e-02, 3.725843285158781e+00, -3.062324139033432e+01, -1.573501181006310e+06, -4.500780951866559e+10, -3.030899159683458e+16, -3.370993645222098e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v2_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.386147056783277e-09, -5.012356393193619e-09, -6.064096294759998e-09, -7.950859130118714e-09, -1.166383543813284e-08, -1.997142727808410e-08, -4.209561110053456e-08, -1.158788848599862e-07, -4.275184031952387e-07, -1.156328718444896e-06, 7.726552037157751e-05, 8.738615800302027e-04, 3.265450052326863e-02, 1.146991857845518e-01, -2.313833170744303e-01, 4.892772017078890e+01, 1.669368120012328e+04, 1.473235732519631e+07, 9.286770660583366e+10, 1.472591868071686e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v2_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.434858132825474e-06, 6.907349021606349e-06, 7.637016993614042e-06, 8.796176509762759e-06, 1.070804299877120e-05, 1.401325484039538e-05, 2.002866537319627e-05, 3.129043248701471e-05, 4.902742976473642e-05, 9.940658311068035e-06, -7.950411147459674e-04, -2.020551129743370e-03, -6.633582265972796e-02, -3.004954546234105e-01, -4.192087001728434e-01, -6.416116826673230e+00, -1.427833443963330e+02, -4.100538873516389e+03, -2.378837995277864e+05, -5.269154880908421e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
