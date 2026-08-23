
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_sb98_2a_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2a", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.349375273414915e+00, -3.286813160291972e+00, -3.199168664726307e+00, -3.077808253882859e+00, -2.912562613188973e+00, -2.692953525700079e+00, -2.411144353358760e+00, -2.067410661875550e+00, -1.677725181021342e+00, -1.275652934734150e+00, -8.783032536765766e-01, -5.811941008451720e-01, -5.061095452463115e-01, -4.263263443726169e-01, -3.169462800231281e-01, -2.083294853932269e-01, -1.121713496912188e-01, -3.957846745156072e-02, -8.595517720789177e-03, -1.013595202096628e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_sb98_2a_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.245198661391687e+00, -4.159445304367592e+00, -4.039079048286300e+00, -3.871913005346588e+00, -3.643235110271446e+00, -3.337051381668155e+00, -2.939365011960517e+00, -2.444872253791354e+00, -1.870041403788282e+00, -1.283941262729400e+00, -8.491762052027310e-01, -7.155840032679543e-01, -6.351978131451369e-01, -5.188916007044704e-01, -3.562452745949801e-01, -2.125793944246109e-01, -1.256234713789275e-01, -5.146375310211750e-02, -1.136362433674176e-02, -1.343723051640395e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2a_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.925369696266852e-06, -2.080661924725800e-06, -2.327227530604606e-06, -2.736140439411429e-06, -3.458190341846689e-06, -4.853185142885398e-06, -7.915665280311109e-06, -1.594520383828256e-05, -4.255863678765841e-05, -1.581488178825176e-04, -8.074677674802040e-04, -3.185284883428479e-03, -7.854654096381615e-03, -1.235866710689362e-02, -5.110382866945738e-02, -3.166517063901159e-01, -1.552859151582860e+00, -2.496343631222230e+00, -1.801555610945446e+00, -1.094783630754727e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2a_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.695722503909572e-03, -9.119233662679251e-03, -9.767702148689996e-03, -1.078827167311161e-02, -1.245917344453052e-02, -1.535407986960263e-02, -2.078828735011632e-02, -3.216699343440785e-02, -5.915640447066751e-02, -1.244188807918242e-01, -2.730667772524810e-01, -4.132928884169401e-01, -4.190068394656684e-01, -8.942186434655824e-01, -2.242344546170264e+00, -4.555548578929896e+00, 1.410968437171401e+01, -3.917314259045618e+02, -1.275787013322809e+04, -1.131448867833006e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2a_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.125325565848655e-08, 1.324658794044175e-08, 1.671176475709134e-08, 2.323869774999418e-08, 3.699776159557673e-08, 7.091855621083496e-08, 1.746082829898509e-07, 5.977509685347550e-07, 3.078751836393509e-06, 2.351891172604287e-05, 3.147987546510855e-04, 5.407815597247397e-03, -1.693426394150768e-02, 6.777107507420581e-02, 7.078361348796121e-01, -1.423248131305256e+00, -3.556827424434739e+03, -2.958275892181798e+05, -2.583582999487453e+07, -1.152191227898193e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_sb98_2a_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_sb98_2a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.296124940062553e-14, 3.652547885377967e-14, 4.185907216182405e-14, 4.951589617839197e-14, 5.826346172648349e-14, 5.386167260946548e-14, -5.501504860772108e-14, -4.275511909664988e-13, 3.156225247554637e-11, 4.602250024403706e-09, 8.902662422203033e-07, 1.008228335763099e-04, 1.603885175766906e-02, 2.339949010548606e-03, 2.337531367601304e-01, 1.838686126270528e+02, 3.699741333383966e+05, 8.771566039022040e+08, 9.123996778580545e+12, 3.197378641348215e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
