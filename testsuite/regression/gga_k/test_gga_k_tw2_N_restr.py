
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_tw2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.451013986693879e+01, 9.084858274333645e+01, 8.584128512929995e+01, 7.914287183643891e+01, 7.046014413644029e+01, 5.969926700790703e+01, 4.718377089752543e+01, 3.386725601165215e+01, 2.133277365064437e+01, 1.131765352593919e+01, 4.922311881950900e+00, 2.208723371088754e+00, 1.629593317621704e+00, 1.100914448984673e+00, 5.531035999687232e-01, 1.991399961039339e-01, 4.449090366967672e-02, 4.831899104753849e-03, 2.087955761242815e-04, 2.553608726426886e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_tw2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.492206910557665e+02, 1.431690882861665e+02, 1.348991187583786e+02, 1.238480456135578e+02, 1.095478205681821e+02, 9.187605925144541e+01, 7.143087312414441e+01, 4.991022748579448e+01, 3.015193275770043e+01, 1.526218735108269e+01, 6.547798967475202e+00, 3.382755283949342e+00, 2.608482411890293e+00, 1.656506558118423e+00, 7.624139762525705e-01, 2.653754786373566e-01, 6.723094144284469e-02, 7.945500217075291e-03, 3.477717892033608e-04, 4.255979829003579e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.901672646316300e-05, 9.423913792667388e-05, 1.022556717627225e-04, 1.149064642997963e-04, 1.356610774407142e-04, 1.715885447005510e-04, 2.384306703570866e-04, 3.746536432022449e-04, 6.816793817343871e-04, 1.448892485510973e-03, 4.410815772107687e-03, 2.394859598554248e-02, 3.993988793443730e-02, 6.626178436573350e-02, 1.502202882581018e-01, 3.562240559347863e-01, 4.691399881069925e-01, 2.426102116821334e-01, 6.012685858628609e-02, 7.339972523729334e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.886757968547047e-01, 6.011544064882806e-01, 6.194993011550870e-01, 6.467019846147708e-01, 6.874929816562438e-01, 7.494540859480896e-01, 8.444756053038742e-01, 9.880841847877555e-01, 1.180486812780811e+00, 1.336898327788943e+00, 1.720743239479644e+00, 3.900311664967578e+00, 4.436388688227350e+00, 5.524941276453085e+00, 6.822597035898426e+00, 5.152272056032995e+00, 2.115223991009460e+01, 1.504572338168715e+02, 8.084000001651557e+02, 7.348661860155185e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.561010443893778e-07, -3.948541877782691e-07, -4.573033357360037e-07, -5.626174156316364e-07, -7.510730830456511e-07, -1.112262497925513e-06, -1.834838989040001e-06, -2.967629881557628e-06, 2.366437263801036e-06, 1.566106301726564e-04, 2.653706799067982e-03, -2.078474146230327e-02, -7.692794551525291e-02, -1.317475186513543e-01, 7.196897392340947e-01, 5.378941095208807e+01, 1.659999940844346e+03, 3.182206019831291e+04, 9.111341675300878e+05, 8.238208373414460e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.512456700442869e-12, -1.881174825081544e-12, -2.572630871106486e-12, -4.029049224595295e-12, -7.653541664980343e-12, -1.910764685417394e-11, -6.997374611977182e-11, -4.342729846672174e-10, -5.429952135587993e-09, -1.619305313291824e-07, -1.438045621762471e-05, -1.435039458401073e-03, -7.507579351709058e-03, -6.630950809008515e-02, -2.790822752716183e+00, -4.518871645450345e+02, -1.449141419908443e+05, -8.869313998094875e+07, -3.053886682636151e+11, -2.143815551048298e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
