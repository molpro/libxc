
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_10_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.903160947142789e+00, -4.806361581855092e+00, -4.670701050902562e+00, -4.482721288183416e+00, -4.226417481272279e+00, -3.884826551659915e+00, -3.443666672187159e+00, -2.897045947434561e+00, -2.253069736730096e+00, -1.550223039313280e+00, -9.403763346834108e-01, -6.240081261517378e-01, -5.725587147477990e-01, -4.913385461033513e-01, -3.422671886169988e-01, -1.909028988407704e-01, -8.288415067929804e-02, -2.644610901321644e-02, -5.479691406932881e-03, -6.064665890276610e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_10_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.115552434985682e+00, -5.980957451481332e+00, -5.792267168222677e+00, -5.530745782619229e+00, -5.174272157782041e+00, -4.700205100319719e+00, -4.093099944029587e+00, -3.362265051312601e+00, -2.571483513890894e+00, -1.815212960567750e+00, -1.148215562679811e+00, -7.839577070591891e-01, -8.068556572216394e-01, -6.274066953993114e-01, -4.066767354401432e-01, -2.321455650593454e-01, -1.048145191065343e-01, -3.376913158830088e-02, -6.990946335297185e-03, -7.725603089074328e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_10_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.187284053683931e-06, -9.940703014185709e-06, -1.112928740952207e-05, -1.307996206158920e-05, -1.646432194598175e-05, -2.280450630021112e-05, -3.595247553964438e-05, -6.667267237096729e-05, -1.447142620218431e-04, -3.222782776309909e-04, -6.919861387840225e-04, -3.817174968337584e-03, -2.092506624235164e-02, -5.160255922507934e-02, -1.492302722556630e-01, -3.942921135236656e-01, -1.171237585235809e+00, -9.177680849411116e+00, -2.292084753776517e+02, -2.033293937376461e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_10_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.059937832618635e-02, 1.081128150850155e-02, 1.112165892816040e-02, 1.157924804029297e-02, 1.225885288356444e-02, 1.327317578499458e-02, 1.477033748985749e-02, 1.679261221386880e-02, 1.828776449139928e-02, 1.437923134594609e-02, 4.847344963932009e-03, -4.208120800624798e-05, 3.973296406170008e-02, 6.498369649210829e-02, 6.744186681700276e-02, 3.497183972193428e-02, 8.925503075330368e-03, 2.249918153265609e-03, 5.062074709937902e-04, 6.171098090428533e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_10_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.635192491375630e-02, -1.716174979837686e-02, -1.839412958018286e-02, -2.031330652838249e-02, -2.339510970683685e-02, -2.853011897349400e-02, -3.735249102476172e-02, -5.200143229008305e-02, -6.939674408886025e-02, -8.039723134768299e-02, -1.459212845541681e-01, -5.309936492591530e-01, -9.960676081125206e-01, -1.475880360409985e+00, -2.099340886116115e+00, -3.696576687374063e+00, -3.237927048671317e+01, -3.748613219345939e+02, -8.953666628433341e+03, -7.347468796549046e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_10_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.551636284088961e-08, 7.508018234050705e-08, 9.123857068794466e-08, 1.204732079685143e-07, 1.786675312451337e-07, 3.105038655860936e-07, 6.615026614205733e-07, 1.739305480295232e-06, 4.229859670393616e-06, -1.745609569852541e-05, -4.227127567873762e-04, -5.569013291050228e-03, 2.744253033127480e-02, 1.440736816686165e-01, -3.193798864959035e-01, -2.990229071190686e+01, -3.179229135351738e+02, 1.599898671878398e+05, 5.780241451845427e+08, 3.819100827131038e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_10_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.775144206112533e-05, -3.037331497088895e-05, -3.457578748864010e-05, -4.163000951380381e-05, -5.425633062910906e-05, -7.887219519883428e-05, -1.318320132317517e-04, -2.503182657066926e-04, -3.908143624461555e-04, 5.533122089034991e-04, 2.087382484972785e-03, 1.554731070751821e-02, 1.067690743785009e-01, 6.367983636663391e-02, 2.574796259594588e-01, 1.797388826567921e+00, 1.150256774211557e+00, -3.999987215919418e+01, -1.276948194269160e+03, -1.159108001456504e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_10_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.651749832266003e-14, -1.097340298350950e-13, -1.543051033833028e-13, -2.513681216532683e-13, -5.045161996149359e-13, -1.357646773349168e-12, -5.472740509533469e-12, -3.757562701894024e-11, -4.814712728210953e-10, -1.100579100588911e-08, -5.055726311886584e-07, -4.288002049673106e-05, -1.494803861435259e-03, -2.114464034252790e-02, -8.814216796587118e-01, -1.297167635082619e+02, -1.383646948626380e+05, -1.704397196789219e+09, -6.167448505484748e+14, -3.143296700627623e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_10_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.672263818796363e-10, 3.228040211807424e-10, 4.234477797155652e-10, 6.250607172087865e-10, 1.091905709893257e-09, 2.421284438868882e-09, 7.483800484175574e-09, 3.593345795231060e-08, 2.841120206838991e-07, 3.082115503507302e-06, 3.731115188280570e-05, 1.247663074701729e-03, 1.769664265760648e-02, 1.373321536098241e-01, 2.621253334562996e+00, 6.776173049131170e+01, 3.043949032176260e+03, 8.514783998031731e+05, 2.650720163721978e+09, 1.855234250938600e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_10_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_10", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.120741822740872e-07, -4.709461672011872e-07, -5.706537350708655e-07, -7.520656275378145e-07, -1.117872834992673e-06, -1.971867979837243e-06, -4.417231267733386e-06, -1.353476605633110e-05, -5.695283524366563e-05, -2.363421453025357e-04, -5.376386801527439e-04, -2.707094690400589e-03, -7.431964889873605e-02, -3.125426607423707e-01, -2.094014569644973e+00, -1.054655190447695e+01, -3.783176605499912e+01, -3.149002679851876e+02, -8.700070513599740e+03, -8.365955788458775e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
