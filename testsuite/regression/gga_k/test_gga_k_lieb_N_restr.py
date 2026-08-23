
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_lieb_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lieb", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.575944963959742e+01, 9.210234532734185e+01, 8.710172097097491e+01, 8.041353148111354e+01, 7.174698706097030e+01, 6.101289747254939e+01, 4.854413282985978e+01, 3.531255241706554e+01, 2.292583383117451e+01, 1.304316647366615e+01, 5.975103581279273e+00, 2.261529518232746e+00, 1.644690431608895e+00, 1.135763063663741e+00, 6.116767451410937e-01, 2.872785749459325e-01, 1.592701877825884e-01, 1.230630554188423e-01, 1.121880047157768e-01, 1.067565608538320e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_lieb_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lieb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.475054814429589e+02, 1.414339430094064e+02, 1.331343629744701e+02, 1.220386552431242e+02, 1.076697190247889e+02, 8.988914626202491e+01, 6.926586408267602e+01, 4.744741682142289e+01, 2.722159399469161e+01, 1.194186033639798e+01, 4.527682049491154e+00, 3.301611243148460e+00, 2.589021520936349e+00, 1.600092521656172e+00, 6.513533725609096e-01, 1.060035780075466e-01, -8.362298582099166e-02, -1.153159267468789e-01, -1.118559376727917e-01, -1.067525012031906e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lieb_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lieb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.297620194927125e-04, 1.379543166464546e-04, 1.506378610289157e-04, 1.709161677429562e-04, 2.048672490643701e-04, 2.655976157684128e-04, 3.850291740562203e-04, 6.539376973900965e-04, 1.386416957360453e-03, 3.942276896935690e-03, 1.446472237783183e-02, 3.752206931392443e-02, 5.651775395987981e-02, 1.087995504962020e-01, 3.468536704141462e-01, 1.996229625680124e+00, 2.366342213027009e+01, 7.220307616211589e+02, 8.136323210434192e+04, 6.019131930183093e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lieb_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lieb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.166320730991168e-01, 6.313929556768730e-01, 6.533513669707575e-01, 6.865213229325325e-01, 7.377801304444029e-01, 8.197558856356808e-01, 9.579610066112133e-01, 1.211105861242477e+00, 1.738244265075553e+00, 3.012520941287395e+00, 5.259189988786657e+00, 4.308957495705917e+00, 4.567755009696621e+00, 6.365304185891428e+00, 1.197555728931406e+01, 3.809404671917747e+01, 2.986862468728559e+02, 7.566966097601442e+03, 7.851984603842985e+05, 5.530250532660264e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lieb_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lieb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.245766220488622e-07, -8.189543886032085e-07, -9.764666309743415e-07, -1.257058297712170e-06, -1.806068414947926e-06, -3.035550555512467e-06, -6.379349577156309e-06, -1.840186640660972e-05, -8.271358588856930e-05, -6.687801522244437e-04, -9.003457756652771e-03, -6.058466192126885e-02, -1.374544849767868e-01, -5.093816878876362e-01, -5.177042319753419e+00, -1.714786750244321e+02, -2.409595970606342e+04, -2.243368035428569e+07, -2.848692096547294e+11, -1.559038539109114e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lieb_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lieb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
