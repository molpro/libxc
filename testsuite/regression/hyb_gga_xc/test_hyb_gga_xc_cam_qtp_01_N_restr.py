
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_cam_qtp_01_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_01", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.260985623653682e+00, -3.197568877136691e+00, -3.108738684105402e+00, -2.985751401329975e+00, -2.818293309765949e+00, -2.595660154647484e+00, -2.309513410761355e+00, -1.958665022916213e+00, -1.554768484555603e+00, -1.123247022493736e+00, -7.012233555379852e-01, -4.287011766449425e-01, -3.562992418014905e-01, -2.767186126039523e-01, -1.649935092233917e-01, -5.582627869479773e-02, -9.462825712406656e-04, -5.142243057609391e-03, -1.401143291379602e-03, -1.710159600044648e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_cam_qtp_01_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_01", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.098963135083305e+00, -4.011720447819192e+00, -3.889481800710482e+00, -3.720178729840281e+00, -3.489567447639525e+00, -3.182915653447217e+00, -2.789134458022541e+00, -2.308796837369662e+00, -1.767335307761365e+00, -1.231715555754862e+00, -7.992003178707008e-01, -5.651907285541107e-01, -4.876249274263747e-01, -3.770593316072049e-01, -2.428379465568581e-01, -1.267031408933808e-01, -4.339362848530648e-02, -6.908827922738559e-03, -1.834012793349711e-03, -2.266329730844939e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_01_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_01", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.939660392458777e-06, -3.163975809077406e-06, -3.515465644914170e-06, -4.086862054022585e-06, -5.065397117853349e-06, -6.868272527555010e-06, -1.054362091957951e-05, -1.913123973437614e-05, -4.301859955084831e-05, -1.241878646388718e-04, -4.847611994359031e-04, -2.874133770518048e-03, -5.323634785165701e-03, -7.547932478040652e-03, -4.924851914101892e-03, 1.898600109583469e-01, 3.369031018481182e+00, 4.194341328047993e+00, -2.796384005113658e-05, -6.308624266702911e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_01_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.055884131555786e-03, -9.452298924996822e-03, -1.005148113693317e-02, -1.097647501418774e-02, -1.244736665889320e-02, -1.488360313263185e-02, -1.914163054658956e-02, -2.707095209020761e-02, -4.254061466649152e-02, -7.019970332492413e-02, -1.188640709661750e-01, -3.584112896906392e-01, -4.735643211672450e-01, -6.757270620662078e-01, -9.418497701098454e-01, 3.146392315383517e-01, 8.066893655887958e+00, -9.223944098000585e+01, -1.965924652880642e+03, -1.902856898051053e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_01_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.431461492510883e-08, 1.618673634947749e-08, 1.929573082346791e-08, 2.478427551138651e-08, 3.534005183144999e-08, 5.817698042279562e-08, 1.158701923914488e-07, 2.904643164756308e-07, 8.651534271570897e-07, -1.125933096395977e-08, -1.297673027211978e-04, 1.637922421114231e-03, 7.543716662128211e-03, -4.759379967354108e-03, -5.290640103333641e-01, -3.164457113008212e+01, -2.811450347278669e+03, 1.308944332499268e+05, -3.548780159728530e+02, -6.215972494444866e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cam_qtp_01_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cam_qtp_01", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.640804827376665e-14, 9.519520598021397e-14, 1.304892366547719e-13, 2.050126128843252e-13, 3.911077000427938e-13, 9.820487473111978e-13, 3.626210638204898e-12, 2.285522078150366e-11, 2.983007756366663e-10, 1.023073294998482e-08, 1.218990554011173e-06, 2.666653378822324e-04, 2.189571592152039e-03, 1.303833428282321e-02, 3.971982523326271e-01, 3.918901530797253e+01, 3.770521043504020e+03, 3.689880648166105e+05, 9.662980316153549e+07, 1.314273793091493e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
