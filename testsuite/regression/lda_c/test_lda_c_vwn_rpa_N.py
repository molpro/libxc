
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_vwn_rpa_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_rpa", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.410728648519166e-01, -1.404662075340095e-01, -1.395953562147443e-01, -1.383464728536000e-01, -1.365580475268321e-01, -1.340024896141373e-01, -1.303623976580591e-01, -1.252028732201241e-01, -1.179522105347911e-01, -1.079548308563352e-01, -9.456568225936141e-02, -7.981074253072690e-02, -7.566241437837769e-02, -7.122838030988472e-02, -6.204902995633835e-02, -4.888924722468268e-02, -3.344674032537886e-02, -1.856907393859667e-02, -7.264107241360514e-03, -1.420471256887572e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_vwn_rpa_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_rpa", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.509844946136106e-01, -1.509868532892473e-01, -1.503696633639455e-01, -1.503746704944857e-01, -1.494859438879196e-01, -1.494966943338776e-01, -1.482160259528446e-01, -1.482394885897940e-01, -1.463913750105050e-01, -1.464438125695910e-01, -1.437688087506850e-01, -1.438901248089875e-01, -1.399922668433385e-01, -1.402874677840918e-01, -1.345176142849361e-01, -1.352909692190727e-01, -1.264163586433449e-01, -1.286698825535926e-01, -1.137475543083708e-01, -1.212917176172778e-01, -9.294094338018556e-02, -1.199908578740014e-01, -7.351470770956726e-02, -1.336256453652660e-01, -6.992234201288750e-02, -1.309711849978975e-01, -6.648458342479603e-02, -1.203814270542869e-01, -5.883209782469006e-02, -1.073234494807389e-01, -4.775141889351477e-02, -8.975233471588702e-02, -3.453409692080420e-02, -6.593366909541741e-02, -2.077143977387648e-02, -3.694414281573117e-02, -8.769480576612778e-03, -1.179569954110245e-02, -1.813107302027799e-03, -1.342796948528877e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_vwn_rpa_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_vwn_rpa", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.850334609690992e-04, -5.969910245597596e-04, 4.850575545569415e-04, 5.126699813705611e-04, -6.316459679023039e-04, 5.127243364503824e-04, 5.551172326553139e-04, -6.849634850519113e-04, 5.552445919847056e-04, 6.221945965481576e-04, -7.694346635766895e-04, 6.225097145117363e-04, 7.325883697682087e-04, -9.090049722241843e-04, 7.334315252791448e-04, 9.250672088336413e-04, -1.153902291342905e-03, 9.275916873342192e-04, 1.289091371798051e-03, -1.622115115754158e-03, 1.297973388169390e-03, 2.059120670040705e-03, -2.633285698349324e-03, 2.098487284060601e-03, 3.938402544709229e-03, -5.221322373069884e-03, 4.180189564529540e-03, 9.104408239305598e-03, -1.344000961787070e-02, 1.138783863804081e-02, 1.909926876936000e-02, -4.268385755030455e-02, 4.936708525944086e-02, 1.570165010825945e-02, -9.411907621913608e-02, 2.109733725382923e-01, 1.858494293207563e-02, -1.341230757662819e-01, 3.230857741601018e-01, 3.394548822207680e-02, -2.405927913105355e-01, 5.415736709693975e-01, 6.743938156494168e-02, -6.592397879107762e-01, 1.538843277516521e+00, 7.547688221003418e-02, -2.932685514594182e+00, 7.777582810897933e+00, -1.927818370204331e+00, -2.305901749931590e+01, 7.513215120082447e+01, -8.343199999096741e+01, -3.651113054170355e+02, 1.509442083112058e+03, -6.138463462887508e+03, -1.328373076609737e+04, 5.097765982517588e+04, -1.263048973826194e+06, -1.169670034118795e+06, -1.998624025898923e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
