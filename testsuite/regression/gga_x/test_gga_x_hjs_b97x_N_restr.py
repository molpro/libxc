
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_hjs_b97x_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b97x", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.165764541947917e+00, -4.082903338160096e+00, -3.966857810014770e+00, -3.806241490471642e+00, -3.587677975444149e+00, -3.297451282376021e+00, -2.925438526776956e+00, -2.472407570908012e+00, -1.960600812814951e+00, -1.440305313815488e+00, -9.466140237371942e-01, -5.853642355561032e-01, -4.952793887057090e-01, -3.961718349986643e-01, -2.676651035967483e-01, -1.564734749590720e-01, -8.013289296870155e-02, -1.202724073010830e-02, -2.502911089890367e-05, -2.506264350159251e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_hjs_b97x_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b97x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.400792014090240e+00, -5.286935447084314e+00, -5.127252563889562e+00, -4.905750716272930e+00, -4.603284978129564e+00, -4.199359615026273e+00, -3.676595377165101e+00, -3.029160417689707e+00, -2.276798254277810e+00, -1.492123532537486e+00, -9.064496574098784e-01, -7.568099398404088e-01, -6.642442085438957e-01, -5.094013002124753e-01, -3.044616468555729e-01, -1.113654883073553e-01, -4.959308724130388e-02, -1.953849068017496e-02, -5.706106422191006e-05, -5.012824846453334e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b97x_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b97x", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.868896486976576e-06, -2.029348448258876e-06, -2.284355082446460e-06, -2.707730907055077e-06, -3.456171792126388e-06, -4.904003593482632e-06, -8.090337305504668e-06, -1.651053746849098e-05, -4.516441202881775e-05, -1.806403042128186e-04, -1.002168408259954e-03, -3.478654459712379e-03, -5.701567673599171e-03, -1.412702228822016e-02, -6.741941637844279e-02, -6.215051469480667e-01, -5.024945437551215e+00, -8.902984519474549e+00, -6.928560823966601e-02, -2.413092440020687e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b97x_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.151531051279579e-02, -1.204615353620470e-02, -1.285536708081528e-02, -1.412138370903696e-02, -1.617868873721686e-02, -1.971374709845320e-02, -2.631018540727265e-02, -4.020170733658931e-02, -7.498084751673575e-02, -1.833363906035675e-01, -4.334592063332964e-01, -5.396709326317022e-01, -6.375128350127597e-01, -1.143094260810126e+00, -3.312735739738645e+00, -1.114499850212600e+01, 1.044940477087635e+02, -3.798430046343690e+01, -2.702190764490933e+02, -1.298637620883147e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b97x_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.446785580731767e-08, 1.671758296181344e-08, 2.057555818711001e-08, 2.772149276592932e-08, 4.250755074853499e-08, 7.836602350234294e-08, 1.873992056130844e-07, 6.427900799887774e-07, 3.593801492160647e-06, 3.842667468832579e-05, 6.199198380936321e-04, 8.146154692435384e-03, 1.940496721496533e-02, 9.728046609357477e-02, 1.454807722133275e+00, 3.469254543190254e+01, -9.262946036401199e+03, -1.088532370609178e+06, -1.377801843958355e+06, -3.706703565490493e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_b97x_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_b97x", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.043726723115333e-15, -7.611417984502391e-15, -1.058261300830885e-14, -1.691751255243002e-14, -3.284086384793728e-14, -8.287705982284435e-14, -2.903488660417349e-13, -1.355255991650121e-12, -3.438085192321060e-13, 9.728188981008184e-10, 5.626143826620706e-07, -6.355975890746544e-05, -5.203540819562622e-04, -4.303978190393269e-03, -1.457800847179587e-01, 1.885658035792956e+02, 1.071441846710247e+06, 3.037023823770114e+09, 3.488674648239408e+11, 7.045694485627728e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
