
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ft97_b_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_b", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.297860506436454e+00, -4.215447814489444e+00, -4.100133036825164e+00, -3.940750442187995e+00, -3.724337093615007e+00, -3.437922709123461e+00, -3.072620875802308e+00, -2.630972331776529e+00, -2.136717999417038e+00, -1.633883384949810e+00, -1.113827258460965e+00, -6.617937046510753e-01, -5.612918514475175e-01, -4.701830843418677e-01, -3.512020612567385e-01, -2.470099234735885e-01, -1.674810358153112e-01, -1.010174585799871e-01, -6.215289702112323e-02, -4.224495497657099e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ft97_b_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.373071356843015e+00, -5.258845558149257e+00, -5.098542675141579e+00, -4.875962849399700e+00, -4.571579963243520e+00, -4.164263929911863e+00, -3.635816139190000e+00, -2.980117943496546e+00, -2.220546063734657e+00, -1.451650071398760e+00, -9.035193220313673e-01, -7.974181025213408e-01, -7.162386766873584e-01, -5.516616661698285e-01, -3.403191919905739e-01, -1.642077236009997e-01, -9.884046626802723e-02, -5.054450347042255e-02, -1.840428155548240e-02, -7.209518622573345e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ft97_b_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_b", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.022090423703933e-06, -4.322563536562631e-06, -4.797301694673677e-06, -5.580500962189282e-06, -6.956557217023884e-06, -9.602490844915015e-06, -1.537483766694107e-05, -3.034934129680073e-05, -7.933939668622345e-05, -2.925136680089623e-04, -1.549022740928099e-03, -6.818542149024768e-03, -1.194426669081660e-02, -2.795691928804771e-02, -1.205624986465484e-01, -8.842819502019160e-01, -8.437565784674176e+00, -1.896117715352285e+02, -1.755204606926313e+04, -1.038506836439970e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ft97_b_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.257832914262472e-02, -1.317555288717776e-02, -1.408818731335152e-02, -1.552111907713143e-02, -1.786138244032274e-02, -2.190828924418207e-02, -2.950457234140913e-02, -4.547040807837346e-02, -8.372270602533087e-02, -1.787206624384429e-01, -4.042956890563787e-01, -6.013861208411596e-01, -6.831193693141401e-01, -1.292233517831667e+00, -3.490441626311144e+00, -6.011643162916727e+00, 4.699156785799563e+01, 1.523323441114199e+02, 1.717666903785553e+04, 1.096315988852486e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ft97_b_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.899725447750669e-08, 3.308148191056464e-08, 3.999795054262559e-08, 5.259767459372373e-08, 7.811132469400229e-08, 1.382691634362971e-07, 3.142641814636903e-07, 1.007062905883701e-06, 4.994814300599317e-06, 3.888788973013244e-05, 5.775238848267001e-04, 1.381826215616004e-02, 3.807048914268423e-02, 1.602400429799324e-01, 1.693498713749852e+00, 7.013468281347279e+00, -5.459789135664137e+03, -1.522855932792321e+06, -1.052468331554765e+10, -3.634082468580680e+15]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ft97_b_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ft97_b", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.707973471483159e-14, -4.205273955708723e-14, -4.925010548536324e-14, -5.854982243665964e-14, -6.389352595050225e-14, -1.777881056735167e-14, 4.875445299588880e-13, 6.818418751033737e-12, 1.642145378021475e-10, 1.096976814615053e-08, 1.885814224318573e-06, 6.909446193333937e-05, 2.458356677870152e-04, 5.305220362402184e-03, 6.650585826259509e-01, 5.047831940672779e+02, 1.146690270107739e+06, 2.113199485625157e+10, 2.517447790109964e+16, 8.351490337704456e+24]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
