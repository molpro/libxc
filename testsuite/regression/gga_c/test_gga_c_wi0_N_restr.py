
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_wi0_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi0", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.290612418452507e-02, -5.277304806200138e-02, -5.257188636355024e-02, -5.226084268698936e-02, -5.176353301035041e-02, -5.092780726031613e-02, -4.941507884853917e-02, -4.636637894720975e-02, -3.940209698715006e-02, -2.430878452821975e-02, -1.367893179159679e-02, -4.495017680382304e-02, -4.854630994103531e-02, -3.989976246789430e-02, -1.722809485776849e-02, -5.111389248235703e-04, 2.260275840644827e-04, 4.146991227567141e-06, -5.862874917740206e-10, -3.172011079523611e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_wi0_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.084332016165575e-02, -6.106480695132471e-02, -6.140362128338302e-02, -6.193646921546396e-02, -6.280896626267458e-02, -6.432344180851789e-02, -6.717554287366133e-02, -7.309718417456321e-02, -8.559009786083539e-02, -9.637370084242385e-02, -7.995020707494289e-02, -6.880637763224955e-02, -5.814053941257209e-02, -7.510927174928038e-02, -7.734010229368365e-02, -9.376669124850705e-03, 6.601426957132603e-04, 3.237314067235104e-05, -3.517724576721408e-09, -1.903206647622360e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wi0_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi0", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.180253254707319e-08, 9.107110494596844e-08, 1.062911125282590e-07, 1.327929678884562e-07, 1.830289231819403e-07, 2.907412372988756e-07, 5.668295023758852e-07, 1.478494453295808e-06, 5.613354549608926e-06, 2.790538131604207e-05, 1.698323657132581e-04, 1.749113389873671e-03, 2.900924938716148e-03, 1.201043823989905e-02, 5.347017183054643e-02, 4.660973986806927e-02, -2.432906037749093e-02, -6.048939654301747e-02, 7.449252709078792e-04, 3.129811812401705e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wi0_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.163284654706889e-05, 9.119058101358288e-05, 1.069450121473599e-04, 1.345198576138513e-04, 1.871330845024172e-04, 3.006530504607992e-04, 5.908334683715600e-04, 1.499129504451130e-03, 4.411008067471885e-03, -3.139013388826332e-03, -9.696016358943575e-02, 8.357741085615072e-02, 4.598872665133449e-02, 3.066954991857656e-01, -1.599496205771799e+00, -5.437932745485738e+00, 2.550760807487764e-01, 5.117177839829730e+00, -6.158132893837198e-02, -2.464784412140493e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wi0_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.724184310146400e-10, -1.037167151764563e-09, -1.330264661168149e-09, -1.903011322554380e-09, -3.184552356787641e-09, -6.668842745935859e-09, -1.915452858970309e-08, -8.369061898712528e-08, -5.395297822792476e-07, 1.093799917450010e-06, 2.428240269725723e-04, -6.593407867274645e-03, -1.761633897719012e-02, -1.125611053266421e-01, 1.379989802673304e+00, 2.777824483014434e+01, -2.167359434831405e+00, -1.077545192230665e+04, 1.564880518112272e+04, 4.863987656513141e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_wi0_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_wi0", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.018263989940101e-15, 1.326902117420743e-15, 1.938708920926405e-15, 3.332443304926837e-15, 7.199732602334630e-15, 2.132054590992328e-14, 9.520543079064221e-14, 6.319359454629422e-13, -5.713011537507433e-12, -3.613453383701325e-09, -1.086365253916123e-06, 1.260685171325925e-04, 1.929720571406163e-03, 4.975708157745604e-03, -2.480988102511648e+00, -1.778152230470694e+02, 2.389620331614543e+03, 2.992796602291316e+07, -5.207469484208980e+09, -1.256954012433160e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
