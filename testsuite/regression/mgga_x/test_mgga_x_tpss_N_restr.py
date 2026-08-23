
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_tpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.717313264658293e+00, -4.621904375778337e+00, -4.488184532516915e+00, -4.302894531209314e+00, -4.050319471194827e+00, -3.714045090840046e+00, -3.281315148329480e+00, -2.751669732249398e+00, -2.152097984485460e+00, -1.554617188978137e+00, -1.021277041532726e+00, -6.494045443520912e-01, -5.604932266689684e-01, -4.801927634740397e-01, -3.416258794674245e-01, -2.175744771723416e-01, -1.197658117134091e-01, -4.187048528295585e-02, -8.769439255074979e-03, -9.701617068941892e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_tpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.770696728533494e+00, -5.660503221768817e+00, -5.505933957079501e+00, -5.291426062697902e+00, -4.998139182339433e+00, -4.605139185462090e+00, -4.091820300056399e+00, -3.439991699770403e+00, -2.633889385523166e+00, -1.712578510625937e+00, -1.001145898475097e+00, -8.306217890902149e-01, -7.280494916281982e-01, -5.844747815045715e-01, -3.940854523154461e-01, -1.923479082463507e-01, -1.305926796834385e-01, -5.448551243646849e-02, -1.167945263576728e-02, -1.293530282556203e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.478408536884973e-05, -1.523099939079789e-05, -1.588781677524349e-05, -1.686048315346115e-05, -1.831518902792577e-05, -2.052402899231423e-05, -2.401171086265080e-05, -3.049020138058892e-05, -5.120338687730025e-05, -1.794304342572727e-04, -1.098884852757893e-03, -2.638112209002566e-03, -1.574031058991070e-02, -4.298560747398635e-02, -8.374359898407142e-02, -5.443515930578018e-01, -1.975174567752864e+00, -3.023611218834854e+00, -3.575695677773870e+00, -3.945369433645118e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tpss_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.096222949058221e-02, 2.030572886291643e-02, 1.938511335860053e-02, 1.810843724123012e-02, 1.636708098853245e-02, 1.405272512964990e-02, 1.111049076445893e-02, 7.678606326853629e-03, 4.358372667814789e-03, 2.242775068684330e-03, 1.635479944022936e-03, -2.068627703938352e-04, 9.197046938864552e-03, 3.502085177636491e-02, 1.703770743330874e-02, 2.665618632296539e-03, 3.230509704348823e-05, 8.201985881843887e-09, 8.209836985028523e-14, 9.720520444427595e-21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.568074534018486e-03, -4.650878381017240e-03, -4.776751631890051e-03, -4.977921501257340e-03, -5.333349261010352e-03, -6.088393817068179e-03, -8.198951571658175e-03, -1.611945625426392e-02, -5.171569968486674e-02, -1.795605663361539e-01, -3.935633007666991e-01, -4.398171740725471e-01, -6.935742070355039e-01, -7.428110170740001e-01, -2.808133753187776e+00, -2.793563404937399e+00, 5.025893533009125e+01, -4.008591949399317e+02, -1.344695137346085e+04, -1.116614206205959e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.307918998866910e-07, -1.481369896266574e-07, -1.769307017237146e-07, -2.276823302600248e-07, -3.248307940984415e-07, -5.323083848962778e-07, -1.038239103061672e-06, -2.418950107764141e-06, -5.562851956810564e-06, 2.703435328329547e-06, 1.603495124711517e-04, 6.682052111617088e-03, 2.818081021350023e-02, -1.997893448353912e-01, -6.700318236420243e-01, -2.586394093907873e+01, -6.418259720417890e+03, -3.682866058152755e+05, -5.003209676141845e+07, -4.087574386171979e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tpss_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.468601151108586e-04, 1.567303115530259e-04, 1.719256892734805e-04, 1.959697037543522e-04, 2.354371278391838e-04, 3.033133489217503e-04, 4.264133246436990e-04, 6.601860978695589e-04, 1.111736851236341e-03, 1.990110514709032e-03, 3.949868771402024e-03, -7.884991194683846e-03, 1.095198853785562e-02, 2.153375313391468e-01, 9.670321871135692e-01, 1.444125402944993e+00, 7.250732869343966e-02, 3.118799975017569e-03, 9.299970068622383e-06, 1.641631222630633e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.679250790308886e-12, 2.063094185055942e-12, 2.766265509567619e-12, 4.194304616205335e-12, 7.547223766580253e-12, 1.717902742874664e-11, 5.358996507586741e-11, 2.507339995307651e-10, 1.920559564743856e-09, 3.086084477545041e-08, 2.580111265405185e-06, -8.352602999264979e-04, -2.326198376334011e-02, 1.520231095537615e-01, 3.601985608728187e+00, 5.323426109972430e+02, 6.145220677938466e+05, 1.112168252971632e+09, 1.816687196590039e+13, 1.152344679756801e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tpss_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.059098333549007e-09, 2.156048486237243e-09, 2.284881086878657e-09, 2.432856578356636e-09, 2.505856091322876e-09, 2.037645008741693e-09, -1.293910566043105e-09, -2.054778924994312e-08, -1.429981276134345e-07, -1.016229428386943e-06, -6.824187879515113e-06, 8.194968087835754e-04, 3.404083750893266e-02, 3.444787631795143e-02, -9.220741405483691e-01, -7.646010509179217e+00, 2.680852008896903e+01, -8.279500986609062e+00, -5.406633049312270e+00, -8.355254797178514e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tpss_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.221199117803531e-06, -9.425981672655867e-06, -9.713175588764410e-06, -1.010512557829190e-05, -1.060575220206694e-05, -1.113007261292009e-05, -1.125975723685457e-05, -9.474170959941126e-06, -1.665877181252998e-06, 1.069541321191376e-05, -5.429414616049636e-05, -1.930875863023564e-04, -4.382209538217766e-02, -2.119967830170675e-01, -4.543233789702057e-02, -6.317518081265924e-02, -3.691545967659246e-01, 4.102342735328608e-04, 1.005799525729769e-05, 2.363182222986633e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
