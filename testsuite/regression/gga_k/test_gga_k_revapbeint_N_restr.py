
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_revapbeint_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbeint", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.402990947340128e+01, 9.037832805152567e+01, 8.538571129151592e+01, 7.870908117925701e+01, 7.005901080515768e+01, 5.934769548196672e+01, 4.690832404107101e+01, 3.370896162172163e+01, 2.134584385235826e+01, 1.151447781667197e+01, 5.073815222913664e+00, 2.195643165040608e+00, 1.622708977609179e+00, 1.094642664429605e+00, 5.570349505028226e-01, 2.138125164135116e-01, 5.447346398290324e-02, 6.386127674072583e-03, 2.792813539586219e-04, 3.417674757267054e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_revapbeint_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.490872929224249e+02, 1.430113638346362e+02, 1.347060741919947e+02, 1.236036109291895e+02, 1.092285625572332e+02, 9.144834716731941e+01, 7.084916145671373e+01, 4.912491385033363e+01, 2.916017506005876e+01, 1.427524904591193e+01, 6.021548189099805e+00, 3.363826860975114e+00, 2.609202247137669e+00, 1.640508114501859e+00, 7.262449533419238e-01, 2.397498784767412e-01, 7.247763543430301e-02, 1.029419950244874e-02, 4.647299800211984e-04, 5.696008260733195e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_revapbeint_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbeint", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.186009631142003e-05, 8.708385626014797e-05, 9.516828153906879e-05, 1.080813149492702e-04, 1.296520024887329e-04, 1.680265283449126e-04, 2.424868000917342e-04, 4.045499007021673e-04, 8.095620204529807e-04, 1.978048610038283e-03, 6.484993561995366e-03, 2.371814403308461e-02, 3.540977447208013e-02, 6.832206431779997e-02, 1.904748762654453e-01, 6.243903064139146e-01, 1.241321162125515e+00, 7.872111746407165e-01, 2.011900225020645e-01, 2.459722237318898e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_revapbeint_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.995374525758272e-01, 6.131154447687676e-01, 6.331999417788168e-01, 6.632642779635020e-01, 7.090172779454774e-01, 7.801965041967690e-01, 8.938443412844783e-01, 1.078396258289186e+00, 1.362238583665599e+00, 1.659136664616295e+00, 2.150846606475387e+00, 4.079488974881279e+00, 4.477142393806508e+00, 5.886655522073478e+00, 8.181619670826473e+00, 4.101135364582431e+00, -6.248894039526268e+00, 1.683144918576307e+02, 1.073555639837264e+03, 9.834327857841421e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_revapbeint_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.779728060477629e-07, -5.386979762075500e-07, -6.392286892485117e-07, -8.159247843943927e-07, -1.153641604667974e-06, -1.877637673764450e-06, -3.680240655248844e-06, -8.989687169076730e-06, -2.554292072817947e-05, -1.797609550655898e-05, 9.265207026167088e-04, -3.679745359210114e-02, -9.163481883588673e-02, -2.846853632781846e-01, -8.999832251515030e-01, 5.155979978306402e+01, 3.758949798574397e+03, 1.012093820692243e+05, 3.045878695655857e+06, 2.760699706301093e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_revapbeint_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_revapbeint", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.239865896471487e-13, 2.483855346582234e-13, 2.794634935857613e-13, 2.995873097906618e-13, 1.833126190393376e-13, -9.625321166122692e-13, -1.115950333749522e-11, -1.372666122526597e-10, -2.871156600762523e-09, -1.277987951736497e-07, -1.321884697329813e-05, -1.202706964631050e-04, 2.049322780738838e-03, -1.307298019938856e-02, -1.830805767688984e+00, -5.632998273656891e+02, -3.405028140690127e+05, -2.831784610554941e+08, -1.021079901995240e+12, -7.184140137176713e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
