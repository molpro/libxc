
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_hcth_407_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.523780812555487e+00, -4.432529811812040e+00, -4.304758495426516e+00, -4.127970726809729e+00, -3.887546774636289e+00, -3.568671284980710e+00, -3.160979686508484e+00, -2.667599335663030e+00, -2.120094258169044e+00, -1.589288339002716e+00, -1.093337693075432e+00, -7.204332213570357e-01, -6.306939804898001e-01, -5.166434221912947e-01, -3.785695211392354e-01, -2.628808158958197e-01, -1.264995247755446e-01, -1.789194988387725e-02, 7.336810338255407e-04, 2.940923994094370e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_hcth_407_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.090610866185223e+00, -5.964629492420794e+00, -5.787716722356397e+00, -5.541862693539853e+00, -5.205233659928149e+00, -4.753800620590250e+00, -4.165276867190307e+00, -3.425158363258498e+00, -2.535474807874556e+00, -1.578676464915801e+00, -9.571341522567149e-01, -9.271665467050563e-01, -8.395844655639105e-01, -6.475005037433074e-01, -4.077623662339722e-01, -2.201652760755656e-01, -1.981187193914574e-01, -3.677789449386829e-02, 3.038887255714609e-04, 3.785014389431150e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_407_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.524012974120614e-07, 8.585098671569456e-07, 8.580416032137328e-07, 8.333344804179352e-07, 7.300543890886518e-07, 3.682887462956381e-07, -9.321272828071474e-07, -6.297973837760563e-06, -3.395457360114412e-05, -2.089074312475418e-04, -1.285744950672373e-03, -1.795375739109391e-03, 2.853973138555079e-03, -1.171490978345953e-02, -8.205396709886256e-02, -6.649264315829119e-01, 1.580261057114332e+00, 1.854411372331896e+01, 4.070856237860781e+01, 5.610752017501762e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_407_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270970781073955e-02, -1.333736067531265e-02, -1.429863398602258e-02, -1.581398579894485e-02, -1.830970821376888e-02, -2.271331540876551e-02, -3.141219683829533e-02, -5.202707079369805e-02, -1.134773012504896e-01, -3.026570545251654e-01, -6.997348673734837e-01, -6.626590392409778e-01, -8.394940926048662e-01, -1.375143688707184e+00, -4.549911181271105e+00, 6.646496598477819e+00, -3.557341297038238e+01, -1.443942672278743e+03, -4.474553859041940e+03, 2.696350720203448e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_407_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.564443268981748e-08, 1.852862096421134e-08, 2.355788308734168e-08, 3.309810517828012e-08, 5.355509081802605e-08, 1.061183140821575e-07, 2.828481445115805e-07, 1.155714111589945e-06, 8.052802347452526e-06, 8.716209792376975e-05, 1.369488736504633e-03, 1.384356313564392e-02, 6.746027967165079e-02, 1.435301240271746e-01, 2.485333880153992e+00, -6.119577571050359e+01, -1.173581069339763e+03, 2.036392749188363e+06, 5.592983873026468e+08, 5.790951481410957e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_407_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_407", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.311601589333634e-13, -2.832032000111332e-13, -3.786805371158769e-13, -5.736408138616083e-13, -1.038960938575092e-12, -2.438216392561760e-12, -8.404769769728074e-12, -5.131749699626188e-11, -6.638079929651419e-10, -1.591957374010451e-08, -8.071124130731860e-07, -7.247429320657174e-04, -2.810622519822905e-02, -2.167926216078185e-02, -7.492192401336866e-01, 7.105699280421592e+02, -1.707273045683365e+05, -6.580742742607658e+09, -2.064610569901124e+14, -1.638723147222431e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
