
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_hyb_tau_hcth_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hyb_tau_hcth", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.010765161264774e-01, -1.004582810469567e-01, -9.958712041247199e-02, -9.837313094699099e-02, -9.670875814522556e-02, -9.447103296929479e-02, -9.147475570508139e-02, -8.710620691177218e-02, -7.867645909245508e-02, -5.877541878355303e-02, -4.108988781051012e-02, -5.725079715684948e-02, -5.546265865533798e-02, -5.017774914093003e-02, -3.900375203875245e-02, -3.239276938331717e-03, 3.480504097653153e-02, 2.446008201832591e-02, 6.706636282725245e-03, 8.170831742220217e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_hyb_tau_hcth_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hyb_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.174624181526724e-01, -1.162654892105658e-01, -1.145048083258046e-01, -1.119411720033548e-01, -1.083324099512736e-01, -1.037018316478578e-01, -9.922293069504937e-02, -9.949938537067074e-02, -1.159530073371218e-01, -1.559940395989818e-01, -1.604893469905976e-01, -6.416259557592111e-02, -6.742025846006186e-02, -5.653425554205360e-02, -7.608571287461154e-02, -9.921108887391047e-02, -5.853357094202287e-03, 2.726714293646489e-02, 8.708080415276449e-03, 1.084690061128200e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_hyb_tau_hcth_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hyb_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.747398246078379e-08, 8.678222842464363e-08, 8.423132969125913e-08, 7.723769485757531e-08, 6.050857024910380e-08, 2.657956783293232e-08, -7.733062882315435e-09, 2.594818767286727e-07, 3.760672571531924e-06, 3.670466700464200e-05, 3.057330751669315e-04, 5.611871754469925e-06, 1.899717176266550e-03, -4.504841260664002e-05, 2.976005397071828e-02, 5.111250430581948e-01, 3.236357061967728e+00, 7.919618223082844e+00, 1.222721396873925e+01, 1.522119273109975e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_hyb_tau_hcth_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hyb_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.898418851105720e-04, -3.215696070243902e-04, -3.651543782079212e-04, -4.206696314345744e-04, -4.752452928565620e-04, -4.620037300463092e-04, -9.174208440702735e-05, 1.887958572931467e-03, 1.093298461245049e-02, 4.337922743558315e-02, 1.264078814400864e-01, -3.353326245030175e-02, -2.160124684110052e-02, 1.849196119174886e-02, 1.910078870706079e+00, -9.478817511649510e-01, -1.378360961915291e+02, -2.056983279190504e+02, 8.531436619215412e+03, 9.166166256074441e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_hyb_tau_hcth_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hyb_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.564422673673389e-09, 3.061733915033832e-09, 3.844102705047659e-09, 5.075048816113897e-09, 6.868939354422101e-09, 8.246818177700052e-09, -1.448087238528454e-09, -1.219276847991254e-07, -1.458396995393896e-06, -1.850697828847879e-05, -3.656181463001374e-04, 1.754921346298731e-03, 9.099304228233640e-04, -1.878073514959444e-02, -1.944216611388739e+00, -2.317086550280999e+00, 9.225968106768842e+03, 9.338676555058880e+05, 1.695907770836052e+08, 1.573560612443201e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_hyb_tau_hcth_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_hyb_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.578153577397551e-14, -4.427561868771826e-14, -5.887648512839482e-14, -8.511655538925634e-14, -1.325320893391181e-13, -1.961223205271923e-13, 5.542261888729839e-14, 6.332321775613693e-12, 1.394985507562257e-10, 3.523585450213175e-09, 1.848982493689400e-07, -1.414555212443435e-04, -2.969981334438757e-03, 7.117450317805264e-03, 1.192975421177250e+00, -3.413038727742990e+02, -9.527838060212285e+05, -2.887222862367022e+09, -6.209606196958916e+13, -4.445709265001144e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
