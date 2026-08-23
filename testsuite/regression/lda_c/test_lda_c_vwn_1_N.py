
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vwn_1_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_1", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.185824110968397e-01, -1.179948578849888e-01, -1.171517400512745e-01, -1.159432734760443e-01, -1.142140692872714e-01, -1.117459450849090e-01, -1.082362948805082e-01, -1.032741219064341e-01, -9.632705223359191e-02, -8.679883936371582e-02, -7.403937417521621e-02, -5.962168232319029e-02, -5.569964764904094e-02, -5.173106420712635e-02, -4.339796344205508e-02, -3.172069556157223e-02, -1.886378498434548e-02, -8.217149411571031e-03, -2.289371586694853e-03, -3.206984741299139e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vwn_1_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_1", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.281833006155152e-01, -1.281856934157441e-01, -1.275848893769095e-01, -1.275899698057089e-01, -1.267250099023250e-01, -1.267359203897113e-01, -1.254898361402160e-01, -1.255136565406511e-01, -1.237160812123992e-01, -1.237693460561839e-01, -1.211685714671773e-01, -1.212918958057196e-01, -1.175036016889167e-01, -1.178040299301422e-01, -1.121959567487622e-01, -1.129843416656180e-01, -1.043433638492694e-01, -1.066465563110423e-01, -9.201910301384074e-02, -9.975888508638760e-02, -7.153040176584706e-02, -9.942140550222255e-02, -5.220788413859199e-02, -1.144238409012038e-01, -4.881459678817216e-02, -1.121053515934221e-01, -4.579708771332978e-02, -1.018206100911050e-01, -3.891827786095027e-02, -8.955915394154708e-02, -2.922735483349606e-02, -7.341642579435582e-02, -1.850151944299112e-02, -5.204529684031119e-02, -8.985311952101319e-03, -2.742799357072668e-02, -2.799252401137267e-03, -8.330553547086247e-03, -4.166910297030472e-04, -1.107873917580443e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vwn_1_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_1", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.943531225145693e-04, -6.033257230986903e-04, 4.943776379993979e-04, 5.226468108765791e-04, -6.384204391447099e-04, 5.227021284426958e-04, 5.661187744820706e-04, -6.924227739919242e-04, 5.662484252925762e-04, 6.348509003360834e-04, -7.779977334661208e-04, 6.351718184057910e-04, 7.480538521828147e-04, -9.194368351716204e-04, 7.489130359222750e-04, 9.456529569015462e-04, -1.167727831284343e-03, 9.482276591578248e-04, 1.319994682272910e-03, -1.642746779132291e-03, 1.329064995932217e-03, 2.113920999097637e-03, -2.669608373196409e-03, 2.154198454167971e-03, 4.059711350025978e-03, -5.301416011208701e-03, 4.307790428803572e-03, 9.449740484262736e-03, -1.367432224416877e-02, 1.180223526650683e-02, 2.012350466372888e-02, -4.351213691380301e-02, 5.146960264127932e-02, 1.740323527285021e-02, -9.586032489913686e-02, 2.203190943276194e-01, 2.110030554616690e-02, -1.365967722117301e-01, 3.380211472727079e-01, 3.916830959486404e-02, -2.451474397292369e-01, 5.689373435753218e-01, 8.473416079719988e-02, -6.710933383310721e-01, 1.627490245026065e+00, 1.783813088002416e-01, -2.969115373696306e+00, 8.316518669406454e+00, -6.224011654397299e-01, -2.289428687274895e+01, 8.230444780698146e+01, -4.127060996698628e+01, -3.421683906061937e+02, 1.815812407516002e+03, -2.392300795101795e+03, -1.124302629929435e+04, 1.104228212782455e+05, -3.264166563486353e+05, -1.060509921555034e+06, 2.599605286822507e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
