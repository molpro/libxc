
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b1wc_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1wc", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.672387035206403e+00, -3.602355144451248e+00, -3.504242029681268e+00, -3.368368244762843e+00, -3.183296352855155e+00, -2.937117277244623e+00, -2.620489813541880e+00, -2.232052802587424e+00, -1.785765679944416e+00, -1.317744491112580e+00, -8.798514187512577e-01, -5.985956072881443e-01, -5.247319696993389e-01, -4.304870118390537e-01, -3.046314583998480e-01, -1.871253215711428e-01, -1.007129151492675e-01, -3.503081093838535e-02, -7.363344280769088e-03, -8.149312683242995e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b1wc_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1wc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.674475363137931e+00, -4.578516463236467e+00, -4.444043878598494e+00, -4.257755638217709e+00, -4.003932299930370e+00, -3.666273181295729e+00, -3.232367183151533e+00, -2.701957349158480e+00, -2.097460807718387e+00, -1.468254797506940e+00, -9.511163431430706e-01, -7.685722353852648e-01, -6.852892365223406e-01, -5.537182933906750e-01, -3.787176624181116e-01, -1.931376204474972e-01, -1.112259598794518e-01, -4.545887051268532e-02, -9.799313349413639e-03, -1.086547194246827e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1wc_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1wc", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.164920602418374e-06, -2.339191589273590e-06, -2.612990928707221e-06, -3.059646733239242e-06, -3.827887546703899e-06, -5.250283779837157e-06, -8.164150494227655e-06, -1.501519362427326e-05, -3.466543154716768e-05, -1.140878490799576e-04, -5.809910049338366e-04, -1.419892903332223e-03, -5.791850134665866e-04, -3.870472088091086e-03, -2.055196586466267e-02, -2.930880116321409e-01, -1.555786959635149e+00, -2.812146345139673e+00, -5.031086317499416e+00, -5.884272057868102e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1wc_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1wc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.998637217380715e-03, -1.043572901421368e-02, -1.109549169368049e-02, -1.211178296199717e-02, -1.372217611400365e-02, -1.637510702439821e-02, -2.098447068807905e-02, -2.966286857749572e-02, -4.924706022352484e-02, -1.167487997934221e-01, -3.310380115362221e-01, -4.484745425438543e-01, -5.418810378866252e-01, -9.215302078081207e-01, -2.649348146804960e+00, -1.196901532278278e+01, 4.089983873401404e+01, -3.416887721734047e+02, -1.118614691461074e+04, -9.378144868228328e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1wc_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1wc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.628823576801366e-08, 1.838073350583133e-08, 2.183644241259282e-08, 2.788310742063829e-08, 3.934435166650243e-08, 6.355357882228227e-08, 1.225636251746456e-07, 2.987026170195565e-07, 1.152994875819763e-06, 1.490022966384489e-05, 3.819033123222319e-04, 5.526630483449256e-03, 1.058727771370349e-02, 5.281955821258492e-02, 9.400393448744822e-01, 3.777201878300287e+01, -5.287831621054602e+03, -2.905379729033303e+05, -6.814930347411065e+07, -6.091205565370516e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b1wc_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b1wc", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.366235338273806e-14, -1.281403004616579e-14, -9.563099655255929e-15, 2.132086286095139e-15, 4.761545249593288e-14, 2.589775572467843e-13, 1.559628496326195e-12, 1.339291707752698e-11, 1.854071465187008e-10, 3.996485539103709e-09, 2.155001128724489e-07, -2.807529011131432e-04, -4.123483036518038e-03, -1.520028774872664e-02, -6.247179107301566e-01, -3.581031555268996e+01, 4.992309604778240e+05, 9.164530432786977e+08, 2.494867447547514e+13, 1.717559462614716e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
