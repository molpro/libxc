
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_lda_xc_lda0_N_2_zk():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_lda0", 2)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.210823035135495e+00, -3.147311103971148e+00, -3.058287102005797e+00, -2.934908327441979e+00, -2.766670402743175e+00, -2.542523252811254e+00, -2.253585148575807e+00, -1.898185960781741e+00, -1.489510504799040e+00, -1.066003790948649e+00, -7.114031120186399e-01, -5.481353767685883e-01, -4.846358533575660e-01, -3.933684821858578e-01, -2.755506324625490e-01, -1.623951695526315e-01, -7.708532130707148e-02, -2.714994145924965e-02, -6.220655002419022e-03, -7.507846017309301e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_lda_xc_lda0_N_2_vrho():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_lda0", 2)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.258820633784635e+00, -4.258788198758162e+00, -4.174295502934720e+00, -4.174227730056081e+00, -4.055834438876399e+00, -4.055692199753167e+00, -3.891695298275164e+00, -3.891394822928165e+00, -3.667957702896639e+00, -3.667316794784846e+00, -3.370050149511741e+00, -3.368663106789994e+00, -2.986462673335040e+00, -2.983393735775678e+00, -2.515718463915791e+00, -2.508693623189447e+00, -1.977262551219146e+00, -1.960336839751248e+00, -1.427015547354905e+00, -1.383415571410348e+00, -9.802417192415234e-01, -8.670884806158561e-01, -7.673217249555530e-01, -5.705112624791977e-01, -6.765086130229448e-01, -4.964921430180876e-01, -5.470688515377630e-01, -4.118797760712540e-01, -3.801113625880027e-01, -2.895363617031404e-01, -2.208785925627162e-01, -1.715819779101119e-01, -1.029079711897609e-01, -8.476699372508631e-02, -3.575440153273476e-02, -3.249599549210755e-02, -8.189680005565952e-03, -7.909353757864182e-03, -9.949130196781227e-04, -8.848225584393804e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_lda_xc_lda0_N_2_v2rho2():
    # Prepare the input
    inp = test_data["N"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_lda_xc_lda0", 2)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.522927905497440e-02, -3.499107971908064e-04, -1.522951662207336e-02, -1.585923527889087e-02, -3.705024896317402e-04, -1.585976287711673e-02, -1.680995859913272e-02, -4.022155450510446e-04, -1.681116725018126e-02, -1.827506747281893e-02, -4.525327622668348e-04, -1.827796279861968e-02, -2.060136697802440e-02, -5.358494585661926e-04, -2.060876325026674e-02, -2.445604778923534e-02, -6.825000592318001e-04, -2.447677367276813e-02, -3.124235209892857e-02, -9.641732868756706e-04, -3.130870175131139e-02, -4.425078809873811e-02, -1.576664893718580e-03, -4.450794224510347e-02, -7.221161686084025e-02, -3.160496613866905e-03, -7.351865194795409e-02, -1.404052672350267e-01, -8.268602436499337e-03, -1.499096658155078e-01, -3.026414117654235e-01, -2.701190806028273e-02, -3.942394811068162e-01, -4.984739297808671e-01, -7.069833561648528e-02, -9.553633693323371e-01, -6.459340413317800e-01, -1.042433596662266e-01, -1.279710158386886e+00, -1.003219503058405e+00, -1.836521237519373e-01, -1.894877525643876e+00, -2.140448314210747e+00, -5.167139202364496e-01, -3.995848135637655e+00, -6.704862413553752e+00, -2.409305507241803e+00, -1.219075455057434e+01, -3.447830943103487e+01, -1.913416384045159e+01, -5.549249571797378e+01, -3.497250853140729e+02, -2.761382110834593e+02, -4.330396079628194e+02, -9.028459240376627e+03, -8.584903037313594e+03, -1.476853989846169e+04, -8.342668248878466e+05, -7.561778346167454e+05, -5.430208569356577e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
