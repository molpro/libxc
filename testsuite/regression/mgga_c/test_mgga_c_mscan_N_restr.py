
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_mscan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.656286400299083e-02, -2.651927104749994e-02, -2.645495302233250e-02, -2.635905343237957e-02, -2.621401651605796e-02, -2.599068678106894e-02, -2.564044023224218e-02, -2.509126177452365e-02, -2.433702523817378e-02, -2.482153057252214e-02, -3.124817791808781e-02, -5.593714581580281e-02, -5.001510309613952e-02, -2.962511831483302e-02, -2.390351045875336e-02, -1.873134387726268e-02, -9.834956916772100e-03, -3.478425470502514e-03, -5.809545171335115e-04, -3.061428077863143e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_mscan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.641947019467202e-02, -3.660464628165037e-02, -3.687513415465316e-02, -3.727284964279022e-02, -3.786312431421984e-02, -3.875095043040055e-02, -4.011358286550717e-02, -4.228846984299001e-02, -4.624022729131546e-02, -5.942130930333437e-02, -5.983481897309823e-02, -8.206584029538290e-02, -2.299146118547329e-02, -3.972092377426769e-02, -4.962495112590150e-02, -4.556186895246647e-02, -2.452013563063679e-02, -7.239766304549492e-03, -1.140580810580261e-03, -6.041773370709242e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mscan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.371833033574061e-07, 2.582069797043988e-07, 2.916444280773697e-07, 3.471939219209731e-07, 4.454035213454585e-07, 6.351575334964951e-07, 1.051470535701537e-06, 2.151286150184905e-06, 6.071456064278754e-06, 3.450985989883889e-05, 1.206335121641636e-04, 3.272520349676064e-03, 1.501322320180192e-02, 1.818264514914303e-02, 6.914353974184596e-02, 2.940453279508619e-01, 1.838352583663034e+00, 1.026776406063624e+01, 1.253116777759246e+02, 4.366349971380132e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mscan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.048107645946947e-04, -3.116668094065000e-04, -3.216956514109805e-04, -3.364627479211328e-04, -3.584023074642290e-04, -3.914065247748952e-04, -4.420588462730628e-04, -5.235753776652096e-04, -6.808802086984544e-04, -1.352573495745989e-03, -5.535060685448011e-04, -1.629687135532119e-03, -2.863723431024490e-02, -2.380438495432401e-02, -3.058295825768598e-02, -2.027724611944436e-02, -1.049826260715840e-02, -1.232509349856971e-03, -4.344219626230563e-05, -1.521368406794521e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mscan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.033438193946426e-05, 4.192627621185170e-05, 4.409313248792037e-05, 4.680614310324873e-05, 4.929301234632041e-05, 4.745874573637867e-05, 2.153258561075826e-05, -1.337422254307826e-04, -1.106318704770314e-03, -8.811746094117162e-03, -2.387455083260057e-02, 5.140614764352829e-02, 4.533610157909392e-01, 1.607178889607297e-01, 8.984730210245948e-02, 6.509857641268637e+01, 7.808179831620063e+01, 4.819106997858678e+02, 1.166113179155126e+03, -1.268858245359096e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mscan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.025291700349667e-10, 2.801302679318189e-10, 4.281713801943975e-10, 7.434630987116157e-10, 1.523501570191141e-09, 3.889590449426379e-09, 1.337340889137479e-08, 6.932645724004645e-08, 6.468620886116920e-07, 1.613171771434531e-05, 1.045212942920881e-04, 2.607813930349424e-03, 9.133298267256101e-03, -4.335901512050732e-02, 1.256722101036307e+00, -1.301051179419855e+03, -1.783579231678250e+04, -3.920482899372781e+06, -2.867624311883637e+09, 7.969084100139873e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mscan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.504182830043334e-06, -1.688043729895118e-06, -1.990377498888136e-06, -2.517047850339516e-06, -3.512978959762872e-06, -5.628700747457999e-06, -1.092877347655229e-05, -2.773890037171651e-05, -1.042136727035748e-04, -8.251307429945403e-04, -5.264762448708065e-04, -8.492388912077065e-03, -1.921376585365389e-01, -3.416306200809464e-02, -9.219009580496058e-01, 1.211413117881090e+02, 1.404584360978659e+02, 1.064308673868944e+03, 8.075674512086228e+03, 4.316480137093412e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mscan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.258691326848827e-14, -5.353067328855893e-14, -7.434808732839182e-14, -1.191362384232451e-13, -2.342405455890340e-13, -6.167370997629112e-13, -2.462066046199309e-12, -1.783222926999601e-11, -3.115819360692403e-10, -2.539437177200959e-08, -4.217892481422150e-07, -8.963621556453913e-04, -6.287398975161203e-03, -1.230612793623345e-01, -7.699534363210464e+00, 2.578714962874091e+04, 3.744073416503549e+06, 2.622582467307393e+10, 2.374090277846091e+15, 2.220009447929281e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mscan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.895053241164744e-11, 4.622837463545140e-11, 5.912574179225675e-11, 8.417602031938903e-11, 1.397019617410452e-10, 2.886291475433046e-10, 8.151570607541500e-10, 3.608437900644646e-09, 3.143827130671765e-08, 9.786326440384344e-07, -2.129927828747313e-06, 5.455128940332653e-05, -1.853544193792587e-02, 1.421634716838652e-01, 3.291165874906091e+00, -2.425649286116844e+03, -3.107732753921550e+04, -7.150511942295765e+06, -6.226644873897522e+09, -2.508614366969934e+13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_mscan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_mscan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.540192358232102e-08, -2.876607222777741e-08, -3.438472022122095e-08, -4.439996667090279e-08, -6.399775731202545e-08, -1.078302147902883e-07, -2.266225560152033e-07, -6.529621478032174e-07, -3.043297418617708e-06, -3.821710474153476e-05, 4.855029966001673e-05, 8.109070666044790e-04, 1.111898120781340e-01, -1.675774283988959e-01, -1.435167113729860e+00, 2.271598646613101e+02, 2.498530248371728e+02, 1.857330019768298e+03, 1.429127248247065e+04, 7.765367024738040e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
