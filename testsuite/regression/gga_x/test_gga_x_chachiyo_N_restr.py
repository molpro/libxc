
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_chachiyo_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_chachiyo", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.319665252385940e+00, -4.237837709614115e+00, -4.123267914498390e+00, -3.964750158198903e+00, -3.749150199052635e+00, -3.463050721746854e+00, -3.096601917104657e+00, -2.650420652966331e+00, -2.144592593270581e+00, -1.620240228731713e+00, -1.094612307207635e+00, -6.672292134380921e-01, -5.646173338714823e-01, -4.740587883831244e-01, -3.508407327269690e-01, -2.369684759702350e-01, -1.602705705931411e-01, -1.147832034937443e-01, -8.111388676436884e-02, -5.468766452902754e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_chachiyo_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_chachiyo", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.385475148751024e+00, -5.271660439092061e+00, -5.112113464583699e+00, -4.890969155300741e+00, -4.589370095999747e+00, -4.187473763702463e+00, -3.669401577897971e+00, -3.032727145919985e+00, -2.304118020011540e+00, -1.564686165872353e+00, -9.930884789993167e-01, -8.020627512920102e-01, -7.154669582363157e-01, -5.574374408355534e-01, -3.592040032552087e-01, -1.826733351530529e-01, -7.351936336152176e-02, -3.365546897150283e-02, -2.057813374562492e-02, -1.084801902533205e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_chachiyo_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_chachiyo", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.013790696714032e-06, -4.329398620434830e-06, -4.826063800376539e-06, -5.638747141508071e-06, -7.044702267792259e-06, -9.677725417860793e-06, -1.519477837285002e-05, -2.873119217810647e-05, -7.006935258983349e-05, -2.396871000100839e-04, -1.242218210050201e-03, -7.027390450244598e-03, -1.387824243905791e-02, -2.773096917980372e-02, -1.023141240648473e-01, -7.137097141667896e-01, -9.502341879235743e+00, -2.690285054686135e+02, -2.384345199619590e+04, -1.312352692948728e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_chachiyo_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_chachiyo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.196471430804536e-02, -1.250704350617559e-02, -1.333049150533050e-02, -1.461069368338898e-02, -1.666969979087260e-02, -2.014612578572788e-02, -2.643560593606569e-02, -3.896671353498372e-02, -6.731573893954115e-02, -1.407994581462482e-01, -3.376467200032980e-01, -5.505167432845995e-01, -6.688534651859140e-01, -1.147933017229693e+00, -2.736157487016732e+00, -8.795498816575735e+00, -2.311146434126651e+01, 4.864106901022907e+02, 4.545087432621157e+04, 1.783402097917683e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_chachiyo_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_chachiyo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.082387934709152e-08, 2.372148294791187e-08, 2.859457736376034e-08, 3.736619597396036e-08, 5.476466402329531e-08, 9.438641784333762e-08, 2.040783575249521e-07, 6.030759917733589e-07, 2.712053516345939e-06, 2.105393019937865e-05, 3.505096166782498e-04, 9.535749494909576e-03, 3.300296641875362e-02, 1.032799830996818e-01, 8.942346864247294e-01, 1.908911424766933e+01, -1.249313609865545e+02, -1.881510438152567e+06, -1.891357344079663e+10, -5.751025661923585e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_chachiyo_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_chachiyo", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.720704419931434e-14, 1.205437568011396e-13, 1.641766631455277e-13, 2.557174376530549e-13, 4.824079332838574e-13, 1.195084848986012e-12, 4.352505073415953e-12, 2.722659072837065e-11, 3.610756856894507e-10, 1.334424222125179e-08, 1.812307197189712e-06, 4.488158800850574e-04, 4.458372840570400e-03, 2.594327250463248e-02, 1.075982114791678e+00, 3.355071622878092e+02, 8.830438592108873e+05, 2.935379969110747e+10, 3.545498254693400e+16, 1.079869308456799e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
