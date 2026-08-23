
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_op_g96_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_g96", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.864883716632895e-02, -5.835597801307585e-02, -5.792542060579060e-02, -5.728649931399186e-02, -5.632595786323550e-02, -5.485609164687243e-02, -5.255528791100549e-02, -4.886578170903789e-02, -4.290796293054384e-02, -3.416561144213823e-02, -2.815698118808909e-02, -3.995926358472488e-02, -4.110699122145740e-02, -3.391932663464747e-02, -2.337762830323923e-02, -1.086033402203533e-02, -1.977085819511672e-03, -5.480979654721206e-05, -1.116105312596447e-07, -9.589276280224255e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_op_g96_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_g96", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.425511526353444e-02, -7.430420165014322e-02, -7.437272467197177e-02, -7.446629688199861e-02, -7.458828501984055e-02, -7.472975768818901e-02, -7.483430654223953e-02, -7.467372892527188e-02, -7.342674079774344e-02, -6.882816167653572e-02, -6.157740101102046e-02, -5.724278719147265e-02, -5.329173701560062e-02, -5.114769482765644e-02, -4.365967404918642e-02, -2.778157221875120e-02, -7.592753931359856e-03, -2.894866991214092e-04, -6.783408078451676e-07, -6.299498374458479e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_g96_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_g96", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.530633971079937e-07, 1.667531559883006e-07, 1.885423031134665e-07, 2.247711085208189e-07, 2.888645345271783e-07, 4.126265385623207e-07, 6.826332632046821e-07, 1.378612334253787e-06, 3.614160936563247e-06, 1.317833601794957e-05, 8.320254548325172e-05, 1.031704403206056e-03, 2.634334517410343e-03, 4.651912296612624e-03, 1.545694723472814e-02, 7.890209848107456e-02, 3.500819970191952e-01, 5.013249389384363e-01, 1.491386013300185e-01, 1.111844439320437e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_g96_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_g96", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.369200998093112e-05, 4.667756422000972e-05, 5.123867828290467e-05, 5.835286578702087e-05, 6.969277350718534e-05, 8.790995821271860e-05, 1.150312661618032e-04, 1.320317617180460e-04, -9.259474456128620e-05, -2.615216700633387e-03, -1.438474423645012e-02, -2.853424818300919e-04, -3.303474711462723e-03, -1.128404548238199e-02, -1.440739731085384e-01, -1.890455895109039e+00, -1.707715591693960e+01, -3.590260677512423e+01, -1.172395088165729e+01, -8.949895935156055e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_g96_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_g96", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.516379799467427e-10, -6.294265697165139e-10, -7.597636101575811e-10, -9.925401578867163e-10, -1.446369181366661e-09, -2.439310458813530e-09, -4.921177407207397e-09, -1.149007778178069e-08, -1.120951638523554e-08, 7.886249067076358e-07, 3.020968323868271e-05, -7.136305604648949e-04, -3.927361127583071e-03, -7.193670729179422e-03, 3.544570686791058e-02, 7.450079784185756e+00, 1.029476247679484e+03, 7.595619770506381e+04, 3.066664499722457e+06, 1.857072248141859e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_op_g96_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_op_g96", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.088560027366100e-15, -1.131535573694038e-14, -1.550357742069517e-14, -2.436912509673506e-14, -4.662476324945982e-14, -1.180856413029475e-13, -4.453511674566417e-13, -2.942825519632430e-12, -4.237407852738472e-11, -1.751212974133433e-09, -2.966154541699069e-07, -1.468473781384099e-04, -2.139050319113024e-03, -9.422729685700359e-03, -3.519245075305864e-01, -9.177082692531606e+01, -1.037274572045792e+05, -2.206329934727531e+08, -1.042660734828900e+12, -4.874676425361296e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
