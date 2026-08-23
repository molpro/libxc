
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ncap_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncap", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.308488615289852e+00, -4.226935782941608e+00, -4.112783477774747e+00, -3.954912287967890e+00, -3.740336595164873e+00, -3.455899617851042e+00, -3.092200556834202e+00, -2.650527924904467e+00, -2.151324163521048e+00, -1.632851088366809e+00, -1.105051363363348e+00, -6.659631897946097e-01, -5.631738636501181e-01, -4.735226608363336e-01, -3.527499921574244e-01, -2.394878385843466e-01, -1.651881403004064e-01, -1.650474249720130e-01, -2.743593616183266e-01, -5.446984587694962e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ncap_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.367821005004763e+00, -5.253090467618331e+00, -5.092219668632811e+00, -4.869165511804668e+00, -4.564833533883850e+00, -4.159124938334354e+00, -3.636132228440421e+00, -2.994655055467017e+00, -2.266988685811671e+00, -1.545224302896779e+00, -9.875222315489112e-01, -7.960869872918197e-01, -7.143084302110774e-01, -5.519184772556655e-01, -3.534800704726953e-01, -1.854843797922958e-01, -5.288455237452243e-02, 5.706485003064787e-02, 1.361986889965819e-01, 2.019337858081401e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ncap_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.043318709261691e-06, -4.375506229341041e-06, -4.900093046375018e-06, -5.762635087953377e-06, -7.264648178124388e-06, -1.010123182040687e-05, -1.610106754695054e-05, -3.092201045060899e-05, -7.588657792549230e-05, -2.542849391186013e-04, -1.294115483922969e-03, -7.371451625153391e-03, -1.359362783739951e-02, -2.951582193053944e-02, -1.101062565401895e-01, -7.166446978982970e-01, -1.134563844657900e+01, -6.244752657791861e+02, -1.366811859424481e+05, -1.962535688444988e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ncap_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.241947145368280e-02, -1.299917264458149e-02, -1.388035318079382e-02, -1.525202386316889e-02, -1.746011245559202e-02, -2.118425666322861e-02, -2.786830083455188e-02, -4.079694202582435e-02, -6.755356150508514e-02, -1.259980550418460e-01, -2.853396543006382e-01, -5.796064806536926e-01, -6.868954758517246e-01, -1.209759365363178e+00, -2.613557963019552e+00, -7.773881796416322e+00, -1.274284134996257e+02, -4.816824394421968e+03, -6.637837315313180e+05, -6.164076952387676e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ncap_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.605591327102592e-08, 2.976629365058307e-08, 3.601492799325216e-08, 4.727531357385998e-08, 6.960279326345022e-08, 1.201860137722318e-07, 2.575422915107373e-07, 7.284734079443483e-07, 2.835224745506219e-06, 1.554060610974303e-05, 2.142684059790986e-04, 1.212808278058100e-02, 4.005470635624150e-02, 1.294499405696641e-01, 8.055476007676461e-01, 1.318757088859603e+01, 7.421433649134196e+03, 1.218590548546587e+07, 2.240042687186110e+11, 1.671928494916563e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ncap_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ncap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.342718196800437e-14, 5.562550986209242e-14, 7.930849804811363e-14, 1.317191631474696e-13, 2.716192232128964e-13, 7.596069281624194e-13, 3.246377259003792e-12, 2.475013119965283e-11, 4.039205358022658e-10, 1.689154535664419e-08, 2.289895474472468e-06, 3.002360766422663e-04, 1.495689944726565e-03, 2.035995683970102e-02, 1.305665805366317e+00, 3.689086752395689e+02, 5.411343287123191e+05, 3.083580287859019e+10, 1.127351124064307e+17, 1.079528395671418e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
