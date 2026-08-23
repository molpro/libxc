
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_24_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.217363083210985e+00, -5.117303674035183e+00, -4.976853587476297e+00, -4.781723626354934e+00, -4.514424342310160e+00, -4.154993620828880e+00, -3.682218549669047e+00, -3.072967242727772e+00, -2.301039076508433e+00, -1.419893441023617e+00, -7.628201567337235e-01, -5.248007962349855e-01, -5.826133667120519e-01, -5.069892899862138e-01, -3.240136206146962e-01, -1.495591614566248e-01, -5.754459032347935e-02, -1.775906386901354e-02, -3.654067614590962e-03, -4.034565588388016e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_24_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.287827154271034e+00, -6.152775241643442e+00, -5.964251537348731e+00, -5.704752271927729e+00, -5.355102752764397e+00, -4.899545012480210e+00, -4.337873398638560e+00, -3.704686182446451e+00, -3.036276242002120e+00, -2.123822751248371e+00, -1.116192156262785e+00, -8.060549547881111e-01, -8.880690161492978e-01, -7.001382484793240e-01, -4.771065557196832e-01, -2.227489395239187e-01, -8.116874904174426e-02, -2.480561164575760e-02, -5.116902182211809e-03, -5.664755520834837e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_24_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.233548848505383e-05, -1.332589796345966e-05, -1.488281493474816e-05, -1.742369318505999e-05, -2.179149873919235e-05, -2.984284235947673e-05, -4.603259274673747e-05, -8.145292752452655e-05, -1.584902271617921e-04, -2.855614486187165e-04, -6.029386009698502e-04, -4.822703522878572e-03, -2.802428157076818e-02, -6.450726304742711e-02, -1.486668444310595e-01, -2.209028825909440e-01, 1.242080371630266e-01, 5.947367699017613e+00, 1.767492868642736e+02, 1.608679229074447e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_24_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.174038982883051e-02, 1.211699637802554e-02, 1.268189803249275e-02, 1.354398809599187e-02, 1.489009509175994e-02, 1.704955849516866e-02, 2.057942467617871e-02, 2.606111717224025e-02, 3.134478902020978e-02, 2.462147711437102e-02, 1.023215730786555e-02, 1.449864727056613e-02, 7.434757693130882e-02, 1.155984507003026e-01, 1.258713109529623e-01, 4.408167812895325e-02, 2.011994932163048e-03, -1.318691350142097e-03, -3.887474188395501e-04, -4.882126568406932e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_24_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.652786765118090e-02, -1.721927296605244e-02, -1.823945310578304e-02, -1.974877547567563e-02, -2.196096299271512e-02, -2.503197551982344e-02, -2.836003089575711e-02, -2.789636333071072e-02, -2.208386841714592e-02, -1.220385238918205e-01, -3.844050272665729e-01, -1.018684389383304e+00, -8.579374328000415e-01, -1.031738313172029e+00, -2.392999375298930e+00, -8.765934654270433e+00, -2.402965102863058e+01, -1.928986955887524e+02, -4.372864673586118e+03, -3.552061672622361e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_24_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.037902034667301e-08, 9.146830440961088e-08, 1.099442109325256e-07, 1.426230473273175e-07, 2.051817197957569e-07, 3.367473664956152e-07, 6.322793869104815e-07, 1.118263609549380e-06, -2.532701429055364e-06, -7.397707192566073e-05, -7.496181367481940e-04, -7.496474026550267e-03, 2.687256122425442e-02, 7.372236045539815e-02, -2.339328520861659e+00, -6.298661465986955e+01, -2.078043122205077e+03, -4.345405376988147e+05, -1.167628610386185e+09, -7.548923284287294e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_24_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.509414893194718e-05, -7.233392883479245e-05, -8.409647936635298e-05, -1.041911262486252e-04, -1.409112726128218e-04, -2.138005752812940e-04, -3.692661708397634e-04, -6.681245288526717e-04, -4.665676595902192e-04, 4.864715853607858e-03, 1.365224389487775e-02, 5.909142188774265e-02, 2.614893382400687e-02, -1.515770230988727e-01, 1.552382925473577e+00, 9.657469243794715e+00, 2.091360553210718e+01, 1.123279682942332e+02, 2.585759950751769e+03, 2.291198497102864e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_24_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.962931854753795e-14, -3.648724054834757e-14, -4.897111956873256e-14, -7.384649804792158e-14, -1.290099391994315e-13, -2.594413524276573e-13, -4.026322978829761e-13, 5.967759161478125e-12, 3.098112509097769e-10, 1.663914668155035e-08, 1.108122714302383e-06, 7.331038743446514e-05, 1.260457723381889e-04, 5.769915425448985e-03, 1.095993951285378e+00, 2.855152323668182e+02, 2.585625801267116e+05, 2.817610638136726e+09, 9.948261607451169e+14, 5.039206297874437e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_24_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.471511566159210e-10, 4.205455760352285e-10, 5.538256649258247e-10, 8.217707658201832e-10, 1.444677710861074e-09, 3.223016572277259e-09, 9.958738156665632e-09, 4.647896016226412e-08, 3.247420798971254e-07, 2.545753226043028e-06, 2.621790490472101e-05, 1.478028949395747e-03, 2.535427363978089e-02, 1.831930453010274e-01, 2.565504213010373e+00, 2.386508928794957e+01, -1.468172177365082e+03, -9.261526434447017e+05, -3.183461852217726e+09, -2.242375089425041e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_24_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_24", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.657608552963625e-07, 2.826739849515350e-07, 3.050111460575328e-07, 3.287080313265606e-07, 3.256523112562691e-07, 1.409655974065798e-07, -1.141506665548641e-06, -9.810925281912766e-06, -6.990508252922795e-05, -3.295026811218500e-04, -8.053974387639530e-04, -7.432565425799982e-03, -6.159687907236115e-02, -3.050454277950705e-01, -3.041120870401547e+00, -1.049418630899112e+01, 4.729216924656291e-02, 2.723224476613635e+02, 9.191135249045366e+03, 8.969299997718330e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
