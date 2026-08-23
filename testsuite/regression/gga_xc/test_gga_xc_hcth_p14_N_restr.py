
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_hcth_p14_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p14", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.425406928337483e+00, -4.338189994509272e+00, -4.216034077154021e+00, -4.046946055116209e+00, -3.816846733024150e+00, -3.511359399578165e+00, -3.120148298435319e+00, -2.645246230266377e+00, -2.113481767018868e+00, -1.580326484934418e+00, -1.082062111532424e+00, -7.408379620057665e-01, -6.515453489981983e-01, -5.382841295262000e-01, -3.948499090705382e-01, -2.600107463938283e-01, -1.456241342713079e-01, -5.997450011080410e-02, -1.467392814036491e-02, -1.814447937284452e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_hcth_p14_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p14", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.885548618394303e+00, -5.765809548736406e+00, -5.597678096172123e+00, -5.364034349562252e+00, -5.044076861699955e+00, -4.614799901339336e+00, -4.054892779270841e+00, -3.352900122501788e+00, -2.528346786891130e+00, -1.703182833865630e+00, -1.118004168546518e+00, -9.475413309270665e-01, -8.510591563395231e-01, -6.755768506044603e-01, -4.503574245094157e-01, -2.677752720811002e-01, -1.546003770737953e-01, -7.406936345288327e-02, -1.916326669549292e-02, -2.400221991435708e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_p14_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p14", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.898492735508090e-07, 2.671223703230000e-07, 2.233345983422637e-07, 1.322301058469355e-07, -7.589682296062589e-08, -6.099034025892044e-07, -2.195824921565565e-06, -7.833443795830196e-06, -3.212326098160436e-05, -1.501911914494485e-04, -7.977096797822638e-04, -1.569178598981855e-03, 3.156439634401679e-04, -9.128057683718124e-03, -5.773359956941958e-02, -3.701836823898771e-01, -2.296634099697957e+00, -8.406987025247636e+00, -1.237983394949532e+01, -1.447404253801721e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_p14_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.198702788044210e-02, -1.257541476274646e-02, -1.347982572648098e-02, -1.491297011861898e-02, -1.728862804411450e-02, -2.149816778849235e-02, -2.970970447730783e-02, -4.781719994637531e-02, -9.102864373680368e-02, -1.666494221246874e-01, -2.935065369071368e-01, -6.065539894168952e-01, -7.432484222285812e-01, -1.291701533577534e+00, -3.192652408349862e+00, -2.261374181026213e+00, 9.465819260569315e+00, -2.667306031738041e+02, -1.996924575398062e+04, -1.999516578682788e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_p14_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.355224842933927e-08, 1.610267264285793e-08, 2.060429122345779e-08, 2.928583577406220e-08, 4.827121750202251e-08, 9.777957188242536e-08, 2.617402428274019e-07, 9.954331344827287e-07, 5.413572101180673e-06, 3.082848720297079e-05, 2.174871968287287e-04, 1.037274196854993e-02, 3.815136558736693e-02, 1.183873490351744e-01, 1.143651517237650e+00, -2.298562378921277e+01, -3.804049541531219e+03, -9.303715577692115e+05, -1.719516651566693e+08, -1.498038986165660e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_hcth_p14_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_hcth_p14", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.653191946158551e-13, -2.041203027912953e-13, -2.763857060685261e-13, -4.272256807987840e-13, -7.982020795312983e-13, -1.951488107337497e-12, -6.922251324195462e-12, -3.962293123723375e-11, -3.575774242216142e-10, 1.205865193594106e-09, 1.169488528740692e-06, -5.218200315555568e-04, -1.410988667176186e-02, -2.066447557729488e-02, 7.923924908949435e-03, 3.477950370019768e+02, 4.766176217264399e+05, 2.898849528011795e+09, 6.271424766707697e+13, 4.227354008998583e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
