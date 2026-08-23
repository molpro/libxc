
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_ernzerhof_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ernzerhof", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.401184997415433e+01, 9.036119629901400e+01, 8.537014232088727e+01, 7.869628035667721e+01, 7.005142392519448e+01, 5.935067952966244e+01, 4.693465430217714e+01, 3.379172702546794e+01, 2.157280572773218e+01, 1.204552771773596e+01, 5.503920923763784e+00, 2.196003015016399e+00, 1.622438885260895e+00, 1.095579753399252e+00, 5.696515172317459e-01, 2.735813808501087e-01, 2.622337789895262e-01, 5.043833250627459e-01, 5.947356284394647e-01, 5.741322229678171e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_ernzerhof_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ernzerhof", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.490483777919691e+02, 1.429627536376460e+02, 1.346421710055609e+02, 1.235147056957897e+02, 1.090967986887839e+02, 9.123852314949421e+01, 7.048643096027052e+01, 4.843961356452773e+01, 2.777434637016199e+01, 1.169332191649806e+01, 4.103535666609938e+00, 3.353820893096144e+00, 2.609408179136063e+00, 1.629689948749281e+00, 6.580804124653385e-01, 1.346048861521203e-02, -4.984050028027820e-01, -7.855112656860286e-01, -6.158709911924343e-01, -5.743986990984040e-01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ernzerhof_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ernzerhof", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.195468992340645e-05, 8.731310196417397e-05, 9.564334290683690e-05, 1.090450161283559e-04, 1.317012451156754e-04, 1.728616505724578e-04, 2.559356474643613e-04, 4.517452254943102e-04, 1.032145504630401e-03, 3.373196385229223e-03, 1.350279635113078e-02, 2.456918027686093e-02, 3.516603097938195e-02, 7.292153541756236e-02, 2.745171581662641e-01, 2.369534984985146e+00, 6.341423343323212e+01, 3.664336465568748e+03, 4.375598428500919e+05, 3.237673020016955e+08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ernzerhof_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ernzerhof", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.035708411797166e-01, 6.178387533840265e-01, 6.390919065444979e-01, 6.712737686180097e-01, 7.212372491744448e-01, 8.019153036807537e-01, 9.409001037713843e-01, 1.209032349116167e+00, 1.843413075122843e+00, 3.841159964742105e+00, 7.724319794112191e+00, 4.218511096230460e+00, 4.485159969582440e+00, 6.267874853479237e+00, 1.364900155705788e+01, 8.435751565272108e+01, 1.886564038699156e+03, 4.632305727237956e+04, 4.195363077082288e+06, 2.974394770607978e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ernzerhof_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ernzerhof", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.228046665911866e-07, -5.948821037434437e-07, -7.164317839862285e-07, -9.363745397616004e-07, -1.377187883730782e-06, -2.402518918266803e-06, -5.369138285437675e-06, -1.721589971163577e-05, -9.320925204291519e-05, -1.013541019866127e-03, -1.603798416632046e-02, -4.881730158670889e-02, -9.448939592171994e-02, -4.388627179080767e-01, -6.690791103907953e+00, -4.475881042430799e+02, -1.508248439003596e+05, -1.410475865400311e+08, -1.533651138674974e+12, -8.386023133061407e+17]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_ernzerhof_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_ernzerhof", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.993563578554388e-13, 8.749905497001020e-13, 1.207229835770722e-12, 1.916372038901273e-12, 3.718259170140679e-12, 9.608683915770792e-12, 3.733107295657622e-11, 2.581934389966930e-10, 3.991073597687308e-09, 1.775826140572436e-07, 2.033082522326986e-05, 7.339762654152335e-04, 3.330062597197230e-03, 3.620733976366005e-02, 2.443681817099421e+00, 1.306791023597996e+03, 5.846924248894100e+06, 6.128231977304388e+10, 4.533823851261994e+14, 3.321293494675041e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
