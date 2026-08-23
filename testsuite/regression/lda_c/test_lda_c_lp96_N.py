
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_lp96_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_lp96", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.721200064515577e-02, -5.714868804704272e-02, -5.705546031414764e-02, -5.691678159957771e-02, -5.670747655855261e-02, -5.638495950846686e-02, -5.587310215575566e-02, -5.502615505212924e-02, -5.354286994589670e-02, -5.077480431116992e-02, -4.574452174894088e-02, -4.049908033227581e-02, -3.772448288076340e-02, -3.250737815199814e-02, -2.042555978144624e-02, 6.597199028460845e-03, 6.211593133837634e-02, -3.395175823551565e-02, -9.623436310194554e+00, -9.756231007378922e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_lp96_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_lp96", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.823577328156226e-02, -5.823577328156226e-02, -5.819333324455090e-02, -5.819333324455090e-02, -5.813083163261188e-02, -5.813083163261188e-02, -5.803783963576206e-02, -5.803783963576206e-02, -5.789744510654640e-02, -5.789744510654640e-02, -5.768100910955269e-02, -5.768100910955269e-02, -5.733725297544785e-02, -5.733725297544785e-02, -5.676775886901813e-02, -5.676775886901813e-02, -5.576827275977863e-02, -5.576827275977863e-02, -5.389573030569440e-02, -5.389573030569440e-02, -5.046755626364334e-02, -5.046755626364334e-02, -4.685623822484629e-02, -4.685623822484629e-02, -4.493015542597244e-02, -4.493015542597244e-02, -4.127716231988304e-02, -4.127716231988304e-02, -3.264606757807834e-02, -3.264606757807834e-02, -1.226242763999246e-02, -1.226242763999246e-02, 3.919191993587393e-02, 3.919191993587393e-02, 1.318682792786667e-01, 1.318682792786667e-01, -2.362238840923643e+00, -2.362238840923643e+00, -3.172368192357227e+02, -3.172368192357227e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_lp96_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_lp96", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.831787435301909e-06, -3.831787435301909e-06, -3.831787435301909e-06, -4.157222826397365e-06, -4.157222826397365e-06, -4.157222826397365e-06, -4.673732404717525e-06, -4.673732404717525e-06, -4.673732404717525e-06, -5.529550044439643e-06, -5.529550044439643e-06, -5.529550044439643e-06, -7.037991834756371e-06, -7.037991834756371e-06, -7.037991834756371e-06, -9.943448814096893e-06, -9.943448814096893e-06, -9.943448814096893e-06, -1.629932990576780e-05, -1.629932990576780e-05, -1.629932990576780e-05, -3.297921722418169e-05, -3.297921722418169e-05, -3.297921722418169e-05, -8.958447474951494e-05, -8.958447474951494e-05, -8.958447474951494e-05, -3.590853142476545e-04, -3.590853142476545e-04, -3.590853142476545e-04, -2.013321792890349e-03, -2.013321792890349e-03, -2.013321792890349e-03, -7.104749259622701e-03, -7.104749259622701e-03, -7.104749259622701e-03, -1.220110638316549e-02, -1.220110638316549e-02, -1.220110638316549e-02, -2.891566813198506e-02, -2.891566813198506e-02, -2.891566813198506e-02, -1.322566463395544e-01, -1.322566463395544e-01, -1.322566463395544e-01, -1.277012190567652e+00, -1.277012190567652e+00, -1.277012190567652e+00, -2.770078677801747e+01, -2.770078677801747e+01, -2.770078677801747e+01, -1.819214683733684e+02, -1.819214683733684e+02, -1.819214683733684e+02, 7.440551905454571e+06, 7.440551905454571e+06, 7.440551905454571e+06, 5.615206169310471e+11, 5.615206169310471e+11, 5.615206169310471e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
