
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_lp_b_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_b", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.543691699648190e+00, -4.461847427600239e+00, -4.346529359753587e+00, -4.185547111211792e+00, -3.963835167015312e+00, -3.664449998217833e+00, -3.271683192995885e+00, -2.777791068035389e+00, -2.194663989391378e+00, -1.569500127812643e+00, -9.829847233064163e-01, -5.440822786575309e-01, -4.516664176162890e-01, -3.741331998972001e-01, -2.420777808455968e-01, -1.164168743009247e-01, -3.727963640367665e-02, -6.487048744471787e-03, -4.671400907751041e-04, -1.124352102670205e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_lp_b_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_b", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.891138157819657e+00, -5.891359381628971e+00, -5.787853594182853e+00, -5.788317181745548e+00, -5.642056434851937e+00, -5.643033402318578e+00, -5.437975013006817e+00, -5.440050827830504e+00, -5.155781656825503e+00, -5.160245435523470e+00, -4.772425517865831e+00, -4.782195391053800e+00, -4.264697553440818e+00, -4.286650781734370e+00, -3.615761149912489e+00, -3.667078364615830e+00, -2.824563956578114e+00, -2.951773941808169e+00, -1.911602870206475e+00, -2.252182372421360e+00, -9.438168992209466e-01, -1.866982182305875e+00, -3.445596586889917e-01, -1.955577830326958e+00, -2.738749331889718e-01, -1.770531336496752e+00, -2.323966584586052e-01, -1.403708915617109e+00, -1.443519938775964e-01, -9.903149386892980e-01, -6.280442989996393e-02, -5.988532254095082e-01, -1.736453713522693e-02, -2.923080144072147e-01, -2.574181996791795e-03, -1.039691001823316e-01, -1.652122151348302e-04, -2.307458675917241e-02, -3.796099855254296e-06, -2.620015038137164e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_lp_b_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_lp_b", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.126239938140198e-02, -6.022259933216827e-02, 4.126413724142439e-02, 4.304371165700791e-02, -6.290390698712427e-02, 4.304757971916494e-02, 4.573518802203645e-02, -6.696087611727378e-02, 4.574407724386986e-02, 4.988948943478998e-02, -7.323566334110442e-02, 4.991087962616351e-02, 5.649955429499406e-02, -8.325045109181237e-02, 5.655454696171575e-02, 6.748068241504208e-02, -9.996759126749405e-02, 6.763618398855621e-02, 8.686338527924790e-02, -1.297124285779448e-01, 8.736761396155086e-02, 1.240370771923919e-01, -1.876436034643102e-01, 1.260274052107575e-01, 2.031228447260920e-01, -3.155270792579991e-01, 2.135115006659064e-01, 3.837382797370621e-01, -6.451528378398402e-01, 4.622456537938167e-01, 6.605743457016857e-01, -1.527141896804944e+00, 1.436347854785293e+00, 5.569798326484960e-01, -2.588925043085843e+00, 4.057170040769640e+00, 6.550701708677905e-01, -3.347309435506968e+00, 5.547381172979405e+00, 1.075932259226690e+00, -5.255060706805628e+00, 8.435215098882269e+00, 2.089633938635746e+00, -1.123000133556790e+01, 1.899961926663550e+01, 4.999858504748281e+00, -3.442995642831234e+01, 6.654844051964997e+01, 1.518422921291570e+01, -1.639691081670449e+02, 3.888833787207313e+02, 6.191938982241118e+01, -1.416262604967893e+03, 4.263875287256914e+03, 4.079077481937907e+02, -2.966279077084364e+04, 1.073628171316129e+05, 6.638490708492004e+03, -2.310610013554002e+06, 9.041870035774268e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
