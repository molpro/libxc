
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pbek1_vdw_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbek1_vdw", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.304630394342828e+00, -4.222981073477601e+00, -4.108688956161206e+00, -3.950614953671360e+00, -3.735745397557818e+00, -3.450886170132443e+00, -3.086597560659270e+00, -2.644165555541302e+00, -2.144112019307272e+00, -1.624198834987774e+00, -1.096924911560141e+00, -6.649261843158094e-01, -5.628293553840342e-01, -4.726011855544746e-01, -3.513037143614218e-01, -2.346335574879792e-01, -1.296269148478782e-01, -4.621051977290119e-02, -9.720063224288315e-03, -1.075564235580103e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pbek1_vdw_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbek1_vdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.374669111553271e+00, -5.260009324625498e+00, -5.099229443107803e+00, -4.876281811994991e+00, -4.572047766148615e+00, -4.166352660452984e+00, -3.643097141194069e+00, -3.000771673419852e+00, -2.272531520737294e+00, -1.560295532109079e+00, -1.009929419651879e+00, -7.975197723815181e-01, -7.149850170494042e-01, -5.529997853627281e-01, -3.549356549334086e-01, -2.055626996404505e-01, -1.377217696878678e-01, -5.961479745142138e-02, -1.293980443106962e-02, -1.434056781946631e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbek1_vdw_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbek1_vdw", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.914642547893011e-06, -4.236159369200196e-06, -4.744023480120320e-06, -5.579422348805156e-06, -7.035227735653485e-06, -9.788063441247215e-06, -1.562360806630210e-05, -3.008502606586284e-05, -7.397390177540227e-05, -2.435778789182191e-04, -1.205575895580195e-03, -7.145530311706646e-03, -1.317161628171187e-02, -2.865762102687619e-02, -1.069176880257293e-01, -5.744716034785544e-01, -2.380360144636996e+00, -4.505025226844522e+00, -5.521543275798527e+00, -6.103173774352928e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbek1_vdw_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbek1_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.235048498572539e-02, -1.292768196374151e-02, -1.380557636921391e-02, -1.517343029851265e-02, -1.737879315020284e-02, -2.110771773326807e-02, -2.782453485880476e-02, -4.083074375900567e-02, -6.676259202617163e-02, -1.060853444634221e-01, -1.823227984805038e-01, -5.778467311498279e-01, -6.831807716427477e-01, -1.208766832253989e+00, -2.478184520085108e+00, 1.572677349176193e+00, 5.160877332706615e+01, -3.798823981260539e+02, -1.481820556008892e+04, -1.237836176236838e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbek1_vdw_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbek1_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.517893578660733e-08, 2.879270425364762e-08, 3.488940834147636e-08, 4.590557728195765e-08, 6.783912603700918e-08, 1.178432820711514e-07, 2.548224521455325e-07, 7.271220399622653e-07, 2.721516936284325e-06, 7.184651865870016e-06, -7.249427189907972e-05, 1.192499587317498e-02, 3.847087691280214e-02, 1.284542405968817e-01, 6.711667472295890e-01, -3.993974250048041e+01, -6.667423722373182e+03, -5.352530451975572e+05, -7.716671675961237e+07, -6.323056461634506e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pbek1_vdw_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pbek1_vdw", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.255763549374881e-14, 5.414684479280087e-14, 7.651254643350496e-14, 1.256302662896577e-13, 2.555679815290109e-13, 7.049164382889841e-13, 2.987469014722010e-12, 2.302727069472116e-11, 3.990705167023166e-10, 1.927947249078377e-08, 2.857960157061304e-06, 2.775040924462010e-04, 1.575696335373827e-03, 1.873952315249006e-02, 1.372495908207412e+00, 5.661975332320872e+02, 6.710629134798114e+05, 1.626677175856051e+09, 2.802794366070835e+13, 1.782565345331759e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
