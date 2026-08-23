
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_k_rda_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.851576319010161e+02, -9.841765635094237e+01, -2.930958559488910e+01, 1.811649596654967e+01, 4.304226763931374e+01, 4.831766139915704e+01, 3.924650867124354e+01, 2.282279053458545e+01, 2.553415692765113e+01, 2.093174620321400e+01, 1.170551298931959e+01, 5.236598723828648e+00, 1.331817343132445e+00, 6.475257407633700e-01, 9.519850477493307e-01, 5.411126814180023e-01, 5.593749330952318e-01, 6.209850742988358e-01, 6.015738367687593e-01, 5.742172521113630e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_k_rda_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.616363295345045e+01, 1.562193669047965e+02, 1.963074204059780e+02, 1.904286368076107e+02, 1.522888383912563e+02, 1.003946084815531e+02, 5.056439314784932e+01, 1.298699307853402e+01, 1.613200817633791e+01, 2.209220393219526e+01, 1.078947949647942e+01, 6.167055258323479e+00, 1.706662010717372e+00, 4.444189877502816e-01, 1.036284153948628e+00, 3.030984589709303e-02, -6.271523206261621e-01, -6.734223545764210e-01, -6.047553772588374e-01, -5.742570267462208e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_rda_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.235237805784284e-04, 2.643923462331473e-04, 2.119477929430483e-04, 1.685303068765445e-04, 1.365508494892206e-04, 1.259688114329907e-04, 2.060936579434956e-04, 1.167722308671322e-03, 1.366324823573733e-03, 1.986128005597548e-03, -2.377103148081260e-03, -7.300534100959295e-02, 7.024668815512267e-04, 2.356166665142299e-01, 9.191827372669185e-02, 2.929834280418027e+00, 9.140036882031740e+01, 3.820599602201484e+03, 4.376230954547743e+05, 3.237673086608064e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_rda_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.359542449412558e-02, 1.182366523430922e-01, 1.367918069751692e-01, 1.399263533472073e-01, 1.174568605959469e-01, 6.007474664141696e-02, -4.375916278916048e-02, -1.118845259164892e-01, 2.486169311219876e-01, 6.108983590550224e-02, 7.172053266948429e-02, 1.050106876237218e-01, -8.790410152529700e-02, -1.543238462083091e-03, 9.851205403230513e-02, 4.897541191410377e-02, 2.946193777564136e-02, 1.807198960035885e-03, 6.987649462874793e-06, 1.635473730444887e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_rda_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.669510911353110e+00, 3.021270754324300e+00, 2.102229923829108e+00, 1.097356710699263e+00, 2.511566659954135e-01, -2.372410200678301e-01, -1.939751249433082e-01, 9.686370879419681e-01, 2.596634150083211e-01, 5.908352263931493e+00, 1.694797129289661e+01, 1.477221574646020e+00, -1.962735697652369e+00, 6.988883799825760e+00, 7.775157695036818e+00, 2.232811493023295e+02, 2.509227143238585e+03, 4.335698665202092e+04, 4.218276381215057e+06, 2.974639152753312e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_rda_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.097092249202134e-06, -4.078469504020170e-06, -4.140394881922883e-06, -4.428365392417212e-06, -5.208201164729178e-06, -7.192595808880899e-06, -1.364515051610191e-05, -5.918197351747432e-05, -1.854209007530949e-04, -2.942162384723354e-03, -4.243348313179895e-02, 1.960216475590694e-01, -1.443648031381497e-01, -2.119720282862031e+00, -1.596502361363939e+01, -1.424291665262784e+03, -2.725266250905450e+05, -1.381965280079826e+08, -1.533425247895136e+12, -8.386023512780659e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_rda_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.030132400637001e-04, 7.045624194639027e-04, 4.817884290721071e-04, -1.194337232937495e-04, -1.256502760124442e-03, -3.118533402499770e-03, -5.917460034364186e-03, -7.344084767674437e-03, 2.951521572778296e-02, 3.033023942297636e-02, 2.582414651830090e-02, 8.225322834467190e-02, -8.802501209906974e-01, -2.656379563482657e-01, 4.237974384762536e+00, 6.709159527074837e+00, 1.514288614411637e+02, 5.634808271419965e+02, 3.135467440210562e+02, 6.194011837416239e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_rda_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.752241658603488e-12, 4.395770876587958e-12, 7.159743173520166e-12, 1.267620672060201e-11, 2.691534724421492e-11, 7.956926026535131e-11, 4.066745023287788e-10, 3.025686243580808e-09, 3.517947803211762e-08, 1.419357246437181e-06, 2.322698004111303e-04, 1.142083809705650e-02, 4.933431825533111e-02, 4.346123700092265e-01, 2.069575292169592e+01, 9.594742153184065e+03, 2.131161681281571e+07, 8.248621254897211e+10, 6.545568253853890e+14, 7.730551192989567e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_rda_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.701752541792659e-10, -7.314717012625560e-10, -1.145356160227328e-09, -1.870596761093040e-09, -3.238557397379651e-09, -5.233426919771054e-09, 1.048831634479537e-08, 6.322009576094338e-07, -2.788262895386617e-06, -7.167007972497741e-06, -3.230289975936474e-04, -6.671236242954611e-03, -1.696172393779471e-03, 3.924239474014387e-01, -1.603592918479854e+00, -9.348093508083768e+01, -1.882685912055507e+04, -2.397595333948950e+06, -1.688813600656124e+08, -2.696296002313873e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_k_rda_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_k_rda", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.523728160595059e-07, 2.205658717637805e-07, 2.036976830106571e-07, -2.038022545473314e-07, -1.917706956898234e-06, -7.906599123728454e-06, -2.844523651579846e-05, 8.802488084651646e-05, -1.182294807679180e-04, -9.732714917496311e-05, 7.122515266282480e-04, 2.676500272209571e-05, -1.521667564668428e-01, 2.025100069774437e+00, -5.517544474598304e-01, 1.622694558962617e+00, 1.762302200500746e+01, 7.011214399815336e+01, 4.366849708797384e+01, 9.415219129567607e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
