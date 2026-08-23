
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_tpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.312729436271210e-02, -5.260683566669200e-02, -5.184984799539321e-02, -5.074303690171835e-02, -4.911194389836800e-02, -4.667994448325786e-02, -4.299380627147267e-02, -3.730839325089587e-02, -2.863611543039196e-02, -1.753106738734892e-02, -1.220355368276240e-02, -4.304694531093838e-02, -5.225375380903537e-02, -3.639261909227360e-02, -2.074965542816470e-02, -6.253534284054614e-03, -4.673902657209876e-04, -5.326578792836809e-06, -5.289922548440638e-09, -1.642378010659873e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_tpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.201077834772369e-01, -1.188650229189927e-01, -1.170976437137144e-01, -1.145982654009979e-01, -1.110946382197282e-01, -1.062512310852206e-01, -9.969502475322709e-02, -9.099979583247149e-02, -7.897860239020975e-02, -6.015389648481295e-02, -4.835184283089966e-02, -8.840811230678662e-02, -8.227917205910552e-02, -7.458313860498311e-02, -5.731693850488840e-02, -2.610969174919233e-02, -2.555133172789893e-03, -3.162032176605670e-05, -3.234145397079170e-08, -1.025669197932155e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.311563049475591e-06, 1.366338507426724e-06, 1.448575525286597e-06, 1.574262411726841e-06, 1.771240360140177e-06, 2.091338528751368e-06, 2.641963872922986e-06, 3.695538303332236e-06, 6.212519828721599e-06, 1.484383689282304e-05, 8.887543970912239e-05, 3.441126641529724e-03, 9.759892919262551e-03, 1.410044293047336e-02, 3.030264905150041e-02, 8.784846420651736e-02, 1.172455044073312e-01, 4.873064274011888e-02, 6.035365465576667e-03, 1.504918029989410e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.371868511539262e-03, -1.325508605552033e-03, -1.259368808334478e-03, -1.165361653569041e-03, -1.032588996657056e-03, -8.474130304790996e-04, -5.967038646707695e-04, -2.833865057337583e-04, 2.452202557691149e-05, 1.525594938695210e-04, 9.107595743109937e-05, -1.805360110204347e-06, -3.789288383699323e-04, -1.309596551466695e-03, 2.142867640849304e-03, 2.252490596384168e-03, 2.608350705611583e-04, 3.522531926525211e-06, 3.622241846327809e-09, 1.053437666420548e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.420506103736814e-04, -4.720970713738460e-04, -5.184653898936400e-04, -5.921544183980473e-04, -7.141497957967783e-04, -9.279562280484428e-04, -1.335146787820908e-03, -2.232875901671305e-03, -4.945133273459634e-03, -1.679046363164303e-02, -6.518124771563323e-02, -2.584666519399779e-02, 5.285416183996412e-03, -1.088614254713918e-01, -7.121151002112448e-01, -5.616041196299658e+00, -1.138640750281946e+01, -4.935355127069460e+00, -5.906458280696414e-01, -1.418369549138961e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.171108700359276e-09, 5.966861497689710e-09, 7.318124441474605e-09, 9.780376976241341e-09, 1.473383425124134e-08, 2.616368090960363e-08, 5.795552747805956e-08, 1.719024251282105e-07, 7.682955378004841e-07, 6.798004769715417e-06, 1.685611438982345e-04, 1.100697632087578e-03, -1.005617999841622e-02, 5.169763843472453e-02, 7.504179465008817e-01, 2.690990457576967e+01, 6.758325400223316e+02, 9.627148593597703e+03, 1.380420411753315e+05, 2.578577325637114e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpss_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.543183947017299e-06, -1.817392512373884e-06, -2.258694892519624e-06, -2.999807743533445e-06, -4.313648539862604e-06, -6.792478468317044e-06, -1.171898208550138e-05, -2.119028889691646e-05, -3.196859927643901e-05, -5.734011739957683e-06, 5.283174790214858e-05, -1.329982396988993e-04, -1.140682423420906e-03, -3.948524527288416e-02, -9.652305146077886e-02, 3.372566568050739e-01, 1.007843832337076e+00, 4.813464288488143e-01, 5.790987989337539e-02, 1.266001360418329e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.113058000059715e-14, 3.201064148241275e-14, 3.147899307711001e-14, 2.430002296108952e-14, -1.258583636091715e-14, -1.996614992324316e-13, -1.352995252927685e-12, -1.142912577132313e-11, -1.587085124785055e-10, -4.825487377168075e-09, -7.310944217450248e-07, -7.730150844813862e-04, -7.848361328866810e-03, -5.514385383829822e-02, -1.596294699967199e+00, -2.268917793140289e+02, -5.981796668093455e+04, -2.704138051894960e+07, -4.600324109656769e+10, -6.593245916958382e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpss_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.871542849847911e-10, -5.362444418748981e-10, -6.145961310362560e-10, -7.448672334062543e-10, -9.731348788093678e-10, -1.397547816572317e-09, -2.217010244586395e-09, -3.604341804809433e-09, -2.994140893031263e-09, 2.736635866283140e-08, 4.568520988829319e-07, 8.735775885580890e-06, -1.257721193034735e-03, -1.907227279043995e-03, 1.504432978675709e-01, 2.268517528006804e+00, 1.009850953579189e+01, 1.785510987379029e+01, 1.452036953599949e+01, 4.009815756803811e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpss_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.264397660285809e-06, 1.313533573319193e-06, 1.385765344073717e-06, 1.492207803755795e-06, 1.648091412793724e-06, 1.868342790676162e-06, 2.137272608520777e-06, 2.265148919236871e-06, 1.409711671756824e-06, -2.069304661698073e-06, -8.226877650670156e-06, 2.635239943493806e-06, 2.037278592828458e-03, 2.867089730902163e-02, -5.015608883932413e-02, -6.018547641371516e-01, -1.017014495679701e+00, -4.770869219574122e-01, -6.096211449384911e-02, -1.400736841128944e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
