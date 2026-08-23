
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_ktbm_16_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.116285408905004e+00, -5.015144445282141e+00, -4.873301686174338e+00, -4.676535929502075e+00, -4.407743348659647e+00, -4.048278726672949e+00, -3.580953593931987e+00, -2.994197812058681e+00, -2.287339494209970e+00, -1.511883789789381e+00, -8.855430231808787e-01, -5.969751950650133e-01, -5.764176739813206e-01, -4.983438557412266e-01, -3.367806146773463e-01, -1.782887168474981e-01, -7.539996097188729e-02, -2.390840573312629e-02, -4.947860041732905e-03, -5.474035384030981e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_ktbm_16_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.317083009895844e+00, -6.177870520108015e+00, -5.982916891890961e+00, -5.713181773524918e+00, -5.346575324738809e+00, -4.861498409038742e+00, -4.245931540409839e+00, -3.515677672288362e+00, -2.727074183413093e+00, -1.897923209546449e+00, -1.135280190172284e+00, -7.832733998590484e-01, -8.431737117244070e-01, -6.595274355919084e-01, -4.275379625808072e-01, -2.272346238620941e-01, -9.734672280361778e-02, -3.101777608732795e-02, -6.409669343656207e-03, -7.079782866712285e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_16_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.153043313909012e-05, -1.246865756556306e-05, -1.394679350372009e-05, -1.636748895999081e-05, -2.055246820836325e-05, -2.834372110915906e-05, -4.430808996052906e-05, -8.065879840300563e-05, -1.675046355254401e-04, -3.391822445800009e-04, -6.315254909581966e-04, -3.561555684396171e-03, -2.389443146776345e-02, -5.974174488473287e-02, -1.599349535990651e-01, -3.629869181940613e-01, -8.534029346049768e-01, -5.526420460625240e+00, -1.365697485652575e+02, -1.234443874650437e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_16_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.391268372191417e-02, 1.422700845601677e-02, 1.469018457324946e-02, 1.537896990031009e-02, 1.641453301080004e-02, 1.798605592034778e-02, 2.035202906798071e-02, 2.358137329963763e-02, 2.572553432182650e-02, 1.898362453324441e-02, 6.025492191457363e-03, 2.760919481877522e-03, 5.533071220122392e-02, 9.110272440926948e-02, 9.197349113939617e-02, 3.910888308160333e-02, 7.247187693901899e-03, 1.388403183144079e-03, 3.019931572507145e-04, 3.746627552647076e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_16_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.745821594796600e-02, -1.830400393855747e-02, -1.958438708688957e-02, -2.156138755334319e-02, -2.469024742717371e-02, -2.976885459074975e-02, -3.806859930454613e-02, -5.062665157305642e-02, -6.585775719172277e-02, -1.061891569542823e-01, -2.145642353728434e-01, -6.420490127339996e-01, -1.051011796905612e+00, -1.470714601807741e+00, -2.440622489321814e+00, -5.649774756878352e+00, -3.372748565460120e+01, -3.683268381189005e+02, -8.765718546105511e+03, -7.199629560797254e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_16_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.206212864254274e-08, 9.393337790233225e-08, 1.139418648124939e-07, 1.499996528416232e-07, 2.212869963825936e-07, 3.807166935525848e-07, 7.936008595964538e-07, 1.970631261596228e-06, 3.740832882644582e-06, -2.785218820441404e-05, -4.740994958526044e-04, -7.135834448570720e-03, 2.152071327365871e-02, 1.282972274974884e-01, -7.692362249198038e-01, -3.112280571247166e+01, -1.452078590606767e+01, 2.794100813526534e+05, 9.324784601875255e+08, 6.129237304351995e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_16_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.754343911581262e-05, -5.230116731602566e-05, -5.995305079188682e-05, -7.284559402485796e-05, -9.598279757438679e-05, -1.409425818253677e-04, -2.352764372401847e-04, -4.239115868856505e-04, -4.614059800544718e-04, 1.782719775407912e-03, 4.936273186023583e-03, 2.695563089596717e-02, 1.232732469483676e-01, 5.618115668109713e-02, 7.010610037211161e-01, 3.381941907284827e+00, 6.934314005995350e-01, -6.705937121546651e+01, -2.057031860032034e+03, -1.860208636497566e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_16_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.480979084236212e-13, -1.878102426715945e-13, -2.640222767011020e-13, -4.298841224783300e-13, -8.619430054603019e-13, -2.314403719856287e-12, -9.280761586298480e-12, -6.285241910247271e-11, -7.763609977647666e-10, -1.646425799336816e-08, -6.972427832600277e-07, -5.759777579799256e-05, -2.277932905002781e-03, -3.330452213674204e-02, -1.323414370212374e+00, -1.816452207532796e+02, -1.823112908114677e+05, -2.203233467653322e+09, -7.957340858564056e+14, -4.056944613038721e+22]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_16_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.292667757890221e-10, 5.180767670629191e-10, 6.786538346560692e-10, 9.995462531880608e-10, 1.739597546666697e-09, 3.831957598676126e-09, 1.169052677745656e-08, 5.454636305852819e-08, 4.028783521848250e-07, 3.809662403439148e-06, 3.961151944407061e-05, 1.352200431688757e-03, 2.472925679668991e-02, 1.953792595654374e-01, 3.323602355026510e+00, 7.276608248013113e+01, 2.977165226800892e+03, 8.084865588440566e+05, 2.526207758047596e+09, 1.778455453678741e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_ktbm_16_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_ktbm_16", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.481244558549382e-07, -5.177914554358594e-07, -6.373832138048282e-07, -8.592073252248414e-07, -1.318887023620051e-06, -2.433435877654967e-06, -5.786735334501721e-06, -1.897802278454655e-05, -8.303049530544696e-05, -3.226963015909999e-04, -6.620382273926199e-04, -3.945913311063152e-03, -9.346716407045774e-02, -4.233029496051240e-01, -2.907459943580180e+00, -1.234664919066793e+01, -3.628123570963545e+01, -2.668931963672683e+02, -7.281330092752501e+03, -7.058361768699016e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
