
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_cqtp25_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cqtp25", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.103550685021565e+00, -2.062585401308571e+00, -2.005193468691103e+00, -1.925711461820534e+00, -1.817444016531945e+00, -1.673407031674417e+00, -1.488070592133067e+00, -1.260376904134037e+00, -9.973039344468496e-01, -7.146760134474394e-01, -4.402577221419507e-01, -2.731190679287072e-01, -2.276697534587649e-01, -1.752812761153303e-01, -1.030509919093255e-01, -3.661520930192389e-02, -5.091335517884861e-03, -6.804560598311277e-03, -1.913417035007900e-03, -2.431312754375819e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_cqtp25_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cqtp25", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.648815255268574e+00, -2.592675416151222e+00, -2.514017457635751e+00, -2.405078039173917e+00, -2.256698031844265e+00, -2.059414091936735e+00, -1.806132641678327e+00, -1.497323269926716e+00, -1.149554123522168e+00, -8.059702669907192e-01, -5.261130946901199e-01, -3.662000835844661e-01, -3.144426990744586e-01, -2.441591648610024e-01, -1.582526942888923e-01, -8.467115954216500e-02, -3.582853449060926e-02, -8.772866583190325e-03, -2.485004703757694e-03, -3.213995638896555e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cqtp25_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cqtp25", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.842521667985945e-06, -1.981976156871667e-06, -2.200275964997131e-06, -2.554621696371238e-06, -3.160055961994433e-06, -4.271468152149359e-06, -6.523561063537223e-06, -1.172932384385113e-05, -2.590014782541228e-05, -7.161357303856355e-05, -2.510083774916986e-04, -1.434407188511969e-03, -2.554640852689258e-03, -2.902176399375123e-03, 4.433737000392835e-03, 1.600397919684741e-01, 2.493814073503534e+00, 3.093125521941198e+00, -5.578657117462990e-06, -1.258556500976498e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cqtp25_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cqtp25", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.802454750765019e-03, -6.055176111228564e-03, -6.436951639781040e-03, -7.025813909107502e-03, -7.960920107718253e-03, -9.506216548353446e-03, -1.219617071086670e-02, -1.716550119453737e-02, -2.667704115631686e-02, -4.261346908184287e-02, -6.733178123265349e-02, -2.240592667346516e-01, -3.004832882693060e-01, -4.171780405513948e-01, -5.597266402650657e-01, 5.094405664568962e-01, 7.643351544129379e+00, -9.074330800692366e+01, -2.562315220187604e+03, -2.667539886736757e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cqtp25_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cqtp25", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.859843891637321e-09, 1.000734322207330e-08, 1.190927633467305e-08, 1.525680464332275e-08, 2.166371595823597e-08, 3.540994810080298e-08, 6.959187640568603e-08, 1.692873830939343e-07, 4.531100804360662e-07, -1.201389242756393e-06, -1.125415409399229e-04, 3.281487973024061e-04, 2.282593345078109e-03, -1.168688402850387e-02, -4.005532663534451e-01, -2.116571136472048e+01, -2.044750599370257e+03, 9.658968867442614e+04, -7.078962236301341e+01, -1.240072731623053e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_cqtp25_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_cqtp25", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.812647230330922e-14, 5.993504411551297e-14, 8.210624199962214e-14, 1.288807184402170e-13, 2.455310669349166e-13, 6.152002000801893e-13, 2.263852353572766e-12, 1.418609471715472e-11, 1.832023791328320e-10, 6.150312281530702e-09, 7.025375572954334e-07, 1.473452144225750e-04, 1.176943445079992e-03, 6.659899409916273e-03, 1.749480457699321e-01, 1.181839243345551e+01, 8.100052897999668e+02, 7.391979246837170e+04, 1.927856170718487e+07, 2.621947038640701e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
