
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_pz_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.183926489312635e-01, -1.177897469501083e-01, -1.169245336530134e-01, -1.156842692181927e-01, -1.139093582944611e-01, -1.113757547273221e-01, -1.077731353931123e-01, -1.026822659143051e-01, -9.557282022219332e-02, -8.595808607403216e-02, -7.458157532319593e-02, -6.678722488925300e-02, -6.361573497482703e-02, -5.883547873596629e-02, -5.063186290258635e-02, -3.893787321242278e-02, -2.491619914399709e-02, -1.171018693721204e-02, -3.338439473370629e-03, -4.506436826536623e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_pz_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.282452221613886e-01, -1.276332495336963e-01, -1.267547314957185e-01, -1.254947864250131e-01, -1.236904109681275e-01, -1.211119326253634e-01, -1.174392868480504e-01, -1.122353505048898e-01, -1.049347951035016e-01, -9.498113519875863e-02, -8.302890069606308e-02, -7.467084436538970e-02, -7.121201741360357e-02, -6.598983546959553e-02, -5.759694239754545e-02, -4.527227409792776e-02, -2.985475396284676e-02, -1.454556849493558e-02, -4.291750431458102e-03, -5.930727728571927e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_pz_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_pz", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.583598320058275e-05, -5.932219857750328e-05, -6.471398183833656e-05, -7.332090971676826e-05, -8.769761816402172e-05, -1.133231526534527e-04, -1.634400131866304e-04, -2.752761592234010e-04, -5.753013689887158e-04, -1.593730575238934e-03, -5.582936790263985e-03, -1.380449150163679e-02, -2.026964009592683e-02, -3.386977481737976e-02, -1.076270793229305e-01, -5.840811650377246e-01, -5.670636286313351e+00, -1.052591643187800e+02, -4.209217212278358e+03, -4.822901161174322e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
