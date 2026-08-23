
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_ev93_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ev93", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.281219772742295e+00, -4.200436264477083e+00, -4.087509952195933e+00, -3.931661853084871e+00, -3.720571217133082e+00, -3.442447787590055e+00, -3.090815136574436e+00, -2.673172094568867e+00, -2.220539621111176e+00, -1.767720369414303e+00, -1.228648718081284e+00, -6.639434882807316e-01, -5.596850566108004e-01, -4.740998951773852e-01, -3.718804293442021e-01, -2.791192980070006e-01, -1.548501255487656e-01, -4.132243985480098e-02, -7.561673111416601e-03, -8.294582817459787e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_ev93_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ev93", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.319159139495031e+00, -5.199737247897248e+00, -5.031798496758424e+00, -4.797911798718824e+00, -4.476624152049896e+00, -4.043780038101842e+00, -3.476826970906566e+00, -2.766688270300991e+00, -1.954627088988525e+00, -1.225750278254734e+00, -7.839873186541122e-01, -7.704865671755129e-01, -7.124533021921163e-01, -5.240303058872698e-01, -2.906856622748163e-01, -1.813006235293231e-01, -2.003941670475821e-01, -6.568650725231653e-02, -1.024220966220349e-02, -1.106176709956297e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ev93_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ev93", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.175331922832051e-06, -4.581472817212495e-06, -5.234572380878063e-06, -6.336731406032378e-06, -8.328768473904840e-06, -1.229392579968383e-05, -2.130902310235085e-05, -4.572189813217142e-05, -1.269427729543193e-04, -4.552064396023268e-04, -2.275147334440256e-03, -9.209620439839647e-03, -1.255465318169512e-02, -4.016291460106749e-02, -1.933094604259729e-01, -1.022004713763877e+00, -4.116616297709391e-01, 2.386313041181939e+01, 4.355699591472715e+01, 4.912358681059460e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ev93_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ev93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.447025291270709e-02, -1.528782551577881e-02, -1.655288853201206e-02, -1.857361777963824e-02, -2.194992950576351e-02, -2.795117911123070e-02, -3.948877686109566e-02, -6.337028705123496e-02, -1.104151527457374e-01, -1.400247134730160e-01, -1.067240538066086e-01, -7.817560441694497e-01, -7.493654519920978e-01, -1.755581767454360e+00, -3.951249857333600e+00, 1.692997105174934e+01, 1.257005034883404e+02, -1.589754559417008e+03, -1.415880661843896e+04, -9.574569237047480e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ev93_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ev93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.903224764676391e-08, 5.713125592723086e-08, 7.109971357114831e-08, 9.713979273182294e-08, 1.513018275914032e-07, 2.824020999065371e-07, 6.709919109493620e-07, 2.145158776869784e-06, 9.027017647642211e-06, 2.845471142368406e-05, -1.489887669147076e-04, 2.945483101364233e-02, 6.382174999151020e-02, 3.484062905557870e-01, 2.360381099289734e+00, -1.184546097511789e+02, -1.313210534883531e+04, 2.049350553586870e+06, 6.004728727223810e+08, 5.088448925603673e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_ev93_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_ev93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.925585454948259e-13, -2.385105068640027e-13, -3.236454316058234e-13, -4.991620508856900e-13, -9.186941898062488e-13, -2.139744502788470e-12, -6.623230464869634e-12, -2.463223044243052e-11, 1.351135929904916e-10, 2.998283555834684e-08, 5.425942510699580e-06, -7.725698321517464e-04, -8.585711755153536e-03, -3.629477545620206e-02, 1.400825333174914e+00, 1.261103704409325e+03, 9.281042009643830e+05, -6.845611856753730e+09, -2.188507686629478e+14, -1.434573533428743e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
