
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m05_2x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.481179377257376e+00, -1.460194495534947e+00, -1.432937957479003e+00, -1.397500536873495e+00, -1.348692908836346e+00, -1.273511774152671e+00, -1.160421243065376e+00, -1.062499457047331e+00, -9.785805126516299e-01, -7.523799293256125e-01, -6.330345031588973e-01, -3.456239271170310e-01, -2.437266206638589e-01, -2.077484065150490e-01, -1.582232308523787e-01, -1.387032247637755e-01, -1.262946634190466e-01, -6.540002874898805e-02, -1.448240269903728e-02, -1.606607573720633e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m05_2x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.577947254755929e+00, -1.484531821595798e+00, -1.384223085490965e+00, -1.303303060917703e+00, -1.284435432654182e+00, -1.328755918558441e+00, -1.205254092786963e+00, -6.562860545460589e-01, -9.347123215525091e-01, -4.106517966547135e-01, -3.888081480502457e-01, -1.943570274846011e-01, -1.810112381234855e-01, -1.459497648778513e-01, -1.441244697247003e-01, -9.418124895421497e-02, -5.973579561076706e-02, -7.881345632751890e-02, -1.922082051027292e-02, -2.142014863188833e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_2x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.325278613529442e-06, -1.440267181609328e-06, -1.625380190929441e-06, -1.936238848019953e-06, -2.486326034184300e-06, -3.523704303796348e-06, -5.696287521301493e-06, -1.160135168486919e-05, -3.177351303367528e-05, -1.026838131457454e-04, -6.210428887497061e-04, -3.617075175359592e-03, -5.636218920453037e-03, -1.218898800613732e-02, -4.463580210399710e-02, -2.891050072226110e-01, -1.767477106248738e+00, -4.607342451863812e+00, -5.898042119495811e+00, -6.533365293216365e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_2x_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.674464660190140e-03, -8.223917924430710e-03, -9.716600000552199e-03, -1.043277536602577e-02, -9.125601374212139e-03, -5.292255961593307e-03, -4.260217471162236e-03, -1.414354629544397e-02, -3.027058154577556e-03, -8.833658298264994e-03, -6.981233829150872e-03, -1.928821945566761e-02, -5.128961472046695e-02, -5.741911843983440e-02, -1.207981797048948e-02, -2.509237313192015e-02, -6.365345955558215e-02, -5.529492093345066e-03, -6.478460206032284e-05, -1.002786362043240e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_2x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.016973101557292e-02, -1.675741056797809e-02, -1.122193298433218e-02, -2.692604588616370e-03, 7.891474494104846e-03, 1.017805444212127e-02, -2.580020986029647e-02, -4.592864220642778e-02, 1.413944723627043e-01, -3.467497916121025e-01, 4.694171904425726e-01, 2.640461011165168e-01, 8.740389766949013e-01, 1.869530375967523e+00, -7.711368824330039e+00, 4.858853488256872e+00, 1.624359682352005e+02, -1.726117495020905e+01, -2.142338689173582e+04, -1.848292696450376e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_2x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.576747310472438e-09, 1.138343099983032e-08, 1.438194857911371e-08, 1.954580800923349e-08, 2.876770386105058e-08, 4.657945044043095e-08, 9.932808404121498e-08, 4.181765752852200e-07, 1.120409327331558e-06, 7.179903470343257e-06, 5.686478525525091e-06, 9.380255801912669e-03, 2.327626066358557e-02, 7.684222999347343e-02, 2.442227879403670e-01, -2.058521184551920e+01, -4.127552859812470e+03, -5.383344502056299e+05, -8.236617881834903e+07, -6.768679479157127e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_2x_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.988441127419644e-04, 3.135196734380147e-04, 1.735490330130203e-04, -4.605816662934496e-05, -3.295962406516736e-04, -4.306398714498142e-04, 4.050787691265925e-04, 8.232016732793349e-04, -4.323088716791462e-03, 8.004589042826613e-03, -1.736062261782835e-02, -4.230105213469291e-02, -4.314811918899407e-01, -1.346712108413006e+00, 4.178930514471872e+00, -2.532931984370729e+00, -9.389848576446504e+01, -4.883374965263780e+02, -6.788240052418091e+02, -7.791821405818735e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_2x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.777253532310777e-14, 2.270200545698635e-14, 3.231145207217988e-14, 5.369915836946342e-14, 1.111223113056641e-13, 3.116467436383322e-13, 1.333478281131289e-12, 1.081002774066894e-11, 2.064342122068235e-10, 9.600101100801344e-09, 1.718819715407579e-06, 1.723560517232608e-04, 8.335754084852578e-04, 9.746094733622373e-03, 6.841279217241372e-01, 3.227902536458362e+02, 5.222581769446378e+05, 1.674452728781459e+09, 2.994828435482717e+13, 1.908219712684546e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_2x_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.334668697121108e-11, -4.815435227197756e-11, -7.144390207895222e-11, -1.063112133851080e-10, -1.483092228371085e-10, -1.673596007893520e-10, -3.464900474634763e-10, -4.345739520391184e-09, -5.863709202453378e-09, -2.045227543957520e-07, -4.263101027640257e-06, -3.259280816897692e-04, -2.884618229767179e-03, -1.577257844016624e-02, -5.086381203047144e-02, -4.492730986721937e+00, -9.071048457649331e+02, -1.210326723330137e+04, -9.237540682928644e+04, -1.056230097307540e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m05_2x_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m05_2x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.356218451774810e-06, -7.164122983909415e-06, -3.598583847127593e-06, 1.944800312222819e-06, 9.020281856308650e-06, 1.140038969960853e-05, -9.312755768789087e-06, -1.558110240369091e-05, 1.134072335741976e-04, -1.832162759346108e-04, 6.416343989827212e-04, 4.943533083050103e-03, 1.914901589381992e-01, 8.643102831502292e-01, -2.522109233379634e+00, 2.791652491399089e+00, 9.934131423423996e+01, 4.803917022802975e+02, 7.256223917433157e+02, 8.889044268421508e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
