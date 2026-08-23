
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_dk87_r1_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r1", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.311762079775614e+00, -4.230792101591661e+00, -4.117460446812454e+00, -3.960723564427482e+00, -3.747654995312879e+00, -3.465039127146534e+00, -3.102976655070158e+00, -2.660932618193235e+00, -2.154621695522335e+00, -1.617469337366899e+00, -1.084819139838373e+00, -6.679146497699165e-01, -5.629841566380930e-01, -4.752725858294717e-01, -3.518446422652485e-01, -2.284774782417265e-01, -1.353191615111311e-01, -8.261681070701282e-02, -6.154093537064203e-02, -5.572801900008412e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_dk87_r1_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.327349219877139e+00, -5.213104900814977e+00, -5.053152841613030e+00, -4.831889353956949e+00, -4.531139509156210e+00, -4.132721367897018e+00, -3.624536905212002e+00, -3.011668813951316e+00, -2.330272486867610e+00, -1.651548061460869e+00, -1.076885230892561e+00, -7.916247765664507e-01, -7.098306350755068e-01, -5.510546529372898e-01, -3.699882642046038e-01, -2.119275805593813e-01, -9.692965045340068e-02, -3.188926699664221e-02, -6.674003359409646e-03, -7.398334997600890e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_dk87_r1_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r1", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.524404718946479e-06, -4.891291389816372e-06, -5.467123974972067e-06, -6.404781742946565e-06, -8.012164672202719e-06, -1.096988909034539e-05, -1.695981393887155e-05, -3.074195091425472e-05, -6.845655393269115e-05, -2.032466013029954e-04, -9.842517020745354e-04, -7.938301887985194e-03, -1.516320931117910e-02, -3.070360845341055e-02, -9.341379577779832e-02, -4.964364851912296e-01, -5.660125517349409e+00, -1.763642309199332e+02, -2.052366017297260e+04, -1.555404019808128e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_dk87_r1_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.249777038090826e-02, -1.302917052105214e-02, -1.382511153017187e-02, -1.503625172562951e-02, -1.691740114843268e-02, -1.991326014200556e-02, -2.481726235267563e-02, -3.307796519481319e-02, -4.782800383732314e-02, -8.075120321969927e-02, -1.810623376983160e-01, -5.365021289332935e-01, -7.063136918958667e-01, -1.054863705188031e+00, -1.736692537155775e+00, -4.605821489435560e+00, -2.757022220656129e+01, -3.118783490496714e+02, -7.698310402339684e+03, -6.379220883665088e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_dk87_r1_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.770432189875329e-08, 3.101350416608223e-08, 3.638005227840828e-08, 4.550130700952535e-08, 6.196971660913040e-08, 9.383998771495207e-08, 1.587466910122624e-07, 2.768064402761160e-07, 1.875804076616681e-07, -5.086440179252597e-06, -1.128522036902226e-04, 8.861967427883012e-03, 4.861741694512883e-02, 7.240319656560130e-02, -9.807846009310564e-02, -7.831159380373528e+00, -3.613334067275060e+02, -4.144166005207790e+04, -2.469561680750808e+07, -1.765461558736736e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_dk87_r1_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_dk87_r1", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.417182170959879e-14, 8.803222563186353e-14, 1.360793942717154e-13, 2.468314747428157e-13, 5.540921731799523e-13, 1.650634248767642e-12, 7.141525414763293e-12, 5.025625027831532e-11, 6.634115212051040e-10, 2.054646050059323e-08, 2.476223526664368e-06, 6.602438865662359e-04, 2.054457211878127e-04, 4.430898697527469e-02, 1.844101948724716e+00, 3.464034750127274e+02, 5.454401528900050e+05, 1.655713435382284e+10, 2.609264794068184e+16, 1.135750974891907e+25]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
