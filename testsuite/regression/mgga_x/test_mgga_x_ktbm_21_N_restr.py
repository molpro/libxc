
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_21_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.240333625676232e+00, -5.137791295917967e+00, -4.993906032048487e+00, -4.794127167831804e+00, -4.520781900911853e+00, -4.154112504662288e+00, -3.674418746088391e+00, -3.063965650405084e+00, -2.310014406680736e+00, -1.469994632885429e+00, -8.255995978942369e-01, -5.658300596291681e-01, -5.792643490667037e-01, -5.033671553492419e-01, -3.305593619597096e-01, -1.649153961533849e-01, -6.733362398201360e-02, -2.116227464300283e-02, -4.373699884944954e-03, -4.837722841892564e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_21_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.377795691520572e+00, -6.237611576095486e+00, -6.041543419573823e+00, -5.770816996991257e+00, -5.404128093932608e+00, -4.921920017465164e+00, -4.316985730575169e+00, -3.613471381809326e+00, -2.859319505617786e+00, -1.978243129464796e+00, -1.119721384750046e+00, -7.891260815409750e-01, -8.715091355707363e-01, -6.847225395227464e-01, -4.478843813003433e-01, -2.212234765645761e-01, -8.844540314692360e-02, -2.769977432382885e-02, -5.710503661153409e-03, -6.305503194786132e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_21_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.312058667161516e-05, -1.418796425974351e-05, -1.586916441607313e-05, -1.862118499088174e-05, -2.337482429009941e-05, -3.220828571306658e-05, -5.022807260626265e-05, -9.077356858635829e-05, -1.843125367653792e-04, -3.525176174076368e-04, -6.035164996241835e-04, -3.468846242578413e-03, -2.600948587052362e-02, -6.561326464828982e-02, -1.681794116332395e-01, -3.463623988714503e-01, -6.871691145633825e-01, -3.655832934269334e+00, -8.860032728079064e+01, -8.164649097174601e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_21_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.497482561625394e-02, 1.536723081805109e-02, 1.594998154169198e-02, 1.682648658249225e-02, 1.816637119320481e-02, 2.024980220437935e-02, 2.349964920950132e-02, 2.817423553212974e-02, 3.174755727476452e-02, 2.341714974239042e-02, 7.718404826729843e-03, 6.787966721123697e-03, 6.737107729338494e-02, 1.111510040210066e-01, 1.151734574769490e-01, 4.505695114425286e-02, 6.785943379532667e-03, 9.641246108867716e-04, 1.964298474415948e-04, 2.478109673247267e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_21_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.796178895136687e-02, -1.880812690762219e-02, -2.008161840502986e-02, -2.202842981686398e-02, -2.505612823677918e-02, -2.981056519457441e-02, -3.705890720606496e-02, -4.644415440647156e-02, -5.836952756910213e-02, -1.328691270466484e-01, -2.988358726405979e-01, -7.860488310836595e-01, -1.019370259487132e+00, -1.360883527908481e+00, -2.753407590348572e+00, -7.804037128907678e+00, -3.404930855795570e+01, -3.416412685296599e+02, -8.064487623915276e+03, -6.624558752855922e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_21_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.434606038112903e-08, 1.079965969688933e-07, 1.309950016078749e-07, 1.724079034497525e-07, 2.541389957205414e-07, 4.361551711072926e-07, 9.021019968062498e-07, 2.178152253928967e-06, 3.461467633432382e-06, -3.550289276928555e-05, -5.080397673265452e-04, -8.004390933550076e-03, 1.804871480297082e-02, 1.201199021821831e-01, -1.087956563413919e+00, -3.265952226932166e+01, 6.748061508864684e+01, 3.075130626029142e+05, 1.013421849715497e+09, 6.655804225465288e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_21_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.595434860872311e-05, -7.294811747542195e-05, -8.426041139932789e-05, -1.034705146358904e-04, -1.383093640190261e-04, -2.069037985810732e-04, -3.527931267445293e-04, -6.449219933651118e-04, -6.637585147661063e-04, 2.860271171251107e-03, 8.087678815701292e-03, 4.016945080367629e-02, 1.052455035551487e-01, -1.812969406401119e-02, 1.042198870362514e+00, 5.165519145657097e+00, 2.337884354211233e+00, -7.123862784933250e+01, -2.232532953190612e+03, -2.019985776683618e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_21_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.967156428352877e-13, -2.495440106688182e-13, -3.509618453230803e-13, -5.717780732226566e-13, -1.147282255495404e-12, -3.082606539817678e-12, -1.235703752145859e-11, -8.325735822150058e-11, -1.004627341318711e-09, -1.989813988357686e-08, -7.701195167001911e-07, -6.396622716154106e-05, -2.853778322629077e-03, -4.255611286332282e-02, -1.617162910442112e+00, -2.008814206404863e+02, -1.893858448282883e+05, -2.256418206096237e+09, -8.138657608999146e+14, -4.150367156666738e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_21_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.290047400243938e-10, 6.390150029516696e-10, 8.381336895788721e-10, 1.236628802383504e-09, 2.157442539123551e-09, 4.766903157766694e-09, 1.458386797951154e-08, 6.792704225622758e-08, 4.905757028162447e-07, 4.312437769821146e-06, 4.080793738868083e-05, 1.417394983654335e-03, 2.946073494181632e-02, 2.361358309581724e-01, 3.816589997902548e+00, 7.496706964981993e+01, 2.820438725971772e+03, 7.369969755753793e+05, 2.297127616459834e+09, 1.621549618429651e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_21_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_21", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.738811826318291e-07, -3.268637733636494e-07, -4.206617414399008e-07, -6.021693132647276e-07, -1.000365040049865e-06, -2.040285862427224e-06, -5.469129783817244e-06, -2.038408178532086e-05, -9.871010904316895e-05, -3.901945144498361e-04, -7.862754819703421e-04, -5.356706989060562e-03, -9.524694194838385e-02, -4.622744464928159e-01, -3.515369542831229e+00, -1.396067072364643e+01, -3.564606376451724e+01, -2.317569350940936e+02, -6.185279029959193e+03, -6.019932539238783e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
