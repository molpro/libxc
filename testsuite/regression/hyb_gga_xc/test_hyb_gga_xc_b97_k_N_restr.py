
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b97_k_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_k", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.438530038453492e+00, -2.397257737730239e+00, -2.339464561289394e+00, -2.259492837642451e+00, -2.150709153718148e+00, -2.006320420235868e+00, -1.821196440497610e+00, -1.594591419506725e+00, -1.330902567177018e+00, -1.029862168588183e+00, -6.937077337291496e-01, -4.195705102751696e-01, -3.627377297121894e-01, -3.050058336772666e-01, -2.260074412942662e-01, -1.397538970253696e-01, -6.078814156483059e-02, -1.940006566069470e-02, -4.334996928456977e-03, -4.926352611383409e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b97_k_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.782627906712452e+00, -2.723478550510938e+00, -2.640451802700446e+00, -2.525183724839167e+00, -2.367736909942153e+00, -2.157926423796766e+00, -1.889176258751908e+00, -1.568032322037269e+00, -1.233785144159686e+00, -9.640162981774474e-01, -6.907430973325034e-01, -4.980658271630001e-01, -4.579281523326070e-01, -3.639587746153772e-01, -2.441771028611588e-01, -1.640966348415030e-01, -8.970510620611413e-02, -2.606686975663760e-02, -5.737875137216190e-03, -6.565457547882912e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_k_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.748958786740610e-06, -5.111861025612943e-06, -5.682396204788855e-06, -6.614167670357367e-06, -8.219534443952124e-06, -1.119724609150311e-05, -1.728819312947733e-05, -3.131784806644216e-05, -6.746285109935539e-05, -1.643406416474132e-04, -6.256048226425645e-04, -4.126820184859366e-03, -4.680067918853269e-03, -1.323632153885414e-02, -5.250719695712593e-02, -1.228203050765252e-01, 6.474935153641871e-01, 1.616944192793695e+00, 7.633792656077589e-01, -9.607544292471423e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_k_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.269122736123323e-03, -7.645200787251964e-03, -8.215073438473663e-03, -9.094883751279814e-03, -1.048241816056967e-02, -1.270586762370871e-02, -1.619098554229082e-02, -2.051289302746816e-02, -1.652518411227606e-02, 5.485347769792984e-02, 2.246583340265434e-01, -3.896481391206815e-01, -2.788229053544480e-01, -8.841534140966226e-01, -1.273680718277243e+00, 4.953598897636262e+00, -3.047781942525218e+01, -3.315412775731837e+02, -6.488676209378767e+03, -5.651760550500860e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_k_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.567035872126717e-08, 2.945543890924810e-08, 3.578732267065105e-08, 4.703390631759758e-08, 6.863566587275786e-08, 1.141346160686270e-07, 2.169084959538013e-07, 4.020899842958740e-07, -7.587490571262775e-07, -4.275125565925592e-05, -9.640757086289281e-04, 1.327733522579940e-02, -1.265182412183073e-02, 1.561498767400952e-01, 2.259958426371727e-01, -5.234799994846090e+01, -9.838438224389472e+01, 1.816087362887360e+05, 1.131902561729707e+07, -8.103761926951360e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_k_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.761561880408832e-14, 1.057320752459081e-13, 1.398548292764143e-13, 2.133360167685553e-13, 4.073794963820676e-13, 1.101590619320601e-12, 4.911566575409344e-12, 4.155468637206807e-11, 7.474998806358529e-10, 3.167798416415396e-08, 3.904498186816585e-06, -5.153873769460449e-04, 7.417737216804260e-03, -3.630532093044482e-02, 6.338713414568197e-01, 3.571017801359090e+02, -4.035083500452808e+04, -5.361857289556513e+08, -3.838214009005638e+12, 2.808968753096940e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
