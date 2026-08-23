
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_optb86b_vdw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb86b_vdw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.244174485091595e+00, -4.161542710396106e+00, -4.045825552307777e+00, -3.885677321459900e+00, -3.667775294139948e+00, -3.378464219120088e+00, -3.007649764240617e+00, -2.555920896625603e+00, -2.044455749503384e+00, -1.519738051245834e+00, -1.018417041320048e+00, -6.500799819307234e-01, -5.569696043248333e-01, -4.596921404213749e-01, -3.318697048742723e-01, -2.163105106290254e-01, -1.319937497152575e-01, -6.274456506205248e-02, -2.060099309568448e-02, -4.704994375653307e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_optb86b_vdw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb86b_vdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.445791034421602e+00, -5.331913370581493e+00, -5.172227291062476e+00, -4.950781243660592e+00, -4.648534145592097e+00, -4.245252459754788e+00, -3.724230004774529e+00, -3.081377079674198e+00, -2.340830793874117e+00, -1.584925237804992e+00, -1.004700468295314e+00, -8.134316267378442e-01, -7.221295576161885e-01, -5.659515057931346e-01, -3.644997621351826e-01, -1.865612835207667e-01, -1.007204985995320e-01, -5.793464369935387e-02, -1.898147345113355e-02, -4.050497350147066e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optb86b_vdw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb86b_vdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.286610910646929e-06, -2.478044203027118e-06, -2.781244332046423e-06, -3.282032902395184e-06, -4.160327314921474e-06, -5.838378610677823e-06, -9.458503852021996e-06, -1.871877935892162e-05, -4.859092175973536e-05, -1.776191134395462e-04, -9.407006657800945e-04, -4.280304813395018e-03, -7.614716710544344e-03, -1.745102543475321e-02, -7.348992565675373e-02, -5.453988336775685e-01, -5.102577084501144e+00, -5.796773237949704e+01, -2.310600483870741e+03, -4.699835984419309e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optb86b_vdw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb86b_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.162443828059951e-02, -1.215634504605933e-02, -1.296566997242017e-02, -1.422804611185753e-02, -1.626903234557085e-02, -1.974468671749015e-02, -2.612295322442341e-02, -3.912461477279301e-02, -6.938176345600829e-02, -1.469476928913296e-01, -3.445090000312392e-01, -5.407681616098513e-01, -6.488878010728759e-01, -1.138228754810380e+00, -2.854711913671415e+00, -7.133132374032151e+00, 4.696246704506311e+01, 3.160657387837377e+02, 2.310783464324305e+03, 1.110588462690066e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optb86b_vdw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb86b_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.596819326996850e-08, 1.835042379675904e-08, 2.240253312969409e-08, 2.981747604201751e-08, 4.488089799538800e-08, 8.039502728922498e-08, 1.837218737135881e-07, 5.859670463398556e-07, 2.880613273541161e-06, 2.306747683585634e-05, 3.623699945400772e-04, 8.262494078784707e-03, 2.357885479252233e-02, 9.473809981963359e-02, 9.811175037014687e-01, 9.591380626878678e+00, -5.501074933415578e+03, -2.064278681406401e+06, -6.660595178758285e+09, -9.742297802343618e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_optb86b_vdw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_optb86b_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.133117724476213e-14, 1.444522658910689e-14, 2.047222135982979e-14, 3.376643785242438e-14, 6.917875092302510e-14, 1.930271395926404e-13, 8.344502568984730e-13, 6.670972300728242e-12, 1.242348061884487e-10, 6.884507567560912e-09, 1.114225698010556e-06, 7.642186643108761e-05, 4.137625896954485e-04, 5.275291951773321e-03, 4.536072536743364e-01, 2.831387156806400e+02, 8.425439063116714e+05, 1.006294413173381e+10, 4.750274582410165e+15, 5.491655839749595e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
