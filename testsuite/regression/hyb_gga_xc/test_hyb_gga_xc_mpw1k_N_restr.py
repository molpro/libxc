
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_mpw1k_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1k", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.543925549716573e+00, -2.496202828909844e+00, -2.429349590075176e+00, -2.336779113302204e+00, -2.210721042287960e+00, -2.043120827613258e+00, -1.827771009704160e+00, -1.564137100007543e+00, -1.262418501060715e+00, -9.458122116649819e-01, -6.376161458859465e-01, -4.269557007126811e-01, -3.761629041074044e-01, -3.096954324553164e-01, -2.217988661567896e-01, -1.385206456149042e-01, -7.798171733982200e-02, -2.039523343893818e-02, -3.927967864408435e-04, -9.641796191884673e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_mpw1k_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.205212187207369e+00, -3.139324679038818e+00, -3.046949975868085e+00, -2.918887937422862e+00, -2.744194475441617e+00, -2.511344457771846e+00, -2.211120138777604e+00, -1.842177145157465e+00, -1.420079912205505e+00, -9.905905463129611e-01, -6.505129821558778e-01, -5.449640268758758e-01, -4.903041318748949e-01, -3.963187676698858e-01, -2.697266409052756e-01, -1.426325664931883e-01, -7.303096523546951e-02, -5.235279054251697e-02, -1.446418828326618e-03, -3.511768472020421e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1k_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.779513578577332e-06, -1.924749168647806e-06, -2.153626265993340e-06, -2.528796402175236e-06, -3.179142989007577e-06, -4.399181508870073e-06, -6.955724070699756e-06, -1.319859135398753e-05, -3.196975947461180e-05, -1.064302268316114e-04, -5.200858980467758e-04, -1.007724835479352e-03, 5.449392623567261e-04, -2.553482455806716e-03, -1.921245837114553e-02, -2.163939438498524e-01, -2.090382012473981e+00, 5.669516252855206e+01, 2.512183246863856e+02, 4.706955356394947e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1k_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.079742758657568e-03, -7.402250883490797e-03, -7.891534525804064e-03, -8.651189381732854e-03, -9.870088859110213e-03, -1.191913429042529e-02, -1.559558121252382e-02, -2.280586200107906e-02, -3.867830621679314e-02, -7.832028265727954e-02, -1.951211571837884e-01, -3.338163870049939e-01, -3.805640536184053e-01, -7.046270033740825e-01, -2.060725663511231e+00, -8.157574782552057e+00, 4.536880128082817e+01, -8.725799031119573e+02, -1.353372147192534e+04, -2.407767440393355e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1k_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.421979429390934e-08, 1.615497776183889e-08, 1.939399057621251e-08, 2.518220249055442e-08, 3.653494645388090e-08, 6.192959796285304e-08, 1.301934664411638e-07, 3.665431665173311e-07, 1.518507198661456e-06, 1.036838183017935e-05, 1.872574239529379e-04, 5.945438070386122e-03, 9.465588380013190e-03, 6.311986073274631e-02, 8.902237804539890e-01, 2.508036458591739e+01, -4.711758390041676e+03, 7.448661122676922e+05, 3.225186280356154e+09, 4.449793191100470e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_mpw1k_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_mpw1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.068992579313811e-14, -2.296573873553939e-14, -2.617414397833706e-14, -2.985722115514905e-14, -2.867174257743908e-14, 1.815331435667471e-14, 4.685707117145111e-13, 5.796003145083476e-12, 1.135559936186933e-10, 5.126829479321856e-09, 5.989797693343402e-07, -3.834076112467660e-04, -5.128266633335655e-03, -2.200800715006019e-02, -5.967851081347927e-01, -1.461161263454554e+01, 5.093816608316905e+05, -6.971750318129307e+09, -1.197416031317080e+15, -1.284540968309199e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
