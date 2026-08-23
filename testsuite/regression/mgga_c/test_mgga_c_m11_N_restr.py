
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m11_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.056449154120817e-01, -2.155455072995046e-01, -2.281655249493448e-01, -2.418268576186414e-01, -2.497330604942823e-01, -2.342319967274756e-01, -1.689794468207038e-01, -7.242599107366392e-02, -5.235773106044621e-02, 2.667011594549328e-02, 2.883689180603703e-02, -2.839968193138028e-02, -5.553676247781002e-02, -4.285662790590788e-02, -1.122544032567616e-02, 6.314566088756411e-03, -5.703224807010538e-02, -8.621965366481314e-02, -2.842147543117572e-02, -3.882254641985613e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m11_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.500347524216865e-01, 3.182218745301230e-01, 2.537756727849671e-01, 1.293185971052493e-01, -9.029656178767798e-02, -4.059316772848253e-01, -6.412061671086405e-01, -3.727010437697413e-01, -5.627292768185088e-02, -2.687265312372781e-01, 9.119608459394338e-02, -3.702850666551154e-02, -7.355195676871430e-02, -6.746211660378972e-02, -1.672904586152603e-01, 3.792635108590357e-02, 5.191114939397587e-02, -8.563733098331548e-02, -3.618389484844665e-02, -5.106249006918055e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.076077070290351e-06, -2.423203448364610e-06, -2.920990996115184e-06, -3.601710580083996e-06, -4.403281169221248e-06, -4.880763221395859e-06, -3.576697248240818e-06, 1.296284341423416e-06, 4.198806704980695e-06, 2.606041087480455e-05, 2.542544403085855e-04, 7.525256830067943e-03, 6.821809950656913e-03, 1.074985730923707e-02, 3.657551478407693e-02, 2.902606315084076e-01, 9.752631903752119e-01, 5.367863789460181e-01, 6.826303102266627e-02, 1.704181594277439e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.541513316959245e-03, -8.614894383187672e-03, -6.897293174345178e-03, -3.778570507893029e-03, 1.501506889143697e-03, 8.868811514005938e-03, 1.405189290064266e-02, 6.898553993507831e-03, -8.433472124762023e-04, 6.175352502720883e-03, -4.744717055206825e-03, -7.208561928067365e-03, -2.359716159534832e-03, -4.774578770669244e-03, 7.292622651215640e-02, -5.642610448316756e-02, -1.033130539408381e-01, -1.884584400708208e-02, -3.198996492453964e-04, -6.089397169803167e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.120328464782531e-03, 7.682687990569171e-03, 1.309153779141010e-02, 2.101666165878085e-02, 3.104599779048845e-02, 3.685116883402340e-02, 1.392648511188544e-02, -5.762403279975637e-02, 3.811164218559403e-02, -1.536830374643136e-01, -1.590611373612582e-01, -5.102989776371263e-01, 1.223024229983737e-01, -9.745143087152139e-01, 1.320587688300294e+00, 6.080930218851396e-01, 5.005972854894291e+01, 1.143637975148651e+03, -3.197215907113196e+04, -4.138976255960364e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.188998226265476e-08, 3.808168217811101e-08, 2.871060064553036e-08, 5.260926725441984e-09, -5.442098574814601e-08, -2.029993396051375e-07, -5.036240766740486e-07, -5.388907082156017e-07, 1.006139282927060e-06, -2.431989996167361e-06, 3.887783640978105e-04, -1.489342849871901e-02, -1.955535741626218e-02, 3.537251390920115e-02, -1.566245872574531e+00, 7.055494401147699e+01, 5.002952861661627e+03, 1.051717848523633e+05, 1.560787821918332e+06, 2.919989420267155e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m11_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.871007934490360e-04, -2.617035802921081e-04, -3.717512195830883e-04, -5.251664957160264e-04, -6.973342336989692e-04, -7.171114473164959e-04, -1.224807457763363e-05, 1.664245608785226e-03, -1.177035923705982e-03, 4.060659406857997e-03, 8.220726269893264e-04, 5.945047531106146e-02, -3.716706255727992e-02, 4.967858059602860e-01, -4.601760051513078e-02, -8.658291932031855e+00, -8.497928927670820e+01, -1.569071681789107e+03, -3.293779611830318e+03, -4.703259787787662e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m11_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.866557431367315e-13, 3.812496334703297e-13, 5.545414943177066e-13, 8.960103471979684e-13, 1.616476355851574e-12, 3.138333423677612e-12, 5.163384549398673e-12, -6.036877767456908e-12, -1.072716881003240e-10, -7.647502820738249e-09, -1.986766158655773e-06, -1.638132347519549e-03, -5.419909564109368e-03, -3.172046758144010e-02, -1.527672380920909e+00, -7.050081798148977e+02, -4.922856209562835e+05, -2.974740264281544e+08, -5.202827370353340e+11, -7.466238596944379e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m11_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.219444101471149e-09, -1.180521041944137e-09, -1.041940545223474e-09, -6.238576854505033e-10, 5.720690675804773e-10, 3.828054448138842e-09, 1.113590997386761e-08, 1.482055133224371e-08, -1.451152016836959e-08, 3.698521664105759e-07, 2.989660663024924e-06, 1.469822637291493e-03, 4.101197442716624e-03, -1.516726262685969e-02, 1.447004992652120e+00, 1.414268391285204e+01, 4.993064094872869e+02, 8.039527285712109e+02, 5.488970956827432e+02, 1.406565136374037e+02]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_c_m11_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.930858277297092e-06, 9.500164065467641e-06, 1.166713641227032e-05, 1.432450634160117e-05, 1.626679183312482e-05, 1.237887655786309e-05, -1.108433408463000e-05, -5.125460981268729e-05, 3.368825130129184e-05, -1.449605062159314e-04, -8.294950244232436e-06, -6.121796613256532e-03, 1.195441985635015e-02, -2.608967733504114e-01, -1.233084296255945e+00, 5.846674380912396e+00, 9.818154763351454e+01, 1.584948117562243e+03, 3.577740858220845e+03, 5.397747428590593e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
