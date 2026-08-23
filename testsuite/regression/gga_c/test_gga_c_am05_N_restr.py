
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_am05_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_am05", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.111299241191249e-01, -1.103875114671114e-01, -1.093209925290867e-01, -1.077904235713317e-01, -1.055982071240688e-01, -1.024708197001509e-01, -9.804672238127138e-02, -9.190132902622648e-02, -8.369293664722359e-02, -7.357751688165956e-02, -6.337814851872106e-02, -6.175843711006937e-02, -6.102592018907702e-02, -5.340694859346832e-02, -4.341708046907469e-02, -3.206015332238742e-02, -2.023230346038012e-02, -9.515111413944880e-03, -2.719840336988117e-03, -3.689428814827619e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_am05_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_am05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.330228109687072e-01, -1.323765552518912e-01, -1.314338325778877e-01, -1.300499117057850e-01, -1.279999380777016e-01, -1.249264381062060e-01, -1.202554954225164e-01, -1.131135007097600e-01, -1.025108061868524e-01, -8.863426949909237e-02, -7.601639920093914e-02, -7.754323296820617e-02, -7.457938887235804e-02, -6.779886702934312e-02, -5.464643675761941e-02, -3.908467588259833e-02, -2.448262530625250e-02, -1.182642510286752e-02, -3.494706548774396e-03, -4.853196460466843e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_am05_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_am05", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.375486072651296e-07, 1.479041000924129e-07, 1.639753487049070e-07, 1.896976900894827e-07, 2.326144876938393e-07, 3.081944765519445e-07, 4.503556608045492e-07, 7.378568500109613e-07, 1.366363898428579e-06, 3.024554838794240e-06, 1.472896059042110e-05, 6.719877006461405e-04, 2.233549131834818e-03, 2.775035223914635e-03, 4.797850071340106e-03, 9.813370143699107e-03, 1.951289666784443e-02, 3.566581704896635e-02, 5.693582383923564e-02, 7.699082548495848e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_am05_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_am05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.239085756377743e-05, -6.978135721777980e-05, -8.179650311462817e-05, -1.023133519331032e-04, -1.397288200023562e-04, -2.139804209348058e-04, -3.770094983855316e-04, -7.746319289146575e-04, -1.827068127807652e-03, -4.764017441468794e-03, -1.477111004292477e-02, -2.440940840689465e-02, -1.766211809629913e-02, -7.677952654692746e-02, -2.863082822653245e-01, -1.023658127773327e+00, -5.685318218551759e+00, -8.709145782491343e+01, -3.421786157858803e+03, -3.938253644280854e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_am05_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_am05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.366441054264155e-11, 1.008562872734156e-10, 1.918931044721096e-10, 3.862302530999846e-10, 8.588144147256266e-10, 2.215157145078875e-09, 7.004314964375727e-09, 2.874109025288014e-08, 1.609277889261180e-07, 1.332288919481009e-06, 2.603467751379690e-05, 8.218792776394144e-04, -1.273159699643856e-03, 1.412489227061394e-02, 1.677004969867462e-01, 2.758052827078195e+00, 7.426819502342691e+01, 4.314790293859818e+03, 7.875736161916635e+05, 7.940961078096108e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_am05_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_am05", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.363809276288856e-14, -1.705577038170244e-14, -2.347848782182362e-14, -3.701876165340636e-14, -7.060527426774611e-14, -1.752313496478238e-13, -6.213694092180544e-13, -3.523533537702262e-12, -3.646541998600113e-11, -8.590827786106004e-10, -1.073005761120171e-07, -2.006120783434934e-04, -2.641109409446874e-03, -1.266699426341921e-02, -2.609400521416086e-01, -2.156105501066126e+01, -7.015694501517971e+03, -1.328225055460893e+07, -2.894300957600869e+11, -2.248727116695775e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
