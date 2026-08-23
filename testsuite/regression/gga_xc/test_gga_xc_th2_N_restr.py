
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_th2_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th2", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.728878761287015e+00, -4.628152705713693e+00, -4.486685421534211e+00, -4.290341274083723e+00, -4.022772293889825e+00, -3.668382208008846e+00, -3.219516583922357e+00, -2.689636774319210e+00, -2.129070931690407e+00, -1.615445864648101e+00, -1.118721260241044e+00, -7.046221133572629e-01, -6.082620258231699e-01, -5.071196479211703e-01, -3.766484517776111e-01, -2.486994612156987e-01, -1.397248565401563e-01, -5.421194965863092e-02, -8.428581037938392e-04, 1.377810747521782e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_th2_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.619043680414086e+00, -6.493683996568058e+00, -6.313479732291371e+00, -6.055414289040262e+00, -5.688864720033431e+00, -5.176602247787350e+00, -4.481775628919485e+00, -3.587216976938728e+00, -2.534186650920708e+00, -1.492169457767403e+00, -8.950282860956077e-01, -8.789768829807881e-01, -7.859622691839160e-01, -6.108845403054586e-01, -3.997135699964087e-01, -2.111875000237446e-01, -6.821736570747380e-02, 3.082197565974258e-02, 8.559607771262108e-02, 9.334026093999943e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th2_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th2", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.237372909776120e-06, 3.528771541002687e-06, 3.945559777910050e-06, 4.530466017109279e-06, 5.306035805014821e-06, 6.145670592747488e-06, 6.177159349284771e-06, 8.297703866618381e-07, -3.485082147894904e-05, -2.554186764852904e-04, -1.555513453749273e-03, -4.120182466396389e-03, -6.892601679056204e-03, -2.061870446590694e-02, -9.058193147628663e-02, -6.710932633831104e-01, -9.386445803164783e+00, -3.060051145525980e+02, -3.342616628919372e+04, -2.227313133211057e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th2_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.040192171071763e-02, -1.137870996014632e-02, -1.287766917377250e-02, -1.524319662091907e-02, -1.912853085527648e-02, -2.588574041713468e-02, -3.864234955041901e-02, -6.573188816967081e-02, -1.334610296590039e-01, -3.343783126177023e-01, -7.756323770564260e-01, -6.621643006447714e-01, -7.548786035947290e-01, -1.276675510946254e+00, -3.144339048539118e+00, -1.288802265947092e+01, -1.096132713319275e+02, -2.512262541965084e+03, -2.238998548730192e+05, -1.433850998764142e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th2_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.440635585896131e-08, -1.175708485331574e-08, -6.513669222430934e-09, 4.859493583085439e-09, 3.254865479031971e-08, 1.108366175328104e-07, 3.811557515679511e-07, 1.609520094358699e-06, 9.793143853363938e-06, 1.006060535858876e-04, 1.643956565501678e-03, 1.452576436765566e-02, 3.909568118634429e-02, 1.306565400378945e-01, 1.291574494426435e+00, 4.257111630624531e+01, 6.004073576058016e+03, 5.672932916532041e+06, 7.384587171479549e+10, 4.149406399306169e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_th2_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_th2", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.713041527918834e-13, -2.472220923376670e-13, -3.942669910986133e-13, -7.134554649051054e-13, -1.521818309793212e-12, -4.044202855700917e-12, -1.450081711422250e-11, -7.853339515137550e-11, -7.524587434821458e-10, -1.594966229583630e-08, -1.055207897270545e-06, -3.242079437961814e-04, -3.085379354622764e-03, 2.848475203406560e-03, 4.300464278738157e-01, 1.481339939954879e+02, 3.510133169114211e+05, 1.151576452609303e+10, 1.503381124993827e+16, 4.289319847447564e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
