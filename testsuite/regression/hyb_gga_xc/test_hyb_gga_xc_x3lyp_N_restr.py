
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_x3lyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_x3lyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.440274633556235e+00, -3.375959725903857e+00, -3.285885914666067e+00, -3.161208379667169e+00, -2.991519274697040e+00, -2.766081998297604e+00, -2.476718716826177e+00, -2.122894018054947e+00, -1.718025685419811e+00, -1.290721814495887e+00, -8.709718612326667e-01, -5.667797454255895e-01, -4.871447602854392e-01, -4.089985132897050e-01, -2.985324003685483e-01, -1.851028028314206e-01, -9.925117799341047e-02, -5.885468789660256e-02, -3.389180361662500e-02, -2.230799875654183e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_x3lyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_x3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.297350464997895e+00, -4.208543149875303e+00, -4.084086389199185e+00, -3.911655972917725e+00, -3.676665541819748e+00, -3.363928871828228e+00, -2.961751100786837e+00, -2.469869363944073e+00, -1.912624256277785e+00, -1.356878343365093e+00, -9.084099663188223e-01, -6.905263078646635e-01, -6.160466998931314e-01, -4.940841117719244e-01, -3.433295378852395e-01, -2.126274034629128e-01, -1.189484455014767e-01, -3.990430086137090e-02, -1.152428084330331e-02, -3.993221909004491e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_x3lyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_x3lyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.880397953129472e-06, -3.104288176761457e-06, -3.455877840261241e-06, -4.029300020745475e-06, -5.016166084180209e-06, -6.848403769227169e-06, -1.063011199986087e-05, -1.965425877239802e-05, -4.575352547016875e-05, -1.420287485628236e-04, -6.551142789620015e-04, -4.422276399582270e-03, -8.859847100203410e-03, -1.624401417308549e-02, -4.730565783124309e-02, -1.631226544011902e-01, -7.487999202488504e-02, -8.177739859368857e+01, -9.138657078494007e+03, -5.443088754649423e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_x3lyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_x3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.202130106526612e-03, -9.608368882783345e-03, -1.022308613207542e-02, -1.117370943267452e-02, -1.268955185571093e-02, -1.521183955705727e-02, -1.965605895666394e-02, -2.805904110075217e-02, -4.497603561514901e-02, -7.759248813529902e-02, -1.452327899052186e-01, -4.046306677629458e-01, -5.192410001268382e-01, -8.170401563087761e-01, -1.444600486908364e+00, 6.604854928003956e-02, 4.532714679455603e+01, -6.217904839781500e+02, 6.335567702722350e+03, 5.326808827821743e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_x3lyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_x3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.435311621560693e-08, 1.626462418580797e-08, 1.944978380157619e-08, 2.510187531110958e-08, 3.606043789291755e-08, 6.008452353350566e-08, 1.222076100295794e-07, 3.192978997656719e-07, 1.062563096186592e-06, 2.174078305149982e-06, -7.241094628625420e-05, 4.566790745943790e-03, 1.906366565951786e-02, 3.792243207866644e-02, -1.181388908581553e-01, -3.244610608607213e+01, -6.693788547993687e+03, 5.945188119464932e+05, -5.257523558733628e+09, -1.849571751014380e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_x3lyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_x3lyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.509364198469959e-14, 9.368003262553716e-14, 1.286611878178629e-13, 2.027268330223160e-13, 3.884516955408219e-13, 9.820701256010963e-13, 3.666432554264697e-12, 2.354494650175795e-11, 3.180335769046252e-10, 1.168042437595733e-08, 1.565880648170932e-06, 3.718533077103041e-04, 3.264049142681013e-03, 2.201373734569073e-02, 9.484943094572192e-01, 2.774510382146057e+02, 5.966397078109389e+05, 7.042300668160617e+09, 1.304684123034166e+16, 4.365576792139203e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
