
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mcml_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.491712116800808e+00, -4.407199862592421e+00, -4.288793816309424e+00, -4.124793887654669e+00, -3.901332667532403e+00, -3.603831044029835e+00, -3.220407035036692e+00, -2.748042313031682e+00, -2.204849226871104e+00, -1.612378702921210e+00, -9.858970377089735e-01, -6.395614336537531e-01, -5.593555633228935e-01, -4.800004056799411e-01, -3.432739512413434e-01, -2.010046928207671e-01, -7.546360694580076e-02, -1.592550288860380e-02, -2.969359342726279e-03, -3.266046231212470e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mcml_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.563277164376261e+00, -5.449074109471105e+00, -5.289452693306032e+00, -5.069229801297865e+00, -4.771165860234412e+00, -4.379180404767171e+00, -3.886198020316648e+00, -3.311779134150320e+00, -2.737089173159624e+00, -1.265554040110339e+00, -1.122504248982988e+00, -8.078973875701861e-01, -7.608680205228515e-01, -6.066734869835838e-01, -3.310759139767572e-01, -2.347066231914241e-01, -1.130367477546495e-01, -2.477828082298266e-02, -3.998880026651172e-03, -4.355317118871006e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mcml_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.487393466031828e-06, -4.789055395225810e-06, -5.251516840615362e-06, -5.977283348709685e-06, -7.147605163549470e-06, -9.072606281353837e-06, -1.209526483887978e-05, -1.429066741889736e-05, 1.778806135885887e-05, -8.640087207113077e-04, -7.652845729302054e-04, -5.028126381689787e-03, -1.360415999204891e-02, -6.758778926509507e-02, -3.177995528020277e-01, -3.612340672676548e-01, -2.941927632393781e+00, 4.870887673397116e+00, 9.797634583781619e+00, 1.233575344981111e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mcml_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.819634296844590e-04, -2.001332915954642e-04, -2.296322843807147e-04, -2.801851814681134e-04, -3.739394288466336e-04, -5.692900081363890e-04, -1.053765400734266e-03, -2.610680340051587e-03, -8.798884439125696e-03, 3.306776603934163e-02, 2.996119313245854e-03, 1.551600576859264e-03, 2.058131454837920e-02, 8.684917513761277e-02, 1.307020224548977e-01, 2.331396275156250e-02, 4.302200918853719e-02, 1.205553157352083e-03, 3.604094174170660e-06, 5.524149737745986e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mcml_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.440385935772544e-02, -1.517042919986233e-02, -1.635805858438592e-02, -1.826440914206373e-02, -2.149667474159698e-02, -2.747883303924862e-02, -4.026202367568528e-02, -7.368107985697281e-02, -1.085614474049583e-01, 4.446743333397588e-02, -4.081801501429008e-02, -6.126607944327177e-01, -1.634790944768019e+00, -1.944398859405376e+00, -8.360236948723108e+00, -6.632144553932463e+01, -6.320297528617664e+02, -1.719608605856726e+03, -5.846920239048485e+03, -3.767762125626205e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mcml_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.010802295693518e-07, 1.186882855188494e-07, 1.495757312380429e-07, 2.087623873324663e-07, 3.377452617147195e-07, 6.770365849500654e-07, 1.852056370315889e-06, 7.755616130267321e-06, 2.884399626243114e-05, -4.132347783879827e-04, -3.764750380886774e-04, 5.244073741759862e-03, -1.058887431449589e-01, 4.610105751640755e-01, 1.487555869719298e+01, 1.349688777334664e+03, 1.125420632581758e+05, 7.327128761022060e+06, 6.078281684473716e+08, 2.065922220416057e+11]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_mcml_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.311132554802324e-04, -1.466050430649223e-04, -1.720646019393848e-04, -2.164125723616260e-04, -3.003956429772589e-04, -4.797017066053316e-04, -9.335004447445244e-04, -2.348761534374097e-03, -4.466768965679817e-03, 2.385191577764605e-02, -1.594880352911397e-03, 9.799874811357561e-03, 5.189184221389652e-01, -1.421703884816384e-01, -5.630148832343386e+00, -1.313454001876400e+02, -8.220390647720808e+02, -1.559491025013984e+03, -1.011865223761933e+03, -2.361840864269326e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mcml_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.396185003471987e-12, -3.039943291619051e-12, -4.278663344226509e-12, -6.988865609864812e-12, -1.412887042720292e-11, -3.875305484945984e-11, -1.642896021126671e-10, -1.270735205866264e-09, -1.243879144453791e-08, 7.888750825590584e-07, -4.257668929115496e-07, 3.391778515760794e-04, -2.372893011492805e-02, -4.894055940722603e-01, -3.791104742733335e+01, -2.721454914759603e+04, -2.275750425314619e+07, -4.385322627285572e+10, -3.981068689461914e+14, -8.088679802484464e+19]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_mcml_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.799223247982441e-09, 4.527566681843265e-09, 5.823946691667139e-09, 8.357678359244371e-09, 1.402483064176488e-08, 2.942669421467855e-08, 8.488461087012028e-08, 3.788347612043867e-07, 1.749213104011536e-06, -3.539587682538761e-05, 3.682798703035176e-05, 1.179494234718197e-04, 8.517628923323556e-02, 7.470739626443594e-01, 1.965834128944827e+01, 2.575675836081512e+03, 1.750900483812688e+05, 1.040355413390267e+07, 7.773967788102937e+08, 1.369316294739221e+11]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_mcml_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mcml", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.434116171194225e-06, -6.090701128529046e-06, -7.173883761589066e-06, -9.071333931690674e-06, -1.269507480514090e-05, -2.053480329841699e-05, -4.083469994447708e-05, -1.073382683424261e-04, -2.360877900363939e-04, 1.629760428771019e-03, -4.040986512227136e-04, -1.054575354415005e-03, -3.046128810839870e-01, -1.171408845369945e+00, -9.854938569067807e+00, -2.390924504611174e+02, -1.368446332831124e+03, -2.676584276473278e+03, -1.776258375400171e+03, -4.229321652710914e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
