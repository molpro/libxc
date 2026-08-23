
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_lv_rpw86_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lv_rpw86", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.225971026548035e+00, -4.143048096835154e+00, -4.026909185476523e+00, -3.866148369339346e+00, -3.647353927260975e+00, -3.356741180860766e+00, -2.984044555545157e+00, -2.529732478653308e+00, -2.015578019045296e+00, -1.492365104255695e+00, -1.000362753212065e+00, -6.456306836880590e-01, -5.552021323800540e-01, -4.558377777608396e-01, -3.264202600738672e-01, -2.158475559907084e-01, -1.288482479446139e-01, -5.761172467602894e-02, -2.128682812228357e-02, -5.611090432005797e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_lv_rpw86_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lv_rpw86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.466897763881676e+00, -5.353231334629737e+00, -5.193836633578768e+00, -4.972780857952584e+00, -4.671024798531889e+00, -4.268264924797291e+00, -3.747459003611387e+00, -3.103176649074799e+00, -2.354319865352172e+00, -1.567960460148441e+00, -9.709317857437599e-01, -8.180510407963867e-01, -7.242631507379249e-01, -5.696253278075687e-01, -3.648982241137657e-01, -1.568840925141961e-01, -1.236670922622314e-01, -5.066264921263713e-02, -1.716312395148495e-02, -4.489340741996742e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lv_rpw86_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lv_rpw86", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.799713603959283e-06, -1.952542507462760e-06, -2.195083491789956e-06, -2.596904532147606e-06, -3.304993348123452e-06, -4.668379475560412e-06, -7.649204174224290e-06, -1.546724832179740e-05, -4.203078970054173e-05, -1.697591128493145e-04, -9.665262617931761e-04, -3.433594166933044e-03, -5.946547243874807e-03, -1.417678680355782e-02, -6.626807178675041e-02, -7.010082647396698e-01, -3.262736045970975e+00, -5.893264675269354e+01, -3.054651308356398e+03, -6.326372562795040e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lv_rpw86_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lv_rpw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.141663549996134e-02, -1.193643952955327e-02, -1.272773329262683e-02, -1.396317004780964e-02, -1.596464015343809e-02, -1.938860055316236e-02, -2.574311524801714e-02, -3.910093570059800e-02, -7.319722749470964e-02, -1.866689240673799e-01, -5.225636893079521e-01, -5.313953351621540e-01, -6.388582992115377e-01, -1.124147514960868e+00, -3.225684659297825e+00, -1.579715711779657e+01, 1.049544348301183e+01, -2.460765447932846e+01, 1.043687924296985e+04, 2.321398477990349e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lv_rpw86_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lv_rpw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.331697946287856e-08, 1.535485647548890e-08, 1.883998552223733e-08, 2.527055222696480e-08, 3.850735927066544e-08, 7.040599080110238e-08, 1.669154480772744e-07, 5.728869766252155e-07, 3.328179387275225e-06, 3.943759822930896e-05, 8.552706404056629e-04, 7.310885881607633e-03, 1.921018500366098e-02, 8.737646358690886e-02, 1.328802655062064e+00, 6.053564371178408e+01, -3.556990860999000e+03, -1.126899884017914e+06, -8.295276333963328e+09, -1.310347560787459e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lv_rpw86_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lv_rpw86", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.822067291006003e-16, 1.142417614367443e-15, 1.652317202686101e-15, 2.792740123917124e-15, 5.863723996150711e-15, 1.653860384706391e-14, 6.831696630738015e-14, 4.268719961540631e-13, 1.921355799604000e-12, -4.183596672399030e-10, -1.415036142697271e-07, 6.511103843177765e-06, 2.710158346730768e-05, 4.166269181622281e-04, -9.426391017574455e-03, 1.057802455955798e+02, 5.414209144756511e+05, 8.040747768610190e+09, 6.141046037048839e+15, 7.390014089349228e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
