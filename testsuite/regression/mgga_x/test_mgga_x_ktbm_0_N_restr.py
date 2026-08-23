
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.783280725333357e+00, -4.689675880166712e+00, -4.558538139138109e+00, -4.376924812180761e+00, -4.129520850941525e+00, -3.800285509365914e+00, -3.376209867018110e+00, -2.853227316419919e+00, -2.240986734728790e+00, -1.569509312643225e+00, -9.650948236095661e-01, -6.338563840829781e-01, -5.715095542727288e-01, -4.892940386532728e-01, -3.457280612032649e-01, -1.957742327132897e-01, -8.518009489165022e-02, -2.715168535468286e-02, -5.621687011311817e-03, -6.218871262902171e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.963499330068056e+00, -5.832706550288618e+00, -5.649322110538500e+00, -5.395100335826464e+00, -5.048455575830316e+00, -4.587193483293590e+00, -3.995973886042721e+00, -3.283975542363725e+00, -2.519100610418221e+00, -1.809911974596406e+00, -1.163630439575820e+00, -7.886834766730105e-01, -7.871882878602676e-01, -6.105332352656888e-01, -4.016869407140221e-01, -2.390387873004977e-01, -1.094238127399301e-01, -3.530761971736637e-02, -7.320401719403867e-03, -8.098354704827265e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.046833122668088e-06, -8.706951923760291e-06, -9.748497656857383e-06, -1.145828598578346e-05, -1.442610112385810e-05, -1.999118010516030e-05, -3.155605846102801e-05, -5.871949534642219e-05, -1.287230901913407e-04, -2.951440845330502e-04, -7.196747592034719e-04, -4.427375447624938e-03, -2.016650570813206e-02, -4.790508190071487e-02, -1.393321274221891e-01, -3.576479144842212e-01, -8.942511818369003e-01, -5.605577837433430e+00, -1.274947319264168e+02, -1.090892103207482e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_0_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.195087832920727e-03, 8.351454575303278e-03, 8.580101771286135e-03, 8.916446047191185e-03, 9.414650784728629e-03, 1.015659135565864e-02, 1.125414737352169e-02, 1.277284318534752e-02, 1.411447967783016e-02, 1.180136270667552e-02, 4.622649040525076e-03, -1.118510306494584e-04, 3.164432375166348e-02, 5.089801753441540e-02, 5.496489699606553e-02, 3.057312660823755e-02, 6.969315193250380e-03, 1.388925503476059e-03, 2.817706441600288e-04, 3.310918442148478e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.554727651283651e-02, -1.630991139063283e-02, -1.746981914366789e-02, -1.927457570473613e-02, -2.216855353158481e-02, -2.697751097837316e-02, -3.518026264486766e-02, -4.838158289465642e-02, -6.027710202320150e-02, -4.979305176317603e-02, -1.083793124976894e-01, -5.019858580358223e-01, -9.349010125979714e-01, -1.403425487412255e+00, -1.641620330930488e+00, -2.127522709268248e+00, -2.765702927888088e+01, -3.273952819969571e+02, -7.788705059009172e+03, -6.367008603511553e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.578424644418574e-08, 6.385956560426821e-08, 7.747947739360092e-08, 1.020555808066342e-07, 1.507672377431484e-07, 2.603101885179681e-07, 5.477383032391677e-07, 1.395705948750604e-06, 2.806024551037379e-06, -2.694934192862553e-05, -5.036133676072237e-04, -4.456495005332433e-03, 3.277960350071772e-02, 1.398457236203261e-01, -5.338182217846471e-01, -4.358742205534022e+01, -1.435929921379744e+03, -2.226803799025824e+05, -5.472258225503136e+08, -3.523557357686513e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_0_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.834466865665706e-05, -2.002584430952108e-05, -2.271899799227297e-05, -2.724041869856247e-05, -3.535339198820309e-05, -5.131248235494388e-05, -8.656381296115563e-05, -1.715416596277829e-04, -3.087172194058720e-04, 3.775215585727143e-04, 1.761502580822635e-03, 1.159070594017246e-02, 8.303783500627204e-02, 4.337396360426140e-02, 1.300872365247485e-01, 2.336040594494957e+00, 9.016478895634796e+00, 5.278744803340009e+01, 1.206710788608809e+03, 1.069389293416396e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.944095048732954e-14, -3.707833677584295e-14, -5.157792601593844e-14, -8.260370347100096e-14, -1.612121631089662e-13, -4.129241300728250e-13, -1.510055844614520e-12, -8.183268515292481e-12, -3.780007669614091e-11, 2.844201582572541e-09, 2.956543151676758e-07, 1.209978758648349e-05, -4.140926927310401e-04, -4.381614716373728e-03, 1.148073618301475e-01, 8.685122158136143e+01, 8.022387881084874e+04, 8.172752960478895e+08, 2.864280600187981e+14, 1.455446570463331e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_0_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.676826217371647e-10, 2.029682077739075e-10, 2.670426370109469e-10, 3.959255563227229e-10, 6.962000185062962e-10, 1.559310206700015e-09, 4.894656261752507e-09, 2.408398081146545e-08, 1.979754382478987e-07, 2.268732133413612e-06, 3.111970853963377e-05, 1.205496095500867e-03, 1.343300742517753e-02, 9.994145894526169e-02, 1.976078678852971e+00, 4.663492869376996e+01, 1.130437152627130e+03, 8.040089325140799e+04, 8.690394955857743e+07, 4.181971361877451e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_0_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.060024171882351e-07, -3.485883613402283e-07, -4.204134842789538e-07, -5.503172319926866e-07, -8.100564160814414e-07, -1.409450670205385e-06, -3.101368440658976e-06, -9.336847334186873e-06, -3.945245765291803e-05, -1.749927923813603e-04, -4.528480841278259e-04, -2.313343401613390e-03, -5.768659951277282e-02, -2.290037213141055e-01, -1.551615455586931e+00, -8.135536371368120e+00, -2.162618286525855e+01, -8.967609704421309e+01, -1.783113168910894e+03, -1.594544237734460e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
