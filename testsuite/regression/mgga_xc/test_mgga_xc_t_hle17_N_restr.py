
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_xc_t_hle17_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.421500201651408e+00, -6.292177742967448e+00, -6.110898966893229e+00, -5.859650654034293e+00, -5.517043230011385e+00, -5.060640817117321e+00, -4.472769256516272e+00, -3.752062531787583e+00, -2.933968394485763e+00, -2.116264272507835e+00, -1.390927559751943e+00, -9.197430801862615e-01, -8.089196098121428e-01, -6.846528497822273e-01, -4.819445927091878e-01, -2.999790784667158e-01, -1.621512360788233e-01, -5.653048171078323e-02, -1.183874828427377e-02, -1.309718304471393e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_xc_t_hle17_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.910548366997454e+00, -7.760544372306896e+00, -7.550108485771041e+00, -7.258023450043167e+00, -6.858582534377963e+00, -6.323189131459043e+00, -5.623652429829365e+00, -4.734988590522516e+00, -3.634729272846484e+00, -2.372134885829828e+00, -1.399898805772281e+00, -1.209747527578577e+00, -1.065145985757173e+00, -8.636240936361548e-01, -5.893322991307407e-01, -2.857793678817658e-01, -1.788552507454319e-01, -7.358706211099852e-02, -1.576729339973980e-02, -1.746265882476543e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.864695219847154e-05, -1.919551067015043e-05, -1.999997712129211e-05, -2.118738984544572e-05, -2.295426482755962e-05, -2.561610061087284e-05, -2.977384579165560e-05, -3.746623356046280e-05, -6.291205245563375e-05, -2.273872493544951e-04, -1.394619111514033e-03, -1.203248406237410e-04, -1.148952637711689e-02, -4.393012715940821e-02, -8.275120957699601e-02, -6.470261864215151e-01, -2.549240162059036e+00, -4.033144502686934e+00, -4.821153799529148e+00, -5.326098243617911e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.692714130074672e-02, 2.608722535938515e-02, 2.491053422577623e-02, 2.328102862209162e-02, 2.106297033786175e-02, 1.812376589454826e-02, 1.440245866734879e-02, 1.008273203551864e-02, 5.908325127126877e-03, 3.180305836593366e-03, 2.298973881862062e-03, -2.810701001418819e-04, 1.203708452909721e-02, 4.596855334662593e-02, 2.514377267581610e-02, 5.851075749984495e-03, 3.044469515698674e-04, 3.533604607465701e-06, 3.622352679127107e-09, 1.053437797647574e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.608951231298637e-03, -6.750782885747121e-03, -6.967080092945209e-03, -7.312348445095457e-03, -7.914171298160752e-03, -9.147287881090486e-03, -1.240373140955944e-02, -2.399414184492759e-02, -7.476132784802975e-02, -2.591972281854508e-01, -5.964917037506771e-01, -6.195998501919364e-01, -9.310397633139339e-01, -1.111656298521292e+00, -4.503095667014743e+00, -9.387351792965148e+00, 5.646315519280374e+01, -5.460952682959772e+02, -1.815397500000022e+04, -1.507429192561740e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.713979561466736e-07, -1.940180744982979e-07, -2.315383228855402e-07, -2.975907688747921e-07, -4.237877377816547e-07, -6.924526387003715e-07, -1.343667261655198e-06, -3.093680220353380e-06, -6.741554603893778e-06, 1.044764246296030e-05, 3.850329857342893e-04, 1.012146798277065e-02, 2.798791378980909e-02, -2.180179770930537e-01, -1.541250154158513e-01, -8.006415691986618e+00, -7.988818082541820e+03, -4.875597692570242e+05, -6.740528858673956e+07, -5.517967563599607e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.967179714526418e-04, 2.097685280842111e-04, 2.298409856266791e-04, 2.615592923248420e-04, 3.135264740430355e-04, 4.026805425760459e-04, 5.639390061834924e-04, 8.700609432269882e-04, 1.468876149892621e-03, 2.680915183117236e-03, 5.385154589294882e-03, -1.077773635252209e-02, 1.364450210268417e-02, 2.512204220349641e-01, 1.208970401142540e+00, 2.286825950780814e+00, 1.105728726073219e+00, 4.855568088150880e-01, 5.792243485296802e-02, 1.266003576620480e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.298119146917594e-12, 2.817187791307935e-12, 3.765937430993397e-12, 5.686611254838292e-12, 1.017616624852242e-11, 2.299202552957553e-11, 7.099345759949335e-11, 3.270617735952097e-10, 2.434046899925699e-09, 3.683665306968998e-08, 2.752055786551975e-06, -1.900616489382158e-03, -3.925203940937597e-02, 1.500873440592798e-01, 3.266385871815854e+00, 4.917707455322492e+02, 7.697868248407582e+05, 1.474385760992754e+09, 2.447927391286896e+13, 1.555599385212512e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_xc_t_hle17_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.292628465306367e-09, 2.374421014545380e-09, 2.469993336249931e-09, 2.539489147375204e-09, 2.409770844476515e-09, 1.353272945228969e-09, -3.963789508744587e-09, -3.134385729223265e-08, -1.960416131711678e-07, -1.344543369659541e-06, -8.755801538462471e-06, 1.115056467743408e-03, 4.469740944402436e-02, 4.459740575019044e-02, -1.094356791872727e+00, -8.053596659385141e+00, 4.629001165590007e+01, 6.677783541868052e+00, 7.221414919427924e+00, 2.881856359184712e+00]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_mgga_xc_t_hle17_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_xc_t_hle17", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.118422114874896e-05, -1.141154168476623e-05, -1.172702170075824e-05, -1.214971172693827e-05, -1.266967405999664e-05, -1.315725523676596e-05, -1.306339966123288e-05, -1.052498187668365e-05, -8.392225229347224e-07, 1.236950317438551e-05, -8.152397496734024e-05, -2.580330015646874e-04, -5.712255017311139e-02, -2.575247597640196e-01, -1.114897450003019e-01, -6.871412582342414e-01, -1.515373201313700e+00, -4.765331056881428e-01, -6.094853620025176e-02, -1.400733650832943e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
