
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_sogga11_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga11", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.257058522739535e+00, -4.174835695983368e+00, -4.059694313275211e+00, -3.900334433605787e+00, -3.683433541766669e+00, -3.395096210959939e+00, -3.023945197266383e+00, -2.564964629866326e+00, -2.018788773446822e+00, -1.409255317785681e+00, -9.109544268570509e-01, -6.534311220143155e-01, -5.580270489526393e-01, -4.621491879630253e-01, -3.197700437510708e-01, -1.997141605414840e-01, 1.289802801390317e-01, -2.528372607728772e-01, -7.190593145080204e-02, -8.065053106698314e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_sogga11_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.416724037959987e+00, -5.303119874537814e+00, -5.144126747596315e+00, -4.924398750540239e+00, -4.626454592532144e+00, -4.234316945310323e+00, -3.743567487374807e+00, -3.185381119585346e+00, -2.650465928121889e+00, -2.003068700779894e+00, -1.146477456148302e+00, -8.127049060307282e-01, -7.191390353238957e-01, -5.714663484503120e-01, -4.445898795726690e-01, -8.032023256435403e-02, 2.203284378414613e-01, -9.952803072391933e-02, -9.309058438356492e-02, -1.074941418735443e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sogga11_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga11", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.782818534021455e-06, -3.009718177678670e-06, -3.364414484592294e-06, -3.937026659674038e-06, -4.899333759606358e-06, -6.583723498582302e-06, -9.537545684918757e-06, -1.344766194347382e-05, -5.204987779242855e-06, 4.992320900860655e-05, -1.814566402458091e-04, -4.697160571795761e-03, -9.249534129714724e-03, -1.661926318962429e-02, 1.717724866540733e-02, -9.958031086757958e-01, -3.277931641744321e+00, -5.353770920899810e+02, -7.579894583351402e+02, -8.436158613526790e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sogga11_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.172280986736471e-02, -1.219423575646609e-02, -1.288585589672264e-02, -1.389685982588107e-02, -1.533517163575806e-02, -1.714478008151722e-02, -1.808054604857254e-02, -1.033774340138464e-02, 3.048409840659725e-02, -2.378409288261399e-01, -1.859238813488304e+00, -4.454436876049215e-01, -6.672913533145755e-01, -6.931224809121301e-01, 6.788581154025002e-01, 1.115786830430780e+01, -8.088778822264171e+03, 2.422729130745610e+04, -6.991618942454978e+04, -9.239489301342959e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sogga11_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.760420865709908e-08, 1.943471631691336e-08, 2.216351641162079e-08, 2.601651608264061e-08, 2.993160180252123e-08, 2.280853953890688e-08, -8.581468839313339e-08, -1.120270728063027e-06, -1.049679923577417e-05, 5.012858814796899e-05, 4.318427523680858e-03, 6.447432666154077e-04, 3.131667030529827e-02, -7.382750463609711e-02, -2.723888076540337e+00, -7.206321160701721e+01, 5.534020032800946e+05, -5.691608389015030e+07, -1.054404587417701e+10, -8.739572190412877e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_sogga11_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_sogga11", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.341679021914832e-14, 5.015144294959145e-14, 8.655075857214713e-14, 1.795842738354466e-13, 4.757940598598365e-13, 1.744982234831713e-12, 9.807179301945047e-12, 9.314910690545553e-11, 1.376664882433828e-09, -2.471611832100357e-08, -1.110080898854862e-05, 7.597068045822644e-04, -4.914327284821853e-04, 6.597256757024836e-02, 2.244507262470865e+00, 9.966183327407773e+02, -3.721302100341125e+07, 1.782315497340818e+11, 3.834215660708012e+15, 2.463854431029314e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
