
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_camh_b3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camh_b3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.513568774688188e+00, -3.447020524693734e+00, -3.353818659724522e+00, -3.224810407691271e+00, -3.049223485840815e+00, -2.815937621526513e+00, -2.516452564829315e+00, -2.150078806059549e+00, -1.730235641551432e+00, -1.285160534888235e+00, -8.447396570972715e-01, -5.311179315097335e-01, -4.501501601698542e-01, -3.693743521840371e-01, -2.556403258179620e-01, -1.423941820807676e-01, -7.010470862598511e-02, -5.030507034372385e-02, -3.060794635678465e-02, -2.045505289786935e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_camh_b3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camh_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.383469967334094e+00, -4.291472357880550e+00, -4.162553083597134e+00, -3.983958239129302e+00, -3.740606884679192e+00, -3.416832949305052e+00, -3.000667098698096e+00, -2.492149963237730e+00, -1.917074325044478e+00, -1.345197307372435e+00, -8.861875563190984e-01, -6.609917515102244e-01, -5.833637770642204e-01, -4.602633666261096e-01, -3.094053815157204e-01, -1.784288818706452e-01, -8.248441234906900e-02, -2.666228345220228e-02, -9.782177765891345e-03, -3.540194850150814e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camh_b3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camh_b3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.218952271722660e-06, -3.467691113373266e-06, -3.858044020582160e-06, -4.494065501001661e-06, -5.587070868542462e-06, -7.611887549166697e-06, -1.177680772180592e-05, -2.166171742604382e-05, -5.000099970172018e-05, -1.530122941501915e-04, -6.813255342087119e-04, -4.333984232896848e-03, -8.486901837583646e-03, -1.485080911331240e-02, -3.815319741142773e-02, -8.508055045828120e-02, -7.083099777521262e-02, -8.676733045547884e+01, -8.438910074020387e+03, -5.017749716049735e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camh_b3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camh_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.610839832200109e-03, -1.003564797298089e-02, -1.067838992369988e-02, -1.167215023086967e-02, -1.325620081339206e-02, -1.589022059483712e-02, -2.052557389509884e-02, -2.927130791343963e-02, -4.684334980744711e-02, -8.117576474978046e-02, -1.526158639864039e-01, -4.081242799460968e-01, -5.259278289917371e-01, -8.069057674399526e-01, -1.371307059010355e+00, -6.852695555103043e-01, 1.048435963885090e+01, 8.302658496580477e-01, 7.318744453265514e+03, 5.013428893927485e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camh_b3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camh_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.596613205638373e-08, 1.808379532557169e-08, 2.161022148886624e-08, 2.786205310195908e-08, 3.996699213283570e-08, 6.645317688638578e-08, 1.347706141139259e-07, 3.510774915514200e-07, 1.174604188246877e-06, 2.957802828860230e-06, -6.198833785356326e-05, 4.104123659885741e-03, 1.699655967931646e-02, 2.857091594304140e-02, -2.054815474898651e-01, -2.771102785068829e+01, -3.605863376988884e+03, -5.278471189370388e+05, -5.054048589385364e+09, -1.705185737301996e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_camh_b3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_camh_b3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.322893853951711e-14, 1.037675841532031e-13, 1.423903405300139e-13, 2.240635130064624e-13, 4.284738599149845e-13, 1.079865840365176e-12, 4.011177498079542e-12, 2.553681047107244e-11, 3.394604819386173e-10, 1.207882836672123e-08, 1.546895718824392e-06, 3.641795555890715e-04, 3.138165678908144e-03, 2.038872363292199e-02, 8.036162617209606e-01, 1.978164031782002e+02, 3.768909781601409e+05, 9.984802497377436e+09, 1.210205120912847e+16, 4.024468377676132e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
