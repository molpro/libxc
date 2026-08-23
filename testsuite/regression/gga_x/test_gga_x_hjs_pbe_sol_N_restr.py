
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_hjs_pbe_sol_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe_sol", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.181456952455108e+00, -4.098784196372875e+00, -3.983004409160643e+00, -3.822757892564840e+00, -3.604695623565591e+00, -3.315108578578879e+00, -2.943780135154539e+00, -2.490984063697419e+00, -1.977006888265843e+00, -1.446658401389566e+00, -9.449306775699302e-01, -5.888015256921197e-01, -4.967278983648709e-01, -3.989337493248591e-01, -2.699260946352996e-01, -1.504494392083729e-01, -5.826277575152434e-02, -4.625947661335427e-03, -1.906513925940564e-05, -2.506091257164601e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_hjs_pbe_sol_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe_sol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.386694340433389e+00, -5.272967124605042e+00, -5.113510266238785e+00, -4.892422574851657e+00, -4.590757228565078e+00, -4.188473706067051e+00, -3.669308588152726e+00, -3.030324804485895e+00, -2.298758614191468e+00, -1.560122457699448e+00, -9.792305245041856e-01, -7.547039092461229e-01, -6.627081191391956e-01, -5.083274762424490e-01, -3.115251229803229e-01, -1.436732405020230e-01, -6.317298291863675e-02, -9.031497247775766e-03, -3.873770369415274e-05, -5.012248495159594e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_pbe_sol_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe_sol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.244805999614154e-06, -2.431166937763727e-06, -2.725991937533766e-06, -3.212089726459441e-06, -4.062269063183787e-06, -5.679307169160082e-06, -9.140652023545668e-06, -1.786442459699569e-05, -4.515477027947795e-05, -1.566870423486497e-04, -8.023379739703591e-04, -4.022268549500184e-03, -7.010106615494998e-03, -1.593444589172693e-02, -6.369368351960088e-02, -4.046118688427406e-01, -2.019420350871623e+00, -1.665845803438003e+00, -3.039846254605595e-03, -3.057425462662705e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_pbe_sol_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.155335680943868e-02, -1.207680414361444e-02, -1.287219250927117e-02, -1.411019044100229e-02, -1.610466821457508e-02, -1.947969439419631e-02, -2.559681467635922e-02, -3.772561152688609e-02, -6.411433187635625e-02, -1.235957279005066e-01, -2.634799311147257e-01, -5.323906123254641e-01, -6.424886519920662e-01, -1.109723478252722e+00, -2.589251191651108e+00, -4.153218659712969e+00, 3.495182883641164e+01, -1.876620708710842e+02, -1.421640891580976e+02, -1.298289992864185e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_pbe_sol_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.515574296384749e-08, 1.738163015172385e-08, 2.115509621181981e-08, 2.802420064740535e-08, 4.186183681111147e-08, 7.402069128981430e-08, 1.651114162483771e-07, 5.001360631288018e-07, 2.167250470172392e-06, 1.283605489973106e-05, 1.268670804519504e-04, 7.651696541574899e-03, 2.177161477921518e-02, 8.547397834747046e-02, 7.333786529185474e-01, -7.873790227790511e+00, -4.880213861038043e+03, -2.252599888757483e+05, -6.180030542951371e+04, -4.349094124465514e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_hjs_pbe_sol_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_hjs_pbe_sol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.662129992091891e-14, 2.117053943084188e-14, 2.996719915070042e-14, 4.934844803949114e-14, 1.009105751238263e-13, 2.810870137472698e-13, 1.214957637681000e-12, 9.739044648362521e-12, 1.795974095313242e-10, 9.091691124745376e-09, 1.434392211087102e-06, 6.939262190731161e-05, 1.387489863071319e-04, 4.226235637418466e-03, 4.695010064981029e-01, 2.845879212561958e+02, 5.031351639325884e+05, 5.802904050621983e+08, 1.535856438090796e+10, 8.929642872189282e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
