
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_optx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.396998814912361e+00, -4.309638194900703e+00, -4.187335956359875e+00, -4.018163666070702e+00, -3.788209119021053e+00, -3.483498884424892e+00, -3.094653531832532e+00, -2.625994627236394e+00, -2.109692560570555e+00, -1.607508474378335e+00, -1.100025795723485e+00, -6.698197756192437e-01, -5.788754152311257e-01, -4.727236953396486e-01, -3.455187108654419e-01, -2.476128278676346e-01, -1.577430140569607e-01, -5.940805124938597e-02, -1.258367965629625e-02, -1.392899040340386e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_optx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.764083956063261e+00, -5.642471483823653e+00, -5.471621532584559e+00, -5.233998197280756e+00, -4.908116210692438e+00, -4.469743676397156e+00, -3.895122338649071e+00, -3.167409047543063e+00, -2.294764792255216e+00, -1.396560910724977e+00, -8.351729053081742e-01, -8.550071277779254e-01, -7.647174821410141e-01, -5.900317793865174e-01, -3.411533319372441e-01, -1.496268089732294e-01, -1.435144808044664e-01, -7.548439317787532e-02, -1.674065872367889e-02, -1.857145245528240e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.057756599492091e-06, -1.185390688039008e-06, -1.395499665836042e-06, -1.762136805340134e-06, -2.457136840879541e-06, -3.937509139998965e-06, -7.643095185532968e-06, -1.914299204817235e-05, -6.537818187026868e-05, -3.005106874457151e-04, -1.682043016139554e-03, -3.056133229315613e-03, -2.643826574225421e-03, -1.496000037577030e-02, -1.126362555946222e-01, -9.666640809041743e-01, -4.528969428569319e+00, -8.396869315121632e+00, -1.023202485290286e+01, -1.130646747770242e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.268714229820599e-02, -1.334569244078600e-02, -1.436428089123903e-02, -1.599314802555167e-02, -1.872981129879945e-02, -2.367762369768742e-02, -3.363623725899307e-02, -5.680526460501815e-02, -1.185921277044566e-01, -2.657240205487115e-01, -5.559924049860632e-01, -6.618752916919683e-01, -6.835586742806181e-01, -1.506174649674391e+00, -5.188889145408157e+00, -8.984442290583043e-01, 1.387719089172157e+02, -3.373065658279615e+02, -1.901216340623041e+04, -1.602867121417542e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.101406405657472e-08, 2.492028196372888e-08, 3.181114498723723e-08, 4.508888934954846e-08, 7.409162836809048e-08, 1.496742953622463e-07, 4.010085637977579e-07, 1.553310314204555e-06, 9.205273080219374e-06, 7.515011546024627e-05, 1.019328658120901e-03, 1.618495123195309e-02, 2.363288433463820e-02, 2.174772684955256e-01, 3.289969057088214e+00, -1.813092614018463e+01, -1.270943569192629e+04, -1.001552687445648e+06, -1.430272245251509e+08, -1.171384281347958e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.409775641246565e-13, -1.775884000457963e-13, -2.471991565310244e-13, -3.966107042536479e-13, -7.777525547541918e-13, -2.018512237998840e-12, -7.678822897473300e-12, -4.787296576911624e-11, -5.052842194330182e-10, -2.888214793592643e-09, 1.003156246094653e-06, -7.707789475656149e-04, -5.594826355288118e-03, -4.610261316952442e-02, -9.878652174661234e-01, 6.899516281322102e+02, 1.278399779762534e+06, 3.040735057511639e+09, 5.194670389904918e+13, 3.302307484379485e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
