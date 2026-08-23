
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_b97_1p_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1p", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.782958061221089e+00, -3.709649172442142e+00, -3.606974740054395e+00, -3.464859134124465e+00, -3.271482942347963e+00, -3.014800050800184e+00, -2.686204439324554e+00, -2.287523601035424e+00, -1.841432830720704e+00, -1.394607297579410e+00, -9.525908097875457e-01, -6.132365609402317e-01, -5.342591916085569e-01, -4.407625748458401e-01, -3.210865614258734e-01, -2.098727792988952e-01, -1.131675968830133e-01, -3.542953190028289e-02, -6.034060292648425e-03, -5.767140703345732e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_b97_1p_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1p", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.901094388037797e+00, -4.800158132377073e+00, -4.658388897438150e+00, -4.461301650941776e+00, -4.191264215075832e+00, -3.828744408654780e+00, -3.355661122512336e+00, -2.762083562961781e+00, -2.059960682489265e+00, -1.329791229343676e+00, -8.380577351245635e-01, -7.772357787877877e-01, -6.935020686020460e-01, -5.506625710854266e-01, -3.572033655949639e-01, -1.925825871643151e-01, -1.156302659334548e-01, -4.715492377731054e-02, -8.248583084243958e-03, -7.757701513079770e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_1p_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1p", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.293942014741279e-06, -1.416860421689790e-06, -1.615818617812416e-06, -1.954946309940882e-06, -2.577395976846285e-06, -3.846549488896172e-06, -6.845381067704966e-06, -1.551358260480280e-05, -4.801124703693089e-05, -2.089989422267394e-04, -1.132688661833010e-03, -2.401941806069321e-03, -3.202455833946613e-03, -1.055449991245003e-02, -6.133918076882604e-02, -4.659092655369795e-01, -2.676926218456507e+00, -4.355331207815373e+00, -2.714138663457753e+00, -1.106417059278362e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_1p_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.032498302604739e-02, -1.084992380418172e-02, -1.165760120183926e-02, -1.293826459826090e-02, -1.506002727026255e-02, -1.880894191205609e-02, -2.608991188563683e-02, -4.229724929837984e-02, -8.509801725536952e-02, -2.062496688044737e-01, -4.797427717267403e-01, -5.275603054705322e-01, -5.242649993951841e-01, -1.155836973119605e+00, -3.063029418580848e+00, -7.592512616243097e+00, 4.329297341351564e+01, -3.332432976356808e+02, -1.059670458720986e+04, -6.967838199084551e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_1p_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.454184114272639e-08, 1.729515365447413e-08, 2.212830526929415e-08, 3.136048058849376e-08, 5.122514565768088e-08, 1.017287874113952e-07, 2.637278795265544e-07, 9.789272592762661e-07, 5.758318214443230e-06, 5.473825714709739e-05, 8.615742589367820e-04, 1.059221218782962e-02, -2.782515932115585e-03, 1.310658851036903e-01, 1.389550967341550e+00, 1.740574580572620e+01, -5.557498795713872e+03, -5.134213271702373e+05, -3.930989318082945e+07, -1.184241854674603e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_b97_1p_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_b97_1p", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.447758787470540e-14, -7.176933429334486e-14, -1.052924662164566e-13, -1.787122714411349e-13, -3.690792015214148e-13, -9.918699426413506e-13, -3.794757295416445e-12, -2.322168082995971e-11, -2.529219147588703e-10, -3.488828165544879e-09, 1.183863517549497e-07, -4.552742608069461e-04, 4.687534816996359e-03, -2.544528861917176e-02, -2.344467433673031e-01, 1.596437604639895e+02, 5.942171761877703e+05, 1.516112474137949e+09, 1.372968610216521e+13, 3.231137325346651e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
