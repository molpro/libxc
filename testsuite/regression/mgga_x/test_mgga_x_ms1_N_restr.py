
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ms1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.722326683435604e+00, -4.628358813900347e+00, -4.496703339879486e+00, -4.314362450197966e+00, -4.065975335333502e+00, -3.735560083501805e+00, -3.310674434040160e+00, -2.789956397300654e+00, -2.192844221122716e+00, -1.548275907484043e+00, -9.619119852325114e-01, -6.045949956719789e-01, -5.599534938340646e-01, -4.822129499397800e-01, -3.371765560132098e-01, -2.001135425506892e-01, -9.749101322381781e-02, -3.275455361359295e-02, -6.826618847445890e-03, -7.550505508777706e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ms1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.196915959647015e+00, -6.069898418952564e+00, -5.891826819081277e+00, -5.644958346368858e+00, -5.308130495419392e+00, -4.858802554256768e+00, -4.277771988078499e+00, -3.555879482755808e+00, -2.688153321757791e+00, -1.598980616912215e+00, -1.055344363678224e+00, -8.082024084593576e-01, -7.698472414283128e-01, -6.237574960142679e-01, -3.693144868461644e-01, -2.174243435831838e-01, -1.151112452850404e-01, -4.306829427630722e-02, -9.096261896181889e-03, -1.006725690587520e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.096364252473863e-06, -1.190763703497160e-06, -1.341322755029205e-06, -1.592922617030980e-06, -2.043499230999189e-06, -2.940001270434036e-06, -5.050864047865847e-06, -1.171503275118194e-05, -4.818050595501304e-05, -4.622960172014796e-04, -1.091684175548890e-03, -6.564001515290492e-03, -1.468245216278861e-02, -6.127373670053386e-02, -2.188361747528194e-01, -3.297078151401861e-01, -1.342591501230058e+00, -1.366465684414890e+00, -1.605444974635798e+00, -1.771243214144305e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms1_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.491964428471410e-05, 7.178494435690482e-05, 8.300105316753109e-05, 1.023893678668498e-04, 1.387577451830755e-04, 2.155398013824896e-04, 4.077694846398132e-04, 1.021112038339269e-03, 3.743370067405080e-03, 1.789635179146875e-02, 5.742768411913807e-03, 7.307371407559199e-03, 2.499571943977311e-02, 8.517697693939313e-02, 9.430590579469461e-02, 8.311906358824462e-03, 3.798828061885146e-03, 1.711414190263829e-06, 1.076551899382855e-11, 2.714349137131136e-19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.106621270642227e-02, -1.145740257293894e-02, -1.203188201320292e-02, -1.287770900677701e-02, -1.411493106559379e-02, -1.584982184915047e-02, -1.782112879851857e-02, -1.716364009802665e-02, 4.561130224067766e-03, -5.355951379227478e-02, -2.711512268075266e-01, -9.802469670581142e-01, -1.609388683641467e+00, -1.756902544909468e+00, -4.223451319405850e+00, -2.299709439093125e+01, -2.656644060745437e+01, -3.735190001402446e+02, -1.053344356328939e+04, -8.690995337017395e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.553307560374162e-08, -3.084826486280639e-08, -4.042577096387880e-08, -5.945453632249693e-08, -1.029179295003966e-07, -2.239752765461398e-07, -6.704046366769040e-07, -3.107021654657709e-06, -2.542465766480881e-05, -1.639858838006687e-04, -3.878995337076405e-04, 3.985577666954465e-03, -1.113144381018562e-01, 2.639928890410083e-01, 2.168151240152211e+00, 3.953079870693078e+02, 3.829696302003646e+03, -1.583937020863725e+05, -2.246403091246133e+07, -1.835086612710270e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms1_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.665883483801688e-05, 5.244730750841568e-05, 6.202418793034337e-05, 7.886424728519984e-05, 1.111717392111565e-04, 1.813456340324882e-04, 3.630200229838254e-04, 9.633116694139862e-04, 3.673393072334920e-03, 9.705813470514179e-03, 6.219187602250445e-03, 4.317600718067279e-02, 5.117191193030457e-01, 4.260444668388184e-02, 5.274798483046313e-02, -3.893701816837527e+01, -5.318290216774680e+01, -1.950486525802502e+00, -2.823724255511259e-03, -1.123041106730649e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.569385289051055e-13, 1.218943215607090e-12, 1.725487222687744e-12, 2.841051263771006e-12, 5.805785498050050e-12, 1.614041431012452e-11, 6.943960319857173e-11, 5.530258910637503e-10, 1.034180400858537e-08, 2.843028794041092e-07, 3.910589132766509e-07, 2.261741289254009e-04, -2.524528616877814e-02, 8.016412608212838e-02, -3.061095810350534e+00, -8.142056346874004e+03, -1.354242283633759e+06, 4.476470357239211e+08, 8.156124731825615e+12, 5.173365997255339e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms1_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.354429176687757e-09, -1.622746512738460e-09, -2.103545992112774e-09, -3.052266415131379e-09, -5.202680953115998e-09, -1.115195284961372e-08, -3.306397278382396e-08, -1.546127374262044e-07, -1.349371426178805e-06, -1.146810259443993e-05, 3.606189367594410e-05, 6.383410336347534e-04, 9.035513272391893e-02, -5.684935118226833e-02, 3.372597803141420e+00, 7.937119591263959e+02, 1.385107897523050e+04, 1.425246427427677e+04, 2.269084904085983e+03, 6.649126320717376e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ms1_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ms1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.939300935065526e-06, 2.185392564407710e-06, 2.594155937163647e-06, 3.317091127034984e-06, 4.715904383261720e-06, 7.793343648070698e-06, 1.592107702808952e-05, 4.369861447988268e-05, 1.778436054666950e-04, 4.656068051954508e-04, -6.586283926685045e-04, -4.797174050562852e-03, -3.087225803131766e-01, -1.316032947263849e-02, -2.544665521626851e+00, -7.474962269874213e+01, -1.174904530728284e+02, -3.829489841538353e+00, -5.309585277888897e-03, -2.078160683966780e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
