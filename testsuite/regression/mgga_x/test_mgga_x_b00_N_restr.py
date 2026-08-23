
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_b00_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.233526748757131e+00, -4.236267474183395e+00, -4.231456598891485e+00, -4.207206498888969e+00, -4.138409651863951e+00, -3.974355838031860e+00, -3.621152061113369e+00, -2.952916867641167e+00, -1.997751269827778e+00, -1.272775343122486e+00, -9.658229610455541e-01, -4.925710125633651e-01, -5.306963466298646e-01, -4.616449219506833e-01, -2.780200016256492e-01, -2.165516662535105e-01, -1.662322047423413e-01, -1.101316797498844e-01, -7.338432209021344e-02, -4.987007605178537e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_b00_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.146597137831026e+00, -5.309028976279158e+00, -5.519871310244688e+00, -5.776855231078035e+00, -6.051447097467549e+00, -6.252669366853191e+00, -6.189313214420680e+00, -5.573610074898407e+00, -3.857363041005968e+00, -1.416318593486328e+00, -5.966950219346910e-01, -5.689450320466765e-01, -1.204764215411394e+00, -9.879837838390452e-01, -3.927579059424251e-01, -1.180344306946588e-01, -1.081950627038010e-01, -6.031588138602668e-02, -3.292942021411865e-02, -1.919590384054725e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.829646146836646e-07, -3.970317976215810e-07, -8.781754446355898e-07, -1.990094638447409e-06, -4.625444810606347e-06, -1.084289151076183e-05, -2.410100374585273e-05, -4.631403987644253e-05, -7.931301999997809e-05, -1.770596816272029e-04, -8.634311021280689e-04, -6.967082835794672e-03, -9.508987531048094e-03, -3.850942893113474e-02, -8.609590291708047e-02, -4.712003681113234e-01, -5.659269711061267e+00, -1.421610430723081e+02, -1.222865976826028e+04, -6.661645550405691e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.553304971370516e-05, -1.337614184380087e-04, -2.709492908242521e-04, -5.411671832058772e-04, -1.049353552949777e-03, -1.897412729999961e-03, -2.909258837114258e-03, -3.291676607624474e-03, -2.658835660095219e-03, -2.087437224134171e-03, -2.774332155985156e-03, -8.629886073153674e-03, -7.819702904246472e-03, -1.645056607726787e-02, -1.153657941735030e-02, -1.097074180589726e-02, -1.111536454704444e-02, -9.150941315141629e-03, -6.985404173767439e-03, -5.143852757215606e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.866204237464531e-02, -1.694401294331153e-02, -1.399386909849924e-02, -8.818603514544986e-03, 2.935403870693825e-04, 1.569962461555767e-02, 3.807180672567558e-02, 5.846132912223054e-02, 5.092303141421062e-02, 1.120244746772866e-02, 1.550874033637680e-04, 2.476037969931346e-02, 1.900839851066315e-01, 2.745214876455835e-01, 1.032853488125797e-01, -6.850400368954425e-03, 3.830348467040692e-02, 3.652220185020993e-02, 2.794147793394029e-02, 2.057541101166442e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.150074744501331e-03, 5.065955284421750e-03, 5.312912180793141e-03, 6.532613926300814e-03, 1.016228411576000e-02, 1.742500677563447e-02, 1.598857337360311e-02, -5.452568744767099e-02, -3.187417836427702e-01, -5.862130759465114e-01, -1.193420338579714e-01, -1.188030210715401e+00, -2.755809463097233e+00, -4.351467794687107e+00, -1.371295809344650e+01, 2.611893339296172e+00, 1.116864001037754e+01, 1.646983333573585e+02, 2.452659429344147e+04, 1.359658668807342e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.683725331012645e-09, -3.703349892366925e-09, -8.210043016769748e-09, -1.776777521639983e-08, -3.236423064834083e-08, -7.765587059083503e-09, 3.056609090771542e-07, 8.360830688552803e-07, -9.593427138179811e-07, 4.002988804461213e-06, 2.907441674751025e-04, 1.713975249918848e-02, -2.914248984648202e-02, 9.577099557689329e-02, 1.514397762673701e-02, 1.686249253270658e+01, 1.505896842872381e+02, -8.707871660595777e+04, 1.332868447161703e+09, 1.511294192851162e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.689947784749931e-07, -2.041735286887843e-06, -4.289449880616187e-06, -8.811787071256893e-06, -1.659321491313862e-05, -2.304469394737803e-05, -1.130534085199719e-05, -3.320516853365320e-05, -1.907863917020156e-04, -3.069263051768581e-04, -7.926580842015561e-04, 7.296256712670477e-03, -4.298326177063716e-02, -3.610713481800391e-02, -1.701625606010435e-01, -5.497990654690944e-01, -1.102276641193973e+01, -2.899273645544944e+02, -2.369594216644668e+04, -1.215633096430458e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.580204397515230e-04, -5.177404135283148e-04, -6.078049682138808e-04, -7.446867394167812e-04, -9.529657793517740e-04, -1.260556206514295e-03, -1.546919572128572e-03, -3.479667013084304e-04, 6.697362608108723e-03, 1.402655810061654e-02, -2.322345262779993e-04, 3.720811371310322e-02, 6.402428081347925e-01, 1.483247810446492e+00, 7.771340622459761e+00, -3.752966323394535e+00, 2.226113841153705e+01, 1.150032641710070e+03, 9.478193267779013e+04, 4.862532369158973e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.133980246173578e-15, -7.656731886188316e-15, -2.960701224529277e-14, -1.258993768339699e-13, -5.905306639710607e-13, -2.813476382033481e-12, -8.660927248131003e-12, 3.471198970624425e-11, 7.391532301836778e-10, 1.521116757192171e-08, 1.559468548062229e-06, -1.202282986313328e-04, -4.116184615333581e-03, -1.293145690080653e-02, 1.564644113779309e+00, 2.493829488127932e+02, 4.191112855859811e+05, 9.835877507954462e+09, 1.050270426175006e+16, 3.027449015713551e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.643348622483312e-13, -2.579580083588773e-12, -9.134847734914580e-12, -3.423586487412934e-11, -1.339709964634926e-10, -4.923341617433085e-10, -1.045470114022311e-09, 2.467084383590213e-09, 2.477886943010714e-08, 1.793313820535733e-07, 5.010803674402265e-06, -1.489226616664958e-04, -3.384938794571214e-03, -5.524096101307494e-03, 2.096573758671113e-01, 5.806268686046685e+00, 8.231759507703377e+02, 6.331378548793549e+05, 5.999482819556062e+09, 2.337673454550497e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.509528612271346e-12, 5.934375393437924e-13, 1.625561563502962e-11, 9.873285376707739e-11, 4.974179475650832e-10, 2.222214681720499e-09, 7.096935033795450e-09, 1.012261972650464e-08, -3.691303024832975e-09, -6.500030551650222e-07, -2.613207031314635e-05, 3.728108649019799e-04, 2.046008585572487e-02, 1.036114144146598e-01, -5.745256510720964e-01, -3.270789251429522e+01, -3.506180129755388e+03, -2.535822630391664e+06, -2.399801223640118e+10, -9.350693824152340e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.737643812287924e-10, -8.690696639974005e-10, -2.818435121002156e-09, -9.309771606140236e-09, -3.039338850370133e-08, -8.615424261862589e-08, -1.261998545882822e-07, 1.753430272151704e-07, 8.306699411727150e-07, 2.114219335050147e-06, 1.610045518045378e-05, -1.844653830280001e-04, -2.783599792951627e-03, -2.359798897414057e-03, 2.809342704093231e-02, 1.351846877064309e-01, 1.616798853266945e+00, 4.075523947477438e+01, 3.427097745980969e+03, 1.805056716643684e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.406729260915966e-10, 1.999312082621781e-10, 5.015452840463537e-09, 2.684846204333867e-08, 1.128469394730453e-07, 3.888684509758631e-07, 8.566788828057863e-07, 7.194447007971261e-07, -1.237447283516121e-07, -7.663182045075721e-06, -8.396621663678909e-05, 4.617880060803098e-04, 1.682532364931068e-02, 4.426101519800751e-02, -7.698462500917906e-02, -7.615228426659409e-01, -6.886483998750137e+00, -1.632315265478126e+02, -1.370843722984107e+04, -7.220226871169357e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_b00_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_b00", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.197393092400472e-05, 1.349045707814813e-05, 1.583941325587493e-05, 1.948496152997224e-05, 2.491357927182171e-05, 3.151742194889129e-05, 3.239361439694721e-05, -8.791784123154273e-06, -1.964389633628367e-04, -3.157721684834240e-04, 6.685179195550781e-04, -6.136881040485134e-03, -2.993182439064203e-01, -1.270227631954775e+00, -4.542832307034389e+00, 1.030646664822572e+01, 5.072622708072305e+01, 6.646761138035696e+02, 5.483626784686191e+04, 2.888090773173284e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
