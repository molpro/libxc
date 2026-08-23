
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_2d_b88_HO2D_restr_1_zk():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b88", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.488250398445515e-01, -8.488228789253529e-01, -8.488171972725241e-01, -8.488022845012735e-01, -8.487632516576766e-01, -8.486615424990719e-01, -8.483983936562767e-01, -8.477251274441423e-01, -8.460321087665366e-01, -8.418846851320950e-01, -8.321080073904186e-01, -8.102935907153237e-01, -7.652408450322605e-01, -6.818940692371117e-01, -5.501453332675080e-01, -3.821093749989537e-01, -2.232178149863966e-01, -1.295003916336735e-01, -9.786188442862966e-02, -8.348389018657955e-02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_2d_b88_HO2D_restr_1_vrho():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.273237557452066e+00, -1.273234308508504e+00, -1.273225753823524e+00, -1.273203248031022e+00, -1.273144122301924e+00, -1.272989148061631e+00, -1.272584486669854e+00, -1.271534511915253e+00, -1.268838829217934e+00, -1.262040408705856e+00, -1.245406285021452e+00, -1.206738163380825e+00, -1.124067439831580e+00, -9.688516523466054e-01, -7.292059811785475e-01, -4.466086376841945e-01, -2.000457558188062e-01, -5.874312955406281e-02, -1.740362982582538e-02, -8.718671418938815e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b88_HO2D_restr_1_vsigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b88", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.948923876607441e-02, -1.948938639258598e-02, -1.948977256423793e-02, -1.949077780292991e-02, -1.949337395174163e-02, -1.949999439929272e-02, -1.951653943558251e-02, -1.955658705839214e-02, -1.964882857515083e-02, -1.984617892609677e-02, -2.023115146072082e-02, -2.094600565825861e-02, -2.239908537713220e-02, -2.575512978800897e-02, -3.406375956392224e-02, -5.968759608882920e-02, -2.081964233773211e-01, -2.861103260799730e+00, -3.696799614055925e+02, -1.827286437696685e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b88_HO2D_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.000001564446960e+00, -1.000004128058560e+00, -1.000010897582725e+00, -1.000028788926234e+00, -1.000076136615849e+00, -1.000201673953277e+00, -1.000535343591023e+00, -1.001424563627975e+00, -1.003797552916670e+00, -1.010105444429954e+00, -1.026562485807234e+00, -1.067430224867403e+00, -1.160219250240482e+00, -1.345414226415081e+00, -1.662527795040335e+00, -2.297977308163687e+00, -4.842243274852486e+00, -6.324922371037887e+00, 4.300134224092854e+03, 2.989151517654729e+07]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b88_HO2D_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.592057825189733e-02, 4.592115360462774e-02, 4.592265147799792e-02, 4.592652009575465e-02, 4.593638236110915e-02, 4.596099069839923e-02, 4.602023764860377e-02, 4.615443115964873e-02, 4.642681835887656e-02, 4.687222532204064e-02, 4.730535826980952e-02, 4.718365879670160e-02, 4.597590023528754e-02, 4.118674031148714e-02, 1.096201136811848e-02, -2.284171586208611e-01, -4.710898453547096e+00, -1.085573152541471e+03, -2.385779191233186e+07, -7.662441789240162e+14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_2d_b88_HO2D_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["HO2D_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_2d_b88", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.692024094979941e-02, 1.692062186673837e-02, 1.692161243438329e-02, 1.692416610572389e-02, 1.693065634341152e-02, 1.694676771507536e-02, 1.698521128780228e-02, 1.707084812855113e-02, 1.723877538654366e-02, 1.749123462523644e-02, 1.768547092348979e-02, 1.776213845264406e-02, 1.926343458806560e-02, 2.825216670739642e-02, 7.723538660608427e-02, 6.338477073704758e-01, 4.533919429397977e+01, 2.010533278571361e+05, 8.055737411757059e+11, 1.990258165143416e+23]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
