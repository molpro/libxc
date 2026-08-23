
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.152893930756702e+00, -4.069433304370352e+00, -3.952440207566345e+00, -3.790288092537490e+00, -3.569171964343051e+00, -3.274617913088062e+00, -2.895254999996276e+00, -2.430344530974751e+00, -1.903163556889764e+00, -1.377197201686520e+00, -9.118606459291239e-01, -6.113865647183361e-01, -5.368713804476842e-01, -4.507271174456830e-01, -3.186412320813579e-01, -2.004218867204591e-01, -1.079910530466633e-01, -3.717385291452071e-02, -7.666171026176571e-03, -8.445170817328239e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.122686306067974e+00, -5.026163380663103e+00, -4.890748088765790e+00, -4.702775054174133e+00, -4.445667493910511e+00, -4.100927270638332e+00, -3.650158837709403e+00, -3.076725410314213e+00, -2.365721156025237e+00, -1.551480179238918e+00, -9.278872491434030e-01, -8.001475923259387e-01, -7.071711386619723e-01, -5.695692157848441e-01, -3.895451108014297e-01, -1.967501378670048e-01, -1.246080886719159e-01, -5.013299974578023e-02, -1.030192987177240e-02, -1.127212367453674e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.178456695171206e-05, -1.211449036550077e-05, -1.259559133040558e-05, -1.329938247912718e-05, -1.433144033867158e-05, -1.584851951613020e-05, -1.812586243296560e-05, -2.218826773019045e-05, -3.641019132420896e-05, -1.359093832147569e-04, -8.486357526965439e-04, 2.231459051580354e-04, -3.583761961805583e-03, -2.241946702821455e-02, -3.957862327393521e-02, -3.516472614056890e-01, -1.118244415474595e+00, 2.372484503373009e+00, 2.848804099413062e+01, 3.188099116843990e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.702485758299681e-02, 1.647210412333433e-02, 1.569746085743281e-02, 1.462423961349942e-02, 1.316255899465501e-02, 1.122449975193736e-02, 8.770418561490296e-03, 5.928899056886525e-03, 3.224702282035514e-03, 1.584504995890344e-03, 1.183577903862679e-03, -5.592273439535693e-04, 4.885150911894579e-03, 2.139871249329685e-02, 7.214818627171585e-03, -1.677240447465530e-03, -1.310078972935609e-03, -2.179033529940332e-04, -1.169362389056665e-05, -1.639250050360928e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.286167901418518e-03, -4.377751730794089e-03, -4.517731250801993e-03, -4.742037008754737e-03, -5.135459625185169e-03, -5.948286679681578e-03, -8.109166933732460e-03, -1.579166478837581e-02, -4.905321233250955e-02, -1.677297546790393e-01, -3.795114108058915e-01, -4.099516449362650e-01, -6.327195699428907e-01, -7.613453847517964e-01, -2.909306003723870e+00, -5.369018047393887e+00, 2.581440855443392e+01, -5.586258837378788e+02, -1.305419981124402e+04, -9.848070397103953e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.077202973344694e-07, -1.220189535886699e-07, -1.457472565214859e-07, -1.875420925702828e-07, -2.674315898797418e-07, -4.375067900430052e-07, -8.489581199046916e-07, -1.944755947416908e-06, -4.102662700773227e-06, 8.423211006100978e-06, 2.558817253457846e-04, 7.469931765975396e-03, 3.219408079194332e-02, -1.155508579012406e-01, 3.283854108681017e-02, -3.186421852711632e+00, -4.131954073902628e+03, 1.924652718774146e+05, 3.553712779606289e+08, 3.020008919501573e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.206845222274990e-04, 1.288371563714061e-04, 1.413911692522832e-04, 1.612614145733974e-04, 1.938882330424385e-04, 2.500130681799960e-04, 3.517748465561191e-04, 5.446534770127718e-04, 9.148159675683733e-04, 1.624028609937487e-03, 3.168924232394609e-03, -7.450717868832409e-03, 4.770624840680559e-03, 1.439634576684522e-01, 6.766389310379138e-01, 6.045742821539961e-01, -2.943288153555036e+00, -1.748541493090153e+01, -1.086054435956172e+02, -1.131666376154330e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.344315934281776e-12, 1.653984276446972e-12, 2.221767415489499e-12, 3.376000205986554e-12, 6.088521657661742e-12, 1.388275043966664e-11, 4.329234557391371e-11, 2.012444494039142e-10, 1.503274634824718e-09, 2.255274321258899e-08, 1.680089477442086e-06, -1.273477765826488e-03, -3.134226454954558e-02, 8.771436491168552e-02, 2.037881495170949e+00, 2.840533467720865e+02, 3.741353675835628e+05, -7.570835022807231e+08, -1.427395377391756e+14, -9.299908802567399e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.671835374444534e-09, 1.743595807504852e-09, 1.835295776627035e-09, 1.929292361175232e-09, 1.929146267544139e-09, 1.392637672191310e-09, -1.808233871820945e-09, -1.942382815088638e-08, -1.292290155806915e-07, -9.079639339030393e-07, -6.291234168902954e-06, 6.257744236854355e-04, 2.360857915148214e-02, 2.747053777944777e-03, -9.404914279721622e-01, -8.190982332032675e+00, -2.359100910194735e+01, -1.413907820942714e+03, -1.748726458795528e+05, -1.366831172861793e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss1kcis_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss1kcis", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.471678860499319e-06, -7.623026445641040e-06, -7.832217218138842e-06, -8.110179683892760e-06, -8.445082842075064e-06, -8.734052317808216e-06, -8.554492961234744e-06, -6.455877306454129e-06, 1.437828641285553e-06, 1.473501761503192e-05, -3.162769587495187e-05, 9.844006021435150e-06, -2.806406013119375e-02, -1.017110988013014e-01, 1.953307514057953e-01, 7.260024579554942e-01, 3.179799209139603e+00, 1.967760400230271e+01, 1.312020168047410e+02, 1.453120585150767e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
