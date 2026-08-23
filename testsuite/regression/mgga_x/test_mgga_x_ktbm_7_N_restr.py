
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_7_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.905603229169162e+00, -4.808167661458032e+00, -4.671588705777031e+00, -4.482278956233934e+00, -4.224037857807261e+00, -3.879595591583641e+00, -3.434174534949570e+00, -2.881141997203838e+00, -2.228323675031175e+00, -1.518573332174451e+00, -9.100813649135865e-01, -6.043440333479159e-01, -5.721330771599962e-01, -4.891102063562834e-01, -3.363645681048279e-01, -1.851250616732396e-01, -8.010526258726949e-02, -2.556994851306372e-02, -5.301645181761751e-03, -5.870112166406861e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_7_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.169824145409966e+00, -6.035418962632300e+00, -5.847019429567055e+00, -5.585947040297008e+00, -5.230161085592793e+00, -4.757083234981235e+00, -4.151031138579547e+00, -3.419291261322954e+00, -2.616072996549067e+00, -1.819472402255415e+00, -1.123833538725561e+00, -7.872561038078117e-01, -8.195598979227479e-01, -6.374062085316422e-01, -4.103393833288813e-01, -2.252274471081927e-01, -9.966227806127190e-02, -3.202784880579847e-02, -6.632525359589609e-03, -7.332382081510752e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_7_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.449796711069732e-06, -9.144582209182177e-06, -1.024108869949974e-05, -1.204171216853696e-05, -1.516867409574693e-05, -2.103584210308327e-05, -3.323734516248650e-05, -6.191248640706905e-05, -1.358511876543816e-04, -3.125372922009479e-04, -7.299899002974780e-04, -3.996870016961837e-03, -2.000895044250228e-02, -4.884352982982493e-02, -1.441360420438001e-01, -4.118972337516942e-01, -1.445167266208019e+00, -1.262364159885371e+01, -3.170764744919953e+02, -2.787783682585742e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_7_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.016692145871258e-02, 1.038096466732236e-02, 1.069541235669877e-02, 1.116105885930911e-02, 1.185725023718632e-02, 1.290698170843068e-02, 1.448166888744869e-02, 1.667090175154207e-02, 1.847566242539209e-02, 1.496192062284444e-02, 5.799276337807389e-03, 2.724549235069174e-03, 4.403642231310930e-02, 6.822427415478474e-02, 7.124311338619922e-02, 3.775186994732641e-02, 1.092476651954691e-02, 3.083595992331924e-03, 7.001189208996819e-04, 8.460969701052825e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_7_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.595411383310959e-02, -1.673281974691204e-02, -1.791701363404432e-02, -1.975957455140868e-02, -2.271595478111919e-02, -2.764265429754465e-02, -3.614881780016078e-02, -5.068697633928845e-02, -7.150484351974665e-02, -1.013750643227631e-01, -1.938229453610328e-01, -6.315074577006581e-01, -9.723099669460642e-01, -1.467184994336558e+00, -2.439878295556105e+00, -4.536984446986261e+00, -2.981922142011587e+01, -3.343953064395837e+02, -7.955925705926573e+03, -6.520673487873927e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_7_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.009202203141964e-08, 6.887003939574854e-08, 8.370303998856067e-08, 1.105461715670027e-07, 1.640015330068159e-07, 2.851921955554878e-07, 6.083766966760539e-07, 1.605741155794398e-06, 3.988905450536183e-06, -1.487991764373807e-05, -3.825101482913669e-04, -4.584996884663315e-03, 2.901025419438660e-02, 1.436017028230083e-01, -2.163839696632495e-01, -2.884449817674056e+01, -6.094269841392074e+02, 2.123829494595009e+04, 1.568505737692663e+08, 1.071557277708532e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_7_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.758759525074237e-05, -3.021092943161253e-05, -3.441336242617730e-05, -4.145845212983520e-05, -5.403096789649452e-05, -7.836710638729648e-05, -1.297590149283085e-04, -2.381409198547701e-04, -3.106554088195033e-04, 9.286847901362108e-04, 3.277812316129097e-03, 2.308106291185824e-02, 9.152528906662385e-02, 5.021912219365865e-02, 3.896440475580411e-01, 2.371328282839783e+00, 3.839410978545089e+00, -5.871542126545628e+00, -3.468383995386525e+02, -3.252230513175079e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_7_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.371286618690614e-14, -8.076334778326648e-14, -1.134684590774859e-13, -1.845954498430878e-13, -3.697044669942415e-13, -9.913175059368011e-13, -3.970711039918061e-12, -2.692972809532811e-11, -3.363239076815428e-10, -7.328317360222582e-09, -3.298047983298113e-07, -3.087769378390983e-05, -1.133509621545884e-03, -1.550480529842356e-02, -6.056317887591096e-01, -8.042987277248588e+01, -8.534990674049655e+04, -1.063005559643538e+09, -3.850455137281431e+14, -1.961417969661362e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_7_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.137285654426054e-10, 2.586019370139909e-10, 3.400358279772074e-10, 5.036774996230014e-10, 8.843361967460401e-10, 1.975588067743527e-09, 6.172060052968551e-09, 3.008511740669144e-08, 2.427802081908296e-07, 2.717658208020540e-06, 3.496416879538256e-05, 1.182607685890311e-03, 1.550189021399430e-02, 1.186690011249445e-01, 2.312840089825442e+00, 6.213419903212844e+01, 2.952509902203507e+03, 8.487513186788250e+05, 2.631843887471701e+09, 1.830940752229049e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_7_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_7", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.747260339442729e-07, -3.167679397793358e-07, -3.887528842766788e-07, -5.217922837123941e-07, -7.961266585038691e-07, -1.457130068213201e-06, -3.433926249606587e-06, -1.122879919106119e-05, -5.071427775677781e-05, -2.233181348862149e-04, -5.535699227931353e-04, -3.422529063087055e-03, -6.728544312941019e-02, -2.782704590540706e-01, -1.984666156267082e+00, -1.027533709298641e+01, -3.938786587585837e+01, -3.511293872500739e+02, -9.745175327139341e+03, -9.307145117854287e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
