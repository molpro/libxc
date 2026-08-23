
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_revtpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.783100524403965e+00, -4.686191550314873e+00, -4.550321846026629e+00, -4.361950550673171e+00, -4.104951070082152e+00, -3.762285550788314e+00, -3.320192548628198e+00, -2.776475767147143e+00, -2.155267986262341e+00, -1.528093369056718e+00, -9.832790037982416e-01, -6.457642436168972e-01, -5.584117539382676e-01, -4.750112037608880e-01, -3.365949744245986e-01, -2.074952703150384e-01, -1.149551736323655e-01, -4.159394134226837e-02, -8.766646563933047e-03, -9.701577328989595e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_revtpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.674447680767168e+00, -5.564969402275421e+00, -5.411551451819522e+00, -5.198956186034165e+00, -4.908959539697466e+00, -4.521826767962166e+00, -4.019317332261128e+00, -3.387762167590974e+00, -2.617800796495608e+00, -1.736551448886183e+00, -1.019090695277552e+00, -8.381119861673977e-01, -7.331063668653502e-01, -5.798790825356619e-01, -3.928529575465787e-01, -1.948903659941749e-01, -1.178567017488090e-01, -5.342505660541678e-02, -1.166830330735492e-02, -1.293514386966929e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.016518033340381e-05, -2.091121306015362e-05, -2.202477900127546e-05, -2.371193505029826e-05, -2.632084588488345e-05, -3.047030380376935e-05, -3.735661705978182e-05, -4.982530055015533e-05, -7.905436922707840e-05, -2.017455777969436e-04, -9.819381859888373e-04, -1.273933035153192e-03, -1.127349106559649e-02, -4.891343881329362e-02, -1.016650495185862e-01, -4.973189377116271e-01, -2.416226853413742e+00, -4.582657321334598e+00, -5.597482132399514e+00, -6.185930432668519e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtpss_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.871309180602775e-02, 2.802465336644936e-02, 2.705736765261504e-02, 2.571121674730928e-02, 2.386270669627327e-02, 2.137267993583723e-02, 1.811579554626889e-02, 1.406493890418957e-02, 9.489351107266992e-03, 5.248686074636881e-03, 2.412019232666491e-03, -6.125486690830075e-04, 7.527891615039961e-03, 4.569834961951658e-02, 3.223607341700922e-02, 7.578197211325318e-03, 1.744604774170264e-04, 1.294233639363747e-07, 2.935783862666994e-12, 7.222119979483785e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.347831255383035e-03, -4.382015427971622e-03, -4.426267375506983e-03, -4.481938735064812e-03, -4.556300086963275e-03, -4.707757670859114e-03, -5.332512647890149e-03, -8.940217353092072e-03, -3.034842242186525e-02, -1.276414259942105e-01, -3.795504733194207e-01, -4.179314044652931e-01, -6.644037557177088e-01, -8.892475008713974e-01, -2.140726125932620e+00, -5.665990491194599e+00, 5.623962609030271e+01, -3.111956713394987e+02, -1.333034282514967e+04, -1.116490697634995e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.405467267464304e-07, -1.596239889874278e-07, -1.914677435019518e-07, -2.480838353598888e-07, -3.580146378909161e-07, -5.987605177218003e-07, -1.215575249615986e-06, -3.111827838713966e-06, -9.798133779594355e-06, -3.009937277229355e-05, 1.628731752363801e-04, 3.297206314405078e-03, 9.545888106323683e-03, -6.083847186793614e-02, -1.430294371825956e+00, -2.192930412615212e+01, -6.612135881833582e+03, -5.456681324154510e+05, -7.823806141584134e+07, -6.408805326479864e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtpss_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.680478962429836e-04, 1.793499138781456e-04, 1.967962820997287e-04, 2.245230747001920e-04, 2.703766398405004e-04, 3.503058787345874e-04, 4.990830963146129e-04, 7.969734854099621e-04, 1.432254988145445e-03, 2.729641338875500e-03, 3.362500412017076e-03, -6.467962052802013e-03, 1.767837988372280e-02, 8.652286677299843e-02, 1.057355939526975e+00, 2.853341961056369e+00, 9.991436893778324e-01, 3.562980951440891e-02, 1.021718587030963e-04, 1.910244208744946e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.096451337317418e-12, 2.568095269165278e-12, 3.430642223675524e-12, 5.179075466324321e-12, 9.278033178616216e-12, 2.105638160230194e-11, 6.584825597141659e-11, 3.137925149079313e-10, 2.543824500251519e-09, 4.092913021518463e-08, 1.274376216528749e-06, -5.000869960391802e-04, -1.619264217345275e-02, -4.488251315728334e-03, 3.459255029278123e+00, 4.873911651658561e+02, 6.705694607173895e+05, 1.657554935411796e+09, 2.841616290397854e+13, 1.806738495685192e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtpss_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.326025417105637e-09, 2.455865255505670e-09, 2.640173945413620e-09, 2.888801892111614e-09, 3.165052969107146e-09, 3.176416253636519e-09, 1.254004833447462e-09, -1.247796086634066e-08, -1.043144258190244e-07, -6.802645619894665e-07, 5.457333058321616e-06, 4.946261977349641e-04, 2.811546155485413e-02, 2.210836400982384e-01, -1.350766258148372e-01, -8.278592224056259e+00, 5.301264294334238e-01, -6.251718215206314e+01, -2.691615029742812e+01, -4.090422030865173e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revtpss_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.069772699417727e-05, -1.099373503059704e-05, -1.142452440395095e-05, -1.205169597745759e-05, -1.296030222410897e-05, -1.425158572124160e-05, -1.598780221170884e-05, -1.802740370314847e-05, -2.033290232802966e-05, -3.498278284942343e-05, -1.858573887786315e-04, 5.519500024562954e-05, -3.961011612049108e-02, -4.400594768251833e-01, -6.666211594370545e-01, -1.040319125528635e+00, -8.217825255241246e-01, -8.044506299787941e-03, -6.478554924281972e-06, -3.901322108511274e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
