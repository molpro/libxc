
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_sregtm_v1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.654456270453278e+00, -4.561793832338779e+00, -4.432018440260234e+00, -4.252389665689344e+00, -4.007927219345334e+00, -3.683220766420907e+00, -3.266684295671463e+00, -2.758101492133563e+00, -2.177945088128740e+00, -1.568783404569132e+00, -9.972285725292694e-01, -6.689046829166878e-01, -5.602158692038230e-01, -4.779104279900526e-01, -3.429337879452380e-01, -2.093288611833815e-01, -1.087746838994742e-01, -4.828816057004690e-02, -1.774529397070281e-02, -4.666581678185211e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_sregtm_v1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.061363534863667e+00, -5.932123244498981e+00, -5.750739247890207e+00, -5.498899616690365e+00, -5.154600786515563e+00, -4.694242999740323e+00, -4.098200812786841e+00, -3.362514563452543e+00, -2.520640343011257e+00, -1.679054182329489e+00, -1.081982826865294e+00, -7.642317826408004e-01, -7.427715246240583e-01, -5.847966036508767e-01, -3.776924482692121e-01, -2.057460909942274e-01, -9.238414252232389e-02, -3.246334089180195e-02, -9.883714843837323e-03, -2.420244623168672e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.464188202105061e-06, -2.728817177423190e-06, -3.155075115516771e-06, -3.875292646744399e-06, -5.176330078537254e-06, -7.753959834970270e-06, -1.354179878852244e-05, -2.886915931762137e-05, -7.883429046774179e-05, -2.821139384980798e-04, -7.752554744816704e-04, -7.131013257487720e-04, -1.345994076192882e-02, -4.965746698396920e-02, -1.367563833458605e-01, -6.324911247787445e-01, -5.556923319423657e+00, -1.106056727898410e+02, -5.835957036749563e+03, -1.268539878334475e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v1_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.076702528652259e-03, 2.163235037550397e-03, 2.290197841503056e-03, 2.477812695931603e-03, 2.757462890625100e-03, 3.178195914455883e-03, 3.815865245365733e-03, 4.780793935155301e-03, 6.183188883657632e-03, 7.552203346548309e-03, 1.364924323574503e-03, -1.034587401982005e-02, 1.276290664472671e-02, 4.748364858297269e-02, 4.069266090411255e-02, 3.054663432945169e-02, 2.260269713808480e-02, 1.496466195988176e-02, 7.362241341916351e-03, 2.256545255722752e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.026188634106188e-02, -1.068574744813141e-02, -1.132787008791542e-02, -1.232277106292350e-02, -1.391400995277401e-02, -1.657268537892240e-02, -2.127256332797992e-02, -3.011541050340404e-02, -4.767269885038630e-02, -8.962989470177121e-02, -1.944532277024734e-01, -5.348190718918993e-01, -7.617831403853004e-01, -1.322956376222864e+00, -2.121769697899861e+00, -6.196131096041975e+00, -7.645465197031028e+01, -1.452684098022686e+03, -5.932147507765536e+04, -1.063272831377886e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.426429590196812e-08, -8.426185898433574e-08, -1.009167649337061e-07, -1.304651192425847e-07, -1.877821060927656e-07, -3.138978422505653e-07, -6.452807096036346e-07, -1.761492871139096e-06, -6.965594995446090e-06, -3.402303777843021e-05, 2.626880262503113e-04, -5.841223409517730e-03, -3.585693080317792e-03, 6.819643925851837e-02, -8.682960240378191e-01, 6.365849507215185e+00, 9.097542511203872e+03, 7.658514617110563e+06, 4.196629319860186e+10, 5.981740980269973e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v1_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.440413240112857e-04, 1.545004406899010e-04, 1.706769983004379e-04, 1.964555603523999e-04, 2.392542131906858e-04, 3.143116113293020e-04, 4.554657045753099e-04, 7.426744356678314e-04, 1.350510829483225e-03, 2.074745975233265e-03, -4.044919933886149e-03, 1.710105121923065e-02, 6.741631869568655e-02, 1.325346302448396e-01, 7.223248010967358e-01, -6.032942607300351e-01, -6.868064395053833e+01, -1.989837989465341e+03, -1.022427210903655e+05, -2.027582084574688e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.955612931002049e-12, 3.591670929087737e-12, 4.747713750615330e-12, 7.073208280468273e-12, 1.247980531967054e-11, 2.792140133362868e-11, 8.691010586549329e-11, 4.253418441627661e-10, 3.777257809625130e-09, 5.725873525361254e-08, -5.553966106781702e-06, -1.685020550331372e-04, -1.530162821311489e-02, 1.720460638831404e-02, 3.744959763727337e+00, -2.938845139183637e+01, -1.573434517459376e+06, -4.500780216215639e+10, -3.030899159803426e+16, -3.370993645222281e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v1_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.463090899485193e-09, -5.094588644576870e-09, -6.154184091479153e-09, -8.052576305047658e-09, -1.178220760184536e-08, -2.011035977149367e-08, -4.224319090417635e-08, -1.159514215621412e-07, -4.275475095742989e-07, -1.164113109775320e-06, 7.752444897216144e-05, 8.255764437872396e-04, 3.521365502921268e-02, 1.142534250366813e-01, -2.386071750996415e-01, 4.884177728452780e+01, 1.669323243105203e+04, 1.473235546260071e+07, 9.286770660653455e+10, 1.472591868071738e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_sregtm_v1_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_sregtm_v1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.542681687373189e-06, 7.015579773286881e-06, 7.745347306598646e-06, 8.903553538623432e-06, 1.081154838203462e-05, 1.410557538483070e-05, 2.009360161763169e-05, 3.130405802497285e-05, 4.902835130739939e-05, 1.024048215781382e-05, -7.967914535853761e-04, -1.901061335284781e-03, -6.871768237119978e-02, -3.005170860384986e-01, -4.166766890656705e-01, -6.410241853314476e+00, -1.427803404081094e+02, -4.100538405916824e+03, -2.378837995252128e+05, -5.269154880908566e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
