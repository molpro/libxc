
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ft97_a_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_a", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.290384383144676e+00, -4.208635318363576e+00, -4.094212559491020e+00, -3.935979630149237e+00, -3.720949600492339e+00, -3.436028662857763e+00, -3.072101825424396e+00, -2.631485238298164e+00, -2.137866683852353e+00, -1.635327439102589e+00, -1.114971072803294e+00, -6.619719690290332e-01, -5.613594966512572e-01, -4.703406396312068e-01, -3.514637861495510e-01, -2.473075616171023e-01, -1.675882888750315e-01, -1.010247436818204e-01, -6.215304187650725e-02, -4.224495572951798e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ft97_a_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.382689569109938e+00, -5.267592577350928e+00, -5.106121091205927e+00, -4.882039941026819e+00, -4.575860130408560e+00, -4.166623005632653e+00, -3.636444967369478e+00, -2.979532936473418e+00, -2.219423996614934e+00, -1.450776367997067e+00, -9.031294823851785e-01, -7.971974989149132e-01, -7.161502748734452e-01, -5.514729067857174e-01, -3.401038805111251e-01, -1.643420727696764e-01, -9.913024683410669e-02, -5.056935223207522e-02, -1.840475825100179e-02, -7.209520982061161e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ft97_a_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_a", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.624775292511384e-06, -3.930865417896095e-06, -4.416173211283900e-06, -5.218990750773649e-06, -6.630260134616562e-06, -9.336051655448895e-06, -1.520436428040050e-05, -3.033335322286629e-05, -7.962402835390979e-05, -2.936200765492431e-04, -1.554118784679128e-03, -6.855316483565509e-03, -1.201061688692534e-02, -2.810509563916682e-02, -1.210941957328959e-01, -8.856875886513774e-01, -8.427615914633050e+00, -1.895776659486739e+02, -1.755196886652959e+04, -1.038506807778728e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ft97_a_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.246348637147047e-02, -1.306505260391789e-02, -1.398442549449784e-02, -1.542783518806043e-02, -1.778420245384652e-02, -2.185512107930900e-02, -2.948549912197611e-02, -4.549548573623145e-02, -8.377096836424933e-02, -1.784073022932723e-01, -4.025918532972618e-01, -6.020768618127862e-01, -6.835968708031808e-01, -1.293801255385963e+00, -3.489746400372969e+00, -5.901995127798246e+00, 4.675941606393946e+01, 1.504784574038528e+02, 1.717278260507627e+04, 1.096314670710808e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ft97_a_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.623123959314117e-08, 3.019127988141200e-08, 3.694158465656919e-08, 4.933260440381499e-08, 7.462078028421738e-08, 1.346442589217756e-07, 3.109743176794750e-07, 1.005966038208601e-06, 5.000789336620115e-06, 3.877961110527016e-05, 5.732003199932525e-04, 1.388321629759996e-02, 3.827451104947127e-02, 1.609319399539538e-01, 1.693853003996257e+00, 6.405727902941950e+00, -5.450719429394350e+03, -1.519258332227347e+06, -1.052377663934495e+10, -3.634080112289838e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ft97_a_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_a", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.110456410731417e-15, 1.054258120085715e-14, 1.535995839766519e-14, 2.634322345285922e-14, 5.701070233779477e-14, 1.716709432204833e-13, 8.239041911113146e-13, 7.575687748949768e-12, 1.681941846469714e-10, 1.112032759338909e-08, 1.908625117292847e-06, 7.023534348564945e-05, 2.499726979614172e-04, 5.391818415554111e-03, 6.746950837558244e-01, 5.088996011225558e+02, 1.145159677020204e+06, 2.112070430466610e+10, 2.517413291689192e+16, 8.351489630219478e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
