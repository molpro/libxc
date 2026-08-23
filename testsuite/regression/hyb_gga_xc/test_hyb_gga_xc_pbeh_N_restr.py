
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_pbeh_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeh", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.291768608759590e+00, -3.229439657497676e+00, -3.142150410877789e+00, -3.021336831431602e+00, -2.856936045272620e+00, -2.638614842185154e+00, -2.358663125070836e+00, -2.017174736766624e+00, -1.628629486984346e+00, -1.222505692314398e+00, -8.233037453113854e-01, -5.413824640320190e-01, -4.745677901367357e-01, -3.907359455449081e-01, -2.812524147534909e-01, -1.766796741338456e-01, -9.095309414006805e-02, -3.141169910300051e-02, -6.577085861267770e-03, -7.276212804627284e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_pbeh_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.166528436273325e+00, -4.079742201681842e+00, -3.958020451705325e+00, -3.789177600921127e+00, -3.558660662061057e+00, -3.251033295013697e+00, -2.853782796378191e+00, -2.365128727253993e+00, -1.808894456909040e+00, -1.259848447227434e+00, -8.309642118198163e-01, -6.881459996234688e-01, -6.191358657897890e-01, -4.952820326588487e-01, -3.311035930643103e-01, -1.860652862270772e-01, -1.042492956685320e-01, -4.092115722192734e-02, -8.759631487259636e-03, -9.701477135404896e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbeh_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeh", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.169810085802965e-06, -2.356948683467477e-06, -2.653476723231041e-06, -3.143358239358590e-06, -4.002063540769878e-06, -5.638283108769139e-06, -9.139277966247015e-06, -1.790022734420095e-05, -4.463967175991417e-05, -1.468523104349117e-04, -7.001942852747931e-04, -1.752263636018010e-03, -3.071635086479667e-04, -5.889650109694621e-03, -3.604463090760800e-02, -2.563799556643704e-01, -1.146581778892474e+00, -2.163692683271904e+00, -2.672517838936138e+00, -2.958764738363095e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbeh_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.462726269207697e-03, -9.908860363455722e-03, -1.058768984381511e-02, -1.164599292324239e-02, -1.335368824565360e-02, -1.624463925055815e-02, -2.146208498386610e-02, -3.160346886919724e-02, -5.205304768175305e-02, -8.538458091865253e-02, -1.690655877852637e-01, -4.489831481292256e-01, -4.999578815338406e-01, -9.519790402047731e-01, -2.540975699135419e+00, -4.373615520143140e+00, 1.103211619966995e+01, -3.102309402940297e+02, -1.008603044787972e+04, -8.374606750758328e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbeh_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.068239991920643e-08, 2.363957070134375e-08, 2.862496484300174e-08, 3.762386643339983e-08, 5.551524512593520e-08, 9.622652543729863e-08, 2.075163025777329e-07, 5.910819499743894e-07, 2.231102690768316e-06, 7.021383277427066e-06, 1.689584894370527e-05, 9.040887249684236e-03, 1.493636523566537e-02, 9.801376734893724e-02, 1.061137823029733e+00, -1.815283447436858e+00, -3.102591437184489e+03, -2.555246200911170e+05, -3.731158520522499e+07, -3.065276103985071e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_pbeh_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_pbeh", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.042029257908029e-14, -7.131375012306707e-14, -9.015171086330704e-14, -1.250841424180951e-13, -1.953565626059023e-13, -3.434004574945717e-13, -5.376973559067389e-13, 2.836862659047378e-12, 1.494865584819656e-10, 1.014922870048182e-08, 1.451172757635381e-06, -5.053302970291756e-04, -6.066928231344041e-03, -2.730813358856191e-02, -4.483073242064912e-01, 1.536575180495240e+02, 3.134327822337493e+05, 7.770209064971424e+08, 1.355479365940902e+13, 8.641533660129371e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
