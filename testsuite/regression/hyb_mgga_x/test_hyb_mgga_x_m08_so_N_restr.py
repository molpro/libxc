
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m08_so_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.066696005508486e+00, -1.034602350773261e+00, -9.998196383217359e-01, -9.716199166255659e-01, -9.671650204504297e-01, -9.983465646891653e-01, -1.018541733836198e+00, -9.410391773139445e-01, -1.011467215994330e+00, -9.795165229338587e-01, -6.517377705327907e-01, -3.148924163293066e-01, -2.325309266480526e-01, -1.943136221835013e-01, -2.052311708946781e-01, -1.383046678190848e-01, -7.830190167351682e-02, -2.928858102478744e-02, -5.785666732761569e-03, -6.377552629800346e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m08_so_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.447585539428367e+00, -1.160486730617174e+00, -7.692623364199603e-01, -2.857230078050819e-01, 1.684123350398338e-01, 2.393916481816445e-01, -4.422449208120121e-01, -7.536226395386146e-01, 1.917331347178917e-01, -7.476374319413207e-01, -5.495162997216128e-01, -2.930854056396732e-01, -1.162989551423834e-01, -4.951179864502266e-02, -1.282952241756332e-01, -1.567326054404415e-01, -4.828613655775281e-02, -4.143081356710683e-02, -7.754149776552921e-03, -8.503986402921302e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_so_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.560538616535196e-05, -1.641518219066748e-05, -1.751974430804332e-05, -1.891997638862529e-05, -2.033806069444483e-05, -2.053344029971557e-05, -1.584900919072226e-05, -3.695363889066714e-06, -3.633136632057403e-05, -2.573995156862359e-04, -1.019679537960260e-03, -1.183373950253555e-02, -6.339819963731107e-04, -3.842477049110032e-03, -1.206578031613719e-01, -2.546900838114206e-01, -2.057773160979892e+00, 4.190792265761894e+00, 7.552282079436683e+00, 8.485183757464750e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_so_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.611820771719918e-02, 2.975886091164387e-02, 2.048454273258283e-02, 7.790484035004948e-03, -6.813959707641033e-03, -1.637858838837303e-02, -1.095797552806922e-02, -1.106709664156185e-02, -3.206320935032707e-02, 2.127997587879661e-03, 1.992347074176650e-03, 1.803588467263414e-03, -7.647880978005436e-02, -1.164457580264340e-01, -1.073097486963937e-02, 1.357426260262882e-02, -1.985583679545266e-02, 4.530287529468211e-04, 1.171824180403378e-05, 1.864353793927034e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_so_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.443734076511967e-02, -6.691176209918419e-02, -6.718835999765443e-02, -5.961054611001321e-02, -3.083827130695319e-02, 3.828726444849036e-02, 1.099294918898104e-01, -6.431846634896717e-02, -2.259344575448393e-02, 1.960580636211116e-01, 5.503676731322397e-01, -9.067691558871703e-01, -1.639685499336041e-01, -2.461457824295878e+00, 5.654552405557555e+00, 1.568335970647948e+01, 8.810819271378668e+01, -6.020368076404407e+02, -9.559340897214395e+03, -7.347735417077168e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_so_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.383791503067162e-09, -2.305601650002420e-08, -5.872657431095617e-08, -1.323960070688050e-07, -2.973267264349656e-07, -6.863704063988807e-07, -1.501448553606261e-06, -1.308643381568429e-06, 1.374086648034708e-05, -4.353291036668358e-05, -1.446200711703909e-03, 1.017861126156122e-02, 5.000908603583350e-02, 2.936311660522010e-01, 8.876030126235133e-01, -9.863304078144759e+01, -3.140898111014991e+03, 3.973567241490738e+05, 1.048305883780788e+08, 8.790115169980569e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_so_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.517044864700734e-03, 1.629046015246439e-03, 1.720753684540544e-03, 1.676863001300618e-03, 1.201348033330622e-03, -1.712572166405737e-04, -1.680901976600684e-03, 2.029637801749682e-03, -2.112040481218144e-03, -3.408164323744092e-03, -3.816582669109196e-03, 5.420424302125502e-02, -2.585584511492165e-02, 9.315683881594408e-01, -4.488989652344380e+00, -1.195419541753736e+00, -4.483160384850122e+01, -2.955564864570687e+00, 1.198789021807873e+02, 1.448204640343287e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_x_m08_so_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.776000751382224e-13, 4.676214549279136e-13, 6.306826362817419e-13, 9.519160672499267e-13, 1.648478515008310e-12, 3.257762685009950e-12, 6.157066049208916e-12, -3.034820592020637e-12, 2.650853364557337e-10, 4.689820197015238e-08, 5.832187079576575e-06, 9.423436595122988e-04, -4.875458471407996e-04, -2.864874475515722e-03, 3.316428927033738e+00, 6.664419339742818e+02, 2.280079465415382e+05, -1.523064403908231e+09, -3.834796025649352e+13, -2.478293219364411e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_so_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.083953294266522e-09, 2.739968064317993e-09, 3.915067054754291e-09, 6.176724469375338e-09, 1.088672406666671e-08, 2.126025181057082e-08, 4.179660299453609e-08, 3.802519671814469e-08, -3.315812575452591e-07, -3.872859466380397e-07, 3.230044740521223e-06, 3.096333338305385e-04, -1.857487943689017e-02, -1.530942366773959e-01, -1.244687548483095e+00, 2.283971168504028e+00, 1.981860667288822e+03, 9.149025979943451e+04, 7.307347363968027e+05, 8.374076849990891e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_so_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_so", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.341089305645799e-05, -4.712776716209697e-05, -5.091842923610836e-05, -5.235310760829303e-05, -4.482917577191774e-05, -1.768434397150031e-05, 1.198963213885178e-05, -6.562424819951620e-05, 1.376740420045566e-04, 1.112957477770568e-04, 6.886369078060415e-05, -5.143007945314369e-03, 5.490086730794286e-02, -1.974199619023586e-01, 3.638013073973809e+00, 2.594854563837939e-01, 1.721565390656615e+01, -3.691386360129945e+01, -1.309772945569468e+02, -1.652583016529919e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
