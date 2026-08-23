
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hse12s_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12s", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.583967315454953e+00, -2.536180904507029e+00, -2.469285219826764e+00, -2.376755481563417e+00, -2.250965129995162e+00, -2.084168456680290e+00, -1.870739170751616e+00, -1.610807502820217e+00, -1.313066947820243e+00, -9.937559693053644e-01, -6.842115343367261e-01, -4.747272574445840e-01, -4.238334492763516e-01, -3.573888356455515e-01, -2.701179659445384e-01, -1.834112594713274e-01, -1.079972346012111e-01, -4.195468232627048e-02, -8.772254453881030e-03, -9.701659372866640e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hse12s_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12s", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.260948173186971e+00, -3.193120949520274e+00, -3.097928191928341e+00, -2.965777556425888e+00, -2.785213291107985e+00, -2.544257587377946e+00, -2.234339750333592e+00, -1.860306082659029e+00, -1.459109670284230e+00, -1.064549510027330e+00, -7.123987927669865e-01, -5.902045586225715e-01, -5.407765332000505e-01, -4.392213601234177e-01, -3.194922770679528e-01, -1.906063060007988e-01, -1.212069823200919e-01, -5.516913136494931e-02, -1.169490134916449e-02, -1.293552739084012e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse12s_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12s", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.576335989709266e-06, -1.729695578040104e-06, -1.974861057158753e-06, -2.384629384087295e-06, -3.113138499388999e-06, -4.520755107896302e-06, -7.542275944993501e-06, -1.479503463813716e-05, -3.352027998502695e-05, -9.581506734086502e-05, -4.767797763260958e-04, -1.217836535136873e-03, 1.250459030008701e-03, -4.630123189115088e-03, -1.914605124756816e-02, -2.121747719139673e-01, -1.081574099878702e+00, -9.266012335819687e-01, 6.036659648291788e-03, 1.504922553420553e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse12s_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12s", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.816992938458733e-03, -8.207435838436960e-03, -8.801444804723137e-03, -9.725324261142207e-03, -1.120274228550934e-02, -1.363313739802510e-02, -1.763985184732363e-02, -2.334656413836372e-02, -2.708953481172917e-02, -7.163192825076752e-02, -2.465555164590287e-01, -3.763311355467345e-01, -4.084245746941905e-01, -7.720507985399645e-01, -1.394901348782673e+00, -3.867900525407241e+00, 1.515087422464100e+00, -3.542345982824324e+02, -1.363879091930162e+04, -1.116817373526388e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hse12s_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12s", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.212490574189498e-08, 2.539525132979009e-08, 3.090299649212219e-08, 4.079806567925159e-08, 6.018080801692641e-08, 1.024087768842591e-07, 2.035295042661099e-07, 4.165421471967502e-07, 8.700561612873124e-08, 7.094967435285109e-06, 3.167820467629870e-04, 9.312901208458530e-03, 1.789519580081690e-02, 8.695228934568011e-02, 2.205757593729134e-01, 3.932181223600750e-02, -2.291844062237890e+03, -4.338128919753374e+05, 1.380746113142922e+05, 2.578585853613300e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_gga_xc_hse12s_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hse12s", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.231325297920379e-13, -1.479130563226916e-13, -1.917945358736517e-13, -2.760505568617884e-13, -4.546292472363013e-13, -8.642400921876572e-13, -1.567536579352153e-12, 6.188777771302027e-12, 3.086258110737574e-10, 5.478768628172207e-09, 1.598813595593433e-07, -5.985523075188997e-04, -8.702521374476538e-03, -2.438668943650794e-02, 6.679637513772985e-02, 1.257590435876714e+02, 2.631418427801220e+05, 1.066113356402938e+09, -4.600982050329903e+10, -6.593259128892691e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
