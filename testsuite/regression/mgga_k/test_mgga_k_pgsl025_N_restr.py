
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_pgsl025_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.001833530683722e+02, 1.415039162765037e+02, 1.103770037499595e+02, 9.145999449832273e+01, 7.727730672733605e+01, 6.434421808844026e+01, 5.146971316254974e+01, 3.909382928566118e+01, 2.886631981567145e+01, 2.209242744736899e+01, 1.359576119799472e+01, 2.604018622406183e+00, 1.654664467152719e+00, 1.205752316044805e+00, 8.826562610343321e-01, 9.041586355140508e-01, 1.620697608641718e+00, 9.527001984441352e+00, 2.011827276877594e+02, 1.613576741492763e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_pgsl025_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.203554086425675e+01, 5.347052488300706e+01, 8.852959626022671e+01, 9.754183648711269e+01, 9.195949960546523e+01, 7.723500388383849e+01, 5.638759511193013e+01, 3.192092549390812e+01, 7.080494009270033e+00, -1.167108106360348e+01, -1.205742611130088e+01, 2.437187287784514e+00, 2.516092097536016e+00, 1.273428130848702e+00, -1.473731061447380e-01, -9.811577513856099e-01, -2.231748961853028e+00, -1.544745286168722e+01, -3.349026887341535e+02, -2.689256287009826e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pgsl025_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.088113891127417e-04, 2.268692667347586e-04, 2.556416869153456e-04, 3.035889710425159e-04, 3.888033013275572e-04, 5.548461073665490e-04, 9.232823944033491e-04, 1.899882518620831e-03, 5.132371539089211e-03, 1.831411174576748e-02, 7.196905943750181e-02, 8.179851176226270e-02, 7.643617286529900e-02, 2.734082810021302e-01, 1.454090219318535e+00, 1.063499116071466e+01, 1.272848426561253e+02, 3.883781956864946e+03, 4.376504016110850e+05, 3.237673133752216e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pgsl025_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.002737317665205e-02, -5.596061130431691e-02, -3.914847090860271e-02, -2.733052339908019e-02, -1.889563593641541e-02, -1.263878646992486e-02, -7.520320794892840e-03, -2.275402557347318e-03, 5.629207767719936e-03, 2.316854073069598e-02, 5.742318510854113e-02, 2.673251664991729e-02, -6.180509139447690e-03, -6.421513828103487e-04, 1.637654948299329e-02, 7.579002460511386e-02, 4.263180098340550e-01, 4.146658453873899e+00, 9.518674858779885e+01, 7.721263675792194e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pgsl025_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.372803724180176e+00, 2.113755932275644e+00, 1.525470317296029e+00, 1.286417498658907e+00, 1.258151450059088e+00, 1.414529670280878e+00, 1.850600829407497e+00, 2.931256932464868e+00, 5.815002647972963e+00, 1.333708111778088e+01, 2.879172809938294e+01, 9.235281377563080e+00, 5.408112201123356e+00, 1.278486008248460e+01, 4.766879461953428e+01, 2.061962437947273e+02, 5.582119414328171e+03, 1.266495823173919e+06, 3.125426001673793e+09, 1.857469088175804e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pgsl025_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.897358499032639e-06, -3.362151730806275e-06, -4.162134633358331e-06, -5.650886391926926e-06, -8.748309148438113e-06, -1.629750791590962e-05, -3.925618975163157e-05, -1.334582023196548e-04, -6.937397831366590e-04, -5.558994310695098e-03, -6.874683549948830e-02, -3.397795295685661e-01, -4.394672206262015e-01, -3.272483881745691e+00, -4.453378926142203e+01, -1.020149466297863e+03, -1.296114511649766e+05, -1.206700983077577e+08, -1.532302992242752e+12, -8.386021856816717e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pgsl025_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.447731875432524e-04, 5.536758995133922e-04, 4.229478480688022e-04, 3.350186397745108e-04, 2.776335358707667e-04, 2.407506255831549e-04, 2.076671869544028e-04, 1.067167255858259e-04, -5.597305554532519e-04, -6.550639221011675e-03, -5.957105015827463e-02, -7.193901763030358e-02, 2.505226650432024e-02, 5.010746119254929e-03, -4.073864425487252e-01, -1.085076655858676e+01, -7.235176108777306e+02, -2.147295637924925e+05, -5.554469166333807e+08, -3.333190394897236e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pgsl025_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.857736448211595e-11, 2.303467680518346e-11, 3.135389194611688e-11, 4.874864998657880e-11, 9.153362538536990e-11, 2.241132474870793e-10, 7.924420730007206e-10, 4.586018392077218e-09, 4.889783715003205e-08, 9.867537655871513e-07, 6.379022935937100e-05, 1.666684959100335e-02, 9.420417397581587e-02, 7.402377513795947e-01, 2.151223138696048e+01, 5.707666092785146e+02, 1.203160246501381e-01, 1.665698479163820e-72, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pgsl025_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_pgsl025_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_pgsl025", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.721545396684167e-07, 1.906475857998800e-07, 2.207476319952440e-07, 2.724652144579362e-07, 3.685191374626755e-07, 5.680406815528217e-07, 1.054779990418410e-06, 2.550154205189626e-06, 8.922685570665522e-06, 5.092343541463026e-05, 4.444838549860385e-04, 2.176792948621229e-03, 4.308379761027347e-03, 1.283465861349811e-02, 8.863045467959381e-02, 1.638161244779480e+00, 1.009566826413761e+02, 3.007913348015153e+04, 7.907747742927623e+07, 4.785150378265925e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
