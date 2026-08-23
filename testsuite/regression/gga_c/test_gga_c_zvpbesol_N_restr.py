
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_zvpbesol_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbesol", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-7.322811301408218e-02, -7.220826673111243e-02, -7.074400996883315e-02, -6.864323080537939e-02, -6.563258175481122e-02, -6.132667047606911e-02, -5.519716149245647e-02, -4.659143648053887e-02, -3.506532936640381e-02, -2.215485002894390e-02, -1.701696452487529e-02, -4.862441244648723e-02, -5.563245388189321e-02, -4.185783660102418e-02, -2.494540909422762e-02, -8.311697051258738e-03, -7.134357746398531e-04, -8.575296253396531e-06, -8.747478279955583e-09, -2.807984425383034e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_zvpbesol_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbesol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.376590571560003e-01, -1.368151164276635e-01, -1.355914525112830e-01, -1.338101177087716e-01, -1.312004466736860e-01, -1.273370093168577e-01, -1.215143214226305e-01, -1.124693103042406e-01, -9.785324850164534e-02, -7.538213443783659e-02, -6.268673934633175e-02, -8.871229695848086e-02, -8.061079838981895e-02, -7.916215319836004e-02, -6.630347186361588e-02, -3.419912611553740e-02, -4.089718355347540e-03, -5.457487489138593e-05, -5.714689459848869e-08, -1.857544809464381e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_zvpbesol_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbesol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.727654515795143e-07, 7.191482749733585e-07, 7.913238982046248e-07, 9.074973382140916e-07, 1.103662614781730e-06, 1.457942349871169e-06, 2.160132370770127e-06, 3.736627279343838e-06, 7.880298687604031e-06, 2.141211669042137e-05, 1.216656579566311e-04, 2.943357132565547e-03, 7.250189187935950e-03, 1.264217598270968e-02, 3.760738519773288e-02, 1.370475946150112e-01, 2.267775783881135e-01, 1.014791853087659e-01, 1.269158971407812e-02, 3.166392589500310e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_zvpbesol_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbesol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.114734258686445e-04, -2.292748538115142e-04, -2.574679788001653e-04, -3.040619727468255e-04, -3.859731587535083e-04, -5.435249215568023e-04, -8.891397799650397e-04, -1.806054891260019e-03, -4.935142154248227e-03, -1.808095554345973e-02, -6.671010388706225e-02, -6.330282215741991e-03, 1.100135563640031e-02, -1.693716086459249e-02, -5.473340870973369e-01, -6.369023887592424e+00, -1.849043232686643e+01, -9.032706535103969e+00, -1.106195995324719e+00, -2.701077356077918e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_zvpbesol_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbesol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.898276738730213e-09, 2.206584128570172e-09, 2.737893659353933e-09, 3.728966394147039e-09, 5.800969568399425e-09, 1.090750435461745e-08, 2.687500269073326e-08, 9.732550216304611e-08, 6.019552300923992e-07, 7.179474210204878e-06, 1.756835366493299e-04, -7.338783963679494e-04, -1.330826882575315e-02, -9.912824010177904e-03, 4.258099685691020e-01, 3.317368256910322e+01, 1.240471491195882e+03, 1.993535104031271e+04, 2.901999241355603e+05, 5.425380284163384e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_zvpbesol_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_zvpbesol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.438906604593425e-14, -1.027744087932888e-13, -1.364148523741280e-13, -2.048426104429827e-13, -3.669867790476229e-13, -8.458894911964486e-13, -2.790594619662762e-12, -1.531163584243654e-11, -1.723574630976632e-10, -5.284466556416764e-09, -7.983265696653352e-07, -5.076848419942160e-04, -4.309054095191505e-03, -2.880006446828376e-02, -1.212516175461109e+00, -2.780593320585133e+02, -1.093724428176208e+05, -5.595844265695358e+07, -9.670690284629980e+10, -1.387231921489522e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
