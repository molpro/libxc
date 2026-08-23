
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_x_erf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_x_erf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.996204656951631e+00, -3.912162884895516e+00, -3.794385587237460e+00, -3.631205097894615e+00, -3.408791562687063e+00, -3.112664141713843e+00, -2.731343364998072e+00, -2.263122667627945e+00, -1.726293964667655e+00, -1.172580135447343e+00, -7.075808640278185e-01, -4.765128501537603e-01, -3.985124645308374e-01, -2.952583800662172e-01, -1.642597865001658e-01, -5.568006414453743e-02, -7.397538324971803e-03, -2.764037333898764e-04, -2.490747481877675e-06, -3.369152819605851e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_x_erf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_x_erf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.383049308581954e+00, -5.270959763231549e+00, -5.113873511066427e+00, -4.896225337267329e+00, -4.599561925723752e+00, -4.204552593866575e+00, -3.695850342233239e+00, -3.071100867251159e+00, -2.354529335294231e+00, -1.614742761541355e+00, -9.919897247929249e-01, -6.809994635403261e-01, -5.754570130764999e-01, -4.348771784958362e-01, -2.534987002113976e-01, -9.477015490899314e-02, -1.411766112813326e-02, -5.498763488331568e-04, -4.980346939174939e-06, -6.738286642713448e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_x_erf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_x_erf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.032837018009156e-02, -1.075849620694945e-02, -1.140799651673543e-02, -1.240974643890997e-02, -1.400240590585256e-02, -1.664705725928750e-02, -2.132024609327650e-02, -3.034181420220100e-02, -5.004575023552305e-02, -1.003013354628507e-01, -2.376555041515320e-01, -4.459255316038760e-01, -5.835381631116086e-01, -8.944667445525559e-01, -1.876442196627030e+00, -5.225535938926198e+00, -1.266023103603866e+01, -1.684378974858545e+01, -1.742649165450011e+01, -1.745296449553856e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
