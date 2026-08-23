
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_scanl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.885392040280302e+00, -4.786555800967261e+00, -4.648029163573114e+00, -4.456065948124008e+00, -4.194347352913540e+00, -3.845725350614875e+00, -3.396135905955513e+00, -2.835684710376439e+00, -2.193817362028414e+00, -1.512502987377288e+00, -8.438316177578825e-01, -5.847208316670618e-01, -6.268939770133503e-01, -5.055147165505297e-01, -3.371397631288706e-01, -1.732117374849102e-01, -6.419314920668114e-02, -1.676444798333310e-02, -2.218404599629759e-03, -1.015353066090259e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_scanl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.524108037862822e+00, -6.392803161218890e+00, -6.208808976552257e+00, -5.953922179088689e+00, -5.606588309105507e+00, -5.144282513406264e+00, -4.512208560393060e+00, -3.563898728508386e+00, -2.642337306810147e+00, -1.558165945998016e+00, -1.079463002010260e+00, -7.929300135005773e-01, -7.377036297048295e-01, -5.843865251640652e-01, -3.466530281647630e-01, -2.065022189789852e-01, -8.945695802364499e-02, -2.731190503510578e-02, -3.997143744949833e-03, -1.958427067379546e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scanl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.100018212929167e-07, 1.226249320421338e-07, 1.431478365245816e-07, 1.782899529086841e-07, 2.429997539990468e-07, 3.747650055335512e-07, -8.183810446839998e-08, -1.087901869920730e-05, -4.549513686032570e-05, -3.528059019371107e-04, -8.777778051737206e-04, -6.305843821551675e-03, -1.620570313317620e-02, -3.183386455464771e-02, -1.745750348820956e-01, -4.205331034604451e-01, -8.558663033072823e-01, 1.105226514080039e+01, 2.843732711398503e+02, 1.284016715958657e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scanl_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 6.856057803423340e-05, 6.511345591845151e-04, 1.240561337468315e-03, 3.251281492008959e-03, 2.118431649275017e-03, 2.780379152424330e-03, 9.378522031032994e-03, 1.011446042745258e-02, 1.792810465515429e-02, 8.165680452087985e-03, 2.301154708106446e-03, 7.642849012484220e-06, -7.393010449963462e-07, -3.824374393304327e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scanl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.195942728580454e-02, -1.244875609392688e-02, -1.318652053783668e-02, -1.432183152317817e-02, -1.612079505879988e-02, -1.909321999756363e-02, 2.431733533756933e-02, 6.561370609348356e-02, 1.220977963342402e-01, 3.494201408554861e-01, -3.590217506872876e-01, -6.467126324965961e-01, -2.685365694783173e-02, 4.937960479456205e-01, 3.752081740996367e+00, -5.357519607078233e+02, -8.763483126202124e+01, -4.455113928389634e+02, -1.034440536342412e+04, -4.598980365814388e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scanl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.972885012911135e-09, -2.301450425226423e-09, -2.867346894945197e-09, -3.919971372130049e-09, -6.102407343089279e-09, -1.136785498733932e-08, -1.034037916206248e-06, -5.022919830932515e-06, -2.791003054524504e-05, -3.657432952487758e-04, 9.234890550900309e-04, -2.612670541061239e-03, -7.976187438340858e-02, -4.958383946832154e-01, -1.061367060001276e+01, 7.538689460812014e+03, 1.165486125408139e+04, 3.809853935560498e+05, 1.568416918961857e+09, 6.212326541240495e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scanl_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 9.129450850050624e-05, 2.730613278900367e-04, 7.421754908421475e-04, 3.664256729619423e-03, -1.579377644495915e-03, 7.640555302540558e-03, 6.130879046129528e-02, 1.823565121530744e-01, 1.259073327478462e+00, -1.325540095940717e+02, -1.599877356947720e+01, -8.998660894218322e-01, -1.154762129087884e+01, -4.315365642002915e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scanl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.238113796377697e-14, 1.521098355721296e-14, 2.040343830000964e-14, 3.097144927081909e-14, 5.584352788970701e-14, 1.273369741665303e-13, 2.178864660553469e-11, 2.772068214053649e-10, 4.928064519840485e-09, 3.249977862063318e-07, -1.074757456838256e-05, 6.146900173766461e-04, 2.344871020996114e-02, 2.478042167527019e-01, 2.278007963150938e+01, -1.073681329273864e+05, -2.796687713797499e+06, -2.118383330792236e+09, -7.987579097205689e+14, -2.272900027881601e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scanl_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -1.915284082172464e-09, -1.423507974366108e-08, -1.200144901372027e-07, -2.814824145651702e-06, 2.865336037558474e-05, 2.580443074278037e-04, -1.189999072921782e-02, -7.061196682173353e-02, -2.194752625648130e+00, 1.896264354603579e+03, 4.292510387227755e+03, 1.418206516539989e+04, 5.378549927177910e+06, 1.481227900677499e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_scanl_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_scanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.715047628847366e-07, 7.374955321961900e-07, 2.938503633789170e-06, 2.446314439197715e-05, -7.176491325973788e-05, -3.737808738721324e-04, 6.342556087688876e-03, 2.069994331840204e-02, 2.134187073655295e-01, -3.348639524115408e+01, -6.712191489672934e+00, -7.666490473514888e-01, -1.045579246562643e+00, -3.388092708046744e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
