
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_pkzb_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.327422678755139e+00, -4.244096533943444e+00, -4.127444709294774e+00, -3.966083863101682e+00, -3.746707777323151e+00, -3.455827363026891e+00, -3.083865025329777e+00, -2.632611558193248e+00, -2.124859003448742e+00, -1.599795122694804e+00, -1.043413050548331e+00, -6.688288291346214e-01, -5.582600654051105e-01, -4.662199692270302e-01, -3.436177723317654e-01, -2.346820525338637e-01, -1.283040617110827e-01, -4.236049658742853e-02, -8.774358517305878e-03, -9.701687042841441e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_pkzb_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.452598112423673e+00, -5.335317171385452e+00, -5.170711562649779e+00, -4.942126468460887e+00, -4.629444146849582e+00, -4.210707577715959e+00, -3.666296894998288e+00, -2.987205334408461e+00, -2.192847713788640e+00, -1.393019461721929e+00, -9.130553672831688e-01, -7.612146847127755e-01, -7.275410251885870e-01, -5.613569218831550e-01, -3.362051063224722e-01, -1.590943933353848e-01, -1.477509729204136e-01, -5.634073890675209e-02, -1.169908370472065e-02, -1.293558271298653e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pkzb_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.043249741115925e-06, -4.393273441963282e-06, -4.950107036980692e-06, -5.875907482796087e-06, -7.515955679045428e-06, -1.069832295837529e-05, -1.773277024970862e-05, -3.642096772580088e-05, -9.991029985762824e-05, -3.811281436691351e-04, -1.603579185307158e-03, -1.357995257166476e-04, -9.811218132621263e-03, -2.946321279582187e-02, -1.477892420476744e-01, -1.090333930532329e+00, -2.156380985775889e+00, -4.324166060569582e-01, -2.266674715251966e-02, -3.105626956365231e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pkzb_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.452941077025203e-03, 1.488898971786689e-03, 1.542383325573003e-03, 1.623124021945874e-03, 1.747642839136443e-03, 1.945633415654686e-03, 2.274060431210927e-03, 2.847870808498675e-03, 3.879795609845465e-03, 5.422561583553363e-03, 3.895344100035187e-03, -1.122668845602450e-02, 3.824498170533971e-03, 1.112480318545249e-02, 2.165024993039235e-02, 3.399028741958769e-02, 6.543054624715785e-03, 4.531532335211639e-05, 2.140688576454475e-08, 3.990141454250206e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pkzb_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.305016123466934e-02, -1.370899267155635e-02, -1.472145253011796e-02, -1.632455129402120e-02, -1.897684737365773e-02, -2.365953207024476e-02, -3.275914658515622e-02, -5.302055945518276e-02, -1.055896543138544e-01, -2.385990698961566e-01, -5.673356736881348e-01, -6.671479808516192e-01, -6.857744762524829e-01, -1.355910855053671e+00, -4.525951740447502e+00, 3.457918372380481e+00, 1.001531555925572e+02, -5.476230352943379e+02, -1.365183024046937e+04, -1.116831673071540e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pkzb_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.402861353575062e-08, 3.943466923403252e-08, 4.874256857484593e-08, 6.608525436142856e-08, 1.022858443413109e-07, 1.912324526310750e-07, 4.669257657782528e-07, 1.646661682461500e-06, 9.229513661689925e-06, 7.944182674271365e-05, 1.650171115141310e-03, -1.301637044067616e-02, 2.324473253191678e-02, 2.115936385349930e-01, 3.379019979751904e+00, -6.053622014159259e+01, -1.422811002418278e+04, -1.137758262431271e+05, -6.846299956509840e+05, -6.928185803105616e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_pkzb_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.593985898485909e-06, -7.305136473369189e-06, -8.463640412334481e-06, -1.045601267687406e-05, -1.415784781333117e-05, -2.182955942834044e-05, -4.031229007471790e-05, -9.435754553714342e-05, -2.859093378075497e-04, -9.843138092778599e-04, -7.597480892344943e-03, 3.656105994785458e-02, 1.330126157687988e-02, -5.241419043836513e-02, -4.546953800038701e-01, 2.246526035927575e+00, 4.592544028935558e+01, 1.273584252878538e+01, 6.937711235101522e-01, 9.574467765124627e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_pkzb_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.328949660750750e-14, -9.288611642289536e-14, -1.304787186969634e-13, -2.122650577927843e-13, -4.253482592917366e-13, -1.143098582025473e-12, -4.612857552995396e-12, -3.198924559372215e-11, -4.193012544673136e-10, -8.612260936182400e-09, -6.141353434113470e-06, -8.593974293270243e-04, -3.906326030027267e-03, -3.719245353481988e-02, -1.647254581365417e+00, 1.012742992723381e+03, 1.510608550878177e+06, 3.945287331648052e+08, 2.860070322512239e+11, 2.243326799241438e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_pkzb_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.089744693154052e-11, 8.473511324758455e-11, 1.094313288651583e-10, 1.578558104997017e-10, 2.664933130611854e-10, 5.617414759539287e-10, 1.613221298211490e-09, 7.042594031390003e-09, 5.225744439682497e-08, 7.375912002473291e-07, 6.245000544856921e-05, 2.092502789952693e-03, 7.600746531182663e-03, 4.233750003556493e-02, 8.130130507257768e-01, -2.532808069821753e+00, -3.952561055101113e+03, -3.783437889853777e+04, -2.499780775614212e+05, -2.679027252373029e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_x_pkzb_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_pkzb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.634047551106747e-08, -7.468407482882889e-08, -8.851585127122113e-08, -1.129024903385946e-07, -1.598441131882113e-07, -2.621673928624349e-07, -5.275659689181019e-07, -1.399154979782847e-06, -5.258905783070976e-06, -3.025150174829537e-05, -5.236826384667185e-04, -4.930616696688043e-03, -1.467988368264600e-02, -4.611721011186416e-02, -3.200696531378117e-01, -1.874642085169105e+00, 7.831255626559223e+00, 3.125631824753548e+00, 1.916806536498052e-01, 2.825268632076742e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
