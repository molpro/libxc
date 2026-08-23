
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_tpss_gaussian_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.312697285554929e-02, -5.260650930668379e-02, -5.184951455437073e-02, -5.074269306356593e-02, -4.911158466913538e-02, -4.667956229053593e-02, -4.299338996972855e-02, -3.730792980448285e-02, -2.863561022351266e-02, -1.753060756793731e-02, -1.220317551673336e-02, -4.304651890970005e-02, -5.225350753954601e-02, -3.639227710085094e-02, -2.074928042713182e-02, -6.253318489572677e-03, -4.673676677875379e-04, -5.326299283887416e-06, -5.289641987431009e-09, -1.642290850951322e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_tpss_gaussian_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.201071048976937e-01, -1.188643471987213e-01, -1.170969725553710e-01, -1.145976016779569e-01, -1.110939867622609e-01, -1.062505994508323e-01, -9.969442109512626e-02, -9.099920850912313e-02, -7.897791999766783e-02, -6.015292610765909e-02, -4.835078809428788e-02, -8.840804281818070e-02, -8.227930155952189e-02, -7.458307258722929e-02, -5.731657348457791e-02, -2.610901801616883e-02, -2.555015305463175e-03, -3.161867062233299e-05, -3.233973911794120e-08, -1.025614766680770e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_gaussian_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.311546116275210e-06, 1.366320632337301e-06, 1.448556225434542e-06, 1.574240917312650e-06, 1.771215413307062e-06, 2.091308047758880e-06, 2.641924522893257e-06, 3.695485411560145e-06, 6.212443670263771e-06, 1.484362546945946e-05, 8.887378153990723e-05, 3.441159572695513e-03, 9.760044794333145e-03, 1.410049053076562e-02, 3.030258233868796e-02, 8.784650300973754e-02, 1.172401974402959e-01, 4.872810305391817e-02, 6.035045480020328e-03, 1.504838165570370e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_gaussian_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.371838124184596e-03, -1.325478327946659e-03, -1.259338712578970e-03, -1.165331873417219e-03, -1.032559795283867e-03, -8.473849572151447e-04, -5.966781206344178e-04, -2.833656947357372e-04, 2.453341289967817e-05, 1.525601144988412e-04, 9.107442264124171e-05, -1.804438824176384e-06, -3.789192563480664e-04, -1.309475398102305e-03, 2.142944717539459e-03, 2.252435994275973e-03, 2.608228172982207e-04, 3.522347546837104e-06, 3.622049766581832e-09, 1.053381761514427e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_gaussian_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.420540962605347e-04, -4.721006237702547e-04, -5.184690215484880e-04, -5.921581249825399e-04, -7.141535183800632e-04, -9.279597892057841e-04, -1.335150085710711e-03, -2.232882541175321e-03, -4.945176298268776e-03, -1.679058563741000e-02, -6.518120623043569e-02, -2.584830446013009e-02, 5.285060015863914e-03, -1.088644894843062e-01, -7.121351880948423e-01, -5.616010069414742e+00, -1.138592902956304e+01, -4.935099550026080e+00, -5.906145231704030e-01, -1.418294278132680e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_gaussian_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.171202061142543e-09, 5.966964788537810e-09, 7.318243449098773e-09, 9.780521628050483e-09, 1.473402187597438e-08, 2.616393963561719e-08, 5.795588001513575e-08, 1.719027335583457e-07, 7.682957241304717e-07, 6.798011187533599e-06, 1.685608327504000e-04, 1.100841459294553e-03, -1.005600040612567e-02, 5.169894083194917e-02, 7.504305273890024e-01, 2.690973527093226e+01, 6.758042963795725e+02, 9.626650395124851e+03, 1.380347250247912e+05, 2.578440483974242e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpss_gaussian_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.543298693227200e-06, -1.817513381475395e-06, -2.258824647531428e-06, -2.999950137068852e-06, -4.313807578208038e-06, -6.792652849669014e-06, -1.171913537262107e-05, -2.119020649402135e-05, -3.196742841006770e-05, -5.730952169412903e-06, 5.283523165416140e-05, -1.329981531183515e-04, -1.140723148180535e-03, -3.948529141457936e-02, -9.651772415446264e-02, 3.372611181646668e-01, 1.007800895920606e+00, 4.813214453515318e-01, 5.790681044767697e-02, 1.265934175462939e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_tpss_gaussian_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.112742507966360e-14, 3.200682747710696e-14, 3.147399121365603e-14, 2.429266435963984e-14, -1.259854314998353e-14, -1.996887857574656e-13, -1.353072904590895e-12, -1.142942892099400e-11, -1.587098598742386e-10, -4.825466029856699e-09, -7.310877855427245e-07, -7.730345830305402e-04, -7.848691587411903e-03, -5.514514348443054e-02, -1.596308726967012e+00, -2.268886808994816e+02, -5.981539628808072e+04, -2.703997807101285e+07, -4.600080269068641e+10, -6.592896021650719e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpss_gaussian_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.871457725226301e-10, -5.362347434079905e-10, -6.145844455053554e-10, -7.448519980505501e-10, -9.731127142199703e-10, -1.397510434493842e-09, -2.216934330172050e-09, -3.604155995988069e-09, -2.993689757150146e-09, 2.736627860775434e-08, 4.568349871445942e-07, 8.736313909125077e-06, -1.257665633850969e-03, -1.906212047974363e-03, 1.504450387450095e-01, 2.268412608334404e+00, 1.009775816548848e+01, 1.785369358433716e+01, 1.451921372423990e+01, 4.009496561413789e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_tpss_gaussian_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_tpss_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.264378620060309e-06, 1.313513149590306e-06, 1.385742770613841e-06, 1.492181784506153e-06, 1.648059638849324e-06, 1.868300917092624e-06, 2.137212200095563e-06, 2.265055260770282e-06, 1.409578649141213e-06, -2.069382441006309e-06, -8.226767790289379e-06, 2.634565647070984e-06, 2.037230452663080e-03, 2.866913313778652e-02, -5.016103495822124e-02, -6.018426326463437e-01, -1.016967042657728e+00, -4.770619518366703e-01, -6.095888180345251e-02, -1.400662505395470e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
