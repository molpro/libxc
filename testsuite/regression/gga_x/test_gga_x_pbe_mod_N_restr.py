
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_mod_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mod", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.303466276367240e+00, -4.221751960329578e+00, -4.107360524739825e+00, -3.949130721884385e+00, -3.734007484915799e+00, -3.448713072153648e+00, -3.083623204114382e+00, -2.639581689487532e+00, -2.136057198985866e+00, -1.609602212936091e+00, -1.082697377053853e+00, -6.644481904066177e-01, -5.627474307066056e-01, -4.720756657447857e-01, -3.492479263706236e-01, -2.286350560983627e-01, -1.207835981703202e-01, -4.187678279675816e-02, -8.769442302023591e-03, -9.701617071528214e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_mod_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mod", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.379092124253585e+00, -5.264669710259001e+00, -5.104250918064137e+00, -4.881865834935419e+00, -4.578537925908505e+00, -4.174370258205091e+00, -3.653843485786744e+00, -3.016699365543531e+00, -2.298392214290801e+00, -1.600228460729708e+00, -1.044794247471780e+00, -7.992728034279557e-01, -7.153008247148203e-01, -5.548828072442956e-01, -3.611011173824484e-01, -2.158508037410620e-01, -1.361095408981461e-01, -5.452650327980316e-02, -1.167947254180576e-02, -1.293530283732018e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_mod_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mod", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.850530121198844e-06, -4.164162291716291e-06, -4.659002647927073e-06, -5.471557709891479e-06, -6.883711678497011e-06, -9.542363772513305e-06, -1.513700068046634e-05, -2.882153220976663e-05, -6.935587355755481e-05, -2.196769030214447e-04, -1.062189456295486e-03, -6.953720587684257e-03, -1.301370880219473e-02, -2.769770658274974e-02, -9.852542853383024e-02, -4.765535526247750e-01, -1.690342705581205e+00, -2.950142951344086e+00, -3.571382005069529e+00, -3.945193737057419e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_mod_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mod", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.223536392666099e-02, -1.279908464215509e-02, -1.365491098425719e-02, -1.498455514484847e-02, -1.711833157837845e-02, -2.069752328560070e-02, -2.705057397552332e-02, -3.898832174689427e-02, -6.112792094862416e-02, -8.713618507907311e-02, -1.333460381185535e-01, -5.652814006359531e-01, -6.795299311004394e-01, -1.170892442628019e+00, -2.176630433177748e+00, 2.182683615328862e+00, 2.863496615211828e+01, -4.078015462251862e+02, -1.344734023588133e+04, -1.116614217782143e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_mod_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mod", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.385537539621680e-08, 2.721749101361285e-08, 3.286780486031797e-08, 4.301656455772235e-08, 6.303022282538819e-08, 1.079221773650544e-07, 2.272605225856287e-07, 6.129335985222575e-07, 1.945678418271852e-06, -1.349295217080401e-06, -2.222081867375026e-04, 1.084100430289981e-02, 3.701943276868472e-02, 1.132911738835462e-01, 3.581205684422699e-01, -4.478363977274458e+01, -5.072949727853740e+03, -3.535914126613969e+05, -4.993254486656080e+07, -4.087351089507060e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_mod_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mod", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.163753753946193e-14, 6.563743536322496e-14, 9.261839717268990e-14, 1.517477686623727e-13, 3.076582913100265e-13, 8.439599574927358e-13, 3.543533684294788e-12, 2.685578735339919e-11, 4.506113607426454e-10, 2.053810596172996e-08, 2.939765770513012e-06, 3.313515154262984e-04, 1.924690755138906e-03, 2.214672239594007e-02, 1.510096261101190e+00, 5.320814333939149e+02, 4.994669918611428e+05, 1.072174654976284e+09, 1.813428296506447e+13, 1.152284637757789e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
