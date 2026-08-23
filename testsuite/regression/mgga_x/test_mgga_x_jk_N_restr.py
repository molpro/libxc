
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_jk_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.191419580744741e+00, -4.119120639827017e+00, -4.017552964320771e+00, -3.876342144219919e+00, -3.682922869754943e+00, -3.423597978017969e+00, -3.086373553713777e+00, -2.666579688886671e+00, -2.176119093614386e+00, -1.658586647205788e+00, -1.272424799349304e+00, -5.573076434495222e-01, -5.653050814913538e-01, -4.825349012339097e-01, -3.632934637678737e-01, -2.366488102706955e-01, -1.374605762254769e-01, -7.748905420106005e-02, -4.822972363302620e-02, -3.449295997392574e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_jk_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.525690237606283e+00, -5.405275197569524e+00, -5.238709306314282e+00, -5.011990495743475e+00, -4.710168738225364e+00, -4.320246840090655e+00, -3.836136373679281e+00, -3.265385121393344e+00, -2.637513748870196e+00, -2.026117572669500e+00, -1.912974630575793e+00, -9.984298899113644e-01, -7.233740450452987e-01, -5.941774254378664e-01, -4.451172431680165e-01, -2.984147835987271e-01, -1.826888016078556e-01, -1.112675421547627e-01, -7.554331775440665e-02, -5.813297987872432e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_jk_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.131335926464717e-06, -1.649142137073931e-06, -2.417638640510331e-06, -3.572270337538325e-06, -5.333801431850426e-06, -8.063696137175744e-06, -1.231163960199419e-05, -1.852734438543272e-05, -2.339341517725098e-05, 3.041566592361030e-05, 3.425730762921889e-03, 4.299985051460543e-02, -1.613416681322764e-02, -1.909309941479195e-02, 7.573902443414817e-03, 3.948727461559199e-01, 7.458740194311759e+00, 2.680425776325459e+02, 3.053036139626325e+04, 2.101147292584140e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_jk_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.839928363900738e-06, -1.976522936192290e-05, -3.921160679950158e-05, -7.645382824660691e-05, -1.455447226272405e-04, -2.682099294123965e-04, -4.733973164659514e-04, -7.915404891714847e-04, -1.252526971951115e-03, -2.028309538159420e-03, -7.982159423273941e-03, -8.488106633096102e-03, -2.246410573261577e-03, -5.606264587425750e-03, -1.029314720318998e-02, -1.371717215134879e-02, -1.543550423730608e-02, -1.554913048899052e-02, -1.436440392084348e-02, -1.252326073278068e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_jk_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.047711363750151e-02, -1.094338516419374e-02, -1.161583065134235e-02, -1.259214347233751e-02, -1.403251114404673e-02, -1.623684240346415e-02, -1.989312831048922e-02, -2.703653634173373e-02, -4.569972413609106e-02, -1.239532786021779e-01, -1.658159089951769e+00, 6.779237676748024e-01, -5.877339790967205e-01, -8.158079815854564e-01, -2.263089511517804e+00, -1.520515073682903e+01, -2.015906888877323e+02, -6.224090898002089e+03, -6.642491930734571e+05, -4.498608044094935e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_jk_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.044447990827915e-09, 5.489946448929938e-09, 7.083044923344702e-09, 8.049335984769414e-09, 5.571231726701344e-09, -1.007245086585126e-08, -7.158179827169157e-08, -2.611968487207306e-07, 7.975828973265577e-08, 4.375508767610692e-05, 1.123378385803345e-02, -2.258734295648508e-01, 9.350424112050012e-04, -4.561341687015625e-02, 1.483915035875293e+00, 1.557497643963360e+02, 3.512160549219790e+04, 4.029230048331349e+07, 5.404617273189236e+11, 2.866970888551937e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_jk_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.270912519621095e-08, 8.020617121607429e-08, 1.406816267239032e-07, 2.111907269931319e-07, 1.760541636616120e-07, -5.318515100938418e-07, -4.424077092157387e-06, -2.301857191374227e-05, -1.177043150284489e-04, -7.723480203753880e-04, -2.205968520861109e-02, 4.840117201297971e-02, 2.084717480318999e-04, -2.894670453466487e-02, -3.320644534440948e-01, -3.385653115527188e+00, -5.281692083872738e+01, -1.794287275601011e+03, -2.005893265713848e+05, -1.372854792006135e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_jk_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.714544261926106e-14, -5.622248769596439e-14, -4.681041394654802e-14, 4.239110932487707e-14, 4.565435583451093e-13, 2.292893996274757e-12, 1.121595995657752e-11, 5.816167198775227e-11, 4.130083500812368e-11, -5.038173874694670e-08, -8.484801587125900e-05, 4.267451942149489e-02, 1.327330033546234e-02, 6.310825935078032e-02, -4.041243910798120e+00, -2.380958698166913e+03, -6.767363224102337e+06, -2.586968676701208e+11, -4.209841064786081e+17, -1.739774872490262e+26]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_jk_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.027750287985204e-12, -4.298082106892710e-12, -9.161055431710601e-12, -1.952662496183778e-11, -4.059894250254897e-11, -7.336355254730390e-11, -2.263903616723850e-11, 1.390463215919194e-09, 2.317470668667716e-08, 5.796639578414890e-07, 1.326605899269031e-04, -1.205858300710217e-02, -2.692470398510977e-03, 1.296515558250667e-02, 5.774522297111617e-01, 3.678662510915847e+01, 7.616016043226619e+03, 8.882047506546339e+06, 1.228958540901516e+11, 6.655201711002382e+16]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_jk_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_jk", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.804474934575468e-11, -1.153353642286708e-10, -3.528036711330934e-10, -1.094164280627660e-09, -3.466518668535915e-09, -1.135556042759426e-08, -3.922674967355298e-08, -1.478945195746988e-07, -6.545328172840898e-07, -4.302407865113450e-06, -1.946829652360538e-04, 3.220837591200431e-03, -1.523704577977378e-03, -7.168847439606455e-03, -4.994309600405085e-02, -4.667208495664043e-01, -7.575721377766126e+00, -2.782430183846853e+02, -3.331764772649496e+04, -2.392664957355928e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
