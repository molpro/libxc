
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mpw1lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.304660058071016e+00, -3.243198731190519e+00, -3.157128844189583e+00, -3.038008546601535e+00, -2.875913144109492e+00, -2.660622323708796e+00, -2.384384480183796e+00, -2.046742703779210e+00, -1.660331950790891e+00, -1.251026790211241e+00, -8.434994420194928e-01, -5.425197660300154e-01, -4.648115035731384e-01, -3.908071047309198e-01, -2.851213986514252e-01, -1.750101759909413e-01, -8.950110280883267e-02, -2.997201395515343e-02, -1.425857902794641e-03, -1.036603634423398e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mpw1lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.101194644182820e+00, -4.016025325785534e+00, -3.896674677705375e+00, -3.731335774173262e+00, -3.506048933235184e+00, -3.206319162487826e+00, -2.821099824581946e+00, -2.350569517906656e+00, -1.819171207894850e+00, -1.293118431507849e+00, -8.692091505545454e-01, -6.568291356882787e-01, -5.863456383066016e-01, -4.694068720185647e-01, -3.265313186877382e-01, -2.056111325594307e-01, -1.256722585865233e-01, -7.309547299361913e-02, -3.105312584918793e-03, -1.410617145503041e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.070185815652404e-06, -3.308197060672852e-06, -3.681838798927465e-06, -4.290922930991129e-06, -5.338357252662748e-06, -7.280667209220853e-06, -1.128138701787308e-05, -2.079337526475013e-05, -4.810598351565089e-05, -1.473125606539707e-04, -6.682882257978274e-04, -4.653297604154690e-03, -9.364690452704398e-03, -1.695921400410438e-02, -4.773787786921564e-02, -1.345827261416025e-01, 1.315361636727813e+00, 7.951503637918719e+01, 3.293866245228402e+02, 6.171705221188997e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.920285223788552e-03, -9.314779947034581e-03, -9.911559923851725e-03, -1.083400664756467e-02, -1.230363490147261e-02, -1.474474307485273e-02, -1.902938102740988e-02, -2.705394030665653e-02, -4.276386553080433e-02, -6.990547687427814e-02, -1.184561091352965e-01, -3.887371501093731e-01, -5.001447848246405e-01, -7.798435984083231e-01, -1.280271596976739e+00, 1.713581705156817e+00, 9.823600024085931e+01, -1.211777194125508e+03, -1.912276936853876e+04, -1.490781183864143e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.510208388445243e-08, 1.710147222458558e-08, 2.042883300740458e-08, 2.632178098682601e-08, 3.771179308888403e-08, 6.254890260834300e-08, 1.261261035689849e-07, 3.231967395281724e-07, 1.009089592307296e-06, 5.032870195155029e-07, -1.220465464853770e-04, 4.589448673100169e-03, 1.971748268655401e-02, 3.630905058368544e-02, -2.107665593183332e-01, -4.101408112356671e+01, -1.065247296726802e+04, 1.127032379807588e+06, 4.228644329383892e+09, 5.834515656709960e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.207025232964526e-14, 1.023757908310260e-13, 1.405919909460447e-13, 2.215033244388133e-13, 4.243754571676826e-13, 1.072710464871148e-12, 4.004007060045413e-12, 2.570855263191756e-11, 3.473379072279679e-10, 1.277856338058903e-08, 1.716082476286643e-06, 4.061456923675789e-04, 3.580883569991074e-03, 2.403923463742623e-02, 1.036489041534232e+00, 3.063695796280368e+02, 7.571807387961007e+05, -9.103659704356430e+09, -1.569977285534996e+15, -1.684274879063571e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
