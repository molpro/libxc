
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_x_n12_sx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_n12_sx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.928943014438919e+00, -2.894719396881632e+00, -2.846094377457300e+00, -2.777257894599763e+00, -2.680112896575157e+00, -2.543030404472526e+00, -2.348033427515692e+00, -2.065037139021316e+00, -1.653575582084906e+00, -1.164653264191762e+00, -8.256458685460790e-01, -4.925607645207762e-01, -3.983535331818755e-01, -3.539522463299519e-01, -2.851665076407747e-01, -2.236952308427019e-01, -1.285581245547845e-01, -7.807654951618374e-02, -2.326179887285918e-02, -2.787925458194475e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_x_n12_sx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_n12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.249256160394481e+00, -2.220430600664950e+00, -2.182694051885713e+00, -2.136033985275509e+00, -2.084340047434418e+00, -2.040424896292780e+00, -2.033239286793595e+00, -2.102029330859275e+00, -2.176137200516315e+00, -1.651941006362555e+00, -7.290798446067864e-01, -5.081164194160094e-01, -4.590409102302440e-01, -3.579664373046816e-01, -2.084291068944177e-01, -1.588163015969599e-01, -1.635721896154942e-01, -8.817525508520023e-02, -3.020565997773111e-02, -3.707955874468487e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_n12_sx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_n12_sx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.748441490386275e-05, -1.845628428210487e-05, -1.990924177946484e-05, -2.210191033900109e-05, -2.541986751675302e-05, -3.030562548338295e-05, -3.645084754561615e-05, -3.788335196837851e-05, -2.957070352441334e-06, 6.269357473038590e-05, -8.429198049744720e-04, -1.204544876936331e-02, -2.580505490603371e-02, -4.278140171322695e-02, -1.579383633887471e-01, -7.179531487543116e-01, 8.489874632633536e-01, -1.222768333659062e+01, -3.413168753744868e+01, -4.384679636439567e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_n12_sx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_n12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.360161739918490e-04, -1.688642064022605e-04, 9.736780041668074e-04, 3.052744110372665e-03, 7.133388069045841e-03, 1.588765964343557e-02, 3.642336081742470e-02, 8.601563251330753e-02, 1.643839540573922e-01, -2.112074101418266e-01, -1.459130655697430e+00, -2.355671239692332e-01, -4.363700460352343e-01, -7.776958814102914e-01, -2.531445391914032e+00, 2.774142627371736e+01, -3.268861323336881e+00, 8.768741905282991e+01, -2.962558833394754e+04, -3.160147823937171e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_n12_sx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_n12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.660907037210444e-08, -3.785551967003242e-08, -5.902377707138068e-08, -1.030812012302594e-07, -2.077975658491293e-07, -5.033622275563662e-07, -1.535999032050159e-06, -6.079098204740562e-06, -2.745548178577755e-05, 2.826341366951749e-05, 3.262625920945315e-03, -1.473183152224586e-03, 3.999579560681430e-02, 7.698100076210969e-02, 1.194225875465243e+00, -1.685282049366175e+02, -4.062379881087392e+03, -1.302319900272955e+06, -4.697461123181301e+08, -4.535826771800368e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_x_n12_sx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_x_n12_sx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.601712162606918e-12, 2.005096999421588e-12, 2.765400712058969e-12, 4.376000625073680e-12, 8.402608605242070e-12, 2.109939563435909e-11, 7.602659376244130e-11, 4.300017928326023e-10, 3.658454434375156e-09, -7.271595385351299e-09, -5.870472829424383e-06, 2.054429940816647e-03, 1.211458501460489e-02, 7.080014857912993e-02, 2.108354002412798e+00, 1.328898263803047e+03, 3.360892654476552e+05, 4.447649246634845e+09, 1.731663681567847e+14, 1.280631508113063e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
