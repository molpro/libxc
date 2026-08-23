
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_br89_1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.417182490252653e+00, -3.405262139072349e+00, -3.383368618797526e+00, -3.343443938235120e+00, -3.272051053795579e+00, -3.148564697535426e+00, -2.945268994532889e+00, -2.635562661498678e+00, -2.218020361115835e+00, -1.730111432343859e+00, -1.201887524792127e+00, -6.593439601744560e-01, -5.181174181887256e-01, -4.617727738530886e-01, -3.695273977340024e-01, -2.578439767146395e-01, -1.689156300787764e-01, -1.101601030093501e-01, -7.338436541673164e-02, -4.987007605681051e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_br89_1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.779987773142868e+00, -4.842282607427467e+00, -4.905506887912666e+00, -4.945791403694839e+00, -4.909511609109419e+00, -4.695243421190821e+00, -4.177370834058352e+00, -3.379625286597333e+00, -2.535497196818941e+00, -1.777146694212418e+00, -1.175671115676971e+00, -9.115235848896273e-01, -7.869050325483049e-01, -6.310544491458763e-01, -3.996293368811883e-01, -2.290523607183306e-01, -1.180599377155408e-01, -6.042501973251939e-02, -3.292958399121038e-02, -1.919590385923185e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.476838377875831e-07, -3.191482494171883e-07, -7.021674857676628e-07, -1.581517298280537e-06, -3.657127457162459e-06, -8.589956919131198e-06, -1.960258444599981e-05, -4.133660366098249e-05, -8.805795592196237e-05, -2.406811076641886e-04, -1.074469247492135e-03, -9.325973048861453e-03, -9.283598993025688e-03, -3.852009406252746e-02, -1.144334751977533e-01, -5.610493737831308e-01, -5.750625220373796e+00, -1.421977326081649e+02, -1.222866698813007e+04, -6.661645551076949e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.289641551934760e-05, -1.075221752760944e-04, -2.166443886250358e-04, -4.300625934903070e-04, -8.296758145214008e-04, -1.503168559081675e-03, -2.366249664585730e-03, -2.937915406915520e-03, -2.951994935515899e-03, -2.837499190481337e-03, -3.452429008623384e-03, -1.155176231284124e-02, -7.634354947946920e-03, -1.645512203806938e-02, -1.533372471735074e-02, -1.306265494826798e-02, -1.129479578839435e-02, -9.153303029590602e-03, -6.985408297989514e-03, -5.143852757733924e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.115856620773904e-04, 4.300887011043778e-04, 8.665775545001433e-04, 1.720250373961228e-03, 3.318703258085603e-03, 6.012674236326699e-03, 9.464998658342919e-03, 1.175166162766208e-02, 1.180797974206360e-02, 1.134999676192535e-02, 1.380971603449353e-02, 4.620704925136496e-02, 3.053741979178768e-02, 6.582048815227751e-02, 6.133489886940294e-02, 5.225061979307193e-02, 4.517918315357741e-02, 3.661321211836241e-02, 2.794163319195806e-02, 2.057541103093570e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.251099344422199e-02, -1.465890717651243e-02, -1.757785941843855e-02, -2.126553889688919e-02, -2.513125932919099e-02, -2.782100890759718e-02, -3.265681667959903e-02, -5.292474422318486e-02, -8.161423648327075e-02, -1.317690089455388e-01, -2.773283149840070e-01, -6.627552563913545e-01, -1.051268656009045e+00, -1.448338008060158e+00, -2.888244307494532e+00, -6.425397520745736e+00, -1.494153006700755e+01, 1.549519194246362e+02, 2.452497761580349e+04, 1.359658655481206e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.510076345871296e-09, -3.296630015694379e-09, -7.226366756310290e-09, -1.535483984078432e-08, -2.681968552726638e-08, 1.900379016723749e-09, 3.430827364762720e-07, 1.450179037793510e-06, 3.073181490300985e-06, 8.936122406643333e-06, 1.207885974205593e-04, 1.951837619770458e-02, -1.148688587550963e-02, 2.353026839205599e-01, 5.858802806154058e-01, 3.533835440835327e+00, -1.284144446156193e+02, -9.085401236870622e+04, 1.332785023704161e+09, 1.511294187207988e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.362367852473827e-07, -1.748942823905007e-06, -3.633933806049211e-06, -7.338481967092857e-06, -1.339871456077855e-05, -1.684736385982006e-05, 2.208727951474842e-06, 2.039533146901830e-05, -7.309266879556916e-05, -3.760101985416213e-04, -1.760826821598549e-03, 5.524795716476051e-03, -2.801342289150878e-02, 2.347707368414494e-02, -1.503608408435945e-01, -1.039822079656753e+00, -1.175346909048238e+01, -2.902437603432043e+02, -2.369600426035111e+04, -1.215633097000452e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.344947140989531e-06, 6.995771295620027e-06, 1.453573522419684e-05, 2.935392786837143e-05, 5.359485824311419e-05, 6.738945543928023e-05, -8.834911805899368e-06, -8.158132587607320e-05, 2.923706751822766e-04, 1.504040794166485e-03, 7.043307286394195e-03, -2.209918286590420e-02, 1.120536915660351e-01, -9.390829473657976e-02, 6.014433633743780e-01, 4.159288318627013e+00, 4.701387636192952e+01, 1.160975041372817e+03, 9.478401704140443e+04, 4.862532388001809e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.722488214798742e-15, -6.154752824263318e-15, -2.367303877187812e-14, -1.000515445139848e-13, -4.669055612884585e-13, -2.228892624322004e-12, -7.044377053854598e-12, 3.098144244378403e-11, 8.206511687880300e-10, 2.067687361928043e-08, 1.940630807940878e-06, -1.609347698559961e-04, -4.018619987169839e-03, -1.293503824934310e-02, 2.079630473936921e+00, 2.969355644275565e+02, 4.258768449086796e+05, 9.838415993693674e+09, 1.050271046260597e+16, 3.027449016018611e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.169493812059787e-13, -2.073558019384319e-12, -7.303999566461406e-12, -2.720705411390486e-11, -1.059247336616317e-10, -3.900370334789462e-10, -8.503345508760380e-10, 2.201943290516968e-09, 2.751095081328435e-08, 2.437690798658513e-07, 6.235534532050308e-06, -1.993443686259888e-04, -3.304706655901069e-03, -5.525625991840325e-03, 2.786639236993868e-01, 6.913414400290684e+00, 8.364641773571470e+02, 6.333012578308728e+05, 5.999486361684601e+09, 2.337673454786052e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.467797524823915e-12, 8.294232077537277e-12, 2.921599826584563e-11, 1.088282164556194e-10, 4.236989346465266e-10, 1.560148133915785e-09, 3.401338203504152e-09, -8.807773162067872e-09, -1.100438032531374e-07, -9.750763194634051e-07, -2.494213812820123e-05, 7.973774745039553e-04, 1.321882662360428e-02, 2.210250396736130e-02, -1.114655694797547e+00, -2.765365760116273e+01, -3.345856709428588e+03, -2.533205031323491e+06, -2.399794544673840e+10, -9.350693819144208e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.209748291455875e-10, -6.985890388323855e-10, -2.253551400010484e-09, -7.398424453642314e-09, -2.403066086924536e-08, -6.825312526274427e-08, -1.026448247851666e-07, 1.564986608822496e-07, 9.222583765629681e-07, 2.873904701106924e-06, 2.003569702247890e-05, -2.469210186117748e-04, -2.717621003335558e-03, -2.360452440351459e-03, 3.734008678211600e-02, 1.609618529942284e-01, 1.642898242452695e+00, 4.076575776296182e+01, 3.427099769358833e+03, 1.805056716825570e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.838993165823498e-10, 2.794356155329542e-09, 9.014205600041935e-09, 2.959369781456925e-08, 9.612264347698143e-08, 2.730125010509771e-07, 4.105792991406664e-07, -6.259946435289984e-07, -3.689033506251872e-06, -1.149561880442770e-05, -8.014278808991558e-05, 9.876840744470993e-04, 1.087048401334223e-02, 9.441809761405837e-03, -1.493603471284640e-01, -6.438474119769138e-01, -6.571592969810781e+00, -1.630630310518473e+02, -1.370839907743533e+04, -7.220226867302280e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_1_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.535597266329399e-09, -1.117742462131817e-08, -3.605682240016774e-08, -1.183747912582770e-07, -3.844905739079257e-07, -1.092050004203908e-06, -1.642317196562666e-06, 2.503978574115994e-06, 1.475613402500749e-05, 4.598247521771079e-05, 3.205711523596623e-04, -3.950736297788397e-03, -4.348193605336893e-02, -3.776723904562335e-02, 5.974413885138560e-01, 2.575389647907655e+00, 2.628637187924312e+01, 6.522521242073891e+02, 5.483359630974133e+04, 2.888090746920912e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
