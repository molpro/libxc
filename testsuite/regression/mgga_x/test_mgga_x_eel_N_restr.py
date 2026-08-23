
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_eel_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.887190668099349e+00, -4.788328725293588e+00, -4.649705425473214e+00, -4.457481788253844e+00, -4.195129125677263e+00, -3.844995331471406e+00, -3.391993606788755e+00, -2.829510784225030e+00, -2.163052433208182e+00, -1.388358712297004e+00, -4.909614780962252e-01, -2.501415973667568e-01, -5.551452935819285e-01, -4.584078851278134e-01, -2.975265766300045e-01, -1.508086776992059e-01, -5.872229176544692e-02, -1.913687628099358e-02, -2.708685582132806e-03, -1.237597656161886e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_eel_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.502536789568954e+00, -6.358941652560183e+00, -6.153564888295623e+00, -5.863102531567961e+00, -5.459161473052862e+00, -4.910329569535486e+00, -4.187605953720902e+00, -3.276300499209682e+00, -2.203244168205310e+00, -1.117257572234770e+00, -5.323970448978537e-01, -8.881446285035526e-01, -1.028162723837564e+00, -6.939880471575075e-01, -3.166110059839708e-01, -1.828392026939207e-02, 3.746750810539819e-02, -2.790943957690122e-02, -4.857375151788898e-03, -2.388156592734171e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_eel_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.320193652373619e-07, -9.737482964679619e-07, -1.824372845889958e-06, -3.494335234725395e-06, -6.905698585164641e-06, -1.438514336668266e-05, -3.269075987881023e-05, -8.498369046047186e-05, -2.676955313688019e-04, -1.073231804040429e-03, -4.019519472586173e-03, -1.325610604097150e-04, 2.212531493779970e-03, -6.369787306176765e-02, -4.210021036634629e-01, -3.281787883267463e+00, -2.222754977542594e+01, 5.262204056701063e+00, 3.391889712484141e+02, 1.560445614354751e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_eel_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.754434361778989e-04, 1.459532054521433e-03, 2.443609781109715e-03, 4.052445069043592e-03, 6.599586681721056e-03, 1.051679045998144e-02, 1.639631132813098e-02, 2.499178825625801e-02, 3.688650907479708e-02, 5.062070658815114e-02, 4.360170314209607e-02, 4.846260150438837e-02, 1.123127007948144e-01, 1.485901168689564e-01, 2.275310768321787e-01, 2.935199985514008e-01, 1.635024244688487e-01, 5.088071672451734e-05, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_eel_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.937293633605052e-02, -2.206754384139302e-02, -2.558407481563243e-02, -3.032634677395950e-02, -3.721848081755534e-02, -4.837767824537326e-02, -6.888056256115208e-02, -1.121613553387528e-01, -2.186527914809284e-01, -5.287703891040011e-01, -1.109278927406500e+00, -2.892317369314445e+00, -3.181517117028947e-01, -3.170516581219707e+00, -9.814180127230424e+00, -4.136566862205810e+01, -8.948611963878813e+02, -1.981621991101227e+02, -1.210507931020345e+04, -5.604521889026429e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_eel_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.322762104203993e-07, 1.807863335618147e-07, 2.525169759758771e-07, 3.672958872064285e-07, 5.759046278725678e-07, 1.026081457438503e-06, 2.232635028019274e-06, 6.493370561977760e-06, 2.803837003365310e-05, 2.120428792370852e-04, 1.521513039481808e-03, 4.940818379323532e-02, -2.441253362951039e-02, 1.107443979144112e+00, 9.086248132493543e+00, 2.867155314757397e+02, 1.867143260749506e+05, 3.273959574671751e+05, 1.752364505980080e+09, 7.490371089256575e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_eel_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.234629491622393e-04, -1.548306078358477e-04, -1.932760379147929e-04, -2.410026316719935e-04, -3.039477171685067e-04, -3.958797412870574e-04, -5.458200319782506e-04, -8.069302835059007e-04, -1.213039643833434e-03, -1.606355866762691e-03, 1.344151990877186e-02, 1.566917530442899e-01, -1.790760986328994e-01, -5.221348967665206e-01, -8.711764314928487e-01, -8.668717050537083e+00, -1.423428842522726e+03, -2.059233430350162e+02, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_eel_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.376805678260080e-12, -1.978232186483694e-12, -2.963307446273146e-12, -4.749851620459669e-12, -8.511612954430738e-12, -1.816618740636774e-11, -4.999484730078657e-11, -1.903199300402883e-10, -9.157854592580787e-10, -9.639850183107500e-09, -1.207070213937239e-05, -7.117196100802428e-03, -2.594485495378927e-03, -2.886573726672303e-01, -2.766194729754142e+00, -2.134822271054968e+03, -4.060836609535112e+07, -4.847985291287542e+09, -9.082264130979694e+14, -2.723154718457751e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_eel_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.801864925738998e-14, 3.788743203709924e-14, 8.945436819273623e-14, 2.453947890028174e-13, 8.307683945022359e-13, 3.820900410374421e-12, 2.754837063214906e-11, 3.811348958387641e-10, 1.315942906061279e-08, 1.431512682221622e-06, 1.995152367396491e-04, 3.447559997139504e-03, 9.646263593664921e-03, 3.924161634843020e-02, 1.382278346076594e+00, 3.329427552603439e+02, 3.410687161587039e+05, 1.400287613098980e+06, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_eel_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_eel", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.973770070319865e-06, 3.714635795454796e-06, 4.606824156777017e-06, 5.681512034915823e-06, 7.030373573684898e-06, 8.848005967969217e-06, 1.140478468161131e-05, 1.434237142612220e-05, 9.605435978982824e-06, -1.260448855128482e-04, -3.061929734283401e-03, -1.966635975534874e-02, 2.471590809372011e-02, 1.079063490677790e-01, -1.072060734327482e+00, -4.225431779584471e+01, -2.823630222169852e+03, -3.627242650454491e+02, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
