
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_xb1k_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.520863680245580e+00, -2.473870567375778e+00, -2.408054141068614e+00, -2.316949318947354e+00, -2.192947403255304e+00, -2.028198997581888e+00, -1.816732232248940e+00, -1.558207269448284e+00, -1.262701423240839e+00, -9.521253061143357e-01, -6.471047053119239e-01, -4.473665803332660e-01, -3.681788491603643e-01, -3.012509001358357e-01, -2.203073412888113e-01, -1.418935753987416e-01, -8.194597869929686e-02, -4.153853191973242e-02, -2.551173279516946e-02, -1.769272643851212e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_xb1k_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.144333514016994e+00, -3.079479844449178e+00, -2.988584135602105e+00, -2.862632630320095e+00, -2.690939849108469e+00, -2.462333003240963e+00, -2.168061901747886e+00, -1.807387140565944e+00, -1.396646224169027e+00, -9.818934419383122e-01, -6.551599725808508e-01, -5.584016870640992e-01, -4.586377421956833e-01, -3.683285636120789e-01, -2.503983120005634e-01, -1.402898097613829e-01, -6.907285442773486e-02, -2.488462815462697e-02, -7.035015890859079e-03, -2.893790237428054e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_xb1k_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.023608582184587e-06, -2.180012107147332e-06, -2.425737464969418e-06, -2.826859091705999e-06, -3.518405356417650e-06, -4.806858186751887e-06, -7.485112585806815e-06, -1.396785641556347e-05, -3.325490495336229e-05, -1.083545660762668e-04, -5.037514317366091e-04, 3.527383972169514e-03, 2.959709157672892e-03, -4.585494249754983e-03, -2.938436353292058e-02, -2.378737242218650e-01, -2.676936214720079e+00, -6.865307001939858e+01, -7.345836549929903e+03, -4.375965490329960e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_xb1k_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.375567663333888e-04, -3.424569951505816e-04, -3.492532570038716e-04, -3.584443056041141e-04, -3.702743158825236e-04, -3.839209698517954e-04, -3.954169130397689e-04, -3.935947374396980e-04, -3.585826108127490e-04, -2.919286190495682e-04, -3.934739840274068e-04, -5.911249725741185e-03, -1.215099559354934e-02, -8.595759447999491e-03, -5.100653368791458e-03, -1.941883042677230e-03, -3.394174606475803e-04, -2.122505356273371e-05, -3.221485433594406e-07, -6.299510954859019e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_xb1k_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.768862287470838e-03, -7.072724581853324e-03, -7.533607366337500e-03, -8.248946050501742e-03, -9.396322188848789e-03, -1.132428847460731e-02, -1.478038798973857e-02, -2.153467945030314e-02, -3.620309014881392e-02, -7.199188726968905e-02, -1.830387905726136e-01, -1.647261036774499e-01, -2.813962530385241e-01, -6.268175271140947e-01, -1.692371666444265e+00, -5.570632568820892e+00, 5.501987533529064e+00, -4.567804733850206e+02, 7.256749581750192e+03, 4.534206603648263e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_xb1k_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.174631244179804e-08, 1.340499767361045e-08, 1.620087470626619e-08, 2.124904926853625e-08, 3.130107787578311e-08, 5.428221196351829e-08, 1.179363254154290e-07, 3.462094059564061e-07, 1.485943593707489e-06, 1.031174200568456e-05, 2.268382601489791e-04, 5.249926248246828e-03, -7.309270719741145e-03, 8.469373822334469e-02, 9.016078443432106e-01, 1.592738508913816e+01, -1.752377271007812e+03, 4.595302264222060e+05, -4.209406863738579e+09, -1.486945288437976e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_xb1k_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.617578248211794e-06, -1.829183131956686e-06, -2.174872864687964e-06, -2.769351600943678e-06, -3.864806628696994e-06, -6.072754570443859e-06, -1.103528589734494e-05, -2.357149524392739e-05, -5.858087267398964e-05, -1.689407216062558e-04, -9.018020406182865e-04, -1.440910780837978e-02, -1.730638894015350e-02, -7.371400611027790e-02, -2.381614667286154e-01, -6.950994680341150e-01, -1.626510888596800e+00, -3.216408521515735e+00, -5.568582976990760e+00, -8.117935153904893e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_xb1k_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.784922462203367e-14, 2.182354405076517e-14, 2.916395031997412e-14, 4.435085730676210e-14, 8.154204258433646e-14, 1.990628445157258e-13, 7.482212072789674e-13, 5.372768808242251e-12, 9.224259824643408e-11, 4.211196509824440e-09, 2.270335078077696e-07, -2.688278846006966e-03, -1.447687792863013e-02, -4.734282501823880e-02, -7.668277827132151e-01, 2.012892511971830e+01, 3.512726639353723e+05, 5.348527210448788e+09, 1.048226297424105e+16, 3.509697112813705e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_xb1k_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.916050179873967e-11, 3.446096601149647e-11, 4.373770127880466e-11, 6.138564941131550e-11, 9.912267028079568e-11, 1.939545178257547e-10, 4.901359636795506e-10, 1.715978639403006e-09, 8.928588069670857e-09, 7.918849669045722e-08, 2.762267028323556e-06, 1.573286494359455e-03, 1.236868686480505e-02, 3.538576891525783e-02, 2.619793796742150e-01, 4.173191644341570e+00, 1.214262748700987e+02, 7.899879129525601e+03, 1.637581142200522e+06, 1.839943426341287e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_xb1k_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_xb1k", 1)
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
