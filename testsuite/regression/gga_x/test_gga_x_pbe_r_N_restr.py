
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_r_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_r", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.305585026913078e+00, -4.223989551763815e+00, -4.109779814824351e+00, -3.951835279429526e+00, -3.737177128838995e+00, -3.452682229360158e+00, -3.089069615755286e+00, -2.648014458242543e+00, -2.151010680307960e+00, -1.637161859873757e+00, -1.109842889260304e+00, -6.653218767534845e-01, -5.628962863956719e-01, -4.730389163328398e-01, -3.530929216655039e-01, -2.404065756325478e-01, -1.396012273665357e-01, -5.154948818250107e-02, -1.090751909127025e-02, -1.207316226658215e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_r_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_r", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.371007224595011e+00, -5.256147235039318e+00, -5.095062160673321e+00, -4.871637527417056e+00, -4.566631264509375e+00, -4.159623832015838e+00, -3.633991138757406e+00, -2.987035583381534e+00, -2.249448394644469e+00, -1.522264459103820e+00, -9.753251386701624e-01, -7.960444717921761e-01, -7.147253001932082e-01, -5.513981592052299e-01, -3.492741070465029e-01, -1.940497479847598e-01, -1.374548548435783e-01, -6.568330532692415e-02, -1.451194859324806e-02, -1.609710227082333e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_r_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_r", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.967591257305868e-06, -4.295669935721955e-06, -4.814388074946415e-06, -5.668865805396896e-06, -7.161250204303476e-06, -9.993436455563781e-06, -1.603380918375496e-05, -3.116669930213724e-05, -7.804696990222476e-05, -2.658370419147683e-04, -1.343617798020500e-03, -7.306248561905636e-03, -1.330125828456851e-02, -2.946950220440585e-02, -1.145002104093622e-01, -6.773385581034880e-01, -3.299989182994172e+00, -6.871338590395190e+00, -8.551966500579047e+00, -9.459978626598584e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_r_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_r", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.244710772158264e-02, -1.303577838613248e-02, -1.393250997580046e-02, -1.533310798870886e-02, -1.760019615923909e-02, -2.145952840148391e-02, -2.849867002096145e-02, -4.248239492200994e-02, -7.211874430813621e-02, -1.264722576583119e-01, -2.402964407180639e-01, -5.886712523102903e-01, -6.862126861060301e-01, -1.241958546746429e+00, -2.779967250997470e+00, 2.616812437158918e-01, 7.871043259869326e+01, -3.218845099303075e+02, -1.649767621694506e+04, -1.389327280461336e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_r_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_r", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.628881201286342e-08, 3.011554642189417e-08, 3.659087227630506e-08, 4.834531318931849e-08, 7.192181523069550e-08, 1.263396379831125e-07, 2.787829871529298e-07, 8.291953405544402e-07, 3.455244187343616e-06, 1.625388350328488e-05, 1.010383967236235e-04, 1.285730480092840e-02, 3.967548948211225e-02, 1.417144218946967e-01, 9.820660290752623e-01, -3.115439701567136e+01, -8.498483701875812e+03, -8.075694960049358e+05, -1.194574595693129e+08, -9.800734484530219e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_r_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_r", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.487870548740005e-14, 4.441111984319451e-14, 6.282821219437291e-14, 1.033440165951906e-13, 2.108157832546641e-13, 5.841110287994306e-13, 2.494693071085280e-12, 1.950220615914534e-11, 3.473734104098480e-10, 1.765599806657816e-08, 2.700900632007124e-06, 2.304570543344698e-04, 1.284350792944970e-03, 1.569597076603000e-02, 1.221734380680354e+00, 5.822432611568468e+02, 8.798297765714631e+05, 2.461207357243962e+09, 4.339404653540178e+13, 2.762979972729999e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
