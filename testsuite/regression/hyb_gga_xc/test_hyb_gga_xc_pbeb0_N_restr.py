
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbeb0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeb0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.298828395105383e+00, -3.236516209753562e+00, -3.149249311484780e+00, -3.028464064440977e+00, -2.864095585075818e+00, -2.645801344012924e+00, -2.365840568029141e+00, -2.024213870976367e+00, -1.635142165851640e+00, -1.227700344673265e+00, -8.276261272007305e-01, -5.457770250524976e-01, -4.770564766341310e-01, -3.948163180351486e-01, -2.856134803104694e-01, -1.790018319933679e-01, -9.120232250163977e-02, -3.141484794160442e-02, -6.577089093514778e-03, -7.276212805665215e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbeb0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeb0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.170925431391031e+00, -4.084237809621055e+00, -3.962660770878050e+00, -3.794032656292507e+00, -3.563840146421490e+00, -3.256717161757103e+00, -2.860284418708265e+00, -2.373015619020713e+00, -1.819037922953961e+00, -1.272165455061592e+00, -8.428903548917336e-01, -6.883101270860852e-01, -6.175539118382195e-01, -4.954679098426698e-01, -3.360828325074366e-01, -1.937954582589785e-01, -1.056371359111487e-01, -4.094114103134368e-02, -8.759652600346647e-03, -9.701477142271035e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbeb0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeb0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.203344531691277e-06, -2.391667893448591e-06, -2.689860767122416e-06, -3.181984975400179e-06, -4.043327393229014e-06, -5.680949897957436e-06, -9.173362758477886e-06, -1.786865366941867e-05, -4.420791867939913e-05, -1.440249563708362e-04, -6.801449751685710e-04, -2.148621101988050e-03, -2.040445631739116e-03, -7.593831913219244e-03, -3.592397021297532e-02, -2.281330869792770e-01, -1.070190324702266e+00, -2.126558047113724e+00, -2.667829057057277e+00, -2.958647697405810e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbeb0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeb0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.404542904878788e-03, -9.846336846192429e-03, -1.051829523513173e-02, -1.156523946644149e-02, -1.325293563087822e-02, -1.610532942596438e-02, -2.123857403882108e-02, -3.116812069026978e-02, -5.107700163596239e-02, -8.406937881406665e-02, -1.681783617847301e-01, -4.337067096140899e-01, -4.984425993271736e-01, -9.053083284046916e-01, -2.259184214386266e+00, -4.763227902658676e+00, 5.128100642752546e+00, -3.135225793157172e+02, -1.008643903747126e+04, -8.374606850599304e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbeb0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeb0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.998856634243567e-08, 2.284653020095358e-08, 2.766317905581293e-08, 3.635272204564929e-08, 5.361159973020489e-08, 9.280735061864823e-08, 1.995376878936458e-07, 5.644727666706889e-07, 2.100844136826807e-06, 6.441441225727185e-06, 1.335250500171520e-05, 7.697995165223757e-03, 1.435790844060158e-02, 7.917894834794850e-02, 7.749035439530276e-01, -1.067509165493163e-01, -2.707333204504444e+03, -2.482612562296436e+05, -3.720439693791302e+07, -3.065075563577537e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbeb0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeb0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.911826403012772e-14, -5.770920234264578e-14, -7.238822427318783e-14, -9.901394672788108e-14, -1.501027397626963e-13, -2.435281772911036e-13, -2.282079837925417e-13, 4.351594160371644e-12, 1.612609478713341e-10, 1.007976828295239e-08, 1.408190289065403e-06, -3.099000307318735e-04, -3.464861142812784e-03, -1.526598221449669e-02, -1.676763614346897e-01, 1.246593874302242e+02, 2.781574581862896e+05, 7.566163897197032e+08, 1.351907265342131e+13, 8.641020892008439e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
