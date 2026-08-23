
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_rcam_b3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_rcam_b3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.428422375882539e+00, -3.361543356994612e+00, -3.267875155873294e+00, -3.138213275003423e+00, -2.961714231271183e+00, -2.727151079918844e+00, -2.425826324112243e+00, -2.056564001095691e+00, -1.631343844360541e+00, -1.174680181558760e+00, -7.193123568816479e-01, -4.195711081926611e-01, -3.424489478882653e-01, -2.600262778130060e-01, -1.439424472712766e-01, -3.262856891513650e-02, 1.548636792665290e-02, -4.978084165191614e-04, -4.032169628216981e-04, -1.344025527334445e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_rcam_b3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_rcam_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.275261797798395e+00, -4.182770578116489e+00, -4.053190369200357e+00, -3.873746049954556e+00, -3.629381650450752e+00, -3.304582447417152e+00, -2.887839568199890e+00, -2.380366355430053e+00, -1.810597581290072e+00, -1.252275523677185e+00, -8.056465957293326e-01, -5.588314140536453e-01, -4.780262128855364e-01, -3.629252208304855e-01, -2.258161143381723e-01, -1.105211661406239e-01, -3.216818665463796e-02, -7.731874544727032e-04, -3.727498495551228e-04, -5.620293403091412e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_rcam_b3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_rcam_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.620477809695922e-06, -3.896369740428608e-06, -4.328606269497199e-06, -5.031095063851739e-06, -6.233677672113712e-06, -8.448031859136083e-06, -1.295783068700168e-05, -2.347716343261493e-05, -5.263998175161897e-05, -1.509771255815285e-04, -5.803924479994005e-04, -3.417544344833987e-03, -6.292230119764632e-03, -8.682408858339409e-03, -3.576345717894523e-03, 2.446313188768643e-01, 4.198399241601631e+00, 4.771923221659928e+00, -4.371358099932061e+01, -2.599194352919793e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_rcam_b3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_rcam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.772714401754649e-03, -1.020272576629946e-02, -1.085266557463286e-02, -1.185588349258895e-02, -1.345055989789797e-02, -1.608917562469105e-02, -2.068878218315965e-02, -2.919230638797230e-02, -4.541444851939842e-02, -7.191588718432147e-02, -1.102042013088119e-01, -3.751217217836476e-01, -4.966827477171706e-01, -6.921893807962068e-01, -8.442762418301326e-01, 1.447500305434144e+00, 1.715995829651364e+01, -4.273613721494684e+01, -3.154303531593630e+02, -6.451275545532495e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_rcam_b3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_rcam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.759420223271689e-08, 1.989167107071274e-08, 2.370586746632270e-08, 3.043618634856937e-08, 4.337043175756311e-08, 7.131734316108980e-08, 1.417518161112244e-07, 3.537648256759150e-07, 1.038425745271077e-06, -3.606936258566542e-07, -1.685210632141233e-04, 1.791589370452986e-03, 8.473774299144041e-03, -8.667682498300702e-03, -6.702207791390653e-01, -3.872671181731693e+01, -3.504055001387203e+03, 1.602438158666414e+05, -2.618031200039170e+07, -8.832862119820354e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_rcam_b3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_rcam_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.416458388386735e-14, 1.173089951816396e-13, 1.607842013139428e-13, 2.525680217195320e-13, 4.817112032624430e-13, 1.209085218384880e-12, 4.461796286864120e-12, 2.809254166661809e-11, 3.659639309637247e-10, 1.250380327138734e-08, 1.478833949638597e-06, 3.211452442067950e-04, 2.624389305116323e-03, 1.549261581764802e-02, 4.603949177370726e-01, 4.267626248048353e+01, 5.639117304918099e+03, 5.207550718828966e+07, 6.268871792724873e+13, 2.084674619648824e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
