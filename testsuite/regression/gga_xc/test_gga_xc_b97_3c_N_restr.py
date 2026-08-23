
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_b97_3c_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_3c", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.499494532651648e+00, -4.409273912262059e+00, -4.282933815170241e+00, -4.108099810734898e+00, -3.870273890336906e+00, -3.554724784706664e+00, -3.151101788663127e+00, -2.662594619443433e+00, -2.121376358364394e+00, -1.598708522875735e+00, -1.098013560529446e+00, -7.154927996379056e-01, -6.211417739443783e-01, -5.130482755187303e-01, -3.731747689542134e-01, -2.466147129877297e-01, -1.388374660798460e-01, -4.189839698511089e-02, -6.245427828542946e-03, -5.372096384298249e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_b97_3c_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_3c", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.012594396280202e+00, -5.888772596885018e+00, -5.714959816253177e+00, -5.473499150914797e+00, -5.142904902894770e+00, -4.699174291795222e+00, -4.118868664103399e+00, -3.383703463744217e+00, -2.489044040121653e+00, -1.511901120389328e+00, -9.077337597826610e-01, -9.118124722716877e-01, -8.077655280449252e-01, -6.399154917926642e-01, -4.192613779239583e-01, -2.097922571836429e-01, -1.267089661380814e-01, -5.601667504760719e-02, -8.692222959161186e-03, -7.268261458053862e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_3c_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_3c", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.359182431997805e-07, 3.186317754347799e-07, 2.836590405828566e-07, 2.071625454655599e-07, 2.301584446012452e-08, -4.779911451974489e-07, -2.078642442731030e-06, -8.384742438066627e-06, -4.037587764083307e-05, -2.433756055960265e-04, -1.455334781224561e-03, -2.559161226357860e-03, -4.801395302473096e-03, -1.298248665514386e-02, -6.618055411808069e-02, -6.384326584764153e-01, -4.515886467208395e+00, -7.564411735142227e+00, -4.200608815165343e+00, -9.608679999095086e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_3c_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_3c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.217524639930195e-02, -1.276228307457030e-02, -1.366787329242859e-02, -1.511232521502444e-02, -1.753681566355941e-02, -2.194102708720077e-02, -3.098698116361802e-02, -5.328620791814408e-02, -1.220469870076770e-01, -3.545204903331614e-01, -8.839625982765452e-01, -5.623731915051858e-01, -7.465941283534472e-01, -1.152868736115737e+00, -3.734689908268884e+00, -1.569559128182983e+01, 8.074852782111527e+01, -3.255714747863618e+02, -1.193017776570989e+04, -6.699925525168434e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_3c_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_3c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.088710248721818e-08, 1.304698766209129e-08, 1.694219117683184e-08, 2.470052339633327e-08, 4.250766455881923e-08, 9.242161004706723e-08, 2.766312580086978e-07, 1.254121062954272e-06, 9.315670238705940e-06, 1.109214965453934e-04, 1.923102171693485e-03, 6.251115871636465e-03, 3.739324648471053e-02, 6.506874096805693e-02, 1.751437722344055e+00, 6.267794587501922e+01, -8.321196040875533e+03, -8.859260830929258e+05, -6.136894926629898e+07, -1.068896853182062e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_b97_3c_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_b97_3c", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.344039749910475e-13, -1.666227853714792e-13, -2.276360361190041e-13, -3.585424834657700e-13, -6.956437775563774e-13, -1.827270989954812e-12, -7.369533747299301e-12, -5.286408178276627e-11, -7.698626471655131e-10, -2.309134399686150e-08, -2.042419190393053e-06, 2.401628270154993e-05, -6.403474798505042e-03, 1.004025623758556e-02, -4.676791194840356e-01, -2.604697109214544e+00, 9.237314271322150e+05, 2.609544315373193e+09, 2.122164425745172e+13, 2.805592968798840e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
