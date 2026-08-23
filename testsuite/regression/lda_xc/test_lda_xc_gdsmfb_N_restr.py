
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_lda_xc_gdsmfb_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_gdsmfb", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.271748529294438e+00, -4.187140313026191e+00, -4.068550681710681e+00, -3.904206517385486e+00, -3.680128208979217e+00, -3.381622260083630e+00, -2.996905369137875e+00, -2.523828357318376e+00, -1.980015647058710e+00, -1.416201722019206e+00, -9.375183054060510e-01, -6.951918412701167e-01, -6.119262226268248e-01, -4.995989306117025e-01, -3.501112437744577e-01, -2.062003309139940e-01, -9.847755179589784e-02, -3.533187815269673e-02, -8.215557578684906e-03, -9.840078133507523e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_lda_xc_gdsmfb_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_gdsmfb", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.667853026333413e+00, -5.555182575321835e+00, -5.397264897215069e+00, -5.178429106358307e+00, -4.880073720763891e+00, -4.482661584179293e+00, -3.970558719335830e+00, -3.341008848568183e+00, -2.617662334918665e+00, -1.868338009212192e+00, -1.233110181911875e+00, -9.121868634897643e-01, -8.020845602579328e-01, -6.537513246907255e-01, -4.568448710977401e-01, -2.681521070507166e-01, -1.278412636847829e-01, -4.603064972904122e-02, -1.080153821599753e-02, -1.305024912080800e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_lda_xc_gdsmfb_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("lda_xc_gdsmfb", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.038143905524082e-02, -1.081473628700500e-02, -1.146913719265355e-02, -1.247870321222416e-02, -1.408441064254018e-02, -1.675233075427062e-02, -2.147119040822537e-02, -3.059582279201137e-02, -5.058439204448051e-02, -1.018744190060216e-01, -2.438824569891864e-01, -4.635127849140049e-01, -6.112224991190671e-01, -9.521857585394561e-01, -2.094396571643512e+00, -6.955076543985649e+00, -3.880138171140040e+01, -4.305852641726191e+02, -1.183505832410102e+04, -1.099906487722763e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
