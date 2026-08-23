
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_n12_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_n12", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.528833539946199e+00, -4.437878674598466e+00, -4.310342334838022e+00, -4.133468529970696e+00, -3.891961627101615e+00, -3.569328829741941e+00, -3.151252251050723e+00, -2.632947892757680e+00, -2.041234873225176e+00, -1.505519655276291e+00, -1.065792250902493e+00, -6.753415122302240e-01, -5.654299422292542e-01, -4.657800060302597e-01, -3.251548929790447e-01, -2.028286725630717e-01, -4.781192835926517e-02, -1.671246076094010e-02, -7.414981161383376e-03, -9.535746008746311e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_n12_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_n12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.014844218921541e+00, -5.901112049168058e+00, -5.742675048892058e+00, -5.525111944117168e+00, -5.232497876096001e+00, -4.850255272684766e+00, -4.368671735445135e+00, -3.773152672885976e+00, -2.952210400591061e+00, -1.556205782172190e+00, -7.612436723686903e-01, -8.258971171614465e-01, -7.220745334469727e-01, -5.763771661349480e-01, -3.500457259794515e-01, -2.298234528329091e-01, -2.009113113709625e-01, -2.174578385089378e-02, -9.448030427626212e-03, -1.265716259996450e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_n12_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_n12", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.057624375254220e-07, -1.147248587373603e-07, 4.900052272823320e-08, 3.656480264852248e-07, 1.035257094939464e-06, 2.608002270990190e-06, 6.729216197492587e-06, 1.813694770934111e-05, 3.850321552764995e-05, -1.538248578363887e-04, -1.712029082437882e-03, -7.166682862554868e-03, -1.535354684690227e-02, -2.204573391152310e-02, -9.131514184431959e-02, -2.468632959791772e-01, 1.008371152602608e+01, 1.472222340052106e+01, -1.126181603321663e-02, -6.011336353674404e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_n12_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_n12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.164986495651021e-03, -6.064957669134262e-03, -5.863199276508618e-03, -5.440493547643676e-03, -4.526011591575261e-03, -2.534130058920501e-03, 1.330600190214930e-03, 2.298355632117816e-03, -8.199717579430345e-02, -9.216299523975461e-01, -2.414316018210587e+00, -4.137808615048453e-01, -6.180874743565024e-01, -1.027344766377452e+00, -4.312988783708055e+00, 4.088530413746586e+01, -2.096082948145550e+02, -7.545180080327754e+02, -8.547709640243718e+03, -1.067982151501840e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_n12_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_n12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.112266035961408e-08, -7.235518663245898e-08, -9.194456039388962e-08, -1.289386996857624e-07, -2.067855620467822e-07, -3.951084496881724e-07, -9.251874888519482e-07, -2.421440165871815e-06, 1.915155484106969e-06, 3.399075319624604e-04, 6.274792289115048e-03, -3.166218899528280e-03, 1.450939266226577e-02, 4.411934581254983e-02, 2.158137552836147e+00, -2.565196693896210e+02, 8.381315207776921e+03, 1.793358486249686e+06, 6.583601062962200e+06, -6.161363241609154e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_n12_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_n12", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.548154603450931e-13, 9.398469443629824e-13, 1.285318778574467e-12, 2.005992759655276e-12, 3.760548116669493e-12, 9.021875927620569e-12, 2.938001852503633e-11, 1.219237924583789e-10, -3.935682448508960e-10, -1.214760990515301e-07, -1.343809220771986e-05, 1.398755542631061e-03, 8.115642768769112e-03, 2.475382588278334e-02, -3.038431351609996e-01, 1.510483229264250e+03, -1.353030106852036e+06, -5.030346487709359e+09, 1.028091520584393e+11, 1.755735532424511e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
