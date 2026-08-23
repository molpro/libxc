
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ow_lyp_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow_lyp", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.631250538390381e-02, -4.625690154050723e-02, -4.617524491288553e-02, -4.605426057827237e-02, -4.587274353264717e-02, -4.559555684374442e-02, -4.516173486112265e-02, -4.445943103357362e-02, -4.326906278540598e-02, -4.109634718785084e-02, -3.600364796479862e-02, -2.504394876180589e-02, -2.280648143720071e-02, -2.173285268997609e-02, -1.755667038987794e-02, -1.103278807697238e-02, -4.522893888624508e-03, -9.253451973420543e-04, -7.132244177750778e-05, -1.745175130844257e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ow_lyp_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow_lyp", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.721147867845736e-02, -4.721373354730347e-02, -4.717095155238579e-02, -4.717575766119855e-02, -4.711044685853544e-02, -4.712082564775100e-02, -4.701853364451043e-02, -4.704137417509394e-02, -4.687520378973909e-02, -4.692686228883670e-02, -4.664254076135595e-02, -4.676410410879277e-02, -4.624041480065708e-02, -4.654345327261596e-02, -4.547285527975874e-02, -4.629420365048120e-02, -4.376405838691786e-02, -4.627207640901893e-02, -3.909666809236696e-02, -4.801452239518558e-02, -2.562429350777913e-02, -5.943694295945599e-02, -1.009062501443698e-02, -8.424532206575397e-02, -8.777480163094322e-03, -8.434977234290475e-02, -9.019700216601933e-03, -7.705952332180524e-02, -7.373347512579982e-03, -6.872673786599995e-02, -4.522259112622684e-03, -5.532342342223797e-02, -1.775811004969057e-03, -3.513290063978110e-02, -3.416450090156765e-04, -1.480512513282961e-02, -2.478755709600689e-05, -3.522565984473320e-03, -5.880138172274943e-07, -4.066672319812003e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ow_lyp_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ow_lyp", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.136492929143009e-04, -5.207537882964396e-04, 5.136739853668127e-04, 5.453300338745047e-04, -5.530430787731391e-04, 5.453859654803577e-04, 5.942574316240699e-04, -6.029476702760921e-04, 5.943892463520876e-04, 6.721894474296826e-04, -6.825300307804838e-04, 6.725183056941382e-04, 8.019148358426695e-04, -8.152595694585683e-04, 8.028052407353589e-04, 1.031825307904405e-03, -1.051290797182005e-03, 1.034536527283660e-03, 1.476951452118999e-03, -1.511218686088930e-03, 1.486719748039152e-03, 2.450673717379714e-03, -2.531429325598373e-03, 2.495420652947321e-03, 4.944197258458970e-03, -5.240050573890213e-03, 5.231483013728552e-03, 1.229816983113330e-02, -1.423931138229256e-02, 1.516057110253775e-02, 2.831492561810604e-02, -4.658547718395872e-02, 6.718664239234493e-02, 2.681976843840678e-02, -9.040247005593192e-02, 2.430981965747676e-01, 3.421168852432920e-02, -1.271743530858770e-01, 3.626653351286810e-01, 6.574480686469254e-02, -2.363490480018386e-01, 6.245634408663508e-01, 1.592846247787166e-01, -6.452476387670857e-01, 1.708626162365149e+00, 4.922338603784275e-01, -2.679017774953986e+00, 7.456169671265688e+00, 1.881672781858168e+00, -1.736866827497463e+01, 5.219045847436384e+01, 8.889079143231230e+00, -1.895585083619632e+02, 6.330925869710746e+02, 6.232223073698286e+01, -4.453827464310839e+03, 1.654210544996970e+04, 1.030422831640824e+03, -3.579194186717214e+05, 1.404892264569955e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
