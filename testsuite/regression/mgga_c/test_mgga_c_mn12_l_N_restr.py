
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_mn12_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.000559939170151e-01, -2.892895578078132e-01, -2.752767920204065e-01, -2.577472272887392e-01, -2.366521264086282e-01, -2.109672598136981e-01, -1.741082919864365e-01, -1.084516978937684e-01, -9.961578805764216e-03, 8.184299257934746e-02, 1.335407551176293e-01, -8.145626950948254e-02, -5.209580389270802e-02, -4.023723386231438e-02, 5.964896351358900e-03, 7.371061735781910e-02, -3.496657156403053e-02, -7.272546736798556e-02, -2.368319000936780e-02, -3.232671212479436e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_mn12_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.299979781566923e-01, -6.827340005534607e-01, -6.210404071515263e-01, -5.459810476642772e-01, -4.669664311592146e-01, -4.092616194316794e-01, -4.085396742227052e-01, -4.385747997367113e-01, -3.296746700846962e-01, -2.386386636332463e-01, -1.667930053482852e-01, -1.323859301849588e-01, -1.252884306619839e-01, -1.627382775519593e-01, -1.343802736901507e-01, -4.890161774923391e-02, 1.039674211353860e-01, -7.343448511313913e-02, -3.018036688979406e-02, -4.251917679813418e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.631433771469105e-07, -1.908286986772389e-07, -2.438210765592445e-07, -3.478671899297737e-07, -5.521623129257411e-07, -9.248731276358469e-07, -1.387875105561336e-06, -6.079338577203462e-07, 8.948634598641009e-06, 6.824532493782806e-05, 7.398645213703579e-04, 1.869828939554774e-02, 3.614745643794500e-03, 7.949807484650897e-03, 1.136703402345504e-01, 8.910283637307159e-01, 1.348461166492493e+00, 4.527629815157213e-01, 5.336076768066429e-02, 1.327023987869981e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.024464243663154e-02, 9.422509538895993e-03, 8.365695462213241e-03, 7.125135119576916e-03, 5.946886725864229e-03, 5.449991637753139e-03, 6.498620528371086e-03, 8.373779574300895e-03, 6.422392547404444e-03, 4.339516198512394e-03, 1.514698768463794e-03, -1.545612429494256e-02, 2.298152184627087e-02, 5.678549636128976e-02, 1.636361857925451e-02, -1.730068607524960e-02, -1.272052546376261e-01, -1.484984210277252e-02, -2.388012655189571e-04, -4.533689816952843e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.120914749834033e-02, -1.113748557645975e-02, -1.082881436198378e-02, -9.930392797799935e-03, -7.680796609486049e-03, -2.798647336169918e-03, 4.788776800221008e-03, 4.096732756947238e-03, -2.435839466265991e-02, 8.649404345652307e-03, -5.948056032786534e-01, 9.156620435125925e-01, -6.529342561202419e-01, -5.345646181769150e-01, 2.687768312467513e+00, -6.430565949250551e+01, 1.784979815009931e+02, 9.048895320812323e+02, -2.696392569884254e+04, -3.446884337803147e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.554180305399315e-09, 4.004661765360968e-09, 6.206983707959867e-09, 9.337625140144313e-09, 1.244344544702263e-08, 7.371883815864900e-09, -5.338427750387564e-08, -3.934014848824147e-07, -1.440408259003652e-06, 6.373738887416038e-06, 8.250751056777862e-04, -4.850557485559977e-02, -1.124139329544950e-01, -3.318163921050708e-01, -1.557107683943658e+00, 2.052512547582220e+02, 8.015582058871349e+03, 9.052315323846255e+04, 1.221271450999206e+06, 2.273786943597223e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn12_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.601503723144865e-04, 2.562417637938479e-04, 2.459136830536247e-04, 2.208910687519230e-04, 1.643727541970718e-04, 5.179557348194986e-05, -9.702248152175058e-05, 3.352518099111070e-05, 8.592892652638635e-04, -7.175703878424988e-04, 9.060299255147536e-03, -3.147606573785818e-02, 3.577544836232408e-01, 7.485835954990382e-01, -8.383045156652749e-01, 1.836072523469091e+01, -2.093566724295723e+02, -1.279921980485910e+03, -2.462489442027087e+03, -3.501748397170913e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mn12_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.252613194525731e-14, 3.002363316848928e-14, 4.628870966091251e-14, 8.654015771042026e-14, 2.027027775731691e-13, 5.946939274572552e-13, 2.003561492400590e-12, 2.831186239375778e-12, -2.286209409093528e-10, -2.002678766161828e-08, -5.781365278280420e-06, -4.070329211853884e-03, -2.871905642099849e-03, -2.345813561440246e-02, -4.747740129738488e+00, -2.164200779185043e+03, -6.806655364761562e+05, -2.509102920859366e+08, -4.067016340072007e+11, -5.813862648544078e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn12_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.782207183045632e-11, -1.175544284772596e-10, -1.803511814335713e-10, -2.773714314749731e-10, -4.043849803155298e-10, -4.150274977259642e-10, 7.563999297213630e-10, 9.426423086560618e-09, 6.084589278909897e-08, 6.348748244091494e-07, 1.832739432306038e-05, 4.653943081006059e-03, 4.281562129957602e-02, 1.980118567509594e-01, 2.442973105618926e+00, 5.115047298760575e+01, -1.560739963638027e+02, -9.034603977430081e+02, -7.378108781018467e+02, -1.908277484332671e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_mn12_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.000698902251293e-06, -6.828141201996506e-06, -6.470898355391923e-06, -5.733764403010763e-06, -4.269134971567159e-06, -1.755892753556892e-06, 3.263135658511591e-07, -8.257336932636717e-06, -3.942164983113207e-05, -3.182876343039863e-05, -5.092994037534996e-04, -8.086314868218395e-04, -1.972510738458644e-01, -8.140266025663241e-01, -1.090520120430865e+00, -1.828358037324957e+01, 2.100897522368685e+02, 1.287433018146683e+03, 2.674323355604781e+03, 4.018811511644850e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
