
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbe_gaussian_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_gaussian", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.303462472064557e+00, -4.221748098164376e+00, -4.107356579054446e+00, -3.949126655533578e+00, -3.734003244208171e+00, -3.448708580346396e+00, -3.083618356435543e+00, -2.639576367620681e+00, -2.136051387989613e+00, -1.609596458293935e+00, -1.082693181787878e+00, -6.644472722622903e-01, -5.627470592796300e-01, -4.720748761692983e-01, -3.492468222990486e-01, -2.286341265656828e-01, -1.207833536529711e-01, -4.187677833833180e-02, -8.769444219080868e-03, -9.701619348755272e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbe_gaussian_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_gaussian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.379096336868939e+00, -5.264673953854031e+00, -5.104255202776301e+00, -4.881870171078257e+00, -4.578542318152252e+00, -4.174374687735490e+00, -3.653847857546421e+00, -3.016703355329987e+00, -2.298394890875365e+00, -1.600228153031688e+00, -1.044792741757484e+00, -7.992736865666539e-01, -7.153012585693049e-01, -5.548834933527486e-01, -3.611013721111250e-01, -2.158497476866673e-01, -1.361087667962936e-01, -5.452646092864809e-02, -1.167947471387768e-02, -1.293530586814711e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_gaussian_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_gaussian", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.850430494728723e-06, -4.164054932224572e-06, -4.658883170391903e-06, -5.471418540608943e-06, -6.883538845058264e-06, -9.542129248120469e-06, -1.513664229973150e-05, -2.882089668762824e-05, -6.935455824592990e-05, -2.196739392332882e-04, -1.062178568186222e-03, -6.953551488788673e-03, -1.301336363436286e-02, -2.769706054710237e-02, -9.852380141490527e-02, -4.765525709732917e-01, -1.690373080508037e+00, -2.950224989268792e+00, -3.571486556895256e+00, -3.945309514915328e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_gaussian_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.223532662698723e-02, -1.279904549388374e-02, -1.365486915590712e-02, -1.498450949355379e-02, -1.711828079833779e-02, -2.069746723459503e-02, -2.705052131483235e-02, -3.898833340619443e-02, -6.112836544168607e-02, -8.713892952143534e-02, -1.333547854750994e-01, -5.652799713387906e-01, -6.795280294256264e-01, -1.170890626286548e+00, -2.176664424531087e+00, 2.182405228530795e+00, 2.863595533318508e+01, -4.077969065892701e+02, -1.344733741083670e+04, -1.116614473784522e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_gaussian_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.385489104626558e-08, 2.721694758954539e-08, 3.286716543785273e-08, 4.301576185787699e-08, 6.302912719650741e-08, 1.079205357845780e-07, 2.272579822395060e-07, 6.129321214505463e-07, 1.945727785737406e-06, -1.348183833680223e-06, -2.221840565200114e-04, 1.084085147063395e-02, 3.701859560655260e-02, 1.132901012574865e-01, 3.581514030052716e-01, -4.478198715092402e+01, -5.072998972048368e+03, -3.536008791515713e+05, -4.993400421877286e+07, -4.087471036652100e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbe_gaussian_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbe_gaussian", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.163477582112540e-14, 6.563393391670467e-14, 9.261347549789809e-14, 1.517397525594328e-13, 3.076421903134027e-13, 8.439164611255551e-13, 3.543355847079712e-12, 2.685450503956879e-11, 4.505919304333527e-10, 2.053738896772311e-08, 2.939677433197508e-06, 3.313345670272905e-04, 1.924585940949124e-03, 2.214562260118353e-02, 1.510036695320186e+00, 5.320719819133227e+02, 4.994731257309912e+05, 1.072203644898905e+09, 1.813481318599807e+13, 1.152318452808614e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
