
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_cap_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_cap", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.284167464761962e+00, -4.201931587500368e+00, -4.086777655159118e+00, -3.927426623851855e+00, -3.710643935861752e+00, -3.422882936149158e+00, -3.054157834032692e+00, -2.605077884204359e+00, -2.096459722169353e+00, -1.573042735156012e+00, -1.059967188777327e+00, -6.590730807537760e-01, -5.610456465880446e-01, -4.671932653485040e-01, -3.417772616347473e-01, -2.291060420342152e-01, -1.642016453812176e-01, -1.565892883478259e-01, -1.953506937308809e-01, -2.622869563750820e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_cap_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_cap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.415880369258510e+00, -5.302091732406174e+00, -5.142556751328985e+00, -4.921375089664482e+00, -4.619603318730895e+00, -4.217192346536239e+00, -3.697762845785896e+00, -3.057655535101361e+00, -2.320624801002960e+00, -1.563660773513381e+00, -9.840245239129960e-01, -8.079240614172438e-01, -7.187726586129424e-01, -5.618426493352081e-01, -3.608600109216288e-01, -1.740113375505820e-01, -4.171870012229468e-02, 2.567439915187359e-02, 4.496957269032840e-02, 4.196277034515462e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_cap_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_cap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.179702593370598e-06, -3.434394626489429e-06, -3.836049052411588e-06, -4.495341164025729e-06, -5.641343605118827e-06, -7.803178549015071e-06, -1.238492854283711e-05, -2.383616824311544e-05, -5.988913124096897e-05, -2.147762816812637e-04, -1.143325585198714e-03, -5.684428700694685e-03, -1.088090581474406e-02, -2.269337417914653e-02, -8.936685954180255e-02, -7.039573360481799e-01, -1.201339833681558e+01, -5.283280643692242e+02, -8.316052759489759e+04, -8.281456347310765e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_cap_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_cap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.177097252010714e-02, -1.230641346363949e-02, -1.312036350676390e-02, -1.438821934783959e-02, -1.643395113798272e-02, -1.990782659203492e-02, -2.626141406451212e-02, -3.920347118834237e-02, -6.990826616995927e-02, -1.574107159979783e-01, -3.980422441163131e-01, -5.447494550799529e-01, -6.579182722225327e-01, -1.143145780287530e+00, -2.929612879231031e+00, -1.230616953837545e+01, -1.002442563622703e+02, -2.082352684333195e+03, -1.716686159161450e+05, -9.982403592593770e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_cap_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_cap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.813783387498675e-08, 2.074011073780096e-08, 2.514118396482064e-08, 3.313008335864612e-08, 4.918060644631790e-08, 8.647368599292425e-08, 1.931362130113336e-07, 6.032438845461637e-07, 2.997744739654671e-06, 2.776174272614653e-05, 5.163788871214501e-04, 8.819826104740641e-03, 2.794480751373227e-02, 9.894723791165304e-02, 1.068756824122208e+00, 3.921610103976840e+01, 5.835559816346733e+03, 5.291516519799541e+06, 6.102901137364283e+10, 2.876653320948787e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_cap_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_cap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.939633548769839e-14, 7.365076872226490e-14, 1.003019332594978e-13, 1.562158198766425e-13, 2.946926248729547e-13, 7.301783192922719e-13, 2.661333034673676e-12, 1.668789147487139e-11, 2.228528242249778e-10, 8.377574710587089e-09, 1.151924826425709e-06, 2.742647441484380e-04, 2.726594600347083e-03, 1.586967878944888e-02, 6.687508700161889e-01, 2.217503730724348e+02, 7.100987153688394e+05, 3.739606790250672e+10, 8.908225781088798e+16, 5.438847702650546e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
