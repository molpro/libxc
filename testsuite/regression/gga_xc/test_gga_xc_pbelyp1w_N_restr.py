
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_xc_pbelyp1w_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbelyp1w", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.379612618791927e+00, -4.297621083026164e+00, -4.182825419744797e+00, -4.024002284171888e+00, -3.807999177828534e+00, -3.521378545569772e+00, -3.154235667456306e+00, -2.706872619515886e+00, -2.197596665697177e+00, -1.660700108560399e+00, -1.122755224297423e+00, -7.125264737771594e-01, -6.098231967500833e-01, -5.130168974551041e-01, -3.785764807955887e-01, -2.396141789993271e-01, -1.181955531697316e-01, -4.732870075018081e-02, -1.031534227388638e-02, -1.161760454009121e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_xc_pbelyp1w_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbelyp1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.462531880003450e+00, -5.348003211643035e+00, -5.187437334962389e+00, -4.964853426270106e+00, -4.661268542478163e+00, -4.256799905653621e+00, -3.736011288937904e+00, -3.098944507234699e+00, -2.382011038543481e+00, -1.688716724534858e+00, -1.133681112959861e+00, -8.602495297662890e-01, -7.714280122367393e-01, -6.102156081898080e-01, -4.150943250498988e-01, -2.672888702395141e-01, -1.683321384602862e-01, -6.163870363136498e-02, -1.369637014539609e-02, -1.547209694347967e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_pbelyp1w_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbelyp1w", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.811204901157974e-06, -4.120537934675507e-06, -4.608364581763620e-06, -5.408827943651224e-06, -6.798412840524917e-06, -9.409842406894933e-06, -1.488803495061370e-05, -2.820913981549832e-05, -6.715971212144707e-05, -2.067524489882745e-04, -9.471820238604546e-04, -6.397719884181544e-03, -1.193101727271790e-02, -2.460959002561597e-02, -8.007663685460198e-02, -2.600654299790413e-01, 1.443602000941306e+00, 9.310633489053415e-01, -3.571405997562360e+00, -3.945220307491248e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_pbelyp1w_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbelyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.221877826592776e-02, -1.277997395708678e-02, -1.363160536430135e-02, -1.495384236275951e-02, -1.707336791839199e-02, -2.062163796603141e-02, -2.689533690750420e-02, -3.857626142141327e-02, -5.958286844655393e-02, -7.861238794241543e-02, -9.196731318933786e-02, -5.565190443999734e-01, -6.827168129144543e-01, -1.141164251041786e+00, -1.873908684684389e+00, 5.369388582961083e+00, 4.447024975869066e+01, -4.895009138180021e+02, -1.557322159483313e+04, -1.328716923900019e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_pbelyp1w_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbelyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.348331974901286e-08, 2.677863231253047e-08, 3.231142397917556e-08, 4.223429207731531e-08, 6.175464099110796e-08, 1.053514707898633e-07, 2.202545495387496e-07, 5.836489033032827e-07, 1.723116137234552e-06, -5.058226355038013e-06, -3.415986016977795e-04, 9.372496107930230e-03, 3.276037059891850e-02, 9.042270229293323e-02, -5.400103507129089e-02, -6.899725829947567e+01, -7.623702922607255e+03, -2.323649878231087e+05, -4.993287973388747e+07, -4.087378616760578e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_xc_pbelyp1w_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_xc_pbelyp1w", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.163688576451838e-14, 6.563660898918558e-14, 9.261723556761176e-14, 1.517458766056212e-13, 3.076544906084024e-13, 8.439496884336762e-13, 3.543491687281260e-12, 2.685548436924499e-11, 4.506067643958339e-10, 2.053793587204021e-08, 2.939744764237688e-06, 3.313475137708196e-04, 1.924666022940885e-03, 2.214646264617367e-02, 1.510082154665420e+00, 5.320791590928268e+02, 4.994683637990815e+05, 1.072181297640959e+09, 1.813440463988309e+13, 1.152292398138968e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
