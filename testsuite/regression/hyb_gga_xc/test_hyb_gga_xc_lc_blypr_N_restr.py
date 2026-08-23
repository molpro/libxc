
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_gga_xc_lc_blypr_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blypr", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.188768849901334e+00, -4.106521824232138e+00, -3.991317295363226e+00, -3.831817864123013e+00, -3.614651869073337e+00, -3.325943507636218e+00, -2.954884822755492e+00, -2.499927738838567e+00, -1.976133515219192e+00, -1.416502367710199e+00, -8.711047687151979e-01, -5.220062412857736e-01, -4.292140773751447e-01, -3.276219037159548e-01, -1.886125261757959e-01, -6.689000008232185e-02, -1.179853321029751e-02, -3.337638944540727e-04, -2.059795128418512e-06, -2.784447109462864e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_gga_xc_lc_blypr_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blypr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.276414145802143e+00, -5.163286626154735e+00, -5.004787057890069e+00, -4.785276753041826e+00, -4.486308056900682e+00, -4.088823256332274e+00, -3.578533693439156e+00, -2.956350621440711e+00, -2.255509563646249e+00, -1.562785601013324e+00, -1.001702935773851e+00, -6.978854954634108e-01, -5.977023773148492e-01, -4.543498494867064e-01, -2.763886252375711e-01, -1.116794385293807e-01, -2.081002096472588e-02, -7.934248168813848e-04, -4.119421067805184e-06, -5.568893745194213e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blypr_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blypr", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.800724231801347e-06, -4.090296341240727e-06, -4.543952573312782e-06, -5.281221344967530e-06, -6.543255962892199e-06, -8.866815486818797e-06, -1.359808450917075e-05, -2.462997282885654e-05, -5.519300567308582e-05, -1.581917829998127e-04, -6.120391252073328e-04, -3.642849542353700e-03, -6.766618915330283e-03, -9.917542520786716e-03, -1.391101671446824e-02, 1.102243350395372e-02, -1.854876609428706e-02, -1.597005622255803e-03, -2.828209511506397e-05, -6.380209847038626e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blypr_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blypr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.173610147699013e-02, -1.224902340684602e-02, -1.302418448856268e-02, -1.422055941620112e-02, -1.612227044108579e-02, -1.927011535238037e-02, -2.476592388166476e-02, -3.497911145583741e-02, -5.481668426945397e-02, -8.998955780997286e-02, -1.546762883285998e-01, -4.638255193685005e-01, -6.117225044330835e-01, -8.900613633741380e-01, -1.539614219982071e+00, -4.820435587585931e+00, -1.501108877729183e+01, -3.364343543206102e+01, -1.442075973870232e+01, -1.442420144867799e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blypr_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blypr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.846534227789562e-08, 2.087588309737922e-08, 2.487754181042828e-08, 3.193792579359355e-08, 4.550418094359424e-08, 7.480778616281560e-08, 1.486171363384883e-07, 3.704737113735322e-07, 1.083514335493932e-06, -4.161766594183535e-07, -1.693102778247684e-04, 2.131640104122923e-03, 9.909585952738699e-03, -2.493214137147086e-04, -3.914274010879737e-01, -7.455261219128456e+00, -5.091949760830806e+01, -1.655729192579864e+02, -3.589347992433096e+02, -6.286506802648154e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_gga_xc_lc_blypr_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_gga_xc_lc_blypr", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.885574763029446e-14, 1.231527366683878e-13, 1.687927507650911e-13, 2.651461316505364e-13, 5.056946832356871e-13, 1.269259193869491e-12, 4.683708489789292e-12, 2.948821651782210e-11, 3.841084102300825e-10, 1.312111606631678e-08, 1.551197573019131e-06, 3.367054567127818e-04, 2.750661323927965e-03, 1.622786187454872e-02, 4.811640876333502e-01, 4.392772365540414e+01, 3.888297271826068e+03, 3.735880136738413e+05, 9.772780825960377e+07, 1.329187205085465e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
