
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.556671624631048e+00, -4.463791411787502e+00, -4.333690920309328e+00, -4.153568910528872e+00, -3.908340692135861e+00, -3.582406324458048e+00, -3.163813594685781e+00, -2.651606019064319e+00, -2.064842366627330e+00, -1.444560856776564e+00, -8.418334036212434e-01, -4.606110526555498e-01, -4.658312507699066e-01, -3.672340672418644e-01, -2.159262089300068e-01, -7.481533624731281e-02, -5.633815174156953e-04, -3.866303553578165e-03, -9.171192476334282e-04, -1.024046612955455e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.919185712087921e+00, -5.790822482694854e+00, -5.610767950792051e+00, -5.360979328856444e+00, -5.019912993304415e+00, -4.564776951759153e+00, -3.977395878248247e+00, -3.256403347401055e+00, -2.439111286078117e+00, -1.627019766277126e+00, -9.586008104870475e-01, -7.538468138759794e-01, -6.945994642405851e-01, -5.175304262606614e-01, -3.054010802528983e-01, -1.389758983286980e-01, -4.486083486139662e-02, -4.931754871870614e-03, -1.212894253221398e-03, -1.364627620395606e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.908254475790916e-06, -4.240415862716459e-06, -4.766231228611933e-06, -5.633547700190078e-06, -7.149778556879287e-06, -1.002484010105263e-05, -1.611942383195317e-05, -3.109827182082796e-05, -7.548849106085358e-05, -2.434570621247191e-04, -1.317175867349729e-03, -1.165037326751176e-02, -1.240788434133746e-02, -2.113961255028527e-02, -5.479487506143861e-02, -4.020339009739277e-02, 2.960929256591440e+00, 2.428161471599971e+00, -3.641554385625737e+00, -3.802088502330742e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.242876081641752e-03, 4.302007188783958e-03, 4.387049387203968e-03, 4.509140151866135e-03, 4.683638645210860e-03, 4.930413077803187e-03, 5.270975957612737e-03, 5.715764355343719e-03, 6.234684690556375e-03, 6.814084794296316e-03, 8.893742793609551e-03, 2.213645215853113e-02, 2.802030091648687e-02, 2.649704496177278e-02, 2.323420216629028e-02, 1.453648352165873e-02, 3.814772209442286e-03, 2.359076866380052e-04, 2.561517252086496e-06, 3.580871266686757e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.380405733139578e-02, -1.445548824771697e-02, -1.544547544405778e-02, -1.698532029556173e-02, -1.945875748138442e-02, -2.360685247147515e-02, -3.094495345101985e-02, -4.463014819256289e-02, -7.045212631224676e-02, -1.145188378108353e-01, -2.466695667955759e-01, -8.592749363987288e-01, -7.919740550125546e-01, -1.281284381826948e+00, -2.249192756991849e+00, -1.289606168082281e+00, 1.208067594356156e+01, -9.049818140598899e+01, -1.397671879973914e+03, -1.175277535237068e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.703047656987187e-08, 3.084209447614595e-08, 3.722471420236498e-08, 4.861342193934113e-08, 7.079061013263886e-08, 1.192858209212810e-07, 2.413487486724350e-07, 5.875296376898743e-07, 1.328211315037447e-06, -9.004376024123687e-06, -3.947271600055231e-04, 2.125166119434847e-02, 4.432531723647551e-02, 8.135210087787603e-02, -1.705637892053683e-01, -3.723876689019302e+01, -3.745687596466605e+03, 1.562429705160060e+05, -1.760134347196577e+05, -9.391411531917101e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.431691360294610e-06, 2.932637051614707e-06, 3.773533072044879e-06, 5.274560618980243e-06, 8.186297922873214e-06, 1.449459344269619e-05, 3.027088023607711e-05, 7.752587975361822e-05, 2.530225197143658e-04, 1.075602334399170e-03, 5.779080354308269e-03, 1.167877975036505e-02, 6.221332918560992e-03, 5.524169620709533e-02, 2.905518851042166e-01, 1.474348844134435e+00, 4.812686797498318e+00, 7.982246683393748e+00, 9.097107020571530e+00, 9.284365286895031e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.837308438635966e-14, 8.907803848009638e-14, 1.299581387545862e-13, 2.224747970065347e-13, 4.765925934885292e-13, 1.393553475529203e-12, 6.231683578273467e-12, 4.912778190116814e-11, 8.073233226706340e-10, 3.398597942821440e-08, 5.472657270075784e-06, 1.624231883995416e-03, 3.555581235635244e-03, 2.794399318391037e-02, 1.326705539506095e+00, 2.205403955048629e+02, 8.529164143317532e+04, 6.175762170945864e+07, 1.705502363573307e+11, 7.161545448144895e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.101580463347752e-10, -1.300193744653861e-10, -1.648539297418562e-10, -2.314231913426069e-10, -3.751577467194925e-10, -7.440119173191816e-10, -1.949764584885663e-09, -7.456899458030850e-09, -4.710443103901619e-08, -5.800171426806146e-07, -1.978879788185696e-05, -1.654489331521324e-03, -7.910541873387075e-03, -2.905203196766336e-02, -3.036956116178120e-01, -7.049808296351988e+00, -1.918558208660278e+02, -3.978715517181794e+03, -9.351521894864197e+04, -5.307192362334110e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_xc_lc_tmlyp_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_xc_lc_tmlyp", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00, 0.000000000000000e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
