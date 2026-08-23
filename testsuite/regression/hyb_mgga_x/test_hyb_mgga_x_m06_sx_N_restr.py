
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m06_sx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.721233124014340e+00, -2.682736981668258e+00, -2.629024531561786e+00, -2.554545462794496e+00, -2.451570057579886e+00, -2.308799567425185e+00, -2.110403126718329e+00, -1.841059165053280e+00, -1.503367473893815e+00, -1.130543102368455e+00, -6.734705923611305e-01, -3.940262891307444e-01, -3.731687687444512e-01, -3.226631545785311e-01, -2.428402551416833e-01, -1.440702164265935e-01, -8.192029671691442e-02, -4.133241865500455e-02, -9.237111456634185e-03, -1.025239022819851e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m06_sx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.772626339736445e+00, -2.708951031443736e+00, -2.627885174928322e+00, -2.530188356398435e+00, -2.419893585368642e+00, -2.298513939109462e+00, -2.143856387060294e+00, -1.892490611341800e+00, -1.480686603601266e+00, -1.033239164529534e+00, -8.055330405199417e-01, -5.908420635248227e-01, -4.834713667404955e-01, -3.657058677560494e-01, -2.297883011361419e-01, -1.652407691347170e-01, -4.408409070327049e-02, -4.844836619728572e-02, -1.224279009816267e-02, -1.366879713996978e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_sx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.325403076741569e-06, -4.691412783973063e-06, -5.271639445686539e-06, -6.230399580747575e-06, -7.909694376302640e-06, -1.109893999847377e-05, -1.786561920963968e-05, -3.453253389253619e-05, -8.439015431498547e-05, -2.748390041335880e-04, -1.315596708401910e-03, -8.235434010875599e-03, -1.539010794285215e-02, -3.312261513717847e-02, -1.214320563644224e-01, -6.158287739399885e-01, -3.063357571173078e+00, -7.826830046172849e+00, -1.010227891351322e+01, -1.118521717180907e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_sx_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.104655620825358e-02, -1.118671038470805e-02, -1.118212453052320e-02, -1.079556097258031e-02, -9.614710608916176e-03, -7.135785772035657e-03, -3.259134127058248e-03, 1.016553703429516e-03, 3.713091693820263e-03, 5.468526979062347e-03, 1.262278600397123e-02, 1.464526867634559e-02, 1.088770073295339e-02, 1.440238524340089e-02, 2.163842334211144e-02, 6.016266679345338e-02, -1.537964881921318e-02, -2.779725697795037e-03, -3.485411014245909e-05, -5.415807164955090e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_sx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.658386704119881e-03, -7.844543603475734e-03, -6.627541873126081e-03, -4.876838626613519e-03, -2.668092115146679e-03, -1.000457143043824e-03, -3.205672911868406e-03, -1.506607714531040e-02, -4.935740527778056e-02, -5.637335959834367e-03, -6.978184340614678e-02, -6.175479279625260e-02, -3.215480205955278e-01, -7.047872753682867e-01, -1.383046359287905e+00, -3.404347664852384e+00, 7.447728235072684e+01, 1.697389247504829e+02, -1.338846107646895e+04, -1.179174946974199e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_sx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.994306864599831e-08, 3.439989177242865e-08, 4.190948930943028e-08, 5.542425173936258e-08, 8.207179182803673e-08, 1.416198772826814e-07, 2.991314783113723e-07, 8.133051968626413e-07, 2.818925617533343e-06, 5.118069308855996e-06, -2.182160420316780e-04, 1.234869683442727e-02, 4.468943072122555e-02, 1.433689801749594e-01, 6.635508182883699e-01, -4.781101962593082e+01, -7.192215635887528e+03, -9.149527135093296e+05, -1.429849051991386e+08, -1.176072027851974e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_sx_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.725860955728597e-05, -1.285182773905358e-05, -5.878889594056421e-05, -1.281700152228628e-04, -2.276781517291021e-04, -3.494876563279030e-04, -4.436714667147288e-04, -4.276484954563695e-04, -6.221244921853338e-05, -1.715386550952752e-03, -4.847995563031602e-04, -3.573097250255979e-02, -7.594139528397383e-02, -1.471895429913221e-01, -2.881560310213939e-01, 5.187927862966823e+00, 1.283806141195011e+01, -2.314621735006428e+02, -3.600758268520270e+02, -4.155641172999778e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_sx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.268269668834908e-14, 6.716787158319250e-14, 9.520015495145470e-14, 1.569949461627505e-13, 3.212458438406067e-13, 8.920519661057070e-13, 3.798504264607347e-12, 2.916086328601133e-11, 4.940754021723360e-10, 2.289947641296526e-08, 3.187255653963118e-06, 3.505919083331893e-04, 2.069907173103683e-03, 2.400131106506405e-02, 1.666064869934553e+00, 5.986297764224007e+02, 8.297895005940532e+05, 2.866836224805996e+09, 5.270306795051825e+13, 3.364258330122763e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_sx_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.467319482224086e-11, -7.684055678255518e-11, -9.687067238176512e-11, -1.311642582148020e-10, -1.920421535173250e-10, -3.013754975463106e-10, -4.843921695973017e-10, -6.666633045751850e-10, -5.580504888439782e-10, 3.709877664179304e-09, 3.564901287256395e-06, 8.815437169091893e-05, -1.413089759755434e-04, -7.042502242669468e-04, -9.364194068355225e-03, 4.471240943335230e+00, -6.855019027339831e+02, -2.880957696987178e+04, -3.293717858023665e+06, -2.956956366088898e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_sx_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.277277733104386e-07, 1.019761058520140e-06, 2.222433604466169e-06, 4.028644915473054e-06, 6.600137042659394e-06, 9.704267881045622e-06, 1.195398031013573e-05, 1.089233733140582e-05, -1.844736766198071e-07, 3.657965766691085e-05, -1.091719227122843e-04, 2.330467116673144e-03, 2.688017894258152e-02, 7.399983998320844e-02, 1.181604679383197e-01, -5.286249171560900e+00, 1.922648731787812e+00, 2.380579978665492e+02, 3.969062207676457e+02, 4.890382598956815e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
