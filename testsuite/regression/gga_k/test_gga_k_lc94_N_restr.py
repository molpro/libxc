
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_k_lc94_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lc94", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.459686781394865e+01, 9.093104743676695e+01, 8.591775856570401e+01, 7.921104915837692e+01, 7.051714310401394e+01, 5.974201759053635e+01, 4.721063385341153e+01, 3.388320451612240e+01, 2.136267642545053e+01, 1.141251246598901e+01, 5.003771990173997e+00, 2.210204859831152e+00, 1.631134813766700e+00, 1.101492454094143e+00, 5.550797423265256e-01, 2.100228978451310e-01, 6.207271136932545e-02, 1.278680829740237e-02, 1.911129745193969e-04, 3.123621979662515e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_k_lc94_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lc94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.494173275809875e+02, 1.433656321654573e+02, 1.350947084683913e+02, 1.240405020098446e+02, 1.097319381840046e+02, 9.203970643993082e+01, 7.154613268050119e+01, 4.991474979250528e+01, 2.992568599798305e+01, 1.472037194159230e+01, 6.160334605769331e+00, 3.388771884998079e+00, 2.610727201115511e+00, 1.658862752914916e+00, 7.487704899539568e-01, 2.304981739859783e-01, 5.070629588957323e-02, 1.304517970058525e-02, 7.765751589872082e-04, 1.356501221996468e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lc94_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lc94", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.845781133611678e-05, 9.356362020519433e-05, 1.014028748577298e-04, 1.137822141105759e-04, 1.341279295946817e-04, 1.695086920537393e-04, 2.360992670085805e-04, 3.759182274789968e-04, 7.165141140469449e-04, 1.730542344564350e-03, 5.804415396466251e-03, 2.366393715855776e-02, 4.006039551280036e-02, 6.574430481290623e-02, 1.661794155664787e-01, 6.401101886048418e-01, 3.575763237101040e+00, 1.862682792984255e+01, -1.247129624944818e+02, -1.767379468966827e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lc94_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lc94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.862819446787749e-01, 5.987944030445944e-01, 6.172355849188716e-01, 6.446991466625694e-01, 6.862043222492401e-01, 7.502249373770418e-01, 8.517399934021794e-01, 1.018399660453135e+00, 1.301809132627211e+00, 1.791011924154889e+00, 2.687181770732293e+00, 3.911493750092355e+00, 4.417730626064602e+00, 5.593760645830700e+00, 8.118904320649202e+00, 1.248989885420007e+01, 9.678546833469213e+00, -5.091649658396525e+02, 7.577586667419493e+03, 1.175240701389059e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lc94_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lc94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.225612766111005e-07, -3.589899899252732e-07, -4.183902298148684e-07, -5.205940806629029e-07, -7.102882375812380e-07, -1.101546640582655e-06, -2.033001454927639e-06, -4.700709151223806e-06, -1.407668128662037e-05, -5.078587447791239e-05, -3.485898384139845e-04, -2.116233784406664e-02, -6.864409198114349e-02, -1.545833550394736e-01, -6.296906599435359e-01, 3.802747239094207e+00, 1.677346957685490e+03, 1.756232151522565e+06, -1.569608281641646e+09, -1.989614655245938e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_k_lc94_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_k_lc94", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.838845099638679e-12, -2.245252300677720e-12, -2.990494390695082e-12, -4.510463511705788e-12, -8.122657480255557e-12, -1.881377559916873e-11, -6.214186055773882e-11, -3.369580904565589e-10, -3.617476812140355e-09, -9.769978296079660e-08, -8.694362824007184e-06, -1.367858436180834e-03, -1.069400975468776e-02, -5.692531259540411e-02, -1.743802303335558e+00, -3.148022472043230e+02, -3.605352126151787e+05, -5.261583482925307e+09, 5.462371191684522e+14, 5.174638364115338e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
