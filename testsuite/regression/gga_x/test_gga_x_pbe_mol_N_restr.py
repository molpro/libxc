
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_mol_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mol", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.337621327961375e+00, -4.256413631323669e+00, -4.142752090570496e+00, -3.985573770325323e+00, -3.771962994147354e+00, -3.488830406735721e+00, -3.126763314478486e+00, -2.686638426398585e+00, -2.186829212338892e+00, -1.658873063942784e+00, -1.118210627052620e+00, -6.726398276044439e-01, -5.660909196250614e-01, -4.790923980499191e-01, -3.588058850779444e-01, -2.363014247349749e-01, -1.227728073834049e-01, -4.197756535381852e-02, -8.770446814417097e-03, -9.701631357036127e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_mol_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.342126375467616e+00, -5.227483386282507e+00, -5.066782579953596e+00, -4.844070363782677e+00, -4.540452350624219e+00, -4.136299844308084e+00, -3.616882634167380e+00, -2.984161515914996e+00, -2.279041452795755e+00, -1.608047513174054e+00, -1.061565857828591e+00, -7.917168700425713e-01, -7.114576370292480e-01, -5.491225467995020e-01, -3.597836174536957e-01, -2.254022234046734e-01, -1.421510432987526e-01, -5.491671304580050e-02, -1.168348453204024e-02, -1.293535997824471e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_mol_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.735801700141435e-06, -5.117408574121566e-06, -5.718610551086443e-06, -6.703610887887313e-06, -8.409523763354203e-06, -1.160339739210987e-05, -1.826197843361252e-05, -3.428380811584979e-05, -8.033891992285536e-05, -2.429663513721331e-04, -1.143636100160326e-03, -8.436462910340595e-03, -1.609769039819290e-02, -3.331364113489865e-02, -1.117749789274662e-01, -4.801434240377864e-01, -1.460589741190597e+00, -2.373653577652778e+00, -2.843709639905929e+00, -3.139762358162536e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_mol_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.254358081925957e-02, -1.312079709315193e-02, -1.399564600240584e-02, -1.535099859622335e-02, -1.751503644944463e-02, -2.110984460738502e-02, -2.736130505648837e-02, -3.854602021675065e-02, -5.641621527459013e-02, -6.213036449700934e-02, -5.764111180764331e-02, -5.753698669231380e-01, -6.957724387048653e-01, -1.179470711524600e+00, -1.846952002199540e+00, 4.312337147885231e+00, 2.035641158716637e+01, -4.415745324664829e+02, -1.348933937476627e+04, -1.116658616743128e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_mol_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.790073936313500e-08, 3.173555866978831e-08, 3.814592815813845e-08, 4.956436330831234e-08, 7.178022567897534e-08, 1.204684026550214e-07, 2.442896026506154e-07, 6.050741084749331e-07, 1.399737886539965e-06, -1.158972595430112e-05, -4.331126315374273e-04, 1.197685996203776e-02, 4.421120038833611e-02, 1.198180494402603e-01, 5.365386484794084e-02, -5.765195793257343e+01, -4.650764285218694e+03, -2.865945970851020e+05, -3.977238318501803e+07, -3.252911893697047e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_mol_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_mol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.895183219645009e-14, 1.002357131854142e-13, 1.411824844230687e-13, 2.306780370691670e-13, 4.656707207733360e-13, 1.268536158847654e-12, 5.263635063273436e-12, 3.905557972046741e-11, 6.297286668632224e-10, 2.677874410876687e-08, 3.681533414873109e-06, 4.963533102731724e-04, 2.968191398457950e-03, 3.274644161040059e-02, 2.045437631247674e+00, 6.031901327454203e+02, 4.497013887547107e+05, 8.673895057122005e+08, 1.444311993172607e+13, 9.170428947420544e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
