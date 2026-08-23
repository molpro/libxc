
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_m08_hx_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.550480653347402e+00, -1.509854471648509e+00, -1.458564090164489e+00, -1.398037110909516e+00, -1.332434515786561e+00, -1.263854998500059e+00, -1.186103518666538e+00, -1.149078002484014e+00, -1.209717503098828e+00, -9.241244264733928e-01, -5.918973375336344e-01, -3.059731650024206e-01, -2.693921801540989e-01, -2.362523722589349e-01, -1.998549324357680e-01, -1.226669349970717e-01, -4.020070834466171e-02, 9.795428488935666e-03, 3.712384029974678e-03, 4.207314833502824e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_m08_hx_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.287286310331154e+00, -2.141128440641050e+00, -1.943543840724006e+00, -1.699309568955115e+00, -1.452312315074364e+00, -1.286690839698678e+00, -1.100797476753845e+00, -3.443631776241223e-01, -5.171456660626635e-01, -8.713838232178813e-01, -6.158265272541180e-01, -3.386592673139294e-01, -1.916185770273602e-01, -8.259601182014427e-02, -2.070758397433042e-01, -1.647995515633773e-01, -7.011104795827117e-02, -3.049936137088119e-04, 4.781832694903724e-03, 5.607306609980877e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_hx_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.086873962098676e-06, -6.042862013204015e-06, -4.471237715092967e-06, -2.123688009738602e-06, 1.224234040186051e-06, 5.229466436028658e-06, 6.772341871750241e-06, -7.015219828015930e-06, -7.188840876139378e-05, -2.280076547198275e-04, -9.439474206940590e-04, -1.003816272158041e-02, -9.428895627870691e-03, -2.219243067391195e-02, -1.151684830026834e-01, -2.195972869545372e-01, -2.299434456507342e+00, 4.694377366257172e+00, 8.870183543446156e+00, 9.981981633332781e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_hx_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.149106956703403e-02, 1.605497602853425e-02, 8.724568010537004e-03, -3.894099348042190e-04, -9.771392727745765e-03, -1.569269349988188e-02, -1.720204493192762e-02, -2.700316244988650e-02, -1.346765181513816e-02, 5.389744051402036e-03, 5.691424747979549e-03, 4.860583605980693e-03, -5.662804954200786e-02, -1.009239155039811e-01, 3.898293270810253e-02, 2.883711707689041e-02, 3.887039491570054e-02, 9.836950801407536e-03, 1.302033291893198e-04, 2.027163218030043e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_hx_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.662638385446366e-02, -1.769666749698941e-02, -1.792825008907297e-02, -1.555222371759710e-02, -8.024698593388110e-03, 3.007865140659909e-04, -3.414904272977586e-02, -1.215185527865381e-01, 2.336491761867597e-01, -1.215734023255522e-01, 4.414614421916490e-01, -7.632178627338120e-02, -1.572311592020378e-01, 4.760589802888168e-01, -1.978615741840822e+00, 1.278886242492525e+01, 2.157012659280041e+01, -1.095372270461289e+03, 3.715472495847877e+03, 4.821002323640725e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_hx_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.322313158993382e-07, -3.512494494668475e-07, -3.745371183917259e-07, -3.950685902107920e-07, -3.813946307585158e-07, -2.131077994450768e-07, 5.359209388795027e-07, 3.133615261089498e-06, 6.954189672160508e-06, -5.197289695944230e-05, -1.226700096666438e-03, 1.233642947113788e-02, 1.399144441499901e-01, 4.714753589614896e-01, -9.858602406565962e-01, -1.073373779726940e+02, -5.665720679974708e+02, 4.279350492613406e+05, 1.230380455112067e+08, 1.034061262329734e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_hx_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.057694100842122e-03, 1.080401129050919e-03, 1.069736063057933e-03, 9.611382492868782e-04, 6.406717464721794e-04, 1.060952556311028e-04, 2.978083638221461e-04, 1.612724427143801e-03, -7.656025519434035e-03, 5.275201727041514e-03, -3.416192998625062e-03, -2.262394474562794e-02, -1.492333170566413e-01, -1.095302869375887e+00, 1.237606766343760e+00, 1.731776096130710e+00, -2.852614667107312e+01, 7.867129018157283e+02, 1.358765521003751e+03, 1.575058173566412e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_hx_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.605205989848196e-13, 1.570343264809786e-13, 1.374316102947208e-13, 6.343614676703987e-14, -2.014033211612565e-13, -1.170466463582019e-12, -4.425940670812695e-12, 1.090678830029113e-12, 7.383943801833242e-10, 4.012092270401662e-08, 5.487828547498229e-06, 7.813318529167590e-04, 1.786556815666431e-03, 2.428889435266426e-02, 3.139428480698116e+00, 6.556838161509349e+02, -6.717453288818080e+03, -1.706082911791540e+09, -4.503982272034624e+13, -2.915467490724108e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_hx_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.032094964624122e-09, 9.420878943244847e-09, 9.856288197595169e-09, 1.011743841013548e-08, 9.358277420511020e-09, 4.612883450149075e-09, -1.384627573879877e-08, -7.323610112813600e-08, -1.814587920607644e-07, 1.006494641636235e-07, -1.581878161678745e-06, -4.031742110095630e-05, -4.545970445054192e-02, -2.328069487990486e-01, -3.349246415508048e-02, 6.852548170906879e+00, 2.919392535169156e+03, 1.174544590737565e+05, 9.408068672986516e+05, 1.078288158613504e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_m08_hx_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_m08_hx", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.734019674214781e-05, -4.734211111676128e-05, -4.597424162572877e-05, -4.105470316208736e-05, -2.856419152087280e-05, -6.250436998587517e-06, 5.416519892326974e-06, -2.077224836880439e-06, 2.396789360303120e-04, -1.526649760558494e-04, 8.894528880701919e-05, 1.786860792112169e-03, 1.264473160152075e-01, 1.098485024900219e+00, -8.661804345088358e-01, -2.618823119306789e+00, -2.137598198875980e+01, -8.202021254573572e+02, -1.455700269717396e+03, -1.796904915753142e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
