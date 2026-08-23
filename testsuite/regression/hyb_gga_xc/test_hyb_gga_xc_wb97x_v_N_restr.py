
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_wb97x_v_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_v", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.515646052058723e+00, -3.446677033763145e+00, -3.350111913148502e+00, -3.216512119371446e+00, -3.034832704347810e+00, -2.793856890031365e+00, -2.485597645256336e+00, -2.111586178803567e+00, -1.691472696596433e+00, -1.261956574994544e+00, -8.143328000646928e-01, -4.650783206357359e-01, -3.892429277171678e-01, -3.025755796465691e-01, -1.892742315282011e-01, -8.336243931971332e-02, -1.431340136701314e-02, 1.003970794517212e-03, 4.311995678442119e-04, 4.385359605805931e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_wb97x_v_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_v", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.469609231846563e+00, -4.372950255139897e+00, -4.237288501402771e+00, -4.048901455189184e+00, -3.791223000675591e+00, -3.446202268447228e+00, -2.997793285024192e+00, -2.438815605428894e+00, -1.784984987352980e+00, -1.120082621246619e+00, -6.779209812562796e-01, -6.123486594513787e-01, -5.384480318048606e-01, -4.052435315186227e-01, -2.373295115321586e-01, -1.022292119240657e-01, -2.787051508573286e-02, 2.821478740256346e-04, 5.648920964112275e-04, 5.933227732098345e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_v_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_v", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.599444594337530e-06, -2.825611776818823e-06, -3.185419781401434e-06, -3.783612542900833e-06, -4.843027839485685e-06, -6.897168673978233e-06, -1.142952598383670e-05, -2.342571867007642e-05, -6.395269826161999e-05, -2.439995937531697e-04, -1.210825499181055e-03, -2.998161952559082e-03, -2.766123905700621e-03, -9.806879064066385e-03, -4.128652802090943e-02, -1.817898518593104e-01, 3.579474719266956e-03, 1.146833524554554e+00, 1.968437936414171e+00, 2.461351559255477e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_v_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.053608033618901e-02, -1.105788413372435e-02, -1.185798722376131e-02, -1.312061307432396e-02, -1.519894623636359e-02, -1.883934282426524e-02, -2.582699139540444e-02, -4.110269454245567e-02, -7.993970146204321e-02, -1.791910014863488e-01, -3.882238639596381e-01, -4.823044678821839e-01, -5.556311065495489e-01, -9.873150898201920e-01, -2.495130152488371e+00, -4.887922835634265e+00, -2.030222106381975e+01, -8.627469131835410e+01, 5.258002713514235e+02, 5.421211647856185e+04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_v_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.302438809925480e-08, 2.661776183652537e-08, 3.278130933090726e-08, 4.420115862889912e-08, 6.783989505078850e-08, 1.251961209436524e-07, 2.996557400998000e-07, 1.025961020979864e-06, 5.538980932029162e-06, 4.632689747934874e-05, 6.527407685664144e-04, 9.419715442964875e-03, 2.252235696595577e-02, 9.494803106074171e-02, 1.029839341837506e+00, 5.894393454433641e+00, 4.457466022127043e+01, 1.332109483355153e+05, 2.728810985787807e+07, 2.544456778593938e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_wb97x_v_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_wb97x_v", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.569335268786044e-14, -5.637831629139368e-14, -7.622659108475823e-14, -1.174709485101916e-13, -2.181361790919445e-13, -5.271944417424443e-13, -1.834643859861500e-12, -1.020572962755947e-11, -8.260183571719732e-11, 2.466964380159217e-09, 7.410205222289787e-07, -3.331986794143679e-04, -6.548761961754608e-03, -1.890642845690671e-02, -4.552769578240762e-01, 1.593731435144689e+01, -3.077542026717293e+04, -4.207868908038298e+08, -9.998317037119416e+12, -7.188973462581179e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
