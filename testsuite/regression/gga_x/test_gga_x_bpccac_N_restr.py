
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_bpccac_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bpccac", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.305527506234435e+00, -4.223928771929497e+00, -4.109714046129878e+00, -3.951761664231288e+00, -3.737090685608659e+00, -3.452573635660606e+00, -3.088919787399978e+00, -2.647780145469324e+00, -2.150587051564350e+00, -1.636352240232812e+00, -1.109025554052470e+00, -6.652979356885049e-01, -5.628922604158347e-01, -4.730123607635335e-01, -3.529822551526861e-01, -2.399823384594277e-01, -1.204249406473710e-01, -1.380694182059036e-02, -1.249912480911544e-04, -1.651393451545206e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_bpccac_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bpccac", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.371228807856840e+00, -5.256381027689875e+00, -5.095314582121189e+00, -4.871919104214619e+00, -4.566960140441286e+00, -4.160033363906051e+00, -3.634547623793661e+00, -2.987881369452622e+00, -2.250891245106057e+00, -1.524721845428535e+00, -9.776445254439466e-01, -7.961343672817761e-01, -7.147409708326502e-01, -5.514961953727577e-01, -3.496326779765578e-01, -1.958333532397530e-01, -1.630419352108320e-01, -5.139620764816939e-02, -5.109690101648624e-04, -6.631495471613019e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bpccac_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bpccac", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.964390797009172e-06, -4.292071541728171e-06, -4.810131060503605e-06, -5.663450032655805e-06, -7.153609635417951e-06, -9.980958551066652e-06, -1.600879586088067e-05, -3.110030117126914e-05, -7.779365163811787e-05, -2.644137784415719e-04, -1.334537655547906e-03, -7.296473588940224e-03, -1.329344219705453e-02, -2.941992458668036e-02, -1.140233073798470e-01, -6.647588184128108e-01, 1.678019983123630e-01, 7.433218351543431e+01, 9.374541902242828e+01, 9.365801293250576e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bpccac_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bpccac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.244122713702687e-02, -1.302919531692362e-02, -1.392477234198809e-02, -1.532336010595401e-02, -1.758664900639713e-02, -2.143792073117323e-02, -2.845699497291646e-02, -4.237903519544054e-02, -7.177481910454925e-02, -1.250579802685834e-01, -2.356168614451951e-01, -5.880051896072930e-01, -6.860289825246315e-01, -1.239901322866656e+00, -2.760086842895797e+00, 2.194770931908431e+00, 1.945875523839422e+02, -3.644084258394603e+03, -5.555280569197695e+03, -5.187633419495542e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bpccac_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bpccac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.622128915302101e-08, 3.003501722539768e-08, 3.648719773115660e-08, 4.819644200989739e-08, 7.167213344121357e-08, 1.258181258048491e-07, 2.773029243248543e-07, 8.228150587663281e-07, 3.408229373130577e-06, 1.562885072578322e-05, 8.729284913281577e-05, 1.279997542689797e-02, 3.960252180843635e-02, 1.408932700137371e-01, 9.616525250317517e-01, -4.177914015792236e+01, -1.694245319699469e+04, 7.012041763456119e+06, 1.350158202274765e+09, 9.757899257346587e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bpccac_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bpccac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.534754275967944e-14, 4.500599500243004e-14, 6.366533096111140e-14, 1.047097856002622e-13, 2.135661027264602e-13, 5.915700668923780e-13, 2.525369845023113e-12, 1.972515788741306e-11, 3.507629761995172e-10, 1.777796896580163e-08, 2.717439919402870e-06, 2.333686997210371e-04, 1.302042952049959e-03, 1.588606748479007e-02, 1.232026388985773e+00, 6.314211322067200e+02, 1.133072308036841e+06, -2.273977677416750e+10, -4.867558558403399e+14, -2.747046333447643e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
