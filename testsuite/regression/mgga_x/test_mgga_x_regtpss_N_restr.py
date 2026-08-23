
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_regtpss_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.786420861728217e+00, -4.689507554642629e+00, -4.553629382618215e+00, -4.365240276032813e+00, -4.108200564128095e+00, -3.765438548947839e+00, -3.323105941992117e+00, -2.778809558741957e+00, -2.156449492952729e+00, -1.528175558620070e+00, -9.832709951292430e-01, -6.430602822164136e-01, -5.586365340778638e-01, -4.763253827121837e-01, -3.366344723138153e-01, -2.074952703806377e-01, -1.149551736323655e-01, -4.159394134226837e-02, -8.766646563933047e-03, -9.701577328989595e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_regtpss_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.115157433446996e+00, -5.986496516369795e+00, -5.806358937500541e+00, -5.557118002657687e+00, -5.218060167174412e+00, -4.767773724148311e+00, -4.189349924077263e+00, -3.477764657492683e+00, -2.644019245697311e+00, -1.737398698721504e+00, -1.018951842581095e+00, -8.349273820832861e-01, -7.371160804156096e-01, -5.889142043053117e-01, -3.931621088233588e-01, -1.948903625782807e-01, -1.178567017488090e-01, -5.342505660541678e-02, -1.166830330735492e-02, -1.293514386966929e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtpss_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.780459184377128e-06, -8.307223977496381e-06, -9.119983623046043e-06, -1.041088744252800e-05, -1.254447852804152e-05, -1.626462995896377e-05, -2.322391926052342e-05, -3.755048072463300e-05, -7.260092067715443e-05, -2.019153992265662e-04, -9.825892535300243e-04, -1.967710579225606e-03, -1.178575011621455e-02, -5.088277014259259e-02, -1.021754464459238e-01, -4.973190362285120e-01, -2.416226853413742e+00, -4.582657321334598e+00, -5.597482132399514e+00, -6.185930432668519e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtpss_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.118872284155432e-02, 1.126179532643923e-02, 1.135825130400320e-02, 1.147768386121303e-02, 1.160541434152781e-02, 1.168646683517156e-02, 1.156199014922286e-02, 1.084032365611974e-02, 8.810814509179759e-03, 5.279053017288669e-03, 2.415674523707177e-03, 1.773346071100932e-04, 9.554543949444065e-03, 5.305315179674655e-02, 3.273130615292701e-02, 7.578207376623632e-03, 1.744604774170264e-04, 1.294233639363747e-07, 2.935783862666994e-12, 7.222119979483785e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtpss_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.092679048147476e-02, -1.126371423312903e-02, -1.175505989824877e-02, -1.247415886014300e-02, -1.353053134454948e-02, -1.509425301579820e-02, -1.751090066149898e-02, -2.226144122465407e-02, -3.997425811116625e-02, -1.282710921627975e-01, -3.784118407490237e-01, -4.739999576492185e-01, -7.858273713048919e-01, -1.114463810027824e+00, -2.169886213804658e+00, -5.665996171160593e+00, 5.623962609030271e+01, -3.111956713394987e+02, -1.333034282514967e+04, -1.116490697634995e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtpss_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.791572909320390e-08, -5.642477505003471e-08, -7.119591373302778e-08, -9.894522743907637e-08, -1.571196749218418e-07, -2.986759879044218e-07, -7.167524878178609e-07, -2.264890232979568e-06, -9.081814395464809e-06, -3.123709095853874e-05, 1.567789492509780e-04, 4.034425201436045e-03, -3.747099050341808e-03, -9.687372354121790e-02, -1.500242135588194e+00, -2.192907971309128e+01, -6.612135881833582e+03, -5.456681324154510e+05, -7.823806141584134e+07, -6.408805326479864e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtpss_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.788757020774065e-05, 1.064557848859003e-04, 1.200104738476952e-04, 1.423238352676834e-04, 1.811265448035781e-04, 2.537370247630774e-04, 4.026577676823945e-04, 7.387685059598307e-04, 1.519995650804718e-03, 2.818909340020558e-03, 3.399542626006659e-03, -2.234347695598924e-03, 7.899093352528193e-02, 2.666054851593944e-01, 1.120554294402410e+00, 2.853317302150779e+00, 9.991436893778324e-01, 3.562980951440891e-02, 1.021718587030963e-04, 1.910244208744946e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtpss_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.157807582487899e-12, 2.639684408909760e-12, 3.523456069551866e-12, 5.324277898522556e-12, 9.586479908480524e-12, 2.204493031340078e-11, 7.082469453904966e-11, 3.529119269305265e-10, 2.976358624372983e-09, 4.222742626389816e-08, 1.302580670232450e-06, -2.585116458790523e-04, -1.795588631233278e-02, 1.945998476408046e-02, 3.517698889311458e+00, 4.873832075006351e+02, 6.705694607173895e+05, 1.657554935411796e+09, 2.841616290397854e+13, 1.806738495685192e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtpss_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.325216476496654e-09, -2.659332076055014e-09, -3.222176545321639e-09, -4.236260743829957e-09, -6.243773632132288e-09, -1.076762375757632e-08, -2.287627121509659e-08, -6.291345801907834e-08, -2.235583282135044e-07, -7.339503727871660e-07, 5.333000411102108e-06, 2.982440408993343e-04, 3.596114250589010e-02, 2.116556690571258e-01, -1.238585501311201e-01, -8.277723452197176e+00, 5.301264294334237e-01, -6.251718215206314e+01, -2.691615029742812e+01, -4.090422030865173e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_regtpss_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_regtpss", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.391896781290302e-06, 2.540920708783397e-06, 2.766273858404258e-06, 3.112236781864794e-06, 3.650034558781481e-06, 4.480332718530639e-06, 5.650067083829747e-06, 6.513163706488604e-06, 1.961344593070197e-06, -3.387181225641840e-05, -1.855782074498831e-04, -1.374621957726653e-04, -7.309275191425428e-02, -5.371903700305707e-01, -7.147494616961027e-01, -1.040413222558538e+00, -8.217825255241246e-01, -8.044506299787941e-03, -6.478554924281972e-06, -3.901322108511274e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
