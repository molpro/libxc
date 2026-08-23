
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pbe_jrgx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_jrgx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.790506654625697e-02, -7.690382444729618e-02, -7.546541250456991e-02, -7.339986421807621e-02, -7.043566322562195e-02, -6.618697104554275e-02, -6.011645356171061e-02, -5.153344236118897e-02, -3.986352216447145e-02, -2.634976533790567e-02, -2.066362891874373e-02, -5.128123089397864e-02, -5.701203112303976e-02, -4.432011792704516e-02, -2.793717868099771e-02, -1.038827690261638e-02, -1.015076536339608e-03, -1.279619540083241e-05, -1.313900853181070e-08, -4.219246836260678e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pbe_jrgx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_jrgx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.397764128341351e-01, -1.389942226148869e-01, -1.378606345386421e-01, -1.362117872322446e-01, -1.337997397968629e-01, -1.302382723623173e-01, -1.248960907853325e-01, -1.166631056986300e-01, -1.034761018559387e-01, -8.298355746277614e-02, -7.044587995985177e-02, -8.810140167275300e-02, -7.950809457424877e-02, -7.854820075901368e-02, -6.811974446038094e-02, -3.954354800505586e-02, -5.674584873291177e-03, -8.120051248467100e-05, -8.582356428455144e-08, -2.791120319851588e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_jrgx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_jrgx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.410529165743504e-07, 6.859052664171221e-07, 7.557941382587547e-07, 8.685162313247734e-07, 1.059449508007848e-06, 1.405996709183087e-06, 2.098616818649406e-06, 3.677539095146090e-06, 7.956457848725180e-06, 2.272806000613396e-05, 1.322883872906665e-04, 2.640786970650511e-03, 6.194766549475160e-03, 1.131834297124488e-02, 3.609970837009097e-02, 1.536333517607375e-01, 3.126523960308952e-01, 1.508855485131494e-01, 1.905961204029441e-02, 4.757773657222998e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_jrgx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_jrgx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.724379330553101e-04, -1.874290443946920e-04, -2.112026221945567e-04, -2.505581362759756e-04, -3.198797538086728e-04, -4.534859365487574e-04, -7.471022815530340e-04, -1.528222521899165e-03, -4.231178444340747e-03, -1.623443010177436e-02, -6.135818271543320e-02, 1.246984159821673e-04, 9.660102437091395e-03, 1.922805399039526e-03, -3.717781829178406e-01, -6.009912264434910e+00, -2.444067937979561e+01, -1.337258753397883e+01, -1.660874159894639e+00, -4.058585178765078e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_jrgx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_jrgx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.427352900003729e-09, 1.669366460913941e-09, 2.088429668064458e-09, 2.875117735721967e-09, 4.533337282450739e-09, 8.661137265105462e-09, 2.171684978058750e-08, 8.007902279248438e-08, 5.072447362768983e-07, 6.388200036668910e-06, 1.602074928861345e-04, -1.303622268335719e-03, -1.271831454597954e-02, -1.753443380681861e-02, 2.477645566837593e-01, 3.086337661418484e+01, 1.636847284395880e+03, 2.950784113491624e+04, 4.357088751389856e+05, 8.152066856637607e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_pbe_jrgx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_jrgx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.582355812259250e-14, -9.245498308781705e-14, -1.229264738904061e-13, -1.850229539317808e-13, -3.325400939281255e-13, -7.697438841042379e-13, -2.553243548674483e-12, -1.410883411902757e-11, -1.607779940204285e-10, -5.098969906137168e-09, -7.835725229863088e-07, -3.979489183348655e-04, -3.115808426715751e-03, -2.223718229870717e-02, -1.002873024527511e+00, -2.766579797342257e+02, -1.456950693309964e+05, -8.289687412731545e+07, -1.452023609127320e+11, -2.084427858056072e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
