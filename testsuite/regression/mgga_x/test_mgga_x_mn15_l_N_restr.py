
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mn15_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.052068237398739e+00, -3.147413908813196e+00, -3.269972933582764e+00, -3.416848591115483e+00, -3.569758482362069e+00, -3.677467257430183e+00, -3.630476514176212e+00, -3.255329845928304e+00, -2.442228166019806e+00, -1.458813765191277e+00, -6.730899971044042e-01, -3.467311818970582e-01, -5.608617240231711e-01, -4.665198248869099e-01, -3.297009667587333e-01, -2.051803563335782e-01, -8.626632809995596e-02, -4.123755744311928e-02, -1.055882827990799e-02, -1.223526729005054e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mn15_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.622612505972689e+00, 3.266006218213374e+00, 2.763637342848764e+00, 2.064779964741672e+00, 1.114635352026702e+00, -1.192448406007842e-01, -1.563417691245879e+00, -2.831629997669503e+00, -3.029926860114858e+00, -1.871146600087567e+00, -9.016803044114637e-01, -9.374400438908680e-01, -8.857739399233293e-01, -6.277494720649572e-01, -3.143598194421075e-01, -2.326887604906298e-01, -1.123166491177138e-01, -4.917438686221780e-02, -1.386070831314914e-02, -1.628983713126628e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn15_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.434057829815068e-05, -3.675296563897465e-05, -4.046281444213187e-05, -4.631629751362339e-05, -5.585973801025222e-05, -7.202635252692619e-05, -1.004630824582510e-04, -1.521495353135354e-04, -2.566698361661720e-04, -5.736611316368842e-04, -2.384404558678479e-03, -1.386007173681702e-02, -1.179749004112425e-02, -4.676732840132645e-02, -2.785179465776494e-01, -1.289073216657673e+00, -2.719858053511059e+00, -9.541451699683702e+00, -1.419221391678543e+01, -1.620060233951930e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn15_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.035185648453786e-01, -9.816417937105648e-02, -9.031362831723186e-02, -7.878484240473139e-02, -6.194494313058324e-02, -3.794890209874736e-02, -6.261357385379718e-03, 2.737302821620219e-02, 4.443995739226313e-02, 3.463354700812990e-02, 2.809491114052929e-02, 5.624043604979943e-02, 6.467939712555981e-02, 7.003915329526203e-02, 1.125947097390900e-01, 1.525284365244394e-01, 4.164587097076734e-02, 1.579816997228807e-03, 1.551301381217036e-05, 2.358950826950793e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn15_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.747026166798763e-02, 6.134428508036285e-02, 6.719810129505338e-02, 7.614803643801195e-02, 8.987234210038136e-02, 1.101823642647160e-01, 1.347191505625056e-01, 1.340334287940859e-01, -6.087779836645342e-03, -2.032239282684011e-01, -5.307333616101767e-02, -2.061477663874881e+00, -3.896617269732727e-01, -1.935060004578426e+00, -4.733545277130625e+00, 3.267506518749013e+01, -4.988957631045982e+01, -4.916422589274100e+01, -1.457410365367646e+04, -1.395762856887068e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn15_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.982751565271200e-07, 2.190914918963017e-07, 2.516779217510297e-07, 3.038657726401172e-07, 3.884584660610765e-07, 5.196402247291507e-07, 6.658472258431004e-07, 4.957345262335979e-07, -1.159002404947356e-06, -5.643460327484288e-05, -1.885146365806105e-03, 4.679748149599249e-02, 7.459152192829574e-02, 5.746335188244692e-01, 4.201451012587026e+00, -3.052460273200413e+02, -9.527909719045509e+03, -1.086533436579568e+06, -1.975349780680175e+08, -1.677893316171041e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn15_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.537316825581023e-03, -1.652930371925646e-03, -1.827865384714055e-03, -2.095806188883124e-03, -2.507892411676582e-03, -3.122745455675136e-03, -3.898570333895509e-03, -4.147557601574188e-03, -1.233618025413850e-03, 5.864542700351363e-03, 1.779221348295612e-02, 8.517863940159068e-02, -2.261828834451443e-01, -4.805954605997232e-01, -1.147019239632302e+00, 1.197700855739003e+01, 1.294295077959189e+02, 1.580867116726907e+02, 1.638636146894115e+02, 1.833382035654112e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn15_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.191095029007427e-13, -7.667718065386368e-13, -1.041044105983847e-12, -1.609588377148916e-12, -2.985410807622459e-12, -7.111113978407509e-12, -2.354496816184512e-11, -1.129837306430537e-10, -4.412034526522262e-10, 4.905715260826793e-08, 9.759573352423750e-06, -2.607680537854883e-04, -1.609279237461909e-02, -1.293801941893756e-01, 1.845213223650514e+00, 2.512016840014328e+03, 1.114736343644957e+06, 3.467410011190426e+09, 7.204769763167828e+13, 4.731745290548945e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn15_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.360181755820434e-09, 2.882256857920493e-09, 3.818953410644344e-09, 5.656461667625475e-09, 9.720897110447108e-09, 2.021517300234357e-08, 5.272423637425091e-08, 1.717571122448895e-07, 6.128032104382095e-07, 1.640208665287704e-06, 7.944935187092786e-06, -1.082255805829716e-03, -1.793801883534186e-03, 1.838885633962803e-02, -2.086783019015803e-01, -4.331907117215163e-01, -2.026645350554395e+03, -3.581748662822932e+04, -2.863274668931530e+05, -3.282746797497051e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn15_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn15_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.512437371080492e-05, 3.718825799668106e-05, 4.018996093936369e-05, 4.448828321815493e-05, 5.030312344311988e-05, 5.663516875404762e-05, 5.666430458033191e-05, 2.232621865724104e-05, -1.109091454577016e-04, -3.050207773769799e-04, -8.621436937851285e-04, -9.149424522583466e-03, 7.955397393452097e-02, 2.734056619556291e-01, 6.649797451092526e-01, -1.121291767877896e+01, -8.764600794021673e+01, -1.378659772609687e+02, -1.737446254673471e+02, -2.091053198984932e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
