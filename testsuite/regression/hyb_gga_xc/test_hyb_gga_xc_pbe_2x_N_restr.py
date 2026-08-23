
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbe_2x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_2x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.957694344057783e+00, -1.920696835050283e+00, -1.868868939646093e+00, -1.797106608020145e+00, -1.699394038237721e+00, -1.569514121721293e+00, -1.402740290116173e+00, -1.198904806648659e+00, -9.664521856746965e-01, -7.235294337238489e-01, -4.876678706678449e-01, -3.354035928550304e-01, -3.001161140437378e-01, -2.443925475341383e-01, -1.729856394462131e-01, -1.058028764229964e-01, -5.351019823045041e-02, -1.842989746105679e-02, -3.858558757910641e-03, -4.268711512599629e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbe_2x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.499009566014812e+00, -2.447694277429536e+00, -2.375702349929349e+00, -2.275798871011133e+00, -2.139313579635042e+00, -1.956978186531593e+00, -1.721090991090455e+00, -1.429951626459099e+00, -1.096392668104717e+00, -7.637776398751212e-01, -5.070781000449455e-01, -4.403713650488194e-01, -3.973925780493945e-01, -3.232683114181539e-01, -2.191622267386111e-01, -1.191516132949405e-01, -6.205539553003188e-02, -2.401794515939515e-02, -5.138995040311603e-03, -5.691533256419997e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_2x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.761531128419514e-07, -1.066066309851084e-06, -1.209194735992373e-06, -1.447185640532616e-06, -1.868125704442126e-06, -2.680167694094798e-06, -4.446834296657440e-06, -8.965599500876836e-06, -2.313944889449512e-05, -7.875269360010238e-05, -3.709163831754547e-04, 4.033772300456409e-04, 3.727060716928804e-03, 2.696591070458255e-03, -5.501869702318661e-03, -1.086484436608939e-01, -6.225734041892629e-01, -1.249142537794665e+00, -1.565381979521241e+00, -1.735746443040807e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_2x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.669766226855151e-03, -5.941147038313552e-03, -6.354670554642735e-03, -7.000784233733944e-03, -8.047009253915620e-03, -9.828411247018014e-03, -1.307641108473337e-02, -1.951708861189725e-02, -3.310336040560562e-02, -5.837216420479532e-02, -1.277276782094459e-01, -2.737460218119865e-01, -2.893037439416752e-01, -5.890025242042026e-01, -1.866217809408346e+00, -5.050226945669429e+00, 2.155207392349729e+00, -1.838128002666099e+02, -5.917355403920167e+03, -4.913102680174177e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_2x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.328726954652257e-08, 1.520218889531943e-08, 1.843599291492829e-08, 2.428879121539089e-08, 3.597595783053999e-08, 6.277077350027986e-08, 1.370657332890851e-07, 4.010726648306224e-07, 1.627938878823706e-06, 7.439584227145893e-06, 8.577863020146337e-05, 5.680187401737763e-03, 3.460403140164272e-03, 6.289358547679698e-02, 9.501182266103754e-01, 1.206752344693402e+01, -1.529973647705075e+03, -1.459106098705361e+05, -2.183239248105541e+07, -1.798188732789291e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbe_2x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbe_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.642772716608099e-14, -9.166109890971460e-14, -1.188630538892667e-13, -1.721253641658376e-13, -2.907294546945071e-13, -6.050248609090114e-13, -1.636179778963930e-12, -5.488337495418572e-12, 9.798461519256986e-12, 3.782468580149359e-09, 5.398518807216977e-07, -6.080480262981297e-04, -6.663574698455715e-03, -3.417353700887575e-02, -9.164327921527715e-01, -1.128702126925234e+01, 1.585975894560340e+05, 4.446447042284451e+08, 7.933128221045258e+12, 5.069427225898570e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
