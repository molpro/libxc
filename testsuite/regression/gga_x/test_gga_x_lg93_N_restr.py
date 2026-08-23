
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_lg93_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lg93", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.272499719956559e+00, -4.191328232576170e+00, -4.077878242591768e+00, -3.921375768974955e+00, -3.709627177381964e+00, -3.431297049289767e+00, -3.080562507464907e+00, -2.661341139540239e+00, -2.182150533701159e+00, -1.653988658991878e+00, -1.110140766449411e+00, -6.617553383734065e-01, -5.590882615456287e-01, -4.725127370450166e-01, -3.584746931436804e-01, -2.319214193210986e-01, -1.249304573607730e-01, -5.434223397045625e-02, -1.776796752322795e-02, -3.764013598647575e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_lg93_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lg93", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.346867217997382e+00, -5.226419810244279e+00, -5.056381557180823e+00, -4.818153966256188e+00, -4.488169766040360e+00, -4.040700343187709e+00, -3.466013895891474e+00, -2.822116252544315e+00, -2.217762877907509e+00, -1.655880483327594e+00, -1.108427848263322e+00, -7.688159655096750e-01, -7.153300556197554e-01, -5.233002866965438e-01, -3.607051012299861e-01, -2.305972197915872e-01, -1.220941563264608e-01, -5.137101165299744e-02, -1.660352889576822e-02, -3.537341336108234e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lg93_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lg93", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.753276905482767e-06, -4.137702072369143e-06, -4.766139261625013e-06, -5.852432264498111e-06, -7.879114005997421e-06, -1.202857714705118e-05, -2.121452404869055e-05, -4.163995532717370e-05, -8.728358318157730e-05, -2.210973602307059e-04, -9.901633640833115e-04, -9.109562720641515e-03, -1.119028438549729e-02, -3.964790988518221e-02, -1.104906084477985e-01, -4.210534216633968e-01, -3.015252027175534e+00, -4.751322332824839e+01, -1.929583508307610e+03, -3.132077602181908e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lg93_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lg93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.463206809472216e-02, -1.560819500625025e-02, -1.715135949917967e-02, -1.966845295303888e-02, -2.386377438799312e-02, -3.052231934253422e-02, -3.781176008655751e-02, -3.525182366600554e-02, -1.967040548738647e-02, -9.418199099883603e-03, -1.358610775595948e-02, -8.369088387230197e-01, -7.243612800873668e-01, -1.531276289810593e+00, -3.739637121044517e-01, -2.522671368083598e-01, -2.312371782641789e+00, 4.423261179479851e+01, 3.717873931556262e+03, 7.077363830412736e+05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lg93_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lg93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([5.021512575053191e-08, 6.018946012490963e-08, 7.792561301056433e-08, 1.120467271983262e-07, 1.836426273428177e-07, 3.405429562231589e-07, 6.174994584385254e-07, 5.033613500098954e-07, -3.082871481124372e-06, -3.388989578100470e-05, -5.763475068118020e-04, 3.395261503873616e-02, 5.366599287577013e-02, 2.654944899654306e-01, -1.338605373319842e+00, -3.400604760541778e+01, -2.652566086604153e+03, -1.298554817563207e+06, -6.288097708434323e+09, -7.953768697689859e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_lg93_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_lg93", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-2.389666338026028e-13, -3.136112275637314e-13, -4.597563217523617e-13, -7.795014976068023e-13, -1.565989787180262e-12, -3.539526050721076e-12, -4.923005049382395e-12, 6.070951588610918e-11, 1.265019376688539e-09, 3.376194889699774e-08, 3.723787097614499e-06, -1.150771358872437e-03, -6.456409129102314e-03, -6.685388813230244e-03, 3.333224751923162e+00, 4.403310394251448e+02, 4.573327341912242e+05, 7.361538942738985e+09, 4.164576619995758e+15, 3.968729974980031e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
