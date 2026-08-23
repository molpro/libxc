
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_tau_hcth_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.481327678964725e+00, -4.387761938218383e+00, -4.256821985235151e+00, -4.075823768694660e+00, -3.830094933816976e+00, -3.505168920891655e+00, -3.091633142242553e+00, -2.591884791599735e+00, -2.022930504503206e+00, -1.455270912175953e+00, -1.012225011548626e+00, -6.695128507347641e-01, -5.948479269764797e-01, -4.691387147132201e-01, -3.199199322292920e-01, -2.391048685551975e-01, -2.120663780986068e-01, -8.758454106925172e-02, -1.869804334893967e-02, -2.070410763907751e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_tau_hcth_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.189120496434780e+00, -6.057705500667350e+00, -5.872484675400508e+00, -5.613702269246767e+00, -5.256731718687524e+00, -4.774004164081145e+00, -4.144040875113900e+00, -3.380765793187975e+00, -2.554784017849766e+00, -1.520713304743794e+00, -6.405954408212434e-01, -9.351833298194510e-01, -8.198974592140825e-01, -6.422360590930730e-01, -3.859938461909315e-01, -3.706743916529923e-02, -1.349952697568487e-01, -1.092932540022543e-01, -2.485758475624326e-02, -2.760443792834805e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tau_hcth_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.290306186556291e-06, 2.367530374716349e-06, 2.465188799165692e-06, 2.566431247051412e-06, 2.589028823627234e-06, 2.206578913857104e-06, 1.711957043067548e-07, -8.064544267505745e-06, -3.690812180566540e-05, -1.799799886716603e-04, -1.546877828229566e-03, 3.491038745025731e-03, 1.028684741475433e-02, 3.622047292832439e-03, -5.193858218308439e-02, -1.207854851351927e+00, -9.082014024690386e+00, -1.659830627179566e+01, -1.989695305902785e+01, -2.196623382913581e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tau_hcth_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.377272165633141e-05, 5.259678648705496e-06, -5.724004518584041e-06, -1.663269348666354e-05, -1.377552873268949e-05, 6.019795515804485e-05, 4.187990966290897e-04, 1.662502982142712e-03, 3.841739541860438e-03, 7.230160197245934e-04, -4.032138913754759e-03, -8.766211676152627e-05, -3.673018079817313e-04, 4.073009398958354e-03, 9.031014667220120e-03, -3.833730965208806e-02, -1.062562171166880e-02, -1.047830369186420e-04, -5.858728455081139e-08, -1.184620089432612e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tau_hcth_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.379735881381522e-02, -1.466064020071241e-02, -1.601252968838080e-02, -1.820208460937616e-02, -2.190069120811725e-02, -2.841830003497618e-02, -4.002350540065044e-02, -5.892402108209395e-02, -1.004570693917289e-01, -4.578402630487475e-01, -1.543081122952513e+00, -6.669032919329333e-01, -6.558824593811180e-01, -1.368598577398832e+00, -6.555435182696378e+00, -2.956334061976298e+01, 3.603699644526109e+02, -2.274765911328143e+02, -2.798734108204588e+04, -2.382234221029190e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tau_hcth_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.302962742100600e-08, 2.901880902288146e-08, 3.997141628132527e-08, 6.198825275769019e-08, 1.121662274248551e-07, 2.462091868001844e-07, 6.754700550966302e-07, 2.288433630075610e-06, 9.394878321568756e-06, 1.076498611663846e-04, 3.073028524812129e-03, 1.130355806958237e-02, -1.999552159518905e-04, 2.126259969021994e-01, 3.624758964109354e+00, 1.177657631779530e+02, -2.470061753369969e+04, -2.000627768535215e+06, -2.782981035807684e+08, -2.275786496471490e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tau_hcth_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.203670486483922e-06, 3.292924754126056e-06, 3.188847225976954e-06, 2.290337776782486e-06, -1.650055974619576e-06, -1.758866609210937e-05, -8.245710354496972e-05, -3.220369446667811e-04, -6.351328019207415e-04, 2.732009079612784e-03, 8.060382651555060e-03, 1.978371787585781e-03, -3.289112297569297e-03, -1.203958844868215e-01, 4.890210846098111e-01, 4.442496081756249e+00, -3.223163597819172e+01, -1.448465108194587e+01, -9.551481444384532e-01, -1.431846706957994e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tau_hcth_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.165166031333534e-13, -5.290921045601479e-13, -7.451082934419909e-13, -1.214460808406047e-12, -2.430096162372515e-12, -6.450636940453636e-12, -2.493548696223985e-11, -1.536247777490080e-10, -1.588896661642087e-09, -3.033463288524959e-08, -2.462628769894200e-06, -1.408488542548604e-03, -1.314037483092348e-02, -1.218492071086046e-01, -3.394011992950610e+00, 5.473657420997228e+02, 2.583659906196460e+06, 6.060567165830304e+09, 1.010609346998567e+14, 6.415769729630048e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_tau_hcth_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.082185506577669e-11, -3.585954653791202e-11, -4.282860523043104e-11, -4.925566892695063e-11, -3.314342371451291e-11, 1.674546806896654e-10, 1.873492915128865e-09, 1.758707330963918e-08, 1.570361028974757e-07, 2.210856445671570e-07, -2.718223232673416e-05, -1.103373470131719e-04, 8.810811908936841e-04, 5.420095462966160e-02, 6.272039816728732e-01, -5.572073071515157e+01, -8.338216484620488e+02, -1.131301717040688e+03, -4.063683552593399e+02, -6.065578389687808e+01]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_tau_hcth_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_tau_hcth", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.708105979297039e-09, -4.055753045119434e-09, 6.011302777664449e-09, 2.960705499060346e-08, 8.938172514534753e-08, 2.468042641279305e-07, 5.897909537303732e-07, -8.469057153280437e-09, -1.755898721975927e-05, -8.699668965129815e-05, 9.374294084397864e-05, -4.845204526111391e-05, 4.839835874111422e-04, -1.861461778081690e-02, -7.443070723985619e-01, 4.819041085332108e+00, 3.710379656326291e+01, 1.401296716836946e+01, 9.854303705287897e-01, 1.575155404715529e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
