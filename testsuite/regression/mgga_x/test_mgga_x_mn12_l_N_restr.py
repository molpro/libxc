
import pylibxc
import pytest
from pylibxc.example_densities import test_data


def test_mgga_x_mn12_l_N_restr_1_zk():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_exc:
        pytest.skip("build lacks the derivative order for zk")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=False, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["zk"])
    tgt = out["zk"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-6.355516489970298e+00, -6.246524038243048e+00, -6.083337769570323e+00, -5.837329024467923e+00, -5.466297915805249e+00, -4.916036414408886e+00, -4.144844597633290e+00, -3.201688343329126e+00, -2.273073913322222e+00, -1.298303253403577e+00, -3.677500480713687e-01, -3.797910442438581e-01, -5.397156911165935e-01, -4.527292553580933e-01, -3.154880306316663e-01, -2.338850736481710e-01, -1.511328726008748e-01, -9.104567295436100e-02, -2.226728909060286e-02, -2.520609109771274e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-08


def test_mgga_x_mn12_l_N_restr_1_vrho():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vrho")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vrho"])
    tgt = out["vrho"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-4.004202664883669e+00, -4.186862973931884e+00, -4.425666138680544e+00, -4.716144865647236e+00, -5.016489362198799e+00, -5.195715127810240e+00, -4.968209245896142e+00, -4.015992856375139e+00, -2.840160852661953e+00, -2.589757022607174e+00, -1.497155912301842e+00, -1.230339335148151e+00, -8.557026551127831e-01, -6.835673640669472e-01, -2.929678977048205e-01, -2.424257209665661e-01, -1.025783844301975e-01, -1.000163210030149e-01, -2.930099931578915e-02, -3.358461815626418e-03]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn12_l_N_restr_1_vsigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vsigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vsigma"])
    tgt = out["vsigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-9.346192395398654e-05, -9.787734330089308e-05, -1.043882691217529e-04, -1.140294294663574e-04, -1.282700880934678e-04, -1.487914246823060e-04, -1.757177532625034e-04, -2.010241933125598e-04, -2.057245132777195e-04, -2.939867636878956e-04, -1.397893258618932e-03, -4.261350804614912e-03, -1.715642414745360e-02, -3.317952371808582e-02, -2.054421335017882e-01, -6.979938928737442e-01, -4.905807216281672e+00, -3.483331831131269e+01, -5.296010069142700e+01, -6.026180265118875e+01]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn12_l_N_restr_1_vtau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_vxc:
        pytest.skip("build lacks the derivative order for vtau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=False, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["vtau"])
    tgt = out["vtau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.005976630735567e-01, 1.053622120385454e-01, 1.115637115069248e-01, 1.190065882231501e-01, 1.263381066177568e-01, 1.293301608328084e-01, 1.183485879204501e-01, 8.129195705854897e-02, 3.481737621770709e-02, 4.071117203268877e-02, 5.189374310613241e-02, 6.859579669303728e-02, 7.521162939298741e-02, 9.494640048204714e-02, 6.875250531446303e-02, 6.375061485855256e-02, -7.035749828052886e-03, -2.247187428743472e-03, -3.014737496945354e-05, -4.725238014020647e-08]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn12_l_N_restr_1_v2rho2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rho2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rho2"])
    tgt = out["v2rho2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([6.150336840378273e-02, 6.347498966334857e-02, 6.580952958089652e-02, 6.788861686299902e-02, 6.753977614185770e-02, 5.849407234264710e-02, 2.711913549024355e-02, -2.852336952390530e-02, 3.385654497627393e-02, 2.741166003601203e-01, -6.305938401217618e-01, -9.642168717010106e-01, -9.735937388920097e-01, -2.595362098221841e+00, -5.956036606305313e+00, 4.117580990445165e+01, -5.501875907526737e+01, 9.968178129368074e+02, -3.022379483926597e+04, -2.887603374179268e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn12_l_N_restr_1_v2rhosigma():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhosigma")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhosigma"])
    tgt = out["v2rhosigma"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-8.994779905559476e-08, -1.285816019426334e-07, -1.987865441458065e-07, -3.374466208408151e-07, -6.417453215702051e-07, -1.399328152743882e-06, -3.551150009242004e-06, -1.010864441087341e-05, -2.475078328375140e-05, -3.401461626797644e-05, -1.673149074473766e-03, 6.035098111923219e-02, -8.046402568667600e-02, 1.816583295613822e-01, 3.604014803651014e+00, -3.303647510898911e+02, -1.461005492340075e+03, -3.795729645445855e+06, -7.362432507949755e+08, -6.241505222524899e+11]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn12_l_N_restr_1_v2rhotau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2rhotau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2rhotau"])
    tgt = out["v2rhotau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([-1.501407201420766e-03, -1.501452138423468e-03, -1.478319554614820e-03, -1.388794002631144e-03, -1.120130609748004e-03, -3.897346863457192e-04, 1.387006049868023e-03, 4.406451684393201e-03, 2.873020449455917e-03, -1.022233711544241e-02, 2.362325494989835e-02, -6.963807580394026e-02, 2.373576902116100e-01, 4.701800265798525e-01, -7.006450143883621e-04, 9.660023354770873e+00, 3.833766212887966e+01, -1.742352612062639e+02, -3.139837057952510e+02, -3.670964307718141e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn12_l_N_restr_1_v2sigma2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigma2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigma2"])
    tgt = out["v2sigma2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([2.165157453803333e-12, 2.654871665941161e-12, 3.549011845835484e-12, 5.352531416760207e-12, 9.522916880514698e-12, 2.106373509075456e-11, 6.048553098953157e-11, 2.153272415189222e-10, 4.773527863419279e-10, 1.656633102224009e-08, 8.722745114701829e-06, -1.407466076096317e-03, -5.793969534501922e-03, 3.894646441676039e-03, 3.297195846483839e+00, 2.325361968225890e+03, 9.806276463967080e+05, 1.210267670816621e+10, 2.683895025570458e+14, 1.760041145704094e+20]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn12_l_N_restr_1_v2sigmatau():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2sigmatau")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2sigmatau"])
    tgt = out["v2sigmatau"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([1.325330303951020e-08, 1.526378973838792e-08, 1.865769997621839e-08, 2.477803260755262e-08, 3.685452215675690e-08, 6.366967111401333e-08, 1.323304771958496e-07, 3.335878784830507e-07, 9.193982899249151e-07, 1.630321776575545e-06, -1.092547291420143e-05, -2.557816812810608e-03, 5.268190962657439e-02, -3.103123900733651e-02, -1.624903506832339e+00, -6.218430629516652e+00, -3.892227904675396e+03, -7.325108183474834e+04, -6.098431419465862e+05, -7.073043542046217e+06]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05


def test_mgga_x_mn12_l_N_restr_1_v2tau2():
    # Prepare the input
    inp = test_data["N_restr"]

    # Get the functional
    feval = pylibxc.LibXCFunctional("mgga_x_mn12_l", 1)
    if not feval._have_fxc:
        pytest.skip("build lacks the derivative order for v2tau2")

    # Evaluate only up to the tested field's derivative order. Computing higher
    # orders than this test checks is wasteful and can trip a latent bug in an
    # order the test does not exercise (e.g. an fxc segfault under a vrho test).
    out = feval.compute(inp, do_exc=feval._have_exc, do_vxc=feval._have_vxc, do_fxc=feval._have_fxc, do_kxc=False, do_lxc=False)
    ns = pylibxc.array_backend.array_namespace(out["v2tau2"])
    tgt = out["v2tau2"].flatten()
    ref_tgt = ns.full_like(tgt, ns.asarray([4.362654967068359e-06, 1.543074244274897e-06, -3.410319349269615e-06, -1.262805405418746e-05, -3.086765544591024e-05, -6.881498580941325e-05, -1.471955047958929e-04, -2.754239421326157e-04, -2.786253057035429e-04, 1.263209191002154e-04, -7.069261006337852e-04, 7.911924410038058e-03, -1.772395048871845e-01, -1.812317267198205e-01, 1.070551614108977e+00, -6.667608203256490e+00, 1.764722133161408e+01, 2.017184314083124e+02, 3.381542937141716e+02, 4.188692486721864e+02]))
    error = ns.max(ns.abs(tgt-ref_tgt))/(1.0+ns.max(ns.asarray([ns.abs(tgt), ns.abs(ref_tgt)])))
    assert error < 5e-05
