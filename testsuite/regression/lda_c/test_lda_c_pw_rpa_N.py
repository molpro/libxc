
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pw_rpa_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_rpa", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.409519107277480e-01, -1.403424243472275e-01, -1.394674455850863e-01, -1.382125056850750e-01, -1.364151231336947e-01, -1.338461807209503e-01, -1.301858351059248e-01, -1.249953022813688e-01, -1.176977041110296e-01, -1.076456046709823e-01, -9.443442148918697e-02, -8.066603244760912e-02, -7.652293422377349e-02, -7.181374562133040e-02, -6.240667764978231e-02, -4.900561413122647e-02, -3.335849149385724e-02, -1.855759526418432e-02, -7.641012361428153e-03, -1.928100463597866e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pw_rpa_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_rpa", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.509097466099783e-01, -1.509115293372810e-01, -1.502929947230606e-01, -1.502967816110887e-01, -1.494066883513848e-01, -1.494148263931255e-01, -1.481334625975526e-01, -1.481512473904386e-01, -1.463050702001068e-01, -1.463448949899596e-01, -1.436797741468384e-01, -1.437721694733393e-01, -1.399067588946947e-01, -1.401325116481303e-01, -1.344601636814040e-01, -1.350551601337895e-01, -1.264783289609449e-01, -1.282276315340775e-01, -1.142783961310249e-01, -1.202113839279491e-01, -9.502624665613384e-02, -1.167045350937382e-01, -7.679297165515757e-02, -1.279687767043708e-01, -7.291580158489053e-02, -1.257343252664270e-01, -6.902252037087714e-02, -1.156182692518890e-01, -6.065296970798709e-02, -1.034522673866769e-01, -4.866786968351432e-02, -8.717895261521671e-02, -3.466005376994628e-02, -6.478172161197433e-02, -2.065581403739058e-02, -3.732329812429822e-02, -9.018617889428563e-03, -1.416023864546532e-02, -2.349171736510420e-03, -2.585362272494133e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pw_rpa_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pw_rpa", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.527258827427191e-04, -4.650865873253188e-04, 3.527442999455228e-04, 3.730184574071845e-04, -4.924263635881201e-04, 3.730600353026137e-04, 4.042073628072290e-04, -5.345278977252521e-04, 4.043048812054272e-04, 4.535422566787504e-04, -6.013181028824889e-04, 4.537838894194707e-04, 5.348512797517439e-04, -7.118870022659823e-04, 5.354991659726454e-04, 6.769081207659141e-04, -9.064409358320245e-04, 6.788538532610160e-04, 9.463532116327020e-04, -1.279928709631730e-03, 9.532294274574315e-04, 1.518613503789711e-03, -2.091391489534177e-03, 1.549288864632588e-03, 2.922186592199554e-03, -4.186805598308340e-03, 3.112402654535790e-03, 6.788781027479965e-03, -1.092850541126960e-02, 8.610373769453948e-03, 1.407904075847908e-02, -3.558031439311904e-02, 3.888482707546857e-02, 1.373060227768297e-02, -9.279920704242461e-02, 2.127571717521053e-01, 1.705654562940715e-02, -1.365767599095938e-01, 3.409886526448860e-01, 2.970695867423582e-02, -2.399432846984415e-01, 5.552738407116219e-01, 5.977411550131306e-02, -6.712060462253820e-01, 1.628747968021489e+00, 6.960981962811512e-02, -3.104186854307523e+00, 8.793412837472063e+00, -1.912120177673164e+00, -2.460437626986085e+01, 8.813773535356314e+01, -8.244904164695943e+01, -3.680864860115131e+02, 1.772108438923489e+03, -5.761763857850895e+03, -1.411581582811943e+04, 9.956223173977813e+04, -1.312431560617761e+06, -1.906860740072355e+06, 5.669759260722474e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
