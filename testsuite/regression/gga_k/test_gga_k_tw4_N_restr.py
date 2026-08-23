
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_tw4_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw4", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.446417470811323e+01, 9.080431292177423e+01, 8.579952934101811e+01, 7.910489010809027e+01, 7.042792367444902e+01, 5.967603979609078e+01, 4.717497305184718e+01, 3.388216089246839e+01, 2.138541753594200e+01, 1.141214867205249e+01, 4.986185412176836e+00, 2.207968468448569e+00, 1.628869320022228e+00, 1.100827608444323e+00, 5.557424138534027e-01, 2.046450992690037e-01, 4.786326436816663e-02, 5.332776865509201e-03, 2.313429788718295e-04, 2.829910225584075e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_tw4_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.491579951635578e+02, 1.431014313477327e+02, 1.348241569694100e+02, 1.237622301647967e+02, 1.094456930978665e+02, 9.174911099931931e+01, 7.126592503363293e+01, 4.968877328763465e+01, 2.986109226150299e+01, 1.495565234782441e+01, 6.381797543675423e+00, 3.377247406396235e+00, 2.608166503358228e+00, 1.651996882152392e+00, 7.514785392138614e-01, 2.574294249383032e-01, 6.938204614150739e-02, 8.712453128041480e-03, 3.852072822097374e-04, 4.716459734433754e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw4_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw4", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.886744580123542e-05, 9.416911936954630e-05, 1.023228702896803e-04, 1.152275419765333e-04, 1.364941771269322e-04, 1.735747554639415e-04, 2.434013769825309e-04, 3.887734222347970e-04, 7.294463993837497e-04, 1.635619971242754e-03, 5.136491907348942e-03, 2.428960583514819e-02, 3.960896248755120e-02, 6.788346890889130e-02, 1.646684090033873e-01, 4.479044304906204e-01, 7.043346011765796e-01, 3.954871697298359e-01, 9.920035555895403e-02, 1.211695695080641e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw4_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.913028786924309e-01, 6.040552629542837e-01, 6.228381598749377e-01, 6.507734167513650e-01, 6.928671990864582e-01, 7.573442794834001e-01, 8.577592200908563e-01, 1.014286352898412e+00, 1.238735715849061e+00, 1.447441161967970e+00, 1.865901502229091e+00, 3.946935696822600e+00, 4.446294285017776e+00, 5.623994318224613e+00, 7.278208530743126e+00, 4.633881290442783e+00, 1.253069306482056e+01, 1.576238650337668e+02, 8.936068219262989e+02, 8.143546106099383e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw4_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.867933712052635e-07, -4.310700567610895e-07, -5.031487124286446e-07, -6.266859106180868e-07, -8.538532603055339e-07, -1.311645376755868e-06, -2.334458862170847e-06, -4.707934007972944e-06, -6.442606268397218e-06, 9.817695380786433e-05, 2.083615552876831e-03, -2.500174873976735e-02, -8.079827931545092e-02, -1.737776668493906e-01, 1.878546917794371e-01, 5.412858258052396e+01, 2.343439755164813e+03, 5.147075903398536e+04, 1.502686569414989e+06, 1.359971682957540e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_tw4_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_tw4", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.174189918669655e-12, -1.462492824107788e-12, -2.004260732582168e-12, -3.148974230624386e-12, -6.011730783969297e-12, -1.513050390499014e-11, -5.617269628612865e-11, -3.572823018162170e-10, -4.678047423591418e-09, -1.511634819377226e-07, -1.406510495546303e-05, -1.140836050522786e-03, -5.770701992936837e-03, -5.351505000174868e-02, -2.492892676074134e+00, -4.958747060406952e+02, -2.074791242512657e+05, -1.436725475254534e+08, -5.036963098423738e+11, -3.539035280089542e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
