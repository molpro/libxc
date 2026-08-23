
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_th_fco_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fco", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.940821579859536e+00, -4.849343731483556e+00, -4.719394044049547e+00, -4.536258460906265e+00, -4.281651765761943e+00, -3.935792256756629e+00, -3.484081281791858e+00, -2.931777953309317e+00, -2.326193296943912e+00, -1.761210945949220e+00, -1.256375509144536e+00, -8.849479987764832e-01, -7.935322955009700e-01, -6.877517228543757e-01, -5.608326579226316e-01, -4.468616959462170e-01, -3.562157776234272e-01, -2.758305735947866e-01, -1.815934419009097e-01, 1.444936220409614e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_th_fco_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fco", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.623802028972100e+00, -6.524623055309549e+00, -6.379235448732685e+00, -6.165779270801316e+00, -5.853207028382930e+00, -5.400522807580211e+00, -4.761646334272089e+00, -3.903819460933502e+00, -2.850318407847181e+00, -1.764629019253945e+00, -1.113588832117377e+00, -1.083465924219515e+00, -9.858471550179813e-01, -7.989723694033959e-01, -5.755821362300850e-01, -3.811982144406663e-01, -2.416043598107917e-01, -1.537187875863252e-01, -1.295810873262244e-01, -2.749235804798033e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th_fco_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fco", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.569038800144377e-06, 2.813660427313184e-06, 3.169249396980503e-06, 3.681597940942958e-06, 4.394581730813619e-06, 5.265423266371928e-06, 5.724664852101522e-06, 2.329471514570921e-06, -2.526800132729560e-05, -2.096653688468646e-04, -1.303250697474910e-03, -2.155227448944258e-03, -2.559545937689457e-03, -1.687288945039453e-02, -9.328139344356078e-02, -8.088813360639081e-01, -1.274567547553447e+01, -4.240766065621034e+02, -2.641818920618869e+04, 6.909555046014062e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th_fco_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fco", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.554773968840855e-03, -9.499774219361882e-03, -1.095436129384710e-02, -1.325963231561715e-02, -1.706829443657400e-02, -2.374527518201384e-02, -3.648460940704050e-02, -6.390245267320044e-02, -1.335086919715431e-01, -3.427464591897521e-01, -8.071495993794183e-01, -7.066947480186191e-01, -8.075591567595259e-01, -1.370637024622759e+00, -3.341410269066103e+00, -1.292206773607508e+01, -8.813226291341171e+01, -5.095963293296295e+02, 4.075937892334514e+05, 1.407057830718457e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th_fco_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fco", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.724596205960333e-09, -3.050485818639066e-09, 2.113472739371322e-09, 1.307344225715443e-08, 3.933261118890996e-08, 1.130053433929706e-07, 3.680111971931617e-07, 1.542374671905346e-06, 9.545654559768525e-06, 1.006476030527480e-04, 1.676879173782070e-03, 1.566958337314569e-02, 4.469086008445826e-02, 1.465900658187349e-01, 1.412506978882799e+00, 4.246108504949195e+01, 4.323992260385960e+03, 8.337092963040232e+04, -1.409981970464770e+11, -3.639340205077324e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th_fco_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th_fco", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.315444286052957e-13, -3.120888980204044e-13, -4.666589399684030e-13, -7.994464994398991e-13, -1.638545813212255e-12, -4.265806577469634e-12, -1.534141986454241e-11, -8.575964623208352e-11, -8.796434626772347e-10, -2.098775397124618e-08, -1.683712292807836e-06, -6.671028379407165e-04, -8.252332489091444e-03, -4.889565483394483e-03, 5.596760085132904e-01, 2.742031533480516e+02, 8.538426940248425e+05, 3.815770433715002e+10, 7.337214255012923e+16, 3.516899374232844e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
