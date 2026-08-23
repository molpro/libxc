
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_m06_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.047859833640617e+00, -4.921041584601811e+00, -4.742603648277770e+00, -4.498529747915808e+00, -4.182597650529765e+00, -3.809075107857822e+00, -3.394594050426107e+00, -2.845774908375124e+00, -2.131625139048525e+00, -1.477386428639721e+00, -9.033467288053015e-01, -5.253321810317312e-01, -5.742440863848975e-01, -4.827551078433247e-01, -3.280653958632816e-01, -1.895064308552479e-01, -2.130643591567425e-01, -1.659725634092275e-01, -3.879948225149465e-02, -4.315738087538460e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_m06_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.590611394394993e+00, -7.464001400577361e+00, -7.216911462124821e+00, -6.754133670191706e+00, -5.964206031569616e+00, -4.876170656608747e+00, -4.016252762645484e+00, -3.850485486341516e+00, -2.682169359184920e+00, -1.789704700076270e+00, -9.743431411372409e-01, -8.095459852350495e-01, -9.186475739456532e-01, -7.045302941088313e-01, -4.067064398436079e-01, -2.212949980476203e-01, 2.733409247598418e-02, -1.866999872899954e-01, -5.134711092738603e-02, -5.753757111955493e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m06_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.118523369688043e-06, -5.507035468717026e-06, -6.113858748106706e-06, -7.101393663889056e-06, -8.815571632248719e-06, -1.209708740411668e-05, -1.920007000205744e-05, -3.610423137189661e-05, -8.209470008768134e-05, -2.482921992059070e-04, -1.390728902824314e-03, -1.107403660258607e-02, -1.778109983554015e-02, -3.581531029232282e-02, -1.186765468036857e-01, -4.160019185509121e-01, 1.472304585388395e-01, 2.877603350017778e+00, 4.570764413250486e+00, 5.199639001919161e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m06_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.263871893875864e-02, 3.384695912113562e-02, 3.386473282614188e-02, 3.083607825665472e-02, 2.223587521272917e-02, 8.329672997706828e-03, 1.772453111884680e-03, 1.738487905989359e-02, 1.256120700897527e-02, 1.143984389674823e-02, 9.180894595641207e-03, 2.152812849630309e-02, 7.998921191136153e-02, 9.191353120878509e-02, 5.909003135767482e-02, 3.160424704816641e-02, -2.417079329447407e-01, -3.127805709773628e-02, -3.867824579673654e-04, -6.005633037172128e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m06_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.485326216489695e-03, -1.414054763700894e-02, -3.004711301831473e-02, -5.228046202557279e-02, -7.672767817123130e-02, -7.980338928685367e-02, -1.178477507787046e-02, 1.745006733460602e-02, -1.780894599305047e-01, -1.826862271829931e-01, 4.885381651014208e-02, -1.329934468985394e+00, -1.619865770246460e+00, -3.204174036954516e+00, -1.683127137981473e+00, 3.252505831262436e+00, 3.099994278209296e+02, 1.050142003508459e+03, -5.592272741197944e+04, -4.963361003131580e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m06_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.450686415951907e-08, 2.725181024116329e-08, 3.212770072261859e-08, 4.178970044975485e-08, 6.384247764612708e-08, 1.210579033917279e-07, 2.655603458502355e-07, 4.655340974296921e-07, 3.998863816496295e-07, -3.146224254516649e-05, -7.613403219507928e-04, 2.295224385903824e-02, 4.862079958860248e-02, 1.146387815654820e-01, -3.264715342669286e-01, -1.294107494687580e+02, -6.477269150724103e+03, 9.296434470515203e+04, 4.475634599121144e+07, 3.989469192498063e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m06_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.155339068460760e-04, -7.367678420884015e-05, 2.912867945962845e-04, 8.063493782444318e-04, 1.371208519027556e-03, 1.389449015477726e-03, -4.624143710705799e-04, -1.563562794370838e-03, 3.112615113182738e-03, 4.181005291853363e-03, 1.095171099327971e-03, 5.298566519609986e-02, 2.964028969183385e-01, 1.049787134741648e+00, 3.810391353783037e-03, 9.949461070519698e+00, -1.581405123705363e+02, -2.637475492975971e+03, -4.006277248188863e+03, -4.623999954492833e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m06_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.014245966816200e-13, 1.286194192401072e-13, 1.808498206706763e-13, 2.948922960785559e-13, 5.950274316750001e-13, 1.632398779297181e-12, 6.936717918070296e-12, 5.328482551011262e-11, 9.014094727646915e-10, 4.342863743560046e-08, 6.978820968213069e-06, 7.100526446516848e-04, 3.759771593476690e-03, 4.375429846257554e-02, 3.148226745255483e+00, 1.224796248160482e+03, 1.019139019258982e+06, 2.533255417567348e+08, -9.514626887663391e+12, -7.308769532588716e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m06_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.012693615273363e-10, 1.243036167405388e-10, 1.535321371925166e-10, 1.763851989494278e-10, 1.282814193811919e-10, -2.296468681065100e-10, -1.283227910956149e-09, -1.023039921654816e-09, -2.595206123693523e-08, -5.315328578398806e-07, -2.215357001145881e-05, -6.934938391532534e-04, -4.306840862806635e-04, -5.162714458514885e-03, -4.050983388015131e-01, -3.526528861153607e+01, -6.749312598498864e+03, -2.830117623265942e+05, -2.994507746650960e+07, -2.390657900634600e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_m06_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.988591670140149e-06, -1.020810630409830e-07, -9.231984047649964e-06, -2.199113002920303e-05, -3.568261228295161e-05, -3.510354074690540e-05, 1.233310206791132e-05, 3.594949567836407e-05, -8.081614447551125e-05, -9.183356220931887e-05, 1.671731241178133e-04, -4.872617604382938e-03, -1.434067964340468e-01, -6.892931004757997e-01, 8.197873509681816e-02, -2.913281168084692e+00, 2.618666312461130e+02, 2.691537926857729e+03, 4.391261725063153e+03, 5.396044881176026e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
