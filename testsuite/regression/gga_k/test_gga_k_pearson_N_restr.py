
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_pearson_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pearson", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.392366360647378e+01, 9.026877772016752e+01, 8.527118288028478e+01, 7.858684896088918e+01, 6.992428305693457e+01, 5.919088342436096e+01, 4.670582005614566e+01, 3.338470726755509e+01, 2.062458634333175e+01, 1.009485886596099e+01, 4.154063173324943e+00, 2.188927882937207e+00, 1.621684655572776e+00, 1.088980786185594e+00, 5.186647080105826e-01, 1.503005015831008e-01, 2.839137904084835e-02, 2.905203445722699e-03, 1.245251438531176e-04, 1.522368990545440e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_pearson_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pearson", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.494300920212721e+02, 1.433670209894907e+02, 1.350819913637598e+02, 1.240130848292668e+02, 1.096982422065662e+02, 9.204045143043703e+01, 7.173925059191265e+01, 5.089600056465670e+01, 3.332529442388634e+01, 1.877633414232156e+01, 7.767585767553398e+00, 3.390301364701801e+00, 2.612451390658953e+00, 1.666841890744900e+00, 9.079851276820756e-01, 2.647779379171504e-01, 4.744519203211819e-02, 4.842166776030494e-03, 2.075419210015131e-04, 2.537281650938421e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pearson_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pearson", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.628193155943367e-05, 8.093200167088139e-05, 8.807397353923651e-05, 9.933584494751056e-05, 1.177090170594449e-04, 1.488150682889359e-04, 2.018838265621037e-04, 2.720342947870553e-04, 1.323586362168224e-04, -7.853243644532425e-04, -2.248342845373206e-03, 2.069565401492090e-02, 3.356843435839736e-02, 5.503252946358101e-02, -4.102976146305683e-02, -7.645072154159353e-02, -8.556833033580747e-03, -3.628691244997808e-04, -3.969560884749907e-06, -6.206745851665730e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pearson_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pearson", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.907072172695020e-01, 6.031688872180485e-01, 6.213367037024776e-01, 6.478186615712009e-01, 6.859664769575965e-01, 7.376615118524573e-01, 7.865892343022300e-01, 6.872676517096722e-01, -8.345766377506714e-02, 1.823293925665685e+00, 4.905987872182807e+00, 3.796892933048882e+00, 4.444532293502593e+00, 4.958164607295048e+00, 8.346768192127743e-02, 2.291151709385606e+01, 3.310724849517390e+01, 1.003332631179491e+02, 4.844313177372895e+02, 4.381273938668665e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pearson_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pearson", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.695337555185766e-07, -4.089255676771018e-07, -4.704096205461751e-07, -5.670023722091918e-07, -7.096034197300093e-07, -8.186142800883122e-07, 1.924259773695689e-07, 1.533793927180576e-05, 1.777685274560713e-04, 1.208118505018771e-04, -4.481885751080369e-03, -1.183429669745675e-02, -7.756264062055730e-02, 9.080910810610693e-02, 8.434576224087902e+00, -4.149065507009326e+01, -6.093994151111578e+01, -7.892096046704235e+01, -9.728767525275991e+01, -1.125343200350104e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_pearson_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_pearson", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.053331617698529e-13, -8.174481026153736e-13, -1.257962678108823e-12, -2.333220576449658e-12, -5.644330844682754e-12, -1.985874570984094e-11, -1.169980512537036e-10, -1.318156397598841e-09, -2.342611349333367e-08, 4.995082923623134e-09, 1.566467523406166e-05, -1.731787636696311e-03, -1.514933487754801e-03, -1.294624599064153e-01, -7.370532216838956e+00, 2.573392576184061e+02, 4.721738013947688e+03, 2.032446289694690e+05, 3.027227985669402e+07, 2.719278487237817e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
