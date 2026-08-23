
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_rge2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_rge2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.984876176916038e-02, -6.881824263607327e-02, -6.733937981329118e-02, -6.521918869757094e-02, -6.218412701977629e-02, -5.785114741693981e-02, -5.170239808473858e-02, -4.312122544546830e-02, -3.177359048322858e-02, -1.940430746946302e-02, -1.467755068241775e-02, -4.660747449333885e-02, -5.453925088451864e-02, -3.998586104860299e-02, -2.280865896285020e-02, -7.017108160994383e-03, -5.548409191452035e-04, -6.485876680259778e-06, -6.590860035529408e-09, -2.115241936101030e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_rge2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_rge2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.358278021077871e-01, -1.349382026392812e-01, -1.336477572047512e-01, -1.317677941841087e-01, -1.290100878458166e-01, -1.249183929229579e-01, -1.187283402577245e-01, -1.090582631895208e-01, -9.337058485292772e-02, -6.961827585604725e-02, -5.694364473937338e-02, -8.890854298314764e-02, -8.139771780221847e-02, -7.935806913103269e-02, -6.443917958840949e-02, -3.034065750881935e-02, -3.227202315360909e-03, -4.134726769390885e-05, -4.306161563068531e-08, -1.399281928322710e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_rge2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_rge2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.920668335461869e-07, 7.392761534826366e-07, 8.126616416289834e-07, 9.305968756837940e-07, 1.129251103495938e-06, 1.486612176429547e-06, 2.190126907736925e-06, 3.749756345625414e-06, 7.745995531668796e-06, 2.022708797667169e-05, 1.127562866977136e-04, 3.149259321605485e-03, 8.050068806961996e-03, 1.353802242568021e-02, 3.811854814242043e-02, 1.237920963135856e-01, 1.795973999895461e-01, 7.691337168532013e-02, 9.563634919057746e-03, 2.385233106173308e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_rge2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_rge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.394240057241454e-04, -2.592622245078127e-04, -2.906692588309686e-04, -3.425528311715420e-04, -4.337269877269668e-04, -6.090497817972563e-04, -9.935352463206282e-04, -2.011067895683879e-03, -5.431895605005481e-03, -1.909310448809064e-02, -6.886500700021594e-02, -1.233839067725782e-02, 1.119626545602595e-02, -3.495578093004655e-02, -6.822732666833146e-01, -6.381783524650176e+00, -1.499901711846066e+01, -6.863176740909284e+00, -8.336689313765467e-01, -2.034716438924600e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_rge2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_rge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.233690433853373e-09, 2.589432241490584e-09, 3.201219225582775e-09, 4.339291437204652e-09, 6.710342352436791e-09, 1.252921106270301e-08, 3.063303407481782e-08, 1.099448281522832e-07, 6.684368819849827e-07, 7.616092744405050e-06, 1.821383964626207e-04, -2.043649960123698e-04, -1.341270380903249e-02, -2.631062668188265e-03, 5.626796364994906e-01, 3.347002856263940e+01, 1.007169248268194e+03, 1.514883869936579e+04, 2.187066874472861e+05, 4.086929180232072e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_rge2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_rge2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.016491828844206e-14, -1.097283578679507e-13, -1.454966068584619e-13, -2.181738365477848e-13, -3.901316064605064e-13, -8.969969871057511e-13, -2.949580431638609e-12, -1.610806976112693e-11, -1.794529112922742e-10, -5.335918230746465e-09, -7.926518016109810e-07, -5.947064460688305e-04, -5.356030401152193e-03, -3.409090922239250e-02, -1.359336871993050e+00, -2.705474114246256e+02, -8.833706270578869e+04, -4.250247012009589e+07, -7.288065331397546e+10, -1.044998955967846e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
