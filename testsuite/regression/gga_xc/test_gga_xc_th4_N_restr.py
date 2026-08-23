
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_th4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.469834992676968e+00, -4.378697393049608e+00, -4.251552266021851e+00, -4.076555732708515e+00, -3.840354990336917e+00, -3.530403467381407e+00, -3.139884444221685e+00, -2.675857452152494e+00, -2.168233080140715e+00, -1.662412588046920e+00, -1.132772932362612e+00, -7.134965649119932e-01, -6.147470712734717e-01, -5.071495524451264e-01, -3.661646996601238e-01, -2.344308722579677e-01, -1.416470921538276e-01, -9.055475733939802e-02, -6.574853733034940e-02, -4.996310760191553e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_th4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.016215045326453e+00, -5.883436670888758e+00, -5.696909611118453e+00, -5.437630914287202e+00, -5.082710873252204e+00, -4.607569279980619e+00, -3.991740706907945e+00, -3.230602116550719e+00, -2.356634329606687e+00, -1.486824936678722e+00, -9.539600637091877e-01, -8.972448594612321e-01, -8.001250277901588e-01, -6.259702311081364e-01, -4.075084072725175e-01, -2.104279535437218e-01, -7.598344705853599e-02, -8.516241862943218e-03, 1.448705153305014e-02, 1.944444735611190e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.589223620078111e-07, 5.090741927528427e-07, 4.068117803216809e-07, 1.846470131134449e-07, -3.316364037181713e-07, -1.635813188335075e-06, -5.304515794463437e-06, -1.719731391730274e-05, -6.363551454687082e-05, -2.899923926668640e-04, -1.491203120006110e-03, -3.957802379749761e-03, -6.509210886805935e-03, -1.776927237900286e-02, -7.556206578477462e-02, -5.599359783438955e-01, -8.014545419864792e+00, -2.697909935995262e+02, -3.015417804894165e+04, -2.003891104122078e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.389462863479802e-02, -1.468367952304130e-02, -1.589481131262323e-02, -1.780753448326705e-02, -2.095486436249502e-02, -2.644966101087897e-02, -3.689868452271509e-02, -5.935908519405753e-02, -1.164840720846322e-01, -2.891592631860857e-01, -6.790525184222723e-01, -6.248584705738910e-01, -7.366518981476327e-01, -1.255307576699712e+00, -3.088484739015675e+00, -1.206632981289314e+01, -9.148634897585285e+01, -1.902212735154588e+03, -1.740729319567355e+05, -1.204702794690774e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.355327642114050e-08, 2.889300115605023e-08, 3.824967990901316e-08, 5.602915652240632e-08, 9.383326982797742e-08, 1.877170047616160e-07, 4.765452311281771e-07, 1.670931526213126e-06, 9.095930817936348e-06, 8.789575496412600e-05, 1.390726817360386e-03, 1.183572814111223e-02, 3.138485197240242e-02, 1.072843989357033e-01, 1.077324426573401e+00, 3.587816131204327e+01, 5.060486144172735e+03, 4.724157076357859e+06, 6.051040783898742e+10, 3.369131867061927e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.778850158616517e-13, -3.488057742209487e-13, -4.801477007648161e-13, -7.505822163821081e-13, -1.396628707487966e-12, -3.295887924107305e-12, -1.074941486870737e-11, -5.446589575034794e-11, -5.033679777082145e-10, -1.061420598148670e-08, -7.140649544501784e-07, -2.192972971747602e-04, -2.010825286847400e-03, 2.688192485232500e-03, 3.439931791454561e-01, 1.232754810153663e+02, 3.131955640753417e+05, 1.116955951846416e+10, 1.585157731918477e+16, 4.848521453618886e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
