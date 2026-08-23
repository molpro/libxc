
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_bcgp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bcgp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.321439723640196e+00, -4.239995493903962e+00, -4.125993556845261e+00, -3.968325705914721e+00, -3.754012706012960e+00, -3.469880976263346e+00, -3.106428420847793e+00, -2.664540174527077e+00, -2.163154022866392e+00, -1.636181120356941e+00, -1.101973355166009e+00, -6.687728238735530e-01, -5.645044889395082e-01, -4.757876072472805e-01, -3.543737362821878e-01, -2.328592750111649e-01, -1.219172937915273e-01, -4.193509984257211e-02, -8.770024830817411e-03, -9.701625356749173e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_bcgp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bcgp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.359407883109178e+00, -5.244853814235135e+00, -5.084263032325252e+00, -4.861669370564843e+00, -4.558131008677364e+00, -4.153876648129160e+00, -3.633773896490160e+00, -2.998688195525950e+00, -2.286939060093551e+00, -1.602947016373166e+00, -1.052697470788582e+00, -7.951956718682028e-01, -7.132643323729815e-01, -5.517433949973162e-01, -3.601433611239345e-01, -2.208255800470733e-01, -1.395089105833245e-01, -5.475194550842208e-02, -1.168179897546939e-02, -1.293533597753126e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bcgp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bcgp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.318873765735462e-06, -4.668669711525402e-06, -5.220140106935549e-06, -6.124618476249894e-06, -7.693653039348689e-06, -1.063900156956814e-05, -1.680652240491593e-05, -3.176186598409553e-05, -7.535952000867389e-05, -2.328436414966166e-04, -1.109593736369551e-03, -7.743578783424147e-03, -1.464064578888070e-02, -3.070284800276461e-02, -1.058676855395333e-01, -4.800744030420688e-01, -1.562371791575483e+00, -2.617349689775660e+00, -3.149441706092283e+00, -3.478065251245062e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bcgp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bcgp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.240477552515693e-02, -1.297643712477446e-02, -1.384363712462981e-02, -1.518914023769908e-02, -1.734311106535659e-02, -2.093909773522162e-02, -2.725794643171704e-02, -3.884708995483088e-02, -5.884639902780035e-02, -7.411687804249809e-02, -9.293067021754560e-02, -5.713326948994244e-01, -6.883023059411645e-01, -1.177498572863406e+00, -2.010098237310968e+00, 3.391276682688466e+00, 2.421983536318787e+01, -4.272431670407217e+02, -1.347169037781766e+04, -1.116639967941514e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bcgp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bcgp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.606625017959685e-08, 2.969272410092644e-08, 3.577055827795683e-08, 4.664056184933916e-08, 6.792881881841316e-08, 1.151175281991336e-07, 2.377854919704185e-07, 6.145223756390837e-07, 1.686547540426262e-06, -6.650211299304898e-06, -3.342198933617480e-04, 1.150266221123981e-02, 4.089182060992477e-02, 1.175657666320185e-01, 2.056937216101068e-01, -5.201815793462023e+01, -4.851868905480538e+03, -3.150433319088562e+05, -4.404203369000092e+07, -3.603399747427061e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_bcgp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_bcgp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.532909451948202e-14, 8.298813327549358e-14, 1.169895852297684e-13, 1.913993835822451e-13, 3.871681725152588e-13, 1.058169732675348e-12, 4.415295197891681e-12, 3.308928952420163e-11, 5.435638800541805e-10, 2.386967496605918e-08, 3.342888424231418e-06, 4.147074391971284e-04, 2.446052762163590e-03, 2.752820396423871e-02, 1.791403418339739e+00, 5.729800492068624e+02, 4.727019212958378e+05, 9.542445940364417e+08, 1.599419650529446e+13, 1.015850958126954e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
