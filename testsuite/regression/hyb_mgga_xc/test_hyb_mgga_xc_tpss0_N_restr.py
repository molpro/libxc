
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_tpss0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.591112242856432e+00, -3.519035117500445e+00, -3.417988247383080e+00, -3.277913935308704e+00, -3.086851547294488e+00, -2.832213762613293e+00, -2.503980167518583e+00, -2.101060692437944e+00, -1.642709603794487e+00, -1.183493959120952e+00, -7.781613348323072e-01, -5.301003535750067e-01, -4.726236738107616e-01, -3.965371916978033e-01, -2.769690650287330e-01, -1.694343921633108e-01, -9.029174905077780e-02, -3.140819054100973e-02, -6.577084731228783e-03, -7.276212803348797e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_tpss0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.448130329877357e+00, -4.364242439245605e+00, -4.246548111523341e+00, -4.083167812424425e+00, -3.859699024974304e+00, -3.560105620181789e+00, -3.168560249795526e+00, -2.670993570660274e+00, -2.054395641532584e+00, -1.344587779454266e+00, -7.992112666872228e-01, -7.113744541244478e-01, -6.283162907802542e-01, -5.129392247334118e-01, -3.528810277414730e-01, -1.703706229339554e-01, -1.004996429353688e-01, -4.089575464911743e-02, -8.759621818279434e-03, -9.701477129428215e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.776500977161703e-06, -1.005691103567170e-05, -1.046728705614602e-05, -1.107109995336902e-05, -1.196515141080415e-05, -1.330168321548430e-05, -1.536681927406512e-05, -1.917211273210945e-05, -3.219002032925359e-05, -1.197289888001315e-04, -7.352881998592970e-04, 1.462542484777799e-03, -2.045340023170472e-03, -1.813876267501640e-02, -3.250505018655316e-02, -3.204152305868340e-01, -1.364135421407317e+00, -2.218977771386021e+00, -2.675736392864826e+00, -2.958876583430840e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss0_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.434980360639739e-02, 1.390378804163529e-02, 1.327946621061592e-02, 1.241596627735355e-02, 1.124272174474228e-02, 9.692130816758323e-03, 7.736164208673428e-03, 5.475568239406462e-03, 3.293301526438003e-03, 1.834640795382768e-03, 1.317685915448301e-03, -1.569524379055808e-04, 6.518856365778482e-03, 2.495604228080699e-02, 1.492114821583086e-02, 4.251704570606572e-03, 2.850638933437745e-04, 3.528683415936594e-06, 3.622303420105196e-09, 1.053437739324451e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.868106510887546e-03, -3.960255857136777e-03, -4.101029113811178e-03, -4.325595544341052e-03, -4.714161741554541e-03, -5.494251590849577e-03, -7.484360466564539e-03, -1.432246809236924e-02, -4.373190803710969e-02, -1.514608883837584e-01, -3.603537232906576e-01, -3.557095457484081e-01, -5.148952390926316e-01, -6.659696882768918e-01, -2.818215415102077e+00, -7.711213750002708e+00, 2.630779399474898e+01, -3.055797513320182e+02, -1.008580417592371e+04, -8.374606688381647e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.292281621465899e-08, -1.051358807223034e-07, -1.253799018513114e-07, -1.609813707187772e-07, -2.288892613225898e-07, -3.730676077626048e-07, -7.207237998181944e-07, -1.642310155694895e-06, -3.403843429807439e-06, 8.825581265962574e-06, 2.888232782515983e-04, 6.112236715800394e-03, 1.107942766170895e-02, -9.814437019181893e-02, 2.478940787693634e-01, 7.511948871460625e+00, -4.137862250291086e+03, -2.665878057678589e+05, -3.738603052988850e+07, -3.065422931896420e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss0_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.086019023861267e-04, 1.157303411523955e-04, 1.266855720625908e-04, 1.439774700722307e-04, 1.722641973395252e-04, 2.206925332229957e-04, 3.080910113972729e-04, 4.739492845052527e-04, 8.018340391508166e-04, 1.486848874291816e-03, 3.015233326453667e-03, -6.046741635711784e-03, 7.073308979970804e-03, 1.220179032314760e-01, 6.287510888743980e-01, 1.420350709013819e+00, 1.062224328857155e+00, 4.836855288300775e-01, 5.791685487092686e-02, 1.266002591641746e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.290568672732262e-12, 1.579331280274369e-12, 2.106178125252825e-12, 3.170028485115091e-12, 5.647831988574273e-12, 1.268460907232755e-11, 3.883947855397288e-11, 1.766213738767506e-10, 1.281711161079386e-09, 1.832014620441973e-08, 1.203989027308864e-06, -1.399460309426260e-03, -2.529484915137189e-02, 5.887347832702289e-02, 1.105194506578941e+00, 1.723651789339034e+02, 4.010735841644503e+05, 8.070848092097746e+08, 1.357915073332872e+13, 8.641925773584314e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_tpss0_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.057169465176963e-09, 1.080791922803034e-09, 1.099064684122737e-09, 1.079775200361222e-09, 9.062571896827891e-10, 1.306859399839531e-10, -3.187443169118724e-09, -1.901518374226677e-08, -1.102427366031071e-07, -7.348057126273755e-07, -4.661288810753402e-06, 6.233583824732624e-04, 2.427290693866476e-02, 2.392867995941958e-02, -5.411123075437060e-01, -3.465990353877609e+00, 3.020489960251866e+01, 1.164548413383349e+01, 1.046539474901529e+01, 3.383171647015423e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_hyb_mgga_xc_tpss0_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_tpss0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.651501678066838e-06, -5.755952681172708e-06, -5.899116347499590e-06, -6.086636379963131e-06, -6.306222738756480e-06, -6.479211669013904e-06, -6.307545319120146e-06, -4.840479300718971e-06, 1.603037858170764e-07, 5.952255247237249e-06, -4.894748727104243e-05, -1.421804497832735e-04, -3.082929294380479e-02, -1.303266899537790e-01, -8.423034226208954e-02, -6.492361497466459e-01, -1.293880443254145e+00, -4.767792462522625e-01, -6.095457099740614e-02, -1.400735068742277e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
