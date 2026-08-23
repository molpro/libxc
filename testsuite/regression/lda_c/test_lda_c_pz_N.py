
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pz_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.183926489241093e-01, -1.177897469177005e-01, -1.169245335025026e-01, -1.156842684934895e-01, -1.139093546174540e-01, -1.113757345926450e-01, -1.077730121334006e-01, -1.026813773675340e-01, -9.556470308305970e-02, -8.585666757689848e-02, -7.308427276525235e-02, -5.901732352793859e-02, -5.523262229742755e-02, -5.154600502321055e-02, -4.358727441129193e-02, -3.200331716665360e-02, -1.895555528143173e-02, -8.176851955595355e-03, -2.273899605821963e-03, -3.222098122603434e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pz_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.282440466536567e-01, -1.282463976821934e-01, -1.276307542700550e-01, -1.276357448565335e-01, -1.267493746524174e-01, -1.267600886137839e-01, -1.254830971047746e-01, -1.255064770671277e-01, -1.236642928588879e-01, -1.237165357761974e-01, -1.210515345480781e-01, -1.211723673196012e-01, -1.172924433166365e-01, -1.175863539611017e-01, -1.118513694171077e-01, -1.126209372343163e-01, -1.038215177340534e-01, -1.060626599472121e-01, -9.132067035879016e-02, -9.882255478128495e-02, -7.088020672592366e-02, -9.785288749985212e-02, -5.183222257061739e-02, -1.121592871460759e-01, -4.841318962778680e-02, -1.099731575052682e-01, -4.537417428094023e-02, -1.003934475792077e-01, -3.895609738502495e-02, -8.943449570527973e-02, -2.948079027658051e-02, -7.403715203705434e-02, -1.863254343982125e-02, -5.244546634086893e-02, -8.955091877431773e-03, -2.735057281383060e-02, -2.776981182594222e-03, -8.310944750782144e-03, -4.179757348131114e-04, -1.129371905844807e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pz_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.834162446115600e-04, -5.951002053157546e-04, 4.834402334960599e-04, 5.109317953522912e-04, -6.296032493954398e-04, 5.109859104687033e-04, 5.531904409758211e-04, -6.826817934870123e-04, 5.533172254350695e-04, 6.199635846820516e-04, -7.667622110879345e-04, 6.202772356755040e-04, 7.298428885562556e-04, -9.056575429939011e-04, 7.306819496794683e-04, 9.213938485759537e-04, -1.149295114710791e-03, 9.239053625665986e-04, 1.283598687860628e-03, -1.614888227898843e-03, 1.292431791229497e-03, 2.049707496083516e-03, -2.619740612752089e-03, 2.088840449552052e-03, 3.920186715111825e-03, -5.189292060843988e-03, 4.160483691569032e-03, 9.075873345538469e-03, -1.334147751239345e-02, 1.134795480236530e-02, 1.919390075854836e-02, -4.234171545763867e-02, 4.951750584888186e-02, 1.618745648924721e-02, -9.306833224621242e-02, 2.140808609189508e-01, 1.948952029387973e-02, -1.324791533720250e-01, 3.305755051764463e-01, 3.954507423883593e-02, -2.356750186796636e-01, 5.678160534754710e-01, 8.642635975643008e-02, -6.592985973157365e-01, 1.639587660673091e+00, 1.821027733171049e-01, -2.979148141542552e+00, 8.412696991161782e+00, -6.593462956349621e-01, -2.319836229169766e+01, 8.275602924481052e+01, -4.176782501757196e+01, -3.431985514127651e+02, 1.807956249388073e+03, -2.366473584527949e+03, -1.115742101887532e+04, 1.106310271394442e+05, -3.252520823848645e+05, -1.073443165212973e+06, 2.678174505246485e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
