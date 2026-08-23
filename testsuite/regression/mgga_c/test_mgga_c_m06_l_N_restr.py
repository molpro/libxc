
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_m06_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.944297489763792e-02, -4.943803509762076e-02, -4.944677505631183e-02, -4.949391433746685e-02, -4.963845571679509e-02, -5.001939712814266e-02, -5.095471560886371e-02, -5.306238907317497e-02, -5.644616247580068e-02, -5.242691656180724e-02, -2.829722308165285e-02, -9.010031737076347e-02, -4.127889049378656e-02, -3.224495072861445e-02, -3.365211162921091e-02, 3.535620459588652e-03, 7.120996176907417e-02, 5.330454401956747e-02, 1.482715679239673e-02, 1.828223490924236e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_m06_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.561926095573744e-02, -1.568842651845254e-02, -1.590076572552269e-02, -1.645464650497311e-02, -1.779912082185125e-02, -2.091673231746674e-02, -2.779217021398862e-02, -4.186547517617861e-02, -6.896779280322396e-02, -1.239883941451487e-01, -1.947732854075049e-01, -7.540067835465654e-02, -3.949620875636627e-02, -3.723628897720664e-03, -5.221034880630351e-02, -1.033332207752630e-01, 4.643679046377857e-02, 1.017987197190753e-01, 3.349046397661546e-02, 4.541376298829112e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.858853673219807e-07, -8.220040580135123e-07, -8.723009608203840e-07, -9.383029826967735e-07, -1.009358874842269e-06, -1.020599529769736e-06, -6.832028090702917e-07, 1.168861186937269e-06, 8.626495133144031e-06, 3.372886205691314e-05, 3.303187895817357e-04, 1.012771713942433e-02, 1.909103622619830e-02, -6.078913875053221e-03, 2.463326200794165e-02, 2.481999951340532e-01, -5.425657671336497e+00, -2.460443687047758e+02, -1.038130625715494e+04, -1.195487019234617e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.652279015979253e-04, 8.356951032777750e-04, 7.875144457535466e-04, 7.058182087321177e-04, 5.615952055421351e-04, 2.992631997857577e-04, -1.731348866905833e-04, -9.206726512812744e-04, -1.565637837995342e-03, -4.599588603232484e-04, 1.236819445318755e-03, -1.321822264948000e-02, -2.319411929244289e-02, -9.526232488808654e-03, -7.641287798174834e-03, 4.169298009881493e-02, 9.177481169665067e-02, 6.469234144583765e-02, 2.298487368219497e-02, 3.628424243094427e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.609026652901039e-05, 1.395817548887462e-04, 2.507957200077093e-04, 4.576725202505937e-04, 8.699071318831236e-04, 1.752043509423253e-03, 3.756278722704263e-03, 8.442471894092099e-03, 1.972241228349901e-02, 5.247979024098080e-02, 1.716829628611894e-01, -7.644778440022298e-03, 4.007652464212376e-02, 1.279142976258456e-01, 2.764983700436347e+00, -3.904669149587087e+00, -3.186090700174825e+02, -1.680487397614059e+02, 4.508382265213756e+04, 5.412860032517051e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.652392794441153e-09, -3.154943308110628e-09, -6.125257372186899e-09, -1.262475919678288e-08, -2.874438033795629e-08, -7.518555394290691e-08, -2.336634686897650e-07, -8.738102472116807e-07, -3.794006881902845e-06, -1.646747009854797e-05, -4.620671343180199e-05, 9.527057587019886e-03, 2.340536804519113e-02, -1.900419001877971e-02, -2.208844506297950e+00, 6.876948033444982e+01, 2.343275813482972e+04, 9.895675752089573e+05, -9.357442933924320e+09, -9.551171546030062e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.773016686804200e-06, 3.197381845608919e-06, 5.690822708106826e-06, 1.032480769702884e-05, 1.953714507517512e-05, 3.909045885313686e-05, 8.214344287700658e-05, 1.698424424545999e-04, 2.552875988663769e-04, -3.575002468209596e-04, -5.273775409662662e-03, -1.086453762545133e-02, -4.538013815946183e-02, -4.511985424639059e-02, -3.260671755674630e-01, -7.085176389371577e+00, -1.503622478841464e+01, 4.124400253879418e+02, 2.178190211627744e+04, 2.900249795433188e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.395169383715817e-14, -6.228258085670450e-15, 3.761897293082768e-14, 1.607143168712498e-13, 5.675761297696489e-13, 2.230808290276872e-12, 1.116596751642760e-11, 7.854855761056618e-11, 8.325154721123014e-10, 1.115946871242488e-08, -2.843119525920928e-06, -4.933968419457658e-03, -6.736517685874847e-02, -4.803490062917385e-03, 2.866799690899553e+00, -7.656597807202326e+02, -2.414852931028969e+06, -8.033400217611717e+09, -1.646465058299276e+14, -1.101412696785077e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.645146905621150e-10, 2.794261478909097e-10, 2.958842125445173e-10, 3.019871965646438e-10, 2.429689029658251e-10, -1.360094374078508e-10, -2.158389891645422e-09, -1.388496708455709e-08, -9.241843398617415e-08, -5.287926959378553e-07, 2.495126388218774e-05, 2.325700170000285e-03, 3.439047037539908e-02, 4.424810473835435e-02, -8.641666553923434e-01, 2.876582421457085e+01, 1.573910877108272e+04, 1.184940205347943e+07, 5.834191590865203e+10, 5.298782564566694e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_m06_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_m06_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.138426696178980e-07, -7.466273046826965e-07, -7.916893758031410e-07, -8.488859548555513e-07, -9.029191107623040e-07, -8.716299059614880e-07, -3.825015265399829e-07, 2.210091923001427e-06, 1.357359725281585e-05, 4.489831515736492e-05, -1.419955590144410e-04, -5.625560984686837e-04, -6.627969355225129e-03, -2.931688897880732e-02, 8.080705184960626e-01, -6.464328781321983e-02, -2.016486120026975e+02, -5.713112733609403e+03, -2.575406511546632e+05, -3.216366945730120e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
