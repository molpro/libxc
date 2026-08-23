
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m11_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.705639232136813e-01, -3.595707039923052e-01, -3.441273267022504e-01, -3.226853175883578e-01, -2.933881238083756e-01, -2.539341899929660e-01, -1.996937630047245e-01, -1.139990744987350e-01, 4.325347619847291e-02, 2.179444126038605e-01, 1.763621868521672e-01, -7.018170408813461e-02, -5.530252936198711e-02, -3.661907187942735e-02, 5.923286110025379e-02, 7.840150639804135e-02, -3.267184227975688e-02, -4.661062007717927e-02, -1.480986429701999e-02, -2.019183245774046e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m11_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.209479864580970e-01, -6.107622902101546e-01, -5.959561591897078e-01, -5.748470639867426e-01, -5.465394304628577e-01, -5.153293127555011e-01, -5.034563875896658e-01, -5.579618423611798e-01, -5.912604043328602e-01, -1.877954168275487e-01, 1.180152592367842e-01, -9.234436769800909e-02, -1.704884424522831e-01, -2.474756616909804e-01, -1.950244253878214e-01, 7.549127402801266e-02, 4.839140891573435e-02, -4.920700685026093e-02, -1.890147892833719e-02, -2.655873274695109e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.864604495017895e-06, -3.936738607696835e-06, -4.029782279318338e-06, -4.137133258899153e-06, -4.222989940552836e-06, -4.159307707954591e-06, -3.513534969129711e-06, -5.489774151434453e-07, 1.537824901223866e-05, 1.116330109603661e-04, 8.975856627230806e-04, 2.732329501981080e-02, 7.241367590978277e-03, 1.492385148132585e-02, 1.927565923309655e-01, 9.846633334573616e-01, 1.236958720948200e+00, 4.992841188341913e-01, 6.166466594932710e-02, 1.537377640560276e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.362284690962361e-02, 1.332704077809808e-02, 1.289003190509471e-02, 1.225172666815056e-02, 1.136213074498019e-02, 1.030520182501593e-02, 9.711017447275332e-03, 1.122160577834222e-02, 1.336273806049736e-02, 4.221243389129971e-03, -7.732077123964041e-03, -2.662781321350605e-02, 3.593204984154385e-02, 9.838027411955029e-02, 4.214981295145909e-02, -1.099447226086190e-01, -8.102654614378033e-02, -7.728803883187409e-03, -1.218178011206720e-04, -2.310540237604538e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.128304618562962e-04, 6.694533859827657e-04, 6.288585663720104e-04, 6.448748591169401e-04, 9.316897894180667e-04, 2.291522508318819e-03, 7.307686489625057e-03, 1.869778100169820e-02, -7.851668915062839e-03, -2.388244227855888e-01, -6.587247436088535e-01, 8.024956775253238e-01, 4.382682574958283e-01, 1.434809632441507e+00, -4.347022394115307e+00, -5.130278935651614e+01, 1.295591222584354e+02, 3.795615916203713e+02, -1.718677991457563e+04, -2.153418205596310e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.675216542077421e-08, -6.344962484210301e-08, -7.430531208108590e-08, -9.275156663693721e-08, -1.261058763525234e-07, -1.913643636189123e-07, -3.335068250850004e-07, -7.269444646252886e-07, -2.311198810861815e-06, 1.907783106332847e-05, 1.445860233436853e-03, -3.739196058536106e-02, -1.780983778561086e-01, -5.145132085358390e-01, -2.042406262153856e+00, 2.856794245492142e+02, 7.176441361289592e+03, 9.865835607614060e+04, 1.410414200032062e+06, 2.634194967136671e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m11_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.496717081291689e-05, 1.018890889613741e-04, 1.115378720566664e-04, 1.239484908784936e-04, 1.356423553187639e-04, 1.283192703882121e-04, 3.664925476863162e-05, -2.038279037796990e-04, 5.699544950926228e-04, 4.998469136592920e-03, 4.665940920453342e-03, -3.179444629267423e-02, -1.652223751383155e-02, -1.607078922289332e-01, 3.766892674030494e+00, 8.273016875850379e-01, -1.709749116893773e+02, -6.749294279808367e+02, -1.256856022321005e+03, -1.784636267819797e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.336078748242108e-13, 6.193785141176817e-13, 7.650422373503559e-13, 1.029209350748011e-12, 1.550290142182765e-12, 2.674437133522874e-12, 5.072202345976926e-12, 2.556622375517001e-12, -3.928856095264251e-10, -3.275902940702605e-08, -7.013811900505927e-06, -5.947859910100603e-03, -5.753246975136766e-03, -4.403700751421608e-02, -8.050985039659469e+00, -2.391628864182142e+03, -6.243822160508278e+05, -2.766911810483484e+08, -4.699917465990121e+11, -6.735449036989033e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m11_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.018614592245227e-09, 1.145900761993682e-09, 1.354109296029520e-09, 1.712751866534746e-09, 2.375100215938305e-09, 3.719270063413245e-09, 6.893072769639790e-09, 1.793331402517620e-08, 1.003614670097914e-07, 8.119469441074753e-07, 8.247727553960753e-06, 3.883214924614513e-03, 6.701466986436558e-02, 3.083668175671993e-01, 3.771596589350964e+00, 1.635538093354557e+01, -7.248134878317755e+00, 2.033494314262339e+01, 2.138727395462253e+01, 5.590868508284658e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m11_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.578702456561984e-06, -5.923331112339186e-06, -6.420879763790096e-06, -7.119053210209543e-06, -8.008740198033284e-06, -8.778226438124823e-06, -8.215084943246068e-06, -6.992028954157096e-06, -4.574552098598655e-05, -1.922953012695580e-04, -1.564049557440802e-04, 8.630833515251944e-04, -7.913206516310112e-02, -5.070119940292933e-01, -4.906014898273571e+00, 6.855379179290545e-01, 1.618039950846233e+02, 6.775291466542715e+02, 1.364889314632864e+03, 2.048151570534365e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
