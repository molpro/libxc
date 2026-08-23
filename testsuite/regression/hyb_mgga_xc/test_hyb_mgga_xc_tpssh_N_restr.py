
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_tpssh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.298709232555176e+00, -4.212320773867196e+00, -4.091215927260617e+00, -3.923348114990101e+00, -3.694399467973712e+00, -3.389320526239300e+00, -2.996177439768005e+00, -2.513811152275354e+00, -1.965524301467306e+00, -1.416686537467672e+00, -9.313528910622161e-01, -6.275110352278204e-01, -5.566976578111070e-01, -4.685661062189093e-01, -3.282129469488467e-01, -2.020705637391621e-01, -1.082566208077892e-01, -3.768876333345310e-02, -7.892500619490031e-03, -8.731455363690081e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_tpssh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.313734839157382e+00, -5.213317922510928e+00, -5.072438205085265e+00, -4.876881721829110e+00, -4.609419902325218e+00, -4.250876498001102e+00, -3.782333294803986e+00, -3.186992325625835e+00, -2.449479049361059e+00, -1.601474556048156e+00, -9.493831514584873e-01, -8.359677224879800e-01, -7.375237145244840e-01, -6.006104419590975e-01, -4.119938455887899e-01, -1.992228091709080e-01, -1.200885448878846e-01, -4.906858151458770e-02, -1.051153971364453e-02, -1.164177255326252e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpssh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.199411378248916e-05, -1.234156094429138e-05, -1.285045957243255e-05, -1.360017242638820e-05, -1.471242976499302e-05, -1.638028756433144e-05, -1.896857590346274e-05, -2.374564293919779e-05, -3.987052836084863e-05, -1.466435539387224e-04, -9.001209277729810e-04, 1.066825653427414e-03, -4.406386611657077e-03, -2.458660379611435e-02, -4.506659003416387e-02, -4.020679695455042e-01, -1.660411606570247e+00, -2.672519454211249e+00, -3.212090744530906e+00, -3.550681998477607e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpssh_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.749413802998473e-02, 1.694964737107276e-02, 1.618723321440600e-02, 1.513223186353807e-02, 1.369778389302215e-02, 1.180003958620581e-02, 9.402737823342267e-03, 6.627359188434507e-03, 3.947057426610221e-03, 2.171057055685418e-03, 1.563007907051741e-03, -1.879818534646561e-04, 7.898413406608164e-03, 3.020917004726172e-02, 1.747680433082717e-02, 4.651547365451053e-03, 2.899096579002977e-04, 3.529913713818871e-06, 3.622315734860674e-09, 1.053437753905232e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpssh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.553317690990319e-03, -4.657887614289363e-03, -4.817541858594686e-03, -5.072283769529653e-03, -5.514164130706094e-03, -6.407510663409804e-03, -8.714203202313267e-03, -1.674038653050883e-02, -5.148926298983970e-02, -1.783949733341815e-01, -4.193882184056624e-01, -4.216821218592902e-01, -6.189313701479572e-01, -7.773913408379919e-01, -3.239435478080244e+00, -8.130248260743318e+00, 3.384663429426267e+01, -3.657086305730080e+02, -1.210284688194283e+04, -1.004952799769058e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpssh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.125416011976627e-07, -1.273564291663020e-07, -1.519195071098686e-07, -1.951337202577809e-07, -2.776138804373560e-07, -4.529138654970465e-07, -8.764596652774453e-07, -2.005152671859516e-06, -4.238271223329023e-06, 9.231096565212007e-06, 3.128757051222710e-04, 7.114544532542957e-03, 1.530654919373399e-02, -1.281127719171276e-01, 1.473893052230597e-01, 3.632357730598816e+00, -5.100601208353770e+03, -3.218307966401502e+05, -4.489084504410127e+07, -3.678559089822217e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpssh_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.306309196527554e-04, 1.392398878853494e-04, 1.524744254536129e-04, 1.733729256353836e-04, 2.075797665154028e-04, 2.661895355612583e-04, 3.720530100938277e-04, 5.729771991856866e-04, 9.685945668362676e-04, 1.785365451498171e-03, 3.607713642163971e-03, -7.229490314914361e-03, 8.716107260649145e-03, 1.543185329323480e-01, 7.738059169414334e-01, 1.636969519455567e+00, 1.073100428161171e+00, 4.841533488263301e-01, 5.791824986643714e-02, 1.266002837886429e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpssh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.542456291278595e-12, 1.888795408032761e-12, 2.521117951687968e-12, 3.799174177545891e-12, 6.779915553561311e-12, 1.526146318663954e-11, 4.687797331535300e-11, 2.142314738063654e-10, 1.569795095790965e-09, 2.294927292073729e-08, 1.591005717119642e-06, -1.524749354415235e-03, -2.878414671587291e-02, 8.167694476008713e-02, 1.645492347888169e+00, 2.522165705834898e+02, 4.932518943335273e+05, 9.739100471555194e+08, 1.630418152821378e+13, 1.037044279321952e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpssh_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.366034215209314e-09, 1.404199195738621e-09, 1.441796847154535e-09, 1.444703687114718e-09, 1.282135603381221e-09, 4.363326912952071e-10, -3.381529754025189e-09, -2.209735212975824e-08, -1.316924557451223e-07, -8.872401268854169e-07, -5.684916992680670e-06, 7.462829037907988e-04, 2.937903256500466e-02, 2.909586140711229e-02, -6.794234286259614e-01, -4.612891930254492e+00, 3.422617761586402e+01, 1.040355898584213e+01, 9.654399791618445e+00, 3.257842825057745e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_xc_tpssh_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpssh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.034681545737368e-06, -7.169849932071089e-06, -7.356092685814252e-06, -7.602405216706916e-06, -7.897085569066521e-06, -8.148722560951919e-06, -7.996508904648331e-06, -6.261604944710141e-06, -8.957779137087334e-08, 7.556567229024313e-06, -5.709160919511688e-05, -1.711435877286270e-04, -3.740260725113144e-02, -1.621262074063392e-01, -9.104519294664262e-02, -6.587124268685448e-01, -1.349253632769033e+00, -4.767177111112326e-01, -6.095306229811755e-02, -1.400734714264944e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
