
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_x_t_sloc_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_t_sloc", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.427805348089480e+00, -5.342093230129861e+00, -5.221313418215406e+00, -5.052647755228772e+00, -4.820141480846392e+00, -4.505514444621104e+00, -4.090858839965318e+00, -3.564549907638820e+00, -2.932008108603345e+00, -2.235406650622309e+00, -1.606599069180414e+00, -1.303178784952724e+00, -1.178690241425951e+00, -9.910439897707225e-01, -7.375980076514157e-01, -4.754747485416125e-01, -2.567989120056819e-01, -1.092958510084165e-01, -3.294298255402461e-02, -5.994283767882205e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_x_t_sloc_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_t_sloc", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.839056382012911e+00, -6.839013094645684e+00, -6.731082927002728e+00, -6.730992010562960e+00, -6.578951018758579e+00, -6.578758784342133e+00, -6.366541375408685e+00, -6.366130916876272e+00, -6.073822701056819e+00, -6.072933580360579e+00, -5.677931347689508e+00, -5.675963741286250e+00, -5.156726512412614e+00, -5.152230221713142e+00, -4.496701135738971e+00, -4.485914815660494e+00, -3.708044645217538e+00, -3.680212563229408e+00, -2.854087177278127e+00, -2.774851657600930e+00, -2.115790577285937e+00, -1.880301422332870e+00, -1.750708559152349e+00, -1.286864281543297e+00, -1.582632390232382e+00, -1.134989301533444e+00, -1.331117778271806e+00, -9.666614916181900e-01, -9.899590102878638e-01, -7.015408730079961e-01, -6.357812484364629e-01, -4.225660341215882e-01, -3.398619953331234e-01, -2.012153121227103e-01, -1.420631950717869e-01, -6.943688885945330e-02, -4.204276728358013e-02, -1.527907949048538e-02, -7.577360595943729e-03, -1.837194831996730e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_x_t_sloc_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_x_t_sloc", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.985779227548806e-02, 3.125865372957169e-133, -1.985815000898652e-02, -2.077788911805245e-02, -1.562932686478584e-133, -2.077868790057982e-02, -2.217475650241647e-02, 3.125865372957169e-133, -2.217660073684882e-02, -2.434587223139351e-02, 3.125865372957169e-133, -2.435034012970218e-02, -2.783587422431308e-02, 3.125865372957169e-133, -2.784747492219822e-02, -3.372231686513960e-02, 3.125865372957169e-133, -3.375559916680342e-02, -4.435394791497951e-02, 3.125865372957169e-133, -4.446420323899886e-02, -6.549704805070397e-02, -2.500692298365735e-132, -6.594627509283026e-02, -1.133925346764626e-01, 1.250346149182867e-132, -1.158503161980165e-01, -2.388519237104579e-01, -5.001384596731470e-132, -2.587795693006623e-01, -5.599035849207846e-01, -1.000276919346294e-131, -7.833664775343063e-01, -9.599188400322264e-01, 5.001384596731470e-131, -2.305215420664879e+00, -1.279358529308144e+00, 4.001107677385176e-131, -3.295668588944853e+00, -2.093723564848201e+00, -1.200332303215553e-130, -5.204390023831734e+00, -4.863317810663385e+00, -2.400664606431105e-130, -1.296031241883007e+01, -1.715043217742899e+01, -4.801329212862211e-130, -5.485549377936847e+01, -1.019632016797237e+02, 1.280354456763256e-129, -4.532589741720428e+02, -1.220749010664567e+03, -6.145701392463630e-128, -9.364205128855028e+03, -3.905214398273783e+04, -6.555414818627872e-127, -6.963014992752774e+05, -5.124797292336105e+06, -9.230024064628044e-124, -2.891303762999498e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
