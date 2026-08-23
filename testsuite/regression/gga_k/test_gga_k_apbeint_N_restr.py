
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_apbeint_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbeint", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.399240382405686e+01, 9.033937401733886e+01, 8.534458668617363e+01, 7.866464449116721e+01, 7.000938864555087e+01, 5.928965995971183e+01, 4.683599274296566e+01, 3.361117141895433e+01, 2.120312462089034e+01, 1.131793395332592e+01, 4.945890251982825e+00, 2.193169789944297e+00, 1.622371027943252e+00, 1.092674163736878e+00, 5.510309817889895e-01, 2.028424799182692e-01, 4.694251226195639e-02, 5.183455948543983e-03, 2.245275170243569e-04, 2.746335464973051e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_apbeint_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.492273999725737e+02, 1.431567986645763e+02, 1.348594638989687e+02, 1.237690666687301e+02, 1.094127190752592e+02, 9.166230106612757e+01, 7.111201111472378e+01, 4.946863431124959e+01, 2.962294204079867e+01, 1.480718218808076e+01, 6.326144737045830e+00, 3.372910880422323e+00, 2.610467251734220e+00, 1.647615344784267e+00, 7.442962210256734e-01, 2.568456251096651e-01, 6.896710322694313e-02, 8.489443807350677e-03, 3.739039712821813e-04, 4.577177258417999e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_apbeint_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.968606054284806e-05, 8.467955579736882e-05, 9.239049253863697e-05, 1.046652886302953e-04, 1.250611243465105e-04, 1.610330803631951e-04, 2.298057088846001e-04, 3.755012759649265e-04, 7.211603836723948e-04, 1.632177635831132e-03, 5.105846812978429e-03, 2.265842797122856e-02, 3.473055698408871e-02, 6.446263958657104e-02, 1.640370295415956e-01, 4.349428365139356e-01, 6.284347628846294e-01, 3.372172637104213e-01, 8.400998155867119e-02, 1.025809091752981e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_apbeint_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.958609043627336e-01, 6.090649912538758e-01, 6.285476823048054e-01, 6.575957317590977e-01, 7.015126820557290e-01, 7.690517166190469e-01, 8.745420167722271e-01, 1.038007060594049e+00, 1.261782118092324e+00, 1.422544758385061e+00, 1.774489671137570e+00, 4.013144807129280e+00, 4.462551182246997e+00, 5.740929628093518e+00, 7.321842702636131e+00, 3.944683765938803e+00, 1.492566473277279e+01, 1.562837002355145e+02, 8.680675311984712e+02, 7.903137510109161e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_apbeint_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.329278959399279e-07, -4.858245423901917e-07, -5.727020368195785e-07, -7.235087269720068e-07, -1.005918124636359e-06, -1.590070681918248e-06, -2.945783675781851e-06, -6.304565045712145e-06, -1.054558823475264e-05, 1.014385032497332e-04, 2.265577193403553e-03, -3.068914791383392e-02, -8.545202891176609e-02, -2.223029318027520e-01, 7.939884823143463e-02, 5.764005774089210e+01, 2.161991166512830e+03, 4.408160686729217e+04, 1.272847214294893e+06, 1.151341087899059e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_apbeint_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_apbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.290813599048567e-13, -1.928009668686058e-13, -3.278410277267198e-13, -6.601383893501160e-13, -1.661763742208457e-12, -5.636493199786316e-12, -2.850250090580570e-11, -2.443386818095207e-10, -4.097984174161362e-09, -1.522409581338238e-07, -1.449894571996358e-05, -4.731194974616666e-04, 3.660436180839740e-04, -2.953645101028975e-02, -2.381819295113241e+00, -5.087157742482414e+02, -1.899396160316987e+05, -1.229423106921072e+08, -4.266381681514815e+11, -2.996117302836071e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
