
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_opwlyp_d_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opwlyp_d", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.380079755911196e+00, -4.298108298339379e+00, -4.183318385362897e+00, -4.024456014715325e+00, -3.808298347835676e+00, -3.521251387553089e+00, -3.153075278097917e+00, -2.703434596085948e+00, -2.189969458966902e+00, -1.649062004866602e+00, -1.111419745190730e+00, -7.093034931415796e-01, -6.068001215708596e-01, -5.092498219244419e-01, -3.714233506216861e-01, -2.303108309889878e-01, -1.255973300786198e-01, -9.263741744775462e-02, -5.935791554725694e-02, -4.067691698746701e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_opwlyp_d_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opwlyp_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.453538157572104e+00, -5.339974618245713e+00, -5.180792526767816e+00, -4.960200615209239e+00, -4.659501625874989e+00, -4.259221951038509e+00, -3.744338948452580e+00, -3.114412633484423e+00, -2.400479586426642e+00, -1.688632956062158e+00, -1.121477758951335e+00, -8.605056217627715e-01, -7.675306523476881e-01, -6.117767739767777e-01, -4.201166870177286e-01, -2.558958733569259e-01, -1.340227465685586e-01, -4.381350980487346e-02, -1.713657257492246e-02, -6.771436459676126e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_opwlyp_d_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opwlyp_d", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.938309895444636e-06, -4.244950138380908e-06, -4.726996281820491e-06, -5.514255774930819e-06, -6.871471371537776e-06, -9.396943862944276e-06, -1.462632435877898e-05, -2.717206505075136e-05, -6.381952120931370e-05, -2.017076671675578e-04, -9.485815872972667e-04, -6.130327382347364e-03, -1.226327613596766e-02, -2.267879342235837e-02, -6.816601432828559e-02, -2.637313622631086e-01, -1.269794492731759e+00, -1.697813953205938e+02, -1.688098880384901e+04, -1.003562813847816e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_opwlyp_d_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opwlyp_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.186410005963678e-02, -1.239869168319840e-02, -1.320690896794057e-02, -1.445547241220768e-02, -1.644488042629295e-02, -1.975685289316933e-02, -2.561160733569674e-02, -3.676836005541834e-02, -5.963733188395708e-02, -1.063183113294619e-01, -2.078401117488740e-01, -5.237527599137854e-01, -6.585687218776154e-01, -1.058036086028623e+00, -1.908943085772215e+00, -4.281436530957148e-01, 3.263972802149904e+01, 6.056436047612554e+01, 1.722986116921955e+04, 1.028650949784325e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_opwlyp_d_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opwlyp_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.973014584533509e-08, 2.246205775194546e-08, 2.701417823163605e-08, 3.509287311990649e-08, 5.077401602708762e-08, 8.530526797462827e-08, 1.756939712705278e-07, 4.709818370638867e-07, 1.688420627143588e-06, 6.265487337746258e-06, -2.022380951591704e-05, 6.721949049622703e-03, 2.452345724147572e-02, 5.831165526562883e-02, -4.453761403113499e-02, -3.687823916232450e+01, -6.674384454434541e+03, -1.044419107313782e+06, -1.012725036524806e+10, -3.410977156090546e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_opwlyp_d_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_opwlyp_d", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.016562866670634e-13, 1.257189416055754e-13, 1.710457873249162e-13, 2.672081816140798e-13, 5.090960052258661e-13, 1.284863899816515e-12, 4.802421005632472e-12, 3.091172118959479e-11, 4.185784123692656e-10, 1.536972859930660e-08, 2.055255226683769e-06, 4.865918957883765e-04, 5.237801581192195e-03, 2.885066916691524e-02, 1.249050619611452e+00, 3.588589969882448e+02, 7.466019169024449e+05, 1.998819833929883e+10, 2.421334464173021e+16, 8.049158798250443e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
