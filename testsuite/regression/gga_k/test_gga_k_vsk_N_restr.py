
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_vsk_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vsk", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.391450532713296e+01, 9.026051504520100e+01, 8.526450723476506e+01, 7.858319027030582e+01, 6.992690388237047e+01, 5.920820727448429e+01, 4.676325559619039e+01, 3.357359836561355e+01, 2.129019358349881e+01, 1.176701750756035e+01, 5.388637149698829e+00, 2.189993860513191e+00, 1.621534033786978e+00, 1.090976797616679e+00, 5.590861711571894e-01, 2.934447279353412e-01, 5.739400365980835e-01, 6.472508016108030e-01, 6.029229495679362e-01, 5.742339009203840e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_vsk_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vsk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.493843834512536e+02, 1.433093439849015e+02, 1.350043309955568e+02, 1.238999562845407e+02, 1.095166095541351e+02, 9.171034810252907e+01, 7.103515692148297e+01, 4.908736462657897e+01, 2.844171456034954e+01, 1.168785238085572e+01, 3.569021077133974e+00, 3.373537796146941e+00, 2.612588582120307e+00, 1.644213261200489e+00, 6.751247201547979e-01, -2.385615980536989e-01, -1.148685514713552e+00, -6.511046570471559e-01, -6.025705341190913e-01, -5.742292915914108e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vsk_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vsk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.660859810718170e-05, 8.143382625669008e-05, 8.890674796919159e-05, 1.008623334812837e-04, 1.209088452417897e-04, 1.568956808963000e-04, 2.283380173185049e-04, 3.937689069702389e-04, 8.885104038785954e-04, 3.188606791306131e-03, 1.441469460200211e-02, 2.218337795550274e-02, 3.342420325830710e-02, 6.467557538672059e-02, 2.418647842524154e-01, 3.896330536018062e+00, 1.427135007875625e+02, 3.898025303179884e+03, 4.376537963161386e+05, 3.237673137886191e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vsk_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vsk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.955561122217568e-01, 6.090869105172584e-01, 6.291711019844350e-01, 6.594229301867146e-01, 7.060214213799106e-01, 7.804154552356539e-01, 9.068474072908681e-01, 1.151052490046151e+00, 1.796000395783385e+00, 4.908968623367113e+00, 1.278963234148734e+01, 4.093663159073269e+00, 4.451182152688578e+00, 6.020414150099572e+00, 1.447848220195697e+01, 2.576469164318177e+02, 1.314696480596999e+03, 3.921991902101292e+04, 4.221267366335781e+06, 2.974686670989942e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vsk_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vsk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.233871908920580e-07, -4.791748757525833e-07, -5.726692454227540e-07, -7.404153445815217e-07, -1.072979293347662e-06, -1.837629379172323e-06, -4.042368567438572e-06, -1.319534896281850e-05, -8.387790732462857e-05, -1.443483176368522e-03, -3.011994678847088e-02, -3.709604396673464e-02, -7.995050164937138e-02, -3.300834897697918e-01, -7.312571720780929e+00, -1.452798303005567e+03, -1.419835639583957e+05, -1.187680215524839e+08, -1.532251472948980e+12, -8.386021810417066e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_vsk_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_vsk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.706805733584080e-14, -4.857899859948465e-14, -4.559988456137497e-14, -2.010030549954013e-14, 1.216491052593409e-13, 1.000524982724167e-12, 8.571565250984222e-12, 1.212302122634187e-10, 3.894918892527377e-09, 3.631952716457333e-07, 5.632562921412483e-05, 1.025393616248088e-04, -4.974972867274911e-04, 1.013632554637427e-02, 3.488782024916176e+00, 5.987170217362969e+03, -2.263185275242627e+05, -5.283325704944489e+09, -1.726306115356161e+13, -1.207446094682249e+18]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
