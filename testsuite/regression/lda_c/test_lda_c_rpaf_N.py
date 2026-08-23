
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_rpaf_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpaf", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.197478934107040e-01, -1.191771031137483e-01, -1.183585673986103e-01, -1.171864436301044e-01, -1.155115835615798e-01, -1.131260071937194e-01, -1.097444464108389e-01, -1.049866883454586e-01, -9.837756485325369e-02, -8.943520013779899e-02, -7.783550864283685e-02, -6.492752299742285e-02, -6.143432049156103e-02, -5.768123568840152e-02, -5.010018498382558e-02, -3.940992553552825e-02, -2.763350570938191e-02, -1.984497776359532e-02, -1.663608659527170e-02, -1.388697851610166e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_rpaf_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpaf", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.290775758661234e-01, -1.290793684790532e-01, -1.284916445948851e-01, -1.284954525867633e-01, -1.276503459715276e-01, -1.276585297005911e-01, -1.264432683233508e-01, -1.264611540684271e-01, -1.247129753242521e-01, -1.247530300119188e-01, -1.222350058434827e-01, -1.223279488148153e-01, -1.186871011179800e-01, -1.189142507640525e-01, -1.135923951697108e-01, -1.141913562842299e-01, -1.061752333525427e-01, -1.079379325285891e-01, -9.488870073870453e-02, -1.008841793834632e-01, -7.684157291714865e-02, -9.909639390311184e-02, -6.324574193916270e-02, -9.923360801712502e-02, -5.622222833908169e-02, -1.096874103333809e-01, -5.469927164982380e-02, -9.553020993670173e-02, -4.668889553127877e-02, -8.982320246773802e-02, -3.630839539226620e-02, -8.121370972062486e-02, -2.494537025865294e-02, -7.151221235789300e-02, -1.761179466140033e-02, -6.418893422919431e-02, -1.649130934216573e-02, -4.010829653528521e-02, -1.433676443019955e-02, -1.107200632563382e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_rpaf_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_rpaf", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.577860743874844e-04, -4.645613469196236e-04, 3.578046025783737e-04, 3.784392163621736e-04, -4.918286096349487e-04, 3.784810465687452e-04, 4.101922114004545e-04, -5.338131262707115e-04, 4.102903277103751e-04, 4.604427203367251e-04, -6.004053067057346e-04, 4.606858576892556e-04, 5.433189097144505e-04, -7.106163120659040e-04, 5.439709267301505e-04, 6.882710502943028e-04, -9.044625069749447e-04, 6.902296566850996e-04, 9.636874123217634e-04, -1.276370425448251e-03, 9.706119468910564e-04, 1.550379100660527e-03, -2.083703413580776e-03, 1.581293402755843e-03, 2.997826582897494e-03, -4.166234292194222e-03, 3.189842076957776e-03, 7.054446715703844e-03, -1.087408716063644e-02, 8.903782165767335e-03, 1.567098641504841e-02, -3.619073935075539e-02, 4.182235609743219e-02, 3.421398157826758e-01, -1.142155597983884e+00, 3.601846604281712e+00, 5.401655959746695e-02, -2.510837765492822e-01, 7.568927951502038e-01, 3.068804301939788e-01, -1.138254689973829e+00, 3.589209226710837e+00, 3.088826289299845e-01, -1.472397219188635e+00, 4.658509473433019e+00, 5.271787670707091e-01, -4.527829180390684e+00, 1.656370967835796e+01, 1.224728971192290e+00, -3.549308176295506e+01, 2.016377992956369e+02, 3.242918309810011e+01, -6.953594294414623e+02, 7.503822503432309e+03, 2.347363563713604e+02, -3.712655388401166e+04, 6.290450557544852e+05, -1.038538351478172e+06, -8.579878673822278e+06, 3.536628271639474e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
