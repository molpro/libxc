
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_wc04_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wc04", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.013076812372389e-01, -3.030533347510481e-01, -3.055868584627602e-01, -3.092791257655141e-01, -3.146911947047498e-01, -3.226799124303150e-01, -3.345305076050915e-01, -3.519089042086891e-01, -3.751946536783305e-01, -3.916060262234824e-01, -3.207498068366671e-01, -1.261272149459649e-01, -9.969928092800308e-02, -1.116746501216512e-01, -1.198024663039390e-01, -1.211728043087806e-01, -1.120028301566253e-01, -8.893038210295363e-02, -6.144082831641715e-02, -4.136850688765753e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_wc04_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wc04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.050273668365645e-02, 2.270557915549922e-02, 2.582014648871627e-02, 3.018467820083990e-02, 3.621037128256546e-02, 4.430701596979246e-02, 5.459424208452085e-02, 6.595553710751177e-02, 7.332333768439130e-02, 6.293694061153714e-02, 2.176339418459594e-02, -5.836670258073715e-02, -7.510919082973005e-02, -5.555651916922842e-02, -4.056118870870925e-02, -3.573345669964482e-02, -3.924901214832831e-02, -3.469040223293542e-02, -1.920215959502860e-02, -7.643562938418561e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wc04_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wc04", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.132482173662374e-06, -4.455995156169839e-06, -4.964518984687504e-06, -5.795112351567143e-06, -7.227871040528050e-06, -9.897972150572157e-06, -1.544489421217183e-05, -2.884414758586964e-05, -6.861885611961728e-05, -2.247182031297211e-04, -1.135894473790557e-03, -7.175090732106358e-03, -1.430403198169785e-02, -2.811441099172401e-02, -9.823879447745074e-02, -6.137602236607295e-01, -6.989233322284371e+00, -1.820116792852691e+02, -1.687613234849403e+04, -1.003449588215622e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wc04_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wc04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.690870928679982e-03, -1.798820317921589e-03, -1.964576054447685e-03, -2.226045990198858e-03, -2.653945567534535e-03, -3.388825175664840e-03, -4.726389924444592e-03, -7.294849706186376e-03, -1.216427177402627e-02, -1.880312587890679e-02, -3.290446464872063e-02, -1.060632672764066e-01, -9.938717591820043e-02, -2.422846148085678e-01, -5.459254873956702e-01, -1.736332277737132e-01, 1.878065844497526e+01, 3.491349013283981e+02, 1.817347919546916e+04, 9.734100400233911e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wc04_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wc04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.096664502696351e-08, 2.379402524182292e-08, 2.851813993424478e-08, 3.693697825787737e-08, 5.337446798343945e-08, 8.985425826916944e-08, 1.864611604665541e-07, 5.103100067542175e-07, 1.965362603406399e-06, 1.101621628804382e-05, 1.422978721649635e-04, 8.972195619796605e-03, 3.408187493781897e-02, 9.283459638644320e-02, 5.660626472841734e-01, 1.506091750612165e+00, -1.593270685690527e+03, -1.320835428415239e+06, -1.010708614658258e+10, -3.410030437456142e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wc04_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wc04", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.051567968168968e-13, 1.311673535248485e-13, 1.801111626681127e-13, 2.837080507471534e-13, 5.433626745222205e-13, 1.372653701433215e-12, 5.117943886916474e-12, 3.278764760842506e-11, 4.407296721596301e-10, 1.602096251584881e-08, 2.131835737482686e-06, 5.195497678434166e-04, 4.570464244847251e-03, 3.071310128633341e-02, 1.308779898030333e+00, 3.683607779282809e+02, 7.512960748905484e+05, 1.996737643284938e+10, 2.420168194742994e+16, 8.048131861676646e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
