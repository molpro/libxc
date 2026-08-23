
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_golden_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_golden", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.827155393733963e+01, 9.460954003370114e+01, 8.960168822833920e+01, 8.290284785615026e+01, 7.422066105553679e+01, 6.346381003164392e+01, 5.096222696388299e+01, 3.768200086215335e+01, 2.520830747716822e+01, 1.507816484408186e+01, 7.103203952802968e+00, 2.358661178922198e+00, 1.676290978376363e+00, 1.196593536821996e+00, 6.881407642907369e-01, 3.647160152056357e-01, 2.317803121959811e-01, 1.896214775062771e-01, 1.742627370563413e-01, 1.658908164124272e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_golden_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_golden", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.449933771452167e+02, 1.389267483030471e+02, 1.306343957171058e+02, 1.195493388680875e+02, 1.051960450302225e+02, 8.743823370293038e+01, 6.684776994865280e+01, 4.507796837633508e+01, 2.493912034869790e+01, 9.906861965982278e+00, 3.399581677967460e+00, 3.204479582459008e+00, 2.557420974168881e+00, 1.539262048497918e+00, 5.748893534112665e-01, 2.856613774784340e-02, -1.561331102343843e-01, -1.818743488343137e-01, -1.739306700133562e-01, -1.658867567617857e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_golden_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_golden", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.016404107273429e-04, 2.143706238462423e-04, 2.340798970893392e-04, 2.655908593158773e-04, 3.183482840927921e-04, 4.127187025996729e-04, 5.983063542184317e-04, 1.016169957953200e-03, 2.154387592104445e-03, 6.126001551198661e-03, 2.247708977345872e-02, 5.830647131863159e-02, 8.782433539805612e-02, 1.690663118127299e-01, 5.389844951397564e-01, 3.101990576301381e+00, 3.677117677588338e+01, 1.121981454205429e+03, 1.264323382432023e+05, 9.353277941950846e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_golden_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_golden", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.446866926774549e-01, 6.611604636138340e-01, 6.857620051552186e-01, 7.231382895565067e-01, 7.813949541008758e-01, 8.757794983382817e-01, 1.038089312884196e+00, 1.344458851650812e+00, 2.010588856583911e+00, 3.702967886300811e+00, 6.663545188281376e+00, 4.622622969509520e+00, 4.721463767620391e+00, 6.934900823948065e+00, 1.425811905435741e+01, 5.139799680807904e+01, 4.463572833381816e+02, 1.170294047809073e+04, 1.219870965004277e+06, 8.593568780764283e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_golden_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_golden", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.125937529675766e-06, -1.272593474812443e-06, -1.517355643052926e-06, -1.953373972213278e-06, -2.806494368810540e-06, -4.717017068553894e-06, -9.913029050718042e-06, -2.859511523390607e-05, -1.285306863788378e-04, -1.039234015531064e-03, -1.399069563740647e-02, -9.414400424207285e-02, -2.135939230553609e-01, -7.915408003373323e-01, -8.044734073875459e+00, -2.664649532897329e+02, -3.744330761030581e+04, -3.486025062224109e+07, -4.426653088701284e+11, -2.422628536413718e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_golden_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_golden", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
