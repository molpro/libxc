
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_14_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.171378505558780e+00, -5.072596402872080e+00, -4.933983753592198e+00, -4.741503033216340e+00, -4.478044359491687e+00, -4.124244639863869e+00, -3.659878030572955e+00, -3.063280387328804e+00, -2.308348937024674e+00, -1.438610444732506e+00, -7.771774042921230e-01, -5.400435558971273e-01, -5.796380881858790e-01, -5.037857102353004e-01, -3.258849778518596e-01, -1.544105628632627e-01, -6.070324438676374e-02, -1.889380306396706e-02, -3.901478851012531e-03, -4.316257262469580e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_14_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.196738655471642e+00, -6.061308242342894e+00, -5.872075178402578e+00, -5.611213528528992e+00, -5.258903640805924e+00, -4.798145233368929e+00, -4.226714096214505e+00, -3.578439310789307e+00, -2.904040553240457e+00, -2.039687435173962e+00, -1.112031840736019e+00, -8.059070505648825e-01, -8.747714465768729e-01, -6.878345881527962e-01, -4.622079584260657e-01, -2.164483183868976e-01, -8.001005259704222e-02, -2.449256755643343e-02, -5.035580320846615e-03, -5.560034349607520e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_14_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.276940273288917e-05, -1.381588031811443e-05, -1.546572975168870e-05, -1.817026581855748e-05, -2.285190002746443e-05, -3.158001806678980e-05, -4.947337597091650e-05, -9.001672186357460e-05, -1.841778539041434e-04, -3.536641484429778e-04, -6.203695117641207e-04, -3.593024913327618e-03, -2.618707281681611e-02, -6.579700872043287e-02, -1.692151151651659e-01, -3.516945448916183e-01, -7.817073639270944e-01, -4.949087844736098e+00, -1.217146974490973e+02, -1.099426339911652e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_14_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.200069390292628e-02, 1.238623118809630e-02, 1.296506890681916e-02, 1.384976711762146e-02, 1.523473433641438e-02, 1.746682264711886e-02, 2.114804527335811e-02, 2.697484463445373e-02, 3.292199344269511e-02, 2.619647159934712e-02, 9.705297839472840e-03, 1.138010276645358e-02, 6.866221483797146e-02, 1.129328081398219e-01, 1.286098516430320e-01, 5.203674693416010e-02, 8.173138027399222e-03, 1.305330306781795e-03, 2.698112742570028e-04, 3.336942401297132e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_14_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.732732307661279e-02, -1.812147026568182e-02, -1.930974860352222e-02, -2.110902439002777e-02, -2.385839783692787e-02, -2.801988067382461e-02, -3.379473018013156e-02, -3.909013805967561e-02, -4.383734522682588e-02, -1.467111462216502e-01, -3.857434926177848e-01, -9.255010552193598e-01, -8.558092836934577e-01, -1.103172461323105e+00, -2.763285580090788e+00, -9.905952806570562e+00, -3.365048782292187e+01, -3.013146759518492e+02, -7.012544714604753e+03, -5.755395471771860e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_14_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.305195558225340e-08, 1.066157449071247e-07, 1.294996202745544e-07, 1.707904098084783e-07, 2.525266975264647e-07, 4.353603745345991e-07, 9.062343673406514e-07, 2.202142304627682e-06, 3.405479776416325e-06, -3.746608666897591e-05, -5.094068221112978e-04, -7.924792347589285e-03, 2.053531364279957e-02, 1.276843627537365e-01, -1.141837170788025e+00, -3.337761989311217e+01, -5.896310923736978e+01, 2.441804044129011e+05, 8.188486829430801e+08, 5.383922200879430e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_14_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.027121188390073e-05, -7.825269779052922e-05, -9.127447842829608e-05, -1.136681693914460e-04, -1.550448573837162e-04, -2.388439782329847e-04, -4.253367501709728e-04, -8.335962551294981e-04, -1.047208364400576e-03, 3.259500829872022e-03, 1.088615024402082e-02, 5.144525523731285e-02, 3.638802249569099e-02, -1.834948947068736e-01, 1.039591037878574e+00, 6.784881355668350e+00, 5.675025425104129e+00, -5.293302941516026e+01, -1.799547581335969e+03, -1.633929522911735e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_14_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.793525545518720e-13, -2.276408541252971e-13, -3.204117034707405e-13, -5.226235166762747e-13, -1.050506870660605e-12, -2.830036124861062e-12, -1.138753076646541e-11, -7.705734275347337e-11, -9.289596384884409e-10, -1.801501617346388e-08, -6.851828995119354e-07, -5.894653833478195e-05, -2.713073708474796e-03, -3.997643099300258e-02, -1.484196302164503e+00, -1.755297887208040e+02, -1.633167587852789e+05, -1.942781005341873e+09, -7.004289059695861e+14, -3.570976078978784e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_14_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.572737043559376e-10, 5.539197700334765e-10, 7.295169862911278e-10, 1.082919213514701e-09, 1.906386687806425e-09, 4.269337463238873e-09, 1.332610009101470e-08, 6.385806541684560e-08, 4.763815055180285e-07, 4.248096311523839e-06, 4.028808462666837e-05, 1.428301008761111e-03, 2.854894877064041e-02, 2.283266620109894e-01, 3.775252985599773e+00, 7.264281952814176e+01, 2.720421812296931e+03, 7.175740151757417e+05, 2.232255656702363e+09, 1.571118226382280e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_14_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.297872659485932e-07, 1.290603574292996e-07, 1.219361534599486e-07, 9.305790988093539e-08, -1.331953152019311e-08, -4.319548100199102e-07, -2.368211885756255e-06, -1.351776410836333e-05, -8.661120078674476e-05, -4.005771885632514e-04, -8.810770206112988e-04, -6.566216376716421e-03, -6.726368799358169e-02, -3.549622295954870e-01, -3.528009373740276e+00, -1.490602483023545e+01, -3.744395386985445e+01, -2.432832655340434e+02, -6.454812325287483e+03, -6.247543849590766e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
