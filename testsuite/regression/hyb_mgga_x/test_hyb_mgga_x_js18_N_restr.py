
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_js18_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.207928562142952e+00, -4.124534610459858e+00, -4.007740277711537e+00, -3.846080032756600e+00, -3.626073115378713e+00, -3.333852824229806e+00, -2.958995856187191e+00, -2.501311367755429e+00, -1.979213354590447e+00, -1.430993674801750e+00, -9.185683955508411e-01, -6.221361854526619e-01, -5.191494848890309e-01, -4.449675617581026e-01, -3.254618609476386e-01, -2.033280963644294e-01, -1.078686956983796e-01, -4.824816582174613e-02, -1.774491197975157e-02, -4.666581166558400e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_js18_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.499899905814045e+00, -5.382042238155792e+00, -5.216680459977564e+00, -4.987181005501246e+00, -4.673610178332218e+00, -4.254695451602297e+00, -3.712969967247758e+00, -3.045480265867211e+00, -2.283628001509263e+00, -1.526153582788208e+00, -9.975334075731991e-01, -7.029477656396961e-01, -6.756095031037780e-01, -5.298147464290057e-01, -3.524561177488914e-01, -1.984522725352864e-01, -9.150073735997688e-02, -3.243138400533176e-02, -9.883468754312065e-03, -2.420244594745369e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_js18_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.485528668272534e-06, -1.722768439683910e-06, -2.107054773489491e-06, -2.760784771929142e-06, -3.950725251388630e-06, -6.325861920115946e-06, -1.168949829692198e-05, -2.592164702880905e-05, -7.212948411338363e-05, -2.569089012328348e-04, -6.521654714090610e-04, -9.189895504172779e-04, -1.017712906241173e-02, -5.020435147628879e-02, -1.325112188890151e-01, -6.048887715856871e-01, -5.465045487707334e+00, -1.104317603231049e+02, -5.835712245519703e+03, -1.268539450969787e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_js18_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.302649368834785e-04, 9.689185612633495e-04, 1.166759345331513e-03, 1.448219147494594e-03, 1.847086893438146e-03, 2.409390948231494e-03, 3.195998187822362e-03, 4.280339683442828e-03, 5.701801967923329e-03, 6.887019628423700e-03, 7.482725219340976e-04, -9.572848194537536e-03, 6.217297878360912e-03, 4.473528889088847e-02, 3.938792988771177e-02, 2.930633714097671e-02, 2.230330714027733e-02, 1.494765158025687e-02, 7.361987250653048e-03, 2.256544365795651e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_js18_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.738902274266387e-03, -5.027433095714667e-03, -5.471575624615145e-03, -6.174789451798537e-03, -7.331975380421935e-03, -9.335583915324887e-03, -1.302738986905688e-02, -2.028347076993412e-02, -3.534066169983509e-02, -7.366558285512236e-02, -1.656797771233212e-01, -4.771258217557549e-01, -6.293711458171368e-01, -1.067849503674109e+00, -1.670168018536220e+00, -5.622639394437211e+00, -7.590406118356606e+01, -1.451903492713995e+03, -5.931779501671503e+04, -1.063271408343618e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_js18_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.019891938149576e-07, -2.227454394425822e-07, -2.563306089909248e-07, -3.135367463221849e-07, -4.184283462939811e-07, -6.322441300295485e-07, -1.140097381364074e-06, -2.645379239050281e-06, -8.687814013934334e-06, -3.503385663925010e-05, 2.506666595831121e-04, -5.359256682766529e-03, 9.436036153805923e-03, 6.434166984216555e-02, -1.129607033454516e+00, 6.718899286245442e+00, 9.177956765927698e+03, 7.661024503661585e+06, 4.196449303251203e+10, 5.981733464018122e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_js18_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.261271858410874e-04, 3.398813766555066e-04, 3.606910607733515e-04, 3.928643185839311e-04, 4.441517112143336e-04, 5.294780040680324e-04, 6.798715704471795e-04, 9.638332692352190e-04, 1.513738140182768e-03, 1.974027971610576e-03, -4.155197841811028e-03, 1.508081862126330e-02, 2.741089584939305e-02, 5.188384806647722e-02, 7.276621479897204e-01, -7.603994270019749e-01, -6.944180282825941e+01, -1.990732597176398e+03, -1.022392052517037e+05, -2.027579914527383e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_js18_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.708915135968631e-12, 7.919479693598425e-12, 1.005280412192764e-11, 1.416377580660107e-11, 2.317577288726925e-11, 4.697232317354005e-11, 1.291772814742760e-10, 5.470620294809070e-10, 4.171931952374759e-09, 5.355811412495831e-08, -5.302188961976728e-06, -3.842479626355757e-05, -1.316870459986373e-02, -4.754062635004541e-02, 3.750739483177032e+00, -5.248231042891337e+01, -1.588589579787400e+06, -4.501914016073013e+10, -3.030757064387318e+16, -3.370989236555407e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_js18_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.006129929493876e-08, -1.116060335518459e-08, -1.295396894376913e-08, -1.604413967672712e-08, -2.180142435123068e-08, -3.378522613594101e-08, -6.291741221726842e-08, -1.501416841414779e-07, -4.770129394601536e-07, -1.043613737725994e-06, 7.179137407448480e-05, 6.823273225241217e-04, 2.361897277702947e-02, 2.229004229440602e-01, -1.065029361172318e-01, 5.020387547839121e+01, 1.676692719891998e+04, 1.473342166196888e+07, 9.286424438502597e+10, 1.472590461555552e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_js18_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_js18", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.488982474587071e-05, 1.551638701931047e-05, 1.646141873103761e-05, 1.791428321370987e-05, 2.020573895449426e-05, 2.393864119092795e-05, 3.023366079326689e-05, 4.093056478114109e-05, 5.511858615996625e-05, 5.951645058044417e-06, -7.217165194399979e-04, -1.594636028526662e-03, -3.831820971515222e-02, -4.241139647328847e-01, -5.113621928482911e-01, -6.490797080841279e+00, -1.431364814672492e+02, -4.100449781158456e+03, -2.378754345359516e+05, -5.269150400458368e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
