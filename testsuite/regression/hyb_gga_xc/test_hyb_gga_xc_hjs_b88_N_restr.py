
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_hjs_b88_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.280842366662287e+00, -3.217968251029206e+00, -3.129879705933987e+00, -3.007884523153935e+00, -2.841717171635933e+00, -2.620717580719027e+00, -2.336654672477315e+00, -1.988922983146051e+00, -1.592036936583475e+00, -1.181026209689091e+00, -7.955311909010064e-01, -5.497600220579943e-01, -4.871808932836243e-01, -3.997025072074322e-01, -2.860150695665690e-01, -1.818559956849294e-01, -1.124034751930474e-01, -7.139112398708646e-02, -7.362549859880566e-02, -1.334573215046060e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_hjs_b88_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.220840683084503e+00, -4.134804987753966e+00, -4.014165859401378e+00, -3.846881284454118e+00, -3.618588546826812e+00, -3.314049311286799e+00, -2.920698017032193e+00, -2.435200496038055e+00, -1.873743619630716e+00, -1.296259230184074e+00, -8.459297994497077e-01, -7.129038987022711e-01, -6.376843457577204e-01, -5.184166346949352e-01, -3.529413834381623e-01, -1.873009124429585e-01, -8.237084885945388e-02, -3.856224935081567e-02, 6.956659404674098e-02, -8.828529158534324e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_b88_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.375357927929047e-06, -1.493800397345080e-06, -1.681356523830243e-06, -1.990962739220908e-06, -2.533236759302015e-06, -3.566457736134696e-06, -5.784785831207502e-06, -1.142778727644903e-05, -2.965036662059113e-05, -1.078695240427007e-04, -5.480042944656409e-04, -2.631941113338805e-04, 2.133896887667960e-03, 7.066388049029731e-05, -1.688283220690741e-02, -2.615888131931056e-01, -4.290099365210478e+00, -1.210917520865175e+02, -4.485051943721656e+04, 1.504922553420554e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_b88_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.944368142105861e-03, -9.351018738133746e-03, -9.968762604351538e-03, -1.093000271271348e-02, -1.247866892030468e-02, -1.510343294416033e-02, -1.989845585018925e-02, -2.971144014287132e-02, -5.311746605552235e-02, -1.109119911093894e-01, -2.847683162365210e-01, -4.167894822111969e-01, -4.786353238054117e-01, -8.841030027706667e-01, -2.758865162513922e+00, -1.108040746037556e+01, -2.035394568885829e+01, 1.796076985426704e+02, -3.918072213756791e+06, -1.283773191663749e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_b88_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.434388320444012e-08, 1.636719380657908e-08, 1.977687053165275e-08, 2.593394307108825e-08, 3.821204750950369e-08, 6.645605733877744e-08, 1.463918259691656e-07, 4.532223604637981e-07, 2.241347889778970e-06, 1.681569411945375e-05, 3.252636895087079e-04, 6.008969828530533e-03, 5.743624805948115e-03, 6.743137305553797e-02, 1.226789317814529e+00, 3.595593664201228e+01, -2.351115097956364e+02, -1.217379748665758e+06, 1.085344396707443e+12, 2.578585853627247e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_hjs_b88_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_hjs_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.585745078286557e-14, -6.626005831329727e-14, -8.454093569164820e-14, -1.194953036365150e-13, -1.946309343234016e-13, -3.837960470875874e-13, -9.665124210814256e-13, -3.179129307475907e-12, -2.219621343512393e-12, 2.660609281603674e-09, 2.936781397905808e-07, -5.163371626636643e-04, -5.525295246255693e-03, -2.951689956804921e-02, -9.560513275191489e-01, -4.407410917523490e+01, 4.144099103711181e+05, 1.446904119327296e+10, -2.364973952110889e+17, -6.593259128892694e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
