
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_cap0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cap0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.284355246818258e+00, -3.221651901778777e+00, -3.133813147092166e+00, -3.012187001900353e+00, -2.846573967487479e+00, -2.626429833404588e+00, -2.343742697223597e+00, -1.998337256877111e+00, -1.605445371720788e+00, -1.200281997057739e+00, -8.105794338268724e-01, -5.417460250796574e-01, -4.757802963068402e-01, -3.911548150043850e-01, -2.800108570900163e-01, -1.793553462320226e-01, -1.237659179643654e-01, -1.174492297528812e-01, -1.465130276901783e-01, -1.967152172815487e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_cap0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cap0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.198516014909243e+00, -4.112303724152435e+00, -3.991389541795088e+00, -3.823663992072853e+00, -3.594638587662811e+00, -3.288833136288591e+00, -2.893223386693314e+00, -2.403732312184829e+00, -1.835712248301998e+00, -1.244740207368505e+00, -7.973137937457654e-01, -6.947983973883013e-01, -6.201576443801552e-01, -5.006876533941195e-01, -3.359021127914421e-01, -1.624163632280550e-01, -3.484421447321641e-02, 1.920952516179270e-02, 3.372713122340017e-02, 3.147207775729647e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cap0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cap0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.700243283683647e-06, -1.844362993639997e-06, -2.072668686972739e-06, -2.449849350690043e-06, -3.111584352315267e-06, -4.376605292868377e-06, -7.109375267817664e-06, -1.412974564968273e-05, -3.710808723155669e-05, -1.403499302750715e-04, -7.409983311262129e-04, -1.196699482103946e-03, -4.409717532731202e-04, -3.840772390575070e-03, -2.905537647640802e-02, -3.986850329828194e-01, -8.812473051942652e+00, -3.961599830281745e+02, -6.237038497048031e+04, -6.211092260456320e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cap0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cap0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.056253743930950e-03, -9.476838023377050e-03, -1.011738940975682e-02, -1.111799266195252e-02, -1.273965552214319e-02, -1.551306165812881e-02, -2.064670518129914e-02, -3.132946446926928e-02, -5.766214249294847e-02, -1.367747128352007e-01, -3.666988056059745e-01, -4.183075038781006e-01, -4.822342074885482e-01, -8.844971486233472e-01, -2.823903856970868e+00, -1.562981869074360e+01, -9.153176876385393e+01, -1.569436928397286e+03, -1.287523968578678e+05, -7.486802696727563e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cap0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cap0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.570046947556692e-08, 1.798856099619583e-08, 2.186829005410883e-08, 2.893795516689677e-08, 4.322450981871674e-08, 7.672114509957533e-08, 1.739446096221767e-07, 5.572047475781611e-07, 2.889879897302670e-06, 2.827448940605748e-05, 5.672880554430172e-04, 6.182094576517098e-03, 7.552096198772618e-03, 6.842057868759649e-02, 1.307863951755292e+00, 6.289274501697875e+01, 5.474076155586268e+03, 3.985571704873086e+06, 4.577200379885577e+10, 2.157489991170000e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cap0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cap0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.329819968985227e-14, -5.169800821790930e-14, -6.662395098695813e-14, -9.566038838589798e-14, -1.598222278949307e-13, -3.288524842293646e-13, -8.898138477709672e-13, -3.274034825052926e-12, -9.553926239674717e-12, 9.595011469527053e-10, 6.732475942665600e-08, -3.527048324349174e-04, -2.863326558867772e-03, -1.997312724348930e-02, -7.986626692713242e-01, -1.080878792079096e+02, 4.361285074282503e+05, 2.799953026048435e+10, 6.681161162542488e+16, 4.079135776870697e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
