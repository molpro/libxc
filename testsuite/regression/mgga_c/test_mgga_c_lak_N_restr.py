
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_c_lak_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.483052703572319e-02, -3.456570224416207e-02, -3.418205826224402e-02, -3.362516472610266e-02, -3.281546764361996e-02, -3.163877799521962e-02, -2.994109869131219e-02, -2.755712154503875e-02, -2.451104615731469e-02, -2.259045304608027e-02, -6.326377126136326e-02, -7.995114578094839e-02, -4.438540081988507e-02, -2.925349252596779e-02, -2.289490133915701e-02, -2.103493501380726e-02, -1.206317269816496e-02, -2.267436132887230e-03, -2.025463036159138e-04, -7.697682030998665e-06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_c_lak_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.327506704573677e-02, -5.320661585299531e-02, -5.309514312095737e-02, -5.290865884253541e-02, -5.258937977362854e-02, -5.203675549639149e-02, -5.109851524026911e-02, -4.965634099030579e-02, -4.829680738541994e-02, -5.694836824220752e-02, -1.593879693761510e-01, -8.301557892912831e-02, -1.176905832982794e-02, -4.307174453782756e-02, -5.056748369540100e-02, -1.499726631514838e-01, -3.643319186754125e-02, -5.938117785753549e-03, -4.253561623444466e-04, -1.538538321528139e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_lak_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.140639502891084e-07, 2.312141194994379e-07, 2.581943545739519e-07, 3.023333958053638e-07, 3.787443524474740e-07, 5.224107925565644e-07, 8.281189854843657e-07, 1.618814766518274e-06, 4.490295494995073e-06, 3.053687042816866e-05, 3.120448367388497e-04, 5.471215512496236e-05, 1.229793517168901e-02, 1.343150479458193e-02, 7.560442322873433e-02, 2.179748055979686e+00, 2.292105429927900e+00, 7.799362470970318e+00, 4.342467293737749e+01, 1.087510676283865e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_lak_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.221365614669011e-05, -4.435343647388526e-05, -4.763288853994582e-05, -5.280124896278526e-05, -6.128008402619858e-05, -7.601229354953883e-05, -1.037728089411653e-04, -1.622794985258031e-04, -3.088260589948773e-04, -1.090393035439167e-03, -7.696180029822411e-04, -6.272622242390960e-04, -2.737775227823731e-02, -1.404627478700704e-02, -3.370380617833710e-02, -1.910292290680580e-01, -7.966555769401798e-03, -1.572192647178566e-04, -4.422423955963860e-07, -1.339246738004167e-11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_lak_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.058313950599119e-05, -2.498978625966743e-05, -3.211559779175386e-05, -4.414011530381413e-05, -6.555716195664785e-05, -1.063092226915746e-04, -1.905709420714732e-04, -3.934770848805732e-04, -1.197181259537630e-03, -1.147781829525522e-02, -2.240025881844682e-02, -5.741846171203544e-03, -4.530531083972781e-01, 1.202445739966951e-02, 4.336819983858470e-01, -3.014453194056781e+01, 5.543736774419618e+01, -2.761815758042797e+02, -1.825523763960097e+03, -3.985624986176712e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_lak_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.877997412051804e-10, 2.479008600976518e-10, 3.567723181951295e-10, 5.723340397225384e-10, 1.053805194594368e-09, 2.323724173622564e-09, 6.619284609511026e-09, 2.948953650561209e-08, 3.329129059593265e-07, 1.954786132788163e-05, 1.229324571673430e-04, 2.313165082474947e-03, -9.200334882847971e-02, -6.529443584861341e-02, 1.086902304547374e+00, 8.059835014126309e+02, -1.931075101151388e+04, 2.339395537487046e+05, 3.447912764405574e+08, 5.645296744693306e+12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_lak_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.357022262200777e-08, 5.780078317737551e-08, 6.373702254806649e-08, 7.107239475675630e-08, 7.470530770246738e-08, 3.984537284948296e-08, -2.791205028172234e-07, -3.074277797141041e-06, -3.659773374370847e-05, -9.660476626458081e-04, -1.071037781289971e-03, -3.526778072617743e-03, 2.833508140828890e-01, 8.979876093298801e-02, -1.029316465933243e+00, -8.280542105827826e+01, 1.757649148064169e+02, 1.313709341499300e+02, 7.797202832418522e+01, 3.706528677676302e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_lak_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.520426548684312e-14, -3.133554222636101e-14, -4.281533976353333e-14, -6.694840852414646e-14, -1.269378904148411e-13, -3.175183362711806e-13, -1.194213204393924e-12, -8.526069505808505e-12, -1.824007038659638e-10, -3.189156793701779e-08, 3.611472359662579e-08, -6.359289083849279e-05, -1.749375222136797e-02, -7.951795588862372e-02, -1.234285087668239e+01, -1.727384052077854e+04, 4.582534277907602e+06, 9.985305340690497e+08, -1.314160990615437e+14, -1.988935972462673e+21]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_lak_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.761823481262632e-12, 4.604742699229151e-12, 6.168148533631163e-12, 9.420404720490290e-12, 1.742638337647121e-11, 4.269232942650188e-11, 1.578768855721783e-10, 1.060838621431340e-09, 1.674314209850708e-08, 1.328114392656293e-06, -1.378947039839101e-05, -1.271155028355199e-04, 3.748000940324833e-02, 1.057587405194819e-01, 6.377450543245792e+00, 1.446097526317848e+03, -4.020282003539464e+04, -9.291586994550142e+05, -6.241139806634218e+07, -2.188814520031496e+09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_c_lak_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_c_lak", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.178316315204793e-09, -6.026313980263446e-09, -7.495801210300118e-09, -1.026066518031008e-08, -1.612018999161622e-08, -3.087420029195861e-08, -7.857863943703025e-08, -3.005414244767426e-07, -2.096277306258505e-06, -5.743626524775020e-05, 2.067921707753572e-04, 4.959546411045266e-04, -1.400377983320644e-01, -1.977193699552101e-01, -3.393065278145086e+00, -1.209075730664077e+02, 3.259003083573226e+02, 2.482354722532110e+02, 1.458523577588562e+02, 6.836002145920750e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
