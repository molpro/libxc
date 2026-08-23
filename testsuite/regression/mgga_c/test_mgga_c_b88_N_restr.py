
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_b88_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.077792530823556e-02, -5.049233304239436e-02, -5.007157617442444e-02, -4.944560331562351e-02, -4.850206102376090e-02, -4.705628550091922e-02, -4.480229826591672e-02, -4.126427178941789e-02, -3.596808513417589e-02, -3.013176205350940e-02, -3.550305747706663e-02, -7.131981811930387e-02, -4.511016711549099e-02, -3.211755902795129e-02, -2.126204835958429e-02, -1.088924974889464e-02, -4.409882607041767e-03, -1.747505326689476e-03, -6.936383823318629e-04, -1.909329806353094e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_b88_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.115929902290295e-02, -7.143158879581590e-02, -7.182638151414546e-02, -7.239892687452998e-02, -7.322598086000424e-02, -7.440099161844213e-02, -7.598150584922291e-02, -7.774898086166819e-02, -7.848107239955333e-02, -7.605472480635661e-02, -8.066621741830590e-02, -5.833864268332484e-02, -4.432301683390122e-02, -5.072792713257907e-02, -4.802610954920004e-02, -3.378787040793454e-02, -2.056606307265169e-02, -1.851929846783433e-02, -1.836914983838375e-02, -1.095893684044066e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b88_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.024970240153713e-07, 3.317660970128130e-07, 3.786539441473744e-07, 4.573096551809587e-07, 5.981219199658903e-07, 8.741466524314118e-07, 1.486781213104966e-06, 3.090537122882274e-06, 8.286261400666742e-06, 3.127855750445463e-05, 2.497970542178466e-04, 4.333589412338574e-03, 6.473860158294208e-03, 1.223361779357261e-02, 4.254039286617411e-02, 2.346480998663364e-01, 2.636064588707144e+00, 1.013261471034423e+02, 1.296894435082197e+04, 6.091409720042351e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b88_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.265063771324209e-04, -2.340524608405310e-04, -2.452324899898434e-04, -2.619877975302467e-04, -2.874742610752348e-04, -3.269328098579601e-04, -3.890839840682511e-04, -4.876627007533193e-04, -6.409517540769497e-04, -8.835114758276248e-04, -1.619543182732683e-03, -6.516153074083709e-03, -9.526381381342089e-03, -1.101236934659900e-02, -1.355098980497094e-02, -1.570340882129468e-02, -1.829424489057549e-02, -2.499081395308027e-02, -2.900229559909916e-02, -1.858740082198480e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b88_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.405307663557805e-04, 1.509934461201713e-04, 1.670475397735705e-04, 1.922258200558622e-04, 2.326108487662985e-04, 2.978558337944314e-04, 3.953691655227548e-04, 4.628381340301140e-04, -1.450913124040038e-04, -5.391288706582110e-03, -2.064614554634301e-02, 1.126499899842657e-01, 3.411713334436242e-02, 7.790953140052231e-02, -1.293632777470018e-01, -2.576085105063046e+00, -1.024991425635744e+01, 2.368104781841591e+01, -2.251899994055259e+04, -2.716876877000129e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b88_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.718828296986551e-09, -1.961387468491415e-09, -2.365303191232361e-09, -3.078235306544159e-09, -4.434999897990838e-09, -7.244619140262120e-09, -1.328115809283692e-08, -2.054925047319201e-08, 1.172179906802209e-07, 4.287850201490661e-06, 1.461949311234985e-04, -8.891656723703203e-03, -2.226884838720721e-02, -3.290470590140596e-02, 2.856750437503902e-01, 2.486820088471938e+01, 2.142196914345848e+03, 1.493268854132983e+06, 3.476906507613819e+10, 1.853735159301005e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b88_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.473934284096113e-07, 2.501552274427273e-07, 2.495347528623784e-07, 2.357636195082063e-07, 1.762088070746417e-07, -4.776009279713440e-08, -9.278327392818807e-07, -4.872708612531359e-06, -2.595823632020789e-05, -1.588714679725964e-04, -1.205668026803698e-03, -9.855115281440588e-04, 5.467831449955378e-03, -1.227269608356233e-02, -1.787170861457730e-01, -1.785082001744051e+00, -2.003567009961706e+01, -7.309997222034194e+02, -1.197817075808766e+05, -7.154120076111187e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b88_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.389773866094268e-14, -1.785831370815500e-14, -2.558283544495398e-14, -4.279166619011332e-14, -8.917652783008721e-14, -2.532510465522210e-13, -1.105720983547447e-12, -8.664948966070739e-12, -1.464856442388536e-10, -6.699688133882623e-09, -1.452325366276422e-06, -6.688744138807592e-04, -3.263609634401646e-03, -2.969695305057450e-02, -1.575759168270572e+00, -3.956838973327463e+02, -5.779170059560909e+05, -1.939540929767483e+10, -3.843288858952959e+16, -1.223621938016732e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b88_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.085820779859422e-12, 7.362364738310821e-12, 9.671682070168011e-12, 1.428638934361131e-11, 2.491300930737531e-11, 5.482592118514334e-11, 1.663332250933231e-10, 7.763472540149646e-10, 6.290004934240805e-09, 1.009564298394500e-07, 4.808535636966485e-06, 5.565574736358616e-04, 2.740052023024394e-03, 1.494944056581834e-02, 2.677004681911782e-01, 1.310217674656966e+01, 1.926632315744765e+03, 2.352701421866402e+06, 4.270217948853349e+10, 1.862288637755488e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_b88_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
