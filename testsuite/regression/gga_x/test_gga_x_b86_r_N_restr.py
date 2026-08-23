
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_b86_r_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_r", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.243666372160320e+00, -4.161005519422092e+00, -4.045243799923947e+00, -3.885025360571439e+00, -3.667008239827782e+00, -3.377497559782229e+00, -3.006308761730859e+00, -2.553802512261047e+00, -2.040548459521126e+00, -1.511981725076635e+00, -1.010409836371934e+00, -6.498665353193820e-01, -5.569341745815324e-01, -4.594539497514498e-01, -3.308318281217533e-01, -2.123523768065215e-01, -1.220195180200990e-01, -5.378528676846717e-02, -1.685596736722540e-02, -3.711296536076405e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_b86_r_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_r", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.447766762718349e+00, -5.333999847635908e+00, -5.174483080644342e+00, -4.953302818566846e+00, -4.651488941845958e+00, -4.248951656841652e+00, -3.729303304577653e+00, -3.089221526796018e+00, -2.354681656301133e+00, -1.610081784383023e+00, -1.029128399030896e+00, -8.142457779799190e-01, -7.222683987520027e-01, -5.668485469610692e-01, -3.680424383418985e-01, -1.964927977255125e-01, -1.078388039094104e-01, -5.288350684988424e-02, -1.602816537300309e-02, -3.255684872673152e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_r_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_r", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.258142453184951e-06, -2.446010232200207e-06, -2.743301163079507e-06, -3.233671996296042e-06, -4.091900529318192e-06, -5.726096270737565e-06, -9.231564890977177e-06, -1.810714313120010e-05, -4.618597051430833e-05, -1.633343577951898e-04, -8.472024097704142e-04, -4.192137911449626e-03, -7.545585546926568e-03, -1.699976061737600e-02, -6.884786589898206e-02, -4.639578652192345e-01, -3.718504631976120e+00, -4.243164218421425e+01, -1.755159139034596e+03, -3.578981382208793e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_r_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_r", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.157133313086116e-02, -1.209681183033859e-02, -1.289554647771560e-02, -1.413941558219976e-02, -1.614522183872374e-02, -1.954553142694892e-02, -2.573314130812391e-02, -3.813066906146639e-02, -6.588164470228340e-02, -1.310670626005754e-01, -2.929958114111768e-01, -5.346033489793141e-01, -6.472452202385026e-01, -1.118873197941183e+00, -2.642555384744770e+00, -5.065920976284382e+00, 3.147862326171246e+01, 8.110098325937608e+01, -2.729878286430441e+02, 6.975445615293462e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_r_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_r", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.535892725035044e-08, 1.762279617121681e-08, 2.146382716941815e-08, 2.846524654140124e-08, 4.260157135649852e-08, 7.559477931345978e-08, 1.699020346447778e-07, 5.247672548069990e-07, 2.404234738245918e-06, 1.610456514580951e-05, 2.116680141714737e-04, 7.732648545796777e-03, 2.292680097183865e-02, 8.702691839423640e-02, 7.646027111244517e-01, -3.000852643313113e+00, -4.615224883944727e+03, -1.416931496975755e+06, -5.018692645129983e+09, -7.418059724061198e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_b86_r_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_b86_r", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.559427055793140e-14, 1.986365316720170e-14, 2.811684333445150e-14, 4.628834484167958e-14, 9.455382614122477e-14, 2.625653772095408e-13, 1.125725658867487e-12, 8.863854759363784e-12, 1.602036008334824e-10, 8.386220938998875e-09, 1.308938727278554e-06, 1.037073500578491e-04, 5.727246189260292e-04, 7.093603202601526e-03, 5.705732329464148e-01, 3.006187961960261e+02, 6.551057685730734e+05, 7.153916840950765e+09, 3.597262867103304e+15, 4.181789001822126e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
