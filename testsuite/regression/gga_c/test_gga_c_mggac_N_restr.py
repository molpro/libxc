
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_mggac_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_mggac", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.276814403175327e-02, -8.179112159673659e-02, -8.038671714302109e-02, -7.836834058711604e-02, -7.546824691054867e-02, -7.130339250357538e-02, -6.533334261625594e-02, -5.684116070284690e-02, -4.514449467498675e-02, -3.119360609890190e-02, -2.497113379381305e-02, -5.387049088063155e-02, -5.829306536617112e-02, -4.671340657258609e-02, -3.104800838974817e-02, -1.290776673728205e-02, -1.474772008046516e-03, -1.983317147858917e-05, -2.054807014001140e-08, -6.601795646223935e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_mggac_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_mggac", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.414254434550133e-01, -1.407060645011399e-01, -1.396639430095425e-01, -1.381492358663918e-01, -1.359362679724092e-01, -1.326763876683347e-01, -1.278076787208179e-01, -1.203627104591970e-01, -1.085723418926157e-01, -9.023728861156059e-02, -7.799731997720950e-02, -8.711637493568894e-02, -7.837257392699362e-02, -7.756734859464795e-02, -6.909896045129905e-02, -4.477176399581424e-02, -7.965639466339592e-03, -1.253506788750598e-04, -1.341915834595342e-07, -4.367212941368533e-12]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_mggac_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_mggac", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.014090548165798e-07, 6.441612000490061e-07, 7.108698798363951e-07, 8.186841647733013e-07, 1.001872099524151e-06, 1.335967488523256e-06, 2.008962395535527e-06, 3.564521326414850e-06, 7.895543616819248e-06, 2.361484937719329e-05, 1.404022097218832e-04, 2.311047458127295e-03, 5.167807595103734e-03, 9.873733773521630e-03, 3.361880823092746e-02, 1.667843462692877e-01, 4.348921750966190e-01, 2.327055149137237e-01, 2.979964803673114e-02, 7.444392395487873e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_mggac_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_mggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.315175381310880e-04, -1.435519821717850e-04, -1.626895849859204e-04, -1.944868734845438e-04, -2.507558611697759e-04, -3.597974193713350e-04, -6.007814225543501e-04, -1.245268042950440e-03, -3.498157788998424e-03, -1.392228360975412e-02, -5.334696916684888e-02, 4.622426976033317e-03, 7.234527152786314e-03, 1.448876424093036e-02, -2.133494280218443e-01, -5.211776080032544e+00, -3.204208120216008e+01, -2.050116614017208e+01, -2.596010478113514e+00, -6.350358935346000e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_mggac_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_mggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.312866342090651e-10, 1.103177898279068e-09, 1.403643275235771e-09, 1.974812670062173e-09, 3.198297773449467e-09, 6.304456873200087e-09, 1.635142515186867e-08, 6.232885784469983e-08, 4.078015458586029e-07, 5.397847163610940e-06, 1.373095305938928e-04, -1.700320802854129e-03, -1.167533506926484e-02, -2.259295008233894e-02, 8.699904616964177e-02, 2.610611267297869e+01, 2.140304457274455e+03, 4.522544270749557e+04, 6.810179632740272e+05, 1.275531568133594e+07]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_mggac_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_mggac", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.619786644361371e-14, -8.084259480396984e-14, -1.077205253521917e-13, -1.626271253448977e-13, -2.935053293815347e-13, -6.831867205382649e-13, -2.282548414566315e-12, -1.272673892213541e-11, -1.468091836850079e-10, -4.781382371264657e-09, -7.414827362137927e-07, -2.980539720479506e-04, -2.150706162388039e-03, -1.638979626992005e-02, -7.890074151804780e-01, -2.592027703013449e+02, -1.931713100129646e+05, -1.271988088347396e+08, -2.269651379256749e+11, -3.261449693406060e+15]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
