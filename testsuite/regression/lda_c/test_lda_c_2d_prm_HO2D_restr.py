
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_2d_prm_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_prm", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.521019434747199e-02, -9.521015168663453e-02, -9.521003943770133e-02, -9.520974446673662e-02, -9.520897092695098e-02, -9.520694903531231e-02, -9.520169161067195e-02, -9.518813135575019e-02, -9.515358390432210e-02, -9.506713403674424e-02, -9.485605788866408e-02, -9.435609732246095e-02, -9.320855563072336e-02, -9.063421842625087e-02, -8.487826382514889e-02, -7.192394155648850e-02, -4.537213537007204e-02, -1.308472447825126e-02, -9.466189886196737e-04, -9.868139377224671e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_2d_prm_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_prm", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.035791569101385e-01, -1.035791285640359e-01, -1.035790539798687e-01, -1.035788579849292e-01, -1.035783439989071e-01, -1.035770005085848e-01, -1.035735069294214e-01, -1.035644949679893e-01, -1.035415279105427e-01, -1.034840103711483e-01, -1.033432998402740e-01, -1.030084476630131e-01, -1.022315526283973e-01, -1.004463630915947e-01, -9.624138691036301e-02, -8.568802349005668e-02, -5.933419244833801e-02, -1.891345413815853e-02, -1.416217049461524e-03, -1.480180593216726e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_2d_prm_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_2d_prm", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.734875374535735e-03, -8.734939760727261e-03, -8.735109174970468e-03, -8.735554378263599e-03, -8.736721971773121e-03, -8.739774397872605e-03, -8.747715195444383e-03, -8.768221415511174e-03, -8.820627233738870e-03, -8.952789554138115e-03, -9.281689401721771e-03, -1.009673388204819e-02, -1.216965776852385e-02, -1.797619346631663e-02, -3.845877225955772e-02, -1.497389314365998e-01, -1.224020557856718e+00, -1.593339692727120e+01, -3.261401189743725e+02, -3.219185280812505e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
