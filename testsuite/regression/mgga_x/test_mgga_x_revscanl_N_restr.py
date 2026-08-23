
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_revscanl_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.885392040280302e+00, -4.786555800967261e+00, -4.648029163573114e+00, -4.456065948124008e+00, -4.194347352913540e+00, -3.845725350614875e+00, -3.396163970671926e+00, -2.836423262668978e+00, -2.195138208359506e+00, -1.515585732664180e+00, -8.312737994676146e-01, -5.727328045478163e-01, -6.283268012392933e-01, -5.064895001834688e-01, -3.380779271219149e-01, -1.732747945799904e-01, -6.319737968542327e-02, -1.650867390399271e-02, -2.184583004751332e-03, -9.998721476809451e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_revscanl_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.524108037862822e+00, -6.392803161218890e+00, -6.208808976552257e+00, -5.953922179088689e+00, -5.606588309105507e+00, -5.144282513406264e+00, -4.515536463670399e+00, -3.586319160189302e+00, -2.671113268687410e+00, -1.596098312560877e+00, -1.056417403863453e+00, -7.761841242241868e-01, -7.466645761060360e-01, -5.924546917518489e-01, -3.540775649039998e-01, -1.924770888432669e-01, -8.801670033398329e-02, -2.689485251980543e-02, -3.936147553274406e-03, -1.928539022697816e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscanl_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.100018212929167e-07, 1.226249320421338e-07, 1.431478365245816e-07, 1.782899529086841e-07, 2.429997539990468e-07, 3.747650055335512e-07, -1.313825277234116e-08, -9.787392850650436e-06, -4.125533936745025e-05, -3.279518228561243e-04, -9.488367915323217e-04, -6.738020980530706e-03, -1.502376929814262e-02, -2.942523825436787e-02, -1.644752271870514e-01, -6.227025375093996e-01, -8.510420600868200e-01, 1.088495839836768e+01, 2.799974325468822e+02, 1.264280347681664e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscanl_N_restr_1_vlapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vlapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vlapl"])
    tgt = out["vlapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 6.239747974619278e-05, 5.939233131057301e-04, 1.135542889342173e-03, 3.034069069537553e-03, 2.270476260566801e-03, 2.920295883348219e-03, 8.713131866245987e-03, 9.383497566706860e-03, 1.693929100190163e-02, 1.173552507521868e-02, 2.275517735902730e-03, 7.394427243381652e-06, -7.149390617091034e-07, -3.698518134322903e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscanl_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.195942728580454e-02, -1.244875609392688e-02, -1.318652053783668e-02, -1.432183152317817e-02, -1.612079505879988e-02, -1.909321999756363e-02, 1.995069701499813e-02, 5.725397598750136e-02, 1.091656518510226e-01, 3.471533453679050e-01, -3.676305464988800e-01, -6.597168893877496e-01, -4.730472663980176e-02, 4.436288151519325e-01, 4.004256473881112e+00, -6.698867000177333e+02, -8.677125474040928e+01, -4.385966042076969e+02, -1.018568154308106e+04, -4.528479533054606e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscanl_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.972885012911135e-09, -2.301450425226423e-09, -2.867346894945197e-09, -3.919971372130049e-09, -6.102407343089279e-09, -1.136785498733932e-08, -9.436058739371689e-07, -4.610578699150570e-06, -2.591999635001358e-05, -3.627629962981537e-04, 1.047481473793874e-03, -3.240508400234048e-03, -7.857367458113211e-02, -4.827772622149271e-01, -1.101137907810678e+01, 9.438519426095858e+03, 1.163864947744071e+04, 3.746639241354032e+05, 1.543861591778583e+09, 6.115750947360491e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscanl_N_restr_1_v2rholapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rholapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rholapl"])
    tgt = out["v2rholapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 8.309607298709155e-05, 2.501964084320768e-04, 6.877807494122311e-04, 3.607629322540951e-03, -1.826820394136617e-03, 8.543519569067111e-03, 5.959105136586935e-02, 1.761566189277106e-01, 1.288001085839171e+00, -1.658063588498264e+02, -1.601768984358923e+01, -8.704709292358584e-01, -1.117017684070165e+01, -4.174652767273631e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscanl_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.238113796377697e-14, 1.521098355721296e-14, 2.040343830000964e-14, 3.097144927081909e-14, 5.584352788970701e-14, 1.273369741665303e-13, 1.986742462043842e-11, 2.540829120357953e-10, 4.564515372847801e-09, 3.190399302060790e-07, -1.263632792160149e-05, 6.356235434784744e-04, 2.250029762424664e-02, 2.377463065016074e-01, 2.315261656589548e+01, -1.342686444931841e+05, -2.799827721423514e+06, -2.081123193990965e+09, -7.861758142365959e+14, -2.237362071915599e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscanl_N_restr_1_v2sigmalapl():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmalapl")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmalapl"])
    tgt = out["v2sigmalapl"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, -1.743286496334778e-09, -1.304165187108824e-08, -1.111826075839106e-07, -2.766599311097587e-06, 3.345939645178407e-05, 2.973014361931732e-04, -1.147554429309226e-02, -6.798678661006312e-02, -2.237971174526291e+00, 2.371368709715454e+03, 4.300321887344969e+03, 1.372222400898023e+04, 5.203526924138771e+06, 1.433215902004399e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_revscanl_N_restr_1_v2lapl2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_revscanl", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2lapl2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2lapl2"])
    tgt = out["v2lapl2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 1.561032780081121e-07, 6.757414874239076e-07, 2.723070128280358e-06, 2.406721798049439e-05, -8.361768986148754e-05, -4.181856506972656e-04, 6.150858870156785e-03, 1.999636455019490e-02, 2.181742541425402e-01, -4.187668633819798e+01, -6.724416784983309e+00, -7.418207405777433e-01, -1.011844055081738e+00, -3.279707425156926e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
