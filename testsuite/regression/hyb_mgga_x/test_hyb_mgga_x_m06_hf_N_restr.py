
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m06_hf_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.574713025834238e+00, 1.493794436000430e+00, 1.373155553552829e+00, 1.199556558601982e+00, 9.722992676187755e-01, 7.349879893152833e-01, 5.785798778819067e-01, 3.953781439098719e-01, -5.866935394321320e-02, -2.030354664654289e-01, -4.550426993059880e-01, -1.648589514799567e-01, 1.981994814720338e-02, 1.575699470964693e-02, -3.180603859180590e-02, -1.208263748352173e-01, -2.234412331940890e-02, 5.887947158682376e-02, 1.546727472749440e-02, 1.729446195110955e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m06_hf_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.948733495069685e+00, 4.063981186112756e+00, 4.105401074456307e+00, 3.925346969176250e+00, 3.272957102934427e+00, 1.977295878968409e+00, 7.798687921954814e-01, 1.477211603470148e+00, 8.032627915105384e-01, 5.663009411793359e-01, 3.447957621957118e-01, 2.211655529841932e-01, 4.141285596489333e-01, 3.307892616133773e-01, 3.162391627992561e-02, 5.661408848070941e-02, -1.829840119859427e-01, 5.508654499973164e-02, 2.035377231801270e-02, 2.305535016013522e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_hf_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.020151680001946e-06, 4.283870478340223e-06, 4.679487139785149e-06, 5.287926214833537e-06, 6.274190624918666e-06, 8.065098671343114e-06, 1.191111700474825e-05, 1.982509167497865e-05, 2.669176141085325e-05, 1.733721536257069e-06, -7.694867053265366e-04, -1.646387839888547e-03, 7.191034228152969e-03, 1.450151582235682e-02, 1.391295603266209e-02, -5.210048885178609e-01, -5.505175383649831e+00, -1.344694235242515e+01, -1.722240026563141e+01, -1.905562009052819e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_hf_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.428001630135549e-02, -5.982620271999411e-02, -6.490108286216345e-02, -6.631175813866121e-02, -5.785461059419480e-02, -3.372571094120805e-02, -9.249431157177773e-03, -3.284505561890490e-02, -2.798304166625251e-02, -2.203060623732477e-02, -2.083105965394543e-02, -3.663045104012184e-02, -1.621120761571654e-01, -2.038729121330524e-01, -5.509598730087348e-02, -8.218375895228774e-02, 1.806706070903640e-01, 2.562217139699421e-02, 3.196745378234298e-04, 4.962880615880178e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_hf_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.721864447482392e-02, -3.257297442366543e-02, -8.162232308005489e-03, 3.166638731268347e-02, 8.898814238304932e-02, 1.340435207956023e-01, 3.841437838283412e-02, -1.688705679558429e-01, 4.063473930476244e-01, -6.596411027073270e-01, 6.699887671008455e-01, 4.867842785466693e-01, 9.574739403652288e-01, 3.063507946692358e+00, -1.080125480598059e+01, 2.314977678913013e+01, -2.728949222487754e+01, -1.246562573945972e+03, 2.116407265637741e+04, 1.987736489483894e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_hf_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.181749172128010e-08, -1.130266491437117e-08, -1.047165628202550e-08, -9.647925738246086e-09, -1.183557216524502e-08, -3.216940410191408e-08, -1.010065141504395e-07, 1.995186420158518e-07, 3.295048333187249e-06, 5.450267024376418e-05, 1.315896381410045e-03, 2.159616446265526e-02, 1.387758979886300e-02, 8.370018921830265e-02, 1.436447745097869e+00, 6.496447463960645e+01, -1.183685717470141e+04, -1.559023544286983e+06, -2.445743617135828e+08, -2.013058342785166e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_hf_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.358833265016912e-03, 1.017134741305184e-03, 4.379083484418471e-04, -5.254007148253833e-04, -1.944302887873619e-03, -3.111880266450211e-03, -7.793400654137996e-04, 4.543224372439990e-03, -1.066260575614253e-02, 1.456504933943057e-02, -3.434596297246924e-02, -5.548529895292877e-02, -2.624885047731175e-01, -1.620499886778476e+00, 5.853570853480193e+00, -2.297290035613994e+01, 1.077482005942777e+02, 2.187524281266300e+03, 3.353724137408267e+03, 3.867964463529969e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_hf_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.946029053169293e-14, -6.194521387850408e-14, -8.532260172400408e-14, -1.344600472288664e-13, -2.570547769620889e-13, -6.553638187173595e-13, -2.590003451451294e-12, -1.761062913541127e-11, -1.810724943942701e-10, -2.589059550049910e-09, 1.500613092366823e-06, 6.998680713269297e-05, -9.313349390560960e-04, -1.075906084703742e-02, -3.163100063506596e-01, 3.904821259532679e+02, 1.306369725923855e+06, 4.810182665843812e+09, 9.041049853826516e+13, 5.784757836198353e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_hf_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.296084113661687e-10, -4.201513565945517e-10, -5.674592625776216e-10, -8.060578955647288e-10, -1.160706629136178e-09, -1.533013987714203e-09, -2.103586906173895e-09, -1.612452914484925e-08, -1.019744240638153e-07, -1.268980253139436e-06, -3.900452029923122e-05, -1.648650419571559e-03, -1.381515335187568e-02, -8.490466099527649e-02, -8.547793031919971e-01, -5.337928534414591e+01, 3.100029058128199e+01, -1.618300793805211e+04, -6.818222290979979e+06, -6.653611596682377e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m06_hf_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m06_hf", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.995164470891706e-05, -2.107409094876907e-05, -6.183731427613864e-06, 1.830691287666999e-05, 5.391367999436795e-05, 8.231080929826336e-05, 2.243705764835979e-05, -1.002157175263357e-04, 3.079134620737030e-04, -2.661979637197992e-04, 1.676020297728663e-03, 8.341384988548533e-03, 1.716855761148656e-01, 1.266677286151698e+00, -2.899010885913256e+00, 2.408801247233860e+01, -1.306689497445231e+02, -2.132390413500116e+03, -3.558803208441985e+03, -4.378968007019866e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
