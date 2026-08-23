
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_br89_explicit_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.417191340882505e+00, -3.405279421933965e+00, -3.383399262914195e+00, -3.343510726163687e+00, -3.272224972760642e+00, -3.148953659555510e+00, -2.946073353995827e+00, -2.637120792953712e+00, -2.221016353681133e+00, -1.737210273618370e+00, -1.223754312005767e+00, -7.121544830672936e-01, -5.259829484927320e-01, -4.675295522626652e-01, -3.722413698059973e-01, -2.591243638712370e-01, -1.693671072246160e-01, -1.108238882798523e-01, -7.489726523162288e-02, -4.915398028283997e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_br89_explicit_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.781048350166017e+00, -4.844411852716932e+00, -4.909762544777760e+00, -4.954278649053765e+00, -4.925867387862890e+00, -4.724228453050872e+00, -4.221821591540903e+00, -3.433267182088966e+00, -2.588803792931229e+00, -1.826721682260752e+00, -1.221887765713478e+00, -9.051935119702272e-01, -7.998568703264484e-01, -6.370072923065668e-01, -4.102820840670259e-01, -2.385072434155461e-01, -1.235333548620706e-01, -6.812947912755064e-02, -3.135459938999904e-02, -2.567877898752187e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.181626724233951e-07, -2.553521579722210e-07, -5.618288852567145e-07, -1.265754253942269e-06, -2.928134689753204e-06, -6.878264435692632e-06, -1.569665617955120e-05, -3.303578722594772e-05, -7.007474609883809e-05, -1.897626872170690e-04, -8.115821593562356e-04, -6.560106301116806e-03, -8.535786174470613e-03, -3.096090865526804e-02, -8.894628269692388e-02, -4.401811638335046e-01, -4.617275919977010e+00, -1.101653780747654e+02, -1.085432349650052e+04, -4.720140679107149e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.290340088174142e-05, -1.075363077220259e-04, -2.166809874877216e-04, -4.302462876659923e-04, -8.303656907661881e-04, -1.504546375802509e-03, -2.368450925584455e-03, -2.934939607844038e-03, -2.936422572860051e-03, -2.796498427876573e-03, -3.259667268726532e-03, -1.015722278260351e-02, -8.774240122909508e-03, -1.653245996443336e-02, -1.489815164606948e-02, -1.281066989504091e-02, -1.133598230981159e-02, -8.864215610125027e-03, -7.750423808980454e-03, -4.555876709244953e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.692908828215725e-04, 3.441161847104827e-04, 6.933791599607092e-04, 1.376788120531175e-03, 2.657170210451802e-03, 4.814548402568029e-03, 7.579042961870256e-03, 9.391806745100923e-03, 9.396552233152163e-03, 8.948794969205035e-03, 1.043093525992490e-02, 3.250311290433121e-02, 2.807756839331043e-02, 5.290387188618675e-02, 4.767408526742235e-02, 4.099414366413092e-02, 3.627514339139710e-02, 2.836548995240009e-02, 2.480135618873745e-02, 1.457880546958385e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.253230602408836e-02, -1.470202722601316e-02, -1.766533994266060e-02, -2.143423231943297e-02, -2.537522562230281e-02, -2.781816230325567e-02, -3.112743108257215e-02, -4.907056464629982e-02, -7.733827642519979e-02, -1.268083520745679e-01, -2.556340063463752e-01, -6.279875526903984e-01, -1.008625051328587e+00, -1.362835238867962e+00, -2.720347905597591e+00, -5.952343923343141e+00, -2.101842199355052e+01, 3.454638276611245e+02, 1.902048227109300e+04, 1.989552919344214e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.217746217632322e-09, -2.669382993750818e-09, -5.895218442359504e-09, -1.271612552145475e-08, -2.308140165679696e-08, -4.193731041571494e-09, 2.628459062803825e-07, 1.188910364558378e-06, 2.811629761601103e-06, 1.029641135464427e-05, 1.337200685052542e-04, 1.189380294392470e-02, -5.599209585119088e-03, 1.936513970464256e-01, 5.730895895270894e-01, 5.152348664441486e+00, 6.269819752837946e+02, -1.324620585019138e+05, 7.077097842247981e+09, 3.971073631945782e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.406119899972515e-07, -1.762536122939550e-06, -3.678185740439543e-06, -7.486761626925790e-06, -1.386580203295235e-05, -1.811299465479571e-05, 4.188848817887370e-07, 2.303477800661436e-05, -5.736791393979253e-05, -3.226703646620106e-04, -1.491877389154656e-03, 2.015290442274826e-03, -2.709509337649081e-02, 2.600341339432892e-02, -1.263754601273877e-01, -9.505031994474122e-01, -1.000387166007636e+01, -2.860717143023254e+02, -2.208247606393363e+04, -1.141706392944863e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.689958367991205e-06, 5.640115593406560e-06, 1.177019436940654e-05, 2.395763720616253e-05, 4.437056650544752e-05, 5.796158289534627e-05, -1.340431621723958e-06, -7.371128962116596e-05, 1.835773246073361e-04, 1.032545166918434e-03, 4.774007645294898e-03, -6.448929415279445e-03, 8.670429880477060e-02, -8.321092286185255e-02, 4.044014724076406e-01, 3.041610238231720e+00, 3.201238931224437e+01, 9.154294857674414e+02, 7.066392340458762e+04, 3.653460457423562e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.102546188119633e-15, -3.939433766321806e-15, -1.515508929294772e-14, -6.409226487849298e-14, -2.991066195397708e-13, -1.426502361602562e-12, -4.484370598579702e-12, 2.016423367244569e-11, 5.196251447289194e-10, 1.264655183979631e-08, 1.069139893178985e-06, 3.297598243188850e-04, -2.882492438184385e-03, 8.618045315946051e-04, 1.237464579779691e+00, 1.862223038607516e+02, 2.546722494877620e+05, 6.496682631773224e+09, 6.906909765030892e+15, 1.883324145157465e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.936283327422470e-13, -1.659011480889097e-12, -5.844875191776666e-12, -2.178579210474041e-11, -8.482119200869642e-11, -3.120320508594594e-10, -6.766416728109469e-10, 1.791415099701337e-09, 2.177444927528564e-08, 1.863699489963210e-07, 4.294131253759603e-06, 5.105777020395068e-04, -2.963017147822270e-03, 4.601851022654266e-04, 2.072704379228102e-01, 5.419660489507996e+00, 6.252518075652645e+02, 5.227413240438335e+05, 4.931811540961886e+09, 1.817783238296314e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.579610664775191e-12, 5.308836738845112e-12, 1.870360061368533e-11, 6.971453473516931e-11, 2.714278144278286e-10, 9.985025627502701e-10, 2.165253352995030e-09, -5.732528319044279e-09, -6.967823768091403e-08, -5.963838367882273e-07, -1.374122001203073e-05, -1.633848646526422e-03, 9.481654873031264e-03, -1.472592327249365e-03, -6.632654013529927e-01, -1.734291356642559e+01, -2.000805784208846e+03, -1.672772236940267e+06, -1.578179693107804e+10, -5.816906362548204e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.210056444904701e-10, -6.986585527218135e-10, -2.254197606301372e-09, -7.405273296719380e-09, -2.405374586776575e-08, -6.825365550336668e-08, -1.020977065386625e-07, 1.591515011960639e-07, 9.124397578745575e-07, 2.746500257848208e-06, 1.724710053582113e-05, 7.905438158162375e-04, -3.045791379011841e-03, 2.457289566059725e-04, 3.471698110693559e-02, 1.577293332354948e-01, 1.535070364556609e+00, 4.206123453324918e+01, 3.521511921106742e+03, 1.754523197680746e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2lapltau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapltau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapltau"])
    tgt = out["v2lapltau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.072180623695043e-10, 2.235707368709803e-09, 7.213432340164391e-09, 2.369687454950202e-08, 7.697198677685042e-08, 2.184116976107734e-07, 3.267126609237199e-07, -5.092848038274045e-07, -2.919807225198584e-06, -8.788800825114265e-06, -5.519072171462763e-05, -2.529740210611960e-03, 9.746532412837891e-03, -7.863326611391119e-04, -1.110943395421939e-01, -5.047338663535834e-01, -4.912225166581149e+00, -1.345959505063974e+02, -1.126883814754158e+04, -5.614474232578387e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_br89_explicit_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_br89_explicit", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.263097799582414e-09, -7.154263579871371e-09, -2.308298348852605e-08, -7.582999855840646e-08, -2.463103576859214e-07, -6.989174323544749e-07, -1.045480514955904e-06, 1.629711372247695e-06, 9.343383120635470e-06, 2.812416264036565e-05, 1.766103094868084e-04, 8.095168673958273e-03, -3.118890372108125e-02, 2.516264515645158e-03, 3.555018865350205e-01, 1.615148372331467e+00, 1.571912053305968e+01, 4.307070416204717e+02, 3.606028207213304e+04, 1.796631754425084e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
