
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_karasiev_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.172577953896510e-01, -1.166571808975035e-01, -1.157953751861201e-01, -1.145602575146513e-01, -1.127932635542866e-01, -1.102721204155070e-01, -1.066896117939470e-01, -1.016316450864745e-01, -9.457159979270102e-02, -8.495191279901630e-02, -7.227275788480927e-02, -5.828141483150252e-02, -5.448088604206806e-02, -5.063534676701330e-02, -4.266872972533108e-02, -3.159845812176166e-02, -1.926782724025918e-02, -8.504917273103135e-03, -2.186019510477491e-03, -2.581096662884453e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_karasiev_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.270723900908375e-01, -1.270747367591765e-01, -1.264602654674328e-01, -1.264652466165029e-01, -1.255806632445786e-01, -1.255913563749506e-01, -1.243171513870718e-01, -1.243404840611663e-01, -1.225027791166647e-01, -1.225549102875774e-01, -1.198973997171056e-01, -1.200179528000591e-01, -1.161512009643023e-01, -1.164443513366820e-01, -1.107340175150275e-01, -1.115012557658073e-01, -1.027515863171353e-01, -1.049842059735638e-01, -9.035225851271510e-02, -9.781355520605699e-02, -7.013786896716170e-02, -9.685761900393504e-02, -5.136514668292649e-02, -1.107605160388962e-01, -4.803878729876398e-02, -1.083957397321823e-01, -4.505138976174278e-02, -9.842271715515580e-02, -3.838283462069000e-02, -8.665153846578098e-02, -2.913541351659524e-02, -7.154338394117332e-02, -1.891788190454721e-02, -5.169264620072613e-02, -9.389485493530719e-03, -2.775530341677201e-02, -2.723921198571338e-03, -8.291746800010923e-03, -3.396826184714344e-04, -1.081989700853881e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_karasiev_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_karasiev", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.825199449192261e-04, -5.939963052945102e-04, 4.825438737869143e-04, 5.099691009246202e-04, -6.284091619903624e-04, 5.100230781891008e-04, 5.521239957950269e-04, -6.813453932752293e-04, 5.522504488395457e-04, 6.187291003999656e-04, -7.651920150964264e-04, 6.190419006840779e-04, 7.283219755127507e-04, -9.036804603921017e-04, 7.291586376957835e-04, 9.193479172919893e-04, -1.146549038936668e-03, 9.218516889947906e-04, 1.280485957220885e-03, -1.610507056159975e-03, 1.289288719425412e-03, 2.044087109221223e-03, -2.611245569828251e-03, 2.083062596454022e-03, 3.907347513782981e-03, -5.167649050837333e-03, 4.146412544741111e-03, 9.036794455893267e-03, -1.326180997590817e-02, 1.129150515352048e-02, 1.909218027064056e-02, -4.194225657731269e-02, 4.897971572409616e-02, 1.631582484772017e-02, -9.209708571275639e-02, 2.094639992411242e-01, 1.972155223415979e-02, -1.309936438204750e-01, 3.212956009619100e-01, 3.667474711819220e-02, -2.344041360300427e-01, 5.409184198586839e-01, 7.969286887183590e-02, -6.394022415183979e-01, 1.552835851075611e+00, 1.718155024729648e-01, -2.827687169341728e+00, 8.024193943024766e+00, -6.010855474232335e-01, -2.210411564221868e+01, 8.094112705848514e+01, -4.468983238898120e+01, -3.427756994438870e+02, 1.807769126517326e+03, -2.572576553497787e+03, -1.138636862640859e+04, 1.111782433763377e+05, -2.845005262237181e+05, -1.050166043609868e+06, 2.803039463395918e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
