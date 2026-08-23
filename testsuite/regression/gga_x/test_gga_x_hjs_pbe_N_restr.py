
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_hjs_pbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.241448138600586e+00, -4.159735908842232e+00, -4.045347533358567e+00, -3.887122150243458e+00, -3.672004917977873e+00, -3.386716914523289e+00, -3.021626206515648e+00, -2.577551310015224e+00, -2.073994791561117e+00, -1.547600909588093e+00, -1.020685386347858e+00, -6.030980606392710e-01, -5.021907016074847e-01, -4.111069902091359e-01, -2.881729863013169e-01, -1.682531625227607e-01, -6.396677474282236e-02, -4.750551988234277e-03, -1.906688993388781e-05, -2.506091257299320e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_hjs_pbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.316987473064595e+00, -5.202561732082261e+00, -5.042140187457666e+00, -4.819756355413245e+00, -4.516444160839726e+00, -4.112336721295342e+00, -3.591986607629878e+00, -2.955142557739487e+00, -2.236053803441806e+00, -1.539404280996306e+00, -9.823902937008017e-01, -7.390250467598755e-01, -6.558205004361183e-01, -4.955691234336298e-01, -3.012395700132191e-01, -1.562058784025160e-01, -7.831655356198100e-02, -9.583358901990137e-03, -3.874796859247971e-05, -5.012248497130438e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_pbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.851274264674929e-06, -4.165024466801545e-06, -4.660031846160802e-06, -5.472795898256973e-06, -6.885071415572298e-06, -9.542977711791329e-06, -1.513201949769148e-05, -2.879313302675799e-05, -6.938646159794710e-05, -2.191946889374442e-04, -1.063054223840938e-03, -6.831865006179136e-03, -1.234549838413060e-02, -2.684629501016711e-02, -9.679187154841799e-02, -4.667888178740949e-01, -1.543055502284445e+00, -9.949043602978664e-01, -1.769449702796836e-03, -2.735617733313101e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_pbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.223879212953203e-02, -1.280233580676140e-02, -1.365768532912891e-02, -1.498603628678906e-02, -1.711617906991070e-02, -2.068481046787457e-02, -2.700985701597856e-02, -3.894800480759426e-02, -6.173760240077613e-02, -8.546858157439481e-02, -1.470513353984207e-01, -5.673061049510065e-01, -6.772443619349502e-01, -1.178662168069158e+00, -2.243712600921851e+00, 1.864163131645120e+00, 2.473356444200305e+01, -2.426390937626850e+02, -1.423375615769326e+02, -1.298289996419009e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_pbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.389873390986991e-08, 2.726218961324425e-08, 3.291165045849814e-08, 4.304949114304300e-08, 6.300956482357794e-08, 1.076588252148833e-07, 2.259305360795095e-07, 6.105102231808564e-07, 2.024020213520734e-06, -2.042758365774931e-06, -1.852900634888520e-04, 1.112139755227686e-02, 3.694582398811685e-02, 1.184298949211821e-01, 4.415314579979670e-01, -4.246599677363483e+01, -4.627520739603231e+03, -1.390298107462507e+05, -3.593848062234703e+04, -3.849124778112937e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_pbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.117758728165767e-14, 6.513898859658602e-14, 9.209469667950474e-14, 1.513234900858783e-13, 3.080638649396895e-13, 8.495949583876035e-13, 3.582293228829839e-12, 2.692551326091233e-11, 4.409534321914669e-10, 2.077133923308565e-08, 2.842871813725082e-06, 2.750361093211938e-04, 8.012309112774373e-04, 1.712479080344860e-02, 1.374942171615618e+00, 5.099229092958996e+02, 4.469715430270279e+05, 3.574904047878624e+08, 8.961140026868067e+09, 7.989715207760324e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
