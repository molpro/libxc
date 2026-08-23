
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mtask_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.361612269942702e+00, -5.252586064763024e+00, -5.099706589227536e+00, -4.887691507803288e+00, -4.598244875759621e+00, -4.211690911801843e+00, -3.710747329513029e+00, -3.086136683898132e+00, -2.340293352913607e+00, -1.505778895872496e+00, -6.053580175422336e-01, -4.006781714135747e-01, -5.779861432883657e-01, -4.967440090755352e-01, -3.289235181511118e-01, -1.634811287636319e-01, -5.755625637024128e-02, -2.027958218573584e-02, -3.068278880405032e-03, -1.408030046087700e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mtask_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.329960637436912e+00, -6.170205012524471e+00, -5.945476517206274e+00, -5.632383613434905e+00, -5.202168218851064e+00, -4.622843473123229e+00, -3.867305036046023e+00, -2.944302989395728e+00, -2.034198378597186e+00, -1.481401815310053e+00, -9.537980901319937e-01, -9.492318619027444e-01, -9.198304978492060e-01, -6.901674341461259e-01, -3.920350086099048e-01, -5.849282557481388e-02, 9.380786155911428e-02, -1.848064864693898e-02, -5.486183481309842e-03, -2.713603708135236e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mtask_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.394717579060448e-05, -2.597950554064094e-05, -2.920152719206555e-05, -3.452903392625122e-05, -4.387885597188382e-05, -6.171122119469234e-05, -9.972124268670290e-05, -1.916072319600001e-04, -4.171168394894405e-04, -8.380152049388441e-04, -3.208717299657060e-03, -4.389454131148267e-03, -2.255331678613368e-02, -5.947776051481963e-02, -3.000193182785797e-01, -3.154828520346252e+00, -3.324282817544114e+01, -4.943793953701407e+01, 3.782116661265237e+02, 1.768082921173893e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mtask_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.448918291140183e-02, 3.519971521610955e-02, 3.624206687121829e-02, 3.778209872434669e-02, 4.007551385182854e-02, 4.350659151687646e-02, 4.855281893808898e-02, 5.504485699494235e-02, 5.682679157262556e-02, 4.075026444346921e-02, 4.248422335583783e-02, 4.091990708699283e-02, 8.358898863216631e-02, 1.098425780691907e-01, 1.686890885247971e-01, 2.932488886804263e-01, 2.465202690286758e-01, 1.166648165931912e-02, 5.792908297398432e-06, 5.212273259067400e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mtask_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.361385099152584e-02, -3.617243639927821e-02, -4.024719437616139e-02, -4.704205873768066e-02, -5.915988592339540e-02, -8.297878511948351e-02, -1.365935443407361e-01, -2.777672374546593e-01, -6.359388435896666e-01, -6.435038788242921e-01, -1.231633281979217e+00, -1.164979587814243e+00, -7.425620805670679e-01, -1.793271274094156e+00, -7.835260731791796e+00, -5.613515598010883e+01, -1.086251498032057e+03, -3.931967299723384e+03, -1.396388387520889e+04, -6.347104020412759e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mtask_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.018437816721713e-07, 4.734458162813649e-07, 5.994329110894443e-07, 8.417119598375790e-07, 1.371255267430887e-06, 2.761883584659689e-06, 7.491025871638134e-06, 3.002997685520452e-05, 1.703563045691288e-04, 4.079797467017851e-04, 2.957931995824369e-03, -1.085374973410965e-02, 6.719509014491613e-02, 4.025471442988203e-01, 7.781651927166041e+00, 3.546505289954505e+02, 2.112681209923649e+05, 2.859254836870732e+07, 2.336074463551031e+09, 8.466378989406594e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mtask_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.812471949282734e-04, -4.268689016391368e-04, -5.021478546577120e-04, -6.340146259199472e-04, -8.855367646243409e-04, -1.426251934989042e-03, -2.792001037328818e-03, -6.936566508889473e-03, -1.932081292352309e-02, -1.189131651911801e-02, -2.415238014727943e-03, 6.876820180313625e-02, -7.327902718914206e-02, -2.146856232919657e-01, -1.472803225342247e+00, -8.033081641768012e+00, -1.540350427432409e+03, -7.801830070657858e+03, -9.795925044165027e+02, -1.406553310560873e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mtask_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.328993820683614e-12, -8.080889976921095e-12, -1.147730233934657e-11, -1.898548988899890e-11, -3.903386858843526e-11, -1.092252478072506e-10, -4.700456633220281e-10, -3.589791257332760e-09, -5.004568792752925e-08, -2.950617399270635e-07, -1.624649559014473e-05, -9.287381873419172e-04, -2.371967809709932e-03, -8.637658579900448e-02, -4.567109665996560e+00, -7.510022131113020e+02, -4.393618156607251e+07, -2.058657210060146e+11, -1.342702975054339e+15, -3.081149860089274e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mtask_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.940922030095974e-09, 1.073775994990727e-08, 1.396661992887342e-08, 2.036228851007073e-08, 3.492845178608565e-08, 7.540250981958947e-08, 2.239474209531340e-07, 1.008196449920752e-06, 6.642592685164277e-06, 1.348075608533877e-05, 1.824914435115002e-04, 2.777179376343768e-03, 4.908148039659753e-03, 1.176154001340700e-01, 1.883735455258145e+00, 1.002819194698246e+02, 3.715082962109673e+05, 5.651088410316593e+07, 7.978439802255715e+08, 8.441354711085439e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mtask_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mtask", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.260047045941311e-05, -1.423514249976809e-05, -1.695855354630401e-05, -2.179471879271030e-05, -3.119894139114332e-05, -5.197701930376502e-05, -1.065859142343818e-04, -2.830169047895455e-04, -8.821036743725464e-04, -6.261869867878752e-04, -2.355201637942825e-03, -1.092496279877043e-02, -3.065234497660451e-03, -1.597439522212399e-01, -8.473303743121426e-01, -1.302948546710802e+01, -3.101331320204828e+03, -1.516852679635422e+04, -1.881940015671206e+03, -2.659590205812829e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
