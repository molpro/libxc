
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_pw91_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.322469476762334e+00, -4.240715932178527e+00, -4.126246730976352e+00, -3.967860008082617e+00, -3.752415216118635e+00, -3.466453327511143e+00, -3.099968724744706e+00, -2.653059993059846e+00, -2.144213336685434e+00, -1.611304976901031e+00, -1.082801223928146e+00, -6.679123491761232e-01, -5.648513168851312e-01, -4.745794237241172e-01, -3.501246328090730e-01, -2.291195527441721e-01, -1.204246568302483e-01, -1.380694182059036e-02, -1.249912480911544e-04, -1.651393451545206e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_pw91_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.380110077872611e+00, -5.266490988729107e+00, -5.107262864442547e+00, -4.886659256660578e+00, -4.586021490922470e+00, -4.185929656656681e+00, -3.671452246732679e+00, -3.042361122891321e+00, -2.330166360101906e+00, -1.621262576340790e+00, -1.050928780769907e+00, -8.019491545393956e-01, -7.147670283833433e-01, -5.580080788640771e-01, -3.666384941353730e-01, -2.102310510144037e-01, -1.630309423483498e-01, -5.139620764816939e-02, -5.109690101648624e-04, -6.631495471613019e-07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw91_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.111475262394140e-06, -4.432345525317081e-06, -4.936488541793554e-06, -5.759353109466010e-06, -7.177201516890597e-06, -9.814607716186792e-06, -1.527542920117085e-05, -2.838063616213147e-05, -6.671892439273448e-05, -2.121262409603507e-04, -1.046219227697570e-03, -7.109595099682520e-03, -1.425417765078229e-02, -2.777686826739303e-02, -9.440922297920587e-02, -5.101052479815729e-01, 1.670824532568451e-01, 7.433218351543431e+01, 9.374541902242828e+01, 9.365801293250576e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw91_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.192573657005316e-02, -1.245576005221929e-02, -1.325805412265992e-02, -1.449934491637408e-02, -1.647998065645100e-02, -1.977842487791629e-02, -2.559519276025361e-02, -3.659371819071679e-02, -5.863233713012121e-02, -1.000906407626775e-01, -1.975972905970787e-01, -5.384466264529844e-01, -6.697402302386257e-01, -1.104755746581543e+00, -2.205420653595910e+00, -6.796782300315536e-01, 1.949953223303717e+02, -3.644084258394603e+03, -5.555280569197695e+03, -5.187633419495542e+03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw91_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.051280341013149e-08, 2.325225274848594e-08, 2.781910061867794e-08, 3.592881938982672e-08, 5.167015056262173e-08, 8.624183376405035e-08, 1.759069323710708e-07, 4.618549444451563e-07, 1.551073396669265e-06, 3.385028192440532e-06, -5.446828712073133e-05, 8.572111269492611e-03, 3.354321424153053e-02, 8.690769241347435e-02, 3.592893808017359e-01, -2.859466318066398e+01, -1.696984268190711e+04, 7.012041763456119e+06, 1.350158202274765e+09, 9.757899257346587e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_pw91_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_pw91", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.083483997589117e-13, 1.352201935717366e-13, 1.858285563594428e-13, 2.930855714057383e-13, 5.624370986781109e-13, 1.425375204067131e-12, 5.343210045903807e-12, 3.456855458982947e-11, 4.739339601074946e-10, 1.794571666368140e-08, 2.457697581609246e-06, 5.403422528597497e-04, 4.710560113570851e-03, 3.213243648746381e-02, 1.431808247193843e+00, 4.659706289577051e+02, 1.134995246430073e+06, -2.273977677416750e+10, -4.867558558403399e+14, -2.747046333447643e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
