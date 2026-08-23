
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_hcth_93_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_93", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.534233480909218e+00, -4.442291451797012e+00, -4.313569061017275e+00, -4.135504400893316e+00, -3.893442137815937e+00, -3.572660026228099e+00, -3.163301917374408e+00, -2.670146529884144e+00, -2.128250374774626e+00, -1.606899121821820e+00, -1.103881818492486e+00, -7.163982750560197e-01, -6.262034791849272e-01, -5.123661663470318e-01, -3.740182721167689e-01, -2.552136405209451e-01, -1.588890920983584e-01, -6.495697594983248e-02, -1.343743907495210e-02, -1.463207038016529e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_hcth_93_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_93", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.127424385616096e+00, -6.000100975433877e+00, -5.821174981749341e+00, -5.572217354891142e+00, -5.230594496541455e+00, -4.770646701292225e+00, -4.166812011820335e+00, -3.399693256772293e+00, -2.475034693814866e+00, -1.522251789623435e+00, -9.360332869646064e-01, -9.259907194224767e-01, -8.293721080491082e-01, -6.458839828677229e-01, -4.033474675353356e-01, -2.072536492235587e-01, -1.175298498264316e-01, -7.819707832056011e-02, -1.791217867408426e-02, -1.951269545549617e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_93_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_93", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.061989611021776e-06, 1.077696664745003e-06, 1.089806042358910e-06, 1.078934682040773e-06, 9.799585897337791e-07, 5.629932360168284e-07, -1.078827345735247e-06, -8.130425673344960e-06, -4.343708526825584e-05, -2.432828644951540e-04, -1.394871189155806e-03, -1.576259753497380e-03, 6.586775836110675e-04, -1.068137459305132e-02, -8.241840986993686e-02, -6.957272745985290e-01, -6.525696917936980e+00, -2.137379187878794e+01, -2.602345273069597e+01, -2.697239868913084e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_93_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.287492434069542e-02, -1.354641133531163e-02, -1.458552081638820e-02, -1.624919551286061e-02, -1.905235651590118e-02, -2.415389383216589e-02, -3.456368607425516e-02, -5.933138033658267e-02, -1.266937494747766e-01, -2.892522745535124e-01, -6.157223618410771e-01, -6.571621579126141e-01, -7.691222283204778e-01, -1.409367575545238e+00, -4.363142281239320e+00, -8.123539240923062e+00, 7.716860893428724e+01, 2.010928827007241e+02, -2.007647460033638e+04, -1.686194518599421e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_93_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.627493617006529e-08, 1.967921397678621e-08, 2.576390817251429e-08, 3.770096995299464e-08, 6.442145496882912e-08, 1.363945632501439e-07, 3.862425444385557e-07, 1.589662905808051e-06, 9.898762376379765e-06, 8.351883286428321e-05, 1.166554523983919e-03, 1.330082853527467e-02, 4.066258621246330e-02, 1.566972854325748e-01, 2.363042318779295e+00, 1.806227461435259e+01, -7.733035354896864e+03, -2.367765071906649e+06, -3.639068656560979e+08, -2.798116877018126e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_93_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.526789509986272e-13, -3.140084129107428e-13, -4.289498640539067e-13, -6.710192812650479e-13, -1.274248976086848e-12, -3.189156520495887e-12, -1.175689479107686e-11, -7.266131525389462e-11, -8.090233266256692e-10, -1.168449903045145e-08, -7.928083785298284e-08, -7.246589530499892e-04, -1.478193480827717e-02, -2.978189245763649e-02, -6.905941828677165e-01, 3.054280567182566e+02, 1.098606777132581e+06, 7.282424620937612e+09, 1.317213804241960e+14, 7.877573029694862e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
