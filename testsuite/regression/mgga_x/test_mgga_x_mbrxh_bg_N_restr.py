
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mbrxh_bg_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.128756668378689e+00, -4.062618056559352e+00, -3.971683670759279e+00, -3.849613536614869e+00, -3.692011590526410e+00, -3.500387463528304e+00, -3.279662062890860e+00, -3.019152702478907e+00, -2.718030511417618e+00, -2.396375251875200e+00, -1.778763146134517e+00, -8.191059157222021e-01, -5.695903250223449e-01, -5.258394337353994e-01, -4.807964277384500e-01, -4.639993867613387e-01, -5.723299509087241e-01, -1.030416868616503e+00, -3.053711631719778e+00, -1.772867037928383e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mbrxh_bg_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.446721569131542e+00, -4.294649975610398e+00, -4.074484221391532e+00, -3.755823319073790e+00, -3.302137998920871e+00, -2.715657890300615e+00, -2.177931308778539e+00, -1.802503398954967e+00, -1.278864172045435e+00, -5.755163499916409e-01, -2.595103631858728e-01, -7.112099272333017e-01, -5.828137195115296e-01, -3.631895542595079e-01, -1.802427071178264e-01, 6.495074870420593e-02, 3.464376725260436e-01, 9.085935847643164e-01, 3.167230854968352e+00, 2.009588293064375e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxh_bg_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.527794780822300e-06, -1.079747119200158e-05, -1.292770374080574e-05, -1.672430715734727e-05, -2.397055408610672e-05, -3.828303956628634e-05, -6.443982077420854e-05, -1.158258224804690e-04, -2.762598568286443e-04, -1.006889565938579e-03, -5.333399007855424e-03, -1.518033402879155e-02, -3.127854285512618e-02, -1.042561539953570e-01, -4.063311943929496e-01, -3.586088932922432e+00, -7.490206582516691e+01, -5.140975872241223e+03, -1.970860644916419e+06, -9.246916410831467e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxh_bg_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.157136563714209e-03, -4.338977726214360e-03, -4.612942062508356e-03, -5.025175967269284e-03, -5.613696428081190e-03, -6.240209003011066e-03, -6.190590174043322e-03, -5.136360344990735e-03, -3.985156243292941e-03, -3.076316333285419e-03, -3.449756573397660e-03, -1.670543300268603e-02, -3.681744313632999e-02, -3.349804530171404e-02, -1.835914575072452e-02, -9.498655184292291e-03, -3.560262457100271e-03, -9.008662974450349e-04, -1.409937919305611e-04, -1.147610034581813e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxh_bg_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.056594906232465e-02, -3.384074352469296e-02, -3.904935352353928e-02, -4.729597012626176e-02, -5.863790692496550e-02, -6.248486409494774e-02, -3.374398910650932e-02, -3.120725892879415e-02, -1.215787589795135e-01, -4.284988484479448e-01, -1.278927686976679e+00, -3.975694252633983e-01, -1.276029590923339e+00, -8.510896322937677e-01, -6.689880238026240e+00, -5.046747494768837e+01, -8.843453606320636e+02, -5.984458375674515e+04, -2.352761248074567e+07, -1.128802575202323e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxh_bg_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.215009181417151e-07, 2.687665435970993e-07, 3.524429723002143e-07, 5.091049367032149e-07, 8.014661295517554e-07, 1.175951846194238e-06, 9.807595819671399e-07, 1.646712427609831e-06, 1.486043177564369e-05, 1.782660868597704e-04, 3.690651393746350e-03, 3.472666732767832e-02, 2.305500959374745e-01, 3.281810399725020e-01, 6.403015177445487e+00, 2.967694628290002e+02, 6.879416617248511e+04, 1.562514494121859e+08, 7.412561242331600e+12, 2.753532053213006e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxh_bg_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.017133590557312e-05, 4.467691596133170e-05, 5.114672868998983e-05, 5.881769988202091e-05, 5.798026755614479e-05, -2.536884226144677e-06, -1.991869128247723e-04, -3.656038560347583e-04, -5.537746534120641e-04, -1.231909810035707e-03, -5.048334573347257e-03, -3.641451504169097e-02, 7.287128286334951e-02, -3.501274191533911e-01, -6.218605369740037e-01, -2.111715623697419e+00, -9.934108015763895e+00, -7.517302013863311e+01, -1.279691051597198e+03, -7.481713048985618e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxh_bg_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.487170482911412e-12, -1.932715329451105e-12, -2.790161379411425e-12, -4.594306904477089e-12, -8.513486673256872e-12, -1.380566023271329e-11, 5.616047709899204e-12, 1.059718296743415e-10, 5.302282617843010e-10, 1.160837464989266e-08, 7.262943398903185e-07, -1.830759179790640e-03, -4.086332452393369e-02, 4.095118491071526e-02, 6.311490909615328e-01, 5.121395066513712e+02, 2.164161207396289e+06, 1.273284415735314e+11, 4.866888857850829e+17, 9.301137807804140e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxh_bg_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.920014081865319e-10, -3.472640199418409e-10, -4.359653845679962e-10, -5.647413100932148e-10, -6.136155993735739e-10, 5.161282586908906e-10, 6.851513002054814e-09, 2.155917301482915e-08, 7.456994958229484e-08, 5.403599390352542e-07, 1.455477150202021e-05, 1.809439856225642e-03, -7.618457044974973e-03, 1.241476724106422e-01, 6.288716034296439e-01, 1.250430786971775e+01, 7.522010373148529e+02, 1.903314447838152e+05, 3.932113404582547e+08, 1.791389655994877e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mbrxh_bg_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mbrxh_bg", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.274051087951229e-07, -1.395484943511102e-07, -1.555638263834468e-07, -1.696886114626186e-07, -1.437034657623890e-07, 8.412989781061291e-08, 6.582096063933619e-07, 9.560534859386423e-07, 1.075700623142832e-06, 1.650943819998496e-06, 9.414337571488942e-06, 1.991226031867073e-03, -8.967556779710067e-03, 3.988929377443996e-02, 2.841412518944176e-02, 3.312079287333460e-02, 3.575379509017678e-02, 3.335226389129305e-02, 2.813002434459760e-02, 2.223245732661410e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
