
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_scan0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.663392072239652e+00, -3.589224972883617e+00, -3.485267708614053e+00, -3.341194537791769e+00, -3.144733816578858e+00, -2.882951210094653e+00, -2.545342516240916e+00, -2.129417433387129e+00, -1.648137860284939e+00, -1.129188357574547e+00, -6.296823382494827e-01, -4.268261837401086e-01, -4.259789649438699e-01, -3.699402664894523e-01, -2.497677626389817e-01, -1.300471126960773e-01, -4.968482045951925e-02, -1.266769473376820e-02, -1.664311160218862e-03, -7.612016077196137e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_scan0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.808034244503699e+00, -4.708249529371773e+00, -4.568357979840386e+00, -4.374426821772938e+00, -4.109856750246220e+00, -3.757050265345852e+00, -3.301421747109257e+00, -2.738378371969322e+00, -2.080496676353966e+00, -1.329511688737221e+00, -8.572204669973109e-01, -5.883751868705037e-01, -6.595569760078126e-01, -4.973378016645985e-01, -3.061183476205120e-01, -1.511559385879538e-01, -4.716334302853745e-02, -1.910705514873209e-02, -2.966119549831912e-03, -1.466288569662797e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_scan0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.354454935029972e-06, -2.543876725028424e-06, -2.842685268180148e-06, -3.333436323479162e-06, -4.187515363058378e-06, -5.803579361259387e-06, -9.258887640089329e-06, -1.815129103647502e-05, -4.952011275408642e-05, -2.841656030691282e-04, -6.353888749204566e-04, -4.266434459944848e-03, -2.225995801053625e-02, -3.444406421474058e-02, -1.442950687546800e-01, -5.283503050704201e-01, -5.256514804413689e+00, -1.823770373565898e+00, 1.882777067914591e+02, 9.516237429632740e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_scan0_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.489062083804390e-03, 3.549541250083909e-03, 3.637889609771472e-03, 3.767835397488420e-03, 3.960937742246481e-03, 4.252683631379684e-03, 4.707297530754463e-03, 5.469048707181273e-03, 7.051959243441635e-03, 1.388082519956919e-02, 8.054432565776206e-03, 6.311180927169916e-03, 6.033622831328751e-02, 5.657394958077337e-02, 7.832274183133583e-02, 5.216131456884095e-02, 4.505852189814934e-02, 2.638470197850472e-03, 5.337576371376997e-05, 1.308388827127725e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_scan0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.849889901550691e-03, -1.027392204195816e-02, -1.091473222925791e-02, -1.190397459919180e-02, -1.347794894574724e-02, -1.609127083005826e-02, -2.069555763346079e-02, -2.948748331541631e-02, -4.803838530863063e-02, -1.009414774907384e-01, -2.677582260374701e-01, -7.775221185648122e-01, -1.437969853251823e+00, -1.140740198822817e+00, -2.953347949535557e+00, -1.923541114214623e+02, -6.107201588397520e+02, -1.804792146115348e+03, -1.358046908555195e+04, -3.641801210465606e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_scan0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.493802193824472e-09, 8.249130167428407e-09, 9.420518332445876e-09, 1.125668313089420e-08, 1.405011722831867e-08, 1.725636373988397e-08, 1.098285975727029e-08, -1.186715333603063e-07, -2.214918921183949e-06, -7.243719573778874e-05, -7.222276320282261e-05, -5.405586125895945e-03, -6.410268912764375e-02, 1.658134553627676e-01, -5.908740785918292e-01, 3.629261091153807e+03, 1.179245051147307e+05, 9.718065832368955e+06, 5.574648678935684e+09, 5.788030637796639e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_scan0_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.938020277640546e-06, 5.756907239609508e-06, 7.132666438163376e-06, 9.598074358622248e-06, 1.443150912890683e-05, 2.516221885116400e-05, 5.346396901536501e-05, 1.488187146550016e-04, 6.200290586969747e-04, 5.388239361659085e-03, 3.678770487310503e-03, 4.601811934953449e-02, 4.284491354561681e-01, -4.776131850535151e-02, 1.276561006525788e+00, -3.342360353385935e+02, -8.824291315086014e+02, -2.359124952710950e+03, -9.956162032561562e+03, -3.713278464283920e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_scan0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.166912389029403e-13, 2.743517044495931e-13, 3.849186114438462e-13, 6.254932574701362e-13, 1.253495822735829e-12, 3.385582251888644e-12, 1.397853308385760e-11, 1.060596240463485e-10, 2.002119336519062e-09, 1.833483016544851e-07, -8.423371150891253e-06, 7.237511664723269e-04, -1.479985748069521e-02, 1.862724195416809e-01, 1.374920483563692e+01, -7.114591662026622e+04, -2.433943029494428e+07, -6.260102321557607e+10, -3.931223401923799e+15, -2.363075130966187e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_scan0_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.479864514090366e-10, -2.962505774926984e-10, -3.823963997676289e-10, -5.514150128634282e-10, -9.314007918497060e-10, -1.970875514763742e-09, -5.748926188708514e-09, -2.662166165631332e-08, -2.486860476100374e-07, -8.351042724660703e-06, 1.182727546125077e-04, 4.853558601135579e-04, 7.014146447679674e-02, -2.642835788328322e-01, -6.905331779564047e+00, 6.632158298815204e+03, 1.913502825853194e+05, 1.581473604464615e+07, 7.676875003361704e+09, 2.158065768206474e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_scan0_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_scan0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.850881432698338e-07, 3.212231300353169e-07, 3.812682988870641e-07, 4.875564393442139e-07, 6.936243367964289e-07, 1.149184161441290e-06, 2.367932695786066e-06, 6.697772978028148e-06, 3.099556791281751e-05, 3.817759527145600e-04, -1.564208895929653e-03, -4.831972278875021e-03, -2.653013921738391e-01, 3.920788180849439e-01, 3.513235647907670e+00, -6.181980125738874e+02, -1.507313043782158e+03, -4.086056190187669e+03, -1.759541189105976e+04, -6.678627568895763e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
