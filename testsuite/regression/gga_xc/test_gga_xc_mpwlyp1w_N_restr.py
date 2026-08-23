
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_mpwlyp1w_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mpwlyp1w", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.392682256047596e+00, -4.310739548615050e+00, -4.195991856736959e+00, -4.037190759224483e+00, -3.821119619394624e+00, -3.534188322942206e+00, -3.166148702771450e+00, -2.716608797944261e+00, -2.202979709847508e+00, -1.661001999880470e+00, -1.121235428865836e+00, -7.127952077946614e-01, -6.088722210772352e-01, -5.125152814462639e-01, -3.762885528921944e-01, -2.374004606794974e-01, -1.278399321470524e-01, -3.990696834143211e-02, -1.890640968546152e-03, -1.452522035513979e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_mpwlyp1w_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mpwlyp1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.452943168801800e+00, -5.339282426412195e+00, -5.179999008473843e+00, -4.959325792008364e+00, -4.658609509776964e+00, -4.258452511055545e+00, -3.743988282689456e+00, -3.115152732235851e+00, -2.403796517523245e+00, -1.696702497961157e+00, -1.127977588181772e+00, -8.595889187585464e-01, -7.676119525914088e-01, -6.106633364163012e-01, -4.184101508683117e-01, -2.551791180206120e-01, -1.560949614752641e-01, -9.717606558454954e-02, -4.110435266307755e-03, -1.966991718320447e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mpwlyp1w_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mpwlyp1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.117657659606834e-06, -4.437638561076009e-06, -4.940122459850173e-06, -5.759639283402248e-06, -7.170039550833734e-06, -9.788706242939920e-06, -1.519431645315813e-05, -2.809956649758998e-05, -6.548651400832474e-05, -2.043339902033821e-04, -9.615043324435030e-04, -6.544985115152527e-03, -1.314947402500450e-02, -2.450400991045393e-02, -7.495222591410285e-02, -3.120668127769525e-01, -1.660827598543739e-01, 1.036423610517214e+02, 4.391821660301165e+02, 8.228940294918664e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mpwlyp1w_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mpwlyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.191908391600333e-02, -1.244757100990698e-02, -1.324731238415747e-02, -1.448411707319612e-02, -1.645625622193954e-02, -1.973696821189364e-02, -2.551203696228829e-02, -3.639915094267085e-02, -5.812137692356062e-02, -9.886352821279230e-02, -1.848270829745349e-01, -5.275369596410696e-01, -6.706183992062649e-01, -1.068691377467207e+00, -1.924611906347616e+00, 1.676577955818415e-01, 1.197282035131381e+02, -1.594771300679686e+03, -2.538270497997065e+04, -2.032607793674750e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mpwlyp1w_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mpwlyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.036396668561433e-08, 2.307073348809933e-08, 2.757919593163895e-08, 3.557481980559076e-08, 5.106366669317983e-08, 8.497314092234040e-08, 1.724597047107304e-07, 4.488689019963820e-07, 1.481804171298689e-06, 2.943346568982632e-06, -8.958518321672349e-05, 7.018868841238785e-03, 2.889900947189684e-02, 6.242141946381846e-02, -2.854679935210735e-02, -3.985163341509774e+01, -1.264068037821262e+04, 1.428443674335477e+06, 5.638192439165352e+09, 7.779354208946613e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_mpwlyp1w_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_mpwlyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.094270031061937e-13, 1.365010544413680e-13, 1.874559879280595e-13, 2.953377659184177e-13, 5.658339428902435e-13, 1.430280619828197e-12, 5.338676080060551e-12, 3.427807017589008e-11, 4.631172096372905e-10, 1.703808450745204e-08, 2.288109968382190e-06, 5.415275898234384e-04, 4.774511426654766e-03, 3.205231284990163e-02, 1.381985388712310e+00, 4.084927728373823e+02, 1.009574318394801e+06, -1.213821293914191e+10, -2.093303047379994e+15, -2.245699838751428e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
