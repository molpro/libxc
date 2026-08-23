
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_eb88_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_eb88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.315111752711513e+00, -4.233293985711892e+00, -4.118735785853780e+00, -3.960228493712345e+00, -3.744627250881790e+00, -3.458481030882477e+00, -3.091836029652809e+00, -2.644990147810022e+00, -2.137112606321397e+00, -1.607844615362398e+00, -1.082444049083279e+00, -6.663092332067339e-01, -5.640979143205044e-01, -4.732832387227371e-01, -3.490537460293302e-01, -2.313857251249706e-01, -1.454182216858845e-01, -9.045077910430571e-02, -5.842155720290394e-02, -4.057213801970724e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_eb88_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_eb88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.385063954099760e+00, -5.271342695173849e+00, -5.111953259737575e+00, -4.891086330937289e+00, -4.590000196105401e+00, -4.189103913182917e+00, -3.673088187144364e+00, -3.040826540539684e+00, -2.321609131546995e+00, -1.597980229524723e+00, -1.025049537547308e+00, -8.024980127882838e-01, -7.153834736729963e-01, -5.581653552333028e-01, -3.638633501409316e-01, -1.953549486500430e-01, -9.095097791754325e-02, -3.974121120875058e-02, -1.589026944478207e-02, -6.631584985566131e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_eb88_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_eb88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.953058500235056e-06, -4.263786646211201e-06, -4.752434000466345e-06, -5.551091074469953e-06, -6.930116200635992e-06, -9.503877945062489e-06, -1.486266614602964e-05, -2.785176796355482e-05, -6.660405401470997e-05, -2.196385809463251e-04, -1.113878848790263e-03, -6.894034208737774e-03, -1.365196410330294e-02, -2.707634950821650e-02, -9.567872640230346e-02, -6.059432863726304e-01, -6.978225810227340e+00, -1.822080307536667e+02, -1.688196713229390e+04, -1.003567446420258e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_eb88_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_eb88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.193383128314956e-02, -1.246830915547063e-02, -1.327831238814830e-02, -1.453388255950294e-02, -1.654349730041212e-02, -1.990842722287875e-02, -2.590495606132556e-02, -3.750898677775369e-02, -6.226810636733385e-02, -1.200788448004599e-01, -2.732126458147382e-01, -5.427800873449261e-01, -6.690561386177684e-01, -1.120847153635622e+00, -2.443781965429948e+00, -6.138015778208117e+00, -8.487852083640762e+00, 1.761370047740299e+02, 1.867226663632341e+04, 1.040785300678253e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_eb88_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_eb88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.050072253263809e-08, 2.328595299858747e-08, 2.794581175226170e-08, 3.626660695416799e-08, 5.256170921210934e-08, 8.889599071258637e-08, 1.858535799369687e-07, 5.151511983563219e-07, 2.031284824447637e-06, 1.195820687461671e-05, 1.612306005323101e-04, 8.896137771384666e-03, 3.310340575935001e-02, 9.279486099656764e-02, 5.968977445815764e-01, 2.914441267827600e+00, -1.517347239222370e+03, -1.324372789066615e+06, -1.013304738657045e+10, -3.411170223050486e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_eb88_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_eb88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.582283902266969e-14, 1.195859206950529e-13, 1.643317037619242e-13, 2.591402940658618e-13, 4.971350797664849e-13, 1.259040517239547e-12, 4.712627265610072e-12, 3.037557413345592e-11, 4.121908082424705e-10, 1.517959138475167e-08, 2.032753378983786e-06, 4.771028083283854e-04, 4.148457085396105e-03, 2.832054612120194e-02, 1.231724769938261e+00, 3.560247531254124e+02, 7.451205608223584e+05, 1.999359115455112e+10, 2.421616645236426e+16, 8.049233446133449e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
