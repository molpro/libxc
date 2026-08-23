
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_bj89_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_bj89", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.315178813617421e-02, -9.304632233076403e-02, -9.289141506862619e-02, -9.266184354704789e-02, -9.231728065505036e-02, -9.179081483585418e-02, -9.096611684786157e-02, -8.962908900363049e-02, -8.735687004688711e-02, -8.318236294009751e-02, -7.317620806910276e-02, -5.109156323715498e-02, -4.660981507403684e-02, -4.455059081355537e-02, -3.619884178727446e-02, -2.295319173409764e-02, -9.512232174267027e-03, -1.963304367256189e-03, -1.519561902839132e-04, -3.722113887675769e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_bj89_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_bj89", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.485665679817575e-02, -9.486119218366799e-02, -9.477987703329149e-02, -9.478954457985982e-02, -9.466513068134395e-02, -9.468600984330076e-02, -9.449054981815821e-02, -9.453650529860423e-02, -9.421767602495079e-02, -9.432163693489766e-02, -9.377316792459470e-02, -9.401789349629106e-02, -9.300078328843023e-02, -9.361117244053829e-02, -9.151471273371174e-02, -9.317053028492778e-02, -8.816920139651220e-02, -9.323269457912467e-02, -7.890542251630488e-02, -9.695588792319791e-02, -5.181636656671026e-02, -1.205394435744259e-01, -2.036992094781551e-02, -1.716511517858008e-01, -1.773067385611533e-02, -1.721784598033363e-01, -1.827621985936237e-02, -1.577523558930226e-01, -1.501628358149610e-02, -1.415164468355025e-01, -9.293882077841176e-03, -1.149832922775869e-01, -3.700100621101593e-03, -7.385438437783703e-02, -7.216658805191964e-04, -3.140882325094893e-02, -5.275209145016015e-05, -7.504951862450294e-03, -1.253951712440288e-06, -8.673407247307114e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_bj89_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_bj89", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.033569135036547e-03, -1.047002722800232e-03, 1.033618856973509e-03, 1.097401797541067e-03, -1.111989066904470e-03, 1.097514434260365e-03, 1.195996608937909e-03, -1.212438235548267e-03, 1.196262096227737e-03, 1.353068378002723e-03, -1.372646551424851e-03, 1.353730858495842e-03, 1.614601839006751e-03, -1.639903530693955e-03, 1.616396070983009e-03, 2.078308716187787e-03, -2.115318113132945e-03, 2.083774455942417e-03, 2.976671449169927e-03, -3.042174852709491e-03, 2.996377736963928e-03, 4.943919134479008e-03, -5.099792816031882e-03, 5.034291492745154e-03, 9.990488293481443e-03, -1.057006866648015e-02, 1.057178938009848e-02, 2.491864614137255e-02, -2.878693735121664e-02, 3.072927154060659e-02, 5.758792793764099e-02, -9.449021764931943e-02, 1.369022164111111e-01, 5.459514917073695e-02, -1.835157930477785e-01, 4.978823257309049e-01, 6.973689449237473e-02, -2.584134375063727e-01, 7.443522212919487e-01, 1.345046193455535e-01, -4.816348949723830e-01, 1.286294560964669e+00, 3.278737630654088e-01, -1.321216758736665e+00, 3.541784072566811e+00, 1.022895830898383e+00, -5.529468062955212e+00, 1.560158273457264e+01, 3.956114198449717e+00, -3.626955189328821e+01, 1.102826056491042e+02, 1.886122761565057e+01, -4.006298199933157e+02, 1.346343614165375e+03, 1.327839343677945e+02, -9.478962203012987e+03, 3.526411719426109e+04, 2.197690852909229e+03, -7.632716065993336e+05, 2.996557387225993e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
