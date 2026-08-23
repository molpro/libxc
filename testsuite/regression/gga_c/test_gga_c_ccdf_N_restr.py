
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_ccdf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_ccdf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.312176243705221e-02, -4.252728798822597e-02, -4.151104743945395e-02, -3.967956576716093e-02, -3.627772555843940e-02, -3.051943494700895e-02, -2.421806331639038e-02, -2.149966920411514e-02, -2.115600634373332e-02, -2.107250564608510e-02, -2.092978389239214e-02, -2.754956767706619e-02, -4.446521741860517e-02, -2.233389211567846e-02, -2.019730619150206e-02, -1.937460234235292e-02, -1.733061778913736e-02, -1.238538611725924e-02, -4.750341055519808e-03, -6.548960022085739e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_ccdf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_ccdf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.077652227746548e-02, -8.619917286095216e-02, -9.486737036085349e-02, -1.082952386040200e-01, -1.246173600988948e-01, -1.227677503475298e-01, -7.088186752826113e-02, -2.786312275510118e-02, -2.135761892224204e-02, -2.116105551546658e-02, -2.106415615360662e-02, -1.077605350516051e-01, -5.442593774254569e-02, -5.294223131583383e-02, -2.056561178676409e-02, -1.996961748944866e-02, -1.841615871170912e-02, -1.411784629959555e-02, -5.981321747494494e-03, -8.664956271870808e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_ccdf_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_ccdf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.034015762002088e-07, 4.984781752499436e-07, 6.670932289496411e-07, 9.777671811787941e-07, 1.518750632646396e-06, 2.075343060931749e-06, 1.541858112919388e-06, 3.619534712314818e-07, 1.751291811390986e-08, 9.677314416949884e-11, 1.470545235537637e-11, 6.417020093358374e-03, 3.535315804745845e-03, 1.126928134782010e-02, 7.054425957235505e-06, 8.355022605458497e-13, 7.507091496093402e-33, 3.384398617069218e-109, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_ccdf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_ccdf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.971055097071957e-03, 2.323107488611030e-03, 2.823316938873142e-03, 3.292158279142406e-03, 2.357699783491461e-03, -4.054765003345338e-03, -1.012725534827332e-02, -3.549955798660070e-03, -2.169920828999657e-04, -1.153163422573365e-05, -5.696832454302989e-05, -9.118490896048830e-01, 2.338830576974122e-01, -2.182406590818640e+00, -7.130882813227097e-03, -3.721448645121805e-02, -8.753983282942224e-01, -5.094417011860932e+01, -5.106976528073079e+03, -7.195504656144083e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_ccdf_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_ccdf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.115443670887432e-08, -2.655884177407589e-08, -3.534732455506887e-08, -4.696807405646502e-08, -4.058716144838289e-08, 9.122357517215985e-08, 3.348940458594029e-07, 2.034363951798216e-07, 2.705764647560030e-08, 5.708191511065951e-10, 3.659483663216882e-10, 7.305751564623429e-02, -8.725214295584241e-02, 8.098350613225097e-01, 3.152940944721494e-03, 3.895049638889244e-09, 9.183773499132480e-28, 3.788625447802751e-102, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_ccdf_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_ccdf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.867334141525694e-13, 2.472323812154118e-13, 3.522937127587174e-13, 4.990789098110791e-13, 3.147047948981538e-13, -2.942416679124586e-12, -1.248329061837272e-11, -1.263455709997392e-11, -3.633297288901766e-12, -2.406841467854294e-13, -1.015160525425067e-12, -7.240773837309872e-03, 2.712330492908639e-02, -3.333017969630836e-01, -3.134475607903028e-03, -2.148585324050699e-08, -6.308733666551591e-26, -8.573395665034706e-99, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
