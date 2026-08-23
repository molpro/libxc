
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_ob_pw_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pw", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.171793140225358e-01, -1.165794405112029e-01, -1.157186199349422e-01, -1.144847442931954e-01, -1.127191508925995e-01, -1.101991527891181e-01, -1.066162859475249e-01, -1.015531072565503e-01, -9.447506764924388e-02, -8.481772300393092e-02, -7.224839758745503e-02, -5.894237146180202e-02, -5.507964582842494e-02, -5.093400503386233e-02, -4.264809812997247e-02, -3.131201750528009e-02, -1.912716830307747e-02, -8.869789022330619e-03, -2.478865318522524e-03, -2.674074463092874e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_ob_pw_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pw", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.269817208626225e-01, -1.269835160611299e-01, -1.263713698143611e-01, -1.263751837002782e-01, -1.254945035975395e-01, -1.255027012564223e-01, -1.242353484965468e-01, -1.242532687537988e-01, -1.224282414429810e-01, -1.224683869782948e-01, -1.198358094088055e-01, -1.199290106106977e-01, -1.161149444273377e-01, -1.163429027419529e-01, -1.107539828735409e-01, -1.113558051550910e-01, -1.029174516013472e-01, -1.046918887201331e-01, -9.095966608730972e-02, -9.700848942031040e-02, -7.200324133664661e-02, -9.428896510748991e-02, -5.399228528602099e-02, -1.066978323566361e-01, -5.032380069576756e-02, -1.048307377607614e-01, -4.682804148845194e-02, -9.527781633655577e-02, -3.932474149984925e-02, -8.438101730896617e-02, -2.909104076658408e-02, -7.060138337695046e-02, -1.838197564652966e-02, -5.286362738323146e-02, -9.574985988475150e-03, -2.938685896387679e-02, -3.281846294786180e-03, -1.015880343105360e-03, -3.673754761703781e-04, 7.964223832330369e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_ob_pw_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_ob_pw", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.561644340708353e-04, -4.673690839352794e-04, 3.561830232088534e-04, 3.767315829356111e-04, -4.948832107111299e-04, 3.767735563604084e-04, 4.083534797434985e-04, -5.372585877592886e-04, 4.084519512341170e-04, 4.583990800390570e-04, -6.044957012648435e-04, 4.586431676185395e-04, 5.409434533109441e-04, -7.158350828919545e-04, 5.415982967723929e-04, 6.853305598078923e-04, -9.118257028349590e-04, 6.872989068443331e-04, 9.597120892625914e-04, -1.288309049177653e-03, 9.666777463168122e-04, 1.544273596916572e-03, -2.107087585599710e-03, 1.575416805007060e-03, 2.985945237372357e-03, -4.224745526970434e-03, 3.179785708214181e-03, 7.001996742386517e-03, -1.105547747536095e-02, 8.870521481509004e-03, 1.482393743195393e-02, -3.608561431905803e-02, 4.051360500203431e-02, 1.467702647946299e-02, -9.248621624830819e-02, 2.170047631927833e-01, 1.849651031984772e-02, -1.356158365758935e-01, 3.469903304096136e-01, 3.340170885225479e-02, -2.389875096911875e-01, 5.714849342675523e-01, 7.507802738341755e-02, -6.676356665181979e-01, 1.696654432857643e+00, 1.900478429540899e-01, -3.092960295831247e+00, 9.463834097963035e+00, 2.029956959639653e-02, -2.576910398994809e+01, 1.105063757692803e+02, -2.877500655832536e+01, -4.293857561756695e+02, 2.322808099369361e+03, -3.156199768987323e+03, -3.564939719425539e+03, -2.238866131336968e+05, -3.435166084394175e+05, 8.445257120590698e+05, -4.956837768905308e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
