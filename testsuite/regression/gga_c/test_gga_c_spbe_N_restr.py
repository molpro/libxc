
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_spbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_spbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.650909019277224e-02, -6.554864452381046e-02, -6.417554984931735e-02, -6.221794885064300e-02, -5.943879520258702e-02, -5.552029485185613e-02, -5.006322178652634e-02, -4.265513637261516e-02, -3.319888942242716e-02, -2.308918009070317e-02, -1.892505599519488e-02, -4.508076165662249e-02, -5.306916129438063e-02, -3.889139818758912e-02, -2.398972670985436e-02, -1.058111244369056e-02, -2.434169389780840e-03, -1.992209684893140e-04, -3.637111423727175e-06, -7.769070314581941e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_spbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_spbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.283860907961332e-01, -1.273347593905463e-01, -1.258119878647689e-01, -1.235995092837891e-01, -1.203705808945692e-01, -1.156291900704089e-01, -1.086149820215903e-01, -9.819108790173282e-02, -8.298663082893486e-02, -6.357292226163658e-02, -5.385289106618858e-02, -8.454585864251682e-02, -8.101171701727199e-02, -7.478748149225732e-02, -5.724813386996199e-02, -3.121598980652989e-02, -8.479158260162229e-03, -7.524923999077974e-04, -1.418721564666750e-05, -3.079786500283867e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_spbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_spbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.500829967927343e-07, 6.918013323751716e-07, 7.562759137318265e-07, 8.590131723332876e-07, 1.029916329380007e-06, 1.331760499267186e-06, 1.910487450995447e-06, 3.149753422394708e-06, 6.234542487496911e-06, 1.621146809765750e-05, 9.242334477616895e-05, 2.936539101651848e-03, 8.575748740130385e-03, 1.228865311090742e-02, 2.994980095399219e-02, 1.070088248455933e-01, 3.950777548755717e-01, 1.176579492630504e+00, 2.637847410277604e+00, 4.380332996088433e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_spbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_spbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.181963659631901e-04, -3.430116808971161e-04, -3.819518442622690e-04, -4.453982420135093e-04, -5.544464997966766e-04, -7.565242468122739e-04, -1.172146394940345e-03, -2.154518997661861e-03, -4.903498710498873e-03, -1.395188179208642e-02, -4.716936395428190e-02, -3.593810094840349e-02, -3.494939897366853e-03, -1.009782298848234e-01, -6.596541145030094e-01, -4.046971063477032e+00, -1.990520665715959e+01, -6.410376129795928e+01, -1.438163449550925e+02, -2.363379207155053e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_spbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_spbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.135445009882897e-09, 3.610179698257253e-09, 4.418807674780228e-09, 5.901290105743372e-09, 8.920529952990489e-09, 1.606320410399959e-08, 3.695178022548014e-08, 1.191224331381936e-07, 6.037969985527981e-07, 5.529447098364166e-06, 1.235085363098123e-04, 1.834839086166689e-03, -7.614044031061348e-03, 2.386125601221251e-02, 5.514511473033594e-01, 2.059070096522776e+01, 1.296873137007559e+03, 1.364593156258933e+05, 3.599907334535011e+07, 4.497557516621724e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_spbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_spbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.616044932568158e-14, -1.166446193346273e-13, -1.539213883343836e-13, -2.291274880058572e-13, -4.051109744189598e-13, -9.146615719589387e-13, -2.916677533329145e-12, -1.508150488448282e-11, -1.527291698676810e-10, -4.037793587682983e-09, -5.791386479926557e-07, -7.223251690248362e-04, -8.303001478188533e-03, -4.097985773887455e-02, -1.171000044545062e+00, -1.877159723608222e+02, -1.306570333541513e+05, -4.318011656697637e+08, -1.339645987820526e+13, -1.279375961371886e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
