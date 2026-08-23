
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_1d_ehwlrg_2_HO1D_2_zk():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_2", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.910817584605058e-01, -4.910791478647203e-01, -4.910722791129845e-01, -4.910542308116922e-01, -4.910069114786643e-01, -4.908833026902008e-01, -4.905623980642321e-01, -4.897380854743092e-01, -4.876598259105076e-01, -4.825937127793833e-01, -4.709882179951210e-01, -4.472950139619783e-01, -4.079174895237556e-01, -3.594837880492974e-01, -3.030839072001293e-01, -2.004498765509276e-01, -7.321287917530456e-02, -1.070799374502246e-02, -3.944390399239982e-04, -1.576564709242865e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_1d_ehwlrg_2_HO1D_2_vrho():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_2", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.003218481094266e+00, -1.003218481094266e+00, -1.003207225642668e+00, -1.003207225642668e+00, -1.003177611409781e+00, -1.003177611409781e+00, -1.003099797478206e+00, -1.003099797478206e+00, -1.002895785657338e+00, -1.002895785657338e+00, -1.002362874538756e+00, -1.002362874538756e+00, -1.000979461283499e+00, -1.000979461283499e+00, -9.974264949170571e-01, -9.974264949170571e-01, -9.884728732826308e-01, -9.884728732826308e-01, -9.666734373101316e-01, -9.666734373101316e-01, -9.169022610434939e-01, -9.169022610434939e-01, -8.163256118554285e-01, -8.163256118554285e-01, -6.553242063107554e-01, -6.553242063107554e-01, -4.890932487341654e-01, -4.890932487341654e-01, -4.003536639961585e-01, -4.003536639961585e-01, -2.964701405327386e-01, -2.964701405327386e-01, -1.159294327962299e-01, -1.159294327962299e-01, -1.716675175461272e-02, -1.716675175461272e-02, -6.326788397549959e-04, -6.326788397549959e-04, -2.528809793035279e-06, -2.528809793035279e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_1d_ehwlrg_2_HO1D_2_v2rho2():
    # Prepare the input
    inp = test_data["HO1D"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_1d_ehwlrg_2", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.956841623682813e+00, -1.956841623682813e+00, -1.956841623682813e+00, -1.956817017830292e+00, -1.956817017830292e+00, -1.956817017830292e+00, -1.956752276520835e+00, -1.956752276520835e+00, -1.956752276520835e+00, -1.956582157525905e+00, -1.956582157525905e+00, -1.956582157525905e+00, -1.956136102213552e+00, -1.956136102213552e+00, -1.956136102213552e+00, -1.954970668972948e+00, -1.954970668972948e+00, -1.954970668972948e+00, -1.951943456488443e+00, -1.951943456488443e+00, -1.951943456488443e+00, -1.944156826042057e+00, -1.944156826042057e+00, -1.944156826042057e+00, -1.924457051802699e+00, -1.924457051802699e+00, -1.924457051802699e+00, -1.876019901305324e+00, -1.876019901305324e+00, -1.876019901305324e+00, -1.762747795463627e+00, -1.762747795463627e+00, -1.762747795463627e+00, -1.520638645896314e+00, -1.520638645896314e+00, -1.520638645896314e+00, -1.082216386541104e+00, -1.082216386541104e+00, -1.082216386541104e+00, -5.102919760451408e-01, -5.102919760451408e-01, -5.102919760451408e-01, -2.185236297892530e-01, -2.185236297892530e-01, -2.185236297892530e-01, -8.334983588956331e-01, -8.334983588956331e-01, -8.334983588956331e-01, -2.944411039637176e+00, -2.944411039637176e+00, -2.944411039637176e+00, -1.147440335415747e+01, -1.147440335415747e+01, -1.147440335415747e+01, -1.003470826501921e+02, -1.003470826501921e+02, -1.003470826501921e+02, -3.748752282148348e+03, -3.748752282148348e+03, -3.748752282148348e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
