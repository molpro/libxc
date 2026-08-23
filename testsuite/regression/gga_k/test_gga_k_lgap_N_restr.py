
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_lgap_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.451148322635204e+01, 9.084828310368350e+01, 8.583930195541663e+01, 7.913985380944648e+01, 7.045845290382503e+01, 5.970516237063858e+01, 4.721188860108086e+01, 3.394893045759465e+01, 2.152462971906976e+01, 1.165469528809445e+01, 5.152608437428071e+00, 2.209174925850998e+00, 1.629968898259925e+00, 1.101892659156373e+00, 5.624784230464911e-01, 2.190571044013879e-01, 5.097912423793870e-02, 5.229311853575309e-03, 2.241452540149797e-04, 2.740264182971884e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_lgap_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.493451916292743e+02, 1.432689277598363e+02, 1.349629627351202e+02, 1.238590332148578e+02, 1.094805633306943e+02, 9.169183351360384e+01, 7.107046816126132e+01, 4.928838432482311e+01, 2.919091586830903e+01, 1.413813013863373e+01, 5.925514100035419e+00, 3.373299535094183e+00, 2.612411730240063e+00, 1.645826853004818e+00, 7.240449919908277e-01, 2.392969555242124e-01, 8.350185855996092e-02, 8.715519755958847e-03, 3.735754233582995e-04, 4.567106971619807e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lgap_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.770488253161770e-05, 9.309230944181658e-05, 1.014152000269203e-04, 1.146780181884670e-04, 1.367696334125072e-04, 1.759566693845830e-04, 2.519011336017108e-04, 4.181068231696461e-04, 8.432802281481495e-04, 2.127266884423756e-03, 7.090544967822691e-03, 2.476774538851957e-02, 3.871265503306356e-02, 7.083527647453970e-02, 2.010964332808231e-01, 6.736216221005021e-01, 9.919931852828028e-02, 1.660974615817134e-35, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lgap_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.965761065679845e-01, 6.100070060525388e-01, 6.298859197159290e-01, 6.596785643509108e-01, 7.051350002577654e-01, 7.762665182304693e-01, 8.914469170908194e-01, 1.085258750946354e+00, 1.410738092435654e+00, 1.802088690832959e+00, 2.299330417424966e+00, 4.060857528051118e+00, 4.460988406760272e+00, 5.879437967624486e+00, 8.693708461697701e+00, -8.283892316288796e-01, 3.275466555446449e+01, 1.805289513220957e+02, 8.719756483455515e+02, 7.886293088525809e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lgap_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.358969615221088e-07, -4.915193332560552e-07, -5.838538326989870e-07, -7.469230050776756e-07, -1.061374449459444e-06, -1.747411705194794e-06, -3.520093791553490e-06, -9.207293625586009e-06, -3.150803265808105e-05, -8.174126020136226e-05, 4.249019698317474e-04, -3.448419669845068e-02, -8.370016651926289e-02, -2.758361863342331e-01, -1.403131226399644e+00, 7.781742210550857e+01, 1.622249931566700e+03, 1.579970851948725e-28, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lgap_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lgap", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.776639511055937e-13, -6.985224080898805e-13, -9.204742740356739e-13, -1.376491836654782e-12, -2.483454760725134e-12, -5.934137362832330e-12, -2.161550269773173e-11, -1.466619958352766e-10, -2.372329326765292e-09, -1.123257343792602e-07, -1.288672071875438e-05, -4.418841325993526e-04, -3.882769698937946e-03, -2.073219819757864e-02, -1.506089860261656e+00, -7.265491197546630e+02, -1.168186964019052e+05, -3.571905919610942e-25, -0.000000000000000e+00, -0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
