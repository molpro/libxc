
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_epc18_1_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_1", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.921528129275159e-03, -3.106843012663250e-03, -3.393951162164739e-03, -3.853473712679664e-03, -4.624185553735571e-03, -6.006942040710231e-03, -8.741101214775207e-03, -1.496263869352647e-02, -3.224344456480543e-02, -9.131730040637551e-02, -1.613214500662493e-01, -6.438502153383080e-02, -4.076834982760571e-02, -2.146334174799281e-02, -6.252144892015095e-03, -9.232297798216207e-04, -5.659611906552626e-05, -1.006921352489677e-06, -3.106259935235027e-09, -9.139026493629745e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_epc18_1_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_1", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.299381585727953e-05, 1.294661178445611e-05, 1.467236743537773e-05, 1.456527303112930e-05, 1.748151376747961e-05, 1.722852843129244e-05, 2.250278602847427e-05, 2.186941255180945e-05, 3.236016700566056e-05, 3.063618516970998e-05, 5.443922665756775e-05, 4.914684160981590e-05, 1.136645631634611e-04, 9.434607254083083e-05, 3.125297200939289e-04, 2.220358843604856e-04, 1.069972910421629e-03, 4.618380471178086e-04, -3.693988513983278e-03, -1.081557531201091e-02, -1.580572704094519e-01, -2.722044859215330e-01, -8.192696598225911e-02, -2.699676564724384e-01, -5.246042163849592e-02, -1.880124124645472e-01, -2.812980322459398e-02, -9.582917019683511e-02, -7.969360345282827e-03, -2.989554134328974e-02, -1.116556980199782e-03, -5.370368111892507e-03, -6.414091135661537e-05, -4.815665804448580e-04, -1.071084188835829e-06, -1.680964769801910e-05, -3.169572774695079e-09, -1.555060434728491e-07, -9.178301853183189e-13, -2.135709139783868e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_epc18_1_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc18_1", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.068518855337309e-05, -1.096903424580108e-05, 1.068624298597027e-05, 1.206706527420702e-05, -1.240730726780796e-05, 1.206960858521848e-05, 1.436941720231262e-05, -1.481105456239982e-05, 1.437597769319809e-05, 1.845965105308915e-05, -1.910229253848299e-05, 1.847828765774445e-05, 2.642652620938352e-05, -2.752735680891575e-05, 2.648733444687792e-05, 4.412760583712115e-05, -4.650106074943121e-05, 4.436965793157751e-05, 9.157720394293617e-05, -9.858821200580177e-05, 9.285868746144551e-05, 2.578408007526575e-04, -2.884539433702335e-04, 2.680551594824084e-04, 1.139076564259425e-03, -1.292660412003502e-03, 1.286206490613258e-03, 1.436015881099380e-02, -5.445131763466959e-03, 1.968095119027404e-02, 1.744048179715416e-01, -6.578935909429888e-02, 3.623337269006818e-01, 1.855551444845384e-02, -5.269552529778614e-01, 1.042341716471571e-01, 2.507627062309217e-03, -5.791682574234314e-01, 9.644819403651913e-03, -3.012093774775018e-03, -5.875182059219560e-01, -2.389129050139421e-02, -1.706611676546042e-03, -5.695505442274439e-01, -1.444801415534984e-02, -2.674350492869534e-04, -5.581011048719974e-01, -3.319124682461437e-03, -1.439880315988346e-05, -5.557534927547384e-01, -3.641831135767275e-04, -2.108758061892735e-07, -5.555610219410466e-01, -1.746565557957282e-05, -5.300269268615549e-10, -5.555555932163312e-01, -2.770767479626894e-07, -1.314121322498464e-13, -5.555555555943388e-01, -8.654888384502988e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
