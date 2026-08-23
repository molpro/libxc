
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_mcweeny_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_mcweeny", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.828347095861466e-02, -9.817949643668376e-02, -9.802675167186743e-02, -9.780032434506383e-02, -9.746034703950091e-02, -9.694059245861057e-02, -9.612579160186109e-02, -9.480408605370762e-02, -9.256570435672427e-02, -8.863016351557472e-02, -8.218713633929710e-02, -7.628847178104749e-02, -7.345496518465582e-02, -6.858528435685932e-02, -5.915252604648717e-02, -4.414878313505582e-02, -2.545150035669389e-02, -9.778331745517985e-03, -2.188218256999676e-03, -2.465801309586236e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_mcweeny_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_mcweeny", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.996634404956276e-02, -9.989343228209407e-02, -9.978619439372390e-02, -9.962694978602479e-02, -9.938722680156166e-02, -9.901930255947496e-02, -9.843902223161916e-02, -9.748865213898171e-02, -9.585350924838530e-02, -9.290041388741109e-02, -8.785064533092199e-02, -8.299330460660016e-02, -8.058040718020346e-02, -7.631289889082436e-02, -6.761251674488601e-02, -5.259409135178798e-02, -3.185121325653641e-02, -1.273014785112611e-02, -2.902218788232284e-03, -3.285778884124937e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_mcweeny_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_mcweeny", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.586452405637618e-06, -7.138332959462459e-06, -8.012798220543251e-06, -9.458173874828484e-06, -1.199635225302235e-05, -1.685745561701135e-05, -2.739578533156797e-05, -5.464097611267678e-05, -1.447008536342589e-04, -5.527515089160399e-04, -2.835982765223205e-03, -9.120194538030948e-03, -1.491506247899876e-02, -3.227240621469969e-02, -1.202996753238413e-01, -7.611922629672800e-01, -7.621671028788662e+00, -1.165142552481755e+02, -3.297948758745083e+03, -2.828437482351682e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
