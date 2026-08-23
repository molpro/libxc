
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_c_xalpha_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_xalpha", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.081498750166679e+00, -2.039452469507453e+00, -1.980526417330794e+00, -1.898880512656333e+00, -1.787589689797317e+00, -1.639396344499308e+00, -1.448529932249636e+00, -1.214077922786723e+00, -9.450629391182922e-01, -6.670775291040537e-01, -4.325025299073082e-01, -3.147722409613938e-01, -2.745978009151725e-01, -2.207409900311278e-01, -1.499834208619897e-01, -8.369288154652205e-02, -3.670564297392554e-02, -1.174645410413772e-02, -2.431920025744523e-03, -2.688937650895131e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_c_xalpha_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_xalpha", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.775331666888906e+00, -2.719269959343270e+00, -2.640701889774392e+00, -2.531840683541778e+00, -2.383452919729756e+00, -2.185861792665744e+00, -1.931373242999515e+00, -1.618770563715631e+00, -1.260083918824390e+00, -8.894367054720717e-01, -5.766700398764110e-01, -4.196963212818584e-01, -3.661304012202299e-01, -2.943213200415037e-01, -1.999778944826529e-01, -1.115905087286961e-01, -4.894085729856739e-02, -1.566193880551696e-02, -3.242560034326030e-03, -3.585250201193508e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_c_xalpha_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_c_xalpha", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.165714005071510e-03, -5.380907054683966e-03, -5.705863630172431e-03, -6.207080702702390e-03, -7.004013666571596e-03, -8.327501936595705e-03, -1.066664200296064e-02, -1.518411706769345e-02, -2.505885378208255e-02, -5.029560588383020e-02, -1.196479777473795e-01, -2.258862601786696e-01, -2.968168537494493e-01, -4.593214160055798e-01, -9.949383184324077e-01, -3.195255752133159e+00, -1.661181152574373e+01, -1.622068142463725e+02, -3.784287203388909e+03, -3.095431534449054e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
