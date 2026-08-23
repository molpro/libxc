
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_gga_x_apbe_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_apbe", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.328093924481268e+00, -4.246747721885455e+00, -4.132886939675463e+00, -3.975422270688447e+00, -3.761401152135808e+00, -3.477685719127498e+00, -3.114812953803075e+00, -2.673669582139122e+00, -2.172970581173035e+00, -1.645649053154770e+00, -1.108772522236770e+00, -6.703660372114162e-01, -5.651563392132688e-01, -4.771508243143869e-01, -3.562166716585831e-01, -2.343132485378575e-01, -1.222857283471855e-01, -4.195354625134683e-02, -8.770208361731245e-03, -9.701627966576917e-04]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_gga_x_apbe_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_apbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-5.352250869965240e+00, -5.237656869969870e+00, -5.077015755883122e+00, -4.854365497295115e+00, -4.550781972281137e+00, -4.146549263608841e+00, -3.626694536346399e+00, -2.992525090708547e+00, -2.283425709984953e+00, -1.604763874557071e+00, -1.056164947466489e+00, -7.937433126872417e-01, -7.125182981355799e-01, -5.506424176834054e-01, -3.599410142864081e-01, -2.227014864770119e-01, -1.406386606695429e-01, -5.482345561003825e-02, -1.168253203510647e-02, -1.293534641664785e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_apbe_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_apbe", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.490864872018055e-06, -4.853827500281812e-06, -5.425891506745627e-06, -6.363737146528711e-06, -7.989555148724705e-06, -1.103818999145749e-05, -1.741043376245911e-05, -3.281302253274542e-05, -7.745427383316429e-05, -2.371924704749880e-04, -1.124503935229063e-03, -8.030579947112189e-03, -1.524069932856633e-02, -3.178718060368815e-02, -1.083737171124599e-01, -4.804102812099497e-01, -1.519088074315255e+00, -2.511632549895986e+00, -3.016479532236204e+00, -3.330920357871539e+00]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_apbe_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.246341743381785e-02, -1.303754337615248e-02, -1.390818103193557e-02, -1.525823285854736e-02, -1.741725332020394e-02, -2.101457184716965e-02, -2.730974237876666e-02, -3.874232745240307e-02, -5.788634662796972e-02, -6.920374827376782e-02, -7.826154560756947e-02, -5.731512033823170e-01, -6.914231819556739e-01, -1.178751194951654e+00, -1.944296034743535e+00, 3.788428557018003e+00, 2.261320255297673e+01, -4.334504201871678e+02, -1.347936534686150e+04, -1.116648079233231e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_apbe_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.683840181088667e-08, 3.055391357135195e-08, 3.677442129149055e-08, 4.788135276468848e-08, 6.957583183814184e-08, 1.174448374528860e-07, 2.407918301749265e-07, 6.118306620156403e-07, 1.574229450726026e-06, -8.668629988708077e-06, -3.752065364408966e-04, 1.171130948938790e-02, 4.227595213903260e-02, 1.186695004661275e-01, 1.446394728241677e-01, -5.443244627407973e+01, -4.768951383636117e+03, -3.027249053360278e+05, -4.218532404874172e+07, -3.450955163009425e+10]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_gga_x_apbe_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("gga_x_apbe", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([7.078363391922687e-14, 8.989587774806680e-14, 1.266827903913634e-13, 2.071463685887133e-13, 4.186698161689326e-13, 1.142714724327465e-12, 4.757122598981541e-12, 3.550461310161807e-11, 5.787599693368113e-10, 2.507773330123595e-08, 3.485012630841819e-06, 4.475448970030230e-04, 2.654726675274943e-03, 2.963295067529725e-02, 1.895925313959383e+00, 5.861140263714072e+02, 4.630972644065504e+05, 9.166176961949064e+08, 1.531967812931120e+13, 9.728744100471421e+18]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
