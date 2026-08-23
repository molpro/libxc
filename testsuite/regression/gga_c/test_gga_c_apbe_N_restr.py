
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_apbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_apbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.987699769913805e-02, -5.882876171491223e-02, -5.732717713140442e-02, -5.518028652564621e-02, -5.212013002722644e-02, -4.778187874297297e-02, -4.170095553491864e-02, -3.341184013502801e-02, -2.297062340996050e-02, -1.263140302074212e-02, -9.133781556088384e-03, -4.022496647946792e-02, -5.079918118402049e-02, -3.406224592916744e-02, -1.680049725407687e-02, -4.104094120975343e-03, -2.672901276279816e-04, -2.942499063663858e-06, -2.965584511593805e-09, -9.513167998349507e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_apbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_apbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.290298890228971e-01, -1.279962201370922e-01, -1.264938234415744e-01, -1.242982698424882e-01, -1.210617008728463e-01, -1.162222218182507e-01, -1.088182327287086e-01, -9.711709105317590e-02, -7.830426880967765e-02, -5.217707081626408e-02, -4.044360553688622e-02, -8.800095039672218e-02, -8.352339602144040e-02, -7.838414431602342e-02, -5.633542408395737e-02, -1.996342938843756e-02, -1.603532584381363e-03, -1.882648182802994e-05, -1.937946289405638e-08, -6.293200713829632e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_apbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_apbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.325170750789540e-07, 7.808275253245802e-07, 8.556497257808964e-07, 9.752198650000556e-07, 1.174849660994240e-06, 1.528759428084469e-06, 2.207911385128113e-06, 3.642804575261414e-06, 6.986614917993413e-06, 1.597295677688758e-05, 8.376235523424666e-05, 3.666174417486489e-03, 1.054985769259889e-02, 1.572835720802431e-02, 3.672474644040788e-02, 8.460519812551769e-02, 8.990425713604581e-02, 3.505007502889314e-02, 4.304220120450021e-03, 1.072747456766444e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_apbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.218955669040713e-04, -3.480198928452550e-04, -3.893982757155859e-04, -4.578044003022669e-04, -5.781315690308515e-04, -8.096532117570100e-04, -1.315796014382022e-03, -2.628317504956652e-03, -6.703095929668522e-03, -2.003695955236489e-02, -6.649965366819888e-02, -3.675992805549017e-02, 6.701707042683469e-03, -1.102650699836834e-01, -1.064266332933252e+00, -5.491976891424708e+00, -7.892344547938065e+00, -3.144278693280007e+00, -3.753039042871644e-01, -9.151078867785298e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_apbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.211886750490814e-09, 3.709019219415744e-09, 4.561759100164213e-09, 6.142680533625070e-09, 9.421873854120538e-09, 1.742182826827181e-08, 4.206919005488444e-08, 1.475091430356845e-07, 8.380185720845833e-07, 8.056966660700129e-06, 1.772037343076377e-04, 1.937476181465027e-03, -1.162324991919834e-02, 2.771811371978400e-02, 9.516313084154597e-01, 2.914684150489400e+01, 5.309108572788283e+02, 6.941878690546186e+03, 9.845970191511668e+04, 1.838085194641116e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_apbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.053993170073345e-13, -1.280669553496892e-13, -1.694427496999869e-13, -2.533203541582933e-13, -4.511351740709917e-13, -1.031474426308598e-12, -3.363682625992173e-12, -1.807398893324420e-11, -1.923211626340366e-10, -5.052513609598569e-09, -7.029210143845398e-07, -8.830364140057673e-04, -9.502550883634064e-03, -5.199182949400048e-02, -1.713438073004843e+00, -2.194993064846433e+02, -4.607418479770867e+04, -1.945681882607689e+07, -3.280855665691407e+10, -4.699850770485816e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
