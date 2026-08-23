
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_blyp_ea_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp_ea", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.207649663341161e+00, -4.125457041926043e+00, -4.010333322242201e+00, -3.850955616123330e+00, -3.633976691683346e+00, -3.345564094459144e+00, -2.974991631828102e+00, -2.520874338436524e+00, -1.998593349700770e+00, -1.441457298705596e+00, -8.966808718085413e-01, -5.425174432591123e-01, -4.489841272263276e-01, -3.471702919464268e-01, -2.044286773663657e-01, -6.503227581485445e-02, 4.262100951079970e-03, -3.515426585849529e-03, -9.133250130789075e-04, -1.023995112699315e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_blyp_ea_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp_ea", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.292479807929387e+00, -5.179313948541368e+00, -5.020757160504732e+00, -4.801160113972677e+00, -4.502057036873918e+00, -4.104357872778660e+00, -3.593713588906291e+00, -2.970921720601033e+00, -2.269042143944698e+00, -1.575048910509561e+00, -1.015983800705216e+00, -7.165791049996624e-01, -6.170955528271207e-01, -4.744489857029097e-01, -3.019339774893544e-01, -1.538419533609833e-01, -4.821706494066223e-02, -5.045259824926917e-03, -1.213804996257977e-03, -1.364638625433159e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blyp_ea_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp_ea", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.828027188187851e-06, -4.120396021681262e-06, -4.578573448151520e-06, -5.323532233593219e-06, -6.599632682479437e-06, -8.951729283446520e-06, -1.375006311252266e-05, -2.497569460488446e-05, -5.628112405141835e-05, -1.633210032123885e-04, -6.454534162574639e-04, -3.834944257790756e-03, -7.127764610165719e-03, -1.031460229068174e-02, -8.711421254893444e-03, 2.302624058421401e-01, 4.207153688612477e+00, 5.242563837996482e+00, -4.140628414236974e-05, -9.341264890886316e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blyp_ea_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp_ea", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.175395394962741e-02, -1.226858380018914e-02, -1.304647936788323e-02, -1.424743995053393e-02, -1.615736480551873e-02, -1.932135807720736e-02, -2.485331556622615e-02, -3.516292558412651e-02, -5.531826856768821e-02, -9.164420489124991e-02, -1.565290258759015e-01, -4.643308783319485e-01, -6.116327130469434e-01, -8.746856798734939e-01, -1.221624867977282e+00, 3.965456271732730e-01, 1.041879028676335e+01, -9.090383646922835e+01, -1.395654769647408e+03, -1.175252112576516e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blyp_ea_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp_ea", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.866829548769123e-08, 2.111259825927992e-08, 2.517274310689449e-08, 3.234301060041646e-08, 4.614119065593049e-08, 7.602294913335126e-08, 1.516591610586155e-07, 3.815841893619834e-07, 1.151134300463517e-06, 3.456775088532223e-07, -1.586226892039031e-04, 2.326477665585905e-03, 1.047815472086405e-02, -3.527573602316151e-03, -6.581177207918467e-01, -4.023020847157007e+01, -3.525691548101023e+03, 1.635804972492951e+05, -5.254726268969671e+02, -9.204074104020491e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blyp_ea_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blyp_ea", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.941931376641444e-14, 1.238692796562571e-13, 1.698040779227114e-13, 2.668032505290992e-13, 5.090531358857026e-13, 1.278459432421769e-12, 4.722225930378816e-12, 2.977935249204041e-11, 3.890579211390751e-10, 1.336993799411903e-08, 1.599216599752767e-06, 3.511953355484621e-04, 2.890891590963875e-03, 1.729354142810723e-02, 5.338848785378207e-01, 5.479746020229896e+01, 5.521027380745888e+03, 5.460173571510648e+05, 1.430797657081203e+08, 1.946062892673536e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
