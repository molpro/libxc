
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_op_b88_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_b88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.922569733403416e-02, -5.891369036314098e-02, -5.845374614637881e-02, -5.776877961196291e-02, -5.673439970451839e-02, -5.514359173830412e-02, -5.264330878635986e-02, -4.863819039267197e-02, -4.227342886518812e-02, -3.334331453410109e-02, -2.750003930011830e-02, -4.011385936200648e-02, -4.152586584038813e-02, -3.392769705324815e-02, -2.295831593054702e-02, -1.086529293611537e-02, -2.718719546208260e-03, -2.595142484437436e-04, -5.944283205279696e-06, -1.734480106346718e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_op_b88_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.605260364510796e-02, -7.615860585079866e-02, -7.630699701864678e-02, -7.651036870852418e-02, -7.677676718890369e-02, -7.708830307642572e-02, -7.732885432228814e-02, -7.705090896780130e-02, -7.483895247356499e-02, -6.781316578465807e-02, -5.942456918817293e-02, -5.888425210962654e-02, -5.412192416243234e-02, -5.260985817833332e-02, -4.383465651927278e-02, -2.585389269837005e-02, -7.739502878753124e-03, -8.354073475546087e-04, -2.107733931097493e-05, -6.499260270470643e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_b88_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.659733339643103e-07, 1.813775492356761e-07, 2.059309963298325e-07, 2.468204048055923e-07, 3.192448751093904e-07, 4.590060803633283e-07, 7.621100611439695e-07, 1.528556683258155e-06, 3.876971491050988e-06, 1.312480372993430e-05, 7.939206637263290e-05, 1.149281573398053e-03, 2.762993654284849e-03, 5.191498082203094e-03, 1.609637138113796e-02, 6.854694623910509e-02, 2.963296853262842e-01, 1.139754385798713e+00, 3.648951381980991e+00, 8.960417578116427e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_b88_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.657012899790667e-05, 7.068537685118501e-05, 7.682034828505599e-05, 8.599877355940972e-05, 9.953156671329526e-05, 1.177704680652011e-04, 1.314139084435601e-04, 6.607144117072631e-05, -5.777071353712735e-04, -4.826575171171562e-03, -2.171859623161933e-02, 1.756650776147079e-03, 2.419735725064454e-03, -1.145617570616114e-02, -2.321677465675306e-01, -2.100696114309831e+00, -1.266529209551975e+01, -5.388380120789934e+01, -1.817617349080411e+02, -4.561508960912597e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_b88_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.001321418499765e-10, -9.074335466014256e-10, -1.084608970958540e-09, -1.393490948511581e-09, -1.970693743859931e-09, -3.133444530907607e-09, -5.518834042143675e-09, -7.892244113193642e-09, 4.937174792014034e-08, 1.683546598793007e-06, 5.010258466712900e-05, -9.068377576691822e-04, -6.160521964860955e-03, -7.566589123931419e-03, 1.179334370151116e-01, 8.786241479161450e+00, 7.258014921723161e+02, 1.050542897408253e+05, 4.347165068150261e+07, 8.540323462095735e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_b88_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.687122805898277e-15, -9.760010321457132e-15, -1.374303150773522e-14, -2.242762242433689e-14, -4.512136259166892e-14, -1.218981663158221e-13, -4.963760975073291e-13, -3.540971285028300e-12, -5.320949652171044e-11, -2.105973029464964e-09, -3.397843804748182e-07, -1.545856113396531e-04, -1.484229307458703e-03, -1.068706639870512e-02, -4.429803616223850e-01, -9.211677465442894e+01, -7.774435346542891e+04, -3.461229114303499e+08, -1.655470856540549e+13, -2.467682355312315e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
