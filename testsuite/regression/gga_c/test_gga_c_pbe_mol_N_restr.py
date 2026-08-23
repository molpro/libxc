
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_c_pbe_mol_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_mol", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.836033420579469e-02, -5.731131839030852e-02, -5.580912652376392e-02, -5.366248302269323e-02, -5.060518689486424e-02, -4.627685642881418e-02, -4.022426373458232e-02, -3.201086918598330e-02, -2.175770853573592e-02, -1.177130552800683e-02, -8.455538151558153e-03, -3.920394739649563e-02, -5.015840776468844e-02, -3.311664342914051e-02, -1.594365096034495e-02, -3.765496365610440e-03, -2.394082544544815e-04, -2.617244871589305e-06, -2.635248394509717e-09, -8.453035695437134e-14]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_c_pbe_mol_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_mol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.278146242421749e-01, -1.267571787288568e-01, -1.252196440845344e-01, -1.229714681821243e-01, -1.196545340128988e-01, -1.146889735597974e-01, -1.070814110599208e-01, -9.505295820669776e-02, -7.580821822925289e-02, -4.957006551820534e-02, -3.809881515241433e-02, -8.763577402777162e-02, -8.380115579143547e-02, -7.799491141066205e-02, -5.479617490733167e-02, -1.858609470207508e-02, -1.441369943978200e-03, -1.675250451149983e-05, -1.722117186819531e-08, -5.591898305478567e-13]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_mol_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_mol", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.365498832474952e-07, 7.848469498924597e-07, 8.595978286040311e-07, 9.789294607703779e-07, 1.177831068554436e-06, 1.529481457157773e-06, 2.201044871666969e-06, 3.607122082446597e-06, 6.827668621697117e-06, 1.527185080925397e-05, 7.932787791186134e-05, 3.729654601153738e-03, 1.094216015152061e-02, 1.598427619046911e-02, 3.614865658398590e-02, 7.910700802239773e-02, 8.087967456614442e-02, 3.119188936163025e-02, 3.824879699869519e-03, 9.532025838405242e-05]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_mol_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_mol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-3.346803791952066e-04, -3.618242936528555e-04, -4.048240771939739e-04, -4.759230795681483e-04, -6.010025725689855e-04, -8.416169771315279e-04, -1.366838746283114e-03, -2.720936878936289e-03, -6.851795529691001e-03, -1.989152462086790e-02, -6.511123684465345e-02, -4.134153128065361e-02, 5.205842301609987e-03, -1.245434965580579e-01, -1.113464452843502e+00, -5.276669499888125e+00, -7.140122305793142e+00, -2.799885940597775e+00, -3.335186756809501e-01, -8.131304387747557e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_c_pbe_mol_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_mol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([3.361750413907762e-09, 3.881070329025592e-09, 4.771745657778799e-09, 6.422666281893667e-09, 9.845939940265427e-09, 1.819188687590504e-08, 4.386102356491957e-08, 1.531050032380757e-07, 8.579207415471991e-07, 8.004630307700051e-06, 1.736282728696928e-04, 2.337484338843504e-03, -1.101651814430317e-02, 3.345605536354110e-02, 1.002174458043934e+00, 2.803592591481975e+01, 4.804009399656229e+02, 6.181701110944638e+03, 8.749765367306852e+04, 1.633253401899885e+06]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))


def test_gga_c_pbe_mol_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_c_pbe_mol", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.075095442701681e-13, -1.306077470258927e-13, -1.727613129947462e-13, -2.581915432030867e-13, -4.595821712403564e-13, -1.049996176754660e-12, -3.419405855231856e-12, -1.831258878614679e-11, -1.929678964113431e-10, -4.954170550142797e-09, -6.814834122588252e-07, -9.301266850288243e-04, -1.028708308470542e-02, -5.494522435431785e-02, -1.750742743116869e+00, -2.095471265872987e+02, -4.164209281523469e+04, -1.732415756355280e+07, -2.915563447122967e+10, -4.176110354319107e+14]))
    err = ns.abs(tgt-ref_tgt)/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    tol = ns.full_like(tgt, ns.asarray([5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 5.000000000000000e-05, 1.000000000000000e+30]))
    assert bool(ns.all(err < tol))
