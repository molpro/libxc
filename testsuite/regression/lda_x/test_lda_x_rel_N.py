
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_rel_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rel", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.118489125999109e+00, -4.037023583041807e+00, -3.922677700890521e+00, -3.763915137000756e+00, -3.546916825339603e+00, -3.256968165656426e+00, -2.881986859962977e+00, -2.419279112207709e+00, -1.886016062127014e+00, -1.333544024513052e+00, -8.742100806713130e-01, -6.700109798341417e-01, -5.892584386094346e-01, -4.717776846780367e-01, -3.231528957900536e-01, -1.841362493711516e-01, -8.361440597702105e-02, -2.795281561334526e-02, -5.998601394012897e-03, -6.741774111875237e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_rel_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rel", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.461953597101896e+00, -5.461909036769650e+00, -5.355081148705350e+00, -5.354987937991752e+00, -5.204973986602650e+00, -5.204778053599243e+00, -4.996377536458642e+00, -4.995962712647914e+00, -4.710958154042701e+00, -4.710070537221565e+00, -4.329125525643907e+00, -4.327195865057516e+00, -3.834791364700626e+00, -3.830493968793071e+00, -3.224742448901250e+00, -3.214810662864831e+00, -2.523863073543221e+00, -2.499575087934395e+00, -1.807395468018998e+00, -1.743284447992969e+00, -1.232574981043993e+00, -1.059494588977022e+00, -9.671518061305092e-01, -6.517554284374881e-01, -8.498355064220745e-01, -5.548832903604558e-01, -6.807905883582742e-01, -4.517210607058483e-01, -4.657835683701111e-01, -2.995221171460899e-01, -2.640328847677580e-01, -1.563877982470666e-01, -1.182884869194838e-01, -6.040788684238508e-02, -3.866129700488696e-02, -1.544179173656098e-02, -8.115968815854318e-03, -2.216961633333107e-03, -9.021359634475816e-04, -1.466713894321955e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_rel_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_rel", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.006097756020158e-02, 3.807954362996404e-04, -2.006131287100561e-02, -2.092108504990821e-02, 3.811703077592798e-04, -2.092183041695103e-02, -2.221979959580148e-02, 3.816837749703367e-04, -2.222150945760807e-02, -2.422262712549626e-02, 3.823721018311865e-04, -2.422673135394773e-02, -2.740605784962413e-02, 3.832666997422626e-04, -2.741657379699557e-02, -3.268911266594926e-02, 3.843787999923780e-04, -3.271871433957015e-02, -4.201122886634023e-02, 3.856759090799146e-04, -4.210665838146962e-02, -5.994079915912764e-02, 3.870565740830302e-04, -6.031480994499011e-02, -9.866785645511887e-02, 3.883378885802048e-04, -1.006044007190938e-01, -1.936273405907069e-01, 3.891720453988367e-04, -2.081683552877560e-01, -4.178480631405577e-01, 3.868000050200725e-04, -5.656942393733464e-01, -6.794848165030617e-01, 3.707890706106662e-04, -1.496783606903373e+00, -8.803682959414022e-01, 3.680171466277476e-04, -2.065656381649800e+00, -1.372466593345393e+00, 3.695266882444734e-04, -3.117945221761083e+00, -2.933244308457244e+00, 3.667273630262445e-04, -7.094103473020560e+00, -9.130868985813693e+00, 3.588406546728840e-04, -2.602768624670966e+01, -4.549722222535527e+01, 3.437080460242419e-04, -1.744557322161737e+02, -4.259181997377119e+02, 3.189193770222737e-04, -2.669831839812272e+03, -9.664943869226339e+03, 2.866310885406056e-04, -1.295280196959886e+05, -7.822329935180524e+05, 2.563539366438887e-04, -2.959302152458608e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
