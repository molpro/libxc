
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_csk_loc1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.107510631300980e+01, 3.313352296127920e+01, 3.541847320877874e+01, 3.760962483033295e+01, 3.915888703818694e+01, 3.937122359021998e+01, 3.768756286021441e+01, 3.411174267041804e+01, 2.940152522773982e+01, 2.427037661841365e+01, 1.959088078633832e+01, 6.235897847564836e+00, 1.047961644723416e+00, 1.062019075485437e+00, 9.948628373865049e-01, 8.863149715775609e-01, 8.458184902180145e-01, 8.262714045320076e-01, 8.157274784493715e-01, 8.127092903791464e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_csk_loc1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.377120486481073e+00, 4.499975953686679e+00, 1.214089984368630e+01, 1.956056501706899e+01, 2.514926513813455e+01, 2.699108234878485e+01, 2.371624443534903e+01, 1.566243250816477e+01, 5.823749627127031e+00, 2.503364429218063e+00, 8.371748373761180e+00, 3.632592914019141e+00, 1.850944175531658e+00, 9.706447794010405e-01, 3.728840317739301e-01, 3.697304856721630e-01, 1.634593966177933e-01, 1.114856907344471e-01, 9.966725139959826e-02, 9.475084561030607e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.892688738901050e-04, 7.246677538969707e-04, 7.759946213030562e-04, 8.525394353933705e-04, 9.729468363126785e-04, 1.179541548033804e-03, 1.580556489449478e-03, 2.491774183911939e-03, 4.952543783204046e-03, 1.031607922519647e-02, -1.283787627445623e-02, -3.330196534929535e-02, 1.565380196710035e-01, 3.097184960207577e-01, 7.117571181370665e-01, -1.769681616755871e+00, -2.100199904314878e+01, -6.408240228827160e+02, -7.221231626582904e+04, -5.342160670691156e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc1_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.327621446868715e-03, 4.366257233705234e-03, 7.885261264480246e-03, 1.354459731285365e-02, 2.182208153218081e-02, 3.249634543996561e-02, 4.414013467966338e-02, 5.434811720820149e-02, 6.260229671219543e-02, 9.570575068752955e-02, 2.171250000000000e-01, 2.171250000000000e-01, 9.040687905238541e-02, 8.773980802536827e-02, 1.152732774442865e-01, 2.170897265874852e-01, 2.171250000000000e-01, 2.171250000000000e-01, 2.171250000000000e-01, 2.171250000000000e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.476712219781168e-01, 6.663410482330232e-01, 8.240113470137924e-01, 1.031674922223246e+00, 1.308328035974050e+00, 1.697583830854559e+00, 2.316797929019454e+00, 3.519694361033747e+00, 6.607826129983457e+00, 1.983513218053193e+01, 4.737695900683681e-01, 3.240124512958061e+00, 9.253852927406593e+00, 1.816123342696664e+01, 6.628724400354153e+01, 1.617455138077204e+00, -2.045112279934018e+02, -6.526602378586703e+03, -6.959728779771243e+05, -4.908181024767150e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.007263173688541e-06, -4.635071743130791e-06, -5.740239318239001e-06, -7.823666067759608e-06, -1.214484020074042e-05, -2.243705105206612e-05, -5.252829996514183e-05, -1.719858080005241e-04, -9.300326593817578e-04, -1.297446472277488e-02, 7.990839623672545e-03, 5.377071011518392e-02, -1.216326154125169e+00, -5.437587642468794e+00, -9.582654966105704e+01, 2.896114391289959e+01, 2.138588915434775e+04, 1.991056622078001e+07, 2.528299937200541e+11, 1.383693606374758e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc1_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.231208523951067e-05, 8.367164368838099e-05, 1.633263398935752e-04, 3.149066077051685e-04, 6.033658056357940e-04, 1.168343329986288e-03, 2.370398353220890e-03, 5.397369438864381e-03, 1.585865630506204e-02, 9.865095067207846e-02, -2.817681462947307e-132, -1.127072585178923e-131, 5.122794034167505e-01, 1.269878936558606e+00, 8.511256128636303e+00, 2.135894384915406e+00, 0.000000000000000e+00, -2.769893585335721e-127, 1.181821263076574e-125, 1.210184973390412e-122]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_k_csk_loc1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.269367750897432e-13, 4.078089596816046e-13, 1.363977588977242e-12, 4.863769056442689e-12, 1.922740428931556e-11, 8.981541499885416e-11, 5.493242261199118e-10, 5.181290223310622e-09, 9.980847281715961e-08, 8.286985400264966e-06, 0.000000000000000e+00, 0.000000000000000e+00, 1.335600009977572e-01, 1.416058914123940e+00, 1.415052951553505e+02, 1.714341039298580e+03, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc1_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.389414100192728e-11, -1.024250621011350e-10, -3.137313089180204e-10, -9.859946669328213e-10, -3.251867858438241e-09, -1.171686634447589e-08, -4.943333170019362e-08, -2.745277892569607e-07, -2.494355304348480e-06, -7.283400907269231e-05, 0.000000000000000e+00, 0.000000000000000e+00, -8.187970819722437e-02, -4.509610035296908e-01, -1.413549964636788e+01, -2.975579049573154e+01, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_csk_loc1_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_csk_loc1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.050275567866975e-09, 2.572501927032720e-08, 7.216198784411010e-08, 1.998831506878765e-07, 5.499777510071868e-07, 1.528523326826059e-06, 4.448473536734102e-06, 1.454570267753867e-05, 6.233747705697497e-05, 6.401354197427947e-04, 0.000000000000000e+00, 0.000000000000000e+00, 5.019681464793635e-02, 1.436139589081435e-01, 1.412048574105331e+00, 5.164707883258342e-01, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
