
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_th3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.514487064355151e+00, -4.421830196091109e+00, -4.292356933648770e+00, -4.113773109150934e+00, -3.872068798519671e+00, -3.553860312712368e+00, -3.151590057464967e+00, -2.672509724658270e+00, -2.149343751667833e+00, -1.635188799977871e+00, -1.115641158671992e+00, -7.112865380137946e-01, -6.155326258287606e-01, -5.111926854710642e-01, -3.756044452495414e-01, -2.491143611697811e-01, -1.583112654395628e-01, -1.046499740500606e-01, -7.468753938357142e-02, -5.434493270247005e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_th3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.092203466059292e+00, -5.958355893407693e+00, -5.770140305867185e+00, -5.508172284079905e+00, -5.148979720469366e+00, -4.667190902674153e+00, -4.041512530567452e+00, -3.267014491294617e+00, -2.377322268896750e+00, -1.492332000921986e+00, -9.483737191782391e-01, -8.910876298611254e-01, -7.962526031088919e-01, -6.251462981753484e-01, -4.112878543519189e-01, -2.181038424571793e-01, -8.376353070234459e-02, -1.194173571005315e-02, 1.659799670400532e-02, 2.418097428433514e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.613286397832011e-07, 6.027975171580548e-07, 4.902490852320515e-07, 2.588139341122086e-07, -2.560798749406208e-07, -1.515989968070953e-06, -4.988422411582674e-06, -1.613748067214709e-05, -5.970438781416337e-05, -2.741845325306765e-04, -1.427748974519883e-03, -3.744794228442048e-03, -6.181615380620060e-03, -1.764019665213543e-02, -7.762425825993546e-02, -5.956804294844258e-01, -8.817122612628436e+00, -3.048076836935684e+02, -3.449063224519222e+04, -2.273051998665722e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.437725566685186e-02, -1.516713600275223e-02, -1.637791226185824e-02, -1.828659236100644e-02, -2.141974754655195e-02, -2.687338796954138e-02, -3.720843212935920e-02, -5.935063936010743e-02, -1.155674572058112e-01, -2.858572636782893e-01, -6.733285038453989e-01, -6.177130528335059e-01, -7.251678507009979e-01, -1.237793107464584e+00, -3.063747427319797e+00, -1.215937670696173e+01, -9.460421212075495e+01, -2.003091918867957e+03, -1.817675547684100e+05, -1.238740603504991e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.903819170298340e-08, 3.452186416650400e-08, 4.403810568959199e-08, 6.191064720442912e-08, 9.941803953150400e-08, 1.913458290072322e-07, 4.710373028406849e-07, 1.620335591246079e-06, 8.770730172890744e-06, 8.531727388905112e-05, 1.369052125201909e-03, 1.188112454639565e-02, 3.196692792534993e-02, 1.095921522456015e-01, 1.109613194089786e+00, 3.724407939495082e+01, 5.264262183050725e+03, 4.891564912994276e+06, 6.224934760946520e+10, 3.459183965291315e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.432649314834286e-13, -4.214447169510705e-13, -5.644621760262703e-13, -8.545137547171789e-13, -1.535438119482621e-12, -3.501099309025009e-12, -1.109203434357587e-11, -5.518233060727165e-11, -5.086513216676093e-10, -1.090070633414542e-08, -7.577870462042406e-07, -2.403690909222915e-04, -2.262284097201954e-03, 2.776217293608025e-03, 3.856036895520172e-01, 1.437595940411948e+02, 3.801672172447910e+05, 1.409110350193019e+10, 2.066784516712152e+16, 6.477277026359561e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
