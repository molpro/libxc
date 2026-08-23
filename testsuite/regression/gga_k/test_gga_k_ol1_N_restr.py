
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_ol1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.446789915242213e+01, 9.080308186006143e+01, 8.579189954940335e+01, 7.908955212737155e+01, 7.040456243852196e+01, 5.964742213800713e+01, 4.715174996229398e+01, 3.389350808321097e+01, 2.149869621652896e+01, 1.171883587922723e+01, 5.229948863877953e+00, 2.206830928723310e+00, 1.629625391169677e+00, 1.100376811033270e+00, 5.628395533575135e-01, 2.347960927723982e-01, 1.082004309913103e-01, 7.520881498590308e-02, 6.719866653886850e-02, 6.381566281828767e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_ol1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.495078140888132e+02, 1.434289499640763e+02, 1.351188511821148e+02, 1.240081092842883e+02, 1.096178757668090e+02, 9.180757610242873e+01, 7.114354171463150e+01, 4.926909634045803e+01, 2.895634493768967e+01, 1.347121265179612e+01, 5.371806877055270e+00, 3.377445616724401e+00, 2.614603416317952e+00, 1.647208425913597e+00, 7.091259509176161e-01, 1.635037700428820e-01, -3.042374841203785e-02, -6.680878156835360e-02, -6.673605810156251e-02, -6.379751541137142e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ol1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.518056019635037e-05, 9.040227712156485e-05, 9.847517579095750e-05, 1.113561888236710e-04, 1.328622470111797e-04, 1.711850510067809e-04, 2.461690490253820e-04, 4.139170997435198e-04, 8.674234377629427e-04, 2.438656533414110e-03, 8.908636366294680e-03, 2.412156785552608e-02, 3.768572359481751e-02, 6.938336219815827e-02, 2.157211947347640e-01, 1.219942024519901e+00, 1.428711622294220e+01, 4.330025719440834e+02, 4.866336454374879e+04, 3.597712457442764e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ol1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.955934455022864e-01, 6.090833093943575e-01, 6.290813961338109e-01, 6.591337989003204e-01, 7.052110194760055e-01, 7.780105017990290e-01, 8.984206637585974e-01, 1.112358136112839e+00, 1.537371307191087e+00, 2.505226253058559e+00, 4.228886076873126e+00, 4.075442522969658e+00, 4.451847545405434e+00, 5.942431717980079e+00, 1.029541782115954e+01, 2.835904271054185e+01, 1.910657434537087e+02, 4.559469266481839e+03, 4.694030763941598e+05, 3.305184908118182e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ol1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.188576169662440e-07, -4.737234918083950e-07, -5.653520927091749e-07, -7.287285263469334e-07, -1.048798942763871e-06, -1.766817522946821e-06, -3.724055352989609e-06, -1.078160668755968e-05, -4.866302211965675e-05, -3.950400865709863e-04, -5.326344455819997e-03, -3.529642110982412e-02, -7.898405012235205e-02, -2.976378439349555e-01, -3.052239614176587e+00, -1.017171678683216e+02, -1.435227396809263e+04, -1.339255139796916e+07, -1.702144079391145e+11, -9.317544893125419e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ol1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ol1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.092504736475526e-13, -7.194006255289911e-13, -9.135135905112418e-13, -1.287538921938325e-12, -2.107197229828407e-12, -4.269708106658591e-12, -1.172821759441254e-11, -4.964988201239824e-11, -3.895534841059958e-10, -7.509396237063234e-09, -5.826808967097220e-07, -2.929874259024409e-04, -4.706990003292388e-03, -1.010685257092898e-02, -1.578810074152779e-01, -1.647885228672413e+01, -1.328620494219393e+04, -1.373418191259322e+08, -4.517467281363890e+13, -2.174988936533697e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
