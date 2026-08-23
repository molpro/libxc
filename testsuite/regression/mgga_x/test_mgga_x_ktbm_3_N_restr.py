
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_3_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.859894862097867e+00, -4.764498345227572e+00, -4.630774736855298e+00, -4.445410301610510e+00, -4.192503011746370e+00, -3.854995462871551e+00, -3.417871884081623e+00, -2.872637353606935e+00, -2.220488547923400e+00, -1.494258549607470e+00, -8.709331386729453e-01, -5.824749199655118e-01, -5.717966417899383e-01, -4.881430839111184e-01, -3.322569340244427e-01, -1.773964386618009e-01, -7.516401422204792e-02, -2.388578402496916e-02, -4.954407557757881e-03, -5.489343311225709e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_3_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.075387792981202e+00, -5.943726311313743e+00, -5.759244802357046e+00, -5.503763333643089e+00, -5.155970048926639e+00, -4.694416012300599e+00, -4.105345437310575e+00, -3.399358501919508e+00, -2.631249565059361e+00, -1.843399989431036e+00, -1.112294308255210e+00, -8.021815419581619e-01, -8.235495685283739e-01, -6.401086674829433e-01, -4.173284517950829e-01, -2.191247519318843e-01, -9.166452688402403e-02, -2.901221938788234e-02, -5.996513220961059e-03, -6.628345557590122e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_3_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.042963443034804e-06, -8.710612670283779e-06, -9.765680481386534e-06, -1.150171863028116e-05, -1.452587861960826e-05, -2.022838145140843e-05, -3.218600749977786e-05, -6.069759728129606e-05, -1.361556970122884e-04, -3.246554259873418e-04, -7.839741490176664e-04, -4.079900155054830e-03, -1.953983394520244e-02, -4.810712280545557e-02, -1.475747303655059e-01, -4.577558963344553e-01, -1.841829750043340e+00, -1.741951810681879e+01, -4.428990267404884e+02, -3.894848994482366e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_3_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.423935919123809e-03, 8.634485323383290e-03, 8.947200244171435e-03, 9.417940801413827e-03, 1.013962073301589e-02, 1.127149734703976e-02, 1.308289977126114e-02, 1.591596646169513e-02, 1.919343884281847e-02, 1.722597087525957e-02, 7.714681801842499e-03, 6.655312840095989e-03, 4.530108525484251e-02, 6.939897731855564e-02, 8.124215055322588e-02, 4.646458530733078e-02, 1.434852695741947e-02, 4.267821692730382e-03, 9.780542691391011e-04, 1.182094706986034e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_3_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.553473520200857e-02, -1.628532166956479e-02, -1.742521524685335e-02, -1.919504069624758e-02, -2.202458949430590e-02, -2.671036644728016e-02, -3.470665522703508e-02, -4.811189888756336e-02, -6.818754290921515e-02, -1.186236227979171e-01, -2.697651643184445e-01, -7.423749198454332e-01, -8.677889338672505e-01, -1.336298940141659e+00, -2.586333117639148e+00, -6.467247477955714e+00, -3.041502406263757e+01, -3.079693274057577e+02, -7.251863864881536e+03, -5.944020702431167e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_3_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.873901455940079e-08, 6.743949233343420e-08, 8.218459775994112e-08, 1.089892421336687e-07, 1.627519761977298e-07, 2.861106266989556e-07, 6.223656402612286e-07, 1.711045562923478e-06, 4.864731859390734e-06, -7.686440092223598e-06, -3.297491152803040e-04, -4.072064394953832e-03, 3.092877947244106e-02, 1.583940893756264e-01, 4.682245836520060e-02, -2.427249904337270e+01, -5.062608609042312e+02, 3.205579466798733e+04, 1.822202708198520e+08, 1.247263996915023e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_3_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.045579213662907e-05, -3.365553147795469e-05, -3.884462745559412e-05, -4.770150206976603e-05, -6.393291158388138e-05, -9.663673593568632e-05, -1.702348154299588e-04, -3.452278276467677e-04, -5.810176836279582e-04, 8.768205683152398e-04, 5.117771727832616e-03, 3.148309841974213e-02, 4.655476609724602e-02, -5.201699362275142e-02, 2.856210726092597e-01, 3.225244029380823e+00, 5.218002446335543e+00, -5.866673961880259e+00, -3.996874032257913e+02, -3.785143691845555e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_3_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.569775916178731e-14, -8.340551526621168e-14, -1.174482253199232e-13, -1.917423755015173e-13, -3.861653822711556e-13, -1.045066746478108e-12, -4.254640492151700e-12, -2.976284898992325e-11, -3.960284084003976e-10, -9.706766082667640e-09, -4.738393302153450e-07, -4.227747715331817e-05, -1.276373151951151e-03, -1.762756459338342e-02, -7.742774220657670e-01, -1.174445618696728e+02, -1.175920600582177e+05, -1.412529358970989e+09, -5.098524628635776e+14, -2.599386520518485e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_3_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.773361810864546e-10, 2.152492327244844e-10, 2.843457154609426e-10, 4.240708440508717e-10, 7.521513131273125e-10, 1.706015558002788e-09, 5.453540468562752e-09, 2.751328183040589e-08, 2.330923966219977e-07, 2.755839370580392e-06, 3.641407575326964e-05, 1.165870620586637e-03, 1.428514649535554e-02, 1.106758469963654e-01, 2.303040757025542e+00, 6.731621412842722e+01, 3.654689682064587e+03, 1.147785921859027e+06, 3.612839212081469e+09, 2.515242712417195e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_3_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_3", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.274178249609399e-08, -5.532935518457168e-08, -7.855710252668390e-08, -1.259396706106815e-07, -2.368452793231584e-07, -5.496513216606786e-07, -1.679043054539694e-06, -7.198000616511101e-06, -4.219241634129795e-05, -2.277970528957831e-04, -6.410215689635436e-04, -4.320652599358194e-03, -4.847978369809634e-02, -2.070125555752637e-01, -1.944537291114025e+00, -1.168884847452204e+01, -4.933004493838305e+01, -4.775314187737060e+02, -1.347012191002609e+04, -1.287324109973206e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
