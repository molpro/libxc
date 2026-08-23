
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_hyb_mgga_x_wr2scan_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.688772739008730e+00, -4.589950001120862e+00, -4.451439299769356e+00, -4.259490519511060e+00, -3.997770687577131e+00, -3.649085171027649e+00, -3.199525626457091e+00, -2.645988229296727e+00, -2.006367234572167e+00, -1.321364804162068e+00, -6.815772258790942e-01, -4.282177555443013e-01, -4.179485542692685e-01, -3.295723496251364e-01, -1.822603830749938e-01, -5.828175264007301e-02, -6.667546507299028e-03, -1.989975533258666e-04, -1.140174004857874e-06, -6.401708607351867e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_hyb_mgga_x_wr2scan_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.211692584535633e+00, -6.078857611271514e+00, -5.892646907337213e+00, -5.634523357559297e+00, -5.282386287584762e+00, -4.812749207321047e+00, -4.206082793488136e+00, -3.456542254003944e+00, -2.582197796366013e+00, -1.611894634121954e+00, -9.657494221438628e-01, -6.355580145187477e-01, -6.706577385892458e-01, -4.892152191757828e-01, -2.638697272135944e-01, -7.712514535098121e-02, -9.909149867472503e-03, -4.234703689792857e-04, -2.676922179919045e-06, -1.401896253226324e-09]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_wr2scan_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.196864695297506e-06, -3.447534108598327e-06, -3.842154769074342e-06, -4.488861266425550e-06, -5.612610218107438e-06, -7.739480790553795e-06, -1.229413781347071e-05, -2.397762003057281e-05, -6.464959336759659e-05, -3.321577318227179e-04, -6.257664659051582e-04, -4.128003435367373e-03, -1.807450720307196e-02, -2.794265652860523e-02, -9.307257598930288e-02, -4.743648378484567e-01, -7.513719092786931e-01, -7.141504558957527e-02, 4.573278740704470e-02, -6.545300753041605e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_wr2scan_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.727217358557533e-03, 4.799930370768814e-03, 4.906039722292770e-03, 5.062406388337521e-03, 5.296833444375889e-03, 5.658111266415080e-03, 6.234672736244371e-03, 7.201737008101072e-03, 9.166634496232231e-03, 1.617464395620844e-02, 7.707315928083524e-03, 6.535935820229437e-03, 4.611212406967553e-02, 4.617882366937429e-02, 5.048554339295244e-02, 4.539467602261706e-02, 6.373179869208411e-03, 5.168393672368221e-05, 2.202805921249847e-07, 4.426462329912876e-10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_wr2scan_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.304217872177606e-02, -1.359955980338509e-02, -1.444501175840733e-02, -1.575840283276267e-02, -1.786882322929100e-02, -2.141318831459247e-02, -2.766466495391995e-02, -3.931524228094369e-02, -6.256273052533760e-02, -1.672964762035394e-01, -3.031673283794780e-01, -6.738989990978628e-01, -9.535547130414969e-01, -1.305439609110793e+00, -3.035972814793197e+00, -1.532438841974558e+01, -9.163144895048991e+01, -4.576646530464514e+01, -3.995779494551041e+01, -8.311960354732926e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_wr2scan_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([8.097361641485952e-09, 8.831048445253894e-09, 1.001646794256065e-08, 1.203929683543274e-08, 1.569331943775556e-08, 2.186290728072993e-08, 2.025081894463877e-08, -1.574974257467550e-07, -3.329813153200009e-06, -2.816733161955673e-05, 7.008100531091490e-05, -1.526765795883387e-02, 5.466715380830633e-02, 1.072508874321315e-01, 4.573796918403160e-01, 1.216580878667855e+02, 1.629321468256747e+04, 1.939100639283982e+05, 2.052234450523790e+07, 4.408665557202972e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_wr2scan_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([9.061541310037750e-06, 1.030761608758689e-05, 1.230108530813961e-05, 1.564585136909517e-05, 2.173122685593283e-05, 3.464789552377918e-05, 7.024301401464621e-05, 2.011221025921037e-04, 8.739982474989436e-04, 3.601952330490749e-03, 1.426574884056597e-03, 3.895119456719832e-02, 4.855183880205306e-02, 5.806707629772024e-03, 3.782732602603365e-01, -7.871545455286781e+00, -1.214167986924055e+02, -4.643799915601599e+01, -4.305528262429062e+01, -1.324714845045850e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_wr2scan_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.233945047137636e-13, 4.067957505347928e-13, 5.641520668517090e-13, 8.983460388891238e-13, 1.742608143280797e-12, 4.517100783544375e-12, 1.821500195984555e-11, 1.408678191361609e-10, 2.741646246551005e-09, 1.251500947916951e-07, -1.839578669772978e-06, 1.313372418980939e-03, 6.016503049845645e-04, 7.518006255071995e-02, 3.114558628226871e+00, -1.801669377680618e+03, -3.447026401078452e+06, -1.246618648812616e+09, -1.488018740810049e+13, -2.499503431468990e+19]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_wr2scan_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.583365688209533e-10, -4.259116464754649e-10, -5.450265898924025e-10, -7.746879789069724e-10, -1.280182513255956e-09, -2.640532211105605e-09, -7.614437327920830e-09, -3.589131433480534e-08, -3.424056615158891e-07, -5.503468444618413e-06, 3.499673603467757e-05, 6.227963347744798e-04, -1.011910689926516e-03, -8.967650716759530e-02, -1.366398918611345e+00, 1.734249798255822e+02, 2.708191567617700e+04, 3.145908413506740e+05, 3.270973418959074e+07, 7.622679931221773e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_hyb_mgga_x_wr2scan_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("hyb_mgga_x_wr2scan", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.880485898955752e-07, 4.365721481749982e-07, 5.171074392685245e-07, 6.595238473487561e-07, 9.356763736504239e-07, 1.548189836779335e-06, 3.201950983002349e-06, 9.180118153369245e-06, 4.286135575688007e-05, 2.429989491702548e-04, -4.978532935162925e-04, -4.287983740272190e-03, -2.819556700192538e-02, 1.131947016638777e-01, 6.073624915162684e-01, -1.663719262737422e+01, -2.131307784587930e+02, -8.078260905955941e+01, -7.385934185809654e+01, -2.337523860041306e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
