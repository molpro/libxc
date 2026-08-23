
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_epc17_2_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17_2", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.494556065165755e-04, -9.033117773427393e-04, -9.867462157817177e-04, -1.120273233465307e-03, -1.344196580549583e-03, -1.745873935024176e-03, -2.539989661585078e-03, -4.347726099242157e-03, -9.399612016696673e-03, -2.801317392361274e-02, -8.448288255827342e-02, -5.110229676948318e-02, -3.284046428398752e-02, -1.707916288086671e-02, -4.856010250384859e-03, -7.087858462030942e-04, -4.335702180299102e-05, -7.712613712368200e-07, -2.379262949863831e-09, -7.000105399321222e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_epc17_2_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17_2", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.387769103134493e-06, 3.387851576193627e-06, 3.825500751683775e-06, 3.825699492302317e-06, 4.554694278491610e-06, 4.555206185556591e-06, 5.849801520325228e-06, 5.851252299635164e-06, 8.371128610853113e-06, 8.375843411538191e-06, 1.396652461726396e-05, 1.398515526078556e-05, 2.890939358823327e-05, 2.900654834330548e-05, 8.036249530015218e-05, 8.110823636363251e-05, 3.203780880715067e-04, 3.297976953501720e-04, 1.197394876626670e-03, 1.334338759118047e-03, -4.312855140759662e-02, -6.789875486926178e-02, -6.246446830219663e-02, -2.040756350013529e-01, -4.225016004708178e-02, -1.517636993430565e-01, -2.261879381922147e-02, -7.742157502730788e-02, -6.222064409045346e-03, -2.339815190213878e-02, -8.579528680459377e-04, -4.128778836787242e-03, -4.913945241228079e-05, -3.689562200399943e-04, -8.204080294530938e-07, -1.287554923473015e-05, -2.427757879495382e-09, -1.191110146708873e-07, -7.030188653334563e-13, -1.635862319835031e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_epc17_2_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_epc17_2", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.647800688602991e-08, -1.864507279011866e-08, -5.648075676098115e-08, -6.777930775862426e-08, -2.236211168882963e-08, -6.778635041909111e-08, -8.807200360905665e-08, -2.902959113907505e-08, -8.809180173893144e-08, -1.282301255208661e-07, -4.220273813898230e-08, -1.282937368010066e-07, -2.196128813398458e-07, -7.209863894533107e-08, -2.198603324542886e-07, -4.736354090972498e-07, -1.548037396213682e-07, -4.748998636674732e-07, -1.412266993731093e-06, -4.574338111451078e-07, -1.421775253335439e-06, -6.557803793988862e-06, -2.074857239074793e-06, -6.680077609053846e-06, -5.207962781196629e-05, -1.482138487405759e-05, -5.518708996219821e-05, -2.122431309649187e-04, 1.929741993791560e-04, -2.635670132719786e-04, 7.500776165742845e-02, 4.897917432670053e-02, 1.859088581050453e-01, 2.708057628202631e-02, -3.418924398008324e-01, 2.890507628220281e-01, 4.560289240626901e-03, -4.554723791578853e-01, 5.883983967074023e-02, -3.548962699256406e-03, -4.805203312852651e-01, -4.158019823186244e-02, -2.027873942180214e-03, -4.497290333288038e-01, -2.867708884938847e-02, -2.914225215582351e-04, -4.297690543311553e-01, -6.749000974127337e-03, -1.370938042435415e-05, -4.258408699954484e-01, -7.728707570738972e-04, -1.586157251433745e-07, -4.255393829649034e-01, -3.906771081585835e-05, -2.654829486551587e-10, -4.255319539691100e-01, -6.390424916086189e-07, -3.530057156507377e-14, -4.255319149182594e-01, -1.911354646575468e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
